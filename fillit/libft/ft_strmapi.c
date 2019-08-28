/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:50:05 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 12:19:53 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fresh;

	if (s && f)
	{
		fresh = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!fresh)
			return (NULL);
		i = 0;
		while (s[i])
		{
			fresh[i] = (*f)(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	else
		return (NULL);
}
