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
set(CPP_OVERRIDE_USE_SINGLE_HEADER "ON" CACHE BOOL "Use single header version instead")


add_library(CppOverride INTERFACE)

if(CPP_OVERRIDE_USE_SINGLE_HEADER)
    target_include_directories(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/Include_SingleHeader")
    #target_sources(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/CppOverride.hpp")
else()
    target_include_directories(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/Include_MultiHeaders")
    #target_sources(CppOverride INTERFACE "${CMAKE_CURRENT_LIST_DIR}/Include/CppOverride.hpp")
endif()

if(CPP_OVERRIDE_BUILD_TEST)
    if(NOT TARGET ssTest)
        add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/External/ssTest" "${CMAKE_CURRENT_BINARY_DIR}/ssTest")
    endif()
    
    #add_executable(CppOverrideTest "${CMAKE_CURRENT_LIST_DIR}/Tests/CppOverrideTests.cpp")
    add_executable(ModifyReturnsTests "${CMAKE_CURRENT_LIST_DIR}/Tests/ModifyReturnsTests.cpp")
    target_link_libraries(ModifyReturnsTests PUBLIC CppOverride ssTest)
    
    add_executable(ModifyArgsTests "${CMAKE_CURRENT_LIST_DIR}/Tests/ModifyArgsTests.cpp")
    target_link_libraries(ModifyArgsTests PUBLIC CppOverride ssTest)
    
    add_executable(WhenCalledWithTests "${CMAKE_CURRENT_LIST_DIR}/Tests/WhenCalledWithTests.cpp")
    target_link_libraries(WhenCalledWithTests PUBLIC CppOverride ssTest)
    
    add_executable(TimesTests "${CMAKE_CURRENT_LIST_DIR}/Tests/TimesTests.cpp")
    target_link_libraries(TimesTests PUBLIC CppOverride ssTest)
    
    add_executable(IfTests "${CMAKE_CURRENT_LIST_DIR}/Tests/IfTests.cpp")
    target_link_libraries(IfTests PUBLIC CppOverride ssTest)
    
    add_executable(Otherwise_DoTests "${CMAKE_CURRENT_LIST_DIR}/Tests/Otherwise_DoTests.cpp")
    target_link_libraries(Otherwise_DoTests PUBLIC CppOverride ssTest)
    
    add_executable(WhenCalledExpectedly_DoTests "${CMAKE_CURRENT_LIST_DIR}/Tests/WhenCalledExpectedly_DoTests.cpp")
    target_link_libraries(WhenCalledExpectedly_DoTests PUBLIC CppOverride ssTest)

endif()

if(CPP_OVERRIDE_BUILD_EXAMPLE)
    #add_executable(CppOverrideExample "${CMAKE_CURRENT_LIST_DIR}/Example.cpp")
    #target_link_libraries(CppOverrideExample PUBLIC CppOverride)
endif()

