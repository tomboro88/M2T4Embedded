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
/**
 * @brief The macro used to initialize a pointer to the child class from a
 * pointer to the base class.
 * @param [in] child_type The name of the child class type.
 * @param [in] base_field The name of the field of the base class.
 * @param [in] child_ptr The name of the child class target pointer.
 */
#define TKIND_CHILD_FROM_BASE(child_type,base_field,child_ptr)\
        Tkind_set_specific((char*)p_obj, \
                             offsetof(child_type,base_field), (char**)child_ptr)

/*******************************************************************************
 * 
 * Non-private function prototypes.
 * 
 ******************************************************************************/
void Tkind_cbase1_SetUintProp(Tkind_cbase1_t* const p_obj,\
                              uint32_t const param1);
uint32_t Tkind_cbase1_GetUintProp(Tkind_cbase1_t* const p_obj);

void Tkind_cbase1_set_uint_default(Tkind_cbase1_t* const p_obj,\
                                   uint32_t const param1);

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

static void Tkind_ctest_sm1(Tkind_ctest_t* const p_obj);
static float Tkind_ctest_get_flt_from_uint(Tkind_cbase2_t* const p_obj);

static void Tkind_ctest_init_df(Tkind_ctest_t* const p_obj);

static void sm1_exit_region1(Tkind_sm1_t* const p_obj);
static void sm1_exit_region2(Tkind_sm1_t* const p_obj);
static void sm1_exit_region3(Tkind_sm1_t* const p_obj);
static void sm1_exit_region4(Tkind_sm1_t* const p_obj);
static void sm1_exit_region5(Tkind_sm1_t* const p_obj);
static void sm1_exit_region6(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_b(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_c(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_d(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_f(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_g(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_i(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_j(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_k(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_m(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_o(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj);
static sm_event_status_t sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj);

static sm_event_status_t sm1_enter_choice1(Tkind_sm1_t* const p_obj);

/*******************************************************************************
 * 
 * Inline functions.
 * 
 ******************************************************************************/
/**
 * @brief Obtains the pointer to the specialized class from the pointer to
 * the base class.
 * @param [in] p_base The pointer to the base class object.
 * @param [in] base_offset The amount by which the p_base is offset 
 *     from the specific class pointer. Should be obtained using the 
 *     offsetof(specific_type, base_field_name) macro.
 * @param [out] pp_specific The pointer to the location where the 
 *     seeked pointer should be stored.
 * @return true if the searched pointer was found.
 */
static inline bool 
Tkind_set_specific(char* const p_base, size_t const base_offset,
                   char** const pp_specific)
{
    bool b_is_copied = false;

    if((NULL != pp_specific) && (NULL != p_base) 
            && (base_offset <= PTRDIFF_MAX))
    {
        *pp_specific = (p_base-((ptrdiff_t)base_offset));

        if(NULL != *pp_specific)
        {
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
sm1_enter_state1(Tkind_sm1_t* const p_obj)
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
sm1_enter_state3(Tkind_sm1_t* const p_obj)
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
sm1_enter_state5(Tkind_sm1_t* const p_obj)
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
sm1_enter_state2(Tkind_sm1_t* const p_obj)
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
sm1_enter_state4(Tkind_sm1_t* const p_obj)
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
sm1_enter_state6(Tkind_sm1_t* const p_obj)
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
sm1_enter_state7(Tkind_sm1_t* const p_obj)
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
sm1_enter_state8(Tkind_sm1_t* const p_obj)
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
sm1_enter_state9(Tkind_sm1_t* const p_obj)
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
sm1_enter_region3(Tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_REGION3_INL;
}

/**
 * @brief Implements entry of the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region4(Tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_REGION4_INL;
}

/**
 * @brief Implements entry of the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region2(Tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_INITIAL3;
    sm1_enter_state2(p_obj);
}

/**
 * @brief Implements entry of the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region6(Tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_INITIAL4;
    sm1_enter_state9(p_obj);
}

/**
 * @brief Implements entry of the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region5(Tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_REGION5_INL;
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_region1(Tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_INITIAL1;
    sm1_enter_state1(p_obj);
    sm1_enter_region2(p_obj);
    sm1_enter_region5(p_obj);
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state1(Tkind_sm1_t* const p_obj)
{
    sm1_exit_region2(p_obj);
    sm1_exit_region5(p_obj);
    (void) p_obj;
    printf("Exit State1");
}

/**
 * @brief Exits the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state3(Tkind_sm1_t* const p_obj)
{
    sm1_exit_region3(p_obj);
    (void) p_obj;
    printf("Exit State3");
}

/**
 * @brief Exits the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state5(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State5");
}

/**
 * @brief Exits the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state2(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State2");
}

/**
 * @brief Exits the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state4(Tkind_sm1_t* const p_obj)
{
    sm1_exit_region4(p_obj);
    (void) p_obj;
    printf("Exit State4");
}

/**
 * @brief Exits the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state6(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State6");
}

/**
 * @brief Exits the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state7(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State7");
}

/**
 * @brief Exits the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state8(Tkind_sm1_t* const p_obj)
{
    sm1_exit_region6(p_obj);
    (void) p_obj;
    printf("Exit State8");
}

/**
 * @brief Exits the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_exit_state9(Tkind_sm1_t* const p_obj)
{
    (void) p_obj;
    printf("Exit State9");
}

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

/*******************************************************************************
 * 
 * Public function bodies.
 * 
 ******************************************************************************/
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
    float result;
    
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

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
Tkind_ctest_set_uint_incr(Tkind_cbase1_t* const p_obj, uint32_t const param1)
{
    p_obj->Property1 = param1 + 1u;
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
 */
static void
Tkind_ctest_sm1(Tkind_ctest_t* const p_obj)
{
    #warning effect Behavior type not supported
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
    /* Check if this is really ctest class object by checking the specialized 
        virtual function table which was assigned by ctest class constructor.*/
    if((&Tkind_ctest_vtable.cbase2== p_obj->p_vtable)
        && TKIND_CHILD_FROM_BASE(Tkind_ctest_t, cbase2, &p_ctest))
    {
        /*Here the p_ctest pointer has the correct value.*/
        /*Intentionally get the value of Property1 from the other base class
           (cbase1).*/
        result = (float)p_ctest->cbase1.Property1;
    }
    
    return result;
}

/**
 * @brief Exits the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region1(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            sm1_exit_state1(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region1 = TKIND_SM1_INITIAL1;
}

/**
 * @brief Exits the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
sm1_exit_region2(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            sm1_exit_state3(p_obj);
            break;
        case TKIND_SM1_STATE2:
            sm1_exit_state2(p_obj);
            break;
        case TKIND_SM1_STATE4:
            sm1_exit_state4(p_obj);
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
sm1_exit_region3(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            sm1_exit_state5(p_obj);
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
sm1_exit_region4(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            sm1_exit_state6(p_obj);
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
sm1_exit_region5(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            sm1_exit_state7(p_obj);
            break;
        case TKIND_SM1_STATE8:
            sm1_exit_state8(p_obj);
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
sm1_exit_region6(Tkind_sm1_t* const p_obj)
{
    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            sm1_exit_state9(p_obj);
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
sm1_dispatch_a(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_a_state1(p_obj);
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
sm1_dispatch_b(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_b_state1(p_obj);
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
sm1_dispatch_c(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_c_state1(p_obj);
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
sm1_dispatch_d(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_d_state1(p_obj);
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
sm1_dispatch_e(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_e_state1(p_obj);
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
sm1_dispatch_f(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_f_state1(p_obj);
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
sm1_dispatch_g(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_g_state1(p_obj);
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
sm1_dispatch_h(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_h_state1(p_obj);
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
sm1_dispatch_i(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_i_state1(p_obj);
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
sm1_dispatch_j(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_j_state1(p_obj);
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
sm1_dispatch_k(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_k_state1(p_obj);
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
sm1_dispatch_l(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_l_state1(p_obj);
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
sm1_dispatch_m(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_m_state1(p_obj);
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
sm1_dispatch_n(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_n_state1(p_obj);
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
sm1_dispatch_o(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = sm1_dispatch_o_state1(p_obj);
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
sm1_dispatch_a_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = sm1_dispatch_a_state2(p_obj);
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
sm1_dispatch_b_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = sm1_dispatch_b_state2(p_obj);
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
sm1_dispatch_c_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_c_state3(p_obj);
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
sm1_dispatch_d_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_d_state3(p_obj);
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
sm1_dispatch_e_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_e_state3(p_obj);
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
sm1_dispatch_f_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_f_state4(p_obj);
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
sm1_dispatch_g_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_g_state4(p_obj);
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
sm1_dispatch_h_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = sm1_dispatch_h_state4(p_obj);
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
sm1_dispatch_n_region2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = sm1_dispatch_n_state3(p_obj);
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
sm1_dispatch_d_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_d_state5(p_obj);
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
sm1_dispatch_e_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_e_state5(p_obj);
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
sm1_dispatch_n_region3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = sm1_dispatch_n_state5(p_obj);
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
sm1_dispatch_g_region4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = sm1_dispatch_g_state6(p_obj);
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
sm1_dispatch_h_region4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = sm1_dispatch_h_state6(p_obj);
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
sm1_dispatch_j_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            result = sm1_dispatch_j_state7(p_obj);
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
sm1_dispatch_k_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_k_state8(p_obj);
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
sm1_dispatch_l_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_l_state8(p_obj);
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
sm1_dispatch_m_region5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = sm1_dispatch_m_state8(p_obj);
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
sm1_dispatch_k_region6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = sm1_dispatch_k_state9(p_obj);
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
sm1_dispatch_l_region6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = sm1_dispatch_l_state9(p_obj);
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
sm1_dispatch_a_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_a_region2(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_b_region2(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_c_region2(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_d_region2(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_e_region2(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_f_region2(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_g_region2(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_h_region2(p_obj);

    return result;
}

/**
 * @brief Implements i event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_i_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state1(p_obj);
    sm1_enter_state1(p_obj);
    sm1_enter_state7(p_obj);
    sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements j event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_j_region5(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_k_region5(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_l_region5(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_m_region5(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_n_region2(p_obj);

    return result;
}

/**
 * @brief Implements o event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_o_state1(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state1(p_obj);
    sm1_enter_state1(p_obj);
    sm1_enter_choice1(p_obj);
    sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_a_state2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state2(p_obj);
    sm1_enter_state3(p_obj);
    sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_b_state2(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state2(p_obj);
    sm1_enter_state4(p_obj);
    sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_c_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_region3(p_obj);
    printf("c event transition fired!");
    sm1_enter_state5(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_d_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_e_region3(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_f_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state4(p_obj);
    sm1_enter_state4(p_obj);
    sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_g_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state4(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_h_region4(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state3(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_n_region3(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_d_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_region3(p_obj);
    sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_e_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_region2(p_obj);
    sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_n_state5(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state3(p_obj);
    sm1_enter_state4(p_obj);
    sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_g_state6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state4(p_obj);
    sm1_enter_state4(p_obj);
    sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_h_state6(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state1(p_obj);
    sm1_enter_state1(p_obj);
    sm1_enter_region2(p_obj);
    sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements j event handling by the State7 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_j_state7(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state7(p_obj);
    sm1_enter_state8(p_obj);
    sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_k_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = IGNORED;

    result = sm1_dispatch_l_region6(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_m_state8(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state1(p_obj);
    sm1_enter_state1(p_obj);
    sm1_enter_region2(p_obj);
    sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_k_state9(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state8(p_obj);
    sm1_enter_state8(p_obj);
    sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_l_state9(Tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = CHANGEDSTATE;

    sm1_exit_state1(p_obj);
    sm1_enter_state1(p_obj);
    sm1_enter_region2(p_obj);
    sm1_enter_region5(p_obj);

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

    if(p_obj->b_test_condition)
    {
        sm1_enter_state8(p_obj);
        sm1_enter_region6(p_obj);
    }
    else
    {
        sm1_enter_region5(p_obj);
    }
    
    return result;
}

/*** end of file ***/
