PROJECT(ImageProcessing)

# REQUIREMENTS
cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )

# Project's source files
file(
		GLOB_RECURSE
		source_files
		src/*
)

#Executable creation
add_executable( 
	prog 
	${source_files} 
)


target_link_libraries( prog ${OpenCV_LIBS} )
include_directories(src)