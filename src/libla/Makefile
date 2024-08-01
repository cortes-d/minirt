NAME = libla.a

SRCS = 	equalf.c \
		matrix/mat_print.c \
		matrix/submatrix/mat3_submatrix.c \
		matrix/submatrix/mat4_submatrix.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
AR = ar -rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
