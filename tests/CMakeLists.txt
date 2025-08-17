find_package(GTest REQUIRED)
enable_testing()
include(GoogleTest)

file(GLOB IMPL_SOURCE "../src/*.cxx")

file(GLOB HEAP_TESTS CONFIGURE_DEPENDS
  "heap/test_*.cxx"
)
file(GLOB OTHER_TESTS CONFIGURE_DEPENDS
  "test_*.cxx"
)

add_executable(test_my_ds ${IMPL_SOURCE} ${HEAP_TESTS} ${OTHER_TESTS})

target_link_libraries(
    test_my_ds
    GTest::gtest
    GTest::gtest_main
)
