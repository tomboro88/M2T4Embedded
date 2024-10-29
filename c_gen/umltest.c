/**
 * @file 
 * 
 * @brief The umltest package source file.
 */

/*******************************************************************************
 * 
 * Include statements.
 * 
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "umltest.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/**
 */
#define UMLTEST_DEFAULT_COEFF 0.25

/**
 * @brief The macro used to initialize a pointer to the child class from a
 * pointer to the base class.
 * @param [in] child_type The name of the child class type.
 * @param [in] base_field The name of the field of the base class.
 * @param [in] child_ptr The name of the child class target pointer.
 */
#define UMLTEST_CHILD_FROM_BASE(child_type,base_field,child_ptr)\
        umltest_set_specific((char*)p_obj, \
                             offsetof(child_type,base_field), (char**)child_ptr)

/**
 * @brief The virtual table type for the umltest_app_s struct.
 */
typedef struct umltest_app_vt_s \
        umltest_app_vt_t;

/**
 * @brief The type representing the umltest_app_s struct.
 */
typedef struct umltest_app_s \
        umltest_app_t;

/**
 * @brief The type representing the umltest_efsm_s struct.
 */
typedef struct umltest_efsm_s \
        umltest_efsm_t;

/**
 * @brief The type representing the umltest_exitbhv_test_sm_s struct.
 */
typedef struct umltest_exitbhv_test_sm_s \
        umltest_exitbhv_test_sm_t;

/**
 * @brief The type representing the umltest_nested_sm_s struct.
 */
typedef struct umltest_nested_sm_s \
        umltest_nested_sm_t;

/**
 * @brief The type representing the umltest_sment_s struct.
 */
typedef struct umltest_sment_s \
        umltest_sment_t;

/**
 */
struct umltest_app_s
{
    /**
     * @brief flt base class data.
     */
    sample_flt_t                    flt;
    /**
     */
    float32_t                       coefficient;
};

/**
 * @brief The virtual table struct for the umltest_app_s struct. Contains
 * pointers to all virtual methods of the class.
 */
struct umltest_app_vt_s
{
    /**
     * flt base class virtual table.
     */
    sample_flt_vt_t                 flt;
};

/**
 * @brief The enumeration of all substates of Region1 Region of efsm
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region1 Region of efsm StateMachine.
     */
    UMLTEST_EFSM_INITIAL1,
    /**
     */
    UMLTEST_EFSM_R1S1,
    /**
     */
    UMLTEST_EFSM_R1S2,
    /**
     */
    UMLTEST_EFSM_FINALSTATE4,
    /**
     * @brief The number of all substates of Region1 Region of efsm
     * StateMachine.
     */
    UMLTEST_EFSM_REGION1_SIZE
}umltest_efsm_region1_t;

/**
 */
struct umltest_efsm_s
{
    /**
     */
    umltest_efsm_region1_t          region1;
};

/**
 * @brief The enumeration of all substates of Region1 Region of exitbhv_test_sm
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region1 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_INITIAL3,
    /**
     */
    UMLTEST_EXITBHV_TEST_SM_R1S1,
    /**
     * @brief A pseudostate reserved for execution of the entry behavior of the
     * R1S2 state.
     */
    UMLTEST_EXITBHV_TEST_SM_R1S2_ENTRY,
    /**
     */
    UMLTEST_EXITBHV_TEST_SM_R1S2,
    /**
     */
    UMLTEST_EXITBHV_TEST_SM_FINALSTATE6,
    /**
     * @brief The number of all substates of Region1 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_REGION1_SIZE
}umltest_exitbhv_test_sm_region1_t;

/**
 * @brief The enumeration of all substates of Region3 Region of exitbhv_test_sm
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region3 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_REGION3_INITIAL,
    /**
     */
    UMLTEST_EXITBHV_TEST_SM_R3S1,
    /**
     * @brief The number of all substates of Region3 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_REGION3_SIZE
}umltest_exitbhv_test_sm_region3_t;

/**
 * @brief The enumeration of all substates of Region2 Region of exitbhv_test_sm
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region2 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_REGION2_INITIAL,
    /**
     * @brief A pseudostate reserved for execution of the entry behavior of the
     * R2S1 state.
     */
    UMLTEST_EXITBHV_TEST_SM_R2S1_ENTRY,
    /**
     */
    UMLTEST_EXITBHV_TEST_SM_R2S1,
    /**
     * @brief The number of all substates of Region2 Region of exitbhv_test_sm
     * StateMachine.
     */
    UMLTEST_EXITBHV_TEST_SM_REGION2_SIZE
}umltest_exitbhv_test_sm_region2_t;

/**
 * @param [in] p_obj The pointer to the self object.
 */
struct umltest_exitbhv_test_sm_s
{
    /**
     */
    umltest_exitbhv_test_sm_region1_t \
                                    region1;
    /**
     */
    umltest_exitbhv_test_sm_region3_t \
                                    region3;
    /**
     */
    umltest_exitbhv_test_sm_region2_t \
                                    region2;
};

