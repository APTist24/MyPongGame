cmake_minimum_required(VERSION 3.15)
project(MyPongGame VERSION 0.1.0 LANGUAGES CXX)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включение SDL2 из папки extern
add_subdirectory(extern/SDL2)

# Настройка исходников
file(SOURCES 
    "src/*.cpp"          # Все .cpp файлы в src/ и поддиректориях
)

file(HEADERS 
    "include/*.h"        # Все .h файлы в include/ и поддиректориях
)

# Создание исполняемого файла
add_executable(MyPongGame  ${SOURCES} ${HEADERS})

# Подключение SDL2
target_link_libraries(MyPongGame PRIVATE SDL2::SDL2)

# Для Windows: копирование DLL
if(WIN32)
    add_custom_command(TARGET MyPongGame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_SOURCE_DIR}/extern/SDL2/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:MyPongGame>
    )
endif()