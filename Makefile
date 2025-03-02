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

clean:
		$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) 
		$(MAKE) clean -C $(PRINTFDIR)
fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) fclean -C $(PRINTFDIR)

re: fclean all

.PHONY: all clean fclean re



# NAME := minitalk.a
# CFLAGS= -Wall -Werror -Wextra -I./

# SRCS= client.c server.c minitalk.h

# B_SRCS = 

# OBJDIR= ./obj/



# OBJS = ${SRCS:%.c=${OBJDIR}%.o}
# OBJS_BONUS = ${B_SRCS:%.c=${OBJDIR}%.o}

# all: $(NAME)

# ${OBJDIR}%.o: %.c
# 	@mkdir -p ${OBJDIR}
# 	@printf "Compiling %s\n" $<
# 	@gcc -c $(CFLAGS) $< -o $@

# bonus: $(OBJS_BONUS)
# 	@printf "making bonus\n"
# 	@ar -rcs $(NAME) $(OBJS_BONUS)

# $(NAME): $(OBJS)
# 	@printf "Compiled library\n"
# 	@ar -rcs $(NAME) $(OBJS)

# re: fclean all

# clean:
# 	@echo Cleaning out the .o
# 	@rm -f $(OBJS)

# fclean: clean
# 	@echo Cleaning out the $(NAME)
# 	@rm -f $(NAME)

# so:
# 	gcc -nostartfiles -fPIC $(CFLAGS) -c $(SRCS)
# 	gcc -nostartfiles -shared -o libft.so $(OBJS)

# .PHONY: clean fclean re all bonus