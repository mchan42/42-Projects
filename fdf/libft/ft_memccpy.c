/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:01:18 by mchan             #+#    #+#             */
/*   Updated: 2019/05/03 17:22:37 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*ptr;
	const unsigned char		*ptr2;

	i = 0;
	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n > i)
	{
		ptr[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
