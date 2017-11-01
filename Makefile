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

NAME_4 = Colleen_Bonus
NAME_5 = Grace_Bonus
NAME_6 = Sully_Bonus

CC = clang
CFLAGS = -Wall -Wextra -Werror
EXT = c

CC2 = swiftc
CFLAGS2 =
EXT2 = swift

all: $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4) $(NAME_5) $(NAME_6)

$(NAME_1):
	@ $(CC) $(CFLAGS) ex00/$(NAME_1).$(EXT) -o $(NAME_1)

$(NAME_2):
	@ $(CC) $(CFLAGS) ex01/$(NAME_2).$(EXT) -o $(NAME_2)

$(NAME_3):
	@ $(CC) $(CFLAGS) ex02/$(NAME_3).$(EXT) -o $(NAME_3)

$(NAME_4):
	@ $(CC2) $(CFLAGS2) ex03/$(NAME_1).$(EXT2) -o $(NAME_4)

$(NAME_5):
	@ $(CC2) $(CFLAGS2) ex04/$(NAME_2).$(EXT2) -o $(NAME_5)

$(NAME_6):
	@ $(CC2) $(CFLAGS2) ex05/$(NAME_3).$(EXT2) -o $(NAME_6)

clean:
	@ echo "All good here"

fclean:
	@ rm $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4) $(NAME_5) $(NAME_6)

re: fclean all