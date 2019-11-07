/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:38:04 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 18:04:07 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Feature which changes the map color to a random color.
*/

void	randomize_color(t_fdf *fdf)
{
	fdf->color.red = (rand() % 0x7F);
	fdf->color.green = (rand() % 0x7F);
	fdf->color.blue = (rand() % 0x7F);
}

/*
**	Feature which changes the text color to a random color.
*/

void	randomize_color_text(t_fdf *fdf)
{
	fdf->map.color = (rand() % 0xFFFFFF);
}

/*
**	Display for the instructions on how to utilize the functionalities
**	of the fdf program.
*/

void	display_instructions(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 0, fdf->map.color, \
			"[ESC]              ->      Exit Program");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 20, fdf->map.color, \
			"[MOUSE WHEEL]      ->      Increase or decrease z values");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 40, fdf->map.color, \
			"[KEY W / S]        ->      Image movement up or down");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 60, fdf->map.color, \
			"[KEY A / D]        ->      Image movement left or right");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 80, fdf->map.color, \
			"[KEY Q / E]        ->      Increase or decrease zoom");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 100, fdf->map.color, \
			"[KEY C]            ->      Randomize color of map");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 120, fdf->map.color, \
			"[KEY V]            ->      Randomize color of text");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 0, 140, fdf->map.color, \
			"[KEY T / P]        ->      Switches projection");
}

/*
**	Calculations for display of parallel projection for fdf project.
*/

void	parallel_projection(t_fdf *fdf)
{
	if (fdf->map.parallel++ % 2)
	{
		fdf->map.x_angle = 1;
		fdf->map.y_angle = 1;
		fdf->map.z_value = 0;
	}
	else
	{
		fdf->map.x_angle = cos(M_PI / 3);
		fdf->map.y_angle = fdf->map.x_angle * sin(M_PI / 6);
		fdf->map.z_value = 1;
	}
}

/*
**	Calculations for display of isometric projection for fdf project.
*/

void	isometric_projection(t_fdf *fdf)
{
	if (fdf->map.isometric++ % 2)
		fdf->map.y_angle = fdf->map.y_angle * 0.2;
	else
		fdf->map.y_angle = fdf->map.y_angle * 5;
}
