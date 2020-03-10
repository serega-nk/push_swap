# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:53:48 by bconchit          #+#    #+#              #
#    Updated: 2020/03/10 07:46:05 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1		= checker
NAME_2		= push_swap

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= checker.h play.h push_swap.h stack.h

SOURCES_S	= \
	$(addprefix stack/, \
		stack_append.c \
		stack_clean.c \
		stack_count.c \
		stack_create.c \
		stack_destroy.c \
		stack_empty.c \
		stack_get.c \
		stack_item_destroy.c \
		stack_item.c \
		stack_load.c \
		stack_next.c \
		stack_ordered.c \
		stack_pop.c \
		stack_push.c \
		stack_reverse_rotate.c \
		stack_rotate.c \
		stack_start.c \
		stack_swap.c \
		stack_to_array.c \
		stack_unique.c \
	) \

SOURCES_P	= \
	$(addprefix play/, \
		play_create.c \
		play_destroy.c \
		play_output.c \
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

SOURCES_1	= \
	$(SOURCES_S) \
	$(SOURCES_P) \
	$(addprefix checker/, \
		$(addprefix app/, \
			app_error.c \
			app_free.c \
			app_load.c \
			app_play.c \
		) \
		main.c \
	) \

SOURCES_2	= \
	$(SOURCES_S) \
	$(SOURCES_P) \
	$(addprefix push_swap/, \
		$(addprefix app/, \
			app_error.c \
			app_free.c \
			app_load.c \
			app_output.c \
			app_stage1.c \
			app_stage2.c \
			app_stage3.c \
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
SRCS_1		= $(addprefix $(SRC_DIR)/, $(SOURCES_1))
SRCS_2		= $(addprefix $(SRC_DIR)/, $(SOURCES_2))
OBJS_1		= $(addprefix $(OBJ_DIR)/, $(SOURCES_1:.c=.o))
OBJS_2		= $(addprefix $(OBJ_DIR)/, $(SOURCES_2:.c=.o))

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(LIBFT) $(OBJS_1)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_1) $(LFLAGS) -o $@

$(NAME_2): $(LIBFT) $(OBJS_2)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_2) $(LFLAGS) -o $@

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
	rm -rf $(NAME_1)
	rm -rf $(NAME_2)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS_1) $(SRCS_2)

test: $(NAME_1)
	echo "rra\npb\nsa\nrra\npa" | ./checker 3 2 1 0

.PHONY: all clean fclean re norm test
