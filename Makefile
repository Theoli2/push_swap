CC			= gcc
CFLAGS		= -Wextra -Wall -Werror -g3 #-fsanitize=address
NAME		= push_swap
BONUS_NAME	= checker

LIBFT_PATH	= ./libft/
LIBFT		= $(LIBFT_PATH)libft.a

SRC_PATH 	= srcs/
OBJ_PATH 	= obj/
BONUS_SRC_PATH = push_swap_bonus/srcs/
BONUS_OBJ_PATH = push_swap_bonus/obj/

SRC     =   main.c \
			verif.c \
			utils.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_rotate.c \
			small_sort.c \
			index.c \
			big_sort.c \
			big_sort_bis.c \
			calculate_moves.c \
			calculate_moves_rev.c \
			do_rotate.c \



BONUS_SRC	= main.c \
			verif_pile.c \
			utils.c \
			read.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			execution.c \


			


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
BONUS_SRCS = $(addprefix $(BONUS_SRC_PATH), $(BONUS_SRC))
OBJ		= $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_PATH), $(BONUS_OBJ))
INCS	= -I ./includes/
BONUS_INCS = -I ./push_swap_bonus/includes/

 all: $(OBJ_PATH) $(NAME) $(BONUS_OBJ_PATH) $(BONUS_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(BONUS_OBJ_PATH)%.o: $(BONUS_SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(BONUS_OBJ_PATH):
	mkdir $(BONUS_OBJ_PATH)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ_PATH) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)
	rm -rf $(BONUS_OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

norm: 
	norminette $(LIBFT_PATH) $(SRC_PATH) $(BONUS_SRC_PATH)

.PHONY: all clean fclean re
