#ifndef __NVC0_QUERY_SW_H__
#define __NVC0_QUERY_SW_H__

#include "nvc0_query.h"

struct nvc0_sw_query {
   struct nvc0_query base;
   uint64_t value;
};

static inline struct nvc0_sw_query *
nvc0_sw_query(struct nvc0_query *q)
{
   return (struct nvc0_sw_query *)q;
}

/*
 * Driver statistics queries:
 */
#define NVC0_SW_QUERY_DRV_STAT(i)    (PIPE_QUERY_DRIVER_SPECIFIC + 1024 + (i))
#define NVC0_SW_QUERY_DRV_STAT_LAST   NVC0_SW_QUERY_DRV_STAT(NVC0_SW_QUERY_DRV_STAT_COUNT - 1)
enum nvc0_sw_query_drv_stat
{
#ifdef NOUVEAU_ENABLE_DRIVER_STATISTICS
   NVC0_SW_QUERY_DRV_STAT_TEX_OBJECT_CURRENT_COUNT = 0,
   NVC0_SW_QUERY_DRV_STAT_TEX_OBJECT_CURRENT_BYTES,
   NVC0_SW_QUERY_DRV_STAT_BUF_OBJECT_CURRENT_COUNT,
   NVC0_SW_QUERY_DRV_STAT_BUF_OBJECT_CURRENT_BYTES_VID,
   NVC0_SW_QUERY_DRV_STAT_BUF_OBJECT_CURRENT_BYTES_SYS,
   NVC0_SW_QUERY_DRV_STAT_TEX_TRANSFERS_READ,
   NVC0_SW_QUERY_DRV_STAT_TEX_TRANSFERS_WRITE,
   NVC0_SW_QUERY_DRV_STAT_TEX_COPY_COUNT,
   NVC0_SW_QUERY_DRV_STAT_TEX_BLIT_COUNT,
   NVC0_SW_QUERY_DRV_STAT_TEX_CACHE_FLUSH_COUNT,
   NVC0_SW_QUERY_DRV_STAT_BUF_TRANSFERS_READ,
   NVC0_SW_QUERY_DRV_STAT_BUF_TRANSFERS_WRITE,
   NVC0_SW_QUERY_DRV_STAT_BUF_READ_BYTES_STAGING_VID,
   NVC0_SW_QUERY_DRV_STAT_BUF_WRITE_BYTES_DIRECT,
   NVC0_SW_QUERY_DRV_STAT_BUF_WRITE_BYTES_STAGING_VID,
   NVC0_SW_QUERY_DRV_STAT_BUF_WRITE_BYTES_STAGING_SYS,
   NVC0_SW_QUERY_DRV_STAT_BUF_COPY_BYTES,
   NVC0_SW_QUERY_DRV_STAT_BUF_NON_KERNEL_FENCE_SYNC_COUNT,
   NVC0_SW_QUERY_DRV_STAT_ANY_NON_KERNEL_FENCE_SYNC_COUNT,
   NVC0_SW_QUERY_DRV_STAT_QUERY_SYNC_COUNT,
   NVC0_SW_QUERY_DRV_STAT_GPU_SERIALIZE_COUNT,
   NVC0_SW_QUERY_DRV_STAT_DRAW_CALLS_ARRAY,
   NVC0_SW_QUERY_DRV_STAT_DRAW_CALLS_INDEXED,
   NVC0_SW_QUERY_DRV_STAT_DRAW_CALLS_FALLBACK_COUNT,
   NVC0_SW_QUERY_DRV_STAT_USER_BUFFER_UPLOAD_BYTES,
   NVC0_SW_QUERY_DRV_STAT_CONSTBUF_UPLOAD_COUNT,
   NVC0_SW_QUERY_DRV_STAT_CONSTBUF_UPLOAD_BYTES,
   NVC0_SW_QUERY_DRV_STAT_PUSHBUF_COUNT,
   NVC0_SW_QUERY_DRV_STAT_RESOURCE_VALIDATE_COUNT,
#endif
   NVC0_SW_QUERY_DRV_STAT_COUNT
};

struct nvc0_query *
nvc0_sw_create_query(struct nvc0_context *, unsigned, unsigned);
int
nvc0_sw_get_driver_query_info(struct nvc0_screen *, unsigned,
                              struct pipe_driver_query_info *);

#endif
