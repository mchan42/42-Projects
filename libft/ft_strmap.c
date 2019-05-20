/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:11:34 by mchan             #+#    #+#             */
/*   Updated: 2019/05/06 14:45:24 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*ptr2;
	char	*result;

	if (!s || !(result = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	ptr = (char*)s;
	ptr2 = result;
	while (*ptr)
	{
		*ptr2 = (*f)(*ptr);
		ptr++;
		ptr2++;
	}
	return (result);
}
