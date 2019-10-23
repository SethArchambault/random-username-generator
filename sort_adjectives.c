#include<stdio.h>
#include<stdlib.h>
char * temp;

char * get_word(char * word){
    int i = 0;
    for (; word[i] != '\n';++i) {
        temp[i] = word[i];
    }
    temp[i] = '\0';
    return temp;
}

int main() {
    temp = malloc(30);
    extern const char adjectives_memory[];
    extern const int adjectives_len;
    //char * adjectives = malloc(adjectives_len);
    int min = 1000;
    int max = 0;
    int count = 0;
    int start = 0;
    for (int i = 0; i < adjectives_len; ++i) {
        if (adjectives_memory[i] == '\0') {
            printf("%d %s\n", count, &adjectives_memory[start]);
            
            if (count < min) min = count;
            if (count > max) max = count;
            count = 0;
            start = i+1;
        }
        else {
            ++count;
        }
    }
    //printf("max %d min %d\n", max, min);

    return 0;
}
