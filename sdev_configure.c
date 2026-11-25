/* 6.14+: scsi_host_template.slave_configure replaced by sdev_configure */
#include <scsi/scsi_host.h>

static int f(struct scsi_device *sdev, struct queue_limits *lim)
{
	return 0;
}

static struct scsi_host_template t __used = { .sdev_configure = f };
