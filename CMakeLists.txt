cmake_minimum_required(VERSION 2.8)
project(listfatbadsectors)

set(SOURCES
    core/FatEntry.cpp
    core/FatFilename.cpp
    core/FatPath.cpp
    core/FatSystem.cpp
    core/FatDate.cpp
    )

foreach(SOURCE ${SOURCES})
    set(ALL_SOURCES ${ALL_SOURCES} src/${SOURCE})
endforeach()

include_directories("${CMAKE_SOURCE_DIR}/src")

add_executable(listfatbadsectors "src/listfatbadsectors.cpp" ${ALL_SOURCES})
install(TARGETS listfatbadsectors DESTINATION bin)
