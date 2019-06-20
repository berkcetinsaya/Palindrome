all: source
	./source.out

source:
	g++ $@.cpp -D 'FILENAME="palindrome.txt"' -ggdb -o $@.out -w

clean:
	rm source.out

