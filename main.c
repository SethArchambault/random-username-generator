#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void load_file(char **buffer, int f_len, const char *filename) {
    FILE * f = fopen(filename, "r");
    *buffer = malloc(f_len-1);
    fread(*buffer, f_len, 1, f);
    fclose(f);
}

void print_random_word(char * buffer, int buffer_len) {
    int start = rand() % (buffer_len - 1);
    for (;start > 0 && buffer[start] != '\n'; --start);
    start++;
    int end = start;
    for (;buffer[end] != '\n'; ++end);
    buffer[end] = '\0';
    printf("%s", &buffer[start]);
}

int main() {
    srand(time(NULL));
    char * adjectives;
    int adjectives_len = 10453;
    load_file(&adjectives, adjectives_len, "adjectives.txt");
    char * nouns;
    int nouns_len = 53672;
    load_file(&nouns, nouns_len, "nouns.txt");
    for (int i = 0; i < 40; ++i) {
        print_random_word(adjectives, adjectives_len);
        print_random_word(nouns, nouns_len);
        printf("\n");
    }
    return 0;
}
