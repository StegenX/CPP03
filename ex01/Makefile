NAME	=	ex01
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f

SRC		=	ClapTrap.cpp \
				ScavTrap.cpp \
				main.cpp
OBJ		=	$(SRC:.cpp=.o)
INC		=	-I.

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
