/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:10:41 by jmarguer          #+#    #+#             */
/*   Updated: 2019/08/20 19:00:26 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		shift_x(t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		piece->x[i] += -1;
		i++;
	}
}

void		shift_y(t_piece *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		piece->y[i] += -1;
		i++;
	}
}

/*
** The function align is going to check whether the piece has at least
** one x coord that is 0 and one y coord that is 0
** and if it doesn't, it will move the piece by one up and/or to the left.
*/

t_piece		*align(t_piece *piece)
{
	while (piece->x[0] != 0 && \
		piece->x[1] != 0 && \
		piece->x[2] != 0 && \
		piece->x[3] != 0)
		shift_x(piece);
	while (piece->y[0] != 0 && \
		piece->y[1] != 0 && \
		piece->y[2] != 0 && \
		piece->y[3] != 0)
		shift_y(piece);
	return (piece);
}
