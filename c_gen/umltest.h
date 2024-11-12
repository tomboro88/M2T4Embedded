/**
 * @file 
 * 
 */

#ifndef UMLTEST_H
#define UMLTEST_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "sample/sample.h"
#    include <sm.h>
//Start of user code includes bottom
//End of user code

    /**
     */
#    define UMLTEST_K 1u

    /**
     * @brief The virtual table type for the umltest_iface_s struct.
     */
    typedef struct umltest_iface_vt_s \
            umltest_iface_vt_t;

    /**
     * @brief The type representing the umltest_iface_s struct.
     */
    typedef struct umltest_iface_s \
            umltest_iface_t;

    /**
     * @brief The virtual table type for the umltest_propulsion_s struct.
     */
    typedef struct umltest_propulsion_vt_s \
            umltest_propulsion_vt_t;

    /**
     * @brief The type representing the umltest_propulsion_s struct.
     */
    typedef struct umltest_propulsion_s \
            umltest_propulsion_t;

    /**
     * @brief The virtual table type for the umltest_emotor_s struct.
     */
    typedef struct umltest_emotor_vt_s \
            umltest_emotor_vt_t;

    /**
     * @brief The type representing the umltest_emotor_s struct.
     */
    typedef struct umltest_emotor_s \
            umltest_emotor_t;

    /**
     * @brief The virtual table type for the umltest_engine_s struct.
     */
    typedef struct umltest_engine_vt_s \
            umltest_engine_vt_t;

    /**
     * @brief The type representing the umltest_engine_s struct.
     */
    typedef struct umltest_engine_s \
            umltest_engine_t;

    /**
     * @brief The virtual table type for the umltest_hybrid_s struct.
     */
    typedef struct umltest_hybrid_vt_s \
            umltest_hybrid_vt_t;

    /**
     * @brief The type representing the umltest_hybrid_s struct.
     */
    typedef struct umltest_hybrid_s \
            umltest_hybrid_t;

    /**
     * @brief The type representing the umltest_sm1_s struct.
     */
    typedef struct umltest_sm1_s \
            umltest_sm1_t;

    /**
     * @brief The virtual table type for the umltest_tmpHybrid_s struct.
     */
    typedef struct umltest_tmpHybrid_vt_s \
            umltest_tmpHybrid_vt_t;

    /**
     * @brief The type representing the umltest_tmpHybrid_s struct.
     */
    typedef struct umltest_tmpHybrid_s \
            umltest_tmpHybrid_t;

    /**
     * @brief The virtual table type for the umltest_tmpCombo_classtmp_s
     * intermediate bound struct.
     */
    typedef struct umltest_tmpCombo_classtmp_vt_s \
            umltest_tmpcombo_classtmp_vt_t;

    /**
     * @brief The type representing the umltest_tmpCombo_classtmp_s intermediate
     * bound struct.
     */
    typedef struct umltest_tmpCombo_classtmp_s \
            umltest_tmpcombo_classtmp_t;
    /**
     * @brief The virtual table type for the umltest_tmpCombo_s struct.
     */
    typedef struct umltest_tmpCombo_vt_s \
            umltest_tmpCombo_vt_t;

    /**
     * @brief The type representing the umltest_tmpCombo_s struct.
     */
    typedef struct umltest_tmpCombo_s \
            umltest_tmpCombo_t;

    /**
     */
    struct umltest_iface_s
    {
        /**
         * @brief The pointer to the virtual table of the iface class.
         */
        const umltest_iface_vt_t*       p_vtable;
    };

    /**
     * @brief The virtual table struct for the umltest_iface_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct umltest_iface_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_accelerate)(umltest_iface_t* const p_obj);
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_decelerate)(umltest_iface_t* const p_obj);
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_start)(umltest_iface_t* const p_obj);
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_stop)(umltest_iface_t* const p_obj);
    };

    /**
     */
    struct umltest_propulsion_s
    {
        /**
         * @brief iface base class data.
         */
        umltest_iface_t                 iface;
        /**
         */
        float32_t                       power;
    };

    /**
     * @brief The virtual table struct for the umltest_propulsion_s struct.
     * Contains pointers to all virtual methods of the class.
     */
    struct umltest_propulsion_vt_s
    {
        /**
         * iface base class virtual table.
         */
        umltest_iface_vt_t              iface;
    };

    /**
     */
    struct umltest_emotor_s
    {
        /**
         * @brief propulsion base class data.
         */
        umltest_propulsion_t            propulsion;
        /**
         */
        float32_t                       voltage;
        /**
         */
        float32_t                       charge;
    };

    /**
     * @brief The virtual table struct for the umltest_emotor_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct umltest_emotor_vt_s
    {
        /**
         * propulsion base class virtual table.
         */
        umltest_propulsion_vt_t         propulsion;
    };

    /**
     */
    struct umltest_engine_s
    {
        /**
         * @brief propulsion base class data.
         */
        umltest_propulsion_t            propulsion;
        /**
         */
        uint16_t                        fuelkind;
        /**
         */
        float32_t                       fuel_lvl;
    };

    /**
     * @brief The virtual table struct for the umltest_engine_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct umltest_engine_vt_s
    {
        /**
         * propulsion base class virtual table.
         */
        umltest_propulsion_vt_t         propulsion;
    };

    /**
     */
    struct umltest_hybrid_s
    {
        /**
         * @brief emotor base class data.
         */
        umltest_emotor_t                emotor;
        /**
         * @brief engine base class data.
         */
        umltest_engine_t                engine;
    };

    /**
     * @brief The virtual table struct for the umltest_hybrid_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct umltest_hybrid_vt_s
    {
        /**
         * emotor base class virtual table.
         */
        umltest_emotor_vt_t             emotor;
        /**
         * engine base class virtual table.
         */
        umltest_engine_vt_t             engine;
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
        UMLTEST_SM1_INITIAL3,
        /**
         * @brief A pseudostate reserved for execution of the effect behavior of
         * the TRN3 transition.
         */
        UMLTEST_SM1_TRN3_EFFECT,
        /**
         */
        UMLTEST_SM1_FLOP,
        /**
         */
        UMLTEST_SM1_FLIP,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION1_SIZE
    }umltest_sm1_region1_t;
    
    /**
     * @brief The enumeration of all substates of Region2 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region2 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION2_INITIAL,
        /**
         */
        UMLTEST_SM1_SUBFLOP,
        /**
         */
        UMLTEST_SM1_SUBFLOP2,
        /**
         * @brief The number of all substates of Region2 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION2_SIZE
    }umltest_sm1_region2_t;
    
    /**
     * @brief The enumeration of all substates of Region3 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region3 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION3_INITIAL,
        /**
         */
        UMLTEST_SM1_SUBFLIP,
        /**
         * @brief The number of all substates of Region3 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION3_SIZE
    }umltest_sm1_region3_t;
    
    /**
     * @brief The enumeration of all substates of Region4 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region4 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION4_INITIAL,
        /**
         */
        UMLTEST_SM1_SUBFLIP2,
        /**
         * @brief A pseudostate reserved for execution of the exit behavior of
         * the SUBFLIP3 state.
         */
        UMLTEST_SM1_SUBFLIP3_EXIT,
        /**
         */
        UMLTEST_SM1_SUBFLIP3,
        /**
         * @brief The number of all substates of Region4 Region of sm1
         * StateMachine.
         */
        UMLTEST_SM1_REGION4_SIZE
    }umltest_sm1_region4_t;
    
    /**
     */
    struct umltest_sm1_s
    {
        /**
         */
        umltest_sm1_region1_t           region1;
        /**
         */
        umltest_sm1_region2_t           region2;
        /**
         */
        umltest_sm1_region3_t           region3;
        /**
         */
        umltest_sm1_region4_t           region4;
    };

    /**
     * @brief tmpHybrid class description.
     */
    struct umltest_tmpHybrid_s
    {
    };

    /**
     * @brief The virtual table struct for the umltest_tmpHybrid_s struct.
     * Contains pointers to all virtual methods of the class.
     */
    struct umltest_tmpHybrid_vt_s
    {
    };

    /**
     * @brief Binding tmpCombo to classtmp.
     */
    struct umltest_tmpCombo_classtmp_s
    {
    };
    
    /**
     * @brief The enumeration of all events handled by tmpCombo Class.
     */
    typedef enum
    {
        /**
         */
        UMLTEST_TMPCOMBO_CALL_FLIP,
        /**
         */
        UMLTEST_TMPCOMBO_CALLFLAP,
        /**
         */
        UMLTEST_TMPCOMBO_CALL_FLOP,
        /**
         */
        UMLTEST_TMPCOMBO_FLUPCALEVT,
        /**
         */
        UMLTEST_TMPCOMBO_FLEPCALLEVT,
        /**
         * @brief The number of all events handled by tmpCombo Class.
         */
        UMLTEST_TMPCOMBO_EVENT_COUNT
    }umltest_tmpcombo_evtype_t;
    
    /**
     * @brief The base type of the event in the event pool of the tmpCombo
     * class.
     */
    typedef struct
    {
        /**
         * @brief The type of the next event in the event pool of the tmpCombo
         * class.
         */
        umltest_tmpcombo_evtype_t       event_next;
    }umltest_tmpcombo_evbase_t;
    
    /**
     * @brief The struct with data of the call_flip event in the event pool
     * of the tmpCombo class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        umltest_tmpcombo_evbase_t       evbase;
    }umltest_tmpcombo_call_flip_t;
    
    /**
     * @brief The struct with call_flip event queue in the event pool of the
     * tmpCombo class.
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
        umltest_tmpcombo_call_flip_t    events[UMLTEST_TMPCOMBO_CALL_FLIP_CNT];
    }umltest_tmpcombo_call_flip_queue_t;
    
    /**
     * @brief The struct with data of the callFlap event in the event pool
     * of the tmpCombo class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        umltest_tmpcombo_evbase_t       evbase;
    }umltest_tmpcombo_callflap_t;
    
    /**
     * @brief The struct with callFlap event queue in the event pool of the
     * tmpCombo class.
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
        umltest_tmpcombo_callflap_t     events[UMLTEST_TMPCOMBO_CALLFLAP_CNT];
    }umltest_tmpcombo_callflap_queue_t;
    
    /**
     * @brief The struct with data of the call_flop event in the event pool
     * of the tmpCombo class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        umltest_tmpcombo_evbase_t       evbase;
    }umltest_tmpcombo_call_flop_t;
    
    /**
     * @brief The struct with call_flop event queue in the event pool of the
     * tmpCombo class.
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
        umltest_tmpcombo_call_flop_t    events[UMLTEST_TMPCOMBO_CALL_FLOP_CNT];
    }umltest_tmpcombo_call_flop_queue_t;
    
    /**
     * @brief The struct with data of the flupcalevt event in the event pool
     * of the tmpCombo class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        umltest_tmpcombo_evbase_t       evbase;
    }umltest_tmpcombo_flupcalevt_t;
    
    /**
     * @brief The struct with flupcalevt event queue in the event pool of
     * the tmpCombo class.
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
        umltest_tmpcombo_flupcalevt_t   events[UMLTEST_TMPCOMBO_FLUPCALEVT_CNT];
    }umltest_tmpcombo_flupcalevt_queue_t;
    
    /**
     * @brief The struct with data of the flepcallevt event in the event
     * pool of the tmpCombo class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        umltest_tmpcombo_evbase_t       evbase;
    }umltest_tmpcombo_flepcallevt_t;
    
    /**
     * @brief The struct with flepcallevt event queue in the event pool of
     * the tmpCombo class.
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
        umltest_tmpcombo_flepcallevt_t  events\
                                        [UMLTEST_TMPCOMBO_FLEPCALLEVT_CNT];
    }umltest_tmpcombo_flepcallevt_queue_t;
    
    /**
     */
    struct umltest_tmpCombo_s
    {
        /**
         * @brief classtmp template class data.
         */
        umltest_tmpCombo_classtmp_t     classtmp;
        /**
         * @brief tmpHybrid base class data.
         */
        umltest_tmpHybrid_t             tmpHybrid;
        /**
         * @brief The type of the first event in the event pool of the tmpCombo
         * class.
         */
        umltest_tmpcombo_evtype_t       event_head;
        /**
         * @brief The type of the last event in the event pool of the tmpCombo
         * class.
         */
        umltest_tmpcombo_evtype_t       event_tail;
        /**
         * @brief The event queue holding call_flip events.
         */
        umltest_tmpcombo_call_flip_queue_t \
                                        call_flip;
        /**
         * @brief The event queue holding callFlap events.
         */
        umltest_tmpcombo_callflap_queue_t \
                                        callFlap;
        /**
         * @brief The event queue holding call_flop events.
         */
        umltest_tmpcombo_call_flop_queue_t \
                                        call_flop;
        /**
         * @brief The event queue holding flupcalevt events.
         */
        umltest_tmpcombo_flupcalevt_queue_t \
                                        flupcalevt;
        /**
         * @brief The event queue holding flepcallevt events.
         */
        umltest_tmpcombo_flepcallevt_queue_t \
                                        flepcallevt;
        /**
         */
        float32_t                       additional_prop;
    };

    /**
     * @brief The virtual table struct for the umltest_tmpCombo_s struct.
     * Contains pointers to all virtual methods of the class.
     */
    struct umltest_tmpCombo_vt_s
    {
        /**
         * tmpHybrid base class virtual table.
         */
        umltest_tmpHybrid_vt_t          tmpHybrid;
    };

    void umltest_classtmp_add(umltest_classtmp_t* const p_obj,\
                              const umltest_E_t* const x);

    void umltest_iface_start(umltest_iface_t* const p_obj);
    void umltest_iface_stop(umltest_iface_t* const p_obj);
    void umltest_iface_accelerate(umltest_iface_t* const p_obj);
    void umltest_iface_decelerate(umltest_iface_t* const p_obj);

    void umltest_tmpCombo_flop(umltest_tmpCombo_t* const p_obj);
    void umltest_tmpCombo_flip(umltest_tmpCombo_t* const p_obj);
    void umltest_tmpCombo_flap(umltest_tmpCombo_t* const p_obj);
    void umltest_tmpCombo_flep(umltest_tmpCombo_t* const p_obj);
    void umltest_tmpCombo_flup(umltest_tmpCombo_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* UMLTEST_H */

/*** end of file ***/
