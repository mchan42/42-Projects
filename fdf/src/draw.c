/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:07:19 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 15:51:35 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Places a pixel in a specified coordinate.
**	Utilizes heavily on the principles from this link:
**	https://github.com/keuhdall/images_example
*/

static void		draw_pixel(t_fdf *fdf, int x, int y, double unit_vector)
{
	int		i;

	if ((x > 0 && y > 0) && (x < WIDTH && y < HEIGHT))
	{
		i = (x * 4) + (4 * WIDTH * y);
		fdf->image.data[i + 0] = fdf->color.blue + unit_vector;
		fdf->image.data[i + 1] = fdf->color.green + unit_vector;
		fdf->image.data[i + 2] = fdf->color.red + unit_vector;
		fdf->image.data[i + 3] = 0x7F + unit_vector;
	}
}

/*
**	Draws a line between two points of coordinate values (x0, y0) and (x1, y1)
**	This is done by calculating the delta x, delta y, and unit vector values
**	which are utilized by draw_line to create a line drawn in by pixels.
*/

static void		draw_line(t_fdf *fdf)
{
	double	x;
	double	y;
	double	x_delta;
	double	y_delta;
	double	unit_vector;

	x = fdf->map.x0;
	y = fdf->map.y0;
	x_delta = fdf->map.x1 - fdf->map.x0;
	y_delta = fdf->map.y1 - fdf->map.y0;
	unit_vector = sqrt((pow(y_delta, 2)) + (pow(x_delta, 2)));
	x_delta = x_delta / unit_vector;
	y_delta = y_delta / unit_vector;
	while (unit_vector > 0)
	{
		draw_pixel(fdf, x, y, unit_vector);
		x = x + x_delta;
		y = y + y_delta;
		unit_vector = unit_vector - 1;
	}
}

/*
**	Draws a vertical line while taking into account any changes in angles,
**	zoom, or map movement.
*/

static void		draw_line_vertical(t_fdf *fdf, int x, int y)
{
	int	xi;
	int	yi;

	xi = x - fdf->map.width / 2;
	yi = y - fdf->map.height / 2;
	fdf->map.x0 = fdf->map.x_angle * (xi - yi) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.y_angle * (xi + yi) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.y0 - (fdf->map.values[y][x] * fdf->map.z_value);
	fdf->map.x1 = fdf->map.x_angle * (xi - (yi + 1)) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.y_angle * (xi + (yi + 1)) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.y1 - (fdf->map.values[y + 1][x] * fdf->map.z_value);
	fdf->map.x0 = fdf->map.x0 + ((WIDTH / 2) + fdf->map.x_coord);
	fdf->map.x1 = fdf->map.x1 + ((WIDTH / 2) + fdf->map.x_coord);
	fdf->map.y0 = fdf->map.y0 + ((HEIGHT / 2) + fdf->map.y_coord);
	fdf->map.y1 = fdf->map.y1 + ((HEIGHT / 2) + fdf->map.y_coord);
	draw_line(fdf);
}

/*
**	Draws a horizontal line while taking into account any changes in angles,
**	zoom, or map movement.
*/

static void		draw_line_horizontal(t_fdf *fdf, int x, int y)
{
	int	xi;
	int	yi;

	xi = x - fdf->map.width / 2;
	yi = y - fdf->map.height / 2;
	fdf->map.x0 = fdf->map.x_angle * (xi - yi) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.y_angle * (xi + yi) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.y0 - (fdf->map.values[y][x] * fdf->map.z_value);
	fdf->map.x1 = fdf->map.x_angle * ((xi + 1) - yi) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.y_angle * ((xi + 1) + yi) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.y1 - (fdf->map.values[y][x + 1] * fdf->map.z_value);
	fdf->map.x0 = fdf->map.x0 + ((WIDTH / 2) + fdf->map.x_coord);
	fdf->map.x1 = fdf->map.x1 + ((WIDTH / 2) + fdf->map.x_coord);
	fdf->map.y0 = fdf->map.y0 + ((HEIGHT / 2) + fdf->map.y_coord);
	fdf->map.y1 = fdf->map.y1 + ((HEIGHT / 2) + fdf->map.y_coord);
	draw_line(fdf);
}

/*
**	Draws the map as an image.
**	Generates a new map and destroys the old map whenever a new action
**	is recorded.
*/

int				draw_fdf(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIDTH, HEIGHT);
	fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
			&fdf->image.line_size, &fdf->image.endian);
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x + 1 < fdf->map.width)
				draw_line_horizontal(fdf, x, y);
			if (y + 1 < fdf->map.height)
				draw_line_vertical(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	display_instructions(fdf);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	return (0);
}
