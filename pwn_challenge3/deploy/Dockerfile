FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    make \
    socat \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m -s /bin/bash ctf

WORKDIR /home/ctf/challenge

COPY challenge.c .
COPY Makefile .
COPY flag.txt .

RUN make && chmod +x spaceterm

RUN chown -R root:ctf /home/ctf/challenge && \
    chmod 750 /home/ctf/challenge && \
    chmod 440 flag.txt && \
    chmod 755 spaceterm

USER ctf

EXPOSE 9003

CMD ["socat", "-T60", "TCP-LISTEN:9003,reuseaddr,fork", "EXEC:./spaceterm,pty,stderr,setsid,sigint,sane"]
