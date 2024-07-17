# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:20:22 by mariaoli          #+#    #+#              #
#    Updated: 2024/05/02 15:30:33 by mariaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LIBFT = libft.a
LIBFT_DIR = ./libft

SRCS = 	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_putxnbr.c ft_putpnbr.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

RM = rm -f

EXEC = a.out

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_DIR)/$(LIBFT):
	make all -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(EXEC) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
