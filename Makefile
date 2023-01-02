NAME = miniRT

SRC_DIR = srcs/
OBJ_DIR = objs/

SRC_FILE = scene_read scene_assign scene_set scene_utils \
	hit hit_sphere hit_plane hit_cylinder hit_utils \
	camera trace color_utils render_utils event\
	matrix_utils vect_utils_1 vect_utils_2 vect_utils_3 \
	main
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

HDR_DIR = includes/
HDR_FILE = mini_rt
HDR_INC = $(addprefix -I, $(HDR_DIR))
HDRS = $(addprefix $(HDR_DIR), $(addsuffix .h, $(HDR_FILE)))

LIB_DIR = libft/
LIB_INC = $(addprefix -I, $(addsuffix $(HDR_DIR), $(filter-out $(MLX), $(LIB_DIR))))
LIB_BINARY = -lm -Llibft -lft

ifeq ($(shell uname), Linux)
MLX = minilibx-linux
LIB_DIR += $(MLX)
LIB_INC += -I/usr/include/ -I$(MLX)/
LIB_BINARY += -L$(MLX) -lmlx -L/usr/lib -lXext -lX11
endif

ifeq ($(shell uname), Darwin)
MLX = minilibx_opengl
LIB_DIR += $(MLX)
LIB_INC += -I$(MLX)/
LIB_BINARY += -L$(MLX) -lmlx -framework OpenGL -framework AppKit
endif

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm
NORM = Norminette

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIB_BINARY)
	@echo "/// ----- tik tak boom ------ ///"

bonus: all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HDR_INC) $(LIB_INC) -c $< -o $@

lib:
ifeq ("$(wildcard $(MLX))", "")
	@mkdir -p $(MLX)
	@tar -xf $(MLX).tgz -C $(MLX)
	@mv $(MLX)/*/* $(MLX)
endif
	$(foreach f, $(LIB_DIR), make -C $f;)

norm:
	$(foreach f, $(filter-out $(MLX), $(LIB_DIR)), make norm -C $f;)
	@$(NORM) -R CheckForbiddenSourceHeader $(SRC_DIR) | grep -v Norme -B1 || true
	@$(NORM) -R CheckDefine $(HDRS) | grep -v Norme -B1 || true

clean:
	$(RM) -rf $(OBJ_DIR)
	$(foreach f, $(LIB_DIR), make clean -C $f;)

fclean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -f $(NAME)
	$(RM) -rf $(NAME).dSYM
	make clean -C $(MLX)
	$(foreach f, $(filter-out $(MLX), $(LIB_DIR)), make fclean -C $f;)

re: fclean all

.PHONY: all clean fclean re lib norm bonus
