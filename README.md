Compile with: gcc -I/usr/pkg/include -L/usr/pkg/lib main.c -lreadline -lncurses

My file currently works for single word commands and most arguments.  Does
not seem to work with the wildcard character, cd, or going back to previous
commands, even though I am using readline.  I think DC was having the same 
problem, so I'm not too worried.
