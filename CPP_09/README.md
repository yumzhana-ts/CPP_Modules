- Mandatory use of standard containers
Each exercise must use a container from the C++ Standard Library (std::vector, std::list, std::map, etc.).

- One container can only be used once
Once a container is used in one exercise, it cannot be used in any other exercises. You need to plan carefully which container to use for each task.

- Read the entire subject before starting
To properly distribute containers across the exercises, it is important to read all the tasks first before solving them.

- At least one container per exercise
Each exercise (except one exception) must use at least one container.

- Exception for exercise 02
Exercise 02 requires the use of two different containers.

- A Makefile for each program
Each exercise must have a separate Makefile that compiles the program.

- Compilation flags
The program must be compiled with the following flags:

-Wall (enables all warnings)

-Wextra (enables extra warnings)

-Werror (treats warnings as errors)

- No unnecessary recompilation
The Makefile must be designed to avoid recompiling files if they have not changed.

- Mandatory rules in the Makefile
The Makefile must include the following rules:

$(NAME) — compiles the executable.

all — compiles all files.

clean — removes object files (.o).

fclean — removes object files and the executable.

re — fully rebuilds the project (fclean + all).


