/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 22:18:53 by mchan             #+#    #+#             */
/*   Updated: 2019/05/14 14:31:22 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (*s)
		s++;
	while (i >= 0)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		i--;
		s--;
	}
	return (NULL);
}
