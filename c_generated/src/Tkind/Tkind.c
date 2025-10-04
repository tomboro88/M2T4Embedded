/**
 * @file 
 * 
 * @brief The Tkind package source file.
 */

/*******************************************************************************
 * 
 * Include statements.
 * 
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "Tkind.h"
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
static void Tkind_ctest_sm1(Tkind_ctest_t* const p_obj);

static bool sm1_exit_region1(Tkind_sm1_t* const p_obj);
static bool sm1_exit_region2(Tkind_sm1_t* const p_obj);
static bool sm1_exit_region3(Tkind_sm1_t* const p_obj);
static bool sm1_exit_region4(Tkind_sm1_t* const p_obj);
static bool sm1_exit_region5(Tkind_sm1_t* const p_obj);
static bool sm1_exit_region6(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_f(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_f_t* const p_event);
static sm_event_status_t sm1_dispatch_g(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_h_t* const p_event);
static sm_event_status_t sm1_dispatch_i(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_i_t* const p_event);
static sm_event_status_t sm1_dispatch_j(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_j_t* const p_event);
static sm_event_status_t sm1_dispatch_k(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_l_t* const p_event);
static sm_event_status_t sm1_dispatch_m(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_m_t* const p_event);
static sm_event_status_t sm1_dispatch_n(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_n_t* const p_event);
static sm_event_status_t sm1_dispatch_o(Tkind_sm1_t* const p_obj,\
                                        tkind_ctest_o_t* const p_event);

static sm_event_status_t sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_f_t* const p_event);
static sm_event_status_t sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_h_t* const p_event);
static sm_event_status_t sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_n_t* const p_event);

static sm_event_status_t sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_n_t* const p_event);

static sm_event_status_t sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_h_t* const p_event);

static sm_event_status_t sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_j_t* const p_event);
static sm_event_status_t sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_l_t* const p_event);
static sm_event_status_t sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_m_t* const p_event);

static sm_event_status_t sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj,\
                                                tkind_ctest_l_t* const p_event);

static sm_event_status_t sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_f_t* const p_event);
static sm_event_status_t sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_h_t* const p_event);
static sm_event_status_t sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_i_t* const p_event);
static sm_event_status_t sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_j_t* const p_event);
static sm_event_status_t sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_l_t* const p_event);
static sm_event_status_t sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_m_t* const p_event);
static sm_event_status_t sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_n_t* const p_event);
static sm_event_status_t sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_o_t* const p_event);

static sm_event_status_t sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_f_t* const p_event);
static sm_event_status_t sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_h_t* const p_event);
static sm_event_status_t sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_n_t* const p_event);

static sm_event_status_t sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_d_t* const p_event);
static sm_event_status_t sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_e_t* const p_event);
static sm_event_status_t sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_n_t* const p_event);

static sm_event_status_t sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_g_t* const p_event);
static sm_event_status_t sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_h_t* const p_event);

static sm_event_status_t sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_j_t* const p_event);
static sm_event_status_t sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_l_t* const p_event);
static sm_event_status_t sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_m_t* const p_event);

static sm_event_status_t sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_k_t* const p_event);
static sm_event_status_t sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj,\
                                               tkind_ctest_l_t* const p_event);

static sm_event_status_t sm1_enter_choice1(Tkind_sm1_t* const p_obj);

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
sm1_enter_state1(Tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_STATE1;
    printf("Enter State1");
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state3(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE3;
    printf("Enter State3");
}

/**
 * @brief Enters the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state5(Tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_STATE5;
    printf("Enter State5");
}

/**
 * @brief Enters the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state2(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE2;
    printf("Enter State2");
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state4(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE4;
    printf("Enter State4");
}

/**
 * @brief Enters the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state6(Tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_STATE6;
    printf("Enter State6");
}

/**
 * @brief Enters the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state7(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE7;
    printf("Enter State7");
}

/**
 * @brief Enters the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state8(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE8;
    printf("Enter State8");
}

/**
 * @brief Enters the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state9(Tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_STATE9;
    printf("Enter State9");
}

/**
 * @brief Implements entry of the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region3 = TKIND_SM1_REGION3_INL;
    result = CHANGEDSTATE;
    return result;
}


/**
 * @brief Implements entry of the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region4 = TKIND_SM1_REGION4_INL;
    result = CHANGEDSTATE;
    return result;
}


/**
 * @brief Implements entry of the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region2 = TKIND_SM1_INITIAL3;
    /*debug marker uml_c_implement_transition_transit 1*/
    sm1_enter_state2(p_obj);
    result = CHANGEDSTATE;
    return result;
}


