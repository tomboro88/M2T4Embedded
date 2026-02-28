/**
 * @file fifo_test.c
 *
 * @brief Source code of the fifo test group.
 * @details Performs tests of the fifo module.
 * @author tomboro88
 * @date   2 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

#include <unity_fixture.h>
#include <fifo.h>

#define FIFO_TEST_BUFFER_SIZE 10u

/**
 * @brief The maximum fifo size corresponding to the selected fifo_size_t
 * type.
 */
#define FIFO_TEST_MAX_SIZE (~((fifo_size_t) 0u))

TEST_GROUP(fifo);

static fifo_t fifo_obj =
    { };

static fifo_t fifo_obj_copied =
    { };

static void
fifo_assert_equal_copy(void)
{
    TEST_ASSERT_EQUAL_MEMORY(&fifo_obj_copied, &fifo_obj, sizeof(fifo_obj));
}

static void
fifo_test_copy(void)
{
    fifo_obj_copied = fifo_obj;
}

static void
fifo_test_dequeue_fail(void)
{
    fifo_test_copy();

    /*Failed dequeue mustn't change the contents of the fifo.*/
    TEST_ASSERT_FALSE(fifo_dequeue(&fifo_obj));
    fifo_assert_equal_copy();
}

static void
fifo_test_enqueue_fail(void)
{
    fifo_test_copy();

    /*Failed enqueue mustn't change the contents of the fifo.*/
    TEST_ASSERT_FALSE(fifo_enqueue(&fifo_obj));
    fifo_assert_equal_copy();
}

TEST_SETUP(fifo)
{
    (void) fifo_initialize(&fifo_obj, FIFO_TEST_BUFFER_SIZE, 0u, 0u);
}

TEST_TEAR_DOWN(fifo)
{

}

TEST(fifo, calc_returns_size_when_size_0)
{
    const fifo_size_t size  = 0u;
    const fifo_size_t head  = 0u;
    const fifo_size_t count = 0u;

    TEST_ASSERT_EQUAL_size_t(size,fifo_calc_tail(size, head, count));
}

TEST(fifo, calc_returns_size_when_size_1)
{
    const fifo_size_t size  = 1u;
    const fifo_size_t head  = 0u;
    const fifo_size_t count = 0u;

    TEST_ASSERT_EQUAL_size_t(size,fifo_calc_tail(size, head, count));
}

TEST(fifo, calc_returns_size_when_head_eq_size)
{
    const fifo_size_t size  = 2u;
    const fifo_size_t head  = 2u;

    for(fifo_size_t count = 0; count < size; ++count)
    {
        TEST_ASSERT_EQUAL_size_t(size, fifo_calc_tail(size, head, count));
    }
}

TEST(fifo, calc_returns_size_when_head_gt_size)
{
    const fifo_size_t size  = 2u;
    const fifo_size_t head  = 3u;

    for(fifo_size_t count = 0u; count < size; ++count)
    {
        TEST_ASSERT_EQUAL_size_t(size, fifo_calc_tail(size, head, count));
    }
}

TEST(fifo, calc_returns_size_when_count_gt_size)
{
    const fifo_size_t size   = 2u;
    const fifo_size_t head   = 0u;
    const fifo_size_t count  = 2u+1u;

    TEST_ASSERT_EQUAL_size_t(size,fifo_calc_tail(size, head, count));
}

TEST(fifo, calc_s_minus_c_gt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 5u;
    const fifo_size_t tail  = FIFO_TEST_MAX_SIZE-1u;

    TEST_ASSERT_TRUE((size-count) > head);

    TEST_ASSERT_EQUAL_size_t(tail, fifo_calc_tail(size, head, count));
}

TEST(fifo, calc_s_minus_c_eq_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-5u;
    const fifo_size_t count = 5u;
    const fifo_size_t tail  = 0u;

    TEST_ASSERT_TRUE((size-count) == head);

    TEST_ASSERT_EQUAL_size_t(tail, fifo_calc_tail(size, head, count));
}

