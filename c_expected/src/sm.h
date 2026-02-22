#ifndef SM_H
#define SM_H

#ifdef  __cplusplus
extern "C" {
#endif

    typedef enum {
        SM_EVENT_STATUS_PENDING,      /**< Event waiting for processing.*/
        SM_EVENT_STATUS_IGNORED,      /**< Event ignored.*/
        SM_EVENT_STATUS_DEFERRED,     /**< Event deferred.*/
        SM_EVENT_STATUS_SAMESTATE,    /**< Event handled, no state change.*/
        SM_EVENT_STATUS_CHANGEDSTATE, /**< Event handled, state changed.*/
        SM_EVENT_STATUS_DISPATCHED    /**< Event processed and removed from the
                                           event pool.*/
    }sm_event_status_t;

    sm_event_status_t sm_event_resolve_status(sm_event_status_t const status1,\
                                              sm_event_status_t const status2);

#ifdef  __cplusplus
}
#endif

#endif  /* SM_H */

/*** end of file ***/
