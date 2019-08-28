/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:24:40 by mchan             #+#    #+#             */
/*   Updated: 2019/05/16 22:49:16 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*ptr;
	const unsigned char		*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (ptr > ptr2)
		while (len >= ++i)
			ptr[len - i] = ptr2[len - i];
	else
		while (len > 0)
		{
			if (!ptr && !ptr2)
				return (dst);
			*ptr = *ptr2;
			ptr++;
			ptr2++;
			len--;
		}
	return (dst);
}
