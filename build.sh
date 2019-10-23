set -e
#cat adjectives_original.txt | tr '\n' '\0' > adjectives.txt
nasm -fmacho64 words.asm -o words.o
#cc words.o -o sort_adjectives sort_adjectives.c
#./sort_adjectives | sort -n > sort_adjectives.txt

cat nouns_original.txt | awk '{ print length, $0 }' | sort -n | awk '{ print $2 }' > nouns.txt
cat adjectives_original.txt | awk '{ print length, $0 }' | sort -n | awk '{ print $2 }' > adjectives.txt
cc words.o -o generate_username main.c
time ./generate_username | awk '{ print length, $0 }' | sort -n 
