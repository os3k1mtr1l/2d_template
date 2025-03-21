# 2D Template

A simple template for creating **2D games or applications** using [Raylib](https://github.com/raysan5/raylib).

## Requirements

This project is designed **exclusively for Windows (64-bit)** and supports **MinGW (GCC)** and **MSVC (Visual Studio)** compilers.  
It primarily uses the **C++17** standard.

## Building

Before building the project, you need to generate the project files using **Premake5**.  
You can find `premake5` in the [`vendor/`](vendor/) folder or download it from the official [website](https://premake.github.io/) or [GitHub releases](https://github.com/premake/premake-core).  

### Generating project files
Open `cmd` or PowerShell and navigate to the folder containing `premake5.lua`, then run:

#### For Visual Studio (`vs2022` or other versions)
```bash
premake5 vs2022
```
**Note:** The `vs2022` argument depends on your installed version of Visual Studio. Adjust accordingly.  

#### For MinGW (`mingw32-make`)
```bash
premake5 gmake
```

### *Building the project
After generating the project files, **build the project** using one of the following methods:

Visual Studio 
- Open the generated solution (`.sln` file).  
- Press `F5` to build and run the project.  

MinGW (`mingw32-make`)
- Run `mingw32-make` in the terminal:
```bash
mingw32-make
```
- Optionally, use `help` as a parameter to see available build options.

### Finally
After a successful build, the compiled binaries will be located in the `bin/` folder under the corresponding configuration (`Debug` or `Release`).

## Third party
This project uses the following dependencies:

- [**Premake5**](https://github.com/premake/premake-core/blob/master/LICENSE.txt) – for project file generation.  
- [**Raylib**](https://github.com/raysan5/raylib/blob/master/LICENSE) – the main rendering and game engine library.
