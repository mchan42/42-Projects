/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountfirstchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:56:29 by mchan             #+#    #+#             */
/*   Updated: 2019/06/05 15:54:49 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcountfirstchar(char *str, const char *charset)
{
	char			*ptr;
	int				i;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		i = 0;
		tmp = count;
		while (charset[i])
			if (charset[i++] == *ptr)
				count++;
		if (count == tmp)
			return (count);
		ptr++;
	}
	return (count);
}
