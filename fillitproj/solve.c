/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:42:37 by mchan             #+#    #+#             */
/*   Updated: 2019/08/23 14:46:26 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_overlap(char **board, t_piece *piece)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->x[i] + piece->x_offset;
	y = piece->y[i] + piece->y_offset;
	while (i <= 3 && board[y][x] == '.')
	{
		i += 1;
		x = piece->x[i] + piece->x_offset;
		y = piece->y[i] + piece->y_offset;
	}
	return (i != 4);
}

void	place_piece(t_piece *piece, char **board, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 3)
	{
		x = piece->x[i] + piece->x_offset;
		y = piece->y[i] + piece->y_offset;
		board[y][x] = letter;
		i += 1;
	}
}

int		check_in_bounds(t_piece *piece, int size, char axis)
{
	if (axis == 'y')
		return (piece->y[0] + piece->y_offset < size &&
					piece->y[1] + piece->y_offset < size &&
					piece->y[2] + piece->y_offset < size &&
					piece->y[3] + piece->y_offset < size);
	else
		return (piece->x[0] + piece->x_offset < size &&
					piece->x[1] + piece->x_offset < size &&
					piece->x[2] + piece->x_offset < size &&
					piece->x[3] + piece->x_offset < size);
}

int		solve_board(char **board, t_piece *piece, int size)
{
	if (!piece)
		return (1);
	piece->x_offset = 0;
	piece->y_offset = 0;
	while (check_in_bounds(piece, size, 'y'))
	{
		while (check_in_bounds(piece, size, 'x'))
		{
			if (!check_overlap(board, piece))
			{
				place_piece(piece, board, piece->letter);
				if (solve_board(board, piece->next, size))
					return (1);
				else
					place_piece(piece, board, '.');
			}
			piece->x_offset++;
		}
		piece->x_offset = 0;
		piece->y_offset++;
	}
	return (0);
}

void	solve(t_piece *piecelist)
{
	char	**board;
	int		size;
	int		pieces;

	pieces = count_pieces(piecelist);
	size = find_min_board_size(pieces);
	board = make_board(size);
	while (!solve_board(board, piecelist, size))
	{
		free_board(board, size);
		size++;
		board = make_board(size);
	}
	print_board(board, size);
	free_board(board, size);
}
