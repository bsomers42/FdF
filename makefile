# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bsomers <bsomers@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 10:36:12 by bsomers       #+#    #+#                  #
#    Updated: 2022/06/10 15:08:10 by bsomers       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft

LIBMLX42 = libmlx42

SRC = FdF.c \
		FdF_utils.c \
		FdF_parse.c \
		FdF_draw.c \
		FdF_bresenham.c \
		FdF_user_input.c

HEADER = FdF.h

CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT).a $(LIBMLX42).a
		$(CC) $(CFLAGS) libmlx42.a -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -L. -lft $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) -Imlx -c $(CFLAGS) -o $@ $<

$(LIBFT).a:
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a .

$(LIBMLX42).a:
	@make -C ./MLX42
	@cp ./MLX42/$(LIBMLX42).a .

clean:
		rm -f $(OBJ)
		@make clean -C $(LIBFT)
		@make clean -C ./MLX42


fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT).a
		rm -f $(LIBMLX42).a
		@make fclean -C $(LIBFT)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re