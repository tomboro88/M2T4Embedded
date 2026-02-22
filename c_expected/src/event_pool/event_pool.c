/**
 * @file event_pool.c
 *
 * @brief Implementation of a generic module used to manage multiple queues of
 * different event types.
 * @details Allows sequencing of events of multiple types as if they were all in
 * a single event queue. Also allows to have a maximum capacity of each event
 * pool for each event type separately. Such an approach protects the event pool
 * from being filled with one event type because of some unexpected behaviors,
 * while blocking other event types (which potentially could also recover
 * the program to normal state) from being enqueued. In case all event types
 * of a single state machine hold no additional data, this module contains all
 * logic that is enough to implement a complete event pool for it.
 * @author tomboro88
 * @date   15 Dec 2025
 * @copyright (c) 2025 tomboro88. All rights reserved.
 * @license MIT – see LICENSE file in project root
 * @project github.com/tomboro88/EmbeddedMachinesCoder
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
#include "event_pool.h"

/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static bool event_pool_enqueue_last(event_pool_t* const p_obj,
                                    event_pool_size_t  const event_type);
static bool event_pool_dequeue_first(event_pool_t* const p_obj);
/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief The initialization function of the event pool.
 * @param p_obj The pointer to the event pool object that should
 * be initialized.
 * @param p_queues The pointer to an array of initialized event_pool_fifo_t
 * objects.
 * @param p_sizes The pointer to an array of queue sizes of each event type.
 * @param fifo_count Specifies the size of p_queues and p_sizes arrays.
 * @return true if valid object was created.
 */
bool
event_pool_initialize(event_pool_t* const p_obj,
                      event_pool_fifo_t* const p_queues,
                      const fifo_size_t* const p_sizes,
                      event_pool_size_t  const fifo_count)
{
    bool b_is_initialized = false;

    if(NULL == p_obj)
    {

    }
    else if((NULL != p_queues) && (NULL != p_sizes) && (fifo_count > 1u))
    {
        bool b_are_sizes_ok = true;

        for(event_pool_size_t i = 0u; i< fifo_count; ++i)
        {
            b_are_sizes_ok &= ((NULL != p_queues[i].p_next_events)
                              && (!fifo_is_not_empty(&p_queues[i].fifo))
                              && fifo_check_with_size((&p_queues[i].fifo),
                                                   p_sizes[i]));
        }

        if(b_are_sizes_ok)
        {
            p_obj->first = fifo_count;
            p_obj->last = fifo_count;
            p_obj->fifo_count = fifo_count;
            p_obj->p_queues = p_queues;
        }
        else
        {
            p_obj->fifo_count = 0u;
        }

        b_is_initialized = b_are_sizes_ok;
    }
    else
    {
        p_obj->fifo_count = 0u;
    }

    return b_is_initialized;
}

/**
 * @brief Adds an event of the given type at the end of the event pool.
 * @param p_obj The pointer to the event queue manager.
 * @param event_type the event type that should be added at the queue end.
 * @return true if the event was correctly added to the queue.
 */
bool
event_pool_enqueue(event_pool_t* const p_obj,
                   event_pool_size_t  const event_type)
{
    bool b_is_enqueued = false;

    if((NULL != p_obj) && (NULL != p_obj->p_queues)
            && (event_type < p_obj->fifo_count))
    {
        fifo_size_t last_count = 0u;
        event_pool_fifo_t* p_last_queue = NULL;

        bool b_last_exists = (p_obj->first < p_obj->fifo_count)
                                           && (p_obj->last < p_obj->fifo_count);
        bool b_is_last_ok = false;

        if(b_last_exists)
        {
            p_last_queue = &p_obj->p_queues[p_obj->last];
            b_is_last_ok = (NULL != p_last_queue->p_next_events)
                           && fifo_is_not_empty(&p_last_queue->fifo);
        }
        else
        {
            b_is_last_ok = (p_obj->first == p_obj->fifo_count)
                                          && (p_obj->last == p_obj->fifo_count);
        }

        if(b_last_exists && b_is_last_ok)
        {
            /* The last count must be captured before calling enqueue.*/
            /* We already know that last_count > 0, because fifo_is_not_empty
             * returned true.*/
            last_count = p_last_queue->fifo.count;
        }

        if(!b_is_last_ok || !event_pool_enqueue_last(p_obj, event_type))
        {

        }
        else if(b_last_exists)
        {
            /*We have already checked that last_count > 0.*/
            fifo_size_t last_index = fifo_calc_tail(p_last_queue->fifo.size,
                                                    p_last_queue->fifo.head,
                                                    last_count-1u);
            p_last_queue->p_next_events[last_index] = event_type;
            b_is_enqueued = true;
        }
        else
        {
            p_obj->first = event_type;
            b_is_enqueued = true;
        }
    }

    return b_is_enqueued;
}

