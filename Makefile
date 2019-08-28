# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 15:51:55 by jmarguer          #+#    #+#              #
#    Updated: 2019/08/22 13:31:58 by mchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./fillitproj/*.c
HEADER = ./fillitproj/fillit.h

LIB = libft/

all: $(NAME)

$(NAME):
	@Make -C $(LIB)
	@gcc -Wall -Wextra -Werror -I $(HEADER) -L. libft/libft.a -o $(NAME) $(SRC)

clean:
	/bin/rm -rf ./fillitproj/*.o
	Make clean -C $(LIB)

fclean: clean
	/bin/rm -rf $(NAME)
	Make fclean -C $(LIB)

re: fclean all
