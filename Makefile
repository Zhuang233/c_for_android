DIR = build
CC = aarch64-none-linux-gnu-gcc
CFLAGS = -o
SRC = main.c main.h

.PHONY:all
all:$(DIR) $(DIR)/main

.PHONY:clean
clean:
	@rd /q/s $(DIR)

$(DIR):
	@mkdir $(DIR)

$(DIR)/main: $(SRC) 
	$(CC) $(CFLAGS) $@ $< -static
