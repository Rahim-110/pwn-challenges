/*
 * NEXUS-7 Emergency Console - Abandoned Space Station
 * "The last transmission was 47 years ago..."
 * 
 * VULNERABILITY: Stack Buffer Overflow (ret2win)
 * DIFFICULTY: Easy to Intermediate
 * ARCHITECTURE: x86_64 Linux, No PIE, No Canary
 * 
 * Compile: gcc -O2 -fno-stack-protector -no-pie -o nexus7 source_code.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FLAG_FILE "flag.txt"
#define FLAG_SIZE 128

// Hidden function - players need to call this via buffer overflow
void emergency_override(void) {
    FILE *f;
    char flag[FLAG_SIZE];
    
    puts("\n\033[1;32m");
    puts("╔═══════════════════════════════════════════════════════════════╗");
    puts("║            EMERGENCY OVERRIDE ACTIVATED                       ║");
    puts("║                 DISPLAYING CORE SECRETS                       ║");
    puts("╚═══════════════════════════════════════════════════════════════╝");
    puts("\033[0m");
    
    f = fopen(FLAG_FILE, "r");
    if (f == NULL) {
        puts("\033[1;31m[ERROR]\033[0m Flag file not found. Contact station admin.");
        exit(1);
    }
    
    if (fgets(flag, FLAG_SIZE, f) != NULL) {
        flag[strcspn(flag, "\n")] = '\0';
        printf("\n\033[1;33m[DECRYPTED]\033[0m Station Master Key: %s\n\n", flag);
    }
    
    fclose(f);
    
    puts("\033[1;36m[NEXUS-7]\033[0m Override complete. Escape pod unlocked.");
    puts("         You have 60 seconds to evacuate.\n");
    
    exit(0);
}

void print_banner(void) {
    puts("\033[1;35m");
    puts("    ███╗   ██╗███████╗██╗  ██╗██╗   ██╗███████╗      ███████╗");
    puts("    ████╗  ██║██╔════╝╚██╗██╔╝██║   ██║██╔════╝      ╚════██║");
    puts("    ██╔██╗ ██║█████╗   ╚███╔╝ ██║   ██║███████╗█████╗    ██╔╝");
    puts("    ██║╚██╗██║██╔══╝   ██╔██╗ ██║   ██║╚════██║╚════╝   ██╔╝ ");
    puts("    ██║ ╚████║███████╗██╔╝ ██╗╚██████╔╝███████║        ██╔╝  ");
    puts("    ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝        ╚═╝   ");
    puts("\033[0m");
    puts("\033[1;31m   ╔══════════════════════════════════════════════════════════╗");
    puts("   ║     ABANDONED RESEARCH STATION · SECTOR 7-G · DEEP SPACE   ║");
    puts("   ║                   LAST CONTACT: 2179 CE                    ║");
    puts("   ╚══════════════════════════════════════════════════════════╝\033[0m");
    puts("");
}

void print_menu(void) {
    puts("\033[1;36m┌────────────────────────────────────────────────────────────────┐");
    puts("│                    NEXUS-7 MAIN TERMINAL                       │");
    puts("├────────────────────────────────────────────────────────────────┤");
    puts("│  [1] Query Station Status                                      │");
    puts("│  [2] Access Crew Manifest                                      │");
    puts("│  [3] Send Distress Signal                                      │");
    puts("│  [4] Emergency Shutdown                                        │");
    puts("└────────────────────────────────────────────────────────────────┘\033[0m");
    printf("\n\033[1;33m[NEXUS-7]>\033[0m ");
}

void query_status(void) {
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║                    STATION STATUS REPORT                       ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m");
    puts("");
    puts("  \033[1;31m[CRITICAL]\033[0m Reactor Core.............. UNSTABLE");
    puts("  \033[1;31m[CRITICAL]\033[0m Life Support.............. FAILING");
    puts("  \033[1;33m[WARNING]\033[0m  Oxygen Reserves........... 12%");
    puts("  \033[1;33m[WARNING]\033[0m  Hull Integrity............ 34%");
    puts("  \033[1;32m[ONLINE]\033[0m   Emergency Override........ LOCKED");
    puts("  \033[1;32m[ONLINE]\033[0m   Escape Pod................ STANDBY");
    puts("");
    puts("  \033[1;35m[AI]\033[0m Station AI status: CORRUPTED - Last update 47 years ago");
    puts("");
}

void access_manifest(void) {
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║                      CREW MANIFEST                             ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m");
    puts("");
    puts("  ┌─────────────────┬─────────────────┬─────────────────┐");
    puts("  │ NAME            │ ROLE            │ STATUS          │");
    puts("  ├─────────────────┼─────────────────┼─────────────────┤");
    puts("  │ Dr. Elena Vasquez│ Station Commander│ \033[1;31mDECEASED\033[0m       │");
    puts("  │ Marcus Chen     │ Chief Engineer  │ \033[1;31mDECEASED\033[0m        │");
    puts("  │ NEXUS-7 AI      │ Station AI      │ \033[1;33mCORRUPTED\033[0m       │");
    puts("  │ YOU             │ Salvage Operator│ \033[1;32mACTIVE\033[0m          │");
    puts("  └─────────────────┴─────────────────┴─────────────────┘");
    puts("");
    puts("  \033[1;35m[LOG]\033[0m Final entry: \"The override code... in the signal...\"");
    puts("");
}

// VULNERABLE FUNCTION: Buffer overflow here
void send_distress_signal(void) {
    char signal_buffer[64];  // Small buffer - easily overflowed
    
    puts("\n\033[1;34m╔═══════════════════════════════════════════════════════════════╗");
    puts("║                   DISTRESS SIGNAL TRANSMITTER                  ║");
    puts("║     Enter your message (will be broadcast on all frequencies)  ║");
    puts("╚═══════════════════════════════════════════════════════════════╝\033[0m");
    
    printf("\n\033[1;32m[TRANSMIT]>\033[0m ");
    fflush(stdout);
    
    // VULNERABILITY: gets() - classic buffer overflow
    // The buffer is 64 bytes but gets() has no length limit
    // Overflow to overwrite return address and call emergency_override()
    gets(signal_buffer);
    
    puts("\n\033[1;33m[NEXUS-7]\033[0m Transmitting signal...");
    puts("\033[1;33m[NEXUS-7]\033[0m Broadcasting: ");
    printf("          \"%s\"\n", signal_buffer);
    puts("\033[1;31m[NEXUS-7]\033[0m No response. Deep space is silent.\n");
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
    print_banner();
    
    puts("\033[1;36m[NEXUS-7]\033[0m Power restored. Terminal online.");
    puts("\033[1;36m[NEXUS-7]\033[0m WARNING: Station AI may be compromised.\n");
    
    while (1) {
        print_menu();
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        choice = atoi(input);
        
        switch (choice) {
            case 1:
                query_status();
                break;
            case 2:
                access_manifest();
                break;
            case 3:
                send_distress_signal();
                break;
            case 4:
                puts("\n\033[1;31m[NEXUS-7]\033[0m Emergency shutdown initiated.");
                puts("         \"In space, no one can hear you scream.\"\n");
                exit(0);
            default:
                puts("\n\033[1;31m[ERROR]\033[0m Unknown command. Station AI unresponsive.\n");
                break;
        }
    }
    
    return 0;
}
