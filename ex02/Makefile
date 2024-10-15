
NAME	:= program

SRCS	:= main.cpp

OBJ_DIR	:= .build
OBJS	:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra -Wpedantic -Wunreachable-code -Wuninitialized -std=c++11
RM		:= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(DFLAGS) -o $(NAME)
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@printf "$(REMOVED)" $(OBJ_DIR) $(CUR_DIR)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# ----------------------------------- messages ------------------------------- #

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= $(MAGENTA) $(BOLD) REMOVED %s (%s) $(RESET)\n\n
CREATED	:= $(GREEN) $(BOLD) CREATED %s (%s) $(RESET)\n\n
UPDATED	:= $(GREEN) $(BOLD) CREATED OR UPDATED %s (%s) $(RESET)\n\n

