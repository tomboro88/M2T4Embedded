/**
 * @file 
 * 
 */

#ifndef TJUNCTION_H
#define TJUNCTION_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include <sm.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The type representing the TJunction_Jtest_s struct.
     */
    typedef struct TJunction_Jtest_s \
            TJunction_Jtest_t;

    /**
     * @brief The type representing the TJunction_sm1_s struct.
     */
    typedef struct TJunction_sm1_s \
            TJunction_sm1_t;

    /**
     * @brief The enumeration of all events handled by Jtest Class.
     */
    typedef enum
    {
        /**
         */
        TJUNCTION_JTEST_A,
        /**
         */
        TJUNCTION_JTEST_B,
        /**
         */
        TJUNCTION_JTEST_C,
        /**
         */
        TJUNCTION_JTEST_D,
        /**
         * @brief The number of all events handled by Jtest Class.
         */
        TJUNCTION_JTEST_EVENT_COUNT
    }tjunction_jtest_evtype_t;
    
    /**
     * @brief The base type of the event in the event pool of the Jtest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The type of the next event in the event pool of the Jtest
         * class.
         */
        tjunction_jtest_evtype_t        event_next;
    }tjunction_jtest_evbase_t;
    
    /**
     * @brief The struct with data of the a event in the event pool of the
     * Jtest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tjunction_jtest_evbase_t        evbase;
    }tjunction_jtest_a_t;
    
    /**
     * @brief The struct with a event queue in the event pool of the Jtest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The index of the first element in the queue.
         */
        size_t                          head;
        /**
         * @brief The index of the last element in the queue.
         */
        size_t                          tail;
        /**
         * @brief The number of elements in the queue.
         */
        size_t                          count;
        /**
         * @brief The array of events in the queue.
         */
        tjunction_jtest_a_t             events[TJUNCTION_JTEST_A_CNT];
    }tjunction_jtest_a_queue_t;
    
    /**
     * @brief The struct with data of the b event in the event pool of the
     * Jtest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tjunction_jtest_evbase_t        evbase;
    }tjunction_jtest_b_t;
    
    /**
     * @brief The struct with b event queue in the event pool of the Jtest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The index of the first element in the queue.
         */
        size_t                          head;
        /**
         * @brief The index of the last element in the queue.
         */
        size_t                          tail;
        /**
         * @brief The number of elements in the queue.
         */
        size_t                          count;
        /**
         * @brief The array of events in the queue.
         */
        tjunction_jtest_b_t             events[TJUNCTION_JTEST_B_CNT];
    }tjunction_jtest_b_queue_t;
    
    /**
     * @brief The struct with data of the c event in the event pool of the
     * Jtest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tjunction_jtest_evbase_t        evbase;
    }tjunction_jtest_c_t;
    
    /**
     * @brief The struct with c event queue in the event pool of the Jtest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The index of the first element in the queue.
         */
        size_t                          head;
        /**
         * @brief The index of the last element in the queue.
         */
        size_t                          tail;
        /**
         * @brief The number of elements in the queue.
         */
        size_t                          count;
        /**
         * @brief The array of events in the queue.
         */
        tjunction_jtest_c_t             events[TJUNCTION_JTEST_C_CNT];
    }tjunction_jtest_c_queue_t;
    
    /**
     * @brief The struct with data of the d event in the event pool of the
     * Jtest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tjunction_jtest_evbase_t        evbase;
    }tjunction_jtest_d_t;
    
    /**
     * @brief The struct with d event queue in the event pool of the Jtest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The index of the first element in the queue.
         */
        size_t                          head;
        /**
         * @brief The index of the last element in the queue.
         */
        size_t                          tail;
        /**
         * @brief The number of elements in the queue.
         */
        size_t                          count;
        /**
         * @brief The array of events in the queue.
         */
        tjunction_jtest_d_t             events[TJUNCTION_JTEST_D_CNT];
    }tjunction_jtest_d_queue_t;
    
    /**
     */
    struct TJunction_Jtest_s
    {
        /**
         * @brief The type of the first event in the event pool of the Jtest
         * class.
         */
        tjunction_jtest_evtype_t        event_head;
        /**
         * @brief The type of the last event in the event pool of the Jtest
         * class.
         */
        tjunction_jtest_evtype_t        event_tail;
        /**
         * @brief The event queue holding a events.
         */
        tjunction_jtest_a_queue_t       a;
        /**
         * @brief The event queue holding b events.
         */
        tjunction_jtest_b_queue_t       b;
        /**
         * @brief The event queue holding c events.
         */
        tjunction_jtest_c_queue_t       c;
        /**
         * @brief The event queue holding d events.
         */
        tjunction_jtest_d_queue_t       d;
    };

    /**
     * @brief The enumeration of all substates of Region1 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION1_INL,
        /**
         */
        TJUNCTION_SM1_STATE1,
        /**
         */
        TJUNCTION_SM1_STATE3,
        /**
         */
        TJUNCTION_SM1_STATE4,
        /**
         */
        TJUNCTION_SM1_STATE12,
        /**
         */
        TJUNCTION_SM1_STATE13,
        /**
         */
        TJUNCTION_SM1_STATE17,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION1_SIZE
    }tjunction_sm1_region1_t;
    
    /**
     */
    struct TJunction_sm1_s
    {
        /**
         */
        tjunction_sm1_region1_t         region1;
    };

    void TJunction_Jtest_a(TJunction_Jtest_t* const p_obj);
    void TJunction_Jtest_b(TJunction_Jtest_t* const p_obj);
    void TJunction_Jtest_c(TJunction_Jtest_t* const p_obj);
    void TJunction_Jtest_d(TJunction_Jtest_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* TJUNCTION_H */

/*** end of file ***/
