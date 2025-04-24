// src/filters.c

#include "filters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 5
#define MAX_WORDS 1000

char words[MAX_WORDS][WORD_LENGTH + 1];
int word_count = 0;

void load_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%s", words[word_count]) != EOF) {
        word_count++;
    }
    fclose(file);
}

int contains_all_letters(const char *word, const char *letters) {
    for (int i = 0; letters[i] != '\0'; i++) {
        if (strchr(word, letters[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}

int contains_none_of_letters(const char *word, const char *letters) {
    for (int i = 0; letters[i] != '\0'; i++) {
        if (strchr(word, letters[i]) != NULL) {
            return 0;
        }
    }
    return 1;
}

int contains_substring(const char *word, const char *substring) {
    return strstr(word, substring) != NULL;
}

void filter_words(const char *include_letters, const char *exclude_letters, const char *substring) {
    printf("Filtered words:\n");
    for (int i = 0; i < word_count; i++) {
        int valid = 1;

        if (include_letters[0] != '\0' && !contains_all_letters(words[i], include_letters)) {
            valid = 0;
        }

        if (exclude_letters[0] != '\0' && !contains_none_of_letters(words[i], exclude_letters)) {
            valid = 0;
        }

        if (substring[0] != '\0' && !contains_substring(words[i], substring)) {
            valid = 0;
        }

        if (valid) {
            printf("%s\n", words[i]);
        }
    }
}

