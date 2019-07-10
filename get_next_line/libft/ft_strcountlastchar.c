/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountlastchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:47:22 by mchan             #+#    #+#             */
/*   Updated: 2019/05/07 16:13:35 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcountlastchar(char *str, const char *charset)
{
	char			*ptr;
	unsigned int	i;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	index = (unsigned int)ft_strlen(ptr) - 1;
	while (index >= 0)
	{
		i = 0;
		tmp = count;
		while (charset[i])
			if (charset[i++] == ptr[index])
				count++;
		if (count == tmp)
			return (count);
		index--;
	}
	return (count);
}
