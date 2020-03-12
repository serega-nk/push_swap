# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:53:48 by bconchit          #+#    #+#              #
#    Updated: 2020/03/13 00:03:41 by bconchit         ###   ########.fr        #
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
		$(addprefix stage1/, \
			stage1_free.c \
			stage1_init.c \
			stage1_median.c \
			stage1_play.c \
			stage1_sequence.c \
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
	rm -rf $(NAME_1).dSYM
	rm -rf $(NAME_2).dSYM
	rm -rf $(NAME_1)
	rm -rf $(NAME_2)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS_1) $(SRCS_2)

test: $(NAME_1) $(NAME_2)
	ARG=`ruby -e "puts (1..1).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG; ./push_swap $$ARG | wc -l

test1: $(NAME_2)
	./push_swap 4 3 2 1 0 -1

test2: $(NAME_2)
	./push_swap 2 3 4 5 6 0 1

test3: $(NAME_2)
	./push_swap 5 6 0 1 2 3 4

test4: $(NAME_2)
	./push_swap 2 3 1

test5: $(NAME_2)
	./push_swap 2 1 5 3 22 17 8 10 30 23 12 99 18 14 4

error: $(NAME_1)
	./push_swap "-" | true
	./push_swap "-0-" | true
	./push_swap "-0+" | true
	./push_swap " - 0" | true
	./push_swap "9-" | true
	./push_swap "123a" | true
	./push_swap "                              908         -00-1" | true
	./push_swap "-0-0" | true

success: $(NAME_1)
	./push_swap ""
	./push_swap "         "
	./push_swap "                           9"
	./push_swap "         9                "
	./push_swap " 2 4 5 6                  7               "
	./push_swap "                               987  "

.PHONY: all clean fclean re norm test error success
