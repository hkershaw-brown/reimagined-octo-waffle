# cpp-game-project

## Overview
Noughts and crosses (aka tic-tac-toe). C++ and a webassembly version

## Project Structure
```
cpp-game-project
├── index.html          # for the web assmebly version
├── src
│   ├── main.cpp        # Entry point of the game C++
│   ├── game.cpp        # Implementation of the Game class
│   └── game.h          # Declaration of the Game class
├── include
│   └── utils.h         # Utility functions
├── CMakeLists.txt      # Build configuration
└── README.md           # Project documentation
```

## C++ version
Use cmake to build:

```
cmake -S . -B build
cmake --build build
```

Run with:

```
build/tictactoe
```

## Web version
Uses Emscripten to compile the websembly
Use cmake to build:

```
source /path/to/emsdk/emsdk_env.sh
emcmake cmake -S . -B build-wasm
cmake --build build-wasm
```

Run locally with:

```
python3 -m http.server 8000
```

```
open index.html
```