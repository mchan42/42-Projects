/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:26:36 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 20:39:03 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	char		*s;

	s = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
