/**
 * @file 
 * 
 * @brief The sample package source file.
 */

/*******************************************************************************
 * 
 * Include statements.
 * 
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "sample.h"
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/**
 * @brief The number of consecutive invalid input samples required for the
 * output to be recognized as invalid.
 */
#define SAMPLE_VALUE_FAIL_MAX_COUNT 8u

/**
 * @brief The number of consecutive valid input samples required for the output
 * to be recognized as valid.
 */
#define SAMPLE_FILTER_PASS_MAX_COUNT 6u

/**
 * @brief The number of out of range output results required to for the value to
 * be treated as out of range error.
 */
#define SAMPLE_FILTER_FAIL_MAX_COUNT 20u

/*******************************************************************************
 * 
 * Non-private function prototypes.
 * 
 ******************************************************************************/
void sample_flt_lp(sample_flt_t* const p_obj, float32_t const filter_in);

void sample_flt_lp_bhv(sample_flt_t* const p_obj, float32_t const filter_in);

/*******************************************************************************
 * 
 * Private function prototypes.
 * 
 ******************************************************************************/
static bool sample_flt_check_input_range(const sample_flt_t* const p_obj);
static bool sample_flt_check_slope(const sample_flt_t* const p_obj,\
                                   float32_t const sample);
static bool sample_flt_dec_out_fault(sample_flt_t* const p_obj);
static void sample_flt_fine_first_preset(sample_flt_t* const p_obj);
static void sample_flt_fine_invalid(sample_flt_t* const p_obj);
static void sample_flt_fine_next_preset(sample_flt_t* const p_obj);
static void sample_flt_fine_valid(sample_flt_t* const p_obj);
static void sample_flt_grade_input(sample_flt_t* const p_obj,\
                                   float32_t const sample,\
                                   bool const b_is_valid);
static bool sample_flt_inc_fail(sample_flt_t* const p_obj);
static bool sample_flt_inc_out_fault(sample_flt_t* const p_obj);
static bool sample_flt_inc_pass(sample_flt_t* const p_obj);
static void sample_flt_predict(sample_flt_t* const p_obj);
static void sample_flt_preset(sample_flt_t* const p_obj);
static void sample_flt_process_graded(sample_flt_t* const p_obj);
static void sample_flt_process_out_error(sample_flt_t* const p_obj);
static void sample_flt_process_out_invalid(sample_flt_t* const p_obj);
static void sample_flt_process_out_ok(sample_flt_t* const p_obj);
static void sample_flt_rank_output(sample_flt_t* const p_obj);
static void sample_flt_set_fine_error(sample_flt_t* const p_obj);

static void sample_flt_init_df(sample_flt_t* const p_obj);

static sm_event_status_t flt_dispatch_new_sample_call_event\
       (sample_flt_t* const p_obj,\
        sample_flt_new_sample_call_event_t* const p_event);
static sm_event_status_t flt_dispatch_filterinvalidcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filternextpresetcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterfirstpresetcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filtervalidcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_setfiltererrorcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_setfiltererrorcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueokcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_valueokcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueerrorcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_valueerrorcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueinvalidcallevent\
       (sample_flt_t* const p_obj,\
        sample_flt_valueinvalidcallevent_t* const p_event);

static sm_event_status_t flt_dispatch_new_sample_call_event_sample_state\
       (sample_flt_t* const p_obj,\
        sample_flt_new_sample_call_event_t* const p_event);

