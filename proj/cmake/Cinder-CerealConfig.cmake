if (NOT TARGET Cinder-Cereal)
    get_filename_component(CINDER-CEREAL_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
    get_filename_component(CINDER_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE)
    list(APPEND CEREAL_SOURCES
            ${CINDER-CEREAL_PATH}/include/CinderCereal.h
            )
    add_library(Cinder-Cereal
            ${CEREAL_SOURCES})
    target_include_directories(Cinder-Cereal PUBLIC
            ${CINDER-CEREAL_PATH}/lib/cereal/include
            ${CINDER-CEREAL_PATH}/include)

    if (NOT TARGET cinder)
        include("${CINDER_PATH}/proj/cmake/configure.cmake")
        find_package(cinder REQUIRED PATHS
                "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
                "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}")
    endif ()

    target_link_libraries(Cinder-Cereal PRIVATE cinder)
endif ()
