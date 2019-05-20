/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:40:57 by mchan             #+#    #+#             */
/*   Updated: 2019/05/07 17:13:56 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	start;
	unsigned int	size;
	unsigned int	whitespacecount;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen(s);
	whitespacecount = ft_strcountfirstchar((char*)s, " \n\t");
	start = whitespacecount;
	if (size > whitespacecount)
		whitespacecount += ft_strcountlastchar((char*)s, " \n\t");
	size -= whitespacecount;
	if (!(result = ft_memalloc((size_t)size + 1)))
		return (NULL);
	result = ft_strncpy(result, (s + start), size);
	return (result);
}
