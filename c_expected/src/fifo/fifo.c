/** @file fifo.c
 *
 * @brief An implementation of a FIFO queue based on array indexes.
 * @details The module only computes the indexes of the tail and head elements
 * in an array of a given size.
 * @author tomboro88
 * @date   2 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include "fifo.h"
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static fifo_size_t fifo_increment_index (const fifo_size_t index,
                                         const fifo_size_t size);
static bool fifo_check (const fifo_t *const p_obj);

/**
 * @brief Increments the index and resets to zero if it's greater than size.
 * @param [in] index The index that should be incremented.
 * @param [in] size The value of which the index must be lower than.
 * @return The new value of the index.
 */
static inline fifo_size_t
fifo_increment_index (const fifo_size_t index, const fifo_size_t size)
{
    fifo_size_t new_index = index + 1u;

    if (new_index >= size)
    {
        new_index = 0u;
    }

    return new_index;
}

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/

/**
 * @brief Initializes the indexes of the given fifo_t struct to empty state.
 * @param [out] p_obj The pointer to the object that should be initialised.
 * @param [in] size The size of the array holding the fifo elements.
 *
 * The .tail and .head fields are set to zero, and the .size field is set to
 * size.
 */
void
fifo_initialize (fifo_t *const p_obj, const fifo_size_t size)
{
    if (NULL != p_obj)
    {
        *p_obj = FIFO_INITIALIZER(size);
    }
}

/**
 * @brief Checks if the indexes and size of the fifo object correspond to the
 * given array size.
 * @param [in] p_obj The pointer to the object that should be checked.
 * @param [in] size The size of the array to which the object should be
 * compared.
 * @returns true if the indexes and size  fields are within the bonds specified
 * by the given size.
 * @returns false if the fields in the object are not valid or if the pointer is
 * NULL.
 */
bool
fifo_check_with_size (const fifo_t *const p_obj, const fifo_size_t size)
{
    bool b_is_valid = fifo_check(p_obj) && (p_obj->count <= p_obj->size)
            && (p_obj->size == size);

    if (b_is_valid)
    {
        /*The following calculations allow to get calc_tail
         * without overflowing fifo_size_t.*/
        fifo_size_t s_minus_c = size - p_obj->count; /* size >= count */

        fifo_size_t calc_tail = 0;

        if (s_minus_c > p_obj->head)
        {
            calc_tail = p_obj->head + p_obj->count; /* always < size here */
        }
        else
        {
            calc_tail = p_obj->head - s_minus_c; /* head >= (size-count) */
        }

        b_is_valid = (calc_tail == p_obj->tail);
    }

    return b_is_valid;
}

/**
 * @brief Marks the element at the end of the queue as occupied.
 * @param [in] p_obj The pointer to the object that should be modified.
 * @returns true if the element was added to the queue.
 * @returns false if the queue was full, or if the pointer was null.
 */
bool
fifo_enqueue (fifo_t *const p_obj)
{
    bool b_is_enqueued = false;

    if (fifo_is_not_full(p_obj))
    {
        fifo_size_t tail = fifo_increment_index(p_obj->tail, p_obj->size);
        p_obj->tail = tail;
        ++p_obj->count;
        b_is_enqueued = true;
    }

    return b_is_enqueued;
}

/**
 * @brief Marks the element at the beginning of the queue as free.
 * @param [in] p_obj The pointer to the object from which an element was taken
 * out.
 * @returns true if the element was dequeued.
 * @returns false if the fifo was empty or the pointer was null.
 */
bool
fifo_dequeue (fifo_t *const p_obj)
{
    bool b_is_dequeued = false;

    if (fifo_is_not_empty(p_obj))
    {
        p_obj->head = fifo_increment_index(p_obj->head, p_obj->size);
        --p_obj->count;
        b_is_dequeued = true;
    }

    return b_is_dequeued;
}

/**
 * @brief Checks if there is at least one element in the fifo.
 * @param [in] p_obj The pointer to the object that should be checked.
 * @returns true if there is at least one element in the fifo.
 * @returns false if the fifo is empty or if the pointer is NULL or the indexes
 * are invalid.
 */
bool
fifo_is_not_empty (const fifo_t *const p_obj)
{
    return fifo_check(p_obj) && (p_obj->count > 0u)
            && (p_obj->count <= p_obj->size);
}

/**
 * @brief Checks if there is at least one element empty in the fifo.
 * @param [in] p_obj The pointer to the object that should be checked.
 * @returns true if there is at least one element empty in the fifo.
 * @returns false if the fifo is full or if the pointer is NULL or if the
 * indexes are invalid.
 */
bool
fifo_is_not_full (const fifo_t *const p_obj)
{
    return fifo_check(p_obj) && (p_obj->count < p_obj->size);
}

/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/
/**
 * @brief Checks if the indexes and size of the fifo object are valid with
 * respect to each other.
 * @param [in] p_obj The pointer to the object that should be checked.
 * @returns true if the index fields are within the bonds specified
 * by the size field.
 * @returns false if the fields in the object are not valid or if the pointer is
 * NULL.
 */
static bool
fifo_check (const fifo_t *const p_obj)
{
    return (NULL != p_obj) && (p_obj->head < p_obj->size)
            && (p_obj->tail < p_obj->size);
}

/*** end of file ***/
