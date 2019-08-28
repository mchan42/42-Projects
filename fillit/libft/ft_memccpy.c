/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:59:25 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 10:52:22 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr2;
	unsigned char	*ptr1;

	i = 0;
	ptr2 = (unsigned char *)src;
	ptr1 = (unsigned char *)dest;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		if (ptr2[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
