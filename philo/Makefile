NAME        = philo

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
PTHREAD     = -pthread
RM          = rm -rf

# Directories
SRC_DIR     = srcs
FEATURES_DIR= $(SRC_DIR)/features
INIT_DIR	= $(SRC_DIR)/init
SIMULATION_DIR	= $(SRC_DIR)/simulation

# Header and Includes
HEADER      = includes/philo.h
INCLUDES    = -I includes

# Source Files
SRC_MAIN    = main.c
FEATURES    = display_status.c ft_atoi.c        ft_putstr_fd2.c  ft_strlen.c      system_time.c
INIT		= init_mutex.c             init_philos_simulation.c init_philosophers.c      parse_arguments.c
SIMULATION  = eating.c           philo_simulation.c pick_up_fork.c     put_down_fork.c    sleep_think.c


SRC = $(addprefix $(SRC_DIR)/, $(SRC_MAIN))  $(addprefix $(FEATURES_DIR)/, $(FEATURES))  $(addprefix $(INIT_DIR)/, $(INIT)) $(addprefix $(SIMULATION_DIR)/, $(SIMULATION))

OBJ         = $(SRC:.c=.o)

# Colors
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
GRAY        = \033[0;37m
RESET       = \033[0m
ITALIC      = \033[3m

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ITALIC)$(GRAY)→ Building executable: $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(PTHREAD) -o $(NAME)
	@echo "$(GREEN)✓ Build complete: $(NAME) is ready to run.$(RESET)"

%.o: $(SRC_DIR)/%.c $(HEADER)
	@echo "$(ITALIC)$(GRAY)→ Compiling: $< → $@$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(PTHREAD) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(YELLOW)• Cleanup done: Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)• Full cleanup complete: Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
