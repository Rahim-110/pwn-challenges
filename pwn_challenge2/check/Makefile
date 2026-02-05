# Makefile for NEXUS-7 CTF Challenge
# Abandoned Space Station - Buffer Overflow Challenge

CC = gcc
CFLAGS = -O2 -fno-stack-protector -no-pie
TARGET = nexus7
SOURCE = source_code.c

# Build the vulnerable binary
all: $(TARGET)

$(TARGET): $(SOURCE)
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║         Compiling NEXUS-7 Station Terminal                   ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)
	@echo ""
	@echo "[SUCCESS] Binary compiled: $(TARGET)"
	@echo "[INFO] No PIE, No stack protector, O2 optimization"
	@echo ""

# Strip symbols for release
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
	@echo "[STARTING] Launching NEXUS-7..."
	./$(TARGET)

# Debug build
debug: $(SOURCE)
	@echo "[DEBUG] Compiling with debug symbols..."
	$(CC) -g -fno-stack-protector -no-pie -o $(TARGET)_debug $(SOURCE)
	@echo "[DONE] Debug binary: $(TARGET)_debug"

# Show binary info
info: $(TARGET)
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                    BINARY INFORMATION                        ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@file $(TARGET)
	@echo ""
	@checksec --file=$(TARGET) 2>/dev/null || echo "(checksec not installed)"
	@echo ""
	@echo "[KEY FUNCTIONS]"
	@nm $(TARGET) | grep -E "(emergency_override|send_distress|main)" || true

.PHONY: all clean run debug info release
