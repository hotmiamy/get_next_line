SRCFILES = get_next_line.c get_next_line_utils.c

OBJFILES = $(SRCFILES:.c=.o)

CC = gcc
CCFLAGS =  -Wall -Wextra -Werror -g -D
BS ?= BUFFER_SIZE
NAME = get_next_line.a

AR = ar
RM = rm -f
ARFLAGS = rcs

.c.o:
	$(CC) $(CCFLAGS) $(BS) -c $^

$(NAME): $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

out: $(OBJFILES) main.c
	$(CC) $(CCFLAGS) $(BS) $^

all: $(NAME)

clean:
	$(RM) $(OBJFILES)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean out