/**
 * @brief Implements entry of the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region6 = TKIND_SM1_INITIAL4;
    /*debug marker uml_c_implement_transition_transit 1*/
    sm1_enter_state9(p_obj);
    result = CHANGEDSTATE;
    return result;
}


/**
 * @brief Implements entry of the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region5 = TKIND_SM1_REGION5_INL;
    result = CHANGEDSTATE;
    return result;
}


/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the initial transition dispatch status.
 */
static inline sm_event_status_t
sm1_enter_region1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result;
    p_obj->region1 = TKIND_SM1_INITIAL1;
    /*debug marker uml_c_implement_transition_transit 1*/
    sm1_enter_state1(p_obj);
    result = CHANGEDSTATE;
    sm_event_status_t temp_status = IGNORED;
    temp_status = sm1_enter_region2(p_obj);
    result = sm_event_resolve_status(result, temp_status);
    temp_status = sm1_enter_region5(p_obj);
    result = sm_event_resolve_status(result, temp_status);
    return result;
}


/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state1(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    b_is_completed &= sm1_exit_region2(p_obj);
    b_is_completed &= sm1_exit_region5(p_obj);

    if(b_is_completed)
    {
        printf("Exit State1");
        b_is_completed &= true
    }

    return b_is_completed;
}

/**
 * @brief Exits the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state3(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    b_is_completed &= sm1_exit_region3(p_obj);

    if(b_is_completed)
    {
        printf("Exit State3");
        b_is_completed &= true
    }

    return b_is_completed;
}

/**
 * @brief Exits the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state5(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    printf("Exit State5");
    b_is_completed &= true
    return b_is_completed;
}

/**
 * @brief Exits the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state2(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    printf("Exit State2");
    b_is_completed &= true
    return b_is_completed;
}

/**
 * @brief Exits the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state4(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    b_is_completed &= sm1_exit_region4(p_obj);

    if(b_is_completed)
    {
        printf("Exit State4");
        b_is_completed &= true
    }

    return b_is_completed;
}

/**
 * @brief Exits the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state6(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    printf("Exit State6");
    b_is_completed &= true
    return b_is_completed;
}

/**
 * @brief Exits the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state7(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    printf("Exit State7");
    b_is_completed &= true
    return b_is_completed;
}

/**
 * @brief Exits the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state8(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    b_is_completed &= sm1_exit_region6(p_obj);

    if(b_is_completed)
    {
        printf("Exit State8");
        b_is_completed &= true
    }

    return b_is_completed;
}

/**
 * @brief Exits the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static inline bool
sm1_exit_state9(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;
    printf("Exit State9");
    b_is_completed &= true
    return b_is_completed;
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
Tkind_ctest_a(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_b(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_c(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_d(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_e(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_f(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_g(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_h(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_i(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_j(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_k(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_l(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_m(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_n(Tkind_ctest_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
Tkind_ctest_o(Tkind_ctest_t* const p_obj)
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
Tkind_ctest_sm1(Tkind_ctest_t* const p_obj)
{
    #warning effect Behavior type not supported
}

/**
 * @brief Exits the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region1(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            b_is_completed &= sm1_exit_state1(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region1 = TKIND_SM1_INITIAL1;

    return b_is_completed;
}

/**
 * @brief Exits the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region2(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            b_is_completed &= sm1_exit_state3(p_obj);
            break;
        case TKIND_SM1_STATE2:
            b_is_completed &= sm1_exit_state2(p_obj);
            break;
        case TKIND_SM1_STATE4:
            b_is_completed &= sm1_exit_state4(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region2 = TKIND_SM1_INITIAL3;

    return b_is_completed;
}

/**
 * @brief Exits the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region3(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            b_is_completed &= sm1_exit_state5(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region3 = TKIND_SM1_REGION3_INL;

    return b_is_completed;
}

/**
 * @brief Exits the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region4(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            b_is_completed &= sm1_exit_state6(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region4 = TKIND_SM1_REGION4_INL;

    return b_is_completed;
}

/**
 * @brief Exits the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region5(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            b_is_completed &= sm1_exit_state7(p_obj);
            break;
        case TKIND_SM1_STATE8:
            b_is_completed &= sm1_exit_state8(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region5 = TKIND_SM1_REGION5_INL;

    return b_is_completed;
}

/**
 * @brief Exits the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @return true if the exit is completed, otherwise false.
 */
