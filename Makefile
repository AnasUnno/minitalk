CC = cc

SERVER = server 

CLIENT = client

SERVER_B = server_b

CLIENT_B = client_b

FILE_M =  minitalk_utils minitalk_utils2

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

SRCS_M = $(addsuffix .c, $(FILE_M))
OBJS_M = $(addsuffix .o, $(FILE_M))

all 	: $(SERVER) $(CLIENT)

$(NAME) : all


$(SERVER)	: $(OBJS_M) $(HEADER) server.c
	$(CC) $(CFLAGS) server.c $(OBJS_M) -o $(SERVER)

$(CLIENT)	: $(OBJS_M) $(HEADER) client.c
	$(CC) $(CFLAGS) client.c $(OBJS_M) -o $(CLIENT)
$(SERVER_B)	: $(OBJS_M) $(HEADER) server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c $(OBJS_M) -o $(SERVER_B)
$(CLIENT_B)	: $(OBJS_M) $(HEADER) client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c $(OBJS_M) -o $(CLIENT_B)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : $(SERVER_B) $(CLIENT_B)


clean	:
	rm -rf $(OBJS_M)
fclean	: clean
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)
re 		: fclean all