# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Proyecto_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto_1.dir/flags.make

CMakeFiles/Proyecto_1.dir/main.cpp.obj: CMakeFiles/Proyecto_1.dir/flags.make
CMakeFiles/Proyecto_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto_1.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Proyecto_1.dir\main.cpp.obj -c "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\main.cpp"

CMakeFiles/Proyecto_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_1.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\main.cpp" > CMakeFiles\Proyecto_1.dir\main.cpp.i

CMakeFiles/Proyecto_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_1.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\main.cpp" -o CMakeFiles\Proyecto_1.dir\main.cpp.s

# Object files for target Proyecto_1
Proyecto_1_OBJECTS = \
"CMakeFiles/Proyecto_1.dir/main.cpp.obj"

# External object files for target Proyecto_1
Proyecto_1_EXTERNAL_OBJECTS =

Proyecto_1.exe: CMakeFiles/Proyecto_1.dir/main.cpp.obj
Proyecto_1.exe: CMakeFiles/Proyecto_1.dir/build.make
Proyecto_1.exe: CMakeFiles/Proyecto_1.dir/linklibs.rsp
Proyecto_1.exe: CMakeFiles/Proyecto_1.dir/objects1.rsp
Proyecto_1.exe: CMakeFiles/Proyecto_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Proyecto_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Proyecto_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto_1.dir/build: Proyecto_1.exe
.PHONY : CMakeFiles/Proyecto_1.dir/build

CMakeFiles/Proyecto_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Proyecto_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto_1.dir/clean

CMakeFiles/Proyecto_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1" "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1" "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug" "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug" "C:\Users\renea\OneDrive\Documentos\Eduardo\Archivos\Proyecto 1\cmake-build-debug\CMakeFiles\Proyecto_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto_1.dir/depend

