/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:15:32 by jmarguer          #+#    #+#             */
/*   Updated: 2019/08/20 18:37:49 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This goes through the input string and assigns
** both a letter representation to each piece
** and stores the x,y coordinates of each element in the piece.
** It also sets the x and y offsets to zero
** and aligns the piece in the top left.
*/

t_piece		*makepiece(char *buffer, char letter)
{
	t_piece		*piece_ptr;
	int			x;
	int			y;
	int			i;

	i = 0;
	x = 0;
	y = 0;
	if (!(piece_ptr = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			piece_ptr->x[x] = (i >= 5) ? (i % 5) : i;
			piece_ptr->y[y] = i / 5;
			x++;
			y++;
		}
		i++;
	}
	piece_ptr->x_offset = 0;
	piece_ptr->y_offset = 0;
	piece_ptr->letter = letter;
	return (align(piece_ptr));
}

/*
** This divides the input string into 21-char pieces (nodes).
*/

t_piece		*makelist(char *buffer, int size)
{
	t_piece		*current;
	t_piece		*beginning;
	int			i;
	char		letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			beginning = makepiece(&buffer[i], letter);
			current = beginning;
		}
		else
		{
			current->next = makepiece(&buffer[i], letter);
			current = current->next;
		}
		letter++;
		i += 21;
	}
	current->next = NULL;
	return (beginning);
}

/*
** This actually reads the input (filename is argv[1] from main)
** and storing the contents in one
** big string called "buffer".
*/

t_piece		*readinput(char *filename)
{
	char	buffer[546];
	int		fd;
	int		bytesread;

	fd = open(filename, O_RDONLY);
	bytesread = read(fd, buffer, 546);
	close(fd);
	if (bytesread > 545 || bytesread < 20)
		return (NULL);
	buffer[bytesread] = '\0';
	if (!validate(buffer, bytesread))
		return (NULL);
	return (makelist(buffer, bytesread));
}
