/**
 * @file event_pool.h
 *
 * @brief Header a generic module used to manage multiple event
 * queues holding data of different types, as if they were in one queue.
 * @author tomboro88
 * @date   15 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/M2T4Embedded
 */

#ifndef EVENT_POOL_H_
#define EVENT_POOL_H_

#include <fifo.h>
#include <stdint.h>
#include <stdbool.h>

    /**
     * @brief The type used to store the event type. A single byte should be
     * enough for a single state machine. The type can be changed to bigger if
     * needed.
     */
    typedef uint8_t event_pool_size_t;

    /**
     * @brief The type used to store a single fifo queue data.
     */
    typedef struct {
        /**
         * @brief The object used to calculate the tail and head indexes in the
         * p_next_events array.
         */
        fifo_t               fifo;
        /**
         * @brief The pointer to an array of next event objects managed by the
         * fifo object.
         */
        event_pool_size_t*   p_next_events;
    }event_pool_fifo_t;

    /**
     * @brief The type used to hold fifo indexes of multiple collaborating
     * fifo queues.
     */
    typedef struct {
        /**
         * @brief The pointer to an array of objects with event fifo queues.
         */
        event_pool_fifo_t*   p_queues;
        /**
         * @brief The size of the p_queues.
         */
        event_pool_size_t    fifo_count;
        /**
         * @brief The type of the last event in the event pool;
         */
        event_pool_size_t    last;
        /**
         * @brief The type of the first event in the event pool;
         */
        event_pool_size_t    first;
    }event_pool_t;

    /**
     * @brief The struct holding data required to localize the event in the
     * event pool.
     */
    typedef struct {
        /**
         * @brief The event type represents the index in the p_queues field
         * of the event_pool_t struct.
         */
        event_pool_size_t    event_type;
        /**
         * @brief The event index represent the index of the event within the
         * fifo of its type.
         */
        fifo_size_t          event_index;
    }event_pool_locator_t;

    bool event_pool_initialize(event_pool_t* const p_obj,
                               event_pool_fifo_t* const p_queues,
                               const fifo_size_t* const p_sizes,
                               event_pool_size_t  const fifo_count);
    bool event_pool_enqueue(event_pool_t* const p_obj,
                            event_pool_size_t  const event_type);
    bool event_pool_get_first_head(const event_pool_t* const p_obj,
                                   event_pool_locator_t* const p_first_head);
    bool event_pool_dequeue(event_pool_t* const p_obj);

#endif /* EVENT_POOL_H_ */

/*** end of file ***/
