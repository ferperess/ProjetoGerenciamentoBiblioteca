# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Projeto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Projeto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Projeto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projeto.dir/flags.make

CMakeFiles/Projeto.dir/main.c.obj: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/main.c.obj: CMakeFiles/Projeto.dir/includes_C.rsp
CMakeFiles/Projeto.dir/main.c.obj: C:/Users/fepec/OneDrive/Documentos/Projeto\ Gerenciamento\ Bilioteca/main.c
CMakeFiles/Projeto.dir/main.c.obj: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Projeto.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projeto.dir/main.c.obj -MF CMakeFiles\Projeto.dir\main.c.obj.d -o CMakeFiles\Projeto.dir\main.c.obj -c "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\main.c"

CMakeFiles/Projeto.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Projeto.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\main.c" > CMakeFiles\Projeto.dir\main.c.i

CMakeFiles/Projeto.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Projeto.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\main.c" -o CMakeFiles\Projeto.dir\main.c.s

CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj: CMakeFiles/Projeto.dir/includes_C.rsp
CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj: C:/Users/fepec/OneDrive/Documentos/Projeto\ Gerenciamento\ Bilioteca/bibliotecaLivros.c
CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj -MF CMakeFiles\Projeto.dir\bibliotecaLivros.c.obj.d -o CMakeFiles\Projeto.dir\bibliotecaLivros.c.obj -c "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLivros.c"

CMakeFiles/Projeto.dir/bibliotecaLivros.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Projeto.dir/bibliotecaLivros.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLivros.c" > CMakeFiles\Projeto.dir\bibliotecaLivros.c.i

CMakeFiles/Projeto.dir/bibliotecaLivros.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Projeto.dir/bibliotecaLivros.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLivros.c" -o CMakeFiles\Projeto.dir\bibliotecaLivros.c.s

CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj: CMakeFiles/Projeto.dir/flags.make
CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj: CMakeFiles/Projeto.dir/includes_C.rsp
CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj: C:/Users/fepec/OneDrive/Documentos/Projeto\ Gerenciamento\ Bilioteca/bibliotecaLeitores.c
CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj: CMakeFiles/Projeto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj -MF CMakeFiles\Projeto.dir\bibliotecaLeitores.c.obj.d -o CMakeFiles\Projeto.dir\bibliotecaLeitores.c.obj -c "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLeitores.c"

CMakeFiles/Projeto.dir/bibliotecaLeitores.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Projeto.dir/bibliotecaLeitores.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLeitores.c" > CMakeFiles\Projeto.dir\bibliotecaLeitores.c.i

CMakeFiles/Projeto.dir/bibliotecaLeitores.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Projeto.dir/bibliotecaLeitores.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\bibliotecaLeitores.c" -o CMakeFiles\Projeto.dir\bibliotecaLeitores.c.s

# Object files for target Projeto
Projeto_OBJECTS = \
"CMakeFiles/Projeto.dir/main.c.obj" \
"CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj" \
"CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj"

# External object files for target Projeto
Projeto_EXTERNAL_OBJECTS =

Projeto.exe: CMakeFiles/Projeto.dir/main.c.obj
Projeto.exe: CMakeFiles/Projeto.dir/bibliotecaLivros.c.obj
Projeto.exe: CMakeFiles/Projeto.dir/bibliotecaLeitores.c.obj
Projeto.exe: CMakeFiles/Projeto.dir/build.make
Projeto.exe: CMakeFiles/Projeto.dir/linkLibs.rsp
Projeto.exe: CMakeFiles/Projeto.dir/objects1.rsp
Projeto.exe: CMakeFiles/Projeto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Projeto.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Projeto.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projeto.dir/build: Projeto.exe
.PHONY : CMakeFiles/Projeto.dir/build

CMakeFiles/Projeto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Projeto.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Projeto.dir/clean

CMakeFiles/Projeto.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca" "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca" "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug" "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug" "C:\Users\fepec\OneDrive\Documentos\Projeto Gerenciamento Bilioteca\cmake-build-debug\CMakeFiles\Projeto.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Projeto.dir/depend

