
NAME = prime
CLANG = clang++ -std=c++14 -pthread
SRC_NAME = main.cpp Program.cpp FileManager.cpp ErrorException.cpp
OBJ_NAME = $(SRC_NAME:.cpp=.o)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(OBJ) -o $(NAME)
$(OBJ_PATH)%.o : $(SRC_PATH)%.cpp
	 mkdir -p $(OBJ_PATH)
	 $(CLANG) -c $< -o $@ $(INC) -fPIC
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
