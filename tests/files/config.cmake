################################################################################
#####
##### Tectiform TFFoundation CMake Configuration File
##### Created by: Steve Wilson
#####
################################################################################

build_and_run_test(
        file_manager_tests
        FileManagerTests
        tests/files/file_manager_tests.cpp
)


build_and_run_test(
        file_handle_tests
        FileHandleTests
        tests/files/file_handle_tests.cpp
)

