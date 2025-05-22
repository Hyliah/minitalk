NAME_CLIENT = client
NAME_SERVER = server

SRCDIR = .
OBJDIR = $(SRCDIR)

PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a

SRC_CLIENT =	client.c
SRC_SERVER =	server.c

OBJS_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRC_SERVER:%.c=%.o)

CC = gcc

INCLUDE = -I include

RM = rm -f 

CFLAGS = -g3 -Wall -Wextra -Werror

all: $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER) 

$(PRINTF):
	$(MAKE) all -C $(PRINTFDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(NAME_SERVER)

bonus: all

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) 
		$(MAKE) clean -C $(PRINTFDIR)
fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re
