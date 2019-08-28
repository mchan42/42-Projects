# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 10:53:20 by mchan             #+#    #+#              #
#    Updated: 2019/08/28 14:11:41 by mchan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./*.c
OBJS = ./*.o
HDRS = ./libft.h
FLGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(FLGS) -I $(HDRS) -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
