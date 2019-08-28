/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:11:10 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/31 19:39:11 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dest && !src && n > 0)
		return (NULL);
	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}
