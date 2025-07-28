
#include "sm.h"

sm_event_status_t
sm_event_resolve_status(sm_event_status_t const status1,\
                        sm_event_status_t const status2)
{
    sm_event_status_t result = IGNORED;

    if(TRANSITION==status1 || TRANSITION==status2)
    {
        result = TRANSITION;
    }
    else if(CHANGEDSTATE==status1 || CHANGEDSTATE==status2)
    {
        result = CHANGEDSTATE;
    }
    else if(SAMESTATE==status1 || SAMESTATE==status2)
    {
        result = SAMESTATE;
    }
    else if (DEFERRED==status1 || DEFERRED==status2)
    {
        result = DEFERRED;
    }
    else
    {
        result = IGNORED;
    }

    return result;
}

/*** end of file ***/
