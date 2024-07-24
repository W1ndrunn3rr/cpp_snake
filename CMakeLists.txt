cmake_minimum_required (VERSION 3.1)

project (Snake)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

IF (WIN32)
    # Include local sfml cmake config
    set(SFML_DIR "C:/lib/SFML-2.5.1/lib/cmake/SFML")
    # Link sfml statically (Optional)
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

add_executable(Snake main.cpp src/Board.cpp lib/Board.h src/Controller.cpp lib/Controller.h src/MenuController.cpp lib/MenuController.h src/Menu.cpp lib/Menu.h src/Menu.cpp src/GameView.cpp lib/GameView.h src/Scoreboard.cpp lib/Scoreboard.h src/Scoreboard.cpp src/GameObjects.cpp lib/GameObjects.h)
target_link_libraries(Snake sfml-graphics)

