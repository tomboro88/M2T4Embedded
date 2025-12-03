/** @file fifo.h
 *
 * @brief Functions that manage the indexes of a fifo queue of any size.
 * @details Functions in this module operate on a fifo_t object. The application
 * can read the fields from the indexes but any modifications to them should
 * only be made by this module's functions.
 * Normally the fifo_t objects will become a part of some other objects with
 * corresponding buffers, e.g.:
 *
 * struct int_fifo{
 *     int    items[10];
 *     fifo_t fifo_obj;
 * };
 *
 * @author tomboro88
 * @date   2 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

#ifndef FIFO_H
#define	FIFO_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief This macro initializes the fifo_t struct to an empty state.
 * @param [in] s The size of the fifo storage array.
 * @return The fifo_t structure initialized to an empty state and given
 * size.
 */
#    define FIFO_INITIALIZER(s) (fifo_t) {.count = 0u,\
                                     .tail = 0u, .head = 0u, .size = s}

    /**
     * @brief The type for element index storage.
     */
    typedef size_t fifo_size_t;

    /**
     * @brief The struct with the description of indexes used to locate data
     * within an array of specific size.
     */
    typedef struct
    {
        /**
         * @brief The number of elements in the queue.
         */
        fifo_size_t count;
        /**@brief The index of an empty element at the end of the queue where
         * new data can be stored.*/
        fifo_size_t tail;
        /**@brief The index of the first element in the queue that can be taken
         * out.*/
        fifo_size_t head;
        /**@brief The number of elements that can be stored within the array.*/
        fifo_size_t size;
    } fifo_t;

    void fifo_initialize (fifo_t *const p_obj, const fifo_size_t size);
    bool fifo_check_with_size (const fifo_t *const p_obj, const fifo_size_t size);
    bool fifo_enqueue (fifo_t *const p_obj);
    bool fifo_dequeue (fifo_t *const p_obj);
    bool fifo_is_not_empty (const fifo_t *const p_obj);
    bool fifo_is_not_full (const fifo_t *const p_obj);

#ifdef	__cplusplus
}
#endif

#endif	/* FIFO_H */

