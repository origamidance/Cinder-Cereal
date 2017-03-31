cmake_minimum_required( VERSION 3.3 FATAL_ERROR )
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  message(STATUS "find ccache")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

project(CerealSample)


get_filename_component( CINDER_PATH "../../../../Cinder/" ABSOLUTE )

include( "${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake" )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

set(CI_APP_SOURCES
${CMAKE_CURRENT_LIST_DIR}/src/CerealApp.cpp
)

ci_make_app(
	SOURCES     ${CI_APP_SOURCES}
	CINDER_PATH ${CINDER_PATH}
	BLOCKS      ../../../Cinder-Cereal
  # LIBRARIES   nfd ${GTK3_LIBRARIES}
    # LIBRARIES   ${ENTITYX_LIBRARY}
)


