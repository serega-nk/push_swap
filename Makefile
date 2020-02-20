# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 03:51:16 by bconchit          #+#    #+#              #
#    Updated: 2020/02/20 07:48:24 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= checker.h
SOURCES		= \
	$(addprefix checker/, \
		$(addprefix stack/, \
			stack_append.c \
			stack_count.c \
			stack_create.c \
			stack_destroy.c \
			stack_is_empty.c \
			stack_is_ordered.c \
			stack_pop.c \
			stack_push.c \
		) \
		main.c \
	) \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/includes/

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $^ -o $@

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
