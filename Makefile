CFILE = client.c
SFILE = server.c
O_CFILE = client.o
O_SFILE = server.o
CFLAGS = -Wall -Wextra
CC = cc
RM = rm -f

all: server client

client.o : client.c
	$(CC) $(CFLAGS) -c $<

server.o : server.c
	$(CC) $(CFLAGS) -c $<

server: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(O_SFILE)


client: $(OFILES)
	$(CC) $(CFLAGS) -o $@ $(O_CFILE)

clean:
	$(RM) $(O_CFILE) $(O_SFILE)

fclean: clean
	$(RM) server client

re: fclean all