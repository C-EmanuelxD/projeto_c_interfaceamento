CC = gcc
CFLAGS = -Wall -I. - Ipocketpy

SRC = main.c levenshtein/levenshtein.c pocketpy/pocketpy.c

BIN = main

default: $(BIN)

#Comando de compilaçao no terminal
$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)