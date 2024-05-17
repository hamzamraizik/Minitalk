NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER)  -o $(NAME_SERVER) 

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all


# NAME_SERVER = server
# NAME_CLIENT = client
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SRCS_SERVER = server.c
# SRCS_CLIENT = client.c
# OBJS_SERVER = $(SRCS_SERVER:.c=.o)
# OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# %.o: %.c minitalk.h
#     $(CC) $(CFLAGS) -c $< -o $@

# all: $(NAME_SERVER) $(NAME_CLIENT)

# $(NAME_SERVER): $(OBJS_SERVER)
#     $(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

# $(NAME_CLIENT): $(OBJS_CLIENT)
#     $(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

# clean:
#     rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

# fclean: clean
#     rm -f $(NAME_SERVER) $(NAME_CLIENT)

# re: fclean all

# .PHONY: all clean fclean re