static sm_event_status_t flt_dispatch_filternextpresetcallevent_filter_state\
       (sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterinvalidcallevent_filter_state\
       (sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filtervalidcallevent_filter_state\
       (sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterfirstpresetcallevent_filter_state\
       (sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event);

static sm_event_status_t flt_dispatch_valueokcallevent_value_state\
       (sample_flt_t* const p_obj,\
        sample_flt_valueokcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueinvalidcallevent_value_state\
       (sample_flt_t* const p_obj,\
        sample_flt_valueinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueerrorcallevent_value_state\
       (sample_flt_t* const p_obj,\
        sample_flt_valueerrorcallevent_t* const p_event);

static sm_event_status_t flt_dispatch_new_sample_call_event_input_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_new_sample_call_event_t* const p_event);

static sm_event_status_t flt_dispatch_filternextpresetcallevent_filter_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filternextpresetcallevent_filter_error\
       (sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filternextpresetcallevent_filter_valid\
       (sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterinvalidcallevent_filter_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterinvalidcallevent_filter_error\
       (sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterinvalidcallevent_filter_valid\
       (sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filtervalidcallevent_filter_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filtervalidcallevent_filter_error\
       (sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filtervalidcallevent_filter_valid\
       (sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterfirstpresetcallevent_filter_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_filterfirstpresetcallevent_filter_valid\
       (sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event);

static sm_event_status_t flt_dispatch_valueokcallevent_value_error\
       (sample_flt_t* const p_obj,\
        sample_flt_valueokcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueokcallevent_value_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_valueokcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueinvalidcallevent_value_ok\
       (sample_flt_t* const p_obj,\
        sample_flt_valueinvalidcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueerrorcallevent_value_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_valueerrorcallevent_t* const p_event);
static sm_event_status_t flt_dispatch_valueerrorcallevent_value_ok\
       (sample_flt_t* const p_obj,\
        sample_flt_valueerrorcallevent_t* const p_event);

/*******************************************************************************
 * 
 * Inline functions.
 * 
 ******************************************************************************/
/**
 * @brief Enters the INPUT_VALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_input_valid(sample_flt_t* const p_obj)
{
    p_obj->sample_state = SAMPLE_FLT_INPUT_VALID;
}

/**
 * @brief Enters the INPUT_INVALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_input_invalid(sample_flt_t* const p_obj)
{
    p_obj->sample_state = SAMPLE_FLT_INPUT_INVALID;
}

/**
 * @brief Enters the INPUT_FIRST_PRESET state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_input_first_preset(sample_flt_t* const p_obj)
{
    p_obj->sample_state = SAMPLE_FLT_INPUT_FIRST_PRESET;
}

/**
 * @brief Enters the INPUT_NEXT_PRESET state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_input_next_preset(sample_flt_t* const p_obj)
{
    p_obj->sample_state = SAMPLE_FLT_INPUT_NEXT_PRESET;
}

/**
 * @brief Enters the FILTER_INVALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_filter_invalid(sample_flt_t* const p_obj)
{
    p_obj->filter_state = SAMPLE_FLT_FILTER_INVALID;
}

/**
 * @brief Enters the FILTER_ERROR state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_filter_error(sample_flt_t* const p_obj)
{
    p_obj->filter_state = SAMPLE_FLT_FILTER_ERROR;
}

/**
 * @brief Enters the FILTER_VALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_filter_valid(sample_flt_t* const p_obj)
{
    p_obj->filter_state = SAMPLE_FLT_FILTER_VALID;
}

/**
 * @brief Enters the VALUE_ERROR state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_value_error(sample_flt_t* const p_obj)
{
    p_obj->value_state = SAMPLE_FLT_VALUE_ERROR;
}

/**
 * @brief Enters the VALUE_INVALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_value_invalid(sample_flt_t* const p_obj)
{
    p_obj->value_state = SAMPLE_FLT_VALUE_INVALID;
}

/**
 * @brief Enters the VALUE_OK state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
flt_enter_value_ok(sample_flt_t* const p_obj)
{
    p_obj->value_state = SAMPLE_FLT_VALUE_OK;
}

/*******************************************************************************
 * 
 * Static data declarations.
 * 
 ******************************************************************************/
/**
 * @brief The initialized virtual table for the sample_flt_s struct.
 */
static const sample_flt_vt_t sample_flt_vtable = 
{
    .p_lp                            = sample_flt_lp_bhv
};

/*******************************************************************************
 * 
 * Public function bodies.
 * 
 ******************************************************************************/
/**
 * @brief Acquire new sample and perform filtration process.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] sample 
 * @param [in] b_is_valid 
 */
void
sample_flt_acquire(sample_flt_t* const p_obj, float32_t const sample,\
                   bool const b_is_valid)
{
    sample_flt_grade_input(p_obj,sample, b_is_valid);
    p_obj->raw_sample = sample;
    sample_flt_process_graded(p_obj);
    sample_flt_rank_output(p_obj);
}

/**
 * @brief Checks if the filter output has already any reasonable value.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
sample_flt_has_value(const sample_flt_t* const p_obj)
{
    return (SAMPLE_FLT_FILTER_VALID == p_obj->filter_state) 
    || (SAMPLE_FLT_INPUT_FIRST_PRESET == p_obj->sample_state)
    || (SAMPLE_FLT_INPUT_NEXT_PRESET == p_obj->sample_state)
    || (SAMPLE_FLT_INPUT_VALID == p_obj->sample_state);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] upper_limit 
 * @param [in] lower_limit 
 * @param [in] max_slope 
 * @return 
 */
sample_flt_t*
sample_flt_init(sample_flt_t* const p_obj, float32_t const upper_limit,\
                float32_t const lower_limit, float32_t const max_slope)
{
    if(NULL != p_obj)
    {
        *p_obj = (sample_flt_t) {};
        sample_flt_init_df(p_obj);
        p_obj->upper_limit = upper_limit;
        p_obj->lower_limit = lower_limit;
        p_obj->max_slope = max_slope;
    }
    return p_obj;
}

/*******************************************************************************
 * 
 * Non-public function bodies.
 * 
 ******************************************************************************/
/**
 * @brief The initializer function of the default values and virtual tables of
 * the sample_flt_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_init_df(sample_flt_t* const p_obj)
{
    p_obj->filter_fail_counter       = 0u;
    p_obj->filter_pass_counter       = 0u;
    p_obj->value_violation_counter   = 0u;
    p_obj->p_vtable                  = &sample_flt_vtable;
}

/**
 * @brief Checks if the input sample is in valid range.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static bool
sample_flt_check_input_range(const sample_flt_t* const p_obj)
{
    return (p_obj->raw_sample <= p_obj->upper_limit) 
        && (p_obj->raw_sample >= p_obj->lower_limit);
}

/**
 * @brief Checks if the difference between the input argument and the last input
 * sample is within the allowed range.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] sample 
 * @return 
 */
static bool
sample_flt_check_slope(const sample_flt_t* const p_obj, float32_t const sample)
{
    return (fabs(sample - p_obj->raw_sample) <= fabs(p_obj->max_slope));
}

/**
 * @brief Decrements the counter of filter output value error.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static bool
sample_flt_dec_out_fault(sample_flt_t* const p_obj)
{
    if(p_obj->value_violation_counter >0)
    {
        --p_obj->value_violation_counter;
    }
    
    return (0u == p_obj->value_violation_counter);
}

/**
 * @brief Performs the filtration process after the sample has been graded as
 * "first preset".
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_fine_first_preset(sample_flt_t* const p_obj)
{
}

/**
 * @brief Performs the filtering process after the sample has been graded as
 * invalid.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_fine_invalid(sample_flt_t* const p_obj)
{
}

/**
 * @brief Performs the filtration process after the sample has been graded as
 * "next preset".
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_fine_next_preset(sample_flt_t* const p_obj)
{
}

/**
 * @brief Performs the filtration process after the input sample has been graded
 * as valid.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_fine_valid(sample_flt_t* const p_obj)
{
}

/**
 * @brief Detects if the new sample meets the criteria of a valid sample.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] sample 
 * @param [in] b_is_valid 
 */
static void
sample_flt_grade_input(sample_flt_t* const p_obj, float32_t const sample,\
                       bool const b_is_valid)
{
    
}

/**
 * @brief Increments the counter of samples classified as invalid.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static bool
sample_flt_inc_fail(sample_flt_t* const p_obj)
{
    if(p_obj->filter_fail_counter < SAMPLE_FILTER_FAIL_MAX_COUNT)
    {
        ++p_obj->filter_fail;
    }
    
    p_obj->filter_pass_counter = 0u;
    
    bool b_is_failed = false;
    
    if(p_obj->filter_fail_counter >= SAMPLE_FILTER_FAIL_MAX_COUNT)
    {
        b_is_failed = true;
    }
    
    return b_is_failed;
}

/**
 * @brief Increments the counter of filter output value error.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static bool
sample_flt_inc_out_fault(sample_flt_t* const p_obj)
{
    if(p_obj->value_violation_counter < SAMPLE_VALUE_FAIL_MAX_COUNT)
    {
        ++p_obj->value_violation_counter;
    }
    
    return (p_obj->value_violation_counter >= SAMPLE_VALUE_FAIL_MAX_COUNT);
}

/**
 * @brief Increments the counter of samples classified as valid.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static bool
sample_flt_inc_pass(sample_flt_t* const p_obj)
{
    if(p_obj->filter_pass_counter < SAMPLE_FILTER_PASS_MAX_COUNT)
    {
        ++p_obj->filter_pass_counter;
    }
    
    bool b_is_f_clean = false;
    
    if(p_obj->filter_pass_counter >= SAMPLE_FILTER_PASS_MAX_COUNT)
    {
        b_is_f_clean = true;
        p_obj->filter_fail_counter = 0u;
    }
    
    return b_is_f_clean;
}

/**
 * @brief Low pass operation performed on the new raw sample.
 * 
 * It is protected so that it can be overriden.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] filter_in The filter input value.
 */
void
sample_flt_lp(sample_flt_t* const p_obj, float32_t const filter_in)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_lp)(sample_flt_t* const p_obj, float32_t const filter_in)
            = p_obj->p_vtable->p_lp;

        if(NULL != p_lp)
        {
            p_lp(p_obj, filter_in);
        }
    }
}

/**
 * @brief Tries to predict the filter putput as if the input sample was valid.
 * 
 * This method is used for filltration when the fail or pass counter hasn't
 * reached the threshold value yet.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_predict(sample_flt_t* const p_obj)
{
    sample_flt_lp(p_obj, p_obj->filtered_sample);
}

/**
 * @brief Set the filter output value to the value of the current input sample.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_preset(sample_flt_t* const p_obj)
{
    p_obj->filtered_sample = p_obj->raw_sample;
}

/**
 * @brief Performs the second step of input sample filtering after it has been
 * graded.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_process_graded(sample_flt_t* const p_obj)
{
    
}

/**
 * @brief Operation called when the input sample processing results in output
 * value error.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_process_out_error(sample_flt_t* const p_obj)
{
}

/**
 * @brief The operation called when the input sample processing results in
 * invalid output value, but still without raising error.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_process_out_invalid(sample_flt_t* const p_obj)
{
}

/**
 * @brief Operation called when the input sample processing results in valid
 * output value.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_process_out_ok(sample_flt_t* const p_obj)
{
}

/**
 * @brief Detects if the filter output value is in valid range.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_rank_output(sample_flt_t* const p_obj)
{
    
}

/**
 * @brief Operation called when the filter output value should enter state.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sample_flt_set_fine_error(sample_flt_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] filter_in The filter input value.
 */
void
sample_flt_lp_bhv(sample_flt_t* const p_obj, float32_t const filter_in)
{
    p_obj->filtered_sample = 0.5*p_obj->filtered_sample + 0.5*filter_in;
}

/**
 * @brief Implements new_sample_call_event event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_new_sample_call_event(sample_flt_t* const p_obj,\
                                   sample_flt_new_sample_call_event_t* \
                                   /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_new_sample_call_event_filter_state(p_obj,\
                                                    p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_new_sample_call_event_sample_state(p_obj,\
                                                    p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_new_sample_call_event_value_state(p_obj,\
                                                   p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements FilterInvalidCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterinvalidcallevent(sample_flt_t* const p_obj,\
                                    sample_flt_filterinvalidcallevent_t* \
                                    /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_filterinvalidcallevent_filter_state(p_obj,\
                                                     p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filterinvalidcallevent_sample_state(p_obj,\
                                                     p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filterinvalidcallevent_value_state(p_obj,\
                                                    p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements FilterNextPresetCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filternextpresetcallevent(sample_flt_t* const p_obj,\
                                       sample_flt_filternextpresetcallevent_t* \
                                       /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_filternextpresetcallevent_filter_state(p_obj,\
                                                        p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filternextpresetcallevent_sample_state(p_obj,\
                                                        p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filternextpresetcallevent_value_state(p_obj,\
                                                       p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements FilterFirstPresetCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterfirstpresetcallevent(sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_filterfirstpresetcallevent_filter_state(p_obj,\
            p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filterfirstpresetcallevent_sample_state(p_obj,\
            p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filterfirstpresetcallevent_value_state(p_obj,\
                                                        p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements FilterValidCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filtervalidcallevent(sample_flt_t* const p_obj,\
                                  sample_flt_filtervalidcallevent_t* \
                                  /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_filtervalidcallevent_filter_state(p_obj,\
                                                   p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filtervalidcallevent_sample_state(p_obj,\
                                                   p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_filtervalidcallevent_value_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements SetFilterErrorCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_setfiltererrorcallevent(sample_flt_t* const p_obj,\
                                     sample_flt_setfiltererrorcallevent_t* \
                                     /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_setfiltererrorcallevent_filter_state(p_obj,\
                                                      p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_setfiltererrorcallevent_sample_state(p_obj,\
                                                      p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_setfiltererrorcallevent_value_state(p_obj,\
                                                     p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements ValueOkCallEvent event handling by the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueokcallevent(sample_flt_t* const p_obj,\
                              sample_flt_valueokcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_valueokcallevent_filter_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueokcallevent_sample_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueokcallevent_value_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements ValueErrorCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueerrorcallevent(sample_flt_t* const p_obj,\
                                 sample_flt_valueerrorcallevent_t* \
                                 /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_valueerrorcallevent_filter_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueerrorcallevent_sample_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueerrorcallevent_value_state(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements ValueInvalidCallEvent event handling by the flt state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueinvalidcallevent(sample_flt_t* const p_obj,\
                                   sample_flt_valueinvalidcallevent_t* \
                                   /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = flt_dispatch_valueinvalidcallevent_filter_state(p_obj,\
                                                    p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueinvalidcallevent_sample_state(p_obj,\
                                                    p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = flt_dispatch_valueinvalidcallevent_value_state(p_obj,\
                                                   p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements new_sample_call_event event handling by the sample_state
 * region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_new_sample_call_event_sample_state(sample_flt_t* const p_obj,\
        sample_flt_new_sample_call_event_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->sample_state)
    {
        case SAMPLE_FLT_INPUT_INVALID:
            result = flt_dispatch_new_sample_call_event_input_invalid(p_obj,\
                                                             p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements FilterNextPresetCallEvent event handling by the
 * filter_state region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filternextpresetcallevent_filter_state(sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->filter_state)
    {
        case SAMPLE_FLT_FILTER_INVALID:
            result = flt_dispatch_filternextpresetcallevent_filter_invalid\
                   (p_obj, p_event);
            break;
        case SAMPLE_FLT_FILTER_ERROR:
            result = flt_dispatch_filternextpresetcallevent_filter_error(p_obj,\
                    p_event);
            break;
        case SAMPLE_FLT_FILTER_VALID:
            result = flt_dispatch_filternextpresetcallevent_filter_valid(p_obj,\
                    p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements FilterInvalidCallEvent event handling by the filter_state
 * region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterinvalidcallevent_filter_state(sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->filter_state)
    {
        case SAMPLE_FLT_FILTER_INVALID:
            result = flt_dispatch_filterinvalidcallevent_filter_invalid(p_obj,\
                    p_event);
            break;
        case SAMPLE_FLT_FILTER_ERROR:
            result = flt_dispatch_filterinvalidcallevent_filter_error(p_obj,\
                                                             p_event);
            break;
        case SAMPLE_FLT_FILTER_VALID:
            result = flt_dispatch_filterinvalidcallevent_filter_valid(p_obj,\
                                                             p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements FilterValidCallEvent event handling by the filter_state
 * region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filtervalidcallevent_filter_state(sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->filter_state)
    {
        case SAMPLE_FLT_FILTER_INVALID:
            result = flt_dispatch_filtervalidcallevent_filter_invalid(p_obj,\
                                                             p_event);
            break;
        case SAMPLE_FLT_FILTER_ERROR:
            result = flt_dispatch_filtervalidcallevent_filter_error(p_obj,\
                                                           p_event);
            break;
        case SAMPLE_FLT_FILTER_VALID:
            result = flt_dispatch_filtervalidcallevent_filter_valid(p_obj,\
                                                           p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements FilterFirstPresetCallEvent event handling by the
 * filter_state region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterfirstpresetcallevent_filter_state(sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->filter_state)
    {
        case SAMPLE_FLT_FILTER_INVALID:
        case SAMPLE_FLT_FILTER_ERROR:
            result = flt_dispatch_filterfirstpresetcallevent_filter_invalid\
                   (p_obj, p_event);
            break;
        case SAMPLE_FLT_FILTER_VALID:
            result = flt_dispatch_filterfirstpresetcallevent_filter_valid\
                   (p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements ValueOkCallEvent event handling by the value_state region
 * of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueokcallevent_value_state(sample_flt_t* const p_obj,\
                                          sample_flt_valueokcallevent_t* \
                                          /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->value_state)
    {
        case SAMPLE_FLT_VALUE_ERROR:
            result = flt_dispatch_valueokcallevent_value_error(p_obj, p_event);
            break;
        case SAMPLE_FLT_VALUE_INVALID:
            result = flt_dispatch_valueokcallevent_value_invalid(p_obj,\
                                                        p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements ValueInvalidCallEvent event handling by the value_state
 * region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueinvalidcallevent_value_state(sample_flt_t* const p_obj,\
        sample_flt_valueinvalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->value_state)
    {
        case SAMPLE_FLT_VALUE_OK:
            result = flt_dispatch_valueinvalidcallevent_value_ok(p_obj,\
                                                        p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements ValueErrorCallEvent event handling by the value_state
 * region of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueerrorcallevent_value_state(sample_flt_t* const p_obj,\
                                             sample_flt_valueerrorcallevent_t* \
                                             /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->value_state)
    {
        case SAMPLE_FLT_VALUE_INVALID:
            result = flt_dispatch_valueerrorcallevent_value_invalid(p_obj,\
                                                           p_event);
            break;
        case SAMPLE_FLT_VALUE_OK:
            result = flt_dispatch_valueerrorcallevent_value_ok(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements new_sample_call_event event handling by the INPUT_INVALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_new_sample_call_event_input_invalid(sample_flt_t* const p_obj,\
        sample_flt_new_sample_call_event_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements FilterNextPresetCallEvent event handling by the
 * FILTER_INVALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filternextpresetcallevent_filter_invalid(sample_flt_t* \
        /**/const p_obj, sample_flt_filternextpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    #error local transition execution not supported

    return result;
}
/**
 * @brief Implements FilterNextPresetCallEvent event handling by the
 * FILTER_ERROR state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filternextpresetcallevent_filter_error(sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sample_flt_inc_fail(p_obj);
    sample_flt_preset(p_obj);
    result = SAMESTATE;

    return result;
}
/**
 * @brief Implements FilterNextPresetCallEvent event handling by the
 * FILTER_VALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filternextpresetcallevent_filter_valid(sample_flt_t* const p_obj,\
        sample_flt_filternextpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements FilterInvalidCallEvent event handling by the FILTER_INVALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterinvalidcallevent_filter_invalid(sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    #error local transition execution not supported

    return result;
}
/**
 * @brief Implements FilterInvalidCallEvent event handling by the FILTER_ERROR
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterinvalidcallevent_filter_error(sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sample_flt_inc_fail(p_obj);
    sample_flt_preset(p_obj);
    result = SAMESTATE;

    return result;
}
/**
 * @brief Implements FilterInvalidCallEvent event handling by the FILTER_VALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterinvalidcallevent_filter_valid(sample_flt_t* const p_obj,\
        sample_flt_filterinvalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements FilterValidCallEvent event handling by the FILTER_INVALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filtervalidcallevent_filter_invalid(sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}
/**
 * @brief Implements FilterValidCallEvent event handling by the FILTER_ERROR
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filtervalidcallevent_filter_error(sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}
/**
 * @brief Implements FilterValidCallEvent event handling by the FILTER_VALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filtervalidcallevent_filter_valid(sample_flt_t* const p_obj,\
        sample_flt_filtervalidcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sample_flt_inc_pass(p_obj);
    sample_flt_lp(p_obj,p_obj->raw_sample);
    result = SAMESTATE;

    return result;
}

/**
 * @brief Implements FilterFirstPresetCallEvent event handling by the
 * FILTER_INVALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterfirstpresetcallevent_filter_invalid\
       (sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sample_flt_preset(p_obj);
    result = SAMESTATE;

    return result;
}
/**
 * @brief Implements FilterFirstPresetCallEvent event handling by the
 * FILTER_VALID state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_filterfirstpresetcallevent_filter_valid(sample_flt_t* const p_obj,\
        sample_flt_filterfirstpresetcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sample_flt_predict(p_obj);
    result = SAMESTATE;

    return result;
}

/**
 * @brief Implements ValueOkCallEvent event handling by the VALUE_ERROR state of
 * the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueokcallevent_value_error(sample_flt_t* const p_obj,\
                                          sample_flt_valueokcallevent_t* \
                                          /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}
/**
 * @brief Implements ValueOkCallEvent event handling by the VALUE_INVALID state
 * of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueokcallevent_value_invalid(sample_flt_t* const p_obj,\
                                            sample_flt_valueokcallevent_t* \
                                            /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements ValueInvalidCallEvent event handling by the VALUE_OK state
 * of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueinvalidcallevent_value_ok(sample_flt_t* const p_obj,\
                                            sample_flt_valueinvalidcallevent_t* \
                                            /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements ValueErrorCallEvent event handling by the VALUE_INVALID
 * state of the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueerrorcallevent_value_invalid(sample_flt_t* const p_obj,\
        sample_flt_valueerrorcallevent_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}
/**
 * @brief Implements ValueErrorCallEvent event handling by the VALUE_OK state of
 * the flt state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
flt_dispatch_valueerrorcallevent_value_ok(sample_flt_t* const p_obj,\
                                          sample_flt_valueerrorcallevent_t* \
                                          /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/*** end of file ***/
