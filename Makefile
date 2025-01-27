NAME = minitalk

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

SRC =	src/client.c \
		src/server.c

SRC_BONUS =	src_bonus/client_bonus.c \
			src_bonus/server_bonus.c

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror 

BONUS_OBJ = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(LIBFT_A) $(CLIENT) $(SERVER)

$(CLIENT): src/client.o
	@$(CC) $(CC_FLAGS) src/client.o $(LIBFT_A) -o $(CLIENT)

$(SERVER): src/server.o
	@$(CC) $(CC_FLAGS) src/server.o $(LIBFT_A) -o $(SERVER)

bonus: $(LIBFT_A) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): src_bonus/client_bonus.o
	@$(CC) $(CC_FLAGS) src_bonus/client_bonus.o $(LIBFT_A) -o $(CLIENT_BONUS)

$(SERVER_BONUS): src_bonus/server_bonus.o
	@$(CC) $(CC_FLAGS) src_bonus/server_bonus.o $(LIBFT_A) -o $(SERVER_BONUS)

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make fclean -C $(LIBFT)

re: fclean all

c:
	@find . -type f -iname "*.c" -exec grep "//" {} +

.PHONY: all clean fclean re c bonus 
