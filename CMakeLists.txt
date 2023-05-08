cmake_minimum_required(VERSION 3.24)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} main.cpp Dot.cpp Dot.h Grid.cpp Grid.h)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET DrugaSpaZadaca POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:DrugaSpaZadaca> $<TARGET_FILE_DIR:DrugaSpaZadaca> COMMAND_EXPAND_LISTS)
endif ()
