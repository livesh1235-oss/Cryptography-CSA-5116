CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

SRCS = $(wildcard prog*.c)
BINS = $(SRCS:.c=)

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(BINS)

.PHONY: all clean
