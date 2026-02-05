/*
 * The Void Library - Ancient Archive Terminal
 * ============================================
 * 
 * An old terminal for searching the forbidden archives.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_banner() {
    printf("\n");
    printf("    ╔═══════════════════════════════════════════════════════════╗\n");
    printf("    ║  ████████╗██╗  ██╗███████╗    ██╗   ██╗ ██████╗ ██╗██████╗ ║\n");
    printf("    ║  ╚══██╔══╝██║  ██║██╔════╝    ██║   ██║██╔═══██╗██║██╔══██╗║\n");
    printf("    ║     ██║   ███████║█████╗      ██║   ██║██║   ██║██║██║  ██║║\n");
    printf("    ║     ██║   ██╔══██║██╔══╝      ╚██╗ ██╔╝██║   ██║██║██║  ██║║\n");
    printf("    ║     ██║   ██║  ██║███████╗     ╚████╔╝ ╚██████╔╝██║██████╔╝║\n");
    printf("    ║     ╚═╝   ╚═╝  ╚═╝╚══════╝      ╚═══╝   ╚═════╝ ╚═╝╚═════╝ ║\n");
    printf("    ║                      L I B R A R Y                        ║\n");
    printf("    ╠═══════════════════════════════════════════════════════════╣\n");
    printf("    ║     ~ Where forgotten knowledge awaits the worthy ~       ║\n");
    printf("    ║              Est. 1847 · Digitized 1983                   ║\n");
    printf("    ╚═══════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

void search_archive() {
    char search_term[128];
    char command[256];
    
    printf("    ┌─────────────────────────────────────────────────────────┐\n");
    printf("    │           ARCHIVE SEARCH TERMINAL v3.14                 │\n");
    printf("    │     Enter a book title to search the catalog...         │\n");
    printf("    └─────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("    [SEARCH] > ");
    fflush(stdout);
    
    if (fgets(search_term, sizeof(search_term), stdin) == NULL) {
        return;
    }
    search_term[strcspn(search_term, "\n")] = '\0';
    
    if (strlen(search_term) == 0) {
        printf("\n    [!] No search term provided.\n\n");
        return;
    }
    
    snprintf(command, sizeof(command), "echo 'Searching for: %s'", search_term);
    
    printf("\n");
    printf("    ══════════════════════════════════════════════════════════\n");
    printf("    CATALOG QUERY RESULTS\n");
    printf("    ══════════════════════════════════════════════════════════\n");
    printf("\n    ");
    
    system(command);
    
    printf("\n");
    printf("    [*] No matching records found in the archives.\n");
    printf("    [*] The void keeps its secrets...\n");
    printf("\n");
}

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    print_banner();
    
    printf("    [SYSTEM] Terminal connected to archive mainframe.\n");
    printf("    [SYSTEM] Warning: Some knowledge should remain buried.\n\n");
    
    search_archive();
    
    printf("    [SYSTEM] Connection terminated.\n\n");
    return 0;
}
