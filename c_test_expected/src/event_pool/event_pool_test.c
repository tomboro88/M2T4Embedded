/**
 * @file event_pool_test.c
 *
 * @brief Source code of the event_pool test group.
 * @details Performs tests of the event_pool module.
 * @author tomboro88
 * @date   15 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

#include <unity_fixture.h>
#include <event_pool.h>

/**
 * @brief The enumeration of fictional event types handled by the test.
 */
typedef enum
{
    /**
     * @brief an event with int argument.
     */
    CONCEPT_EVENT_INT,
    /**
     * @brief an event with char argument.
     */
    CONCEPT_EVENT_CHAR,
    /**
     * @brief an event with double argument.
     */
    CONCEPT_EVENT_DOUBLE,
    /**
     * @brief an event with c-string argument.
     */
    CONCEPT_EVENT_STRING,
    /**
     * @brief The number of all events handled by concept Class.
     */
    CONCEPT_EVENT_COUNT
}concept_evtype_t;

#define CONCEPT_EVENT_INT_COUNT 2
#define CONCEPT_EVENT_CHAR_COUNT 5
#define CONCEPT_EVENT_DOUBLE_COUNT 4
#define CONCEPT_EVENT_STRING_COUNT 3

TEST_GROUP(event_pool);

static event_pool_t      event_pool = {0};

static event_pool_fifo_t fifo_pool[CONCEPT_EVENT_COUNT];

static event_pool_size_t int_next_events[CONCEPT_EVENT_INT_COUNT];
static event_pool_size_t char_next_events[CONCEPT_EVENT_CHAR_COUNT];
static event_pool_size_t double_next_events[CONCEPT_EVENT_DOUBLE_COUNT];
static event_pool_size_t string_next_events[CONCEPT_EVENT_STRING_COUNT];


static event_pool_t      event_pool_copied = {0};

static event_pool_fifo_t fifo_pool_copied[CONCEPT_EVENT_COUNT];

static event_pool_size_t int_next_events_copied[CONCEPT_EVENT_INT_COUNT];
static event_pool_size_t char_next_events_copied[CONCEPT_EVENT_CHAR_COUNT];
static event_pool_size_t double_next_events_copied[CONCEPT_EVENT_DOUBLE_COUNT];
static event_pool_size_t string_next_events_copied[CONCEPT_EVENT_STRING_COUNT];


static event_pool_size_t* const next_event_pools[CONCEPT_EVENT_COUNT] =
        {
                int_next_events,
                char_next_events,
                double_next_events,
                string_next_events
        };

static const fifo_size_t    concept_fifo_sizes[CONCEPT_EVENT_COUNT] =
        {
                CONCEPT_EVENT_INT_COUNT,
                CONCEPT_EVENT_CHAR_COUNT,
                CONCEPT_EVENT_DOUBLE_COUNT,
                CONCEPT_EVENT_STRING_COUNT
        };

/*======================================TESTS=================================*/

static void
event_pool_test_init(void)
{
    event_pool = (event_pool_t) {0};

    for(event_pool_size_t i = 0u; i < CONCEPT_EVENT_COUNT; ++i)
    {
        fifo_initialize((&fifo_pool[i].fifo), concept_fifo_sizes[i], 0u, 0u);
        fifo_pool[i].p_next_events = next_event_pools[i];
    }

    (void) event_pool_initialize(&event_pool, fifo_pool, concept_fifo_sizes,
                                                           CONCEPT_EVENT_COUNT);
}

static void
event_pool_copy(void)
{
    event_pool_copied = event_pool;

    for(event_pool_size_t i = 0u; i < CONCEPT_EVENT_COUNT; ++i)
    {
        fifo_pool_copied[i] = fifo_pool[i];
    }

    for(fifo_size_t i = 0u; i < CONCEPT_EVENT_INT_COUNT; ++i)
    {
        int_next_events_copied[i] = int_next_events[i];
    }

    for(fifo_size_t i = 0u; i < CONCEPT_EVENT_CHAR_COUNT; ++i)
    {
        char_next_events_copied[i] = char_next_events[i];
    }

    for(fifo_size_t i = 0u; i < CONCEPT_EVENT_DOUBLE_COUNT; ++i)
    {
        double_next_events_copied[i] = double_next_events[i];
    }

    for(fifo_size_t i = 0u; i < CONCEPT_EVENT_STRING_COUNT; ++i)
    {
        string_next_events_copied[i] = string_next_events[i];
    }
}

