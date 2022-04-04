# code details

EXE = ./library
SRC= main.c library.c librarian.c user.c utility.c reg_or_login.c search_for_books.c

# generic build details

CC=      gcc
CFLAGS= -std=c99 -Wall
CLINK=

# compile to object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE)

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:      main.c library.h
library.o:   library.c library.h librarian.h user.h utility.h book_management.h reg_or_login.h
librarian.o: librarian.c librarian.h book_management.h search_for_books.h utility.h
user.o:      user.c user.h book_management.h search_for_books.h library.h librarian.h
utility.o:   utility.c utility.h
reg_or_login.o:      reg_or_login.c reg_or_login.h utility.h book_management.h
search_for_books.o:      search_for_books.c search_for_books.h book_management.h

