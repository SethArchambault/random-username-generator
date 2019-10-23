#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// @todo: get an array of positions of length

// @todo: add starting position
int random_word(char * out, const char * buffer, int buffer_len) {
    int start = rand() % (buffer_len - 1);
    for (;start > 0 && buffer[start] != '\n'; --start);
    start++;
    int end = start;
    for (;buffer[end] != '\n'; ++end);
    int i = start;
    for (; i < end; ++i) {
        out[i - start] = buffer[i];
    }
    out[i - start] = '\0';
    return end-start;
}

int main() {
    extern const int adjectives_len;
    extern const char adjectives_memory[];
    extern const int nouns_len;
    extern const char nouns_memory[];
    srand(time(NULL));
    //int start = rand() % 0);
    //srand(1);
    char adj[28];
    char noun[28];
    int max = 13;
    int min = 13;
    int min_word = 3;
    for (int i = 0; i < 1240; ++i) {
        int count = 0;
        count += random_word(adj, adjectives_memory, adjectives_len);
        count += random_word(noun, nouns_memory, nouns_len);
        //printf("%d %s.%s %s%s\n", count, adj, noun, adj, noun);
        printf("%s%s\n", adj, noun);
    }
    return 0;
}
