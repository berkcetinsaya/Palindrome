all: source
	./source

source:
	g++ $@.cpp -D 'FILENAME="palindrome.txt"' -ggdb -o $@ -w

clean:
	rm source

