/**
 * @file 
 * 
 * A Package containing test diagrams for different kinds of transitions:
 * internal, external and local.
 */

#ifndef TKIND_H
#define TKIND_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include <sm.h>
#    include <stddef.h>
#    include <stdbool.h>
#    include <stdint.h>
#    include <event_pool.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The maximum number of I events stored in the I event queue.
     * @details This (and other) constant must be included by the creator inside
     * of the model. This way it provides an elastic way to specify the queue
     * size for each event.
     * A missing (unspecified explicitly in the model) constant will result in
     * the C-compiler error, since the queue buffers use these names as the
     * internal array sizes.
     * The specified size of 2 is not a random number. This is the minimum
     * recommended size of the created event queue. Although it may seem obvious
     * for a queue, the number of two
     * events in the queue means, that when one ovent is being processed by the
     * state machine, there will still be place for at least one new event in
     * the queue.
     * This is important for critical events, that are sent only occasionally,
     * and cannot be missed just because the event queue was filled with other
     * more frequent event types.
     */
#    define TKIND_CTEST_I_CNT 2u

    /**
     */
#    define TKIND_CTEST_O_CNT 2u

    /**
     */
#    define TKIND_CTEST_A_CNT 2u

    /**
     */
#    define TKIND_CTEST_B_CNT 2u

    /**
     */
#    define TKIND_CTEST_C_CNT 2u

    /**
     */
#    define TKIND_CTEST_F_CNT 2u

    /**
     */
#    define TKIND_CTEST_E_CNT 2u

    /**
     */
#    define TKIND_CTEST_D_CNT 2u

    /**
     */
#    define TKIND_CTEST_N_CNT 2u

    /**
     */
#    define TKIND_CTEST_H_CNT 2u

    /**
     */
#    define TKIND_CTEST_G_CNT 2u

    /**
     */
#    define TKIND_CTEST_J_CNT 2u

    /**
     */
#    define TKIND_CTEST_M_CNT 2u

    /**
     */
#    define TKIND_CTEST_K_CNT 2u

    /**
     */
#    define TKIND_CTEST_L_CNT 2u

    /**
     * @brief The size of the internal name string.
     * @details This constant is defined internally in the model as an upper
     * limit of the number of characters in the my_name property of ctest class.
     * It is automatically detected by the generator and included as a literal
     * constant in the package header.
     */
#    define TKIND_MAX_CHAR_NUM 20u

    /**
     */
