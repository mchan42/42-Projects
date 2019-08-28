/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:25:48 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 20:30:01 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (!fresh)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		fresh[i] = s[start];
		start++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
