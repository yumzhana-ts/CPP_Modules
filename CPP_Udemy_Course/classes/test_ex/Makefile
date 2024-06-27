NAME		=	main
SRCS		=	main.cpp movie.cpp movies.cpp
OBJS		=	$(SRCS:.cpp=.o)
CPPFLAGS	=	-Wall -Werror -Wextra -pedantic -g -std=c++98
CPP			=	c++

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(CPPFLAGS) $^ -o $@

%.o:		%.cpp
			$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:	all clean fclean re