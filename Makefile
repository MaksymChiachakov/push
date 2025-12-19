# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 12:45:21 by mchiacha          #+#    #+#              #
#    Updated: 2025/12/19 12:45:25 by mchiacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC =	main.c \
		utils.c \
		stack_utils.c \
		stack_swap.c \
		stack_reverse_rotate.c \
		stack_rotate.c \
		stack_push.c \
		push_swap.c \
		sort_greedy.c \
		rotations.c \
		sort_utils.c \
		normalize.c

SRC_BONUS = checker_bonus/main_bonus.c \
			checker_bonus/checker_bonus.c \
			checker_bonus/stack_push_bonus.c \
			checker_bonus/stack_rotate_bonus.c \
			checker_bonus/stack_reverse_rotate_bonus.c \
			checker_bonus/stack_swap_bonus.c \
			stack_utils.c \
			utils.c

LIBFT_DIR = libftprintf
LIBFT = $(LIBFT_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus: $(NAME_BONUS) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc -o $(NAME) $(OBJ) $(LIBFT)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	cc -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)

%.o: %.c
	cc $(FLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS) & make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
