cmake_minimum_required (VERSION 2.8)

#configuration du projet
project(CORNEVISUALISATION)


set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

include_directories("include")

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#Génération de la liste des fichiers sources
file (
		GLOB_RECURSE
		source_files
		src/*
)


add_executable(
	Cornea

	${source_files}

	main.cpp
)

target_link_libraries(Cornea ${VTK_LIBRARIES})

#message(${VTK_LIBRARIES})


