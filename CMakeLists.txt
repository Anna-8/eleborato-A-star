cmake_minimum_required(VERSION 3.14)
project(elaborato_A_star)

set(EXECUTABLE_NAME elaborato_A_star)

set(CMAKE_CXX_STANDARD 14)

add_executable(elaborato_A_star Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h Schermo.cpp Schermo.h Personaggio.h Personaggio.cpp Obiettivo.cpp Obiettivo.h)

set(SOURCE_FILE main.cpp Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h fsa.h )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/share/SFML/cmake/Modules/" )

find_package(SFML 2 COMPONENTS system network graphics window audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(elaborato_A_star ${SFML_LIBRARIES})
endif ()
add_subdirectory(test)
add_library(core ${SOURCE_FILE})
target_link_libraries(elaborato_A_star core)
#[[
cmake_minimum_required(VERSION 3.14)
project(elaborato_A_star)
add_executable(Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h)
set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/anna/Scrivania/SFML-2.5.1-Compiled/include")
set(SFML_LIBRARY_DIR "/home/anna/Scrivania/SFML-2.5.1-Compiled/lib")
set(SFML_DIR "/home/anna/Scrivania/SFML-2.5.1-Compiled/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLApp main.cpp)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)]]
