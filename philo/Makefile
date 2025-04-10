NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
PTHREAD     = -pthread
RM          = rm -rf

# Directories
SRC_DIR     = srcs
FEATURES_DIR= $(SRC_DIR)/features
INIT_DIR	= $(SRC_DIR)/init

# Header and Includes
HEADER      = includes/philo.h
INCLUDES    = -I includes

# Source Files
SRC_MAIN    = main.c
FEATURES    = ft_putstr_fd2.c ft_strlen.c ft_atoi.c
INIT		= init_philosophers.c parse_arguments.c init_mutex.c 

SRC = $(addprefix $(SRC_DIR)/, $(SRC_MAIN)) \
      $(addprefix $(FEATURES_DIR)/, $(FEATURES)) \
      $(addprefix $(INIT_DIR)/, $(INIT))

OBJ         = $(SRC:.c=.o)

# Colors
GREEN       = \033[92;5;118m
YELLOW      = \033[93;5;226m
GRAY        = \033[33;2;37m
RESET       = \033[0m
CURSIVE     = \033[33;3m

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE)$(GRAY)  - Compiling $(NAME)... $(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(PTHREAD) -o $(NAME)
	@printf "$(GREEN)    - Executable ready.$(RESET)\n"

%.o: $(SRC_DIR)/%.c $(HEADER)
	@printf "$(CURSIVE)$(GRAY)  - Compiling $< into $@...$(RESET)\n"
	@$(CC) $(CFLAGS) $(INCLUDES) $(PTHREAD) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@printf "$(YELLOW)    - Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
