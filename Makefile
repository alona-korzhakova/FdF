# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 18:35:56 by akorzhak          #+#    #+#              #
#    Updated: 2018/01/13 18:35:58 by akorzhak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

C = gcc

CFLAG = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

INC = -I ./includes -I ./libft -I /usr/local/include

LIBDIR = libft

LIBFT = $(LIBDIR)/libft.a

LIBS = -L /usr/local/lib/ -lmlx -L ./libft -lft

SRCDIR = src

SRC = fdf.c addPoint.c createPoint.c rotateMap.c projectMap.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) $(CFLAG) -c $< $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp $(LIBFT) $(NAME)
	@$(C) $(CFLAG) -o $(NAME) $(OBJ) $(LIBS) $(LINKS)
	@echo FdF compilation is \done'!' :')'	
	@./$(NAME) ./maps/42.fdf

clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -f $(OBJ) *~
	@echo Object files have been cleaned.

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo FdF has been removed.

re: fclean all
