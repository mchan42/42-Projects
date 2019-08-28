/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:21:07 by jmarguer          #+#    #+#             */
/*   Updated: 2019/08/20 18:04:46 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function counts the number of nodes
** in the piecelist linked list. This could have been accomplished
** by using check_char(buffer) / 4 as well, since check_char returns
** the number of "#" symbols found in the input file.
*/

size_t	count_pieces(t_piece *piecelist)
{
	size_t	count;

	count = 0;
	while (piecelist)
	{
		piecelist = piecelist->next;
		count++;
	}
	return (count);
}

/*
** Determine min board size by calling
** find_min_board_size(count_pieces(piecelist))
*/

int		find_min_board_size(int pieces)
{
	int		minsize;

	minsize = 2;
	while (minsize * minsize < pieces * 4)
		minsize++;
	return (minsize);
}

/*
** Build the board by calling make_board.
** Size is whatever find_min_board_size returned
** First malloc for SIZE number of strings
** Then malloc each string separately
*/

char	**make_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * size);
		ft_memset(board[i], '.', size);
		i++;
	}
	return (board);
}

void	print_board(char **board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_board(char **board, int minsize)
{
	int i;

	i = 0;
	while (i < minsize)
	{
		ft_memdel((void **)&(board[i]));
		i++;
	}
	ft_memdel((void **)&(board));
	ft_memdel((void **)&(board));
}