TEST(fifo, calc_s_minus_c_lt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-5u;
    const fifo_size_t count = 6u;
    const fifo_size_t tail  = 1u;

    TEST_ASSERT_TRUE((size-count) < head);

    TEST_ASSERT_EQUAL_size_t(tail, fifo_calc_tail(size, head, count));
}

TEST(fifo, init_fails_when_nullptr)
{
    TEST_ASSERT_FALSE(fifo_initialize(NULL, FIFO_TEST_BUFFER_SIZE, 0u, 0u));
}

static void
fifo_test_init_pass(fifo_size_t const size, fifo_size_t const head,
                    fifo_size_t const count, fifo_size_t const tail)
{
    /*Run the initialization function, the fifo_obj should be overwritten.*/
    TEST_ASSERT_TRUE(fifo_initialize(&fifo_obj, size, head, count));
    /*Verify results.*/
    TEST_ASSERT_EQUAL_size_t(size,  fifo_obj.size);
    TEST_ASSERT_EQUAL_size_t(head,  fifo_obj.head);
    TEST_ASSERT_EQUAL_size_t(count, fifo_obj.count);
    TEST_ASSERT_EQUAL_size_t(tail,  fifo_obj.tail);
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, size));
    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
}

TEST(fifo, init_s_minus_c_gt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 5u;
    const fifo_size_t tail  = FIFO_TEST_MAX_SIZE-1u;

    TEST_ASSERT_TRUE((size-count) > head);

    fifo_test_init_pass(size, head, count, tail);
}

TEST(fifo, init_s_minus_c_lt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-3u;
    const fifo_size_t count = 5u;
    const fifo_size_t tail  = 2u;

    TEST_ASSERT_TRUE((size-count) < head);

    fifo_test_init_pass(size, head, count, tail);
}

TEST(fifo, init_s_minus_c_eq_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-3u;
    const fifo_size_t count = 3u;
    const fifo_size_t tail  = 0u;

    TEST_ASSERT_TRUE((size-count) == head);

    fifo_test_init_pass(size, head, count, tail);
}

static void
fifo_test_init_fail(fifo_size_t const size, fifo_size_t const head,
                    fifo_size_t const count)
{
    /*Check if fifo_obj is properly initialized by the TEST_SETUP*/
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    /*Run the initialization function, the fifo_obj should be overwritten.*/
    TEST_ASSERT_FALSE(fifo_initialize(&fifo_obj, size, head, count));
    /* Verify results. If the initialization fails, we don't want the fifo_obj
     * contain old data when it's valid, because it may lead to potential use of
     * some old data, while the program thinks it has a correct fifo object.
     * fifo_obj initialized with the invalid arguments should lead to blocking
     * the operation of the corresponding state machine.*/
    TEST_ASSERT_EQUAL_size_t(size,  fifo_obj.size);
    TEST_ASSERT_EQUAL_size_t(head,  fifo_obj.head);
    TEST_ASSERT_EQUAL_size_t(count, fifo_obj.count);
    TEST_ASSERT_EQUAL_size_t(size,  fifo_obj.tail);
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, size));
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_is_not_full(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_is_not_empty(&fifo_obj));
    fifo_test_enqueue_fail();
    fifo_test_dequeue_fail();
}

TEST(fifo, init_fail_head_eq_size)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t count = 0u;

    fifo_test_init_fail(size, head, count);
}

TEST(fifo, init_fail_head_gt_size)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE-1u;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t count = 0u;

    fifo_test_init_fail(size, head, count);
}

TEST(fifo, init_fail_count_gt_size)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE-1u;
    const fifo_size_t head  = 0u;
    const fifo_size_t count = FIFO_TEST_MAX_SIZE;

    fifo_test_init_fail(size, head, count);
}

