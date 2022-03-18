cmake_minimum_required(VERSION 3.21)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c library.c library.h book_management.h librarian.c librarian.h utility.c utility.h reg_or_login.c reg_or_login.h search_for_books.c search_for_books.h user.c user.h)
