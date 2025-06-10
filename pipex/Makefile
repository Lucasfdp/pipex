CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = pipex.c main.c

OBJ_FILES = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re



# # ───── Compiler & Flags ─────
# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror

# # ───── Project Name ─────
# NAME    = so_long

# # ───── Directories ─────
# SRC_DIR     = src
# LIBFT_DIR   = ./libft

# # ───── Source Files ─────
# SRCS        = $(wildcard $(SRC_DIR)/*.c)
# OBJS        = $(SRCS:.c=.o)

# # ───── Libft ─────
# LIBFT       = $(LIBFT_DIR)/libft.a

# # ───── Platform Detection for MiniLibX ─────
# UNAME       := $(shell uname)

# ifeq ($(UNAME), Darwin)
# 	MLX


# CC      = cc
# CFLAGS  = -Wall -Wextra -Werror

# NAME    = so_long

# LIBFT_DIR = ./libft
# LIBFT     = $(LIBFT_DIR)/libft.a

# MLX_DIR   = ./mlx_linux
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# SRC_DIR = src
# SRCS    = $(wildcard $(SRC_DIR)/*.c)
# OBJS    = $(SRCS:.c=.o)

# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	@$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# clean:
# 	@$(MAKE) -C $(LIBFT_DIR) clean
# 	@rm -f $(OBJS)

# fclean: clean
# 	@$(MAKE) -C $(LIBFT_DIR) fclean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
