/**
 * @file fifo_test_runner.c
 *
 * @brief A separate file for the fifo group test runner.
 * @author tomboro88
 * @date   2 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

#include <unity_fixture.h>

TEST_GROUP_RUNNER(fifo)
{
    RUN_TEST_CASE(fifo, init);
    RUN_TEST_CASE(fifo, empty_after_init);
    RUN_TEST_CASE(fifo, not_full_after_init);
    RUN_TEST_CASE(fifo, full_on_nullptr);
    RUN_TEST_CASE(fifo, empty_on_nullptr);
    RUN_TEST_CASE(fifo, deq_fail_after_init);
    RUN_TEST_CASE(fifo, deq_fail_on_nullptr);
    RUN_TEST_CASE(fifo, correct_size_on_init);
    RUN_TEST_CASE(fifo, size_check_fail1);
    RUN_TEST_CASE(fifo, size_check_fail2);
    RUN_TEST_CASE(fifo, size_check_fail3);
    RUN_TEST_CASE(fifo, size_check_fail4);
    RUN_TEST_CASE(fifo, false_on_enqueue_null);
    RUN_TEST_CASE(fifo, true_on_enqueue_ok);
    RUN_TEST_CASE(fifo, not_empty_after_enqueue);
    RUN_TEST_CASE(fifo, full_after_enqueue_all);
    RUN_TEST_CASE(fifo, enqueue_increments_tail);
    RUN_TEST_CASE(fifo, true_on_dequeue_ok);
    RUN_TEST_CASE(fifo, dequeue_ok_when_not_empty);
    RUN_TEST_CASE(fifo, dequeue_increments_head);
    RUN_TEST_CASE(fifo, check_size_always_ok);
    RUN_TEST_CASE(fifo, correct_data_in_buffer);
}

