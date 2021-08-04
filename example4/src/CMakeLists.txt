cmake_minimum_required(VERSION 2.6)

# fix cmake cross ccompilation issues
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(Example4 C)

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

FIND_LIBRARY(ubox_library NAMES ubox)
FIND_LIBRARY(blob_library NAMES blobmsg_json)
FIND_LIBRARY(json         NAMES json-c json)

FIND_PATH(ubox_include_dir libubox/usock.h)
INCLUDE_DIRECTORIES(${ubox_include_dir})


ADD_EXECUTABLE(MCUDaemon main.c)
TARGET_LINK_LIBRARIES(MCUDaemon ${ubox_library} ${blob_library} ${json})

INSTALL(TARGETS MCUDaemon 
        RUNTIME DESTINATION /usr/bin/)
