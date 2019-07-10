/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:49:32 by mchan             #+#    #+#             */
/*   Updated: 2019/07/10 14:36:22 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_string(char **str1, const char *str2)
{
	char	*temp;

	temp = ft_strjoin(*str1, str2);
	free(*str1);
	return (temp);
}

char	*dup_string_from_len(char **str, int len)
{
	char	*temp;

	temp = ft_strdup(*str + len + 1);
	free(*str);
	return (temp);
}

int		get_one_line(char **str, char **line, int fd, int ret)
{
	int		length;

	length = 0;
	while (str[fd][length] != '\n' && str[fd][length] != '\0')
		length++;
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		str[fd] = dup_string_from_len(&str[fd], length);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][length] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		return_value(const int fd, char **line, char **str, int ret)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	return (get_one_line(str, line, fd, ret));
}

int		get_next_line(const int fd, char **line)
{
	static char *str[FD_SIZE];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		str[fd] = join_string(&(str[fd]), buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (return_value(fd, line, str, ret));
}
