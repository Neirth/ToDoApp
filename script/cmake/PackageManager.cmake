# Download Package Manager
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

# Import package manager
include(${CMAKE_BINARY_DIR}/conan.cmake)

# Configuration of Conan
conan_cmake_install(PATH_OR_REFERENCE ${CMAKE_SOURCE_DIR} PROFILE ../emscripten.profile BUILD missing REMOTE conancenter SETTINGS ${settings})