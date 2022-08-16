NAME		= push_swap
CNAME		= checker
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror
RM			= /bin/rm -f

LIBFT_DIR	= libft
PRINTF_DIR	= ft_printf

INCLUDE_DIR	= includes
INCLUDES 	= -I$(INCLUDE_DIR) \
			  -I$(LIBFT_DIR) \
			  -I$(PRINTF_DIR)
LIBS		= -L$(LIBFT_DIR) -lft \
			  -L$(PRINTF_DIR) -lftprintf

SRC_DIR		= ./srcs
UTIL_SRCS = \
				utils/setup.c \
				utils/lst_opt.c \
				utils/sorted.c \
				utils/util.c \
				utils/validate.c \
				opts/push.c \
				opts/swap.c \
				opts/rotate.c \
				opts/reverse.c

SRCS		= \
				main.c \
				psort.c \
				qsorta.c \
				qsortb.c \
				$(UTIL_SRCS)

CSRCS = \
				checker.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				$(UTIL_SRCS)

BUILD_DIR	= build
CBUILD_DIR	= cbuild

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
COBJS = $(CSRCS:%.c=$(CBUILD_DIR)/%.o)

all: $(NAME)

bonus: $(CNAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)


$(CNAME): $(COBJS) libs
	$(CC) $(CFLAGS) $(COBJS) $(LIBS) -o $(CNAME)

$(COBJS): $(CBUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

crestart: ccbuild $(COBJS)
	$(CC) $(CFLAGS) $(COBJS) $(LIBS) -o $(CNAME)

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

re: fclean all

cbuild:
	$(RM) -r $(BUILD_DIR)

ccbuild: 
	$(RM) -r $(CBUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

.PHONY: all bonus clean fclean re libs crestart cbuild ccbuild