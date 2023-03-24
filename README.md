# T3Vtech-3-template
T3Vtech-3 game engine template repository. Simply fork it to use the engine.

# Dependencies

The dependencies of the engine are

```
SDL2
SDL2_ttf
GLEW
OpenAL
OpenGL
```

Once you installed everything appropriately to your OS then you can build with the commands in the "Usage" section.

# Usage
Once you have all dependencies you can set up the repository by calling

```
git submodule update --init --recursive --checkout
```

If you want to build something with the engine i.e. the example.cpp file you can use the commands

```
mkdir build
cd build
cmake ..
make
```