/**
 * @brief Get the type of the first event in the queue.
 * @details The stored data points to the event that will be removed from the
 * pool at the next event_pool_dequeue() call.
 * @param p_obj The pointer to the event pool which the event should be
 * read from.
 * @param p_first_head The pointer to the object, where the event location
 * should be stored.
 * @return true if the head index of the first event in the event pool was found
 * and saved into the p_first_head object, otherwise false.
 */
bool
event_pool_get_first_head(const event_pool_t* const p_obj,
                          event_pool_locator_t* const p_first_head)
{
    bool b_found_first_head = false;

    if((NULL != p_obj) && (NULL != p_first_head)
            && (NULL != p_obj->p_queues) && (p_obj->first < p_obj->fifo_count))
    {
        event_pool_size_t first = p_obj->first;
        event_pool_fifo_t* p_first_queue = &p_obj->p_queues[first];

        if((NULL != p_first_queue->p_next_events)
                    && fifo_is_not_empty(&p_first_queue->fifo))
        {
            p_first_head->event_type = first;
            p_first_head->event_index = p_first_queue->fifo.head;
            b_found_first_head = true;
        }
    }

    return b_found_first_head;
}

/**
 * @brief Removes an event from the beginning of the event pool.
 * @param p_obj The pointer to the event pool which the event should be
 * taken from.
 * @return true if the event pool was not empty and the dequeue was successful.
 */
bool
event_pool_dequeue(event_pool_t* const p_obj)
{
    bool b_is_dequeued = false;

    if((NULL != p_obj) && (NULL != p_obj->p_queues)
            && (p_obj->first < p_obj->fifo_count)
            && event_pool_dequeue_first(p_obj))
    {
        b_is_dequeued = true;
    }

    return b_is_dequeued;
}

/*******************************************************************************
 *
 * Private function bodies.
 *
 ******************************************************************************/

/**
 * @brief A helper function that places the event directly into the selected
 * event queue.
 * @param p_obj The pointer to the event queue.
 * @param event_type The event type that selects the queue, which it
 * should be appended to.
 * @return true if the event was correctly added to the queue.
 */
static bool
event_pool_enqueue_last(event_pool_t* const p_obj,
                        event_pool_size_t  const event_type)
{
    bool b_is_enqueued = false;

    event_pool_fifo_t* p_event_queue = &p_obj->p_queues[event_type];

    if((NULL != p_event_queue->p_next_events)
            && fifo_enqueue(&p_event_queue->fifo))
    {
        b_is_enqueued = true;

        // p_obj.fifo_count > 0 because fifo_enqueue is successful

        fifo_size_t next_index =
                fifo_calc_tail(p_event_queue->fifo.size,
                               p_event_queue->fifo.head,
                               p_event_queue->fifo.count-1u);
        p_event_queue->p_next_events[next_index] = p_obj->fifo_count;
        p_obj->last = event_type;
    }

    return b_is_enqueued;
}

/**
 * @brief A helper function that takes the event from the first fifo in the
 * sequence.
 * @param p_obj The pointer to the event queue.
 * @return true if the event was correctly taken from the pool.
 */
static bool
event_pool_dequeue_first(event_pool_t* const p_obj)
{
    bool b_is_dequeued = false;

    /*The head index must be captured before calling dequeue.*/
    event_pool_size_t first = p_obj->first;
    event_pool_fifo_t* p_first_queue = &p_obj->p_queues[first];
    fifo_size_t head = p_first_queue->fifo.head;
    /*Here still not sure if head is valid.*/

    if((NULL != p_first_queue->p_next_events)
            && fifo_dequeue(&p_first_queue->fifo))
    {
        if(!fifo_is_not_empty(&p_first_queue->fifo)
                && (first == p_obj->last))
        {
            p_obj->first = p_obj->fifo_count;
            p_obj->last = p_obj->fifo_count;
        }
        else
        {
            //Since fifo_dequeue is successful, that means head is valid.
            p_obj->first = p_first_queue->p_next_events[head];
        }

        b_is_dequeued = true;
    }

    return b_is_dequeued;
}

/*** end of file ***/
