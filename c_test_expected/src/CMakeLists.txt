add_executable(test_expected)

target_sources(test_expected
    PRIVATE
        all_tests.c
        fifo/fifo_test.c
        fifo/fifo_test_runner.c
)

target_link_libraries(test_expected
    PRIVATE
        unity
        fifo
)
