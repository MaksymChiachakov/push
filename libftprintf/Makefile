# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 12:48:31 by mchiacha          #+#    #+#              #
#    Updated: 2025/12/19 12:48:35 by mchiacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putarg.c ft_putint.c ft_putstr.c ft_intlen.c ft_putunsigned.c ft_putptr.c
SRC_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

HEADERS = ./get_next_line/ ./

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(OBJ_GNL)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) $(OBJ_GNL)

%.o: %.c
	cc $(FLAGS) -o $@ -c $< -I HEADERS

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ) $(OBJ_GNL) & make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
