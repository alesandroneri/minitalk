NAME = minitalk

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

SRC =	src/client.c \
		src/server.c

BONUS_SRC =	src_bonus/client_bonus.c \
		src_bonus/server_bonus.c 

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(SRC_BONUS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT_A) 

bonus: $(LIBFT_A) $(NAME)

$(NAME): $(BONUS_OBJ)
	@$(CC) $(CC_FLAGS) $(BONUS_OBJ) $(LIBFT_A)

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

r:$(NAME)
	clear
	@echo "Input: ${var}"
	@./$(NAME) ${var}

v: $(NAME)
	clear
	@echo "input: ${var}\n"
	@valgrind -s --track-origins=yes  --leak-check=full --show-leak-kinds=all ./$(NAME) ${var}

c:
	@find . -type f -iname "*.c" -exec grep "//" {} +

.PHONY: all clean fclean re v c bonus t
