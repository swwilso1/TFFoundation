################################################################################
#####
##### Tectiform TFFoundation CMake Configuration File
##### Created by: Steve Wilson
#####
################################################################################

include(CheckCXXCompilerFlag)

CHECK_CXX_COMPILER_FLAG(-std=c++14 HAS_STDCXX14_FLAG)

if(HAS_STDCXX14_FLAG)
    list(APPEND OSX_COMPILE_FLAGS -std=c++14)
else()
    list(APPEND OSX_COMPILE_FLAGS -std=c++11)
endif()

set(FOUNDATION_FRAMEWORK_LIBRARY_NAME ${FOUNDATION_LIBRARY_NAME}-framework CACHE STRING
    "Name of framework library target")

set(FOUNDATION_SHARED_LIBRARY_NAME ${FOUNDATION_LIBRARY_NAME}-shared CACHE STRING
    "Name of shared library target")

set(FOUNDATION_STATIC_LIBRARY_NAME ${FOUNDATION_LIBRARY_NAME}-static CACHE STRING
    "Name of static library target")

set(FOUNDATION_FRAMEWORK_INSTALL_DIR "${FOUNDATION_LIBRARY_INSTALL_DIR}" CACHE STRING
    "Framework object install directory.")

mark_as_advanced(
    FOUNDATION_FRAMEWORK_LIBRARY_NAME
    FOUNDATION_SHARED_LIBARY_NAME
    FOUNDATION_STATIC_LIBRARY_NAME
    FOUNDATION_FRAMEWORK_INSTALL_DIR
)

list(APPEND OSX_COMPILE_FLAGS -stdlib=libc++)

# set(FOUNDATION_FRAMEWORK_LIBRARY_COMPILE_DEFINITIONS )
set(FOUNDATION_FRAMEWORK_LIBRARY_COMPILE_FLAGS ${OSX_COMPILE_FLAGS})
# set(FOUNDATION_FRAMEWORK_LIBRARY_LINK_FLAGS )
# set(FOUNDATION_FRAMEWORK_LIBRARY_LIBRARIES )

# set(FOUNDATION_SHARED_LIBRARY_PLATFORM_COMPILE_DEFINITIONS )
set(FOUNDATION_SHARED_LIBRARY_PLATFORM_COMPILE_FLAGS ${OSX_COMPILE_FLAGS})
# set(FOUNDATION_SHARED_LIBRARY_PLATFORM_LINK_FLAGS )
# set(FOUNDATION_SHARED_LIBRARY_PLATFORM_LIBRARIES )

# set(FOUNDATION_STATIC_LIBRARY_PLATFORM_COMPILE_DEFINITIONS )
set(FOUNDATION_STATIC_LIBRARY_PLATFORM_COMPILE_FLAGS ${OSX_COMPILE_FLAGS})
# set(FOUNDATION_STATIC_LIBRARY_PLATFORM_LINK_FLAGS )
# set(FOUNDATION_STATIC_LIBRARY_PLATFORM_LIBRARIES )


# set(TEST_PLATFORM_COMPILE_DEFINITIONS)
set(TEST_PLATFORM_COMPILE_FLAGS ${OSX_COMPILE_FLAGS})
# set(TEST_PLATFORM_LINK_FLAGS )
set(TEST_PLATFORM_LIBRARIES gtest gtest_main)
