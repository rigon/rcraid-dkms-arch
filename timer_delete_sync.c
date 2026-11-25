/* 6.2+: del_timer_sync() renamed to timer_delete_sync() */
#include <linux/timer.h>

static int __used f(struct timer_list *t)
{
	return timer_delete_sync(t);
}
