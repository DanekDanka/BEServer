cmake_minimum_required(VERSION 3.28)
project(BEServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(BEServer main.cpp
        src/Server.cpp
        src/Sender.cpp
        src/Fabric.cpp
        include/Server.h
        include/Sender.h
        include/Fabric.h
        src/Recevier.cpp
        include/Recevier.h
        src/Storage.cpp
        include/Storage.h
        src/Message.cpp
        include/Message.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
)
