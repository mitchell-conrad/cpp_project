add_executable(run_tests tests.cpp)
target_compile_features(run_tests PRIVATE cxx_std_17)
target_link_libraries(run_tests
        PRIVATE
        project_library
        Catch2::Catch2
        )

add_test(NAME tests COMMAND run_tests)
