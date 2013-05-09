CMAKE_MINIMUM_REQUIRED (VERSION 2.6.2)
PROJECT (SDL_TUTORIAL)

#
# Project Output Paths
#
SET (MAINFOLDER ${PROJECT_SOURCE_DIR})
SET (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")

Find_Package ( SDL REQUIRED )
if ( NOT SDL_FOUND )
    message ( FATAL_ERROR "SDL not found!" )
endif (NOT SDL_FOUND)

link_libraries (
    ${SDL_LIBRARY}
    SDLmain
)


add_subdirectory("src")

add_custom_command(TARGET run COMMAND bin/main)
