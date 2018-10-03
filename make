#g++ ./src/*.cpp -o ./bin/test -DGLEW_STATIC -L./external/glew/lib -lGL -lGLEW -lglfw3

# run sudo pacman -Rs glfw-x11

g++ ./src/*.cpp -o ./bin/threedee -lGL -lGLU `pkg-config --static --libs x11 xrandr xi xxf86vm glew glfw3`
