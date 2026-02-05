# Space Station Alpha - Build Configuration
# Compiles the vulnerable binary for CTF exploitation

CC = gcc
CFLAGS = -O0 -fno-stack-protector -no-pie
TARGET = spaceterm
SOURCE = challenge.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo ""
	@echo "[+] Built $(TARGET) with exploitation-friendly flags:"
	@echo "    -O0                  : No optimization"
	@echo "    -fno-stack-protector : No stack canaries"
	@echo "    -no-pie              : Fixed addresses (no ASLR bypass needed)"
	@echo ""

clean:
	rm -f $(TARGET)

.PHONY: all clean
