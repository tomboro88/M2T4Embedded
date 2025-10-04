/**
 * @file 
 * 
 */

#ifndef TKIND_H
#define TKIND_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include <sm.h>
//Start of user code includes bottom
//End of user code

    /**
     */
#    define TKIND_CTEST_I_CNT 2u

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
     * @brief The enumeration of all events handled by ctest Class.
     */
    typedef enum
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
    }tkind_ctest_evtype_t;
    
    /**
     * @brief The base type of the event in the event pool of the ctest
     * class.
     */
    typedef struct
    {
        /**
         * @brief The type of the next event in the event pool of the ctest
         * class.
         */
        tkind_ctest_evtype_t            event_next;
    }tkind_ctest_evbase_t;
    
    /**
     * @brief The struct with data of the i event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_i_t;
    
    /**
     * @brief The struct with i event queue in the event pool of the ctest
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
        tkind_ctest_i_t                 events[TKIND_CTEST_I_CNT];
    }tkind_ctest_i_queue_t;
    
    /**
     * @brief The struct with data of the o event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_o_t;
    
    /**
     * @brief The struct with o event queue in the event pool of the ctest
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
        tkind_ctest_o_t                 events[TKIND_CTEST_O_CNT];
    }tkind_ctest_o_queue_t;
    
    /**
     * @brief The struct with data of the a event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_a_t;
    
    /**
     * @brief The struct with a event queue in the event pool of the ctest
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
        tkind_ctest_a_t                 events[TKIND_CTEST_A_CNT];
    }tkind_ctest_a_queue_t;
    
    /**
     * @brief The struct with data of the b event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_b_t;
    
    /**
     * @brief The struct with b event queue in the event pool of the ctest
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
        tkind_ctest_b_t                 events[TKIND_CTEST_B_CNT];
    }tkind_ctest_b_queue_t;
    
    /**
     * @brief The struct with data of the c event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_c_t;
    
    /**
     * @brief The struct with c event queue in the event pool of the ctest
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
        tkind_ctest_c_t                 events[TKIND_CTEST_C_CNT];
    }tkind_ctest_c_queue_t;
    
    /**
     * @brief The struct with data of the f event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_f_t;
    
    /**
     * @brief The struct with f event queue in the event pool of the ctest
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
        tkind_ctest_f_t                 events[TKIND_CTEST_F_CNT];
    }tkind_ctest_f_queue_t;
    
    /**
     * @brief The struct with data of the e event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_e_t;
    
    /**
     * @brief The struct with e event queue in the event pool of the ctest
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
        tkind_ctest_e_t                 events[TKIND_CTEST_E_CNT];
    }tkind_ctest_e_queue_t;
    
    /**
     * @brief The struct with data of the d event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_d_t;
    
    /**
     * @brief The struct with d event queue in the event pool of the ctest
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
        tkind_ctest_d_t                 events[TKIND_CTEST_D_CNT];
    }tkind_ctest_d_queue_t;
    
    /**
     * @brief The struct with data of the n event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_n_t;
    
    /**
     * @brief The struct with n event queue in the event pool of the ctest
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
        tkind_ctest_n_t                 events[TKIND_CTEST_N_CNT];
    }tkind_ctest_n_queue_t;
    
    /**
     * @brief The struct with data of the h event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_h_t;
    
    /**
     * @brief The struct with h event queue in the event pool of the ctest
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
        tkind_ctest_h_t                 events[TKIND_CTEST_H_CNT];
    }tkind_ctest_h_queue_t;
    
    /**
     * @brief The struct with data of the g event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_g_t;
    
    /**
     * @brief The struct with g event queue in the event pool of the ctest
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
        tkind_ctest_g_t                 events[TKIND_CTEST_G_CNT];
    }tkind_ctest_g_queue_t;
    
    /**
     * @brief The struct with data of the j event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_j_t;
    
    /**
     * @brief The struct with j event queue in the event pool of the ctest
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
        tkind_ctest_j_t                 events[TKIND_CTEST_J_CNT];
    }tkind_ctest_j_queue_t;
    
    /**
     * @brief The struct with data of the m event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_m_t;
    
    /**
     * @brief The struct with m event queue in the event pool of the ctest
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
        tkind_ctest_m_t                 events[TKIND_CTEST_M_CNT];
    }tkind_ctest_m_queue_t;
    
    /**
     * @brief The struct with data of the k event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_k_t;
    
    /**
     * @brief The struct with k event queue in the event pool of the ctest
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
        tkind_ctest_k_t                 events[TKIND_CTEST_K_CNT];
    }tkind_ctest_k_queue_t;
    
    /**
     * @brief The struct with data of the l event in the event pool of the
     * ctest class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        tkind_ctest_evbase_t            evbase;
    }tkind_ctest_l_t;
    
    /**
     * @brief The struct with l event queue in the event pool of the ctest
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
        tkind_ctest_l_t                 events[TKIND_CTEST_L_CNT];
    }tkind_ctest_l_queue_t;
    
    /**
     */
    struct Tkind_ctest_s
    {
        /**
         * @brief The type of the first event in the event pool of the ctest
         * class.
         */
        tkind_ctest_evtype_t            event_head;
        /**
         * @brief The type of the last event in the event pool of the ctest
         * class.
         */
        tkind_ctest_evtype_t            event_tail;
        /**
         * @brief The event queue holding i events.
         */
        tkind_ctest_i_queue_t           i;
        /**
         * @brief The event queue holding o events.
         */
        tkind_ctest_o_queue_t           o;
        /**
         * @brief The event queue holding a events.
         */
        tkind_ctest_a_queue_t           a;
        /**
         * @brief The event queue holding b events.
         */
        tkind_ctest_b_queue_t           b;
        /**
         * @brief The event queue holding c events.
         */
        tkind_ctest_c_queue_t           c;
        /**
         * @brief The event queue holding f events.
         */
        tkind_ctest_f_queue_t           f;
        /**
         * @brief The event queue holding e events.
         */
        tkind_ctest_e_queue_t           e;
        /**
         * @brief The event queue holding d events.
         */
        tkind_ctest_d_queue_t           d;
        /**
         * @brief The event queue holding n events.
         */
        tkind_ctest_n_queue_t           n;
        /**
         * @brief The event queue holding h events.
         */
        tkind_ctest_h_queue_t           h;
        /**
         * @brief The event queue holding g events.
         */
        tkind_ctest_g_queue_t           g;
        /**
         * @brief The event queue holding j events.
         */
        tkind_ctest_j_queue_t           j;
        /**
         * @brief The event queue holding m events.
         */
        tkind_ctest_m_queue_t           m;
        /**
         * @brief The event queue holding k events.
         */
        tkind_ctest_k_queue_t           k;
        /**
         * @brief The event queue holding l events.
         */
        tkind_ctest_l_queue_t           l;
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
    };

    void Tkind_ctest_a(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_b(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_c(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_d(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_e(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_f(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_g(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_h(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_i(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_j(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_k(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_l(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_m(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_n(Tkind_ctest_t* const p_obj);
    void Tkind_ctest_o(Tkind_ctest_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* TKIND_H */

/*** end of file ***/
