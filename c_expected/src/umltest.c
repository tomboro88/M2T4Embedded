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
#include <stdlib.h>
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
/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
int
main(void)
{
    printf("Initialize my_ctest:\n");
    Tkind_ctest_t my_ctest = {0};
    Tkind_ctest_init(&my_ctest);
    Tkind_cbase1_SetUintProp(&my_ctest.cbase1, 123);
    Tkind_cbase2_SetFloatProp(&my_ctest.cbase2, 13.0f);
    printf("\nPolymorphism example:\n"
           "The result of GetUintProp: %d\n"
           "The result of GetFloatProp: %f\n",
           Tkind_cbase1_GetUintProp(&my_ctest.cbase1),
           Tkind_cbase2_GetFloatProp(&my_ctest.cbase2));
    printf("Send an process the a event in my_ctest:\n");
    Tkind_ctest_a(&my_ctest);
    Tkind_ctest_fetch_event(&my_ctest);
    Tkind_ctest_dispatch_event(&my_ctest);
    Tkind_ctest_release_event(&my_ctest);

    printf("\n\nInitialize my_jtest:\n");
    TJunction_Jtest_t my_jtest = {0};
    TJunction_Jtest_init(&my_jtest);
    printf("Send an process the a event in my_jtest:\n");
    TJunction_Jtest_a(&my_jtest);
    TJunction_Jtest_fetch_event(&my_jtest);
    TJunction_Jtest_dispatch_event(&my_jtest);
    TJunction_Jtest_release_event(&my_jtest);

    return EXIT_SUCCESS;
}
/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/*** end of file ***/
