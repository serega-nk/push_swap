# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 11:53:48 by bconchit          #+#    #+#              #
#    Updated: 2020/03/13 11:57:05 by bconchit         ###   ########.fr        #
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

reverse:
	./push_swap "500 499 498 497 496 495 494 493 492 491 490 489 488 487 486 485 484 483 482 481 480 479 478 477 476 475 474 473 472 471 470 469 468 467 466 465 464 463 462 461 460 459 458 457 456 455 454 453 452 451 450 449 448 447 446 445 444 443 442 441 440 439 438 437 436 435 434 433 432 431 430 429 428 427 426 425 424 423 422 421 420 419 418 417 416 415 414 413 412 411 410 409 408 407 406 405 404 403 402 401 400 399 398 397 396 395 394 393 392 391 390 389 388 387 386 385 384 383 382 381 380 379 378 377 376 375 374 373 372 371 370 369 368 367 366 365 364 363 362 361 360 359 358 357 356 355 354 353 352 351 350 349 348 347 346 345 344 343 342 341 340 339 338 337 336 335 334 333 332 331 330 329 328 327 326 325 324 323 322 321 320 319 318 317 316 315 314 313 312 311 310 309 308 307 306 305 304 303 302 301 300 299 298 297 296 295 294 293 292 291 290 289 288 287 286 285 284 283 282 281 280 279 278 277 276 275 274 273 272 271 270 269 268 267 266 265 264 263 262 261 260 259 258 257 256 255 254 253 252 251 250 249 248 247 246 245 244 243 242 241 240 239 238 237 236 235 234 233 232 231 230 229 228 227 226 225 224 223 222 221 220 219 218 217 216 215 214 213 212 211 210 209 208 207 206 205 204 203 202 201 200 199 198 197 196 195 194 193 192 191 190 189 188 187 186 185 184 183 182 181 180 179 178 177 176 175 174 173 172 171 170 169 168 167 166 165 164 163 162 161 160 159 158 157 156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"

.PHONY: all clean fclean re norm test error success
