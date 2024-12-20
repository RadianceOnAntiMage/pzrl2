#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_text(const char *filename, const char *old_text, const char *new_text) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *pos = NULL;
        while ((pos = strstr(line, old_text)) != NULL) {
            *pos = '\0';
            printf("%s%s%s", line, new_text, pos + strlen(old_text));
            strcpy(line, pos + strlen(old_text)); 
        }
    }
    fclose(file);
}

void delete_lines(const char *filename, const char *text_to_delete) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *pos;
        
        while ((pos = strstr(line, text_to_delete)) != NULL) {
            
            *pos = '\0';  
            strcat(line, pos + strlen(text_to_delete));  
        }
        
        printf("%s", line);
    }

    fclose(file);
}

void insert_text(const char *filename, const char *insert_text, int position_front) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (position_front) {
            printf("%s%s", insert_text, line); 
        } else {
            line[strcspn(line, "\n")] = '\0'; 
            printf("%s%s\n", line, insert_text); 
        }
    }
    fclose(file);
}
