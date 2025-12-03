add_library(fifo)

target_sources(fifo
    PRIVATE
        fifo.c
    PUBLIC
        FILE_SET fifo_headers
    TYPE HEADERS
    FILES
        fifo.h
)