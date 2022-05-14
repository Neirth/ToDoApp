<p align="center">
  <img src="./assets/Logo.png?raw=true">
</p>

This is a Todo WebApplication using C++ and IndexedDB as base.

# Why this project?
This project is designed to testing a mix of technologies, such as Asm.js, Fruit (From Google), IndexedDB, Conan, JsonCPP, and WebComponents. This project, trutly, it won't make your life easier, but can inspire for make a more useful and interesting project with C++ for Web Platforms.

Even so, if your idea is to have the panacea of writing a single application for the Web, iOS or Android. I highly recommend watching Kotlin Multiplatform or Flutter, it will save you a lot of headaches.

A small example of why these techniques may not be sufficient for the needs of your application:
[The (not so) hidden cost of sharing code between iOS and Android](https://dropbox.tech/mobile/the-not-so-hidden-cost-of-sharing-code-between-ios-and-android)

## Installation

For build this project, we must be configure before a Conan Dependency System, Cmake Build System and Emscripten WebAssembly SDK
```bash
[neirth@codespace todoapp]$ mkdir buildjs && cd buildjs
[neirth@codespace buildjs]$ conan install -pr ../emscripten.profile ../conanfile.txt --build=fruit --build=jsoncpp --build=sqlite3
[neirth@codespace buildjs]$ emcmake cmake build ..
[neirth@codespace buildjs]$ make -j 8
[neirth@codespace buildjs]$
```

## Usage

After build the project, copy the content of the folder __./example__ into your web server, or run this

```bash
[neirth@codespace todoapp]$ cd ./example
[neirth@codespace example]$ python -m http.server
Serving HTTP on 0.0.0.0 port 8000 (http://0.0.0.0:8000/) ...
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
