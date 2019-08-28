/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:08:59 by mchan             #+#    #+#             */
/*   Updated: 2019/08/20 18:13:36 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Return (0) or false if anything does not pass a check.
**	Checking for invalid characters that are not ".", "#", or "\n".
**	Checking to make sure "\n" are located in the correct position.
**	Counts the number of times "#" character appears.
**	Checks that last character of tetrimino is a "\n"
*/

int		check_char(char *buffer)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buffer[i] != '.' && buffer[i] != '#' && buffer[i] != '\n')
			return (0);
		if (buffer[i] == '\n' && (((i + 1) % 5) != 0))
			return (0);
		if (buffer[i] == '#')
			count++;
		i++;
	}
	if (!buffer[i] || buffer[i] != '\n')
		return (0);
	return (count);
}

/*
**	Checks to see if each "#" is adjacent to another "#"
**	Checks to the right, left, up, and then down before returning a count.
**	Tetriminos with four "#"s will have 6 or 8 adjacency connections.
*/

int		check_count(char *buffer)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buffer[i] == '#')
		{
			if (i + 1 <= 18 && buffer[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buffer[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buffer[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buffer[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
**	Goes through 21 char chunks from buf at a time
**	Performs both checks on each tetrimino
**	Will return (0) for any check failures
*/

int		validate(char *buffer, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (check_char(buffer + i) != 4)
			return (0);
		if (check_count(buffer + i) != 6 && check_count(buffer + i) != 8)
			return (0);
		i = i + 21;
	}
	return (1);
}
