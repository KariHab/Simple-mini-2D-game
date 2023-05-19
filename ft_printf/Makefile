NAME = libftprintf.a

# Sources are all .c files
SRCS =  ft_printf.c\
		ft_printu.c\
		ft_printhex.c\
		ft_printptr.c

OBJS	=	$(SRCS:.c=.o)


# le compilateur et les flags pour compiler
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# LIBFT = libft.a
# LDIR = libft/

# Pour obtenir les .o de chaque .c 
$(NAME): $(OBJS) # $(LDIR)$(LIBFT)
# cp $(LDIR)$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)  #$(LDIR)$(LIBFT)

# pour make la libft
# $(LDIR)$(LIBFT):
# 	$(MAKE) -C $(LDIR)


# Pour supprimer les .o qu'on a genere
clean:
	$(RM) $(OBJS)
# $(RM) $(LDIR)*.o

# on clean tout donc .o et les exe
fclean: clean
	$(RM) $(NAME)
# $(RM) $(LDIR)$(LIBFT)


re: fclean all