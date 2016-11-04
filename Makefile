CPPFLAGS+= -Wall -Wextra -Wpedantic -Wextra -Wpedantic -Wwrite-strings 
CPPFLAGS+= -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

CFLAGS+=-std=c11
CFLAGS+=-g
LDLIBS += -lm

hangman:hangman.c