/**
 * @brief The enumeration of all substates of Region1 Region of nested_sm
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region1 Region of nested_sm
     * StateMachine.
     */
    UMLTEST_NESTED_SM_INITIAL2,
    /**
     */
    UMLTEST_NESTED_SM_STATE1,
    /**
     */
    UMLTEST_NESTED_SM_STATE3,
    /**
     */
    UMLTEST_NESTED_SM_FINALSTATE4,
    /**
     * @brief The number of all substates of Region1 Region of nested_sm
     * StateMachine.
     */
    UMLTEST_NESTED_SM_REGION1_SIZE
}umltest_nested_sm_region1_t;

/**
 * @param [in] p_obj The pointer to the self object.
 */
struct umltest_nested_sm_s
{
    /**
     */
    umltest_nested_sm_region1_t     region1;
};

/**
 * @brief The enumeration of all substates of Region1 Region of sment
 * StateMachine.
 */
typedef enum{
    /**
     * @brief The default substate of the Region1 Region of sment StateMachine.
     */
    UMLTEST_SMENT_INITIAL4,
    /**
     */
    UMLTEST_SMENT_R1S1,
    /**
     */
    UMLTEST_SMENT_R1S2,
    /**
     */
    UMLTEST_SMENT_FINALSTATE3,
    /**
     * @brief The number of all substates of Region1 Region of sment
     * StateMachine.
     */
    UMLTEST_SMENT_REGION1_SIZE
}umltest_sment_region1_t;

/**
 * @param [in] p_obj The pointer to the self object.
 */
struct umltest_sment_s
{
    /**
     */
    umltest_sment_region1_t         region1;
};

/*******************************************************************************
 * 
 * Non-private function prototypes.
 * 
 ******************************************************************************/
extern void sample_flt_lp(sample_flt_t* const p_obj, float32_t const filter_in);

extern void sample_flt_lp_bhv(sample_flt_t* const p_obj,\
                              float32_t const filter_in);

umltest_app_t* umltest_app_create_coeff(umltest_app_t* const p_obj,\
                                        float32_t const coeff);

void umltest_emotor_start_bhv(umltest_iface_t* const p_obj);
void umltest_emotor_stop_bhv(umltest_iface_t* const p_obj);

void umltest_engine_accel_bhv(umltest_iface_t* const p_obj);
void umltest_engine_start_bhv(umltest_iface_t* const p_obj);

void umltest_hybrid_start_bhv(umltest_iface_t* const p_obj);

void umltest_propulsion_stop_bhv(umltest_iface_t* const p_obj);

/*******************************************************************************
 * 
 * Private function prototypes.
 * 
 ******************************************************************************/
static void umltest_app_lp_bh(sample_flt_t* const p_obj,\
                              float32_t const filter_in);

static void umltest_tmpCombo_sm1(umltest_tmpCombo_t* const p_obj);

static void umltest_app_init_df(umltest_app_t* const p_obj);
static void umltest_classtmp_init_df(umltest_classtmp_t* const p_obj);
static void umltest_emotor_init_df(umltest_emotor_t* const p_obj);
static void umltest_engine_init_df(umltest_engine_t* const p_obj);
static void umltest_hybrid_init_df(umltest_hybrid_t* const p_obj);
static void umltest_propulsion_init_df(umltest_propulsion_t* const p_obj);
static void umltest_tmpCombo_init_df(umltest_tmpCombo_t* const p_obj);
static void umltest_tmpHybrid_init_df(umltest_tmpHybrid_t* const p_obj);

static void sm1_exit_region1(umltest_sm1_t* const p_obj,\
                             umltest_sm1_region1_t const exit_state);
static void sm1_exit_region3(umltest_sm1_t* const p_obj,\
                             umltest_sm1_region3_t const exit_state);
static void sm1_exit_region4(umltest_sm1_t* const p_obj,\
                             umltest_sm1_region4_t const exit_state);

static sm_event_status_t efsm_dispatch_call_flip(umltest_efsm_t* const p_obj,\
                                                 umltest_tmpcombo_call_flip_t* \
                                                 /**/const p_event);
static sm_event_status_t efsm_dispatch_callflap(umltest_efsm_t* const p_obj,\
                                                umltest_tmpcombo_callflap_t* \
                                                /**/const p_event);


