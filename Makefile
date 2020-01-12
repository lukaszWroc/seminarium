CC=g++
CFLAGS=-Ofast

make: $(OBJ)
	$(CC) $(CFLAGS) *.cpp -o game

.PHONY: clean
clean:
	rm -f *.o game