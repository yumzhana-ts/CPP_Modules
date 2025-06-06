# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 18:06:28 by ytsyrend          #+#    #+#              #
#    Updated: 2025/05/12 13:38:12 by ytsyrend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	PmergeMe

# Compiler
CPP			=	c++

# Compiler Flags
CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I. -Iinclude
RM 			= 	rm -rf

# Directories
OBJS_DIR 	= 	objs
SRC_DIRS 	= 	srcs

MAIN 		= 	$(SRC_DIRS)/main.cpp
TEST 		= 	$(SRC_DIRS)/tests.cpp
COMMON_SRCS =	$(SRC_DIRS)/Pmerge_me.class.cpp

# Source and Object Files
SRCS 		= 	$(COMMON_SRCS) $(MAIN)
TEST_SRCS 	= 	$(COMMON_SRCS) $(TEST)
OBJS 		= 	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)
TEST_OBJS 	= 	$(TEST_SRCS:%.cpp=$(OBJS_DIR)/%.o)

all : $(OBJS_DIR) $(NAME)

# Compile and Link the Project
$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@
	@echo "main: Compilation successful."

test : $(TEST_OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@
	@echo "test: Compilation successful."


# Compile Source Files into Object Files
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) -c $< -o $@


# Create the Object File Directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)/$(SRC_DIRS)


# Clean Objects and Executable
clean :
	$(RM) $(OBJS_DIR)
	@echo "Object files and directory cleaned."

fclean : clean
	$(RM) $(NAME) 
	@echo "Executable removed."

tclean : clean
	$(RM) test
	@echo "Executable removed."

re: fclean all

leaks: re
	@echo "\033[1;33m\nChecking for memory leaks...\033[0m"
	leaks --atExit -- ./$(NAME)

valgrind_leaks: re
	@echo "\033[1;33m\nChecking for memory leaks with valgrind...\033[0m"
	valgrind --leak-check=full ./$(NAME)


# Define symbolic constants for color codes
CYAN=\033[1;36m
GREEN=\033[1;32m"
RESET_COLOR=\033[0m


.PHONY : clean fclean re all bonus
