/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:41:04 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/23 16:46:39 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (find[j] != '\0' && len > i + j)
		{
			if (str[i + j] != find[j])
				break ;
			j++;
		}
		if (find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
