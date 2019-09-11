cmake_minimum_required(VERSION 3.14)
project(elaborato_A_star)

set(EXECUTABLE_NAME elaborato_A_star)

set(CMAKE_CXX_STANDARD 14)

add_executable(elaborato_A_star Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h Schermo.cpp Schermo.h Personaggio.h Personaggio.cpp Obiettivo.cpp Obiettivo.h)

set(SOURCE_FILE Mappa.h Mappa.cpp MapSearchNode.h MapSearchNode.cpp stlastar.h main.cpp fsa.h Schermo.cpp Schermo.h Personaggio.h Personaggio.cpp Obiettivo.cpp Obiettivo.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/share/SFML/cmake/Modules/" )

find_package(SFML 2 COMPONENTS system network graphics window audio REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(elaborato_A_star ${SFML_LIBRARIES})
endif ()
add_subdirectory(test)
add_library(core ${SOURCE_FILE})
target_link_libraries(elaborato_A_star core)
