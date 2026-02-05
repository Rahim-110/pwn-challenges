/*
 * Gotham City Cyber Division - Secure Terminal v2.1
 * "The night is darkest just before the dawn."
 * 
 * VULNERABILITY: Format string vulnerability in the access log system
 * DIFFICULTY: Easy to Intermediate
 * ARCHITECTURE: x86_64 Linux
 * 
 * Compile with: gcc -O2 -fno-stack-protector -no-pie -o batcomputer source_code.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Flag is loaded from file at runtime - NOT in binary
#define FLAG_FILE "flag.txt"
#define FLAG_SIZE 128

char flag[FLAG_SIZE];

// Global variable to track access level - target for overwrite
int access_level = 0;
int required_level = 0xBADC0DE;  // Batman's access code

void load_flag(void) {
    FILE *f = fopen(FLAG_FILE, "r");
    if (f == NULL) {
        strncpy(flag, "GTH{flag_not_found_contact_admin}", FLAG_SIZE - 1);
        return;
    }
    if (fgets(flag, FLAG_SIZE, f) == NULL) {
        strncpy(flag, "GTH{flag_read_error}", FLAG_SIZE - 1);
    }
    // Remove trailing newline if present
    flag[strcspn(flag, "\n")] = '\0';
    fclose(f);
}

void print_banner(void) {
    puts("\033[1;33m");
    puts("  ██████╗  █████╗ ████████╗ ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗   ██╗████████╗███████╗██████╗ ");
    puts("  ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║   ██║╚══██╔══╝██╔════╝██╔══██╗");
    puts("  ██████╔╝███████║   ██║   ██║     ██║   ██║██╔████╔██║██████╔╝██║   ██║   ██║   █████╗  ██████╔╝");
    puts("  ██╔══██╗██╔══██║   ██║   ██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║   ██║   ██║   ██╔══╝  ██╔══██╗");
    puts("  ██████╔╝██║  ██║   ██║   ╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ╚██████╔╝   ██║   ███████╗██║  ██║");
    puts("  ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝      ╚═════╝    ╚═╝   ╚══════╝╚═╝  ╚═╝");
    puts("\033[0m");
    puts("\033[1;36m                    ╔══════════════════════════════════════════════╗");
    puts("                    ║    GOTHAM CITY CYBER DIVISION - LEVEL 5     ║");
    puts("                    ║         AUTHORIZED PERSONNEL ONLY           ║");
    puts("                    ╚══════════════════════════════════════════════╝\033[0m");
    puts("");
}

void print_menu(void) {
    puts("\033[1;35m┌─────────────────────────────────────────────────────────────┐");
    puts("│                    BATCOMPUTER TERMINAL                     │");
    puts("├─────────────────────────────────────────────────────────────┤");
    puts("│  [1] Log Security Event                                     │");
    puts("│  [2] Check Access Level                                     │");
    puts("│  [3] Access Classified Intel                                │");
    puts("│  [4] Exit Terminal                                          │");
    puts("└─────────────────────────────────────────────────────────────┘\033[0m");
    printf("\n\033[1;33m[BATCOMPUTER]\033[0m Enter command: ");
}

// VULNERABLE FUNCTION: Format string vulnerability here
void log_security_event(void) {
    char event_log[256];
    
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║              SECURITY EVENT LOGGING SYSTEM                     ║");
    puts("║    Enter event details for Gotham's crime database            ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m");
    
    printf("\n\033[1;32m[GCPD-LOG]\033[0m Event description: ");
    fflush(stdout);
    
    // Read user input
    if (fgets(event_log, sizeof(event_log), stdin) == NULL) {
        puts("Error reading input.");
        return;
    }
    
    // Remove trailing newline
    event_log[strcspn(event_log, "\n")] = '\0';
    
    puts("\n\033[1;33m[BATCOMPUTER]\033[0m Processing event log...");
    puts("────────────────────────────────────────────────────────────────");
    printf("\033[1;31m[LOGGED]\033[0m ");
    
    // VULNERABILITY: User input passed directly to printf
    // This allows format string attacks (%x, %n, etc.)
    printf(event_log);
    
    printf("\n────────────────────────────────────────────────────────────────\n");
    puts("\033[1;32m[SUCCESS]\033[0m Event logged to Gotham Crime Database.\n");
}

void check_access_level(void) {
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║                    ACCESS LEVEL STATUS                         ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m");
    
    printf("\n\033[1;33m[SYSTEM]\033[0m Current access level: 0x%08x\n", access_level);
    printf("\033[1;33m[SYSTEM]\033[0m Required level:       0x%08x\n", required_level);
    printf("\033[1;33m[SYSTEM]\033[0m access_level address: %p\n\n", (void*)&access_level);
    
    if (access_level == required_level) {
        puts("\033[1;32m[AUTHORIZED]\033[0m Access level VERIFIED. Welcome, Dark Knight.\n");
    } else {
        puts("\033[1;31m[DENIED]\033[0m Insufficient access level. Identity verification failed.\n");
    }
}

void access_classified_intel(void) {
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║                CLASSIFIED INTELLIGENCE VAULT                   ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m\n");
    
    if (access_level == required_level) {
        puts("\033[1;32m[VERIFIED]\033[0m Biometric scan complete. Welcome, Batman.");
        puts("");
        puts("\033[1;33m┌─────────────────────────────────────────────────────────────┐");
        puts("│              TOP SECRET - EYES ONLY                         │");
        puts("├─────────────────────────────────────────────────────────────┤\033[0m");
        printf("\033[1;32m│  FLAG: %s\033[0m\n", flag);
        puts("\033[1;33m└─────────────────────────────────────────────────────────────┘\033[0m");
        puts("");
        puts("\033[1;36m[ORACLE]\033[0m Intel retrieved. Stay safe out there, Dark Knight.\n");
    } else {
        puts("\033[1;31m╔═══════════════════════════════════════════════════════════════╗");
        puts("║                    ACCESS DENIED                              ║");
        puts("╠═══════════════════════════════════════════════════════════════╣");
        puts("║  Your access level does not match the required clearance.     ║");
        puts("║  This incident has been logged to Wayne Enterprises Security. ║");
        puts("║                                                               ║");
        puts("║  Hint: Every log leaves a trace...                            ║");
        puts("╚═══════════════════════════════════════════════════════════════╝\033[0m\n");
    }
}

void disable_buffering(void) {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(void) {
    int choice;
    char input[16];
    
    disable_buffering();
    load_flag();
    print_banner();
    
    puts("\033[1;36m[ORACLE]\033[0m Batcomputer online. Awaiting authentication...\033[0m\n");
    
    while (1) {
        print_menu();
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        choice = atoi(input);
        
        switch (choice) {
            case 1:
                log_security_event();
                break;
            case 2:
                check_access_level();
                break;
            case 3:
                access_classified_intel();
                break;
            case 4:
                puts("\n\033[1;33m[BATCOMPUTER]\033[0m Terminating session. Gotham needs you.\n");
                puts("  \"I'm Batman.\"\n");
                exit(0);
            default:
                puts("\n\033[1;31m[ERROR]\033[0m Invalid command. Try again.\n");
                break;
        }
    }
    
    return 0;
}
