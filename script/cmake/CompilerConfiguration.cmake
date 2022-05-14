# Make verbose enable
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set project standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE_INIT "Release")

# Set the output directory
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".js")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/example/js/service/)

# Set paths for modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

# Set compiler version
set(CMAKE_C_COMPILER_VERSION "15")
set(CMAKE_CXX_COMPILER_VERSION "15")
