/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:29:50 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 12:17:41 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			fresh[i] = (*f)(s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	else
		return (NULL);
}
