CC=CLANG++

shakespeare-quote: main.o
	$(CC) main.o -o shakespeare-quote

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm *.o shakespeare-quote
