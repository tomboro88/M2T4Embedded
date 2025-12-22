add_library(event_pool)

target_sources(event_pool
    PRIVATE
        event_pool.c
    PUBLIC
        FILE_SET event_pool_headers
    TYPE HEADERS
    FILES
        event_pool.h
)

target_link_libraries(event_pool
    PUBLIC
        fifo
)

target_compile_options(event_pool PRIVATE
    $<$<CONFIG:Coverage>:
        -O0
        -g
        -fprofile-arcs
        -ftest-coverage
    >
)

target_link_options(event_pool PRIVATE
    $<$<CONFIG:Coverage>:
        -fprofile-arcs
        -ftest-coverage
    >
)
