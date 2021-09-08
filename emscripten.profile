include(default)

[settings]
os=Emscripten
arch=asm.js
compiler=clang
compiler.version=13.0
compiler.libcxx=libc++

[env]
CC=/home/builder/.local/emsdk/upstream/emscripten/emcc
CXX=/home/builder/.local/emsdk/upstream/emscripten/em++
CFLAGS=-DSQLITE_OMIT_POPEN
CXXFLAGS=-DSQLITE_OMIT_POPEN
RANLIB=/home/builder/.local/emsdk/upstream/emscripten/emranlib
AR=/home/builder/.local/emsdk/upstream/emscripten/emar
EMSDK=/home/builder/.local/emsdk
EMSCRIPTEN=/home/builder/.local/emsdk/upstream/emscripten/
EM_CONFIG=/home/builder/.local/emsdk/.emscripten
EM_CACHE=/home/builder/.local/emsdk/.emscripten_cache
CONAN_CMAKE_TOOLCHAIN_FILE=/home/builder/.local/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
