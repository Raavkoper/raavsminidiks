NAME = minishell

HEADER = includes/minishell.h

CFLAGS = -g -fsanitize=address

CC = gcc

LIBFT = libraries/libft/libft.a

SRCS = main.c lexer.c is_check.c

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT) $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C libraries/libft

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "\033[92mFiles made🤔\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[1;34mA\033[1;31ml\033[1;32ml \033[1;33mc\033[1;30ml\033[1;35me\033[1;36ma\033[1;37mn\033[0m"

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "\033[0;31mFiles killed💀❌\033[0m"

re:	fclean all

.PHONY: all clean fclean re