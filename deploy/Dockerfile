FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt-get update && apt-get install -y \
    gcc \
    socat \
    && rm -rf /var/lib/apt/lists/*

# Create challenge user
RUN useradd -m -s /bin/bash ctf

# Create challenge directory
WORKDIR /home/ctf/challenge

# Copy challenge files
COPY source_code.c .
COPY Makefile .
COPY flag.txt .

# Build the binary
RUN make && chmod +x batcomputer

# Set proper permissions
RUN chown -R root:ctf /home/ctf/challenge && \
    chmod 750 /home/ctf/challenge && \
    chmod 440 flag.txt && \
    chmod 755 batcomputer

# Switch to challenge user
USER ctf

# Expose the challenge port
EXPOSE 9001

# Run with socat
CMD ["socat", "-T60", "TCP-LISTEN:9001,reuseaddr,fork", "EXEC:./batcomputer,pty,stderr,setsid,sigint,sane"]
