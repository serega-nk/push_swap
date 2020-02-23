# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 03:51:16 by bconchit          #+#    #+#              #
#    Updated: 2020/02/23 13:23:20 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= checker.h
SOURCES		= \
	$(addprefix checker/, \
		$(addprefix app/, \
			app_error.c \
			app_free.c \
			app_init.c \
			app_load.c \
			app_play.c \
		) \
		$(addprefix play/, \
			play_pa.c \
			play_pb.c \
			play_ra.c \
			play_rb.c \
			play_rra.c \
			play_rrb.c \
			play_rr.c \
			play_rrr.c \
			play_sa.c \
			play_sb.c \
			play_ss.c \
		) \
		$(addprefix stack/, \
			stack_append.c \
			stack_create.c \
			stack_destroy.c \
			stack_empty.c \
			stack_item.c \
			stack_ordered.c \
			stack_pop.c \
			stack_push.c \
			stack_reverse_rotate.c \
			stack_rotate.c \
			stack_swap.c \
			stack_unique.c \
		) \
		main.c \
	) \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/includes/
LFLAGS		= -L$(LIBFT_DIR)/ -lft

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

test: $(NAME)
	#cat 1.txt | ./checker 3 2 1 0
	./checker 3 2 one 0

.PHONY: all clean fclean re norm $(LIBFT)
