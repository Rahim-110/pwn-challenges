/*
 * Space Station Alpha - Access Terminal
 * =====================================
 * 
 * A simple terminal authentication system for Space Station Alpha.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void unlock_override() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║  [!] EMERGENCY OVERRIDE ACTIVATED                        ║\n");
    printf("║  [+] Spawning maintenance shell...                       ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n");
    printf("\n");
    
    system("/bin/sh");
}

void print_banner() {
    printf("\n");
    printf("    ╔═══════════════════════════════════════════════════════╗\n");
    printf("    ║   ___  ___   _   ___ ___   ___ _____ _ _____ ___ ___  ║\n");
    printf("    ║  / __|/ _ \\ /_\\ / __| __| / __|_   _/_\\_   _|_ _/ _ \\ ║\n");
    printf("    ║  \\__ \\ |_) / _ \\ (__| _|  \\__ \\ | |/ _ \\| |  | | (_) |║\n");
    printf("    ║  |___/ __/_/ \\_\\___|___| |___/ |_/_/ \\_\\_| |___\\___/ ║\n");
    printf("    ║      |_|            ALPHA                             ║\n");
    printf("    ╠═══════════════════════════════════════════════════════╣\n");
    printf("    ║        >> ACCESS TERMINAL v2.3.1 <<                   ║\n");
    printf("    ║        Orbital Position: LEO-7                        ║\n");
    printf("    ╚═══════════════════════════════════════════════════════╝\n");
    printf("\n");
}

void authenticate() {
    char access_code[64];
    
    printf("    ┌─────────────────────────────────────────────────────┐\n");
    printf("    │  AUTHENTICATION REQUIRED                            │\n");
    printf("    │  Enter your crew access code:                       │\n");
    printf("    └─────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("    ACCESS CODE > ");
    
    read(0, access_code, 256);
    
    printf("\n");
    printf("    [X] ACCESS DENIED - Invalid crew credentials\n");
    printf("    [!] Security alert logged to central command\n");
    printf("\n");
}

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    print_banner();
    authenticate();
    
    printf("    [*] Terminal session ended.\n\n");
    return 0;
}