static void
event_pool_assert_equal_copy(void)
{
    TEST_ASSERT_EQUAL_MEMORY(&event_pool_copied, &event_pool,
                                                            sizeof(event_pool));

    TEST_ASSERT_EQUAL_MEMORY_ARRAY(fifo_pool_copied, fifo_pool,
                                     sizeof(fifo_pool[0]), CONCEPT_EVENT_COUNT);

    TEST_ASSERT_EQUAL_MEMORY_ARRAY(int_next_events_copied, int_next_events,
                                   sizeof(int_next_events[0]),
                                   CONCEPT_EVENT_INT_COUNT);

    TEST_ASSERT_EQUAL_MEMORY_ARRAY(char_next_events_copied, char_next_events,
                                   sizeof(char_next_events[0]),
                                   CONCEPT_EVENT_CHAR_COUNT);

    TEST_ASSERT_EQUAL_MEMORY_ARRAY(double_next_events_copied,
                                   double_next_events,
                                   sizeof(double_next_events[0]),
                                   CONCEPT_EVENT_DOUBLE_COUNT);

    TEST_ASSERT_EQUAL_MEMORY_ARRAY(string_next_events_copied,
                                   string_next_events,
                                   sizeof(string_next_events[0]),
                                   CONCEPT_EVENT_STRING_COUNT);
}

static void
event_pool_test_enqueue_fail(void)
{
    event_pool_copy();

    /*Failed enqueue mustn't change the contents of the event pool.*/
    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_INT));
    event_pool_assert_equal_copy();

    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_CHAR));
    event_pool_assert_equal_copy();

    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_DOUBLE));
    event_pool_assert_equal_copy();

    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_STRING));
    event_pool_assert_equal_copy();
}

static void
event_pool_test_enqueue_event_fail(event_pool_size_t  const event_type)
{
    event_pool_copy();
    /*Failed enqueue musn't change the contents of the event pool.*/
    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, event_type));
    event_pool_assert_equal_copy();
}

static void
event_pool_test_enqueue_fail_after_init_fail(void)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   CONCEPT_EVENT_COUNT
                                                   ));

    event_pool_test_enqueue_fail();
}

static void
event_pool_test_dequeue_fail(void)
{
    event_pool_copy();

    /*Failed dequeue mustn't change the contents of the event pool.*/
    TEST_ASSERT_FALSE(event_pool_dequeue(&event_pool));
    event_pool_assert_equal_copy();
}

/**
 * @brief Checks if the event_pool_get_first_head() function fails.
 * @param p_obj The event_pool_t object that should be tested.
 */
static void
event_pool_test_assert_first_fail(const event_pool_t* const p_obj)
{
    /* Initialize the object where the first event location should be stored
     * if found any.*/
    event_pool_locator_t locator = {.event_type = CONCEPT_EVENT_COUNT,
                                    .event_index = (~((fifo_size_t) 0u))};
    event_pool_locator_t locator_copied = locator;

    /*
     * Execute the test.
     */
    TEST_ASSERT_FALSE(event_pool_get_first_head(p_obj, &locator));

    TEST_ASSERT_EQUAL_MEMORY(&locator_copied, &locator, sizeof(locator));
}

static void
event_pool_test_assert_first(event_pool_size_t const expected_type,
                             fifo_size_t const expected_index)
{
    event_pool_locator_t locator = {.event_type = CONCEPT_EVENT_COUNT,
                                    .event_index = (~((fifo_size_t) 0u))};

    TEST_ASSERT_TRUE(event_pool_get_first_head(&event_pool, &locator));

    TEST_ASSERT_EQUAL_size_t(expected_type, locator.event_type);
    TEST_ASSERT_EQUAL_size_t(expected_index, locator.event_index);
}

TEST_SETUP(event_pool)
{
    event_pool_test_init();
}

TEST_TEAR_DOWN(event_pool)
{

}

TEST(event_pool, init_indexes)
{
    TEST_ASSERT_TRUE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   CONCEPT_EVENT_COUNT
                                                   ));
}

TEST(event_pool, init_fail_when_nullptr)
{
    TEST_ASSERT_FALSE(event_pool_initialize(NULL,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   CONCEPT_EVENT_COUNT
                                                   ));
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   NULL,
                                                   concept_fifo_sizes,
                                                   CONCEPT_EVENT_COUNT
                                                   ));
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   NULL,
                                                   CONCEPT_EVENT_COUNT
                                                   ));
}

TEST(event_pool, init_fail_when_count_lt_2)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   0u
                                                   ));

    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   1u
                                                   ));
}

TEST(event_pool, init_fail_when_fifos_uninitialized)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        fifo_pool[i].fifo = (fifo_t){0};
        TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                       fifo_pool,
                                                       concept_fifo_sizes,
                                                       CONCEPT_EVENT_COUNT
                                                       ));
    }
}

