cmake_minimum_required(VERSION 3.28)
project(BEServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(BEServer main.cpp
        src/Server.cpp
        include/Server.h
        src/Storage.cpp
        include/Storage.h
        include/SocketConnection.h
        src/SocketConnection.cpp
        src/ServerLogger.cpp
        include/ServerLogger.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}
)
