# The Void Library - Build Configuration

CC = gcc
CFLAGS = -O0 -fno-stack-protector -no-pie
TARGET = voidlib
SOURCE = challenge.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo ""
	@echo "[+] Built $(TARGET)"
	@echo ""

clean:
	rm -f $(TARGET)

.PHONY: all clean
