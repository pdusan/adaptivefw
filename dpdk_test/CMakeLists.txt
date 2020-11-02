cmake_minimum_required (VERSION 3.10)
project(dpdk-test)

include(dpdk.cmake)

add_executable(dpdk_test dpdk_test.c)
target_compile_options(dpdk_test PUBLIC ${DPDK_CFLAGS_OTHER})
target_include_directories(dpdk_test PUBLIC ${DPDK_INCLUDE_DIRS})
target_link_libraries(dpdk_test ${DPDK_LIBRARIES})
target_link_libraries(dpdk_test pthread dl rt m numa)