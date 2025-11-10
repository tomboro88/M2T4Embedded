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
#include <stdio.h>
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

static void sm1_exit_region1(TJunction_sm1_t* const p_obj);
static void sm1_exit_region36(TJunction_sm1_t* const p_obj);
static void sm1_exit_region431(TJunction_sm1_t* const p_obj);
static void sm1_exit_region4321(TJunction_sm1_t* const p_obj);
static void sm1_exit_region432(TJunction_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_a_t* const p_event);
static sm_event_status_t sm1_dispatch_b(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_b_t* const p_event);
static sm_event_status_t sm1_dispatch_c(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_c_t* const p_event);
static sm_event_status_t sm1_dispatch_d(TJunction_sm1_t* const p_obj,\
                                        tjunction_jtest_d_t* const p_event);

static sm_event_status_t sm1_dispatch_a_region36(TJunction_sm1_t* const p_obj,\
                                                 tjunction_jtest_a_t* \
                                                 /**/const p_event);

static sm_event_status_t sm1_dispatch_a_region431(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_a_t* \
                                                  /**/const p_event);
static sm_event_status_t sm1_dispatch_b_region431(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_b_t* \
                                                  /**/const p_event);

static sm_event_status_t sm1_dispatch_b_region4321(TJunction_sm1_t* \
                                                   /**/const p_obj,\
                                                   tjunction_jtest_b_t* \
                                                   /**/const p_event);

static sm_event_status_t sm1_dispatch_a_region432(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_a_t* \
                                                  /**/const p_event);
static sm_event_status_t sm1_dispatch_c_region432(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_c_t* \
                                                  /**/const p_event);

