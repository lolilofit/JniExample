cmake_minimum_required(VERSION 3.15)
project(JniProject C)

set(CMAKE_C_STANDARD 99)

include_directories("$ENV{JAVA_HOME}/include")
include_directories("$ENV{JAVA_HOME}/include/win32")
include_directories("D:/JavaProjects/jni/JniProject/src")

add_link_options("-Wl,--add-stdcall-alias")
add_library(JniProject SHARED library.c)