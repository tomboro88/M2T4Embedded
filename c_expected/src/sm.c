
#include "sm.h"

sm_event_status_t
sm_event_resolve_status(sm_event_status_t const status1,\
                        sm_event_status_t const status2)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    if(SM_EVENT_STATUS_CHANGEDSTATE==status1
            || SM_EVENT_STATUS_CHANGEDSTATE==status2)
    {
        result = SM_EVENT_STATUS_CHANGEDSTATE;
    }
    else if(SM_EVENT_STATUS_SAMESTATE==status1
            || SM_EVENT_STATUS_SAMESTATE==status2)
    {
        result = SM_EVENT_STATUS_SAMESTATE;
    }
    else if (SM_EVENT_STATUS_DEFERRED==status1
            || SM_EVENT_STATUS_DEFERRED==status2)
    {
        result = SM_EVENT_STATUS_DEFERRED;
    }
    else
    {
        result = SM_EVENT_STATUS_IGNORED;
    }

    return result;
}

/*** end of file ***/
