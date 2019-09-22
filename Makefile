# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bphofuya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 18:08:54 by bphofuya          #+#    #+#              #
#    Updated: 2019/09/20 13:21:47 by bphofuya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Werror -Wextra -Wall

NAME = ft_ls

SRC =	ft_a.c \
		ft_rec.c \
		print_list.c \
		print_sort_t.c \
		add_node_to_list.c \
		sort.c \
		sort_rev.c \
		node.c \
		create_list.c \
		read_files.c \
		read_flags.c \
		sort_t.c \
		print.c \
		listlen.c \
		swap.c \
		ft_ls.c \
		filepath.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a
	echo "$(NAME) Created"

$(OBJ): %.o: %.c
	gcc $(FLAG) -c $< -o $@
	echo "Objects created"

clean:
	rm -rf *.o
	echo "Objects deleted"

fclean: clean
	rm -rf $(NAME)
	echo "$(NAME) Deleted"

re: fclean all
