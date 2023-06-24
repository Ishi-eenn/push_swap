CC			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= main.c utils.c utils_stack.c \
			sort.c sort_utils.c get_input.c sort_utils2.c \
			push.c rotate.c reverse_rotate.c swap.c libft.c
# BONUS_SRCS	=

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
NAME		= push_swap
BONUS_NAME	= checkerbbb
RM 			= rm -f

all	: $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) -o $(BONUS_NAME) $(CFLAGS) $(BONUS_OBJS)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY : all clean fclean re
