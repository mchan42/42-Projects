# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 14:32:36 by mchan             #+#    #+#              #
#    Updated: 2019/09/23 14:06:50 by mchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MLIBX_DIR = ./minilibx/
SRC = ./src/*.c

FLGS = -Wall -Wextra -Werror

LINK = -L $(LIBFT_DIR) -lft \
	   -L $(MLIBX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@make -C $(MLIBX_DIR)
	@gcc $(FLGS) -o $(NAME) $(SRC) \
		-I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLIBX_DIR) \
		$(LINK)

clean:
	@/bin/rm -f *.o
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLIBX_DIR) clean


re: fclean all

.PHONY: all clean fclean re
