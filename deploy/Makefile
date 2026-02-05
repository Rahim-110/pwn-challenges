# Makefile for Batcomputer CTF Challenge
# Gotham City Cyber Division - Format String Vulnerability Challenge

CC = gcc
CFLAGS = -O2 -fno-stack-protector -no-pie
TARGET = batcomputer
SOURCE = source_code.c

# Build the vulnerable binary
all: $(TARGET)

$(TARGET): $(SOURCE)
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║   Compiling Batcomputer Terminal - Gotham Cyber Division     ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo ""
	@echo "[SUCCESS] Binary compiled: $(TARGET)"
	@echo "[INFO] No PIE, No stack protector, O2 optimization"
	@echo ""

# Strip symbols for release binary (harder for players)
release: $(SOURCE)
	@echo "[RELEASE] Building stripped binary..."
	$(CC) $(CFLAGS) -s -o $(TARGET) $(SOURCE)
	@echo "[DONE] Stripped binary created"

# Clean build artifacts
clean:
	@echo "[CLEANING] Removing binary..."
	rm -f $(TARGET) $(TARGET)_debug
	@echo "[DONE] Clean complete."

# Run the challenge (requires flag.txt)
run: $(TARGET)
	@if [ ! -f flag.txt ]; then echo "GTH{test_flag_replace_me}" > flag.txt; fi
	@echo "[STARTING] Launching Batcomputer..."
	@echo ""
	./$(TARGET)

# Debug build (with symbols, no optimization)
debug: $(SOURCE)
	@echo "[DEBUG] Compiling with debug symbols..."
	$(CC) -g -fno-stack-protector -no-pie -o $(TARGET)_debug $(SOURCE)
	@echo "[DONE] Debug binary: $(TARGET)_debug"

# Show binary info
info: $(TARGET)
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                    BINARY INFORMATION                        ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@echo ""
	@echo "[FILE INFO]"
	@file $(TARGET)
	@echo ""
	@echo "[SECURITY CHECKS]"
	@checksec --file=$(TARGET) 2>/dev/null || echo "(checksec not installed)"
	@echo ""
	@echo "[SYMBOLS - Key Addresses]"
	@nm $(TARGET) | grep -E "(access_level|required_level|flag|main)" || true

.PHONY: all clean run debug info release
