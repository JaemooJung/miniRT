NAME 		=	miniRT

CC 			=	gcc
CFLAGS		=	-Werror -Wall -Wextra -g
RM			=	rm -f

FILES 		=	main.c \
				error.c \
				ray.c \
				ray_hit_obj.c \
				ray_hit_sp.c \
				ray_hit_cy.c \
				ray_hit_pl.c \
				phong_lighting.c \
				scene.c \
				draw.c \
				utils.c \
				utils_vec_operations.c \
				utils_vec_operations_2.c \
				utils_vec_operations_3.c \
				mlx_utils.c \
				objects.c \
				objects_utils.c \
				get_next_line_utils.c \
				get_next_line.c \
				parser_figure.c \
				parser_type.c \
				parser_unique.c \
				parser_utils.c \
				parser_validation.c \
				parser.c

SRC_DIR		=	./sources/
INC_DIR		=	./includes
MLX_DIR		=	./minilibx
LIBFT_DIR	=	./libft

SRCS		=	$(addprefix $(SRC_DIR), $(FILES))

OBJS		=	$(SRCS:.c=.o)

MLX			=	libmlx.dylib

.PHONY: all clean fclean re

all: $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INC_DIR) -c -o $@ $<

$(MLX):
	make all -C $(MLX_DIR)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $@ $^
	install_name_tool -change libmlx.dylib $(MLX_DIR)/libmlx.dylib $(NAME)
clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	make clean -C minilibx

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	make clean -C minilibx
	
re: clean all