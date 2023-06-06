NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror
LIBMLX  = ./MLX42
CC		= gcc
RM      = rm -f


HEADERS	= -I ./include -I $(LIBMLX)/include
# LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS    = ./Sources/Events.c\
			./Sources/Init_load.c\
			./Sources/main.c\
			./Sources/Parsing_0.c\
			./Sources/Parsing_1.c\
			./Sources/Rendering_0.c\
			./Sources/Rendering_1.c\
			./Sources/Utils_Functions.c

# SRCS	= $(shell find ./Sources -iname "*.c")
OBJS	= $(SRCS:%.c=%.o)

LIBFT	=./Sources/libft/libft.a

all: $(NAME)

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


$(NAME): $(OBJS)
	@$(MAKE) -C ./Sources/libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ./MLX42/build
	@$(MAKE) clean -C ./Sources/libft

fclean: clean
	@$(RM) $(NAME)
	@rm -rf ./MLX42/build
	@$(MAKE) fclean -C ./Sources/libft

re: fclean mlx all 

.PHONY: all, clean, fclean, re, libmlx

#for linux wsl il faut just    LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit