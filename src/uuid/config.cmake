################################################################################
#####
##### Tectiform TFFoundation CMake Configuration File
##### Created by: Steve Wilson
#####
################################################################################

list(APPEND FOUNDATION_HEADER_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/uuid/tfuuid.hpp"
        )

if(UNIX)
    include(src/uuid/unix/config.cmake)
endif()

