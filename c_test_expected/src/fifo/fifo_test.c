/**
 * @file fifo_test.c
 *
 * @brief Source code of the fifo test group.
 * @details Performs tests of the fifo module.
 * @author tomboro88
 * @date   2 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

#include <unity_fixture.h>
#include <fifo.h>

#define FIFO_TEST_BUFFER_SIZE 10u

TEST_GROUP(fifo);

static fifo_t fifo_obj =
    { };

TEST_SETUP(fifo)
{
    fifo_initialize(&fifo_obj, FIFO_TEST_BUFFER_SIZE);
}

TEST_TEAR_DOWN(fifo)
{

}

TEST(fifo, init)
{
    /*Apply some random data to the fifo object.*/
    fifo_t temp_obj =
            (fifo_t) { .count = 10u, .tail = 5u, .head = 3u, .size = 1u };
    /*Run the initialization function.*/
    fifo_initialize(&temp_obj, 5u);
    /*Verify results.*/
    TEST_ASSERT_EQUAL_size_t(5u, temp_obj.size);
    TEST_ASSERT_EQUAL_size_t(0u, temp_obj.count);
    TEST_ASSERT_EQUAL_size_t(0u, temp_obj.head);
    TEST_ASSERT_EQUAL_size_t(0u, temp_obj.tail);
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
    TEST_ASSERT_FALSE(fifo_dequeue(&fifo_obj));
}

TEST(fifo, deq_fail_on_nullptr)
{
    /*Dequeue must fail on null pointer.*/
    TEST_ASSERT_FALSE(fifo_dequeue(NULL));
}

TEST(fifo, correct_size_on_init)
{
    TEST_ASSERT_TRUE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, size_check_fail1)
{
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE+1));
}

TEST(fifo, size_check_fail2)
{
    /*Check the consistency of count field with other fields.*/
    fifo_obj.count = 1; /*This test fails only for FIFO_TEST_BUFFER_SIZE == 1*/
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, size_check_fail3)
{
    /*Check the consistency of tail field with other fields.*/
    fifo_obj.tail = 1;
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
}

TEST(fifo, size_check_fail4)
{
    /*Check the consistency of head field with other fields.*/
    fifo_obj.head = 1;
    TEST_ASSERT_FALSE(fifo_check_with_size(&fifo_obj, FIFO_TEST_BUFFER_SIZE));
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
    TEST_ASSERT_FALSE(fifo_enqueue(&fifo_obj));
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

    TEST_ASSERT_FALSE(fifo_dequeue(&fifo_obj));
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

    if (!fifo_dequeue(&fifo_obj))
    {
        TEST_ASSERT_FALSE(fifo_is_not_empty(&fifo_obj));
    }
    else
    {
        TEST_FAIL_MESSAGE("Unexpected fifo dequeue.");
    }
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
        /*The buffer data must be captured before calling dequeue.*/
        int data = buffer[fifo_obj.head];

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i + 1, data);
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected dequeue fail.");
        }
    }
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
            buffer[tail] = i;
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected enqueue fail.");
        }
    }

    for(int i = 0; i < (FIFO_TEST_BUFFER_SIZE*2); ++i)
    {
        /*The buffer data must be captured before calling dequeue.*/
        int data = buffer[fifo_obj.head];

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i, data);
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
        /*The buffer data must be captured before calling dequeue.*/
        int data = buffer[fifo_obj.head];

        if (fifo_dequeue(&fifo_obj))
        {
            TEST_ASSERT_EQUAL(i, data);
        }
        else
        {
            TEST_FAIL_MESSAGE("Unexpected dequeue fail.");
        }
    }
}
