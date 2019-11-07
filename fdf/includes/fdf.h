/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:49:00 by mchan             #+#    #+#             */
/*   Updated: 2019/11/06 15:43:26 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**	User defined header files from  minilibx and libft folders.
*/

# include "mlx.h"
# include "libft.h"
# include "key.h"

/*
**	Call header files
*/

# include <math.h>

/*
**	Define utilized variables
*/

# define WIDTH			(1920)
# define HEIGHT			(1200)
# define Z_MAX			(30)

# define SMALLER(a, b) ((a) > (b) ? (b) : (a))
# define LARGER(a, b) ((a) > (b) ? (a) : (b))

/*
**	Structure holding required pointers for minilibx.
*/

typedef struct	s_minilibx
{
	void		*init;
	void		*win;
	void		*img;
}				t_minilibx;

/*
**	Structures holding all the data for images.
*/

typedef struct	s_image
{
	char		*data;
	int			line_size;
	int			endian;
	int			bpp;
}				t_image;

typedef struct	s_map
{
	int			**values;
	int			height;
	int			width;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			x_coord;
	int			y_coord;
	int			zoom;
	int			isometric;
	int			parallel;
	int			color;
	double		z_value;
	double		x_angle;
	double		y_angle;
}				t_map;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_fdf
{
	t_minilibx	mlx;
	t_map		map;
	t_image		image;
	t_color		color;
}				t_fdf;

/*
**	Prototype functions from all files
*/

int				check_values(char *line);
int				draw_fdf(t_fdf *fdf);
void			read_fdf(t_fdf *fdf, char *file);
void			randomize_color(t_fdf *fdf);
void			randomize_color_text(t_fdf *fdf);
void			display_instructions(t_fdf *fdf);
void			parallel_projection(t_fdf *fdf);
void			isometric_projection(t_fdf *fdf);

#endif
