# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 23:03:51 by dramos-p          #+#    #+#              #
#    Updated: 2022/04/03 15:13:52 by dramos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft 
LIB			=	-L ./libft -lft
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/push_swap.c\
				src/linked_lstadd.c\
				src/linked_lstdel.c\
				src/ft_swap.c\
				src/ft_push.c\
				src/ft_rotate.c\
				src/ft_rev_rotate.c\
				src/util.c\
				src/quick_sort.c\
				src/radix_sort.c\
				src/error.c\
				src/small_sort.c\

all:		$(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			rm -rf ${NAME}
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
