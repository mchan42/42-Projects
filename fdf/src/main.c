/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:24:34 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 15:28:32 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Resets all map values to initial settings.
*/

static void		reset(t_fdf *fdf)
{
	fdf->image.bpp = 4;
	fdf->image.endian = 0;
	fdf->map.x_coord = 0;
	fdf->map.y_coord = 0;
	fdf->map.zoom = SMALLER(WIDTH, HEIGHT) \
	/ LARGER(fdf->map.width, fdf->map.height);
	fdf->image.line_size = fdf->image.bpp * fdf->map.width;
	fdf->map.x_angle = cos(M_PI / 3);
	fdf->map.y_angle = fdf->map.x_angle * sin(M_PI / 6);
	fdf->map.z_value = 1.00;
	fdf->map.isometric = 1;
	fdf->map.parallel = 1;
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
	fdf->map.color = 0xFFFFFF;
}

/*
**	Sets up the individual keyboard keystroke functions.
*/

static int		fdf_keys(int key, t_fdf *fdf)
{
	if (key == KEY_ESCAPE)
		exit(0);
	else if (key == KEY_ANSI_R)
		reset(fdf);
	else if (key == KEY_ANSI_D)
		fdf->map.x_coord = fdf->map.x_coord + 10;
	else if (key == KEY_ANSI_A)
		fdf->map.x_coord = fdf->map.x_coord - 10;
	else if (key == KEY_ANSI_S)
		fdf->map.y_coord = fdf->map.y_coord + 10;
	else if (key == KEY_ANSI_W)
		fdf->map.y_coord = fdf->map.y_coord - 10;
	else if (key == KEY_ANSI_Q)
		fdf->map.zoom = fdf->map.zoom + 1;
	else if (key == KEY_ANSI_E)
		fdf->map.zoom = fdf->map.zoom - 1;
	else if (key == KEY_ANSI_C)
		randomize_color(fdf);
	else if (key == KEY_ANSI_V)
		randomize_color_text(fdf);
	else if (key == KEY_ANSI_T)
		isometric_projection(fdf);
	else if (key == KEY_ANSI_P)
		parallel_projection(fdf);
	return (0);
}

/*
**	Sets up the individual mouse keystroke functions.
*/

static int		fdf_mousekeys(int key, int x, int y, t_fdf *fdf)
{
	int		x0;
	int		y0;

	x0 = x;
	y0 = y;
	if ((key == 4) && (fdf->map.z_value < Z_MAX))
		fdf->map.z_value = fdf->map.z_value + 1;
	else if ((key == 5) && (fdf->map.z_value > -Z_MAX))
		fdf->map.z_value = fdf->map.z_value - 1;
	return (0);
}

int				main(int argc, char *argv[])
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_puterror("Error. Issue with memory allocation.", 1);
		read_fdf(fdf, argv[1]);
		reset(fdf);
		fdf->mlx.init = mlx_init();
		if (!(fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIDTH, \
						HEIGHT, argv[1])))
			ft_puterror("Error. Issue creating new window.", 1);
		mlx_hook(fdf->mlx.win, 2, 3, fdf_keys, fdf);
		mlx_hook(fdf->mlx.win, 4, 3, fdf_mousekeys, fdf);
		mlx_loop_hook(fdf->mlx.init, draw_fdf, fdf);
		mlx_loop(fdf->mlx.init);
	}
	return (0);
}
