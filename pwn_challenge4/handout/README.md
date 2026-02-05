# 📚 The Void Library

## Challenge Description

```
    ╔═══════════════════════════════════════════════════════════╗
    ║  ████████╗██╗  ██╗███████╗    ██╗   ██╗ ██████╗ ██╗██████╗ ║
    ║  ╚══██╔══╝██║  ██║██╔════╝    ██║   ██║██╔═══██╗██║██╔══██╗║
    ║     ██║   ███████║█████╗      ██║   ██║██║   ██║██║██║  ██║║
    ║     ██║   ██╔══██║██╔══╝      ╚██╗ ██╔╝██║   ██║██║██║  ██║║
    ║     ██║   ██║  ██║███████╗     ╚████╔╝ ╚██████╔╝██║██████╔╝║
    ║     ╚═╝   ╚═╝  ╚═╝╚══════╝      ╚═══╝   ╚═════╝ ╚═╝╚═════╝ ║
    ║                      L I B R A R Y                        ║
    ╚═══════════════════════════════════════════════════════════╝
```

**The Void Library** — an ancient digital archive containing forbidden knowledge, digitized in 1983 from manuscripts dating back to 1847.

You've gained access to the archive's search terminal. The old system seems... *poorly sanitized*. Perhaps you can search for more than just books?

---

## 🎯 Objective

Exploit the archive terminal to spawn a shell and retrieve the flag.

**Flag Format:** `GTH{...}`

---

## 📁 Files Provided

- `voidlib` - The archive search terminal

---

## 💡 Hints

1. What happens when user input meets shell commands?
2. The search function seems to *echo* your query...
3. Special characters can break things. Or break *into* things.
4. `; && || $()` — the classics never die.

---

## 🔧 Running Locally

```bash
chmod +x voidlib
./voidlib
```

---

**Difficulty:** ⭐ Very Easy  
**Category:** Pwn / Command Injection
