# Random Username Generator

# How to run

```
./random_username_generator
```

# How it works!

1. Picks a random byte inside the file
2. Seeks to the beginning of that word, sets the start index
3. Seeks to the end of that word, changes newline to \0 (to delinate the end of a string)

# Notes

This is not completely random, longer words are favored. I favored a design that's simplistic in structure and in logic. 
