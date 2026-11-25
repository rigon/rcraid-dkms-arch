/* 3.4+: register_sysctl(path, table) replaces nested register_sysctl_table() */
#include <linux/sysctl.h>

static struct ctl_table t[] = { { } };

static struct ctl_table_header * __used f(void)
{
	return register_sysctl("dev", t);
}
