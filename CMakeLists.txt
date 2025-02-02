cmake_minimum_required(VERSION 3.15)
project(MyGameEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "d")  # Для отладочных версий библиотек

# Включить поддержку папок в IDE
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Настройки SDL
set(SDL_SHARED OFF CACHE BOOL "Build shared SDL3 library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build static SDL3 library" FORCE)
set(SDL_TEST OFF CACHE BOOL "Disable SDL tests" FORCE)

# Настройки GLEW
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static GLEW" FORCE)
set(GLEW_USE_STATIC_LIBS ON)

# Добавляем подмодули
add_subdirectory(extern/SDL)
add_subdirectory(extern/glew)

# Группировка целей SDL
set(SDL_TARGETS SDL3-static SDL3_test SDL_uclibc)
foreach(target IN LISTS SDL_TARGETS)
    if(TARGET ${target})
        set_property(TARGET ${target} PROPERTY FOLDER "extern/SDL")
    endif()
endforeach()

# Группировка целей GLEW
set(GLEW_TARGETS libglew_static)
foreach(target IN LISTS GLEW_TARGETS)
    if(TARGET ${target})
        set_property(TARGET ${target} PROPERTY FOLDER "extern/glew")
    endif()
endforeach()

# Исходники проекта
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.c"
)

file(GLOB_RECURSE HEADERS 
    "include/*.h"
    "include/*.hpp"
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Пути для заголовков
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/extern/SDL/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/extern/glew/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Линковка библиотек
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3-static     # Статическая SDL3
    libglew_static  # Статическая GLEW
)

# Системные зависимости для Windows
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        opengl32.lib
        glu32.lib
    )
endif()

# Группировка исходников в IDE
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "src" FILES ${SOURCES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/include" PREFIX "include" FILES ${HEADERS})