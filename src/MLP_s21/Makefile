.PHONY: all install uninstall dist clean dvi tests

SOURCES = logic/*.cpp graphics/*.cpp controller/*.cpp logic/tests/*.cpp
HEADERS = logic/headers/*.hpp graphics/headers/*.hpp graphics/headers/*.h controller/*.hpp

build: 
		cmake -S . -B ./build
		cmake --build ./build

install: build

		cp -rf ./build/MLP_s21.app $(HOME)/Applications/

uninstall:

		rm -rf $(HOME)/Applications/MLP_Design.app

clean:
		rm -rf ./build
		rm -rf test

style:
		clang-format -n -style=Google $(SOURCES) $(HEADERS)

dist:	clean
		tar -czf MLP.tgz ./*

dvi:
		open readme.pdf

tests: clean
		g++ -std=c++17 -lgtest logic/tests/test.cpp logic/*.cpp -o test
		