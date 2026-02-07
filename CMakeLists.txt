cmake_minimum_required(VERSION 3.10)

project(CppGameProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(tictactoe ${SOURCES})

# --- Emscripten (WebAssembly/JS) build ---
if(EMSCRIPTEN)
  set_target_properties(tictactoe PROPERTIES
    OUTPUT_NAME "game"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
  )
  target_link_options(tictactoe PRIVATE
    "SHELL:-s EXPORTED_FUNCTIONS=['_createGame','_destroyGame','_makeMove','_getBoard','_resetGame','_makeComputerMove','_getStatus']"
    "SHELL:-s EXPORTED_RUNTIME_METHODS=['cwrap','ccall']"
    "SHELL:-s ENVIRONMENT=web"
  )
endif()
