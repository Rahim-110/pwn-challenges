# 🦇 BATCOMPUTER - Gotham City Cyber Division

```
  ██████╗  █████╗ ████████╗ ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗███████╗██████╗ 
  ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔════╝██╔══██╗
  ██████╔╝███████║   ██║   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   █████╗  ██████╔╝
  ██╔══██╗██╔══██║   ██║   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██╔══╝  ██╔══██╗
  ██████╔╝██║  ██║   ██║   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ███████╗██║  ██║
  ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═╝
```

---

## 📋 Challenge Information

| Category | Details |
|----------|---------|
| **Name** | Batcomputer |
| **Category** | PWN / Binary Exploitation |
| **Difficulty** | Easy to Intermediate |
| **Points** | 250 |
| **Author** | Gotham City Cyber Division |
| **Flag Format** | `GTH{...}` |

---

## 📖 Story

*The year is 2026. Gotham City's underworld has evolved.*

After Scarecrow's latest attack on the city's infrastructure, the GCPD Cyber Division 
implemented a new security system, interfacing directly with the legendary **Batcomputer** 
housed deep beneath Wayne Tower.

The system logs security events across Gotham's grid - from break-ins at Ace Chemicals 
to suspicious activity near Arkham Asylum. But Oracle has detected an anomaly in the 
logging subsystem. Something's not quite right with how events are being processed...

**Your mission:** Infiltrate the Batcomputer terminal system, bypass the access controls, 
and retrieve the classified intelligence hidden within.

*"Sometimes, to fight the darkness, you must become the night."*

---

## 🎯 Objective

Gain unauthorized access to the **Classified Intelligence Vault** and capture the flag.

The Batcomputer requires a specific access level to view classified intel. Your current
access level doesn't match the required clearance. Find a way to elevate your privileges.

---

## 📦 Files Provided

| File | Description |
|------|-------------|
| `batcomputer` | The vulnerable binary (ELF x86_64) |

---

## 🔧 Connection

```bash
nc challenge.gotham-ctf.com 9001
```

---

## 💡 Hints

<details>
<summary>Hint 1 (Free)</summary>

> *"Every log tells a story... but who decides how that story is told?"*

Pay attention to how your security events are being logged.

</details>

<details>
<summary>Hint 2 (-25 points)</summary>

> *"Format is everything in Gotham's database."*

The logging system processes user input in an... unconventional way.

</details>

<details>
<summary>Hint 3 (-50 points)</summary>

> *"Writing to the right place at the right time."*

Look up format string attacks. The program helpfully shows you where 
important variables are stored when you check your access level.

</details>

---

## 🎬 The Challenge Awaits

```
┌─────────────────────────────────────────────────────────────┐
│                    BATCOMPUTER TERMINAL                     │
├─────────────────────────────────────────────────────────────┤
│  [1] Log Security Event                                     │
│  [2] Check Access Level                                     │
│  [3] Access Classified Intel                                │
│  [4] Exit Terminal                                          │
└─────────────────────────────────────────────────────────────┘
```

*"It's not who I am underneath, but what I do that defines me."*

---

**Good luck, Dark Knight.**

🦇 *Gotham City Cyber Division - CTF Challenge* 🦇
