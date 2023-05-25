NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= MLX42
CC		:= gcc

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./Sources -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

LIBFT	:=./libft/libft.a

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# makelibft:
# 	@$(MAKE) -C ./libft
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
# $(MAKE) clean -C ./libft

fclean: clean
	@rm -f $(NAME)
#$(MAKE) fclean -C ./libft

re: clean all

.PHONY: all, clean, fclean, re, libmlx

#for linux wsl il faut just    LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit