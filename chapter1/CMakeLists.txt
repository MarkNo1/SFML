cmake_minimum_required(VERSION 3.5.1)
project(SFML-Book)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_NAME "game")
set(RESOURCE_DIR "/resource/")

include_directories(
      lib
      ${PROJECT_BINARY_DIR}
)

file(GLOB ASTEROIDS_SOURCE
      "src/*.cpp"
      )

MESSAGE( STATUS "PROJECT_BINARY_DIR:     " ${PROJECT_BINARY_DIR} )
MESSAGE( STATUS "SOURCE FILES: " )
foreach (_variableName ${ASTEROIDS_SOURCE})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}${RESOURCE_DIR}
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}${RESOURCE_DIR})
#####################################################################################################################################


# Add directory containing FindSFML.cmake to module path
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/;${CMAKE_MODULE_PATH}")

# Find SFML
# Note: SFML_STATIC_LIBRARIES determines which libraries are found by find_package()
find_package(SFML 2 COMPONENTS graphics window system )

# If found, include and link; otherwise output error message
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
else()
	set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
	message("\n-> SFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
	message("-> Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

######################################################################################################################################


add_executable(${EXECUTABLE_NAME} ${ASTEROIDS_SOURCE} )
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
