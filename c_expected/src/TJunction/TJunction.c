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
static void TJunction_Jtest_invoke_sm1(TJunction_Jtest_t* const p_obj);

static void TJunction_sm1_exit_region36(TJunction_sm1_t* const p_obj);
static void TJunction_sm1_exit_region431(TJunction_sm1_t* const p_obj);
static void TJunction_sm1_exit_region4321(TJunction_sm1_t* const p_obj);
static void TJunction_sm1_exit_region432(TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a(TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_b(TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c(TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_d(TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_region36(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_region431(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_b_region431(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_b_region4321(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_region432(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_region432(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_state1(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_a_state4(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_a_state17(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_a_state36(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_a_state43(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_b_state1(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_b_state43(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state1(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state3(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state4(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state13(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state17(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state36(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state43(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_d_state3(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_d_state4(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_d_state43(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_state36_1(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_a_state36_2(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_state431(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_b_state432(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_b_state4321(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_dispatch_a_state434(
                                                  TJunction_sm1_t* const p_obj);
static sm_event_status_t TJunction_sm1_dispatch_c_state433(
                                                  TJunction_sm1_t* const p_obj);

static sm_event_status_t TJunction_sm1_enter_choice46(
                                                  TJunction_sm1_t* const p_obj);

static bool TJunction_sm1_enter_junction2_a_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction2_b_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction2_c_1(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction8_c_4(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction8_d_4(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction8_c_5(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction8_d_5(TJunction_sm1_t* const p_obj,\
                                    sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction11_4_6(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_5_6(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_13_12(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_11_15_12(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_14_15_12(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_16(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction11_17(TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction20_c_13(TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction20_c_11_15(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction20_c_14_15(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction24_a_11(TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction24_c_11(TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction24_a_14(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction24_c_14(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction31_4_18(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction31_5_18(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction361_11_22_23(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction361_14_22_23(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction361_1_24_23(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction361_28(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction37_11_22(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction37_14_22(TJunction_sm1_t* const p_obj,\
                                       sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction37_1_24(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction41_a_32(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);
static bool TJunction_sm1_enter_junction41_a_33(TJunction_sm1_t* const p_obj,\
                                      sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction4321_26_37(
                                             TJunction_sm1_t* const p_obj,\
                                             sm_event_status_t* const p_result);

static bool TJunction_sm1_enter_junction431_26(TJunction_sm1_t* const p_obj,\
                                     sm_event_status_t* const p_result);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
        TJunction_Jtest_fifo_sizes[TJUNCTION_JTEST_EVENT_COUNT] =
        {
                TJUNCTION_JTEST_A_CNT,
                TJUNCTION_JTEST_B_CNT,
                TJUNCTION_JTEST_C_CNT,
                TJUNCTION_JTEST_D_CNT
        };
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
TJunction_sm1_enter_state1(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE1;
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state3(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE3;
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state4(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE4;
}

/**
 * @brief Enters the State12 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state12(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE12;
}

/**
 * @brief Enters the State13 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state13(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE13;
}

/**
 * @brief Enters the State17 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state17(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE17;
}

/**
 * @brief Enters the State29 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state29(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE29;
}

/**
 * @brief Enters the State30 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state30(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE30;
}

/**
 * @brief Enters the State36 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state36(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE36;
    (void) p_obj;
    printf("Enter State36");
}

/**
 * @brief Enters the State36_1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state36_1(TJunction_sm1_t* const p_obj)
{
    p_obj->region36 = TJUNCTION_SM1_STATE36_1;
}

/**
 * @brief Enters the State36_2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state36_2(TJunction_sm1_t* const p_obj)
{
    p_obj->region36 = TJUNCTION_SM1_STATE36_2;
}

/**
 * @brief Enters the State43 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state43(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_STATE43;
}

/**
 * @brief Enters the State431 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state431(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_STATE431;
}

/**
 * @brief Enters the State432 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state432(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_STATE432;
}

/**
 * @brief Enters the State4321 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state4321(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_STATE4321;
}

/**
 * @brief Enters the State4322 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state4322(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_STATE4322;
}

/**
 * @brief Enters the State433 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state433(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_STATE433;
}

/**
 * @brief Enters the State434 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_state434(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_STATE434;
    (void) p_obj;
    printf("State434 entry behavior.\n");
}

/**
 * @brief Implements entry of the Region4321 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_region4321(TJunction_sm1_t* const p_obj)
{
    p_obj->region4321 = TJUNCTION_SM1_INITIAL4321;
    TJunction_sm1_enter_state4321(p_obj);
}

/**
 * @brief Implements entry of the Region431 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_region431(TJunction_sm1_t* const p_obj)
{
    p_obj->region431 = TJUNCTION_SM1_INITIAL431;
    TJunction_sm1_enter_state431(p_obj);
}

/**
 * @brief Implements entry of the Region432 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_region432(TJunction_sm1_t* const p_obj)
{
    p_obj->region432 = TJUNCTION_SM1_INITIAL432;
    TJunction_sm1_enter_state433(p_obj);
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_enter_region1(TJunction_sm1_t* const p_obj)
{
    p_obj->region1 = TJUNCTION_SM1_INITIAL49;
    TJunction_sm1_enter_state1(p_obj);
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state1(TJunction_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State1");
}

/**
 * @brief Exits the State36 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state36(TJunction_sm1_t* const p_obj)
{
    TJunction_sm1_exit_region36(p_obj);
}

/**
 * @brief Exits the State36_1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state36_1(TJunction_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State36_1");
}

/**
 * @brief Exits the State36_2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state36_2(TJunction_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State36_2");
}

/**
 * @brief Exits the State43 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state43(TJunction_sm1_t* const p_obj)
{
    TJunction_sm1_exit_region431(p_obj);
    TJunction_sm1_exit_region432(p_obj);
}

/**
 * @brief Exits the State432 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state432(TJunction_sm1_t* const p_obj)
{
    TJunction_sm1_exit_region4321(p_obj);
}

/**
 * @brief Exits the State4321 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state4321(TJunction_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State4321.\n");
}

/**
 * @brief Exits the State433 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
TJunction_sm1_exit_state433(TJunction_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State433.\n");
}

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief The constructor of the Jtest class.
 */
bool
TJunction_Jtest_init(TJunction_Jtest_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        fifo_initialize((&p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_A].fifo),
                        TJUNCTION_JTEST_A_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_A].p_next_events
                                              = p_obj->event_pool.a_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_B].fifo),
                        TJUNCTION_JTEST_B_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_B].p_next_events
                                              = p_obj->event_pool.b_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_C].fifo),
                        TJUNCTION_JTEST_C_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_C].p_next_events
                                              = p_obj->event_pool.c_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_D].fifo),
                        TJUNCTION_JTEST_D_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TJUNCTION_JTEST_D].p_next_events
                                              = p_obj->event_pool.d_next_events;

        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = TJUNCTION_JTEST_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};

        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = event_pool_initialize(&p_obj->event_pool.manager,
                                             p_obj->event_pool.fifo_pool,
                                             TJunction_Jtest_fifo_sizes,
                                             TJUNCTION_JTEST_EVENT_COUNT);
        /* Initialize the state machine. */
        TJunction_Jtest_invoke_sm1(p_obj);
    }

    return b_is_created;
}
/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
TJunction_Jtest_a(TJunction_Jtest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TJUNCTION_JTEST_A);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
TJunction_Jtest_b(TJunction_Jtest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TJUNCTION_JTEST_B);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
TJunction_Jtest_c(TJunction_Jtest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TJUNCTION_JTEST_C);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
TJunction_Jtest_d(TJunction_Jtest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TJUNCTION_JTEST_D);
    }

    return b_is_added;
}

/**
 * @brief Fetches the first event pending in the event pool.
 * @details This function is separated to allow the user to call it from
 * an enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object.
 * @returns true, when an event was fetched from the event pool and is waiting
 * for processing.
 * @returns false, when the event pool is empty, or the p_obj is NULL.
 */
bool
TJunction_Jtest_fetch_event(TJunction_Jtest_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                            (event_pool_locator_t)
                            {.event_type = TJUNCTION_JTEST_EVENT_COUNT,
                             .event_index = (~((fifo_size_t) 0u))};
                b_is_new_event =
                    event_pool_get_first_head(&p_obj->event_pool.manager,
                                              &p_obj->event_pool.fetched_event);
                break;
            case SM_EVENT_STATUS_PENDING:
                b_is_new_event = true;
                break;
            default:
                break;
        }

        if(b_is_new_event)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_PENDING;
        }
    }

    return b_is_new_event;
}

/**
 * @brief Executes the proper action corresponding to the event fetched from
 * the event pool.
 * @details This function was separated from the other two (*fetch* and
 * *release*) functions, because in normal scenario this function doesn't need
 * to be called from a critical section. Since the event at the head of the
 * event pool has already been fetched, no action on the event pool is able to
 * modify the event data contents. Because the event data is still in the event
 * pool, there is no need for an additional temporary buffer for keeping a copy
 * of the event data (which could be troublesome due to separate data types for
 * each event).
 * To access the required event data it is enough to use information in the
 * 'event_pool.fetched_event' field. This approach saves memory and improves
 * speed due to no need of event data copying.
 */
bool
TJunction_Jtest_dispatch_event(TJunction_Jtest_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
            && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case TJUNCTION_JTEST_A:
                temp_status = TJunction_sm1_dispatch_a(&p_obj->sm1);
                break;
            case TJUNCTION_JTEST_B:
                temp_status = TJunction_sm1_dispatch_b(&p_obj->sm1);
                break;
            case TJUNCTION_JTEST_C:
                temp_status = TJunction_sm1_dispatch_c(&p_obj->sm1);
                break;
            case TJUNCTION_JTEST_D:
                temp_status = TJunction_sm1_dispatch_d(&p_obj->sm1);
                break;
            default:
                break;
        }

        p_obj->event_pool.event_proc_status = temp_status;
        b_is_new_event = true;
    }

    return b_is_new_event;
}

/**
 * @brief Removes the processed event from the event pool.
 * @details This function is separated to allow the user to call it from
 * an enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object of the Jtest class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in
 * the event pool.
 */
bool
TJunction_Jtest_release_event(TJunction_Jtest_t* const p_obj)
{
    bool b_is_released = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING < p_obj->event_pool.event_proc_status)
        && (SM_EVENT_STATUS_DISPATCHED > p_obj->event_pool.event_proc_status))
    {
        b_is_released = event_pool_dequeue(&p_obj->event_pool.manager);

        if(b_is_released)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        }
    }

    return b_is_released;
}
/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/**
 * @brief Brings the sm1 state machine to the initial state.
 */
static void
TJunction_Jtest_invoke_sm1(TJunction_Jtest_t* const p_obj)
{
    p_obj->sm1.p_context  = p_obj;
    p_obj->sm1.region1    = TJUNCTION_SM1_INITIAL49;
    p_obj->sm1.region36   = TJUNCTION_SM1_REGION36_INL;
    p_obj->sm1.region431  = TJUNCTION_SM1_INITIAL431;
    p_obj->sm1.region432  = TJUNCTION_SM1_INITIAL432;
    p_obj->sm1.region4321 = TJUNCTION_SM1_INITIAL4321;
    p_obj->sm1.b_guard1   = false;
    p_obj->sm1.b_guard2   = false;
    p_obj->sm1.b_guard3   = false;
    p_obj->sm1.b_guard4   = false;
    p_obj->sm1.b_guard5   = false;
    p_obj->sm1.b_guard6   = false;
    p_obj->sm1.b_guard7   = false;
    p_obj->sm1.b_guard8   = false;
    p_obj->sm1.b_guard9   = false;

    TJunction_sm1_enter_region1(&p_obj->sm1);
}

/**
 * @brief Exits the Region36 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
TJunction_sm1_exit_region36(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region36)
    {
        case TJUNCTION_SM1_STATE36_1:
            TJunction_sm1_exit_state36_1(p_obj);
            break;
        case TJUNCTION_SM1_STATE36_2:
            TJunction_sm1_exit_state36_2(p_obj);
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
TJunction_sm1_exit_region431(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE432:
            TJunction_sm1_exit_state432(p_obj);
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
TJunction_sm1_exit_region4321(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region4321)
    {
        case TJUNCTION_SM1_STATE4321:
            TJunction_sm1_exit_state4321(p_obj);
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
TJunction_sm1_exit_region432(TJunction_sm1_t* const p_obj)
{
    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE433:
            TJunction_sm1_exit_state433(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            result = TJunction_sm1_dispatch_a_state1(p_obj);
            break;
        case TJUNCTION_SM1_STATE4:
            result = TJunction_sm1_dispatch_a_state4(p_obj);
            break;
        case TJUNCTION_SM1_STATE17:
            result = TJunction_sm1_dispatch_a_state17(p_obj);
            break;
        case TJUNCTION_SM1_STATE36:
            result = TJunction_sm1_dispatch_a_state36(p_obj);
            break;
        case TJUNCTION_SM1_STATE43:
            result = TJunction_sm1_dispatch_a_state43(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            result = TJunction_sm1_dispatch_b_state1(p_obj);
            break;
        case TJUNCTION_SM1_STATE43:
            result = TJunction_sm1_dispatch_b_state43(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE1:
            result = TJunction_sm1_dispatch_c_state1(p_obj);
            break;
        case TJUNCTION_SM1_STATE3:
            result = TJunction_sm1_dispatch_c_state3(p_obj);
            break;
        case TJUNCTION_SM1_STATE4:
            result = TJunction_sm1_dispatch_c_state4(p_obj);
            break;
        case TJUNCTION_SM1_STATE13:
            result = TJunction_sm1_dispatch_c_state13(p_obj);
            break;
        case TJUNCTION_SM1_STATE17:
            result = TJunction_sm1_dispatch_c_state17(p_obj);
            break;
        case TJUNCTION_SM1_STATE36:
            result = TJunction_sm1_dispatch_c_state36(p_obj);
            break;
        case TJUNCTION_SM1_STATE43:
            result = TJunction_sm1_dispatch_c_state43(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_d(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TJUNCTION_SM1_STATE3:
            result = TJunction_sm1_dispatch_d_state3(p_obj);
            break;
        case TJUNCTION_SM1_STATE4:
            result = TJunction_sm1_dispatch_d_state4(p_obj);
            break;
        case TJUNCTION_SM1_STATE43:
            result = TJunction_sm1_dispatch_d_state43(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_region36(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region36)
    {
        case TJUNCTION_SM1_STATE36_1:
            result = TJunction_sm1_dispatch_a_state36_1(p_obj);
            break;
        case TJUNCTION_SM1_STATE36_2:
            result = TJunction_sm1_dispatch_a_state36_2(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_region431(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE431:
            result = TJunction_sm1_dispatch_a_state431(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_region431(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region431)
    {
        case TJUNCTION_SM1_STATE432:
            result = TJunction_sm1_dispatch_b_state432(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_region4321(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4321)
    {
        case TJUNCTION_SM1_STATE4321:
            result = TJunction_sm1_dispatch_b_state4321(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_region432(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE434:
            result = TJunction_sm1_dispatch_a_state434(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_region432(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region432)
    {
        case TJUNCTION_SM1_STATE433:
            result = TJunction_sm1_dispatch_c_state433(p_obj);
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
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state1(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction2_a_1(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state4(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction24_a_11(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State17 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state17(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction24_a_14(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State36 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state36(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = TJunction_sm1_dispatch_a_region36(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state43(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;
    sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

    temp_status = TJunction_sm1_dispatch_a_region431(p_obj);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = TJunction_sm1_dispatch_a_region432(p_obj);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements b event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_state1(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction2_b_1(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements b event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_state43(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = TJunction_sm1_dispatch_b_region431(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state1(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction2_c_1(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state3(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(p_obj->b_guard1
       && TJunction_sm1_enter_junction8_c_5(p_obj, &result))
    {
    }
    else if(p_obj->b_guard6
       && TJunction_sm1_enter_junction11_17(p_obj, &result))
    {
    }
    else if(TJunction_sm1_enter_junction11_16(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state4(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(p_obj->b_guard2
       && TJunction_sm1_enter_junction8_c_4(p_obj, &result))
    {
    }
    else if(p_obj->b_guard4)
    {
        TJunction_sm1_enter_state17(p_obj);
        result = SM_EVENT_STATUS_CHANGEDSTATE;
    }
    else if(TJunction_sm1_enter_junction24_c_11(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State13 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state13(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction20_c_13(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State17 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state17(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction24_c_14(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State36 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state36(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction431_26(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements c event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state43(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = TJunction_sm1_dispatch_c_region432(p_obj);

    if(SM_EVENT_STATUS_IGNORED == result)
    {
        TJunction_sm1_exit_state43(p_obj);
        TJunction_sm1_enter_choice46(p_obj);
    }

    return result;
}

/**
 * @brief Implements d event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_d_state3(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(p_obj->b_guard1
       && TJunction_sm1_enter_junction8_d_5(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements d event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_d_state4(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(p_obj->b_guard2
       && TJunction_sm1_enter_junction8_d_4(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements d event handling by the State43 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_d_state43(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    TJunction_sm1_exit_state43(p_obj);
    TJunction_sm1_enter_choice46(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State36_1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state36_1(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction41_a_32(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State36_2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state36_2(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(TJunction_sm1_enter_junction41_a_33(p_obj, &result))
    {
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State431 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state431(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    TJunction_sm1_enter_state432(p_obj);
    TJunction_sm1_enter_region4321(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State432 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_state432(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = TJunction_sm1_dispatch_b_region4321(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State4321 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_b_state4321(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    TJunction_sm1_exit_state4321(p_obj);
    TJunction_sm1_enter_state4322(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State434 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_a_state434(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    TJunction_sm1_enter_state433(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State433 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_dispatch_c_state433(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    TJunction_sm1_exit_state433(p_obj);
    TJunction_sm1_enter_state434(p_obj);

    return result;
}

/**
 * @brief Implements entry of the Choice46 choice Pseudostate of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
TJunction_sm1_enter_choice46(TJunction_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    if(TJunction_sm1_enter_junction361_28(p_obj, &result))
    {
    }
    else
    {
        TJunction_sm1_enter_state43(p_obj);
        result = SM_EVENT_STATUS_CHANGEDSTATE;
        TJunction_sm1_enter_region431(p_obj);
        TJunction_sm1_enter_region432(p_obj);
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
TJunction_sm1_enter_junction2_a_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    TJunction_sm1_exit_state1(p_obj);
    printf("Enter junction2");
    TJunction_sm1_enter_state3(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction2_b_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    TJunction_sm1_exit_state1(p_obj);
    printf("Enter junction2");
    TJunction_sm1_enter_state4(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction2_c_1(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction37_1_24(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction8_c_4(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction31_4_18(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(TJunction_sm1_enter_junction11_4_6(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction8_d_4(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    printf("State4 handles event");
    TJunction_sm1_enter_state17(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction8_c_5(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction31_5_18(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(TJunction_sm1_enter_junction11_5_6(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction8_d_5(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    printf("State3 handles event");
    TJunction_sm1_enter_state17(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_4_6(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("State4 handles event");
        printf("Common c event effect");
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        printf("State4 handles event");
        printf("Common c event effect");
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_5_6(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("State3 handles event");
        printf("Common c event effect");
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        printf("State3 handles event");
        printf("Common c event effect");
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_13_12(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_11_15_12(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_14_15_12(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_16(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction11_17(TJunction_sm1_t* const p_obj,\
                        sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard3)
    {
        printf("Action for b_guard6");
        printf("b_guard3 was true");
        TJunction_sm1_enter_state12(p_obj);
    }
    else
    {
        printf("Action for b_guard6");
        TJunction_sm1_enter_state13(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction20_c_13(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5
       && TJunction_sm1_enter_junction11_13_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        TJunction_sm1_enter_state29(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction20_c_11_15(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5
       && TJunction_sm1_enter_junction11_11_15_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        TJunction_sm1_enter_state29(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction20_c_14_15(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5
       && TJunction_sm1_enter_junction11_14_15_12(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else if(p_obj->b_guard9)
    {
        printf("b_guard9 was true");
        TJunction_sm1_enter_state29(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction24_a_11(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction37_11_22(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction24_c_11(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction20_c_11_15(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction24_a_14(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction37_14_22(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction24_c_14(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(TJunction_sm1_enter_junction20_c_14_15(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction31_4_18(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard7)
    {
        printf("State4 handles event");
        printf("Common c event alternative effect");
        printf("b_guard7 was true");
        TJunction_sm1_enter_state29(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard8)
    {
        printf("State4 handles event");
        printf("Common c event alternative effect");
        printf("b_guard8 was true");
        TJunction_sm1_enter_state30(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction31_5_18(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard7)
    {
        printf("State3 handles event");
        printf("Common c event alternative effect");
        printf("b_guard7 was true");
        TJunction_sm1_enter_state29(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard8)
    {
        printf("State3 handles event");
        printf("Common c event alternative effect");
        printf("b_guard8 was true");
        TJunction_sm1_enter_state30(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction361_11_22_23(TJunction_sm1_t* const p_obj,\
                               sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_1(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_2(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction361_14_22_23(TJunction_sm1_t* const p_obj,\
                               sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_1(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_2(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction361_1_24_23(TJunction_sm1_t* const p_obj,\
                              sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        TJunction_sm1_exit_state1(p_obj);
        printf("Enter junction2");
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_1(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        TJunction_sm1_exit_state1(p_obj);
        printf("Enter junction2");
        printf("Exit junction 37");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_2(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction361_28(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard5)
    {
        printf("Chosen State36.\n");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_1(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard6)
    {
        printf("Chosen State36.\n");
        TJunction_sm1_enter_state36(p_obj);
        TJunction_sm1_enter_state36_2(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction37_11_22(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && TJunction_sm1_enter_junction361_11_22_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction37_14_22(TJunction_sm1_t* const p_obj,\
                           sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && TJunction_sm1_enter_junction361_14_22_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction37_1_24(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard4
       && TJunction_sm1_enter_junction361_1_24_23(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
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
TJunction_sm1_enter_junction41_a_32(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    TJunction_sm1_exit_state36(p_obj);
    TJunction_sm1_enter_state30(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction41_a_33(TJunction_sm1_t* const p_obj,\
                          sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    TJunction_sm1_exit_state36(p_obj);
    TJunction_sm1_enter_state30(p_obj);
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction4321_26_37(TJunction_sm1_t* const p_obj,\
                             sm_event_status_t* const p_result)
{
    bool b_is_handled = true;

    if(p_obj->b_guard7)
    {
        TJunction_sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        TJunction_sm1_enter_state43(p_obj);
        TJunction_sm1_enter_region432(p_obj);
        printf("Go to junction4321\n");
        TJunction_sm1_enter_state432(p_obj);
        TJunction_sm1_enter_state4321(p_obj);
    }
    else
    {
        TJunction_sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        TJunction_sm1_enter_state43(p_obj);
        TJunction_sm1_enter_region432(p_obj);
        printf("Go to junction4321\n");
        TJunction_sm1_enter_state432(p_obj);
        TJunction_sm1_enter_state4322(p_obj);
    }
    
    *p_result = SM_EVENT_STATUS_CHANGEDSTATE;

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
TJunction_sm1_enter_junction431_26(TJunction_sm1_t* const p_obj,\
                         sm_event_status_t* const p_result)
{
    bool b_is_handled = false;

    if(p_obj->b_guard6)
    {
        TJunction_sm1_exit_state36(p_obj);
        printf("Execute c event from State36");
        TJunction_sm1_enter_state43(p_obj);
        TJunction_sm1_enter_region432(p_obj);
        printf("Exit junction431\n");
        TJunction_sm1_enter_state431(p_obj);
        *p_result = SM_EVENT_STATUS_CHANGEDSTATE;
        b_is_handled = true;
    }
    else if(p_obj->b_guard5
       && TJunction_sm1_enter_junction4321_26_37(p_obj, p_result))
    {
        b_is_handled = true;
    }
    else
    {
        *p_result = SM_EVENT_STATUS_IGNORED;
    }
    
    return b_is_handled;
}

/*** end of file ***/
