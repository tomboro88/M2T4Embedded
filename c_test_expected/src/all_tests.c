/**
 * @file all_tests.c
 *
 * @brief The entry point for unit tests for c_expected project code.
 */

#include <unity_fixture.h>

void run_all_tests(void)
{
	RUN_TEST_GROUP(fifo);
}

int main(int argc, const char* argv[])
{
	return UnityMain(argc, argv, run_all_tests);
}
