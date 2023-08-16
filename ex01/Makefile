NAME = FixedPoint

FLAG =  c++

FLAGS =  -Wall -Wextra -Werror -std=c++98
 
HEADER = ./Fixed.hpp

SRC = ./main.cpp ./Fixed.cpp


OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) 
		$(FLAG) $(FLAGS)  $^ -o $@


%.o : %.cpp ${HEADER} 
	$(FLAG) $(FLAGS)  $< -c -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all 