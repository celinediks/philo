# -*- Makefile -*-
CC = clang

CFLAGS = -Wall -Werror -Wextra

SOURCES = src/main.c src/utils.c src/init.c src/check.c src/actions.c src/mutex.c src/time.c

REG_OBJFILES = $(SOURCES:.c=.o)

HEADER = includes/philo.h

NAME = philo

# -*- colors -*-
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[1;33m
BLUE=\e[0;34m
MAG=\e[0;35m
NC=\033[0m

all: $(BUILD_PATH) $(NAME)
	@echo "${GREEN}Done compiling all files:)${NC}"

%.o: %.c $(HEADER)
	@echo "${YELLOW}Compiling ${notdir $<}${NC}"
	@$(CC) -c $(CFLAGS) -I includes -o $@ $<

$(NAME): $(REG_OBJFILES)
	@$(CC) $(CFLAGS) $(REG_OBJFILES) -o $(NAME)

	  
clean: 
	@rm -f $(REG_OBJFILES)

fclean: clean
	@rm -f $(NAME)
	@echo "${GREEN}Everything clean!${NC}"

re: fclean all

.PHONY: all clean fclean re