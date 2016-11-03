CPPFLAGS+=	-Wall -Wextra -Wpedantic 

CFLAGS+=-std=c11

LDLIBS += -lm

#CFLAGS+=-g

.PHONY: debug

debug: CFLAGS+=-g
