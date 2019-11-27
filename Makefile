# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmienk <lsmienk@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/15 12:17:27 by lsmienk        #+#    #+#                 #
#    Updated: 2019/07/05 16:41:50 by lsmienk       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = main controls drawinfo mandelbrot valid_argument magic_loop fractol_loop \
colour_convert burningship julia mouse_control tricorn basic_setup
SRCF = $(SRC:%=srcs/%.c)
OBJ = $(SRC:%=%.o)
NAME = fractol
MINILIBX = -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

MAKECOLOUR = \033[38;5;208m
CLEANCOLOUR = \033[38;5;229m
FCLEANCOLOUR = \033[38;5;214m
LIBCOLOUR = \033[38;5;220m
RESETCOLOUR = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCF)
	@echo "$(LIBCOLOUR)Compiling Libraries$(RESETCOLOUR)"
	@make -C libft/
	@make -C minilibx/
	@echo "$(MAKECOLOUR)Compiling Program$(RESETCOLOUR)"
	@clang $(FLAGS) -I minilibx -I libft/includes -c $(SRCF)
	@clang -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

clean:
	@echo "$(CLEANCOLOUR)Cleaning Libraries$(RESETCOLOUR)"
	@make -C libft/ clean
	@make -C minilibx/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "$(FCLEANCOLOUR)Removing Libraries and $(NAME) $(RESETCOLOUR)"
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all