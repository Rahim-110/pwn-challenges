#!/bin/bash
# ╔═══════════════════════════════════════════════════════════════════════════╗
# ║                    PWN CTF Challenges - EC2 Deploy Script                 ║
# ║                                                                           ║
# ║  Run this script on your EC2 instance to deploy all challenges.          ║
# ║  Containers will auto-restart on EC2 reboot.                             ║
# ╚═══════════════════════════════════════════════════════════════════════════╝

set -e

echo "╔═══════════════════════════════════════════════════════════════╗"
echo "║           PWN CTF Challenge Deployment Script                 ║"
echo "╚═══════════════════════════════════════════════════════════════╝"
echo ""

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    echo "[!] Docker not found. Installing Docker..."
    sudo apt-get update
    sudo apt-get install -y docker.io docker-compose
    sudo systemctl enable docker
    sudo systemctl start docker
    sudo usermod -aG docker $USER
    echo "[+] Docker installed. Please logout and login again, then re-run this script."
    exit 0
fi

# Check if docker-compose is installed
if ! command -v docker-compose &> /dev/null; then
    echo "[!] docker-compose not found. Installing..."
    sudo apt-get install -y docker-compose
fi

# Ensure Docker starts on boot
sudo systemctl enable docker

# Get script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo ""
echo "[*] Deploying Challenge 1: Batcomputer (Port 9001)..."
cd pwn_challenge1/deploy
docker-compose down 2>/dev/null || true
docker-compose up -d --build
cd "$SCRIPT_DIR"

echo ""
echo "[*] Deploying Challenge 2: Nexus-7 (Port 9002)..."
cd pwn_challenge2/deploy
docker-compose down 2>/dev/null || true
docker-compose up -d --build
cd "$SCRIPT_DIR"

echo ""
echo "[*] Deploying Challenge 3: Space Station Alpha (Port 9003)..."
cd pwn_challenge3/deploy
docker-compose down 2>/dev/null || true
docker-compose up -d --build
cd "$SCRIPT_DIR"

echo ""
echo "[*] Deploying Challenge 4: The Void Library (Port 9004)..."
cd pwn_challenge4/deploy
docker-compose down 2>/dev/null || true
docker-compose up -d --build
cd "$SCRIPT_DIR"

echo ""
echo "╔═══════════════════════════════════════════════════════════════╗"
echo "║                    Deployment Complete!                       ║"
echo "╠═══════════════════════════════════════════════════════════════╣"
echo "║  Challenge 1: nc ctf.neocyberrange.com 9001 (Format String)   ║"
echo "║  Challenge 2: nc ctf.neocyberrange.com 9002 (Buffer Overflow) ║"
echo "║  Challenge 3: nc ctf.neocyberrange.com 9003 (Buffer Overflow) ║"
echo "║  Challenge 4: nc ctf.neocyberrange.com 9004 (Cmd Injection)   ║"
echo "╚═══════════════════════════════════════════════════════════════╝"
echo ""

# Show running containers
echo "[*] Running containers:"
docker ps --format "table {{.Names}}\t{{.Ports}}\t{{.Status}}"

echo ""
echo "[+] All challenges are now running with restart:always policy."
echo "[+] Containers will auto-restart on EC2 reboot."
