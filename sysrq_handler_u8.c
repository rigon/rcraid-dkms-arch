/* 6.6+: sysrq handlers take a u8 key instead of an int */
#include <linux/sysrq.h>

static void f(u8 key)
{
}

static const struct sysrq_key_op op __used = { .handler = f };