static sm_event_status_t efsm_dispatch_callflap_r1s2\
       (umltest_efsm_t* const p_obj,\
        umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t efsm_dispatch_call_flip_r1s1\
       (umltest_efsm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

static sm_event_status_t exitbhv_test_sm_dispatch_callflap\
       (umltest_exitbhv_test_sm_t* const p_obj,\
        umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t exitbhv_test_sm_dispatch_call_flip\
       (umltest_exitbhv_test_sm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

static sm_event_status_t exitbhv_test_sm_dispatch_call_flip_region2\
       (umltest_exitbhv_test_sm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

static sm_event_status_t exitbhv_test_sm_dispatch_call_flip_r1s2\
       (umltest_exitbhv_test_sm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);
static sm_event_status_t exitbhv_test_sm_dispatch_callflap_r1s1\
       (umltest_exitbhv_test_sm_t* const p_obj,\
        umltest_tmpcombo_callflap_t* const p_event);


static sm_event_status_t nested_sm_dispatch_call_flip\
       (umltest_nested_sm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);


static sm_event_status_t nested_sm_dispatch_call_flip_state1\
       (umltest_nested_sm_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

static sm_event_status_t sm1_dispatch_call_flip(umltest_sm1_t* const p_obj,\
                                                umltest_tmpcombo_call_flip_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_callflap(umltest_sm1_t* const p_obj,\
                                               umltest_tmpcombo_callflap_t* \
                                               /**/const p_event);
static sm_event_status_t sm1_dispatch_call_flop(umltest_sm1_t* const p_obj,\
                                                umltest_tmpcombo_call_flop_t* \
                                                /**/const p_event);
static sm_event_status_t sm1_dispatch_flupcalevt(umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flupcalevt_t* const p_event);
static sm_event_status_t sm1_dispatch_flepcallevt(umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flepcallevt_t* const p_event);

static sm_event_status_t sm1_dispatch_callflap_region3\
       (umltest_sm1_t* const p_obj, umltest_tmpcombo_callflap_t* const p_event);

static sm_event_status_t sm1_dispatch_callflap_region4\
       (umltest_sm1_t* const p_obj, umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t sm1_dispatch_flepcallevt_region4\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flepcallevt_t* const p_event);
static sm_event_status_t sm1_dispatch_call_flip_region4\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

static sm_event_status_t sm1_dispatch_callflap_subflop2\
       (umltest_sm1_t* const p_obj, umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t sm1_dispatch_callflap_flip(umltest_sm1_t* \
        /**/const p_obj, umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t sm1_dispatch_flepcallevt_flip\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flepcallevt_t* const p_event);
static sm_event_status_t sm1_dispatch_call_flop_subflop2\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_call_flop_t* const p_event);
static sm_event_status_t sm1_dispatch_call_flop_flip\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_call_flop_t* const p_event);
static sm_event_status_t sm1_dispatch_call_flip_flop\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);
static sm_event_status_t sm1_dispatch_call_flip_flip\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);
static sm_event_status_t sm1_dispatch_flupcalevt_flip\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flupcalevt_t* const p_event);

static sm_event_status_t sm1_dispatch_callflap_subflip\
       (umltest_sm1_t* const p_obj, umltest_tmpcombo_callflap_t* const p_event);

static sm_event_status_t sm1_dispatch_callflap_subflip2\
       (umltest_sm1_t* const p_obj, umltest_tmpcombo_callflap_t* const p_event);
static sm_event_status_t sm1_dispatch_flepcallevt_subflip3\
       (umltest_sm1_t* const p_obj,\
        umltest_tmpcombo_flepcallevt_t* const p_event);

static sm_event_status_t sment_dispatch_call_flip(umltest_sment_t* \
        /**/const p_obj, umltest_tmpcombo_call_flip_t* const p_event);


static sm_event_status_t sment_dispatch_call_flip_r1s1\
       (umltest_sment_t* const p_obj,\
        umltest_tmpcombo_call_flip_t* const p_event);

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
umltest_set_specific(char* const p_base, size_t const base_offset,
                     char** const pp_specific)
{
    bool b_is_copied = false;

    if((NULL != pp_specific) && (NULL != p_base) 
            && (base_offset <= PTRDIFF_MAX))
    {
        *pp_specific = (&p_base[-((ptrdiff_t)base_offset)]);
        b_is_copied = true;
    }

    return b_is_copied;
}

/**
 * @brief Enters the R1S1 state of the efsm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
efsm_enter_r1s1(umltest_efsm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EFSM_R1S1;
}

/**
 * @brief Enters the R1S2 state of the efsm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
efsm_enter_r1s2(umltest_efsm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EFSM_R1S2;
}

/**
 * @brief Enters the FinalState4 state of the efsm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
efsm_enter_finalstate4(umltest_efsm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EFSM_FINALSTATE4;
}

/**
 * @brief Enters the R1S1 state of the exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
exitbhv_test_sm_enter_r1s1(umltest_exitbhv_test_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EXITBHV_TEST_SM_R1S1;
}

/**
 * @brief Enters the R1S2 state of the exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
exitbhv_test_sm_enter_r1s2(umltest_exitbhv_test_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EXITBHV_TEST_SM_R1S2;
    
}

/**
 * @brief Enters the R3S1 state of the exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
exitbhv_test_sm_enter_r3s1(umltest_exitbhv_test_sm_t* const p_obj)
{
    p_obj->region3 = UMLTEST_EXITBHV_TEST_SM_R3S1;
}

/**
 * @brief Enters the R2S1 state of the exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
exitbhv_test_sm_enter_r2s1(umltest_exitbhv_test_sm_t* const p_obj)
{
    p_obj->region2 = UMLTEST_EXITBHV_TEST_SM_R2S1;
    
}

/**
 * @brief Enters the FinalState6 state of the exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
exitbhv_test_sm_enter_finalstate6(umltest_exitbhv_test_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_EXITBHV_TEST_SM_FINALSTATE6;
}

/**
 * @brief Enters the State1 state of the nested_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
nested_sm_enter_state1(umltest_nested_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_NESTED_SM_STATE1;
}

/**
 * @brief Enters the State3 state of the nested_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
nested_sm_enter_state3(umltest_nested_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_NESTED_SM_STATE3;
}

/**
 * @brief Enters the FinalState4 state of the nested_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
nested_sm_enter_finalstate4(umltest_nested_sm_t* const p_obj)
{
    p_obj->region1 = UMLTEST_NESTED_SM_FINALSTATE4;
}

/**
 * @brief Enters the FLOP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_flop(umltest_sm1_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SM1_FLOP;
    printf("entered FLOP");
}

/**
 * @brief Enters the SUBFLOP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_subflop(umltest_sm1_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SM1_SUBFLOP;
}

/**
 * @brief Enters the SUBFLOP2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_subflop2(umltest_sm1_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SM1_SUBFLOP2;
}

/**
 * @brief Enters the FLIP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_flip(umltest_sm1_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SM1_FLIP;
    printf("entered FLIP");
}

/**
 * @brief Enters the SUBFLIP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_subflip(umltest_sm1_t* const p_obj)
{
    p_obj->region3 = UMLTEST_SM1_SUBFLIP;
}

/**
 * @brief Enters the SUBFLIP2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_subflip2(umltest_sm1_t* const p_obj)
{
    p_obj->region4 = UMLTEST_SM1_SUBFLIP2;
}

/**
 * @brief Enters the SUBFLIP3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sm1_enter_subflip3(umltest_sm1_t* const p_obj)
{
    p_obj->region4 = UMLTEST_SM1_SUBFLIP3;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_exit_flop(umltest_sm1_t* const p_obj)
{
    printf("exit FLOP");
}

/**
 * @brief Exits the FLOP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_flop(umltest_sm1_t* const p_obj,\
              umltest_sm1_region1_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_FLOP)
    {
        umltest_tmpCombo_exit_flop(p_obj);
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_(umltest_sm1_t* const p_obj)
{
    printf("Exit subflop");
}

/**
 * @brief Exits the SUBFLOP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_subflop(umltest_sm1_t* const p_obj,\
                 umltest_sm1_region1_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_SUBFLOP)
    {
        umltest_tmpCombo_(p_obj);
        sm1_exit_flop(p_obj, exit_state);
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_exit_flip(umltest_sm1_t* const p_obj)
{
    printf("exit FLIP");
}

/**
 * @brief Exits the FLIP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_flip(umltest_sm1_t* const p_obj,\
              umltest_sm1_region1_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_FLIP)
    {
        sm1_exit_region3(p_obj, UMLTEST_SM1_REGION3_INITIAL);
        sm1_exit_region4(p_obj, UMLTEST_SM1_REGION4_INITIAL);
        umltest_tmpCombo_exit_flip(p_obj);
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_exit_subflip(umltest_sm1_t* const p_obj)
{
    printf("SUBFLIP exited.\n");
}

/**
 * @brief Exits the SUBFLIP state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_subflip(umltest_sm1_t* const p_obj,\
                 umltest_sm1_region3_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_SUBFLIP)
    {
        umltest_tmpCombo_exit_subflip(p_obj);
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_exit_subflip2(umltest_sm1_t* const p_obj)
{
    printf("exit SUBFLIP2");
}

/**
 * @brief Exits the SUBFLIP2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_subflip2(umltest_sm1_t* const p_obj,\
                  umltest_sm1_region4_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_SUBFLIP2)
    {
        umltest_tmpCombo_exit_subflip2(p_obj);
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
umltest_tmpCombo_exitbhv_test_sm(umltest_sm1_t* const p_obj)
{
    
}

/**
 * @brief Exits the SUBFLIP3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static inline void
sm1_exit_subflip3(umltest_sm1_t* const p_obj,\
                  umltest_sm1_region4_t const exit_state)
{
    if(exit_state <= UMLTEST_SM1_SUBFLIP3)
    {
        umltest_tmpCombo_exitbhv_test_sm(p_obj);
    }
}

/**
 * @brief Enters the r1s1 state of the sment state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sment_enter_r1s1(umltest_sment_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SMENT_R1S1;
}

/**
 * @brief Enters the r1s2 state of the sment state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sment_enter_r1s2(umltest_sment_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SMENT_R1S2;
}

/**
 * @brief Enters the FinalState3 state of the sment state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
sment_enter_finalstate3(umltest_sment_t* const p_obj)
{
    p_obj->region1 = UMLTEST_SMENT_FINALSTATE3;
}

/*******************************************************************************
 * 
 * Static data declarations.
 * 
 ******************************************************************************/
/**
 * @brief The initialized virtual table for the umltest_app_s struct.
 */
static const umltest_app_vt_t umltest_app_vtable = 
{
    .flt.p_lp                        = umltest_app_lp_bh
};

/**
 * @brief The initialized virtual table for the umltest_classtmp_s struct.
 */
static const umltest_classtmp_vt_t umltest_classtmp_vtable = 
{
    .flt.p_lp                        = sample_flt_lp_bhv,
    .p_add                           = NULL
};

/**
 * @brief The initialized virtual table for the umltest_emotor_s struct.
 */
static const umltest_emotor_vt_t umltest_emotor_vtable = 
{
    .propulsion.iface.p_accelerate   = NULL,
    .propulsion.iface.p_decelerate   = NULL,
    .propulsion.iface.p_start        = umltest_emotor_start_bhv,
    .propulsion.iface.p_stop         = umltest_emotor_stop_bhv
};

/**
 * @brief The initialized virtual table for the umltest_engine_s struct.
 */
static const umltest_engine_vt_t umltest_engine_vtable = 
{
    .propulsion.iface.p_accelerate   = umltest_engine_accel_bhv,
    .propulsion.iface.p_decelerate   = NULL,
    .propulsion.iface.p_start        = umltest_engine_start_bhv,
    .propulsion.iface.p_stop         = umltest_propulsion_stop_bhv
};

/**
 * @brief The initialized virtual table for the umltest_hybrid_s struct.
 */
static const umltest_hybrid_vt_t umltest_hybrid_vtable = 
{
    .emotor.propulsion.iface.p_accelerate
                                     = NULL,
    .emotor.propulsion.iface.p_decelerate
                                     = NULL,
    .emotor.propulsion.iface.p_start = umltest_hybrid_start_bhv,
    .emotor.propulsion.iface.p_stop  = umltest_emotor_stop_bhv,
    .engine.propulsion.iface.p_accelerate
                                     = umltest_engine_accel_bhv,
    .engine.propulsion.iface.p_decelerate
                                     = NULL,
    .engine.propulsion.iface.p_start = umltest_hybrid_start_bhv,
    .engine.propulsion.iface.p_stop  = umltest_propulsion_stop_bhv
};

/**
 * @brief The initialized virtual table for the umltest_propulsion_s struct.
 */
static const umltest_propulsion_vt_t umltest_propulsion_vtable = 
{
    .iface.p_accelerate              = NULL,
    .iface.p_decelerate              = NULL,
    .iface.p_start                   = NULL,
    .iface.p_stop                    = umltest_propulsion_stop_bhv
};

/**
 * @brief The initialized virtual table for the umltest_tmpCombo_s struct.
 */
static const umltest_tmpCombo_vt_t umltest_tmpCombo_vtable = 
{

};

/**
 * @brief The initialized virtual table for the umltest_tmpHybrid_s struct.
 */
static const umltest_tmpHybrid_vt_t umltest_tmpHybrid_vtable = 
{

};

/*******************************************************************************
 * 
 * Public function bodies.
 * 
 ******************************************************************************/
/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] coeff 
 * @return 
 */
umltest_app_t*
umltest_app_create_coeff(umltest_app_t* const p_obj, float32_t const coeff)
{
    if(NULL != p_obj)
    {
        sample_flt_init(&p_obj->flt, 1.0f, 0.0f, 1.0f);
        umltest_app_init_df(p_obj);
        p_obj->coefficient = coeff;
    }
    
    return p_obj;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] x 
 */
void
umltest_classtmp_add(umltest_classtmp_t* const p_obj,\
                     const umltest_E_t* const x)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_add)(umltest_classtmp_t* const p_obj,\
                      const umltest_E_t* const x)
            = p_obj->p_vtable->p_add;

        if(NULL != p_add)
        {
            p_add(p_obj, x);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_iface_accelerate(umltest_iface_t* const p_obj)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_accelerate)(umltest_iface_t* const p_obj)
            = p_obj->p_vtable->p_accelerate;

        if(NULL != p_accelerate)
        {
            p_accelerate(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_iface_decelerate(umltest_iface_t* const p_obj)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_decelerate)(umltest_iface_t* const p_obj)
            = p_obj->p_vtable->p_decelerate;

        if(NULL != p_decelerate)
        {
            p_decelerate(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_iface_start(umltest_iface_t* const p_obj)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_start)(umltest_iface_t* const p_obj)
            = p_obj->p_vtable->p_start;

        if(NULL != p_start)
        {
            p_start(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_iface_stop(umltest_iface_t* const p_obj)
{
    /*Code for handling a virtual operation generated automatically.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_stop)(umltest_iface_t* const p_obj)
            = p_obj->p_vtable->p_stop;

        if(NULL != p_stop)
        {
            p_stop(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_tmpCombo_flap(umltest_tmpCombo_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_tmpCombo_flep(umltest_tmpCombo_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_tmpCombo_flip(umltest_tmpCombo_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_tmpCombo_flop(umltest_tmpCombo_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_tmpCombo_flup(umltest_tmpCombo_t* const p_obj)
{
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_emotor_start_bhv(umltest_iface_t* const p_obj)
{
    
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_emotor_stop_bhv(umltest_iface_t* const p_obj)
{
    
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_engine_accel_bhv(umltest_iface_t* const p_obj)
{
    
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_engine_start_bhv(umltest_iface_t* const p_obj)
{
    
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_hybrid_start_bhv(umltest_iface_t* const p_obj)
{
    
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
umltest_propulsion_stop_bhv(umltest_iface_t* const p_obj)
{
    
}

/*******************************************************************************
 * 
 * Non-public function bodies.
 * 
 ******************************************************************************/
/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_app_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_app_init_df(umltest_app_t* const p_obj)
{
    p_obj->coefficient               = UMLTEST_DEFAULT_COEFF;
    p_obj->flt.p_vtable              = &umltest_app_vtable.flt;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_classtmp_s struct. Generated automatically for properties for
 * which a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_classtmp_init_df(umltest_classtmp_t* const p_obj)
{
    p_obj->flt.p_vtable              = &umltest_classtmp_vtable.flt;
    p_obj->p_vtable                  = &umltest_classtmp_vtable;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_emotor_s struct. Generated automatically for properties for which
 * a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_emotor_init_df(umltest_emotor_t* const p_obj)
{
    p_obj->propulsion.iface.p_vtable = &umltest_emotor_vtable.propulsion.iface;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_engine_s struct. Generated automatically for properties for which
 * a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_engine_init_df(umltest_engine_t* const p_obj)
{
    p_obj->propulsion.iface.p_vtable = &umltest_engine_vtable.propulsion.iface;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_hybrid_s struct. Generated automatically for properties for which
 * a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_hybrid_init_df(umltest_hybrid_t* const p_obj)
{
    p_obj->emotor.propulsion.iface.p_vtable
                                     = &umltest_hybrid_vtable.emotor.propulsion
                                        .iface;
    p_obj->engine.propulsion.iface.p_vtable
                                     = &umltest_hybrid_vtable.engine.propulsion
                                        .iface;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_propulsion_s struct. Generated automatically for properties for
 * which a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_propulsion_init_df(umltest_propulsion_t* const p_obj)
{
    p_obj->iface.p_vtable            = &umltest_propulsion_vtable.iface;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_tmpCombo_s struct. Generated automatically for properties for
 * which a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_tmpCombo_init_df(umltest_tmpCombo_t* const p_obj)
{
    
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the umltest_tmpHybrid_s struct. Generated automatically for properties for
 * which a default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
umltest_tmpHybrid_init_df(umltest_tmpHybrid_t* const p_obj)
{
    
}

/**
 * The test application entrypoint.
 * @return 
 */
int
main(void)
{
    umltest_app_t app;
    (void) umltest_app_create_coeff(&app, 0.33);
    return EXIT_SUCCESS;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] filter_in The filter input value.
 */
static void
umltest_app_lp_bh(sample_flt_t* const p_obj, float32_t const filter_in)
{
    umltest_app_t* p_app = NULL;
    if((p_obj->p_vtable == (&umltest_app_vtable.flt)) 
       && UMLTEST_CHILD_FROM_BASE(umltest_app_t, flt, p_app))
    {
    	float32_t c =
    		(p_app->coefficient > 0.0f) && (p_app->coefficient <= 1.0f) ?
    				p_app->coefficient : 1.0f;
    	p_obj->filtered_sample = (1.0f - c) * p_obj->filtered_sample
    		+ c * filter_in;
    }
}

/**
 */
static void
umltest_tmpCombo_sm1(umltest_tmpCombo_t* const p_obj)
{
    
}

/**
 * @brief Implements call_flip event handling by the efsm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
efsm_dispatch_call_flip(umltest_efsm_t* const p_obj,\
                        umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_EFSM_R1S1:
            result = efsm_dispatch_call_flip_r1s1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements callFlap event handling by the efsm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
efsm_dispatch_callflap(umltest_efsm_t* const p_obj,\
                       umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_EFSM_R1S2:
            result = efsm_dispatch_callflap_r1s2(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}


/**
 * @brief Implements callFlap event handling by the R1S2 state of the efsm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
efsm_dispatch_callflap_r1s2(umltest_efsm_t* const p_obj,\
                            umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements call_flip event handling by the R1S1 state of the efsm
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
efsm_dispatch_call_flip_r1s1(umltest_efsm_t* const p_obj,\
                             umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Implements callFlap event handling by the exitbhv_test_sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
exitbhv_test_sm_dispatch_callflap(umltest_exitbhv_test_sm_t* const p_obj,\
                                  umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_EXITBHV_TEST_SM_R1S1:
            result = exitbhv_test_sm_dispatch_callflap_r1s1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements call_flip event handling by the exitbhv_test_sm state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
exitbhv_test_sm_dispatch_call_flip(umltest_exitbhv_test_sm_t* const p_obj,\
                                   umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_EXITBHV_TEST_SM_R1S2_ENTRY:
            result = sment_dispatch_call_flip(p_obj->r1s2_entry, p_event);
            break;        case UMLTEST_EXITBHV_TEST_SM_R1S2:
            result = exitbhv_test_sm_dispatch_call_flip_r1s2(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements call_flip event handling by the Region2 region of the
 * exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
exitbhv_test_sm_dispatch_call_flip_region2(umltest_exitbhv_test_sm_t* \
                                           /**/const p_obj,\
                                           umltest_tmpcombo_call_flip_t* \
                                           /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region2)
    {
        case UMLTEST_EXITBHV_TEST_SM_R2S1_ENTRY:
            result = nested_sm_dispatch_call_flip(p_obj->r2s1_entry, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements call_flip event handling by the R1S2 state of the
 * exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
exitbhv_test_sm_dispatch_call_flip_r1s2(umltest_exitbhv_test_sm_t* const p_obj,\
                                        umltest_tmpcombo_call_flip_t* \
                                        /**/const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = exitbhv_test_sm_dispatch_call_flip_region2(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements callFlap event handling by the R1S1 state of the
 * exitbhv_test_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
exitbhv_test_sm_dispatch_callflap_r1s1(umltest_exitbhv_test_sm_t* const p_obj,\
                                       umltest_tmpcombo_callflap_t* \
                                       /**/const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}


/**
 * @brief Implements call_flip event handling by the nested_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
nested_sm_dispatch_call_flip(umltest_nested_sm_t* const p_obj,\
                             umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_NESTED_SM_STATE1:
            result = nested_sm_dispatch_call_flip_state1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}


/**
 * @brief Implements call_flip event handling by the State1 state of the
 * nested_sm state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
nested_sm_dispatch_call_flip_state1(umltest_nested_sm_t* const p_obj,\
                                    umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/**
 * @brief Exits the Region1 region of the sm1 state machine.
 * 
 * Allows to easily exit a parent state when the statemachine is in a child
 * state.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static void
sm1_exit_region1(umltest_sm1_t* const p_obj,\
                 umltest_sm1_region1_t const exit_state)
{
    switch(p_obj->Region1)
    {
        case UMLTEST_SM1_FLOP:
        case UMLTEST_SM1_SUBFLOP2:
            sm1_exit_flop(p_obj, exit_state);
            break;
        case UMLTEST_SM1_SUBFLOP:
            sm1_exit_subflop(p_obj, exit_state);
            break;
        case UMLTEST_SM1_FLIP:
            sm1_exit_flip(p_obj, exit_state);
            break;
        default:
            break;
    }
}

/**
 * @brief Exits the Region3 region of the sm1 state machine.
 * 
 * Allows to easily exit a parent state when the statemachine is in a child
 * state.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static void
sm1_exit_region3(umltest_sm1_t* const p_obj,\
                 umltest_sm1_region3_t const exit_state)
{
    switch(p_obj->Region3)
    {
        case UMLTEST_SM1_SUBFLIP:
            sm1_exit_subflip(p_obj, exit_state);
            break;
        default:
            break;
    }
}

/**
 * @brief Exits the Region4 region of the sm1 state machine.
 * 
 * Allows to easily exit a parent state when the statemachine is in a child
 * state.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] exit_state The state that wants to exit.
 */
static void
sm1_exit_region4(umltest_sm1_t* const p_obj,\
                 umltest_sm1_region4_t const exit_state)
{
    switch(p_obj->Region4)
    {
        case UMLTEST_SM1_SUBFLIP2:
            sm1_exit_subflip2(p_obj, exit_state);
            break;
        case UMLTEST_SM1_SUBFLIP3:
            sm1_exit_subflip3(p_obj, exit_state);
            break;
        default:
            break;
    }
}

/**
 * @brief Implements call_flip event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flip(umltest_sm1_t* const p_obj,\
                       umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SM1_FLOP:
        case UMLTEST_SM1_SUBFLOP2:
        case UMLTEST_SM1_SUBFLOP:
            result = sm1_dispatch_call_flip_flop(p_obj, p_event);
            break;
        case UMLTEST_SM1_FLIP:
            result = sm1_dispatch_call_flip_flip(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements callFlap event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap(umltest_sm1_t* const p_obj,\
                      umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SM1_SUBFLOP2:
            result = sm1_dispatch_callflap_subflop2(p_obj, p_event);
            break;
        case UMLTEST_SM1_FLIP:
            result = sm1_dispatch_callflap_flip(p_obj, p_event);
            break;
        case UMLTEST_SM1_TRN3_EFFECT:
            result = efsm_dispatch_callflap(p_obj->trn3_effect, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements call_flop event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flop(umltest_sm1_t* const p_obj,\
                       umltest_tmpcombo_call_flop_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SM1_SUBFLOP2:
            result = sm1_dispatch_call_flop_subflop2(p_obj, p_event);
            break;
        case UMLTEST_SM1_FLIP:
            result = sm1_dispatch_call_flop_flip(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements flupcalevt event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flupcalevt(umltest_sm1_t* const p_obj,\
                        umltest_tmpcombo_flupcalevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SM1_FLIP:
            result = sm1_dispatch_flupcalevt_flip(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements flepcallevt event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flepcallevt(umltest_sm1_t* const p_obj,\
                         umltest_tmpcombo_flepcallevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SM1_FLIP:
            result = sm1_dispatch_flepcallevt_flip(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements callFlap event handling by the Region3 region of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_region3(umltest_sm1_t* const p_obj,\
                              umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region3)
    {
        case UMLTEST_SM1_SUBFLIP:
            result = sm1_dispatch_callflap_subflip(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements callFlap event handling by the Region4 region of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_region4(umltest_sm1_t* const p_obj,\
                              umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case UMLTEST_SM1_SUBFLIP2:
            result = sm1_dispatch_callflap_subflip2(p_obj, p_event);
            break;
        case UMLTEST_SM1_SUBFLIP3_EXIT:
            result = exitbhv_test_sm_dispatch_callflap(p_obj->subflip3_exit,\
                                              p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements flepcallevt event handling by the Region4 region of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flepcallevt_region4(umltest_sm1_t* const p_obj,\
                                 umltest_tmpcombo_flepcallevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case UMLTEST_SM1_SUBFLIP3:
            result = sm1_dispatch_flepcallevt_subflip3(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements call_flip event handling by the Region4 region of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flip_region4(umltest_sm1_t* const p_obj,\
                               umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region4)
    {
        case UMLTEST_SM1_SUBFLIP3_EXIT:
            result = exitbhv_test_sm_dispatch_call_flip(p_obj->subflip3_exit,\
                                               p_event);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements callFlap event handling by the SUBFLOP2 state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_subflop2(umltest_sm1_t* const p_obj,\
                               umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_exit_region1(p_obj, UMLTEST_SM1_SUBFLOP2);
    

    return result;
}
/**
 * @brief Implements callFlap event handling by the FLIP state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_flip(umltest_sm1_t* const p_obj,\
                           umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = sm1_dispatch_callflap_region3(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    temp_status = sm1_dispatch_callflap_region4(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    if(IGNORED == result)
    {
        sm1_exit_region1(p_obj, UMLTEST_SM1_FLIP);
        
    }

    return result;
}

/**
 * @brief Implements flepcallevt event handling by the FLIP state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flepcallevt_flip(umltest_sm1_t* const p_obj,\
                              umltest_tmpcombo_flepcallevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = sm1_dispatch_flepcallevt_region4(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements call_flop event handling by the SUBFLOP2 state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flop_subflop2(umltest_sm1_t* const p_obj,\
                                umltest_tmpcombo_call_flop_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    result = SAMESTATE;

    return result;
}
/**
 * @brief Implements call_flop event handling by the FLIP state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flop_flip(umltest_sm1_t* const p_obj,\
                            umltest_tmpcombo_call_flop_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_exit_region1(p_obj, UMLTEST_SM1_FLIP);
    

    return result;
}

/**
 * @brief Implements call_flip event handling by the FLOP state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flip_flop(umltest_sm1_t* const p_obj,\
                            umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_exit_region1(p_obj, UMLTEST_SM1_FLOP);
    

    return result;
}
/**
 * @brief Implements call_flip event handling by the FLIP state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_call_flip_flip(umltest_sm1_t* const p_obj,\
                            umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;
    sm_event_status_t temp_status = IGNORED;

    temp_status = sm1_dispatch_call_flip_region4(p_obj, p_event);
    result = sm_event_resolve_status(result, temp_status);

    return result;
}

/**
 * @brief Implements flupcalevt event handling by the FLIP state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flupcalevt_flip(umltest_sm1_t* const p_obj,\
                             umltest_tmpcombo_flupcalevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    printf("flup event detected");
    result = SAMESTATE;

    return result;
}

/**
 * @brief Implements callFlap event handling by the SUBFLIP state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_subflip(umltest_sm1_t* const p_obj,\
                              umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_exit_region1(p_obj, UMLTEST_SM1_FLIP);
    

    return result;
}

/**
 * @brief Implements callFlap event handling by the SUBFLIP2 state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_callflap_subflip2(umltest_sm1_t* const p_obj,\
                               umltest_tmpcombo_callflap_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    if(b_is_true_test)
    {
        sm1_exit_region4(p_obj, UMLTEST_SM1_SUBFLIP2);
        
    }
    else 
    {
    }

    return result;
}

/**
 * @brief Implements flepcallevt event handling by the SUBFLIP3 state of the sm1
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sm1_dispatch_flepcallevt_subflip3(umltest_sm1_t* const p_obj,\
                                  umltest_tmpcombo_flepcallevt_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    sm1_exit_region4(p_obj, UMLTEST_SM1_SUBFLIP3);
    

    return result;
}


/**
 * @brief Implements call_flip event handling by the sment state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sment_dispatch_call_flip(umltest_sment_t* const p_obj,\
                         umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    switch(p_obj->region1)
    {
        case UMLTEST_SMENT_R1S1:
            result = sment_dispatch_call_flip_r1s1(p_obj, p_event);
            break;
        default:
            break;
    }

    return result;
}


/**
 * @brief Implements call_flip event handling by the r1s1 state of the sment
 * state machine.
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_event The pointer to the event data.
 * return the event dispatch status.
 */
static sm_event_status_t
sment_dispatch_call_flip_r1s1(umltest_sment_t* const p_obj,\
                              umltest_tmpcombo_call_flip_t* const p_event)
{
    sm_event_status_t result = IGNORED;

    

    return result;
}

/*** end of file ***/
