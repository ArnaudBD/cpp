NAME 	= CPP_01_EX00
SRCS 	= 	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp
OBJS 	= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
OBJDIR	= objs
INCL	= -I includes
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -g -std=c++98
RM		= rm -f
$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all:	$(NAME)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
