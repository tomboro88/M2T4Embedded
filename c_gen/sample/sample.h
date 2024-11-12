/**
 * @file 
 * 
 * @brief The package used for measurement data filtering.
 */

#ifndef SAMPLE_H
#define SAMPLE_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include <sm.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The virtual table type for the sample_flt_s struct.
     */
    typedef struct sample_flt_vt_s \
            sample_flt_vt_t;

    /**
     * @brief The type representing the sample_flt_s struct.
     */
    typedef struct sample_flt_s \
            sample_flt_t;

    /**
     * @brief The enumeration of all substates of sample_state Region of flt
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the sample_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_INPUT_INITIAL,
        /**
         */
        SAMPLE_FLT_INPUT_VALID,
        /**
         * @brief The state indicating, that the previous input sample was
         * invalid.
         */
        SAMPLE_FLT_INPUT_INVALID,
        /**
         */
        SAMPLE_FLT_INPUT_FIRST_PRESET,
        /**
         */
        SAMPLE_FLT_INPUT_NEXT_PRESET,
        /**
         * @brief The number of all substates of sample_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_SAMPLE_STATE_SIZE
    }sample_flt_sample_state_t;
    
    /**
     * @brief The enumeration of all substates of filter_state Region of flt
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the filter_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_FILTER_INITIAL,
        /**
         */
        SAMPLE_FLT_FILTER_INVALID,
        /**
         */
        SAMPLE_FLT_FILTER_VALID,
        /**
         * @brief The number of all substates of filter_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_FILTER_STATE_SIZE
    }sample_flt_filter_state_t;
    
    /**
     * @brief The enumeration of all substates of finvalid_state Region of flt
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the finvalid_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_FINVALID_STATE_INITIAL,
        /**
         */
        SAMPLE_FLT_FILTER_ERROR,
        /**
         * @brief The number of all substates of finvalid_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_FINVALID_STATE_SIZE
    }sample_flt_finvalid_state_t;
    
    /**
     * @brief The enumeration of all substates of value_state Region of flt
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the value_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_VALUE_INITIAL,
        /**
         */
        SAMPLE_FLT_VALUE_ERROR,
        /**
         */
        SAMPLE_FLT_VALUE_INVALID,
        /**
         */
        SAMPLE_FLT_VALUE_OK,
        /**
         * @brief The number of all substates of value_state Region of flt
         * StateMachine.
         */
        SAMPLE_FLT_VALUE_STATE_SIZE
    }sample_flt_value_state_t;
    
    /**
     * @brief The enumeration of all events handled by flt Class.
     */
    typedef enum
    {
        /**
         */
        SAMPLE_FLT_NEW_SAMPLE_CALL_EVENT,
        /**
         */
        SAMPLE_FLT_FILTERINVALIDCALLEVENT,
        /**
         */
        SAMPLE_FLT_FILTERNEXTPRESETCALLEVENT,
        /**
         */
        SAMPLE_FLT_FILTERFIRSTPRESETCALLEVENT,
        /**
         */
        SAMPLE_FLT_FILTERVALIDCALLEVENT,
        /**
         */
        SAMPLE_FLT_SETFILTERERRORCALLEVENT,
        /**
         */
        SAMPLE_FLT_VALUEOKCALLEVENT,
        /**
         */
        SAMPLE_FLT_VALUEERRORCALLEVENT,
        /**
         */
        SAMPLE_FLT_VALUEINVALIDCALLEVENT,
        /**
         * @brief The number of all events handled by flt Class.
         */
        SAMPLE_FLT_EVENT_COUNT
    }sample_flt_evtype_t;
    
    /**
     * @brief The base type of the event in the event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The type of the next event in the event pool of the flt class.
         */
        sample_flt_evtype_t             event_next;
    }sample_flt_evbase_t;
    
    /**
     * @brief The struct with data of the new_sample_call_event event in the
     * event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_new_sample_call_event_t;
    
    /**
     * @brief The struct with new_sample_call_event event queue in the event
     * pool of the flt class.
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
        sample_flt_new_sample_call_event_t \
                                        events\
                                        [SAMPLE_FLT_NEW_SAMPLE_CALL_EVENT_CNT];
    }sample_flt_new_sample_call_event_queue_t;
    
    /**
     * @brief The struct with data of the FilterInvalidCallEvent event in
     * the event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_filterinvalidcallevent_t;
    
    /**
     * @brief The struct with FilterInvalidCallEvent event queue in the
     * event pool of the flt class.
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
        sample_flt_filterinvalidcallevent_t \
                                        events\
                                        [SAMPLE_FLT_FILTERINVALIDCALLEVENT_CNT];
    }sample_flt_filterinvalidcallevent_queue_t;
    
    /**
     * @brief The struct with data of the FilterNextPresetCallEvent event in
     * the event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_filternextpresetcallevent_t;
    
    /**
     * @brief The struct with FilterNextPresetCallEvent event queue in the
     * event pool of the flt class.
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
        sample_flt_filternextpresetcallevent_t \
                                        events\
                                        [SAMPLE_FLT_FILTERNEXTPRESETCALLEVENT_CNT];
    }sample_flt_filternextpresetcallevent_queue_t;
    
    /**
     * @brief The struct with data of the FilterFirstPresetCallEvent event
     * in the event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_filterfirstpresetcallevent_t;
    
    /**
     * @brief The struct with FilterFirstPresetCallEvent event queue in the
     * event pool of the flt class.
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
        sample_flt_filterfirstpresetcallevent_t \
                                        events\
                                        [SAMPLE_FLT_FILTERFIRSTPRESETCALLEVENT_CNT];
    }sample_flt_filterfirstpresetcallevent_queue_t;
    
    /**
     * @brief The struct with data of the FilterValidCallEvent event in the
     * event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_filtervalidcallevent_t;
    
    /**
     * @brief The struct with FilterValidCallEvent event queue in the event
     * pool of the flt class.
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
        sample_flt_filtervalidcallevent_t \
                                        events\
                                        [SAMPLE_FLT_FILTERVALIDCALLEVENT_CNT];
    }sample_flt_filtervalidcallevent_queue_t;
    
    /**
     * @brief The struct with data of the SetFilterErrorCallEvent event in
     * the event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_setfiltererrorcallevent_t;
    
    /**
     * @brief The struct with SetFilterErrorCallEvent event queue in the
     * event pool of the flt class.
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
        sample_flt_setfiltererrorcallevent_t \
                                        events\
                                        [SAMPLE_FLT_SETFILTERERRORCALLEVENT_CNT];
    }sample_flt_setfiltererrorcallevent_queue_t;
    
    /**
     * @brief The struct with data of the ValueOkCallEvent event in the
     * event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_valueokcallevent_t;
    
    /**
     * @brief The struct with ValueOkCallEvent event queue in the event pool
     * of the flt class.
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
        sample_flt_valueokcallevent_t   events[SAMPLE_FLT_VALUEOKCALLEVENT_CNT];
    }sample_flt_valueokcallevent_queue_t;
    
    /**
     * @brief The struct with data of the ValueErrorCallEvent event in the
     * event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_valueerrorcallevent_t;
    
    /**
     * @brief The struct with ValueErrorCallEvent event queue in the event
     * pool of the flt class.
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
        sample_flt_valueerrorcallevent_t \
                                        events\
                                        [SAMPLE_FLT_VALUEERRORCALLEVENT_CNT];
    }sample_flt_valueerrorcallevent_queue_t;
    
    /**
     * @brief The struct with data of the ValueInvalidCallEvent event in the
     * event pool of the flt class.
     */
    typedef struct
    {
        /**
         * @brief The base data of the event.
         */
        sample_flt_evbase_t             evbase;
    }sample_flt_valueinvalidcallevent_t;
    
    /**
     * @brief The struct with ValueInvalidCallEvent event queue in the event
     * pool of the flt class.
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
        sample_flt_valueinvalidcallevent_t \
                                        events\
                                        [SAMPLE_FLT_VALUEINVALIDCALLEVENT_CNT];
    }sample_flt_valueinvalidcallevent_queue_t;
    
    /**
     * @brief The sample filtering state machine.
     */
    struct sample_flt_s
    {
        /**
         */
        sample_flt_sample_state_t       sample_state;
        /**
         */
        sample_flt_filter_state_t       filter_state;
        /**
         */
        sample_flt_finvalid_state_t     finvalid_state;
        /**
         */
        sample_flt_value_state_t        value_state;
        /**
         * @brief The type of the first event in the event pool of the flt
         * class.
         */
        sample_flt_evtype_t             event_head;
        /**
         * @brief The type of the last event in the event pool of the flt class.
         */
        sample_flt_evtype_t             event_tail;
        /**
         * @brief The event queue holding new_sample_call_event events.
         */
        sample_flt_new_sample_call_event_queue_t \
                                        new_sample_call_event;
        /**
         * @brief The event queue holding FilterInvalidCallEvent events.
         */
        sample_flt_filterinvalidcallevent_queue_t \
                                        FilterInvalidCallEvent;
        /**
         * @brief The event queue holding FilterNextPresetCallEvent events.
         */
        sample_flt_filternextpresetcallevent_queue_t \
                                        FilterNextPresetCallEvent;
        /**
         * @brief The event queue holding FilterFirstPresetCallEvent events.
         */
        sample_flt_filterfirstpresetcallevent_queue_t \
                                        FilterFirstPresetCallEvent;
        /**
         * @brief The event queue holding FilterValidCallEvent events.
         */
        sample_flt_filtervalidcallevent_queue_t \
                                        FilterValidCallEvent;
        /**
         * @brief The event queue holding SetFilterErrorCallEvent events.
         */
        sample_flt_setfiltererrorcallevent_queue_t \
                                        SetFilterErrorCallEvent;
        /**
         * @brief The event queue holding ValueOkCallEvent events.
         */
        sample_flt_valueokcallevent_queue_t \
                                        ValueOkCallEvent;
        /**
         * @brief The event queue holding ValueErrorCallEvent events.
         */
        sample_flt_valueerrorcallevent_queue_t \
                                        ValueErrorCallEvent;
        /**
         * @brief The event queue holding ValueInvalidCallEvent events.
         */
        sample_flt_valueinvalidcallevent_queue_t \
                                        ValueInvalidCallEvent;
        /**
         */
        float32_t                       filtered_sample;
        /**
         */
        uint16_t                        filter_fail_counter;
        /**
         */
        uint16_t                        filter_pass_counter;
        /**
         */
        float32_t                       raw_sample;
        /**
         */
        float32_t                       max_slope;
        /**
         */
        float32_t                       upper_limit;
        /**
         */
        float32_t                       lower_limit;
        /**
         */
        uint16_t                        value_violation_counter;
        /**
         * @brief The pointer to the virtual table of the flt class.
         */
        const sample_flt_vt_t*          p_vtable;
    };

    /**
     * @brief The virtual table struct for the sample_flt_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct sample_flt_vt_s
    {
        /**
         * @brief Low pass operation performed on the new raw sample.
         * 
         * It is protected so that it can be overriden.
         * @param [in] p_obj The pointer to the self object.
         * @param [in] filter_in The filter input value.
         */
        void (*p_lp)(sample_flt_t* const p_obj, float32_t const filter_in);
    };

    void sample_flt_acquire(sample_flt_t* const p_obj, float32_t const sample,\
                            bool const b_is_valid);
    bool sample_flt_has_value(const sample_flt_t* const p_obj);
    sample_flt_t* sample_flt_init(sample_flt_t* const p_obj,\
                                  float32_t const upper_limit,\
                                  float32_t const lower_limit,\
                                  float32_t const max_slope);

#ifdef  __cplusplus
}
#endif

#endif  /* SAMPLE_H */

/*** end of file ***/