TEST(event_pool, init_fail_when_next_events_nullptr)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        fifo_pool[i].p_next_events = NULL;
        TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                       fifo_pool,
                                                       concept_fifo_sizes,
                                                       CONCEPT_EVENT_COUNT
                                                       ));
    }
}

TEST(event_pool, init_fail_when_fifos_not_empty)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        fifo_enqueue(&fifo_pool[i].fifo);
        TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                       fifo_pool,
                                                       concept_fifo_sizes,
                                                       CONCEPT_EVENT_COUNT
                                                       ));
    }
}

TEST(event_pool, enqueue_fail_after_init_fail1)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   NULL,
                                                   concept_fifo_sizes,
                                                   CONCEPT_EVENT_COUNT
                                                   ));
    event_pool_test_enqueue_fail();
}

TEST(event_pool, enqueue_fail_after_init_fail2)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   NULL,
                                                   CONCEPT_EVENT_COUNT
                                                       ));
    event_pool_test_enqueue_fail();
}

TEST(event_pool, enqueue_fail_after_init_fail3)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   0u
                                                   ));
    event_pool_test_enqueue_fail();
}

TEST(event_pool, enqueue_fail_after_init_fail4)
{
    TEST_ASSERT_FALSE(event_pool_initialize(&event_pool,
                                                   fifo_pool,
                                                   concept_fifo_sizes,
                                                   1u
                                                   ));
    event_pool_test_enqueue_fail();
}

TEST(event_pool, enqueue_fail_after_init_fail5)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        fifo_pool[i].fifo = (fifo_t){0};
        event_pool_test_enqueue_fail_after_init_fail();
    }
}

TEST(event_pool, enqueue_fail_after_init_fail6)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        fifo_pool[i].p_next_events = NULL;
        event_pool_test_enqueue_fail_after_init_fail();
    }
}

TEST(event_pool, enqueue_fail_after_init_fail7)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        TEST_ASSERT_TRUE(fifo_enqueue(&fifo_pool[i].fifo));
        //init will fail because fifo_pool[i].fifo is not empty
        event_pool_test_enqueue_fail_after_init_fail();
    }
}

TEST(event_pool, enqueue_ok_after_init)
{
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_INT));
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_CHAR));
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_DOUBLE));
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_STRING));
}

TEST(event_pool, enqueue_invalid_event_fail)
{
    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, CONCEPT_EVENT_COUNT));
}

TEST(event_pool, enqueue_to_nullptr_fail)
{
    TEST_ASSERT_FALSE(event_pool_enqueue(NULL, CONCEPT_EVENT_INT));
}

/*This test was added because it was noticed that in the very initial version
 * these conditions could cause enqueue command overwrite the event_pool, even
 * if it returned the false value. It will stay here to keep the code correct.*/
TEST(event_pool, enqueue_fail_after_malfunction1)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
        //the last event type is now not empty try to damage the last queue
        ++fifo_pool[i].fifo.head;
        event_pool_test_enqueue_fail();
    }
}

/*This test was added because it was noticed that in the very initial version
 * these conditions could cause enqueue command overwrite the event_pool, even
 * if it returned the false value. It will stay here to keep the code correct.*/
TEST(event_pool, enqueue_fail_after_malfunction2)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
        //the last event type is now not empty try to damage the last queue
        fifo_pool[i].p_next_events = NULL;
        event_pool_test_enqueue_fail();
    }
}

TEST(event_pool, enqueue_fail_after_malfunction3)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        /* Let's simulate malfunction by setting first<fifo_count without
         * calling enqueue.*/
        event_pool.first = i;
        event_pool_test_enqueue_fail();
    }
}

TEST(event_pool, enqueue_fail_after_malfunction4)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        /* Let's simulate malfunction by setting last < fifo_count without
         * calling enqueue. */
        event_pool.last = i;
        event_pool_test_enqueue_fail();
    }
}

TEST(event_pool, enqueue_fail_after_malfunction5)
{
    for(event_pool_size_t i = 0; i < CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        /* Let's simulate malfunction by setting p_next_events pointer
         * for the new event to NULL. The pointers for other events
         * need not to be altered since they don't need to be checked by the
         * enqueue function, because they don't take part in the enqueue
         * process.*/
        event_pool.p_queues[i].p_next_events = NULL;
        event_pool_test_enqueue_event_fail(i);
    }
}

TEST(event_pool, enqueue_null_queues_fail)
{
    event_pool.p_queues = NULL;
    event_pool_test_enqueue_fail();
}

TEST(event_pool, enqueue_max_fifo_size)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        for(fifo_size_t j = 0; j<concept_fifo_sizes[i]; ++j)
        {
            TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
        }

        event_pool_test_enqueue_event_fail(i);
    }
}

