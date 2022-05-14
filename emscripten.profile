include(default)

[settings]
os=Emscripten
arch=asm.js
compiler=clang
compiler.version=15
compiler.libcxx=libc++

[env]
CFLAGS=-DSQLITE_OMIT_POPEN
CXXFLAGS=-DSQLITE_OMIT_POPEN

AR=/home/codespace/.emsdk/upstream/emscripten/emar
CC=/home/codespace/.emsdk/upstream/emscripten/emcc
CXX=/home/codespace/.emsdk/upstream/emscripten/em++
RANLIB=/home/codespace/.emsdk/upstream/emscripten/emranlib

EMSDK=/home/codespace/.emsdk
EM_CONFIG=/home/codespace/.emsdk/.emscripten
EM_CACHE=/home/codespace/.emsdk/.emscripten_cache
EMSCRIPTEN=/home/codespace/.emsdk/upstream/emscripten/

CMAKE_C_COMPILER_VERSION=15
CMAKE_CXX_COMPILER_VERSION=15
CONAN_CMAKE_TOOLCHAIN_FILE=/home/codespace/.emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
