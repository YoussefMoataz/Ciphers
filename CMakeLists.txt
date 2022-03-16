cmake_minimum_required(VERSION 3.21)
project(Ciphers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ciphers "main.cpp" "CaesarCipher_20211111.cpp" "VignereCipher_20210083.cpp" "XORCipher_20210488.cpp")
