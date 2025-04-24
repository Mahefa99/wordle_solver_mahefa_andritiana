// src/main.c

#include "filters.h"
#include <stdio.h>

int main() {
    load_words("ressource/bdd_wordle_clean.txt");

    char include_letters[10], exclude_letters[10], substring[WORD_LENGTH + 1];

    printf("Enter letters to include (or press Enter to skip): ");
    fgets(include_letters, sizeof(include_letters), stdin);
    include_letters[strcspn(include_letters, "\n")] = '\0';

    printf("Enter letters to exclude (or press Enter to skip): ");
    fgets(exclude_letters, sizeof(exclude_letters), stdin);
    exclude_letters[strcspn(exclude_letters, "\n")] = '\0';

    printf("Enter substring to search (or press Enter to skip): ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0';

    filter_words(include_letters, exclude_letters, substring);

    return 0;
}
