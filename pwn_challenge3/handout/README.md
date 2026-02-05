# 🚀 Space Station Alpha - Access Terminal

## Challenge Description

```
    ╔═══════════════════════════════════════════════════════╗
    ║   ___  ___   _   ___ ___   ___ _____ _ _____ ___ ___  ║
    ║  / __|/ _ \ /_\ / __| __| / __|_   _/_\_   _|_ _/ _ \ ║
    ║  \__ \ |_) / _ \ (__| _|  \__ \ | |/ _ \| |  | | (_) |║
    ║  |___/ __/_/ \_\___|___| |___/ |_/_/ \_\_| |___\___/ ║
    ║      |_|            ALPHA                             ║
    ╚═══════════════════════════════════════════════════════╝
```

**Year 2157.** You're a cyber-operative aboard Space Station Alpha, orbiting Earth at 400km. The station's AI has gone rogue and locked out all crew members from critical systems.

Your mission: **Bypass the authentication terminal** and regain control of the station before life support fails.

The authentication system seems hastily written... perhaps the developers made some *classic mistakes*?

---

## 🎯 Objective

Exploit the vulnerable access terminal to spawn a shell and retrieve the flag.

**Flag Format:** `GTH{...}`

---

## 📁 Files Provided

- `spaceterm` - The compiled access terminal binary

---

## 💡 Hints

1. The access code buffer seems a bit... *small*
2. Old C functions can be dangerous. Very dangerous.
3. There's an emergency override function somewhere in the binary...
4. `objdump -d` and `gdb` are your friends

---

## 🔧 Running Locally

```bash
chmod +x spaceterm
./spaceterm
```

---

**Difficulty:** ⭐ Very Easy  
**Category:** Pwn / Binary Exploitation
