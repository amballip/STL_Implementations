
# $@ replaced by name of the target
# $< replaced by name of the first prerequisite
# $^ replaced by name of all prerequisites
# -E Preprocess only; do not compile, assemble or link.
# -S Compile only; do not assemble or link.
# -c Compile and assemble, but do not link.

cc:=g++
ccflags:=-g -Wall -std=c++17
target:=main
obj:= main.o 

all:$(target)


$(target):$(obj)
	$(cc) $(ccflags) $^ -o $@ 

./%.o: ./%.cpp ./forward_list.hpp
	$(cc) $(ccflags) -c $< -o $@

clean:
	rm -f .*.o $(target)


# Running create will delete all old files and create new ones


create:
	rm -f ./src/*.cpp ./src/*.h 
	mkdir -p obj src 
	touch ./src/main.cpp
	cp -i ~/dev/timer.h ./src/timer.h
	cp -i ~/dev/timer.cpp ./src/timer.cpp


# Writing to ./src/main.cpp  
	

	echo "int main()">>./src/main.cpp
	echo "{">>./src/main.cpp
	echo "">>./src/main.cpp
	echo "}">>./src/main.cpp	 

