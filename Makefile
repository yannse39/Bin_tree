-include ../Makefile.rules

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-L. -lmybintree
LIB_NAME=libmybintree

SRC_DIR=src
TEST_DIR=check

SRC=	$(wildcard 	$(SRC_DIR)/*.c)
OBJ=	$(SRC:.c=.o)

TEST_SRC=	$(wildcard $(TEST_DIR)/*.c)
TEST_OBJ=	$(TEST_SRC:.c=.o)
TEST_EXE=	$(TEST_DIR)/tests	tests_2	tests_3	tests_4	tests_5

all:	static dynamic	$(TEST_EXE)

static:	$(OBJ)
	ar	rcs	$(LIB_NAME).a	$(OBJ)

dynamic:	$(OBJ)
	$(CC)	$(LDFLAGS)	-shared	-o	$(LIB_NAME).so	$(OBJ)

$(TEST_EXE):	$(TEST_OBJ)	$(OBJ)
	$(CC)	-o	$@	$^	$(LDFLAGS)

%.o:	%.c
	$(CC)	$(CFLAGS)	$<	-o	$@

clean:
	rm	-f	$(OBJ)	$(LIB_NAME).a	$(LIB_NAME).so	$(TEST_OBJ)	$(TEST_EXE)
dist:   clean
	tar	-cvjf	yann.meza-demehz-bastion.x-MiniProjet2.tar.bz2 *

distclean:      clean
	rm	-f	yann.meza-demehz-bastion.x-MiniProjet2.tar.gz

check:


.PHONY: all libmylpf static shared clean dist distclean check
