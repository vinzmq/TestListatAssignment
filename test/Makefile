NAME=testAll
CLANG = g++

CFLAGS = -g -L/opt/gtest/lib -lgtest_main -lgtest  -lpthread

INCS = -I/opt/gtest/include -I./ -I../../inc

OBJS = ../obj/ErrorException.o ../obj/Program.o ../obj/FileManager.o ./src/FileManager_Test.o ./src/Program_Test.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CLANG) $(OBJS) ./src/Main_TestAll.cpp  $(CFLAGS) $(INCS) -o testAll

./src/.cpp.o:
	$(CLANGS) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	rm testAll ./src/*.o

fclean: clean
	rm -f $(NAME)

re: clean testAll