TEST(fifo, init_fail_if_size_1)
{
    const fifo_size_t size  = 1u;
    const fifo_size_t head  = 0u;
    const fifo_size_t count = 0u;

    fifo_test_init_fail(size, head, count);
}

TEST(fifo, init_fail_if_size_0)
{
    const fifo_size_t size  = 0u;
    const fifo_size_t head  = 0u;
    const fifo_size_t count = 0u;

    fifo_test_init_fail(size, head, count);
}

TEST(fifo, check_pass_after_init)
{
    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_when_nullptr)
{
    TEST_ASSERT_FALSE(fifo_check(NULL));
    TEST_ASSERT_FALSE(fifo_check_with_size(NULL, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_tail_eq_size)
{
    fifo_obj.tail = fifo_obj.size;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_tail_gt_size)
{
    fifo_obj.tail = fifo_obj.size+1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_size_0)
{
    fifo_obj.size = 0u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_size_1)
{
    fifo_obj.size = 1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_head_eq_size)
{
    fifo_obj.head = fifo_obj.size;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_head_gt_size)
{
    fifo_obj.head = fifo_obj.size+1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_fail_count_gt_size)
{
    fifo_obj.count = fifo_obj.size+1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_pass_count_eq_size)
{
    fifo_obj.count = fifo_obj.size;
    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_pass_count_lt_size)
{
    fifo_obj.count = fifo_obj.size-1u;
    fifo_obj.tail = fifo_obj.size-1u;
    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_pass_s_minus_c_gt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 5u;

    TEST_ASSERT_TRUE((size-count) > head);

    (void) fifo_initialize(&fifo_obj, size, head, count);

    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_MAX_SIZE));
}

TEST(fifo, check_pass_s_minus_c_eq_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 6u;

    TEST_ASSERT_TRUE((size-count) == head);

    (void) fifo_initialize(&fifo_obj, size, head, count);

    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_MAX_SIZE));
}

TEST(fifo, check_pass_s_minus_c_lt_head)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 7u;

    TEST_ASSERT_TRUE((size-count) < head);

    (void) fifo_initialize(&fifo_obj, size, head, count);

    TEST_ASSERT_TRUE(fifo_check(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_MAX_SIZE));
}

TEST(fifo, check_tail_fail)
{
    const fifo_size_t size  = FIFO_TEST_MAX_SIZE;
    const fifo_size_t head  = FIFO_TEST_MAX_SIZE-6u;
    const fifo_size_t count = 7u;

    TEST_ASSERT_TRUE((size-count) < head);

    (void) fifo_initialize(&fifo_obj, size, head, count);
    ++fifo_obj.tail;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_MAX_SIZE));
}

TEST(fifo, check_size_fail)
{
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE+1));
}

TEST(fifo, check_count_fail)
{
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.count = 1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, check_head_fail)
{
    /*Check the inconsistency of head field with other fields.*/
    fifo_obj.head = 1u;
    TEST_ASSERT_FALSE(fifo_check(&fifo_obj));
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, empty_after_init)
{
    bool b_is_not_empty = fifo_is_not_empty(&fifo_obj);
    TEST_ASSERT_FALSE(b_is_not_empty);
}

TEST(fifo, not_full_after_init)
{
    bool b_is_not_full = fifo_is_not_full(&fifo_obj);
    TEST_ASSERT_TRUE(b_is_not_full);
}

TEST(fifo, full_on_nullptr)
{
    /*When called with null pointer, will not allow to enqueue any item.*/
    TEST_ASSERT_FALSE(fifo_is_not_full(NULL));
}

TEST(fifo, empty_on_nullptr)
{
    /*When called with null pointer, will not allow to dequeue any item.*/
    TEST_ASSERT_FALSE(fifo_is_not_empty(NULL));
}

TEST(fifo, deq_fail_after_init)
{
    /*Dequeue must fail on empty fifo.*/
    fifo_test_dequeue_fail();
}