static bool
sm1_exit_region6(Tkind_sm1_t* const p_obj)
{
    bool b_is_completed = true;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            b_is_completed &= sm1_exit_state9(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region6 = TKIND_SM1_INITIAL4;

    return b_is_completed;
}

/**
 * @brief Implements a event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a(Tkind_sm1_t* const p_obj, tkind_ctest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
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
sm1_dispatch_b(Tkind_sm1_t* const p_obj, tkind_ctest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
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
sm1_dispatch_c(Tkind_sm1_t* const p_obj, tkind_ctest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_c_state1(p_obj, p_event);
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
sm1_dispatch_d(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_d_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_e_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements f event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f(Tkind_sm1_t* const p_obj, tkind_ctest_f_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_f_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_g_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_h_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements i event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_i(Tkind_sm1_t* const p_obj, tkind_ctest_i_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_i_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements j event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j(Tkind_sm1_t* const p_obj, tkind_ctest_j_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_j_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_k_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_l_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements m event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m(Tkind_sm1_t* const p_obj, tkind_ctest_m_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_m_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_n_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements o event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_o(Tkind_sm1_t* const p_obj, tkind_ctest_o_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_o_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj, tkind_ctest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = sm1_dispatch_a_state2(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj, tkind_ctest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = sm1_dispatch_b_state2(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj, tkind_ctest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_c_state3(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_d_state3(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_e_state3(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements f event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj, tkind_ctest_f_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_f_state4(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_g_state4(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_h_state4(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_n_state3(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_d_state5(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_e_state5(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_n_state5(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the Region4 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = sm1_dispatch_g_state6(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the Region4 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = sm1_dispatch_h_state6(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements j event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj, tkind_ctest_j_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            result = sm1_dispatch_j_state7(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_k_state8(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_l_state8(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements m event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj, tkind_ctest_m_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_m_state8(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the Region6 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = sm1_dispatch_k_state9(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the Region6 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = sm1_dispatch_l_state9(p_obj, p_event);
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
sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj, tkind_ctest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_a_region2(p_obj, p_event);

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
sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj, tkind_ctest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_b_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements c event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj, tkind_ctest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_c_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements d event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_d_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements e event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_e_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements f event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj, tkind_ctest_f_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_f_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements g event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_g_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements h event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_h_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements i event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj, tkind_ctest_i_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state1(p_obj);
    
    if(b_is_completed)
    {
        sm1_enter_state1(p_obj);
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state7(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements j event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj, tkind_ctest_j_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_j_region5(p_obj, p_event);

    return result;
}

/**
 * @brief Implements k event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_k_region5(p_obj, p_event);

    return result;
}

/**
 * @brief Implements l event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_l_region5(p_obj, p_event);

    return result;
}

/**
 * @brief Implements m event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj, tkind_ctest_m_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_m_region5(p_obj, p_event);

    return result;
}

/**
 * @brief Implements n event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_n_region2(p_obj, p_event);

    return result;
}

/**
 * @brief Implements o event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj, tkind_ctest_o_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state1(p_obj);
    
    if(b_is_completed)
    {
        sm1_enter_state1(p_obj);
        /*debug marker uml_c_implement_transition_transit 1*/
        result = sm1_enter_choice1(p_obj);
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj, tkind_ctest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state2(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state3(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region3(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements b event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj, tkind_ctest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state2(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state4(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region4(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

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
sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj, tkind_ctest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 2*/
    bool b_is_completed = sm1_exit_region3(p_obj);
    
    if(b_is_completed)
    {
        printf("c event transition fired!");
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state5(p_obj);
        result = CHANGEDSTATE;
    }
    else
    {
        result = TRANSITION;
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
sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_d_region3(p_obj, p_event);

    return result;
}

/**
 * @brief Implements e event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_e_region3(p_obj, p_event);

    return result;
}

/**
 * @brief Implements f event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj, tkind_ctest_f_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state4(p_obj);
    
    if(b_is_completed)
    {
        sm1_enter_state4(p_obj);
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state6(p_obj);
        result = CHANGEDSTATE;
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements g event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_g_region4(p_obj, p_event);

    return result;
}

/**
 * @brief Implements h event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_h_region4(p_obj, p_event);

    return result;
}

/**
 * @brief Implements n event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_n_region3(p_obj, p_event);

    return result;
}

/**
 * @brief Implements d event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj, tkind_ctest_d_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 2*/
    bool b_is_completed = sm1_exit_region3(p_obj);
    
    if(b_is_completed)
    {
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region3(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements e event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj, tkind_ctest_e_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 2*/
    bool b_is_completed = sm1_exit_region2(p_obj);
    
    if(b_is_completed)
    {
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements n event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj, tkind_ctest_n_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state3(p_obj);
    
    if(b_is_completed)
    {
        sm1_enter_state4(p_obj);
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state6(p_obj);
        result = CHANGEDSTATE;
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements g event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj, tkind_ctest_g_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state4(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state4(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region4(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements h event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj, tkind_ctest_h_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state1(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state1(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
        temp_status = sm1_enter_region5(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements j event handling by the State7 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj, tkind_ctest_j_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state7(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state8(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region6(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements k event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_k_region6(p_obj, p_event);

    return result;
}

/**
 * @brief Implements l event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_l_region6(p_obj, p_event);

    return result;
}

/**
 * @brief Implements m event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj, tkind_ctest_m_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state1(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state1(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
        temp_status = sm1_enter_region5(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements k event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj, tkind_ctest_k_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state8(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state8(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region6(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements l event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj, tkind_ctest_l_t* const p_event)
{
    sm_event_status_t result = IGNORED;
/*debug marker uml_c_implement_state_dispatch 2*/

    /*debug marker uml_c_implement_transition_execution 3*/
    bool b_is_completed = sm1_exit_state1(p_obj);
    
    if(b_is_completed)
    {
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state1(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region2(p_obj);
        result = sm_event_resolve_status(result, temp_status);
        temp_status = sm1_enter_region5(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else
    {
        result = TRANSITION;
    }

    return result;
}

/**
 * @brief Implements entry of the Choice1 choice Pseudostate of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_enter_choice1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    /*debug marker uml_c_implement_vertex_transitions 1*/
    if(b_test_condition)
    {
    /*debug marker uml_c_implement_transition_guard 1*/
    /*debug marker uml_c_implement_transition_guard 2*/
        /*debug marker uml_c_implement_transition_transit 1*/
        sm1_enter_state8(p_obj);
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region6(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }
    else 
    {
    /*debug marker uml_c_implement_vertex_transitions 2*/
    /*debug marker uml_c_implement_vertex_transitions 3*/
        result = CHANGEDSTATE;
        sm_event_status_t temp_status = IGNORED;
        temp_status = sm1_enter_region5(p_obj);
        result = sm_event_resolve_status(result, temp_status);
    }

    return result;
}

/*** end of file ***/
