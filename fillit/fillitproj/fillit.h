/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:25:45 by jmarguer          #+#    #+#             */
/*   Updated: 2019/08/22 13:16:29 by mchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_piece
{
	int				x[4];
	int				y[4];
	char			letter;
	int				x_offset;
	int				y_offset;
	struct s_piece	*next;
}					t_piece;

void				free_list(t_piece *list);
t_piece				*align(t_piece *piece);
void				shift_x(t_piece *piece);
void				shift_y(t_piece *piece);
t_piece				*makepiece (char *buffer, char letter);
t_piece				*makelist(char *buffer, int size);
t_piece				*readinput(char *filename);
size_t				count_pieces(t_piece *piecelist);
int					find_min_board_size(int pieces);
char				**make_board(int size);
void				print_board(char **board, int size);
void				free_board(char **board, int size);
int					check_char(char *buffer);
int					check_count(char *buffer);
int					validate(char *buffer, int size);
int					check_overlap(char **board, t_piece *piece);
void				place_piece(t_piece *piece, char **board, char letter);
int					check_in_bounds(t_piece *piece, int size, char axis);
int					solve_board(char **board, t_piece *piece, int size);
void				solve(t_piece *piecelist);

#endif