TEST(fifo, deq_fail_on_nullptr)
{
    /*Dequeue must fail on null pointer.*/
    TEST_ASSERT_FALSE(fifo_dequeue(NULL));
}

TEST(fifo, enqueue_check_count)
{
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.count = 1u;
    fifo_test_enqueue_fail();
}

TEST(fifo, enqueue_check_tail)
{
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.tail = 1u;
    fifo_test_enqueue_fail();
}

TEST(fifo, enqueue_check_head)
{
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.head = 1u;
    fifo_test_enqueue_fail();
}

TEST(fifo, false_on_enqueue_null)
{
    TEST_ASSERT_FALSE(fifo_enqueue(NULL));
}

TEST(fifo, true_on_enqueue_ok)
{
    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        TEST_ASSERT_TRUE(fifo_enqueue(&fifo_obj));
    }
    fifo_test_enqueue_fail();
}

TEST(fifo, not_empty_after_enqueue)
{
    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        if (fifo_enqueue(&fifo_obj))
        {
            TEST_ASSERT_TRUE(fifo_is_not_empty(&fifo_obj));
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected enqueue fail.");
        }
    }
}

TEST(fifo, full_after_enqueue_all)
{
    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        if (fifo_is_not_full(&fifo_obj))
        {
            TEST_ASSERT_TRUE(fifo_enqueue(&fifo_obj));
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected fifo full.");
        }
    }

    TEST_ASSERT_FALSE(fifo_is_not_full(&fifo_obj));
}

TEST(fifo, enqueue_increments_tail)
{
    int buffer[FIFO_TEST_BUFFER_SIZE + 1] =
        { };

    bool b_is_not_full = true;

    while (b_is_not_full)
    {
        /*The tail index must be captured before calling enqueue.*/
        fifo_size_t tail = fifo_obj.tail;

        if (fifo_enqueue(&fifo_obj))
        {
            buffer[tail] = (int) fifo_obj.count;
        }
        else
        {
            b_is_not_full = false;
        }
    }

    /*Verify the contents of the filled data buffer.*/
    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        TEST_ASSERT_EQUAL((i + 1), buffer[i]);
    }
    /*The last item in the array should be untouched.*/
    TEST_ASSERT_EQUAL(0, buffer[FIFO_TEST_BUFFER_SIZE]);
}

TEST(fifo, true_on_dequeue_ok)
{
    while (fifo_enqueue(&fifo_obj))
    {
    }

    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        TEST_ASSERT_TRUE(fifo_dequeue(&fifo_obj));
    }

    fifo_test_dequeue_fail();
}

TEST(fifo, dequeue_ok_when_not_empty)
{
    while (fifo_enqueue(&fifo_obj))
    {
    }

    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        if (fifo_is_not_empty(&fifo_obj))
        {
            TEST_ASSERT_TRUE(fifo_dequeue(&fifo_obj));
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected fifo empty.");
        }
    }

    fifo_test_dequeue_fail();
    TEST_ASSERT_FALSE(fifo_is_not_empty(&fifo_obj));
}

TEST(fifo, dequeue_increments_head)
{
    int buffer[FIFO_TEST_BUFFER_SIZE + 1] =
        { };

    bool b_is_not_full = true;

    while (b_is_not_full)
    {
        /*The tail index must be captured before calling enqueue.*/
        fifo_size_t tail = fifo_obj.tail;

        if (fifo_enqueue(&fifo_obj))
        {
            buffer[tail] = (int) fifo_obj.count;
        }
        else
        {
            b_is_not_full = false;
        }
    }

    bool b_is_not_empty = true;

    /*Verify the contents of the dequeued data.*/
    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE; ++i)
    {
        /*The head index must be captured before calling dequeue.*/
        fifo_size_t head = fifo_obj.head;

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i + 1, buffer[head]);
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected dequeue fail.");
        }
    }
}

