/* 6.18+: scsi_host_template.bios_param takes a struct gendisk */
#include <scsi/scsi_host.h>

static int f(struct scsi_device *sdev, struct gendisk *disk, sector_t capacity, int geom[])
{
	return 0;
}

static struct scsi_host_template t __used = { .bios_param = f };
