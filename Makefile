NAME	= libft.a
SRCS	= ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_strlcpy.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

B_SRCS	= ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS	= $(SRCS:%.c=%.o)
B_OBJS	= $(B_SRCS:%.c=%.o)
CC		= gcc
CFCLAGS	= -Wall -Wextra -Werror -I. -c
RM		= rm -f

.c.o:
	$(CC) $(CFCLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
bonus:	 all $(B_OBJS)
	ar rc $(NAME) $(B_OBJS)

$(OBJS):
	$(CC) $(CFCLAGS) $(SRCS)
$(B_OBJS):
	$(CC) $(CFCLAGS) $(B_SRCS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
