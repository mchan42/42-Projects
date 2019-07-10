/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:13:09 by mchan             #+#    #+#             */
/*   Updated: 2019/06/25 19:54:46 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size1;
	int		size2;

	if (s1 && s2)
	{
		size1 = ft_strlen(s1);
		size2 = ft_strlen(s2);
		if (!(result = ft_strnew(size1 + size2)))
			return (NULL);
		ft_strncat(result, s1, size1 + 1);
		ft_strncat(result, s2, size2 + 1);
		return (result);
	}
	return (NULL);
}
