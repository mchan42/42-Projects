/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 01:13:25 by mchan             #+#    #+#             */
/*   Updated: 2019/06/25 18:42:49 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (size == 0)
		return (NULL);
	if (!(memory = malloc(size)))
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}
