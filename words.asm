bits 64
section .rodata

global _adjectives_memory
global _adjectives_len
_adjectives_memory: incbin "adjectives.txt"
_adjectives_len: dd $-_adjectives_memory

global _nouns_memory
global _nouns_len
_nouns_memory: incbin "nouns.txt"
_nouns_len: dd $-_nouns_memory

