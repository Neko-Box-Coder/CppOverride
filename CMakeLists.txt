cmake_minimum_required(VERSION 3.14)

if(TARGET CppOverride)
    return()
endif()

set (CMAKE_CXX_STANDARD 11)

# For Clang to do parsing
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set the project name
project(CppOverrideProject)

# ==========================================================
# Variables 
# ==========================================================
set(CPP_OVERRIDE_BUILD_EXAMPLE "ON" CACHE BOOL "Build tests for CppOverride")
set(CPP_OVERRIDE_BUILD_TEST "OFF" CACHE BOOL "Build tests for CppOverride")
set(CPP_OVERRIDE_BUILD_TEST_ASAN "OFF" CACHE BOOL "Build tests with asan for CppOverride")
set(CPP_OVERRIDE_USE_SINGLE_HEADER "ON" CACHE BOOL "Use single header version instead")

add_library(CppOverride INTERFACE)

if(CPP_OVERRIDE_USE_SINGLE_HEADER)
    target_include_directories(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/Include_SingleHeader")
else()
    target_include_directories(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/Include_MultiHeaders")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(STANDARD_COMPILE_FLAGS "/utf-8;/W1")
    set(STANDARD_LINK_FLAGS "")
else()
    set(STANDARD_COMPILE_FLAGS  "-Wall"
                                "-Wno-return-local-addr"
                                "-Wno-sign-compare"
                                "-Wno-switch"
                                "-Wno-gnu-zero-variadic-macro-arguments"
                                "-Wextra"
                                "-pedantic"
                                "-Werror")
    set(STANDARD_LINK_FLAGS "")
    
    if(CPP_OVERRIDE_BUILD_TEST_ASAN)
        set (STANDARD_COMPILE_FLAGS "${STANDARD_COMPILE_FLAGS};-fstack-protector-all;-fsanitize=address")
        set(STANDARD_LINK_FLAGS "${STANDARD_LINK_FLAGS};-fsanitize=address")
    endif()
endif()


add_executable(GenerateSingleHeader "${CMAKE_CURRENT_LIST_DIR}/Scripts/GenerateSingleHeader.cpp")
target_compile_options(GenerateSingleHeader PRIVATE "${STANDARD_COMPILE_FLAGS}")

add_executable(GenerateMockClass "${CMAKE_CURRENT_LIST_DIR}/Scripts/GenerateMockClass.cpp")
target_compile_options(GenerateMockClass PRIVATE "${STANDARD_COMPILE_FLAGS}")

if(CPP_OVERRIDE_BUILD_TEST)
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/External/ssTest" "${CMAKE_CURRENT_BINARY_DIR}/ssTest")
    
    add_executable(ModifyReturnsTests "${CMAKE_CURRENT_LIST_DIR}/Tests/ModifyReturnsTests.cpp")
    target_link_libraries(ModifyReturnsTests PUBLIC CppOverride ssTest)
    target_compile_options(ModifyReturnsTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(ModifyReturnsTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(ModifyArgsTests "${CMAKE_CURRENT_LIST_DIR}/Tests/ModifyArgsTests.cpp")
    target_link_libraries(ModifyArgsTests PUBLIC CppOverride ssTest)
    target_compile_options(ModifyArgsTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(ModifyArgsTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(WhenCalledWithTests "${CMAKE_CURRENT_LIST_DIR}/Tests/WhenCalledWithTests.cpp")
    target_link_libraries(WhenCalledWithTests PUBLIC CppOverride ssTest)
    target_compile_options(WhenCalledWithTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(WhenCalledWithTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(TimesTests "${CMAKE_CURRENT_LIST_DIR}/Tests/TimesTests.cpp")
    target_link_libraries(TimesTests PUBLIC CppOverride ssTest)
    target_compile_options(TimesTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(TimesTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(IfTests "${CMAKE_CURRENT_LIST_DIR}/Tests/IfTests.cpp")
    target_link_libraries(IfTests PUBLIC CppOverride ssTest)
    target_compile_options(IfTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(IfTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(Otherwise_DoTests "${CMAKE_CURRENT_LIST_DIR}/Tests/Otherwise_DoTests.cpp")
    target_link_libraries(Otherwise_DoTests PUBLIC CppOverride ssTest)
    target_compile_options(Otherwise_DoTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(Otherwise_DoTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(WhenCalledExpectedly_DoTests "${CMAKE_CURRENT_LIST_DIR}/Tests/WhenCalledExpectedly_DoTests.cpp")
    target_link_libraries(WhenCalledExpectedly_DoTests PUBLIC CppOverride ssTest)
    target_compile_options(WhenCalledExpectedly_DoTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(WhenCalledExpectedly_DoTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(MixedModifyArgsAndReturnsTest "${CMAKE_CURRENT_LIST_DIR}/Tests/MixedModifyArgsAndReturnsTest.cpp")
    target_link_libraries(MixedModifyArgsAndReturnsTest PUBLIC CppOverride ssTest)
    target_compile_options(MixedModifyArgsAndReturnsTest PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(MixedModifyArgsAndReturnsTest PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(MockShapesTests "${CMAKE_CURRENT_LIST_DIR}/Tests/MockShapesTests.cpp")
    target_link_libraries(MockShapesTests PUBLIC CppOverride ssTest)
    target_compile_options(MockShapesTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(MockShapesTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(GlobalInstanceMockShapesTests "${CMAKE_CURRENT_LIST_DIR}/Tests/GlobalInstanceMockShapesTests.cpp")
    target_link_libraries(GlobalInstanceMockShapesTests PUBLIC CppOverride ssTest)
    target_compile_options(GlobalInstanceMockShapesTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(GlobalInstanceMockShapesTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(FreeFunctionTests    "${CMAKE_CURRENT_LIST_DIR}/Tests/FreeFunctionTests.cpp"
                                        "${CMAKE_CURRENT_LIST_DIR}/Tests/Components/FreeFunctions.cpp"
                                        "${CMAKE_CURRENT_LIST_DIR}/Tests/Components/MockFreeFunctions.cpp")
    target_link_libraries(FreeFunctionTests PUBLIC CppOverride ssTest)
    target_compile_options(FreeFunctionTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(FreeFunctionTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    add_executable(ArrayParamTests "${CMAKE_CURRENT_LIST_DIR}/Tests/ArrayParamTests.cpp")
    target_link_libraries(ArrayParamTests PUBLIC CppOverride ssTest)
    target_compile_options(ArrayParamTests PUBLIC "${STANDARD_COMPILE_FLAGS}")
    target_link_options(ArrayParamTests PUBLIC "${STANDARD_LINK_FLAGS}")
    
    if(WIN32)
        execute_process(COMMAND ${CMAKE_COMMAND} -E copy    "${CMAKE_CURRENT_LIST_DIR}/Tests/RunAllTests.bat" 
                                                            "${CMAKE_CURRENT_BINARY_DIR}")
    else()
        file(   CHMOD "${CMAKE_CURRENT_LIST_DIR}/Tests/RunAllTests.sh"
                PERMISSIONS  OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_WRITE GROUP_EXECUTE WORLD_READ WORLD_WRITE WORLD_EXECUTE)
        execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink  "${CMAKE_CURRENT_LIST_DIR}/Tests/RunAllTests.sh" 
                                                                    "${CMAKE_CURRENT_BINARY_DIR}/RunAllTests.sh")
    endif()

endif()

if(CPP_OVERRIDE_BUILD_EXAMPLE)
    add_executable(CppOverrideExample "${CMAKE_CURRENT_LIST_DIR}/Example.cpp")
    target_compile_options(CppOverrideExample PUBLIC ${STANDARD_COMPILE_FLAGS})
    target_link_libraries(CppOverrideExample PUBLIC CppOverride)
    target_link_options(CppOverrideExample PUBLIC "${STANDARD_LINK_FLAGS}")
endif()

