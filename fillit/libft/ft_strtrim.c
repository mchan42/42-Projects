/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:20:06 by jmarguer          #+#    #+#             */
/*   Updated: 2019/06/03 09:50:06 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		strlen;
	int		start;
	int		stop;
	int		len;

	if (s)
	{
		start = 0;
		strlen = ft_strlen(s);
		while (s[start] != '\0' && ISBLANK(s[start]))
			start++;
		stop = strlen - 1;
		while (stop > 0 && ISBLANK(s[stop]))
			stop--;
		if (start == 0 && stop == strlen)
			return ((char *)s);
		len = ft_absolute(stop - start);
		return (ft_strsub(s, start, len + 1));
	}
	else
		return (NULL);
}
