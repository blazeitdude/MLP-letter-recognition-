.PHONY: all install uninstall dist clean dvi tests

SOURCES = logic/*.cpp graphics/*.cpp controller/*.cpp
HEADERS = logic/headers/*.hpp graphics/headers/*.hpp graphics/headers/*.h controller/*.hpp

build: 
		cmake -S . -B ./build
		cmake --build ./build

install: build

		cp -rf ./build/MLP_Design.app $(HOME)/Applications/

uninstall:

		rm -rf $(HOME)/Applications/MLP_Design.app

clean:
		rm -rf ./build

style:
		clang-format -n -style=Google $(SOURCES) $(HEADERS)

dist:	clean
		tar -czf MLP.tgz ./*

dvi:
		open readme.pdf

tests: clean
		rm -rf test
		g++ -std=c++17 -lgtest logic/tests/test.cpp logic/*.cpp -o test
		