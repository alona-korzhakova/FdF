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

SRC = fdf.c read_map.c add_point.c create_point.c\
		center_map.c rotate_map.c project_map.c\
		draw_image.c handle_key.c display_message.c\
		connect_dots.c draw_pixel.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) $(CFLAG) -c $< $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp $(LIBFT) $(NAME)
	@$(C) $(CFLAG) -o $(NAME) $(OBJ) $(LIBS) $(LINKS)
	@echo FdF compilation is \done :')'
	@echo ----------NAVIGATION-----------
	@echo -------------------------------
	@echo '*' TO MODIFY THE MAP PRESS KEYS:  
	@echo '*' ASWD	- MOVE			  
	@echo '*' ARROWS - ROTATE 			  
	@echo '*' P - CHANGE PROJECTION 
	@echo '*' + - ENLARGE			  
	@echo '*' - - REDUCE 	
	@echo '*' PGUP, PGDN - CHANGE ALTITUDE	 			  
	@echo '*' ENTER - CHANGE COLORS	  
	@echo '*' SPACE - RESET			 
	@echo '*' ESC - CLOSE
	@echo -------------------------------
clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -f $(OBJ) *~
	@echo Object files have been cleaned.

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo FdF has been removed.

re: fclean all
