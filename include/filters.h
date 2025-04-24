// include/filters.h

#ifndef FILTERS_H
#define FILTERS_H

#define WORD_LENGTH 5

void load_words(const char *filename);
int contains_all_letters(const char *word, const char *letters);
int contains_none_of_letters(const char *word, const char *letters);
int contains_substring(const char *word, const char *substring);
void filter_words(const char *include_letters, const char *exclude_letters, const char *substring);

#endif // FILTERS_H
