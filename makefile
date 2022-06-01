# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bsomers <bsomers@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 10:36:12 by bsomers       #+#    #+#                  #
#    Updated: 2022/06/01 16:38:00 by bsomers       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = FdF

LIBFT = libft

LIBMLX = libmlx

SRC = FdF.c \
		FdF_utils.c \
		FdF_parse.c \
		FdF_draw.c \
		FdF_bresenham.c

HEADER = FdF.h

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT).a $(LIBMLX).a
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -L. -lft $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) -Imlx -c $(CFLAGS) -o $@ $<

$(LIBFT).a:
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT).a .

$(LIBMLX).a:
	@make -C ./mlx
	@cp ./mlx/$(LIBMLX).a .

clean:
		rm -f $(OBJ)
		@make clean -C $(LIBFT)
		@make clean -C ./mlx


fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT).a
		rm -f $(LIBMLX).a
		@make fclean -C $(LIBFT)

re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re