/**
 * @file 
 * 
 * @brief A package with state machine diagrams utilizing the Junction
 * Pseudostate.
 * @details The state diagrams included in this package are used to validate the
 * code
 * generated for Junction Pseudostates, which are advanced choice vertices used 
 * for static evaluation of a sequence of guard conditions before any transition
 * is started.
 */

#ifndef TJUNCTION_H
#define TJUNCTION_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include <sm.h>
#    include <stddef.h>
#    include <stdbool.h>
#    include <event_pool.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The size of the A event queue. Specified directly in the UML
     * model.
     */
#    define TJUNCTION_JTEST_A_CNT 4u

    /**
     * @brief The size of the B event queue. Specified individually in the UML
     * model.
     */
#    define TJUNCTION_JTEST_B_CNT 10u

    /**
     * @brief The size of the C event queue. Specified explicitly in the UML
     * model.
     */
#    define TJUNCTION_JTEST_C_CNT 8u

    /**
     * @brief The size of the A event queue. Specified manually in the UML
     * model.
     */
#    define TJUNCTION_JTEST_D_CNT 2u

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
    enum tjunction_jtest_evtype
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
    };
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the Jtest class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the Jtest class.
         */
        event_pool_t         manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t    fifo_pool[TJUNCTION_JTEST_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any a event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TJUNCTION_JTEST_A] object.
         */
        event_pool_size_t    a_next_events[TJUNCTION_JTEST_A_CNT];
        /**
         * @brief The array of the events that follow any b event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TJUNCTION_JTEST_B] object.
         */
        event_pool_size_t    b_next_events[TJUNCTION_JTEST_B_CNT];
        /**
         * @brief The array of the events that follow any c event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TJUNCTION_JTEST_C] object.
         */
        event_pool_size_t    c_next_events[TJUNCTION_JTEST_C_CNT];
        /**
         * @brief The array of the events that follow any d event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TJUNCTION_JTEST_D] object.
         */
        event_pool_size_t    d_next_events[TJUNCTION_JTEST_D_CNT];
        /**
         * @brief The marker that stores the status of processing of the event
         * at the 'first' position. It is used to prevent processing of the same
         * event multiple times, and from removing unprocessed events.
         * Moreover it can be used to handle event deferring.
         */
        sm_event_status_t    event_proc_status;
        /**
         * @brief Stores the location of the event that is currently being
         * processed.
         */
        event_pool_locator_t fetched_event;
    }TJunction_Jtest_event_pool_t;

    /**
     * @brief The enumeration of all substates of Region1 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_INITIAL49,
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
         */
        TJUNCTION_SM1_STATE29,
        /**
         */
        TJUNCTION_SM1_STATE30,
        /**
         */
        TJUNCTION_SM1_STATE36,
        /**
         */
        TJUNCTION_SM1_STATE43,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION1_SIZE
    }tjunction_sm1_region1_t;
    
    /**
     * @brief The enumeration of all substates of Region36 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region36 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION36_INL,
        /**
         */
        TJUNCTION_SM1_STATE36_1,
        /**
         */
        TJUNCTION_SM1_STATE36_2,
        /**
         * @brief The number of all substates of Region36 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION36_SIZE
    }tjunction_sm1_region36_t;
    
    /**
     * @brief The enumeration of all substates of Region431 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region431 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_INITIAL431,
        /**
         */
        TJUNCTION_SM1_STATE431,
        /**
         */
        TJUNCTION_SM1_STATE432,
        /**
         * @brief The number of all substates of Region431 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION431_SIZE
    }tjunction_sm1_region431_t;
    
    /**
     * @brief The enumeration of all substates of Region4321 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region4321 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_INITIAL4321,
        /**
         */
        TJUNCTION_SM1_STATE4321,
        /**
         */
        TJUNCTION_SM1_STATE4322,
        /**
         * @brief The number of all substates of Region4321 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION4321_SIZE
    }tjunction_sm1_region4321_t;
    
    /**
     * @brief The enumeration of all substates of Region432 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region432 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_INITIAL432,
        /**
         */
        TJUNCTION_SM1_STATE433,
        /**
         */
        TJUNCTION_SM1_STATE434,
        /**
         * @brief The number of all substates of Region432 Region of sm1
         * StateMachine.
         */
        TJUNCTION_SM1_REGION432_SIZE
    }tjunction_sm1_region432_t;
    
    /**
     */
    struct TJunction_sm1_s
    {
        /**
         * @brief The pointer to the StateMachine's context object.
         */
        TJunction_Jtest_t*              p_context;
        /**
         */
        tjunction_sm1_region1_t         region1;
        /**
         */
        tjunction_sm1_region36_t        region36;
        /**
         */
        tjunction_sm1_region431_t       region431;
        /**
         */
        tjunction_sm1_region4321_t      region4321;
        /**
         */
        tjunction_sm1_region432_t       region432;
        /**
         */
        bool                            b_guard1;
        /**
         */
        bool                            b_guard2;
        /**
         */
        bool                            b_guard3;
        /**
         */
        bool                            b_guard4;
        /**
         */
        bool                            b_guard5;
        /**
         */
        bool                            b_guard6;
        /**
         */
        bool                            b_guard7;
        /**
         */
        bool                            b_guard8;
        /**
         */
        bool                            b_guard9;
    };

    /**
     */
    struct TJunction_Jtest_s
    {
        /**
         * @brief The event pool object managing all events corresponding to the
         * Jtest class.
         */
        TJunction_Jtest_event_pool_t    event_pool;
        /**
         * @brief The instance of the sm1 state machine. According to UML Jtest
         * class is the context of the sm1 state machine.
         */
        TJunction_sm1_t                 sm1;
    };

    bool TJunction_Jtest_init(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_a(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_b(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_c(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_d(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_fetch_event(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_dispatch_event(TJunction_Jtest_t* const p_obj);
    bool TJunction_Jtest_release_event(TJunction_Jtest_t* const p_obj);
#ifdef  __cplusplus
}
#endif

#endif  /* TJUNCTION_H */

/*** end of file ***/
