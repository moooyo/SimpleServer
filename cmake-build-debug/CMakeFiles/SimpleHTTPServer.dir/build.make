# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lengyu/CLionProjects/SimpleHTTPServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SimpleHTTPServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleHTTPServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleHTTPServer.dir/flags.make

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o: ../SimpleHTTPServer/base/ListenServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/ListenServer.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/ListenServer.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/ListenServer.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o: ../SimpleHTTPServer/base/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/main.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/main.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/main.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o: ../SimpleHTTPServer/tool/epollHelp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/epollHelp.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/epollHelp.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/epollHelp.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o: ../SimpleHTTPServer/tool/errHelp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/errHelp.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/errHelp.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/errHelp.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o: ../SimpleHTTPServer/tool/io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/io.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/io.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/io.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o: ../SimpleHTTPServer/tool/nethelp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/nethelp.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/nethelp.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/nethelp.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o: ../SimpleHTTPServer/tool/HTTP/httpContext.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/HTTP/httpContext.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/HTTP/httpContext.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/HTTP/httpContext.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o: ../SimpleHTTPServer/tool/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/Buffer.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/Buffer.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/tool/Buffer.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.s

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o: CMakeFiles/SimpleHTTPServer.dir/flags.make
CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o: ../SimpleHTTPServer/base/HTTPTask.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o -c /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/HTTPTask.cpp

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/HTTPTask.cpp > CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.i

CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lengyu/CLionProjects/SimpleHTTPServer/SimpleHTTPServer/base/HTTPTask.cpp -o CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.s

# Object files for target SimpleHTTPServer
SimpleHTTPServer_OBJECTS = \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o" \
"CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o"

# External object files for target SimpleHTTPServer
SimpleHTTPServer_EXTERNAL_OBJECTS =

SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/ListenServer.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/main.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/epollHelp.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/errHelp.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/io.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/nethelp.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/HTTP/httpContext.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/tool/Buffer.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/SimpleHTTPServer/base/HTTPTask.cpp.o
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/build.make
SimpleHTTPServer: CMakeFiles/SimpleHTTPServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable SimpleHTTPServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleHTTPServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleHTTPServer.dir/build: SimpleHTTPServer

.PHONY : CMakeFiles/SimpleHTTPServer.dir/build

CMakeFiles/SimpleHTTPServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleHTTPServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleHTTPServer.dir/clean

CMakeFiles/SimpleHTTPServer.dir/depend:
	cd /home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lengyu/CLionProjects/SimpleHTTPServer /home/lengyu/CLionProjects/SimpleHTTPServer /home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug /home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug /home/lengyu/CLionProjects/SimpleHTTPServer/cmake-build-debug/CMakeFiles/SimpleHTTPServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleHTTPServer.dir/depend

