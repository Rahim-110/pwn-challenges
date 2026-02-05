FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    socat \
    && rm -rf /var/lib/apt/lists/*

RUN useradd -m -s /bin/bash ctf

WORKDIR /home/ctf/challenge

COPY source_code.c .
COPY Makefile .
COPY flag.txt .

RUN make && chmod +x nexus7

RUN chown -R root:ctf /home/ctf/challenge && \
    chmod 750 /home/ctf/challenge && \
    chmod 440 flag.txt && \
    chmod 755 nexus7

USER ctf

EXPOSE 9002

CMD ["socat", "-T60", "TCP-LISTEN:9002,reuseaddr,fork", "EXEC:./nexus7,pty,stderr,setsid,sigint,sane"]
