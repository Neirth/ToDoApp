cmake_minimum_required(VERSION 3.19)

# Include compiler configuration
include(${CMAKE_SOURCE_DIR}/script/cmake/CompilerConfiguration.cmake)

# Set project name
project(ToDoApp CXX)

# Set compiler parameters 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Oz -s DISABLE_EXCEPTION_CATCHING=0")

# Include package manager script 
include(${CMAKE_SOURCE_DIR}/script/cmake/PackageManager.cmake)

# Load package into CMake
find_package(fruit)
find_package(jsoncpp)

# Files to link in the same binary object
add_executable(
    todoapp 

    src/main/cpp/io/neirth/todoapp/domain/Task.h
    src/main/cpp/io/neirth/todoapp/domain/Task.cc
    src/main/cpp/io/neirth/todoapp/service/MainService.h
    src/main/cpp/io/neirth/todoapp/service/MainService.cc
    src/main/cpp/io/neirth/todoapp/repository/TaskRepository.h
    src/main/cpp/io/neirth/todoapp/repository/TaskRepository.cc

    src/main/cpp/io/neirth/todoapp/utility/Utilities.cc
    src/main/cpp/io/neirth/todoapp/utility/Utilities.h

    src/main/cpp/io/neirth/todoapp/bridge/webassembly/Domain.cc
    src/main/cpp/io/neirth/todoapp/bridge/webassembly/Service.cc
    src/main/cpp/io/neirth/todoapp/bridge/webassembly/BusinessLayer.cc
)

set(MODULE_OPTS " -s MODULARIZE=1 -s EXPORT_ES6=1 -s USE_ES6_IMPORT_META=0 -s STRICT=1")
set(COMMON_OPTS " -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s SINGLE_FILE=1 -s FILESYSTEM=0 -s DISABLE_EXCEPTION_CATCHING=0 --bind --no-entry")
set(ASYNCIFY_OPTS " -s ASYNCIFY -s ASYNCIFY_IMPORTS=[\"insert_task_js\",\"update_task_js\",\"delete_task_js\",\"find_by_id_task_js\",\"find_all_task_js\"]")

if(${CMAKE_BUILD_TYPE} EQUAL "Debug")
    set(EMSCRIPTEN_OPTS " -O0")
else()
    set(EMSCRIPTEN_OPTS " -flto -Oz")
endif()

set_target_properties(todoapp PROPERTIES LINK_FLAGS ${COMMON_OPTS}${MODULE_OPTS}${ASYNCIFY_OPTS}${EMSCRIPTEN_OPTS})

# Link libraries into shared library
target_link_libraries(todoapp fruit::fruit jsoncpp::jsoncpp)
