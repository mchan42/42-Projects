/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:43:24 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 11:31:49 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	else
		dest = ft_strcpy(dest, str);
	return (dest);
}
