cmake_minimum_required(VERSION 3.21)
project(cw3 C)

set(CMAKE_C_STANDARD 99)

add_executable(cw3 main.c library.h user.h utility.h user.c utility.c library.c librarian.c librarian.h reg_or_login.c reg_or_login.h search_for_books.c search_for_books.h book_management.h test.c libararian.c libararian.h)
