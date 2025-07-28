/**
 * @file 
 * 
 * @brief The TJunction package source file.
 */

/*******************************************************************************
 * 
 * Include statements.
 * 
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "TJunction.h"
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/*******************************************************************************
 * 
 * Non-private function prototypes.
 * 
 ******************************************************************************/
/*******************************************************************************
 * 
 * Private function prototypes.
 * 
 ******************************************************************************/
static void TJunction_Jtest_sm1(TJunction_Jtest_t* const p_obj);


static sm_event_status_t sm1_dispatch_a(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_d_t* const p_event);


static sm_event_status_t sm1_dispatch_a_state1(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_a_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_b_state1(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_b_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state3(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_c_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state4(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_c_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state13(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_c_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state17(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_c_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_d_state3(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_d_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_d_state4(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_d_t* \
                                               /**/const p_event);

/*******************************************************************************
 * 
 * Inline functions.
 * 
 ******************************************************************************/
/**
 * @brief Enters the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state1(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE1;
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state3(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE3;
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state4(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE4;
}

/**
 * @brief Enters the State12 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state12(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE12;
}

/**
 * @brief Enters the State13 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state13(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE13;
}

/**
 * @brief Enters the State17 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state17(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE17;
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region1(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region1 = TJUNCTION_SM1_REGION1_INL;
    result = CHANGEDSTATE;
    return result;
}


/*******************************************************************************
 * 
 * Static data declarations.
 * 
 ******************************************************************************/

/*******************************************************************************
 * 
 * Public function bodies.
 * 
 ******************************************************************************/
/**
 * @param [in] p_obj The pointer to the self object.
 */
void
TJunction_Jtest_a(TJunction_Jtest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
TJunction_Jtest_b(TJunction_Jtest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
TJunction_Jtest_c(TJunction_Jtest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
TJunction_Jtest_d(TJunction_Jtest_t* const p_obj)
{
}


/*******************************************************************************
 * 
 * Non-public function bodies.
 * 
 ******************************************************************************/
/**
 */
static void
TJunction_Jtest_sm1(TJunction_Jtest_t* const p_obj)
{
    #error effect Behavior type not supported
}

/**
 * @brief Implements a event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a(TJunction_sm1_t* const p_obj, tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            result = sm1_dispatch_a_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b(TJunction_sm1_t* const p_obj, tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            result = sm1_dispatch_b_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c(TJunction_sm1_t* const p_obj, tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE3:
            result = sm1_dispatch_c_state3(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE4:
            result = sm1_dispatch_c_state4(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE13:
            result = sm1_dispatch_c_state13(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE17:
            result = sm1_dispatch_c_state17(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d(TJunction_sm1_t* const p_obj, tjunction_jtest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE3:
            result = sm1_dispatch_d_state3(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE4:
            result = sm1_dispatch_d_state4(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}


/**
 * @brief Implements a event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state1(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_enter_junction2(p_obj);
    result = CHANGEDSTATE;

    return result;
}

/**
 * @brief Implements b event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state1(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_enter_junction2(p_obj);
    result = CHANGEDSTATE;

    return result;
}

/**
 * @brief Implements c event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state3(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(b_guard1
       && sm1_enter_junction8_c_5(p_obj, &result))
    {
    }
    else if(b_guard6
       && sm1_enter_junction11_17(p_obj, &result))
    {
    }
    else 
    {
        sm1_enter_junction11(p_obj);
        result = CHANGEDSTATE;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state4(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(b_guard2
       && sm1_enter_junction8_c_4(p_obj, &result))
    {
    }
    else if(b_guard4)
    {
        sm1_enter_state17(p_obj);
        result = CHANGEDSTATE;
    }
    else if(sm1_enter_junction24_c_11(p_obj, &result))
    {
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements c event handling by the State13 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state13(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction20_c_13(p_obj, &result))
    {
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements c event handling by the State17 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state17(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction24_c_14(p_obj, &result))
    {
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements d event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state3(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(b_guard1
       && sm1_enter_junction8_d_5(p_obj, &result))
    {
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements d event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state4(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(b_guard2
       && sm1_enter_junction8_d_4(p_obj, &result))
    {
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements entry of the Junction2 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State1, Junction2.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction2_a_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    sm1_enter_state3(p_obj);
    result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction2 junction Pseudostate of the sm1
 * state machine at the b event.
 * @details Transition sequence: State1, Junction2.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction2_b_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    sm1_enter_state4(p_obj);
    result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction8 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State4, Junction8.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction8_c_4(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction11_46(p_obj, p_result))
    {
    }
    else 
    {
        printf("Common c event effect");
        sm1_enter_junction11(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction8 junction Pseudostate of the sm1
 * state machine at the d event.
 * @details Transition sequence: State4, Junction8.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction8_d_4(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    sm1_enter_state17(p_obj);
    result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction8 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State3, Junction8.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction8_c_5(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction11_56(p_obj, p_result))
    {
    }
    else 
    {
        printf("Common c event effect");
        sm1_enter_junction11(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction8 junction Pseudostate of the sm1
 * state machine at the d event.
 * @details Transition sequence: State3, Junction8.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction8_d_5(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    sm1_enter_state17(p_obj);
    result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State4, Junction8, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_46(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State3, Junction8, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_56(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}


/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State13, Junction20, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_1312(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State4, Junction24, Junction20, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_111512(TJunction_sm1_t* const p_obj,\
                            sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State17, Junction24, Junction20, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_141512(TJunction_sm1_t* const p_obj,\
                            sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}



/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State3, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_16(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction11 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State3, Junction11.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction11_17(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
        result = CHANGEDSTATE;
    }
    else 
    {
        sm1_enter_state13(p_obj);
        result = CHANGEDSTATE;
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction20 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State13, Junction20.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction20_c_13(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard5
       && sm1_enter_junction11_1312(p_obj, p_result))
    {
    }
    else 
    {
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction20 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State4, Junction24, Junction20.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction20_c_1115(TJunction_sm1_t* const p_obj,\
                            sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard5
       && sm1_enter_junction11_111512(p_obj, p_result))
    {
    }
    else 
    {
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction20 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State17, Junction24, Junction20.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction20_c_1415(TJunction_sm1_t* const p_obj,\
                            sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(b_guard5
       && sm1_enter_junction11_141512(p_obj, p_result))
    {
    }
    else 
    {
    }

    return b_is_handled;
}


/**
 * @brief Implements entry of the Junction24 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State4, Junction24.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction24_c_11(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction20_c_1115(p_obj, p_result))
    {
    }
    else 
    {
    }

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction24 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State17, Junction24.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction24_c_14(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction20_c_1415(p_obj, p_result))
    {
    }
    else 
    {
    }

    return b_is_handled;
}


/*** end of file ***/
