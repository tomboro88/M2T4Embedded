add_library(unity)
target_sources(unity
    PRIVATE
        extras/fixture/src/unity_fixture.c
        src/unity.c
    PUBLIC
        FILE_SET unity_headers
        TYPE HEADERS
        BASE_DIRS
            extras/fixture/src
            src
        FILES
            extras/fixture/src/unity_fixture_internals.h
            extras/fixture/src/unity_fixture.h
            src/unity_internals.h
            src/unity.h
)

target_compile_definitions(unity PUBLIC UNITY_FIXTURE_NO_EXTRAS)