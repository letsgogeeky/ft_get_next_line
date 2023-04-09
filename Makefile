# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 20:02:16 by ramoussa          #+#    #+#              #
#    Updated: 2023/04/07 20:06:11 by ramoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextlinebonus.a
SOURCE = get_next_line.c get_next_line_utils.c
BONUS_SOURCE = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SOURCE:%.c=%.o)

BONUS_OBJ = $(BONUS_SOURCE:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -D BUFFER_SIZE=100 $(SOURCE)
	ar rcs $(NAME) $(OBJ)

bonus:
	gcc -c -Wall -Wextra -Werror -D BUFFER_SIZE=100 $(BONUS_SOURCE)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all