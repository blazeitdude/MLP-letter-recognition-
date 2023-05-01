.PHONY: all install uninstall dist clean dvi tests

SOURCES = logic/* graphics/* controller/*

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
		clang-format -n -verbose -style=Google $(SOURCES)

dist:	clean
		tar -czf MLP.tgz ./*

dvi:
		open readme.pdf

tests: clean
		g++ -std=c++17 logic/
		