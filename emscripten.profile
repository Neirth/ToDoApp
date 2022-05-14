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
CC=/home/codespace/.emsdk/upstream/emscripten/emcc
CXX=/home/codespace/.emsdk/upstream/emscripten/em++
RANLIB=/home/codespace/.emsdk/upstream/emscripten/emranlib
AR=/home/codespace/.emsdk/upstream/emscripten/emar
EMSDK=/home/codespace/.emsdk
EMSCRIPTEN=/home/codespace/.emsdk/upstream/emscripten/
EM_CONFIG=/home/codespace/.emsdk/.emscripten
EM_CACHE=/home/codespace/.emsdk/.emscripten_cache
CONAN_CMAKE_TOOLCHAIN_FILE=/home/codespace/.emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
