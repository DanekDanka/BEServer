cmake_minimum_required(VERSION 3.28)
project(BEServer)

set(CMAKE_CXX_STANDARD 20)

#add_library(${PROJECT_NAME} SHARED
#        src/core.cpp
#        include/core.h
#)

add_executable(BEServer main.cpp
        src/Client.cpp
        src/MessageStr.cpp
        src/Sender.cpp
        src/Fabric.cpp
        include/Client.h
        include/IMessage.h
        include/MessageStr.h
        include/Sender.h
        include/Fabric.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
)
