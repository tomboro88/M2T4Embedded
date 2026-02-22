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
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
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
void Tkind_cbase1_set_uint_default(Tkind_cbase1_t* const p_obj,\
                                   uint32_t const param1);

void Tkind_ctest_set_uint_incr(Tkind_cbase1_t* const p_obj,\
                               uint32_t const param1);

/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void Tkind_cbase1_init_df(Tkind_cbase1_t* const p_obj);

static float Tkind_cbase2_get_flt_dflt(Tkind_cbase2_t* const p_obj);

static void Tkind_cbase2_init_df(Tkind_cbase2_t* const p_obj);

static void Tkind_ctest_invoke_sm1(Tkind_ctest_t* const p_obj);
static float Tkind_ctest_get_flt_from_uint(Tkind_cbase2_t* const p_obj);

static void Tkind_ctest_init_df(Tkind_ctest_t* const p_obj);

static void Tkind_sm1_exit_region2(Tkind_sm1_t* const p_obj);
static void Tkind_sm1_exit_region3(Tkind_sm1_t* const p_obj);
static void Tkind_sm1_exit_region4(Tkind_sm1_t* const p_obj);
static void Tkind_sm1_exit_region5(Tkind_sm1_t* const p_obj);
static void Tkind_sm1_exit_region6(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_a(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_b(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_c(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_d(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_f(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_g(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_i(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_j(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_k(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_m(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_o(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj);
static sm_event_status_t Tkind_sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj);

static sm_event_status_t Tkind_sm1_enter_choice1(Tkind_sm1_t* const p_obj);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief The initialized virtual table for the Tkind_cbase1_s struct.
 */
static const Tkind_cbase1_vt_t Tkind_cbase1_vtable = 
{
    .p_SetUintProp                   = Tkind_cbase1_set_uint_default
};

/**
 * @brief The initialized virtual table for the Tkind_cbase2_s struct.
 */
static const Tkind_cbase2_vt_t Tkind_cbase2_vtable = 
{
    .p_GetFloatProp                  = Tkind_cbase2_get_flt_dflt
};

/**
 * @brief The initialized virtual table for the Tkind_ctest_s struct.
 */
static const Tkind_ctest_vt_t Tkind_ctest_vtable = 
{
    .cbase1.p_SetUintProp            = Tkind_ctest_set_uint_incr,
    .cbase2.p_GetFloatProp           = Tkind_ctest_get_flt_from_uint
};

/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
Tkind_ctest_fifo_sizes[TKIND_CTEST_EVENT_COUNT] =
{
        TKIND_CTEST_I_CNT,
        TKIND_CTEST_O_CNT,
        TKIND_CTEST_A_CNT,
        TKIND_CTEST_B_CNT,
        TKIND_CTEST_C_CNT,
        TKIND_CTEST_F_CNT,
        TKIND_CTEST_E_CNT,
        TKIND_CTEST_D_CNT,
        TKIND_CTEST_N_CNT,
        TKIND_CTEST_H_CNT,
        TKIND_CTEST_G_CNT,
        TKIND_CTEST_J_CNT,
        TKIND_CTEST_M_CNT,
        TKIND_CTEST_K_CNT,
        TKIND_CTEST_L_CNT
};
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/**
 * @brief Obtains the pointer to the specialized ctest class from the pointer to
 * the cbase2 class.
 * @param [out] pp_ctest The pointer to the location where the
 *                       seeked child pointer should be stored.
 * @param [in] p_cbase2 The pointer to the base class object.
 * @return true if the searched pointer was found and stored in the target
 * pointer.
 */
static inline bool
Tkind_cbase2_try_as_ctest(Tkind_cbase2_t* const p_cbase2,
                          Tkind_ctest_t** const pp_ctest)
{
    bool b_is_copied = false;

    /* Check if this is really ctest class object by checking the specialized
         virtual function table which was assigned by ctest class constructor.*/
    if((NULL != pp_ctest) && (NULL != p_cbase2)
            && (offsetof(Tkind_ctest_t, cbase2) <= (uintptr_t)p_cbase2)
            && (&Tkind_ctest_vtable.cbase2 == p_cbase2->p_vtable))
    {
        Tkind_ctest_t* p_temp = (Tkind_ctest_t*)((uintptr_t)p_cbase2
                                             - offsetof(Tkind_ctest_t, cbase2));
        if(NULL != p_temp)
        {
            *pp_ctest = p_temp;
            b_is_copied = true;
        }
    }

    return b_is_copied;
}

/**
 * @brief Enters the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state1(Tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_STATE1;
    (void) p_obj;
    printf("Enter State1");
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state3(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE3;
    (void) p_obj;
    printf("Enter State3");
}

/**
 * @brief Enters the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state5(Tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_STATE5;
    (void) p_obj;
    printf("Enter State5");
}

/**
 * @brief Enters the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state2(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE2;
    (void) p_obj;
    printf("Enter State2");
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state4(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE4;
    (void) p_obj;
    printf("Enter State4");
}

/**
 * @brief Enters the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state6(Tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_STATE6;
    (void) p_obj;
    printf("Enter State6");
}

/**
 * @brief Enters the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state7(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE7;
    (void) p_obj;
    printf("Enter State7");
}

/**
 * @brief Enters the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state8(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE8;
    (void) p_obj;
    printf("Enter State8");
}

/**
 * @brief Enters the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_state9(Tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_STATE9;
    (void) p_obj;
    printf("Enter State9");
}

/**
 * @brief Implements entry of the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_region3(Tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_REGION3_INL;
}

/**
 * @brief Implements entry of the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_region4(Tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_REGION4_INL;
}

/**
 * @brief Implements entry of the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_region2(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_INITIAL3;
    Tkind_sm1_enter_state2(p_obj);
}

/**
 * @brief Implements entry of the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_region6(Tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_INITIAL4;
    Tkind_sm1_enter_state9(p_obj);
}

/**
 * @brief Implements entry of the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_enter_region5(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_REGION5_INL;
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_Tkind_sm1_enter_region1(Tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_INITIAL1;
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_region2(p_obj);
    Tkind_sm1_enter_region5(p_obj);
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state1(Tkind_sm1_t* const p_obj)
{
    Tkind_sm1_exit_region2(p_obj);
    Tkind_sm1_exit_region5(p_obj);
    (void) p_obj;
    printf("Exit State1");
}

/**
 * @brief Exits the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state3(Tkind_sm1_t* const p_obj)
{
    Tkind_sm1_exit_region3(p_obj);
    (void) p_obj;
    printf("Exit State3");
}

/**
 * @brief Exits the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state5(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State5");
}

/**
 * @brief Exits the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state2(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State2");
}

/**
 * @brief Exits the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state4(Tkind_sm1_t* const p_obj)
{
    Tkind_sm1_exit_region4(p_obj);
    (void) p_obj;
    printf("Exit State4");
}

/**
 * @brief Exits the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state6(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State6");
}

/**
 * @brief Exits the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state7(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State7");
}

/**
 * @brief Exits the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state8(Tkind_sm1_t* const p_obj)
{
    Tkind_sm1_exit_region6(p_obj);
    (void) p_obj;
    printf("Exit State8");
}

/**
 * @brief Exits the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
Tkind_sm1_exit_state9(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State9");
}

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief The initialization function of the cbase1 class.
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_cbase1_init(Tkind_cbase1_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        Tkind_cbase1_init_df(p_obj);
        b_is_created = true;
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1
 */
void
Tkind_cbase1_SetUintProp(Tkind_cbase1_t* const p_obj, uint32_t const param1)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_SetUintProp)(Tkind_cbase1_t* const p_obj,\
                              uint32_t const param1)
            = p_obj->p_vtable->p_SetUintProp;

        if(NULL != p_SetUintProp)
        {
            p_SetUintProp(p_obj, param1);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
uint32_t
Tkind_cbase1_GetUintProp(Tkind_cbase1_t* const p_obj)
{
    return p_obj->Property1;
}

/**
 * @brief The initialization function of the cbase2 class.
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_cbase2_init(Tkind_cbase2_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        Tkind_cbase2_init_df(p_obj);
        b_is_created = true;
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
Tkind_cbase2_SetFloatProp(Tkind_cbase2_t* const p_obj, float const param1)
{
    p_obj->Property1 = param1;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
float
Tkind_cbase2_GetFloatProp(Tkind_cbase2_t* const p_obj)
{
    float result = 0.0;
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        float (*p_GetFloatProp)(Tkind_cbase2_t* const p_obj)
            = p_obj->p_vtable->p_GetFloatProp;

        if(NULL != p_GetFloatProp)
        {
            result = p_GetFloatProp(p_obj);
        }
    }

    return result;
}

/**
 * @brief The initialization function of the ctest class.
 * @param p_obj The pointer to the object that should be initialized.
 */
bool
Tkind_ctest_init(Tkind_ctest_t* const p_obj)
{
    bool b_is_created = false;

    if((NULL != p_obj) && Tkind_cbase1_init(&p_obj->cbase1)
            && Tkind_cbase2_init(&p_obj->cbase2))
    {
        Tkind_ctest_init_df(p_obj);
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_I].fifo),
                        TKIND_CTEST_I_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_I].p_next_events
                                              = p_obj->event_pool.i_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_O].fifo),
                        TKIND_CTEST_O_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_O].p_next_events
                                              = p_obj->event_pool.o_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_A].fifo),
                        TKIND_CTEST_A_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_A].p_next_events
                                              = p_obj->event_pool.a_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_B].fifo),
                        TKIND_CTEST_B_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_B].p_next_events
                                              = p_obj->event_pool.b_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_C].fifo),
                        TKIND_CTEST_C_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_C].p_next_events
                                              = p_obj->event_pool.c_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_F].fifo),
                        TKIND_CTEST_F_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_F].p_next_events
                                              = p_obj->event_pool.f_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_E].fifo),
                        TKIND_CTEST_E_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_E].p_next_events
                                              = p_obj->event_pool.e_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_D].fifo),
                        TKIND_CTEST_D_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_D].p_next_events
                                              = p_obj->event_pool.d_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_N].fifo),
                        TKIND_CTEST_N_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_N].p_next_events
                                              = p_obj->event_pool.n_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_H].fifo),
                        TKIND_CTEST_H_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_H].p_next_events
                                              = p_obj->event_pool.h_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_G].fifo),
                        TKIND_CTEST_G_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_G].p_next_events
                                              = p_obj->event_pool.g_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_J].fifo),
                        TKIND_CTEST_J_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_J].p_next_events
                                              = p_obj->event_pool.j_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_M].fifo),
                        TKIND_CTEST_M_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_M].p_next_events
                                              = p_obj->event_pool.m_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_K].fifo),
                        TKIND_CTEST_K_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_K].p_next_events
                                              = p_obj->event_pool.k_next_events;

        fifo_initialize((&p_obj->event_pool.fifo_pool[TKIND_CTEST_L].fifo),
                        TKIND_CTEST_L_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_L].p_next_events
                                              = p_obj->event_pool.l_next_events;

        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = TKIND_CTEST_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};

        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = event_pool_initialize(&p_obj->event_pool.manager,
                                             p_obj->event_pool.fifo_pool,
                                             Tkind_ctest_fifo_sizes,
                                             TKIND_CTEST_EVENT_COUNT);
        /* Initialize the state machine. */
        Tkind_ctest_invoke_sm1(p_obj);
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_a(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_A);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_b(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_B);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_c(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_C);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_d(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_D);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_e(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_E);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_f(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_F);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_g(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_G);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_h(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_H);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_i(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_I);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_j(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_J);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_k(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_K);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_l(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_L);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_m(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_M);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_n(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_N);
    }

    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