TEST(fifo, dequeue_check_count)
{
    fifo_enqueue(&fifo_obj);
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.count++;
    fifo_test_dequeue_fail();
}

TEST(fifo, dequeue_check_tail)
{
    fifo_enqueue(&fifo_obj);
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.tail++;
    fifo_test_dequeue_fail();
}

TEST(fifo, dequeue_check_head)
{
    fifo_enqueue(&fifo_obj);
    /*Check the inconsistency of count field with other fields.*/
    fifo_obj.head++;
    fifo_test_dequeue_fail();
}

TEST(fifo, check_size_always_ok)
{
    do
    {
        TEST_ASSERT_TRUE(
                fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    } while (fifo_enqueue(&fifo_obj));

    do
    {
        TEST_ASSERT_TRUE(
                fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    } while (fifo_dequeue(&fifo_obj));

    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));

    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE * 2; ++i)
    {
        TEST_ASSERT_TRUE(fifo_is_not_full(&fifo_obj));
        TEST_ASSERT_TRUE(fifo_enqueue(&fifo_obj));
        TEST_ASSERT_TRUE(fifo_is_not_empty(&fifo_obj));
        TEST_ASSERT_TRUE(
                fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
        TEST_ASSERT_TRUE(fifo_dequeue(&fifo_obj));
        TEST_ASSERT_FALSE(fifo_is_not_empty(&fifo_obj));
        TEST_ASSERT_TRUE(
                fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    }

    /*Do the same tests with the fifo nearly full.*/
    do
    {
        TEST_ASSERT_TRUE(
                        fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    } while (fifo_enqueue(&fifo_obj));

    TEST_ASSERT_FALSE(fifo_is_not_full(&fifo_obj));
    TEST_ASSERT_TRUE(fifo_is_not_empty(&fifo_obj));

    for (int i = 0; i < FIFO_TEST_BUFFER_SIZE * 2; ++i)
    {
        TEST_ASSERT_TRUE(fifo_dequeue(&fifo_obj));
        TEST_ASSERT_TRUE(fifo_is_not_full(&fifo_obj));
        TEST_ASSERT_TRUE(
                        fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
        TEST_ASSERT_TRUE(fifo_enqueue(&fifo_obj));
        TEST_ASSERT_FALSE(fifo_is_not_full(&fifo_obj));
        TEST_ASSERT_TRUE(fifo_is_not_empty(&fifo_obj));
        TEST_ASSERT_TRUE(
                        fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
    }
}

TEST(fifo, correct_data_in_buffer)
{
    int buffer[FIFO_TEST_BUFFER_SIZE + 1] =
            { };

    for(int i = 0; i < (FIFO_TEST_BUFFER_SIZE); ++i)
    {
        /*The tail index must be captured before calling enqueue.*/
        fifo_size_t tail = fifo_obj.tail;

        if (fifo_enqueue(&fifo_obj))
        {
            //The data can be written only after enqueue is confirmed.
            buffer[tail] = i;
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected enqueue fail.");
        }
    }

    for(int i = 0; i < (FIFO_TEST_BUFFER_SIZE*2); ++i)
    {
        /*The head index must be captured before calling dequeue.*/
        fifo_size_t head = fifo_obj.head;

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i, buffer[head]);
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected dequeue fail.");
        }

        /*The tail index must be captured before calling enqueue.*/
        fifo_size_t tail = fifo_obj.tail;

        if (fifo_enqueue(&fifo_obj))
        {
            buffer[tail] = i + (int)FIFO_TEST_BUFFER_SIZE;
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected enqueue fail.");
        }
    }

    for(int i = (FIFO_TEST_BUFFER_SIZE*2); i < (FIFO_TEST_BUFFER_SIZE*3); ++i)
    {
        /*The head index must be captured before calling dequeue.*/
        fifo_size_t head = fifo_obj.head;

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i, buffer[head]);
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected dequeue fail.");
        }
    }
}

/*** end of file ***/