#    define TKIND_PI_LITERAL_CONSTANT 3.14

    /**
     * @brief The virtual table type for the Tkind_cbase1_s struct.
     */
    typedef struct Tkind_cbase1_vt_s \
            Tkind_cbase1_vt_t;

    /**
     * @brief The type representing the Tkind_cbase1_s struct.
     */
    typedef struct Tkind_cbase1_s \
            Tkind_cbase1_t;

    /**
     * @brief The virtual table type for the Tkind_cbase2_s struct.
     */
    typedef struct Tkind_cbase2_vt_s \
            Tkind_cbase2_vt_t;

    /**
     * @brief The type representing the Tkind_cbase2_s struct.
     */
    typedef struct Tkind_cbase2_s \
            Tkind_cbase2_t;

    /**
     * @brief The virtual table type for the Tkind_ctest_s struct.
     */
    typedef struct Tkind_ctest_vt_s \
            Tkind_ctest_vt_t;

    /**
     * @brief The type representing the Tkind_ctest_s struct.
     */
    typedef struct Tkind_ctest_s \
            Tkind_ctest_t;

    /**
     * @brief The type representing the Tkind_sm1_s struct.
     */
    typedef struct Tkind_sm1_s \
            Tkind_sm1_t;

    /**
     * @brief An example base class with one uint32 property.
     */
    struct Tkind_cbase1_s
    {
        /**
         */
        uint32_t                        Property1;
        /**
         * @brief The pointer to the virtual table of the cbase1 class.
         */
        const Tkind_cbase1_vt_t*        p_vtable;
    };

    /**
     * @brief The virtual table struct for the Tkind_cbase1_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct Tkind_cbase1_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         * @param [in] param1 
         */
        void (*p_SetUintProp)(Tkind_cbase1_t* const p_obj,\
                              uint32_t const param1);
    };

    /**
     * @brief An example base class with one float property.
     */
    struct Tkind_cbase2_s
    {
        /**
         */
        float                           Property1;
        /**
         * @brief The pointer to the virtual table of the cbase2 class.
         */
        const Tkind_cbase2_vt_t*        p_vtable;
    };

    /**
     * @brief The virtual table struct for the Tkind_cbase2_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct Tkind_cbase2_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         * @return 
         */
        float (*p_GetFloatProp)(Tkind_cbase2_t* const p_obj);
    };

    /**
     * @brief The enumeration of all events handled by ctest Class.
     */
    enum tkind_ctest_evtype
    {
        /**
         */
        TKIND_CTEST_I,
        /**
         */
        TKIND_CTEST_O,
        /**
         */
        TKIND_CTEST_A,
        /**
         */
        TKIND_CTEST_B,
        /**
         */
        TKIND_CTEST_C,
        /**
         */
        TKIND_CTEST_F,
        /**
         */
        TKIND_CTEST_E,
        /**
         */
        TKIND_CTEST_D,
        /**
         */
        TKIND_CTEST_N,
        /**
         */
        TKIND_CTEST_H,
        /**
         */
        TKIND_CTEST_G,
        /**
         */
        TKIND_CTEST_J,
        /**
         */
        TKIND_CTEST_M,
        /**
         */
        TKIND_CTEST_K,
        /**
         */
        TKIND_CTEST_L,
        /**
         * @brief The number of all events handled by ctest Class.
         */
        TKIND_CTEST_EVENT_COUNT
    };
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the ctest class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the ctest class.
         */
        event_pool_t         manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t    fifo_pool[TKIND_CTEST_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any i event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_I] object.
         */
        event_pool_size_t    i_next_events[TKIND_CTEST_I_CNT];
        /**
         * @brief The array of the events that follow any o event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_O] object.
         */
        event_pool_size_t    o_next_events[TKIND_CTEST_O_CNT];
        /**
         * @brief The array of the events that follow any a event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_A] object.
         */
        event_pool_size_t    a_next_events[TKIND_CTEST_A_CNT];
        /**
         * @brief The array of the events that follow any b event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_B] object.
         */
        event_pool_size_t    b_next_events[TKIND_CTEST_B_CNT];
        /**
         * @brief The array of the events that follow any c event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_C] object.
         */
        event_pool_size_t    c_next_events[TKIND_CTEST_C_CNT];
        /**
         * @brief The array of the events that follow any f event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_F] object.
         */
        event_pool_size_t    f_next_events[TKIND_CTEST_F_CNT];
        /**
         * @brief The array of the events that follow any e event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_E] object.
         */
        event_pool_size_t    e_next_events[TKIND_CTEST_E_CNT];
        /**
         * @brief The array of the events that follow any d event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_D] object.
         */
        event_pool_size_t    d_next_events[TKIND_CTEST_D_CNT];
        /**
         * @brief The array of the events that follow any n event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_N] object.
         */
        event_pool_size_t    n_next_events[TKIND_CTEST_N_CNT];
        /**
         * @brief The array of the events that follow any h event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_H] object.
         */
        event_pool_size_t    h_next_events[TKIND_CTEST_H_CNT];
        /**
         * @brief The array of the events that follow any g event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_G] object.
         */
        event_pool_size_t    g_next_events[TKIND_CTEST_G_CNT];
        /**
         * @brief The array of the events that follow any j event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_J] object.
         */
        event_pool_size_t    j_next_events[TKIND_CTEST_J_CNT];
        /**
         * @brief The array of the events that follow any m event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_M] object.
         */
        event_pool_size_t    m_next_events[TKIND_CTEST_M_CNT];
        /**
         * @brief The array of the events that follow any k event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_K] object.
         */
        event_pool_size_t    k_next_events[TKIND_CTEST_K_CNT];
        /**
         * @brief The array of the events that follow any l event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[TKIND_CTEST_L] object.
         */
        event_pool_size_t    l_next_events[TKIND_CTEST_L_CNT];
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
    }Tkind_ctest_event_pool_t;

    /**
     * @brief The virtual table struct for the Tkind_ctest_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct Tkind_ctest_vt_s
    {
        /**
         * cbase1 base class virtual table.
         */
        Tkind_cbase1_vt_t               cbase1;
        /**
         * cbase2 base class virtual table.
         */
        Tkind_cbase2_vt_t               cbase2;
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
        TKIND_SM1_INITIAL1,
        /**
         */
        TKIND_SM1_STATE1,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION1_SIZE
    }tkind_sm1_region1_t;
    
    /**
     * @brief The enumeration of all substates of Region2 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region2 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_INITIAL3,
        /**
         * Only local transitions are linked with this state
         */
        TKIND_SM1_STATE3,
        /**
         */
        TKIND_SM1_STATE2,
        /**
         * Only external transitions are linked to this state
         */
        TKIND_SM1_STATE4,
        /**
         * @brief The number of all substates of Region2 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION2_SIZE
    }tkind_sm1_region2_t;
    
    /**
     * @brief The enumeration of all substates of Region3 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region3 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION3_INL,
        /**
         */
        TKIND_SM1_STATE5,
        /**
         * @brief The number of all substates of Region3 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION3_SIZE
    }tkind_sm1_region3_t;
    
    /**
     * @brief The enumeration of all substates of Region4 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region4 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION4_INL,
        /**
         */
        TKIND_SM1_STATE6,
        /**
         * @brief The number of all substates of Region4 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION4_SIZE
    }tkind_sm1_region4_t;
    
    /**
     * @brief The enumeration of all substates of Region5 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region5 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION5_INL,
        /**
         */
        TKIND_SM1_STATE7,
        /**
         */
        TKIND_SM1_STATE8,
        /**
         * @brief The number of all substates of Region5 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION5_SIZE
    }tkind_sm1_region5_t;
    
    /**
     * @brief The enumeration of all substates of Region6 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region6 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_INITIAL4,
        /**
         */
        TKIND_SM1_STATE9,
        /**
         * @brief The number of all substates of Region6 Region of sm1
         * StateMachine.
         */
        TKIND_SM1_REGION6_SIZE
    }tkind_sm1_region6_t;
    
    /**
     */
    struct Tkind_sm1_s
    {
        /**
         * @brief The pointer to the StateMachine's context object.
         */
        Tkind_ctest_t*                  p_context;
        /**
         */
        tkind_sm1_region1_t             region1;
        /**
         */
        tkind_sm1_region2_t             region2;
        /**
         */
        tkind_sm1_region3_t             region3;
        /**
         */
        tkind_sm1_region4_t             region4;
        /**
         * This region has no initial transition and allows to verify the
         * correctness of transition sequences in this case
         */
        tkind_sm1_region5_t             region5;
        /**
         */
        tkind_sm1_region6_t             region6;
        /**
         */
        bool                            b_test_condition;
    };

    /**
     * This is a comment linked
     * to the ctest type
     */
    struct Tkind_ctest_s
    {
        /**
         * @brief cbase1 base class data.
         */
        Tkind_cbase1_t                  cbase1;
        /**
         * @brief cbase2 base class data.
         */
        Tkind_cbase2_t                  cbase2;
        /**
         * @brief The event pool object managing all events corresponding to the
         * ctest class.
         */
        Tkind_ctest_event_pool_t        event_pool;
        /**
         * @brief The instance of the sm1 state machine. According to UML, ctest
         * class is the context of the sm1 state machine.
         */
        Tkind_sm1_t                     sm1;
        /**
         */
        char                            my_name[TKIND_MAX_CHAR_NUM];
        /**
         */
        double                          pi;
    };

    bool Tkind_cbase1_init(Tkind_cbase1_t* const p_obj);
    void Tkind_cbase1_SetUintProp(Tkind_cbase1_t* const p_obj,\
                                  uint32_t const param1);
    uint32_t Tkind_cbase1_GetUintProp(Tkind_cbase1_t* const p_obj);

    bool Tkind_cbase2_init(Tkind_cbase2_t* const p_obj);
    void Tkind_cbase2_SetFloatProp(Tkind_cbase2_t* const p_obj,\
                                   float const param1);
    float Tkind_cbase2_GetFloatProp(Tkind_cbase2_t* const p_obj);

    bool Tkind_ctest_init(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_a(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_b(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_c(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_d(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_e(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_f(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_g(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_h(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_i(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_j(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_k(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_l(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_m(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_n(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_o(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_fetch_event(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_dispatch_event(Tkind_ctest_t* const p_obj);
    bool Tkind_ctest_release_event(Tkind_ctest_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* TKIND_H */

/*** end of file ***/
