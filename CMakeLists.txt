cmake_minimum_required(VERSION 2.6)
project(Omicron)

set(SRCS

    src/omicron/system/System.cpp
)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++0x -DGL_GLEXT_PROTOTYPES")

include_directories("${BASEPATH}" ${INCLUDE_DIRECTORIES})

link_directories(${LINK_DIRECTORIES})

add_executable(Omicron ${SRCS})

target_link_libraries(Omicron

    -lGL
    -lGLU
    -lglut
    -lm
    -lpng
)
