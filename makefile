src = $(wildcard *.c)
obj = $(src:.c=.o)
CC = arm-linux-gnueabi-gcc

motor: $(obj)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) motor 
