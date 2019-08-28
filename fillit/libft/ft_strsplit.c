/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:54:03 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/31 19:52:23 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int count;
	int	i;

	count = 0;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**tab;
	int		i;
	int		j;
	int		start;

	len = ft_count_words(s, c);
	if (!s || c == '\0' || !(tab = (char **)malloc((sizeof(char *) * len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < len)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
