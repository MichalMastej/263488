FLAGS= -Wall -pedantic -std=c++17 -iquote inc

__start__: ./test_arytm_zesp
	./test_arytm_zesp test-arytmetyka.txt

./test_arytm_zesp: obj obj/main.o obj/LZespolona.o\
			obj/WyrazenieZespolone.o\
			obj/StatystykaTestu.o
	g++ -o ./test_arytm_zesp obj/main.o obj/LZespolona.o\
			obj/WyrazenieZespolone.o\
			obj/StatystykaTestu.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/LZespolona.hh inc/WyrazenieZespolone.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/StatystykaTestu.o: src/StatystykaTestu.cpp inc/StatystykaTestu.hh
	g++ -c ${FLAGS} -o obj/StatystykaTestu.o src/StatystykaTestu.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/WyrazenieZespolone.o: src/WyrazenieZespolone.cpp inc/WyrazenieZespolone.hh\
				inc/LZespolona.hh
	g++ -c ${FLAGS} -o obj/WyrazenieZespolone.o src/WyrazenieZespolone.cpp

clean:
	rm -f ./test_arytm_zesp obj/*
