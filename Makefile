NAME = so_long

SRC = src/so_long.c src/character_moves.c src/cleaning.c src/map_filling.c src/map_outline.c src/parsing.c src/set_up_map.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I mlx_linux -I libft -I includes -I usr/include

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< 

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C libft --no-print-directory
	@make re -C mlx_linux --no-print-directory

	@$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${INCLUDES} -o ${NAME}

clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re re_bonus bonus