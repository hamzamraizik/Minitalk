NAME_SERVER = server
NAME_CLIENT = client
B_NAME_SERVER = server_bonus
B_NAME_CLIENT = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# bonus
B_SRCS_SERVER = server_bonus.c utils.c
B_SRCS_CLIENT = client_bonus.c utils.c
B_OBJS_SERVER = $(B_SRCS_SERVER:.c=.o)
B_OBJS_CLIENT = $(B_SRCS_CLIENT:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(B_NAME_SERVER) $(B_NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER)  -o $(NAME_SERVER) 

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)
 # bonus
$(B_NAME_SERVER): $(B_OBJS_SERVER)
	$(CC) $(CFLAGS) $(B_OBJS_SERVER)  -o $(B_NAME_SERVER) 

$(B_NAME_CLIENT): $(B_OBJS_CLIENT)
	$(CC) $(CFLAGS) $(B_OBJS_CLIENT) -o $(B_NAME_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(B_OBJS_CLIENT) $(B_OBJS_SERVER)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(B_NAME_CLIENT) $(B_NAME_SERVER)

re: fclean all
