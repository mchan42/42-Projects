/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:14:22 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 17:50:10 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	int		length;
	char	**tab;

	length = get_str_wordcount(s, c);
	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (length + 1))))
		return (NULL);
	x = -1;
	y = 0;
	while (++x < length)
	{
		z = 0;
		if (!(tab[x] = ft_strnew(get_word_length(&s[y], c) + 1)))
			tab[x] = NULL;
		while (s[y] == c)
			y++;
		while (s[y] != c && s[y])
			tab[x][z++] = s[y++];
		tab[x][z] = '\0';
	}
	tab[x] = 0;
	return (tab);
}
