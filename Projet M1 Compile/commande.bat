flex lexical.l
bison -d S.y
gcc lex.yy.c S.tab.c quad.c -lfl -ly -o zizou2023.exe
zizou2023.exe<prog.txt
pause