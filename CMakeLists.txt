cmake_minimum_required(VERSION 3.20)

project(SecureVault C)

set(CMAKE_C_STANDARD 17)

# include headers
include_directories(include)

# sorgenti
set(SOURCES
    src/main.c
    src/utils.c
    src/fs/file.c
    src/crypto/crypto.c)

# eseguibile
add_executable(SecureVault ${SOURCES})