#ifndef XCORO_LIB_EV_H
#define XCORO_LIB_EV_H

#include "xcoro.h"

#define EV_CB_DECLARE(type)   xcoro_task_t *cb;
#define EV_CB_INVOKE(watcher) xcoro_resume((watcher)->cb)
#include "libev/ev.h"

static inline void wait_for_event(ev_watcher *w)
{
	ev_set_cb(w, xcoro_get_current_task());
	xcoro_suspend();
}

#endif