Tkind_ctest_o(Tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;

    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_O);
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
Tkind_ctest_fetch_event(Tkind_ctest_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                            (event_pool_locator_t)
                            {.event_type = TKIND_CTEST_EVENT_COUNT,
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
 * 'event_pool.fetched_event' field. This approach saves memory and has no need
 * of event data copying, but may be only a little slower when accessing the
 * event data due to retrieving information from the 'event_pool.fetched_event'
 * field.
 * @returns true when a fetched event was waiting for processing
 * @returns false when there was no event waiting for processing or the p_obj
 * was NULL.
 */
bool
Tkind_ctest_dispatch_event(Tkind_ctest_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
            && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case TKIND_CTEST_I:
                temp_status = Tkind_sm1_dispatch_i(&p_obj->sm1);
                break;
            case TKIND_CTEST_O:
                temp_status = Tkind_sm1_dispatch_o(&p_obj->sm1);
                break;
            case TKIND_CTEST_A:
                temp_status = Tkind_sm1_dispatch_a(&p_obj->sm1);
                break;
            case TKIND_CTEST_B:
                temp_status = Tkind_sm1_dispatch_b(&p_obj->sm1);
                break;
            case TKIND_CTEST_C:
                temp_status = Tkind_sm1_dispatch_c(&p_obj->sm1);
                break;
            case TKIND_CTEST_F:
                temp_status = Tkind_sm1_dispatch_f(&p_obj->sm1);
                break;
            case TKIND_CTEST_E:
                temp_status = Tkind_sm1_dispatch_e(&p_obj->sm1);
                break;
            case TKIND_CTEST_D:
                temp_status = Tkind_sm1_dispatch_d(&p_obj->sm1);
                break;
            case TKIND_CTEST_N:
                temp_status = Tkind_sm1_dispatch_n(&p_obj->sm1);
                break;
            case TKIND_CTEST_H:
                temp_status = Tkind_sm1_dispatch_h(&p_obj->sm1);
                break;
            case TKIND_CTEST_G:
                temp_status = Tkind_sm1_dispatch_g(&p_obj->sm1);
                break;
            case TKIND_CTEST_J:
                temp_status = Tkind_sm1_dispatch_j(&p_obj->sm1);
                break;
            case TKIND_CTEST_M:
                temp_status = Tkind_sm1_dispatch_m(&p_obj->sm1);
                break;
            case TKIND_CTEST_K:
                temp_status = Tkind_sm1_dispatch_k(&p_obj->sm1);
                break;
            case TKIND_CTEST_L:
                temp_status = Tkind_sm1_dispatch_l(&p_obj->sm1);
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
 * @param [in] p_obj The pointer to the self object of the ctest class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in
 * the event pool.
 */
bool
Tkind_ctest_release_event(Tkind_ctest_t* const p_obj)
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
 * @brief The initializer function of the default values and virtual tables of
 * the Tkind_cbase1_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_cbase1_init_df(Tkind_cbase1_t* const p_obj)
{
    p_obj->p_vtable                  = &Tkind_cbase1_vtable;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
Tkind_cbase1_set_uint_default(Tkind_cbase1_t* const p_obj,\
                              uint32_t const param1)
{
    p_obj->Property1 = param1;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the Tkind_cbase2_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_cbase2_init_df(Tkind_cbase2_t* const p_obj)
{
    p_obj->p_vtable                  = &Tkind_cbase2_vtable;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static float
Tkind_cbase2_get_flt_dflt(Tkind_cbase2_t* const p_obj)
{
    return p_obj->Property1;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the Tkind_ctest_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_ctest_init_df(Tkind_ctest_t* const p_obj)
{
    p_obj->pi                        = TKIND_PI_LITERAL_CONSTANT;
    p_obj->cbase1.p_vtable           = &Tkind_ctest_vtable.cbase1;
    p_obj->cbase2.p_vtable           = &Tkind_ctest_vtable.cbase2;
}

/**
 * @brief Initializes the sm1 state machine.
 * @details According to UML, the state machine must be invoked first, which
 * will lead to its initialization and execution of the initial transition.
 * @param p_obj The pointer to the ctest context object for which the state
 * machine should be initialized.
 */
static void
Tkind_ctest_invoke_sm1(Tkind_ctest_t* const p_obj)
{
    p_obj->sm1.p_context             = p_obj;
    p_obj->sm1.region1               = TKIND_SM1_INITIAL1;
    p_obj->sm1.region2               = TKIND_SM1_INITIAL3;
    p_obj->sm1.region3               = TKIND_SM1_REGION3_INL;
    p_obj->sm1.region4               = TKIND_SM1_REGION4_INL;
    p_obj->sm1.region5               = TKIND_SM1_REGION5_INL;
    p_obj->sm1.region6               = TKIND_SM1_INITIAL4;
    p_obj->sm1.b_test_condition      = false;

    /* Execute the initial transition.*/
    Tkind_Tkind_sm1_enter_region1(&p_obj->sm1);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1
 */
void
Tkind_ctest_set_uint_incr(Tkind_cbase1_t* const p_obj, uint32_t const param1)
{
    p_obj->Property1 = param1 + 1u;
}

/**
 * @brief Implementation of virtual function GetFloatProp () from the cbase2
 * class.
 * @details It shows how a pointer to a base class can be converted to a pointer
 * to a child class.
 * After the pointer conversion, it returns the Property1 value of the another
 * base class (cbase1).
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static float
Tkind_ctest_get_flt_from_uint(Tkind_cbase2_t* const p_obj)
{
    float result = 0.0f;
    Tkind_ctest_t* p_ctest = NULL;

    if(Tkind_cbase2_try_as_ctest(p_obj, &p_ctest))
    {
        /*Here the p_ctest pointer has the correct value.*/
        /*Intentionally get the value of Property1 from the other base class
           (cbase1).*/
        result = (float)p_ctest->cbase1.Property1;
    }
    
    return result;
}

/**
 * @brief Exits the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_sm1_exit_region2(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            Tkind_sm1_exit_state3(p_obj);
            break;
        case TKIND_SM1_STATE2:
            Tkind_sm1_exit_state2(p_obj);
            break;
        case TKIND_SM1_STATE4:
            Tkind_sm1_exit_state4(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region2 = TKIND_SM1_INITIAL3;
}

/**
 * @brief Exits the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_sm1_exit_region3(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            Tkind_sm1_exit_state5(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region3 = TKIND_SM1_REGION3_INL;
}

/**
 * @brief Exits the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_sm1_exit_region4(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            Tkind_sm1_exit_state6(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region4 = TKIND_SM1_REGION4_INL;
}

/**
 * @brief Exits the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_sm1_exit_region5(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            Tkind_sm1_exit_state7(p_obj);
            break;
        case TKIND_SM1_STATE8:
            Tkind_sm1_exit_state8(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region5 = TKIND_SM1_REGION5_INL;
}

/**
 * @brief Exits the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
Tkind_sm1_exit_region6(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            Tkind_sm1_exit_state9(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region6 = TKIND_SM1_INITIAL4;
}

/**
 * @brief Implements a event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_a(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_a_state1(p_obj);
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
Tkind_sm1_dispatch_b(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_b_state1(p_obj);
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
Tkind_sm1_dispatch_c(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_c_state1(p_obj);
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
Tkind_sm1_dispatch_d(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_d_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_e_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements f event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_f(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_f_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_g_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_h_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements i event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_i(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_i_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements j event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_j(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_j_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_k_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_l_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements m event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_m(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_m_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_n_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements o event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_o(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = Tkind_sm1_dispatch_o_state1(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = Tkind_sm1_dispatch_a_state2(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = Tkind_sm1_dispatch_b_state2(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = Tkind_sm1_dispatch_c_state3(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = Tkind_sm1_dispatch_d_state3(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = Tkind_sm1_dispatch_e_state3(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = Tkind_sm1_dispatch_f_state4(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = Tkind_sm1_dispatch_g_state4(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = Tkind_sm1_dispatch_h_state4(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = Tkind_sm1_dispatch_n_state3(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = Tkind_sm1_dispatch_d_state5(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = Tkind_sm1_dispatch_e_state5(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = Tkind_sm1_dispatch_n_state5(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = Tkind_sm1_dispatch_g_state6(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = Tkind_sm1_dispatch_h_state6(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            result = Tkind_sm1_dispatch_j_state7(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = Tkind_sm1_dispatch_k_state8(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = Tkind_sm1_dispatch_l_state8(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = Tkind_sm1_dispatch_m_state8(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = Tkind_sm1_dispatch_k_state9(p_obj);
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
 * return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = Tkind_sm1_dispatch_l_state9(p_obj);
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
Tkind_sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_a_region2(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_b_region2(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_c_region2(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_d_region2(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_e_region2(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_f_region2(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_g_region2(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_h_region2(p_obj);

    return result;
}

/**
 * @brief Implements i event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state1(p_obj);
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_state7(p_obj);
    Tkind_sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements j event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_j_region5(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_k_region5(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_l_region5(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_m_region5(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_n_region2(p_obj);

    return result;
}

/**
 * @brief Implements o event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state1(p_obj);
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_choice1(p_obj);
    Tkind_sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state2(p_obj);
    Tkind_sm1_enter_state3(p_obj);
    Tkind_sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state2(p_obj);
    Tkind_sm1_enter_state4(p_obj);
    Tkind_sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_region3(p_obj);
    printf("c event transition fired!");
    Tkind_sm1_enter_state5(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_d_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_e_region3(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state4(p_obj);
    Tkind_sm1_enter_state4(p_obj);
    Tkind_sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_g_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_h_region4(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_n_region3(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_region3(p_obj);
    Tkind_sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_region2(p_obj);
    Tkind_sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state3(p_obj);
    Tkind_sm1_enter_state4(p_obj);
    Tkind_sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state4(p_obj);
    Tkind_sm1_enter_state4(p_obj);
    Tkind_sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state1(p_obj);
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_region2(p_obj);
    Tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements j event handling by the State7 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state7(p_obj);
    Tkind_sm1_enter_state8(p_obj);
    Tkind_sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_k_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = Tkind_sm1_dispatch_l_region6(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state1(p_obj);
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_region2(p_obj);
    Tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state8(p_obj);
    Tkind_sm1_enter_state8(p_obj);
    Tkind_sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    Tkind_sm1_exit_state1(p_obj);
    Tkind_sm1_enter_state1(p_obj);
    Tkind_sm1_enter_region2(p_obj);
    Tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements entry of the Choice1 choice Pseudostate of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
Tkind_sm1_enter_choice1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    if(p_obj->b_test_condition)
    {
        Tkind_sm1_enter_state8(p_obj);
        Tkind_sm1_enter_region6(p_obj);
    }
    else
    {
        Tkind_sm1_enter_region5(p_obj);
    }
    
    return result;
}

/*** end of file ***/