static sm_event_status_t sm1_dispatch_a_state1(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_a_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_a_state4(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_a_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_a_state17(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_a_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_a_state36(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_a_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_a_state43(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_a_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_b_state1(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_b_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_b_state43(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_b_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state1(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_c_t* \
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
static sm_event_status_t sm1_dispatch_c_state36(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_c_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state43(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_c_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_d_state3(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_d_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_d_state4(TJunction_sm1_t* const p_obj,\
                                               tjunction_jtest_d_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_d_state43(TJunction_sm1_t* const p_obj,\
                                                tjunction_jtest_d_t* \
                                                /**/const p_event);

static sm_event_status_t sm1_dispatch_a_state36_1(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_a_t* \
                                                  /**/const p_event);
static sm_event_status_t sm1_dispatch_a_state36_2(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_a_t* \
                                                  /**/const p_event);

static sm_event_status_t sm1_dispatch_a_state431(TJunction_sm1_t* const p_obj,\
                                                 tjunction_jtest_a_t* \
                                                 /**/const p_event);
static sm_event_status_t sm1_dispatch_b_state432(TJunction_sm1_t* const p_obj,\
                                                 tjunction_jtest_b_t* \
                                                 /**/const p_event);

static sm_event_status_t sm1_dispatch_b_state4321(TJunction_sm1_t* \
                                                  /**/const p_obj,\
                                                  tjunction_jtest_b_t* \
                                                  /**/const p_event);

static sm_event_status_t sm1_dispatch_a_state434(TJunction_sm1_t* const p_obj,\
                                                 tjunction_jtest_a_t* \
                                                 /**/const p_event);
static sm_event_status_t sm1_dispatch_c_state433(TJunction_sm1_t* const p_obj,\
                                                 tjunction_jtest_c_t* \
                                                 /**/const p_event);

static sm_event_status_t sm1_enter_choice46(TJunction_sm1_t* const p_obj);

static bool sm1_enter_junction2_a_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction2_b_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction2_c_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);

static bool sm1_enter_junction8_c_4(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction8_d_4(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction8_c_5(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction8_d_5(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);

static bool sm1_enter_junction11_4_6(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);
static bool sm1_enter_junction11_5_6(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);
static bool sm1_enter_junction11_13_12(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool sm1_enter_junction11_11_15_12(TJunction_sm1_t* const p_obj,\
                                          sm_event_status_t* const p_result);
static bool sm1_enter_junction11_14_15_12(TJunction_sm1_t* const p_obj,\
                                          sm_event_status_t* const p_result);
static bool sm1_enter_junction11_16(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool sm1_enter_junction11_17(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);

static bool sm1_enter_junction20_c_13(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction20_c_11_15(TJunction_sm1_t* const p_obj,\
                                         sm_event_status_t* const p_result);
static bool sm1_enter_junction20_c_14_15(TJunction_sm1_t* const p_obj,\
                                         sm_event_status_t* const p_result);

static bool sm1_enter_junction24_a_11(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction24_c_11(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction24_a_14(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction24_c_14(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool sm1_enter_junction31_4_18(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction31_5_18(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool sm1_enter_junction361_11_22_23(TJunction_sm1_t* const p_obj,\
                                           sm_event_status_t* const p_result);
static bool sm1_enter_junction361_14_22_23(TJunction_sm1_t* const p_obj,\
                                           sm_event_status_t* const p_result);
static bool sm1_enter_junction361_1_24_23(TJunction_sm1_t* const p_obj,\
                                          sm_event_status_t* const p_result);
static bool sm1_enter_junction361_28(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);

static bool sm1_enter_junction37_11_22(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool sm1_enter_junction37_14_22(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool sm1_enter_junction37_1_24(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool sm1_enter_junction41_a_32(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool sm1_enter_junction41_a_33(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool sm1_enter_junction4321_26_37(TJunction_sm1_t* const p_obj,\
                                         sm_event_status_t* const p_result);

static bool sm1_enter_junction431_26(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);

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
 * @brief Enters the State29 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state29(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE29;
}

/**
 * @brief Enters the State30 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state30(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE30;
}

/**
 * @brief Enters the State36 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state36(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE36;
    printf("Enter State36");
}

/**
 * @brief Enters the State36_1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state36_1(TJunction_sm1_t* const p_obj)
{
    p_obj->region36 = TJUNCTION_SM1_STATE36_1;
}

/**
 * @brief Enters the State36_2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state36_2(TJunction_sm1_t* const p_obj)
{
    p_obj->region36 = TJUNCTION_SM1_STATE36_2;
}

/**
 * @brief Enters the State43 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state43(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE43;
}

/**
 * @brief Enters the State431 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state431(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_STATE431;
}

/**
 * @brief Enters the State432 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state432(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_STATE432;
}

/**
 * @brief Enters the State4321 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state4321(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_STATE4321;
}

/**
 * @brief Enters the State4322 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state4322(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_STATE4322;
}

/**
 * @brief Enters the State433 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state433(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_STATE433;
}

/**
 * @brief Enters the State434 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_state434(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_STATE434;
    printf("State434 entry behavior.\n");
}

/**
 * @brief Implements entry of the Region36 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region36(TJunction_sm1_t* const p_obj)
{
    p_obj->region36 = TJUNCTION_SM1_REGION36_INL;
}

/**
 * @brief Implements entry of the Region4321 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region4321(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_INITIAL4321;
    sm1_enter_state4321(p_obj);
}

/**
 * @brief Implements entry of the Region431 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region431(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_INITIAL431;
    sm1_enter_state431(p_obj);
}

/**
 * @brief Implements entry of the Region432 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region432(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_INITIAL432;
    sm1_enter_state433(p_obj);
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region1(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_REGION1_INL;
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state1(TJunction_sm1_t* const p_obj)
{
    printf("Exit State1");
}

/**
 * @brief Exits the State36 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state36(TJunction_sm1_t* const p_obj)
{
    sm1_exit_region36(p_obj);
}

/**
 * @brief Exits the State36_1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state36_1(TJunction_sm1_t* const p_obj)
{
    printf("Exit State36_1");
}

/**
 * @brief Exits the State36_2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state36_2(TJunction_sm1_t* const p_obj)
{
    printf("Exit State36_2");
}

/**
 * @brief Exits the State43 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state43(TJunction_sm1_t* const p_obj)
{
    sm1_exit_region431(p_obj);
    sm1_exit_region432(p_obj);
}

/**
 * @brief Exits the State432 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state432(TJunction_sm1_t* const p_obj)
{
    sm1_exit_region4321(p_obj);
}

/**
 * @brief Exits the State4321 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state4321(TJunction_sm1_t* const p_obj)
{
    printf("Exit State4321.\n");
}

/**
 * @brief Exits the State433 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state433(TJunction_sm1_t* const p_obj)
{
    printf("Exit State433.\n");
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
    #warning effect Behavior type not supported
}

/**
 * @brief Exits the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region1(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            sm1_exit_state1(p_obj);
            break;
        case TJUNCTION_SM1_STATE36:
            sm1_exit_state36(p_obj);
            break;
        case TJUNCTION_SM1_STATE43:
            sm1_exit_state43(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region1 = TJUNCTION_SM1_REGION1_INL;
}

/**
 * @brief Exits the Region36 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region36(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region36)
    {
        case TJUNCTION_SM1_STATE36_1:
            sm1_exit_state36_1(p_obj);
            break;
        case TJUNCTION_SM1_STATE36_2:
            sm1_exit_state36_2(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region36 = TJUNCTION_SM1_REGION36_INL;
}

/**
 * @brief Exits the Region431 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region431(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE432:
            sm1_exit_state432(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region431 = TJUNCTION_SM1_INITIAL431;
}

/**
 * @brief Exits the Region4321 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region4321(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region4321)
    {
        case TJUNCTION_SM1_STATE4321:
            sm1_exit_state4321(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region4321 = TJUNCTION_SM1_INITIAL4321;
}

/**
 * @brief Exits the Region432 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region432(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE433:
            sm1_exit_state433(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region432 = TJUNCTION_SM1_INITIAL432;
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
        case TJUNCTION_SM1_STATE4:
            result = sm1_dispatch_a_state4(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE17:
            result = sm1_dispatch_a_state17(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE36:
            result = sm1_dispatch_a_state36(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE43:
            result = sm1_dispatch_a_state43(p_obj, p_event);
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
        case TJUNCTION_SM1_STATE43:
            result = sm1_dispatch_b_state43(p_obj, p_event);
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
        case TJUNCTION_SM1_STATE1:
            result = sm1_dispatch_c_state1(p_obj, p_event);
            break;
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
        case TJUNCTION_SM1_STATE36:
            result = sm1_dispatch_c_state36(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE43:
            result = sm1_dispatch_c_state43(p_obj, p_event);
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
        case TJUNCTION_SM1_STATE43:
            result = sm1_dispatch_d_state43(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region36 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_region36(TJunction_sm1_t* const p_obj,\
                        tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region36)
    {
        case TJUNCTION_SM1_STATE36_1:
            result = sm1_dispatch_a_state36_1(p_obj, p_event);
            break;
        case TJUNCTION_SM1_STATE36_2:
            result = sm1_dispatch_a_state36_2(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region431 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_region431(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE431:
            result = sm1_dispatch_a_state431(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the Region431 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_region431(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE432:
            result = sm1_dispatch_b_state432(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the Region4321 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_region4321(TJunction_sm1_t* const p_obj,\
                          tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4321)
    {
        case TJUNCTION_SM1_STATE4321:
            result = sm1_dispatch_b_state4321(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region432 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_region432(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE434:
            result = sm1_dispatch_a_state434(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the Region432 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_region432(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE433:
            result = sm1_dispatch_c_state433(p_obj, p_event);
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction2_a_1(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state4(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_a_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction24_a_11(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State17 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state17(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_a_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction24_a_14(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State36 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state36(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_a_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_a_region36(p_obj, p_event);

    return result;
}

/**
 * @brief Implements a event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state43(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = sm1_dispatch_a_region431(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = sm1_dispatch_a_region432(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction2_b_1(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements b event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state43(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_b_region431(p_obj, p_event);

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
sm1_dispatch_c_state1(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_c_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction2_c_1(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
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
sm1_dispatch_c_state3(TJunction_sm1_t* const p_obj,\
                      tjunction_jtest_c_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(p_obj->b_guard1
       && sm1_enter_junction8_c_5(p_obj, &result))
    {
    }
    else if(p_obj->b_guard6
       && sm1_enter_junction11_17(p_obj, &result))
    {
    }
    else if(sm1_enter_junction11_16(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(p_obj->b_guard2
       && sm1_enter_junction8_c_4(p_obj, &result))
    {
    }
    else if(p_obj->b_guard4)
    {
        sm1_enter_state17(p_obj);
        result = CHANGEDSTATE;
    }
    else if(sm1_enter_junction24_c_11(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction20_c_13(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction24_c_14(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State36 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state36(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction431_26(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state43(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_c_region432(p_obj, p_event);

    if(IGNORED == result)
    {
        sm1_exit_state43(p_obj);
        sm1_enter_choice46(p_obj);
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(p_obj->b_guard1
       && sm1_enter_junction8_d_5(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
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
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(p_obj->b_guard2
       && sm1_enter_junction8_d_4(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements d event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state43(TJunction_sm1_t* const p_obj,\
                       tjunction_jtest_d_t* const p_event)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state43(p_obj);
    sm1_enter_choice46(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State36_1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state36_1(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_a_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction41_a_32(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State36_2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state36_2(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_a_t* const p_event)
{
    /**
     * @todo p_event must be processed here.
     */
    (void) p_event;
    sm_event_status_t result = IGNORED;

    if(sm1_enter_junction41_a_33(p_obj, &result))
    {
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State431 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state431(TJunction_sm1_t* const p_obj,\
                        tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_enter_state432(p_obj);
    sm1_enter_region4321(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State432 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state432(TJunction_sm1_t* const p_obj,\
                        tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_b_region4321(p_obj, p_event);

    return result;
}

/**
 * @brief Implements b event handling by the State4321 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state4321(TJunction_sm1_t* const p_obj,\
                         tjunction_jtest_b_t* const p_event)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state4321(p_obj);
    sm1_enter_state4322(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State434 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state434(TJunction_sm1_t* const p_obj,\
                        tjunction_jtest_a_t* const p_event)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_enter_state433(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State433 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state433(TJunction_sm1_t* const p_obj,\
                        tjunction_jtest_c_t* const p_event)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state433(p_obj);
    sm1_enter_state434(p_obj);

    return result;
}

/**
 * @brief Implements entry of the Choice46 choice Pseudostate of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_enter_choice46(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    if(sm1_enter_junction361_28(p_obj, &result))
    {
    }
    else
    {
        sm1_enter_state43(p_obj);
        result = CHANGEDSTATE;
        sm1_enter_region431(p_obj);
        sm1_enter_region432(p_obj);
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
    bool b_is_handled = true;

    sm1_exit_state1(p_obj);
    printf("Enter junction2");
    sm1_enter_state3(p_obj);
    *p_result = CHANGEDSTATE;

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
    bool b_is_handled = true;

    sm1_exit_state1(p_obj);
    printf("Enter junction2");
    sm1_enter_state4(p_obj);
    *p_result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction2 junction Pseudostate of the sm1
 * state machine at the c event.
 * @details Transition sequence: State1, Junction2.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction2_c_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction37_1_24(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
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

    if(sm1_enter_junction31_4_18(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(sm1_enter_junction11_4_6(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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
    bool b_is_handled = true;

    printf("State4 handles event");
    sm1_enter_state17(p_obj);
    *p_result = CHANGEDSTATE;

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

    if(sm1_enter_junction31_5_18(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(sm1_enter_junction11_5_6(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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
    bool b_is_handled = true;

    printf("State3 handles event");
    sm1_enter_state17(p_obj);
    *p_result = CHANGEDSTATE;

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
sm1_enter_junction11_4_6(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("State4 handles event");
        printf("Common c event effect");
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        printf("State4 handles event");
        printf("Common c event effect");
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
sm1_enter_junction11_5_6(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("State3 handles event");
        printf("Common c event effect");
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        printf("State3 handles event");
        printf("Common c event effect");
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
sm1_enter_junction11_13_12(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
sm1_enter_junction11_11_15_12(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
sm1_enter_junction11_14_15_12(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("Action for b_guard6");
        printf("b_guard3 was true");
        sm1_enter_state12(p_obj);
    }
    else
    {
        printf("Action for b_guard6");
        sm1_enter_state13(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

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

    if(p_obj->b_guard5
       && sm1_enter_junction11_13_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        sm1_enter_state29(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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
sm1_enter_junction20_c_11_15(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5
       && sm1_enter_junction11_11_15_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        sm1_enter_state29(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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
sm1_enter_junction20_c_14_15(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5
       && sm1_enter_junction11_14_15_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        sm1_enter_state29(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction24 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State4, Junction24.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction24_a_11(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction37_11_22(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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

    if(sm1_enter_junction20_c_11_15(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction24 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State17, Junction24.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction24_a_14(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(sm1_enter_junction37_14_22(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
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

    if(sm1_enter_junction20_c_14_15(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction31 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State4, Junction8, Junction31.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction31_4_18(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard7)
    {
        printf("State4 handles event");
        printf("Common c event alternative effect");
        printf("b_guard7 was true");
        sm1_enter_state29(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard8)
    {
        printf("State4 handles event");
        printf("Common c event alternative effect");
        printf("b_guard8 was true");
        sm1_enter_state30(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction31 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State3, Junction8, Junction31.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction31_5_18(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard7)
    {
        printf("State3 handles event");
        printf("Common c event alternative effect");
        printf("b_guard7 was true");
        sm1_enter_state29(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard8)
    {
        printf("State3 handles event");
        printf("Common c event alternative effect");
        printf("b_guard8 was true");
        sm1_enter_state30(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction361 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State4, Junction24, Junction37, Junction361.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction361_11_22_23(TJunction_sm1_t* const p_obj,\
                               sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_1(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_2(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction361 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State17, Junction24, Junction37, Junction361.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction361_14_22_23(TJunction_sm1_t* const p_obj,\
                               sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_1(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_2(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction361 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State1, Junction2, Junction37, Junction361.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction361_1_24_23(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        sm1_exit_state1(p_obj);
        printf("Enter junction2");
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_1(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        sm1_exit_state1(p_obj);
        printf("Enter junction2");
        printf("Exit junction 37");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_2(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction361 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: Choice46, Junction361.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction361_28(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Chosen State36.\n");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_1(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Chosen State36.\n");
        sm1_enter_state36(p_obj);
        sm1_enter_state36_2(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction37 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State4, Junction24, Junction37.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction37_11_22(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && sm1_enter_junction361_11_22_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction37 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State17, Junction24, Junction37.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction37_14_22(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && sm1_enter_junction361_14_22_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction37 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State1, Junction2, Junction37.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction37_1_24(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && sm1_enter_junction361_1_24_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction41 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State36_1, Junction41.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction41_a_32(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    sm1_exit_state36(p_obj);
    sm1_enter_state30(p_obj);
    *p_result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction41 junction Pseudostate of the sm1
 * state machine at the a event.
 * @details Transition sequence: State36_2, Junction41.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction41_a_33(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    sm1_exit_state36(p_obj);
    sm1_enter_state30(p_obj);
    *p_result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction4321 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State36, Junction431, Junction4321.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction4321_26_37(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard7)
    {
        sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        sm1_enter_state43(p_obj);
        sm1_enter_region432(p_obj);
        printf("Go to junction4321\n");
        sm1_enter_state432(p_obj);
        sm1_enter_state4321(p_obj);
    }
    else
    {
        sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        sm1_enter_state43(p_obj);
        sm1_enter_region432(p_obj);
        printf("Go to junction4321\n");
        sm1_enter_state432(p_obj);
        sm1_enter_state4322(p_obj);
    }
    
    *p_result = CHANGEDSTATE;

    return b_is_handled;
}

/**
 * @brief Implements entry of the Junction431 junction Pseudostate of the sm1
 * state machine.
 * @details Transition sequence: State36, Junction431.
 * @param [in] p_obj The pointer to the self object.
 * @param [out] p_result The pointer to the transition execution result object.
 * @return true if the junction transition was executed.
 */
static bool
sm1_enter_junction431_26(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard6)
    {
        sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        sm1_enter_state43(p_obj);
        sm1_enter_region432(p_obj);
        printf("Exit junction431\n");
        sm1_enter_state431(p_obj);
        *p_result = CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard5
       && sm1_enter_junction4321_26_37(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = IGNORED;
    }
    
    return b_is_handled;
}

/*** end of file ***/
