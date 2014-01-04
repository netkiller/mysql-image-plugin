cmake_minimum_required(VERSION 2.8)
PROJECT(image)
ADD_LIBRARY(image SHARED image.c)
INCLUDE_DIRECTORIES(/usr/include/mysql)
#TARGET_LINK_LIBRARIES(fifo )
INSTALL(PROGRAMS libimage.so DESTINATION /usr/lib/mysql/plugin/)

