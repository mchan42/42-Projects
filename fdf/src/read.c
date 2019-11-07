/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:22:54 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 16:55:33 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Checks the string to make sure the values are valid numbers.
**	Valid characters are '-' and digits.
*/

int			check_values(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && line[i] == '-')
			i++;
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
**	Counts the number of values, or number of columns, by splitting along ' '.
**	This value is used to help allocate the correct memory requirements.
**	Returns an error message upon an invalid character.
*/

static int	get_numcols(char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
	{
		if (!check_values(arr[i]))
			ft_puterror("Error. Invalid characters used.", 5);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (i);
}

/*
**	Counts the number of rows that are present in the file.
**	This value is used to allocate the proper memory size for a 2D array.
**	Checks the file format to ensure the number of columns is the same
**	in every single row.
*/

static int	get_numrows(t_fdf *fdf, char *file)
{
	int		fd;
	int		length;
	int		rows;
	int		cols;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("Error. Issue opening file.", 1);
	cols = 0;
	rows = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == '\0')
			break ;
		if ((length = get_numcols(line)) > cols)
			cols = length;
		(cols == length) ? rows++ : ft_puterror("Error. File format issue.", 4);
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error. Issue closing file.", 2);
	if (!(fdf->map.width = cols))
		ft_puterror("Error. File format issue.", 4);
	return (rows);
}

/*
**	Uses ft_strsplit to generate the pointer and then ft_atoi to convert the
**	values as integers for use as z values which are used for
**	2.5 D representation.
*/

static void	store_values(t_fdf *fdf, int x, int y, char *line)
{
	int		i;
	char	**arr;

	if ((arr = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (arr[i] && (x != fdf->map.width))
		{
			fdf->map.values[y][x] = ft_atoi(arr[i]);
			ft_strdel(&arr[i]);
			i++;
			x++;
		}
		free(arr);
	}
}

/*
**	Reads the fdf file. Allocates the necessary memory for the height
**	and width for the map.
*/

void		read_fdf(t_fdf *fdf, char *file)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	y = 0;
	fdf->map.height = get_numrows(fdf, file);
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_puterror("Error. Issue opening file.", 1);
	if (!(fdf->map.values = (int**)malloc(sizeof(int*) * fdf->map.height)))
		ft_puterror("Error. Issue with memory allocation.", 3);
	while (get_next_line(fd, &line) == 1 && y != fdf->map.height)
	{
		if (!(fdf->map.values[y] = (int*)malloc(sizeof(int) * fdf->map.width)))
			ft_puterror("Error. Issue with memory allocation.", 3);
		store_values(fdf, x, y, line);
		x = 0;
		y++;
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("Error. Issue closing file.", 2);
}
