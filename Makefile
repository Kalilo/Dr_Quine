# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 11:28:20 by khansman          #+#    #+#              #
#    Updated: 2017/10/25 11:28:22 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = Colleen
NAME_2 = Grace
NAME_3 = Sully

CC = clang
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1):
	@ $(CC) $(CFLAGS) ex00/$(NAME_1).c -o $(NAME_1)

$(NAME_2):
	@ $(CC) $(CFLAGS) ex01/$(NAME_2).c -o $(NAME_2)

$(NAME_3):
	@ $(CC) $(CFLAGS) ex02/$(NAME_3).c -o $(NAME_3)

clean:
	@ echo "All good here"

fclean:
	@ rm $(NAME_1) $(NAME_2) $(NAME_3)

re: fclean all