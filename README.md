# 🏴 PWN CTF Challenges

A collection of binary exploitation (pwn) challenges for CTF competitions.

## 🎯 Challenges Overview

| # | Challenge | Vulnerability | Port | Difficulty |
|---|-----------|---------------|------|------------|
| 1 | **Batcomputer** | Format String | 9001 | ⭐⭐ Easy |
| 2 | **Nexus-7** | Buffer Overflow (ret2win) | 9002 | ⭐⭐ Easy |
| 3 | **Space Station Alpha** | Buffer Overflow (ret2shell) | 9003 | ⭐ Very Easy |
| 4 | **The Void Library** | Command Injection | 9004 | ⭐ Very Easy |

## 🌐 Remote Server

All challenges are hosted at: `ctf.neocyberrange.com`

```bash
# Connect to challenges
nc ctf.neocyberrange.com 9001  # Batcomputer
nc ctf.neocyberrange.com 9002  # Nexus-7
nc ctf.neocyberrange.com 9003  # Space Station Alpha
nc ctf.neocyberrange.com 9004  # The Void Library
```

---

## 📁 Directory Structure

```
pwn_ctf_challenge/
├── deploy.sh                    # EC2 deployment script
├── pwn_challenge1/              # Batcomputer (Format String)
│   ├── deploy/                  # Server files + Docker
│   ├── handout/                 # Files for players (source + README)
│   └── solution/                # Exploit + writeup
├── pwn_challenge2/              # Nexus-7 (Buffer Overflow)
│   ├── deploy/
│   ├── handout/
│   └── solution/
├── pwn_challenge3/              # Space Station Alpha (Buffer Overflow)
│   ├── deploy/
│   ├── handout/
│   └── solution/
└── pwn_challenge4/              # The Void Library (Command Injection)
    ├── deploy/
    ├── handout/
    └── solution/
```

---

## 🚀 EC2 Deployment

### Prerequisites
- Ubuntu 22.04 EC2 instance
- Ports 9001-9004 open in Security Group
- Docker installed (script will install if missing)

### Quick Deploy

```bash
# SSH to your EC2 instance
ssh -i your-key.pem ubuntu@ctf.neocyberrange.com

# Clone the repository
git clone https://github.com/YOUR_USERNAME/pwn-challenges.git
cd pwn-challenges

# Run the deployment script
chmod +x deploy.sh
./deploy.sh
```

### What the Script Does
1. Installs Docker if not present
2. Enables Docker to start on boot
3. Builds and starts all 4 challenge containers
4. Configures `restart: always` for auto-restart on reboot

### Manual Deployment (per challenge)

```bash
cd pwn_challenge1/deploy
docker-compose up -d --build
```

---

## 📦 Handout Files (For Players)

Each challenge's `handout/` folder contains:
- `README.md` - Challenge description and hints
- Source code (`.c` file) - For local testing
- `Makefile` - Compilation instructions

**Players can compile locally:**
```bash
cd handout
make
./binary_name
```

---

## 🔧 For CTF Organizers

### Adding to CTFd

1. Create a new challenge in CTFd
2. Set connection info: `nc ctf.neocyberrange.com PORT`
3. Upload files from the `handout/` folder
4. Set the flag from `deploy/flag.txt`

### Flags

| Challenge | Flag |
|-----------|------|
| Batcomputer | `GTH{f0rm4t_str1ng_m4st3r_0f_g0th4m}` |
| Nexus-7 | `GTH{st4ck_0v3rfl0w_1n_th3_v01d}` |
| Space Station Alpha | `GTH{0v3rfl0w_t0_th3_st4rs}` |
| The Void Library | `GTH{sh3ll_fr0m_th3_v01d}` |

---

## ✅ Testing Exploits

Each `solution/` folder contains:
- `exploit.py` - Pwntools exploit script
- `WRITEUP.md` - Detailed solution

```bash
cd solution

# Local testing
python3 exploit.py

# Remote
python3 exploit.py REMOTE
```

---

## 🔒 Security Notes

- All containers run with resource limits (0.5 CPU, 128MB RAM)
- `no-new-privileges` security option enabled
- Read-only filesystem with tmpfs for /tmp
- 60-second connection timeout per session
