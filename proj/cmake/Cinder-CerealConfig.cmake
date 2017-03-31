if(NOT TARGET Cinder-ImGui)
  get_filename_component( CINDER-CEREAL_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
	get_filename_component( CINDER_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../.." ABSOLUTE )
  include_directories("${CINDER-CEREAL_PATH}/lib/cereal/include"
    "${CINDER-CEREAL_PATH}/include")
endif()
