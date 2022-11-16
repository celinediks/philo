
# -*- Makefile -*-
CC = clang

CFLAGS = -Wall -Werror -Wextra -pthread -fsanitize=thread

SOURCES = src/main.c src/utils.c src/init.c src/check.c src/actions.c

REG_OBJFILES = $(SOURCES:.c=.o)

NAME = philo

# -*- colors -*-
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[1;33m
BLUE=\e[0;34m
MAG=\e[0;35m
NC=\033[0m

all: $(NAME)
	@echo "${GREEN}Done making all files:)${NC}"

$(NAME): $(SOURCES)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)
	  
clean: 
	@rm -f $(REG_OBJFILES)

fclean: clean
	@rm -f $(NAME)
	@echo "${GREEN}Everything clean!${NC}"

re: fclean all

.PHONY: all clean fclean re