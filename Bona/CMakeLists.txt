cmake_minimum_required (VERSION 3.20)
project (Bona)

set(CMAKE_CXX_STANDARD 17)

file(GLOB ASSETS 
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SDL3/bin/*")
file(COPY ${ASSETS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(SDL3_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SDL3/cmake)
find_package(SDL3)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/SDL3/include)

aux_source_directory (. DIRSRCS)
add_subdirectory(util)
add_subdirectory(pipeline)

add_executable (Bona ${DIRSRCS})

target_link_libraries(Bona
    PRIVATE
    SDL3::SDL3
    PUBLIC
    utilLib
    pipelineLib)
