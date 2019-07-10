/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:03:33 by mchan             #+#    #+#             */
/*   Updated: 2019/05/06 16:12:50 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s || !(substring = ft_memalloc(len + 1)))
		return (NULL);
	substring = ft_strncpy(substring, s + start, len);
	return (substring);
}
