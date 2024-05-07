NAME = array
OBJ_PATH = objects/
INC = -I ./includes -I ./templates

SRC = sources/main.cpp
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(NAME)

re: fclean all

