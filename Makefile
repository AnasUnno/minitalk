CC = cc

SERVER = server 

CLIENT = client

FILE_M =  minitalk_utils minitalk_utils2

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

SRCS_M = $(addsuffix .c, $(FILE_M))
OBJS_M = $(addsuffix .o, $(FILE_M))

all 	: $(SERVER) $(CLIENT)

$(NAME) : all


$(SERVER)	: $(OBJS_M) $(HEADER)
	$(CC) $(CFLAGS) server.c $(OBJS_M) -o $(SERVER)

$(CLIENT)	: $(OBJS_M) $(HEADER)
	$(CC) $(CFLAGS) client.c $(OBJS_M) -o $(CLIENT)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean	:
	rm -rf $(OBJS_M)
fclean	: clean
	rm -rf $(CLIENT) $(SERVER)
re 		: fclean all