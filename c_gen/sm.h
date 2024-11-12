#ifndef SM_H
#define SM_H

#ifdef  __cplusplus
extern "C" {
#endif

    typedef enum {
        IGNORED,      /**< Event ignored.*/
        DEFERRED,     /**< Event deferred.*/
        SAMESTATE,    /**< Event handled, no state change.*/
        CHANGEDSTATE, /**< Event handled, state changed.*/
        TRANSITION    /**< Event processing started, but paused \
                                      on some submachine action.*/
    }sm_event_status_t;

    sm_event_status_t sm_event_resolve_status(sm_event_status_t const status1,\
                                              sm_event_status_t const status2);

#ifdef  __cplusplus
}
#endif

#endif  /* SM_H */

/*** end of file ***/
