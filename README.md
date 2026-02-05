# CTF PWN Challenges

Two binary exploitation challenges for CTF competitions.

## Challenges

| Challenge | Vulnerability | Difficulty | Port |
|-----------|--------------|------------|------|
| Batcomputer | Format String | Easy-Medium | 9001 |
| NEXUS-7 | Buffer Overflow | Easy | 9002 |

## Deployment

Each challenge has a `deploy/` folder with Docker files:

```bash
cd <challenge>/deploy
docker-compose up -d --build
```

## Structure

```
├── deploy/           # Server deployment files
│   ├── Dockerfile
│   ├── docker-compose.yml
│   ├── source_code.c
│   ├── Makefile
│   └── flag.txt      # Real flag
│
├── handout/          # Files for players
│   ├── README.md
│   └── source_code.c
│
└── solution/         # Organizer only
    ├── exploit.py
    └── WRITEUP.md
```

## Flag Format

`GTH{...}`
