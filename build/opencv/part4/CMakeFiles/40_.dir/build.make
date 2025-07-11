# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bangme/bangme/bangme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bangme/bangme/bangme/build

# Include any dependencies generated for this target.
include opencv/part4/CMakeFiles/40_.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include opencv/part4/CMakeFiles/40_.dir/compiler_depend.make

# Include the progress variables for this target.
include opencv/part4/CMakeFiles/40_.dir/progress.make

# Include the compile flags for this target's objects.
include opencv/part4/CMakeFiles/40_.dir/flags.make

opencv/part4/CMakeFiles/40_.dir/40_.cpp.o: opencv/part4/CMakeFiles/40_.dir/flags.make
opencv/part4/CMakeFiles/40_.dir/40_.cpp.o: ../opencv/part4/40_.cpp
opencv/part4/CMakeFiles/40_.dir/40_.cpp.o: opencv/part4/CMakeFiles/40_.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object opencv/part4/CMakeFiles/40_.dir/40_.cpp.o"
	cd /home/bangme/bangme/bangme/build/opencv/part4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT opencv/part4/CMakeFiles/40_.dir/40_.cpp.o -MF CMakeFiles/40_.dir/40_.cpp.o.d -o CMakeFiles/40_.dir/40_.cpp.o -c /home/bangme/bangme/bangme/opencv/part4/40_.cpp

opencv/part4/CMakeFiles/40_.dir/40_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/40_.dir/40_.cpp.i"
	cd /home/bangme/bangme/bangme/build/opencv/part4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bangme/bangme/bangme/opencv/part4/40_.cpp > CMakeFiles/40_.dir/40_.cpp.i

opencv/part4/CMakeFiles/40_.dir/40_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/40_.dir/40_.cpp.s"
	cd /home/bangme/bangme/bangme/build/opencv/part4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bangme/bangme/bangme/opencv/part4/40_.cpp -o CMakeFiles/40_.dir/40_.cpp.s

# Object files for target 40_
40__OBJECTS = \
"CMakeFiles/40_.dir/40_.cpp.o"

# External object files for target 40_
40__EXTERNAL_OBJECTS =

opencv/part4/40_: opencv/part4/CMakeFiles/40_.dir/40_.cpp.o
opencv/part4/40_: opencv/part4/CMakeFiles/40_.dir/build.make
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_alphamat.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_barcode.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_intensity_transform.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_mcc.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_rapid.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_wechat_qrcode.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.5.4d
opencv/part4/40_: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.5.4d
opencv/part4/40_: opencv/part4/CMakeFiles/40_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bangme/bangme/bangme/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 40_"
	cd /home/bangme/bangme/bangme/build/opencv/part4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/40_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
opencv/part4/CMakeFiles/40_.dir/build: opencv/part4/40_
.PHONY : opencv/part4/CMakeFiles/40_.dir/build

opencv/part4/CMakeFiles/40_.dir/clean:
	cd /home/bangme/bangme/bangme/build/opencv/part4 && $(CMAKE_COMMAND) -P CMakeFiles/40_.dir/cmake_clean.cmake
.PHONY : opencv/part4/CMakeFiles/40_.dir/clean

opencv/part4/CMakeFiles/40_.dir/depend:
	cd /home/bangme/bangme/bangme/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bangme/bangme/bangme /home/bangme/bangme/bangme/opencv/part4 /home/bangme/bangme/bangme/build /home/bangme/bangme/bangme/build/opencv/part4 /home/bangme/bangme/bangme/build/opencv/part4/CMakeFiles/40_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : opencv/part4/CMakeFiles/40_.dir/depend

