#ifndef FILTERS_H
#define FILTERS_H

#include <stdbool.h>

// Vérifie que le mot contient toutes les lettres données
bool contains_all_letters(const char *word, const char *letters);

// Vérifie que le mot NE contient PAS certaines lettres
bool excludes_letters(const char *word, const char *letters);

// Vérifie que le mot contient une sous-chaîne (substring)
bool contains_substring(const char *word, const char *substr);

#endif
