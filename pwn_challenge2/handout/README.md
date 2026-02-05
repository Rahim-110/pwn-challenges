# 🚀 NEXUS-7 - Abandoned Space Station

```
    ███╗   ██╗███████╗██╗  ██╗██╗   ██╗███████╗      ███████╗
    ████╗  ██║██╔════╝╚██╗██╔╝██║   ██║██╔════╝      ╚════██║
    ██╔██╗ ██║█████╗   ╚███╔╝ ██║   ██║███████╗█████╗    ██╔╝
    ██║╚██╗██║██╔══╝   ██╔██╗ ██║   ██║╚════██║╚════╝   ██╔╝ 
    ██║ ╚████║███████╗██╔╝ ██╗╚██████╔╝███████║        ██╔╝  
    ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝        ╚═╝   
```

---

## Challenge Info

| Field | Value |
|-------|-------|
| **Name** | NEXUS-7 |
| **Category** | PWN |
| **Difficulty** | Easy |
| **Points** | 200 |
| **Flag Format** | `GTH{...}` |

---

## Story

*The year is 2226. You're a salvage operator exploring the outer rim.*

Your ship picked up a faint signal from NEXUS-7, a research station abandoned 47 years ago after a catastrophic incident. The crew is long dead, but the station AI is still running—corrupted and unpredictable.

You've docked and restored power to the main terminal. The station's **emergency override** system could unlock the escape pod and reveal what really happened here... if you can find a way to trigger it.

The AI's communication system seems fragile. Perhaps there's a way to make it do something it wasn't designed to do.

*"In space, no one can hear you overflow."*

---

## Objective

Trigger the station's emergency override to reveal the classified access key.

---

## Connection

```bash
nc challenge.ctf.com 9002
```

---

## Files

| File | Description |
|------|-------------|
| `nexus7` | Station terminal binary |
| `source_code.c` | Terminal source code |

---

## Hints

<details>
<summary>Hint 1 (Free)</summary>

> *"The distress signal system was built in a hurry. They used some... legacy functions."*

Check how user input is handled in the transmission feature.

</details>

<details>
<summary>Hint 2 (-25 points)</summary>

> *"gets() what gets() wants."*

The signal buffer might accept more than it should.

</details>

<details>
<summary>Hint 3 (-50 points)</summary>

There's a hidden function in the binary. Find its address and redirect execution there.

</details>

---

**Good luck, operator. The void awaits.**

🚀 *NEXUS-7 CTF Challenge* 🚀
