/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:30:07 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 11:12:31 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = dest;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
