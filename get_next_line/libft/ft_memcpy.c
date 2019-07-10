/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:59:49 by mchan             #+#    #+#             */
/*   Updated: 2019/05/20 13:06:11 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*ptr;
	const unsigned char		*ptr2;

	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (n > 0 && !ptr && !ptr2)
		return (dst);
	while (n-- > 0)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
	}
	return (dst);
}
