cmake_minimum_required(VERSION 3.16)
project("T3Vtech-3")

set(BUILD_MODE "DEBUG")

if (NOT MSVC)
    if (BUILD_MODE EQUAL "RELEASE")
        # BASICALLY RELEASE MODE
        SET(CMAKE_CXX_FLAGS  "-m64 -Ofast -flto -march=native")
    elseif (BUILD_MODE EQUAL "DEBUG")
        # DEBUG MODE
        SET(CMAKE_CXX_FLAGS "-g -ggdb -fsanitize=address")
        SET(CMAKE_CXX_FLAGS "-g -Werror -Wall -Wextra")
        SET(CMAKE_CXX_FLAGS "-O0 -g -D _DEBUG")
    endif()
endif()

#PROFILERMODE
#SET(CMAKE_CXX_FLAGS "-g -pg")

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include(FindPkgConfig)
find_package(OpenAL REQUIRED)
if (WIN32)
    find_package(OPENGL REQUIRED)
else()
    find_package(OpenGL REQUIRED)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(GLEW REQUIRED)

# T3Vtech-3 dependency
include_directories(vendor/T3Vtech-3/src/engine/)
include_directories(vendor/T3Vtech-3/vendor/stb/)
include_directories(vendor/T3Vtech-3/vendor/Tlib/)
file(GLOB_RECURSE "engine" SRC vendor/T3Vtech-3/src/engine/*.c)
add_library(T3Vtech STATIC ${engine})

target_link_libraries(T3Vtech LINK_PRIVATE "${OPENGL_LIBRARIES}")
target_link_libraries(T3Vtech LINK_PRIVATE "${OPENAL_LIBRARY}")

if (MSVC)
    target_link_libraries(T3Vtech LINK_PRIVATE "${SDL2_LIBRARIES}")   
    target_link_libraries(T3Vtech LINK_PRIVATE "${GLEW_LIBRARIES}")
    target_link_libraries(T3Vtech LINK_PRIVATE "${SDL2_TTF_LIBRARY}")
endif()


if (NOT MSVC)
    set_target_properties(T3Vtech PROPERTIES LINK_SEARCH_START_STATIC ON)
    link_directories(/usr/lib64/)
    target_link_options(T3Vtech PRIVATE -static-libgcc -static-libstdc++ -static)
    target_link_libraries(T3Vtech LINK_PRIVATE SDL2)
    target_link_libraries(T3Vtech LINK_PRIVATE SDL2_ttf)
    target_link_libraries(T3Vtech LINK_PRIVATE GLEW)
    target_link_libraries(T3Vtech LINK_PRIVATE m)
    set_target_properties(T3Vtech PROPERTIES LINK_SEARCH_END_STATIC ON)
endif()


include_directories("${SDL2_INCLUDE_DIRS}")
include_directories("${SDL2_TTF_INCLUDE_DIRS}")
include_directories("${GLEW_INCLUDE_DIR}")
include_directories("${OPENAL_INCLUDE_DIR}")

include_directories(src/)
file(GLOB_RECURSE "template-src" SRC src/*.cpp src/*.c)
file(GLOB_RECURSE "template-header" SRC src/*.hpp src/*.h)
add_executable(template WIN32 ${template-src} ${template-header})
target_link_libraries(template LINK_PRIVATE T3Vtech)
file(COPY vendor/T3Vtech-3/shaders DESTINATION .)
file(COPY vendor/T3Vtech-3/settings DESTINATION .)
file(COPY assets DESTINATION .)