TEST(event_pool, get_first_fail_after_init)
{
    event_pool_test_assert_first_fail(&event_pool);
}

TEST(event_pool, get_first_event_type_after_enqueue)
{
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_INT);
    event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);

    event_pool_enqueue(&event_pool, CONCEPT_EVENT_CHAR);
    event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);

    event_pool_enqueue(&event_pool, CONCEPT_EVENT_DOUBLE);
    event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);

    event_pool_enqueue(&event_pool, CONCEPT_EVENT_STRING);
    event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);
}

TEST(event_pool, get_first_event_fail_on_nullptr)
{
    event_pool_test_assert_first_fail(NULL);
}

TEST(event_pool, get_first_fail_on_first_head_nullptr)
{
    TEST_ASSERT_FALSE(event_pool_get_first_head(&event_pool, NULL));
}

TEST(event_pool, get_first_fail_on_next_events_nullptr)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        event_pool_enqueue(&event_pool, i);
        event_pool.p_queues[i].p_next_events = NULL;
        event_pool_test_assert_first_fail(&event_pool);
    }
}

TEST(event_pool, get_first_fail_when_queues_nullptr)
{
    event_pool.p_queues = NULL;
    event_pool_test_assert_first_fail(&event_pool);
}

TEST(event_pool, get_first_fail_when_empty_enqueue_fail)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        /*Force some inconsistent data in fifo object.*/
        ++fifo_pool[i].fifo.head;
        event_pool_test_enqueue_event_fail(i);
        event_pool_test_assert_first_fail(&event_pool);
    }
}

TEST(event_pool, get_first_fail_when_fifo_empty)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        event_pool_enqueue(&event_pool, i);
        //make the corresponding fifo empty bypassing event_pool interface
        fifo_dequeue(&event_pool.p_queues[i].fifo);
        event_pool_test_assert_first_fail(&event_pool);
    }
}

TEST(event_pool, dequeue_nullptr_fail)
{
    TEST_ASSERT_FALSE(event_pool_dequeue(NULL));
}

TEST(event_pool, dequeue_null_queues_fail)
{
    event_pool.p_queues = NULL;
    event_pool_test_dequeue_fail();
}

TEST(event_pool, dequeue_null_next_event_fail)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
        fifo_pool[i].p_next_events = NULL;
        event_pool_test_dequeue_fail();
    }
}

TEST(event_pool, dequeue_pool_empty_fail)
{
    event_pool_test_dequeue_fail();
}

TEST(event_pool, dequeue_fifo_empty_fail)
{
    for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
    {
        event_pool_test_init();
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
        // Dequeue the specific fifo bypassing the event_pool interface.
        TEST_ASSERT_TRUE(fifo_dequeue(&fifo_pool[i].fifo));
        event_pool_test_dequeue_fail();
    }
}

TEST(event_pool, correct_first_after_dequeue)
{
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_CHAR);
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_STRING);
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_INT);
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_COUNT);
    event_pool_enqueue(&event_pool, CONCEPT_EVENT_DOUBLE);

    event_pool_test_assert_first(CONCEPT_EVENT_CHAR, 0u);

    event_pool_dequeue(&event_pool);
    event_pool_test_assert_first(CONCEPT_EVENT_STRING, 0u);

    event_pool_dequeue(&event_pool);
    event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);

    event_pool_dequeue(&event_pool);
    event_pool_test_assert_first(CONCEPT_EVENT_DOUBLE, 0u);

    event_pool_dequeue(&event_pool);
    event_pool_test_assert_first_fail(&event_pool);

    event_pool_dequeue(&event_pool);
    event_pool_test_assert_first_fail(&event_pool);
}

TEST(event_pool, enqueue_dequeue_full)
{
    for(int k = 0; k<10; ++k)
    {
        for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
        {
            for(fifo_size_t j = 0; j<concept_fifo_sizes[i]; ++j)
            {
                TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
                event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);
            }

            event_pool_test_enqueue_event_fail(i);
            event_pool_test_assert_first(CONCEPT_EVENT_INT, 0u);
        }

        for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
        {
            for(fifo_size_t j = 0; j<concept_fifo_sizes[i]; ++j)
            {
                event_pool_test_assert_first(i, j);
                TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
                TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, i));
            }
        }


        for(event_pool_size_t i = 0; i<CONCEPT_EVENT_COUNT; ++i)
        {
            for(fifo_size_t j = 0; j<concept_fifo_sizes[i]; ++j)
            {
                event_pool_test_assert_first(i, j);
                TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
            }
        }

        event_pool_test_assert_first_fail(&event_pool);
        event_pool_test_dequeue_fail();
    }
}

/*** end of file ***/
