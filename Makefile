NAME		= push_swap
CC			= gcc
# CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf

INCLUDE_DIR	= includes
INCLUDES 	= -I$(INCLUDE_DIR) \
			  -I$(LIBFT_DIR) \
			  -I$(PRINTF_DIR)
LIBS		= -L$(LIBFT_DIR) -lft \
			  -L$(PRINTF_DIR) -lftprintf

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= 	mylist.c \
				validate.c \
				opts/push.c \
				opts/swap.c \
				opts/rotate.c \
				opts/reverse.c \
				main.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

re: fclean all

cbuild:
	$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

.PHONY: all clean fclean re libs