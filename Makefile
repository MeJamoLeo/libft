NAME	= libft.a
SRCS	= ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_strlcpy.c \
			ft_memcpy.c \
			ft_memccpy.c

OBJS	= $(SRCS:%.c=%.o)
CC		= gcc
CFCLAGS	= -Wall -Wextra -Werror -I. -c
RM		= rm -f

.c.o:
	$(CC) $(CFCLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFCLAGS) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
