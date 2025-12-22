/**
 * @file event_pool_test_runner.c
 *
 * @brief A separate file for the event_pool group test runner.
 * @author tomboro88
 * @date   15 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

#include <unity_fixture.h>

TEST_GROUP_RUNNER(event_pool)
{
    RUN_TEST_CASE(event_pool, init_indexes);
    RUN_TEST_CASE(event_pool, init_fail_when_nullptr);
    RUN_TEST_CASE(event_pool, init_fail_when_count_lt_2);
    RUN_TEST_CASE(event_pool, init_fail_when_fifos_uninitialized);
    RUN_TEST_CASE(event_pool, init_fail_when_next_events_nullptr);
    RUN_TEST_CASE(event_pool, init_fail_when_fifos_not_empty);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail1);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail2);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail3);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail4);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail5);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail6);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_init_fail7);
    RUN_TEST_CASE(event_pool, enqueue_ok_after_init);
    RUN_TEST_CASE(event_pool, enqueue_invalid_event_fail);
    RUN_TEST_CASE(event_pool, enqueue_to_nullptr_fail);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_malfunction1);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_malfunction2);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_malfunction3);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_malfunction4);
    RUN_TEST_CASE(event_pool, enqueue_fail_after_malfunction5);
    RUN_TEST_CASE(event_pool, enqueue_null_queues_fail);
    RUN_TEST_CASE(event_pool, enqueue_max_fifo_size);
    RUN_TEST_CASE(event_pool, get_first_fail_after_init);
    RUN_TEST_CASE(event_pool, get_first_event_type_after_enqueue);
    RUN_TEST_CASE(event_pool, get_first_event_fail_on_nullptr);
    RUN_TEST_CASE(event_pool, get_first_fail_on_first_head_nullptr);
    RUN_TEST_CASE(event_pool, get_first_fail_on_next_events_nullptr);
    RUN_TEST_CASE(event_pool, get_first_fail_when_queues_nullptr);
    RUN_TEST_CASE(event_pool, get_first_fail_when_empty_enqueue_fail);
    RUN_TEST_CASE(event_pool, get_first_fail_when_fifo_empty);
    RUN_TEST_CASE(event_pool, dequeue_nullptr_fail);
    RUN_TEST_CASE(event_pool, dequeue_null_queues_fail);
    RUN_TEST_CASE(event_pool, dequeue_null_next_event_fail);
    RUN_TEST_CASE(event_pool, dequeue_pool_empty_fail);
    RUN_TEST_CASE(event_pool, dequeue_fifo_empty_fail);
    RUN_TEST_CASE(event_pool, correct_first_after_dequeue);
    RUN_TEST_CASE(event_pool, enqueue_dequeue_full);
}

/*** end of file ***/
