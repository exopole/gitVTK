cmake_minimum_required (VERSION 2.8)

#configuration du projet
project(CORNEVISUALISATION)

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
	test

	${source_files}

	

)

target_link_libraries(test ${VTK_LIBRARIES})

#message(${VTK_LIBRARIES})


