CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGETS = window_join akari helicopters

build: $(TARGETS)

window_join: window_join.c
	$(CC) $(CFLAGS) -o window_join window_join.c

akari: akari.c
	$(CC) $(CFLAGS) -o akari akari.c

helicopters: helicopters.c
	$(CC) $(CFLAGS) -o helicopters helicopters.c

clean:
	rm -f $(TARGETS)
