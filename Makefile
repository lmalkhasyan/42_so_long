NAME		= so_long
SRCS 		= $(shell find "." -name "*.c")
OBJS		= $(SRCS:.c=.o)
INCS		= -I./incs
CFLAGS		= -Wall -Wextra -Werror -Imlx $(INCS)
RM			= rm -f
CC			= cc
AR			= ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
