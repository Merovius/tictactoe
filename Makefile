TTT_CFLAGS += -std=c11

all: tictactoe.o

tictactoe.o: tictactoe.c
	$(CC) $(TTT_CFLAGS) $(CFLAGS) -c -o $@ $<

test_tictactoe: test_tictactoe.c all
	$(CC) -o $@ $< tictactoe.o

test: test_tictactoe
	./test_tictactoe

clean:
	rm -f test_tictactoe test_tictactoe.o tictactoe.o
