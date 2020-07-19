/*
 ******************************************************************************
 * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all copies.
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * ****************************************************************************
 */

#ifndef __NSS_GRE_TUNNEL_STATS_H
#define __NSS_GRE_TUNNEL_STATS_H

/*
 * GRE Tunnel session debug statistic counters
 */
enum nss_gre_tunnel_stats_session {
	NSS_GRE_TUNNEL_STATS_SESSION_RX_PKTS,
	NSS_GRE_TUNNEL_STATS_SESSION_TX_PKTS,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_QUEUE_0_DROPPED,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_QUEUE_1_DROPPED,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_QUEUE_2_DROPPED,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_QUEUE_3_DROPPED,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_MALFORMED,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_INVALID_PROT,
	NSS_GRE_TUNNEL_STATS_SESSION_DECAP_QUEUE_FULL,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_SINGLE_REC_DGRAM,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_INVALID_REC_DGRAM,
	NSS_GRE_TUNNEL_STATS_SESSION_BUFFER_ALLOC_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_BUFFER_COPY_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_OUTFLOW_QUEUE_FULL,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_DROPPED_HROOM,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_CBUFFER_ALLOC_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_CENQUEUE_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_DECRYPT_DONE,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_FORWARD_ENQUEUE_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_TX_CBUFFER_ALLOC_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_TX_CENQUEUE_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_DROPPED_TROOM,
	NSS_GRE_TUNNEL_STATS_SESSION_TX_FORWARD_ENQUEUE_FAIL,
	NSS_GRE_TUNNEL_STATS_SESSION_TX_CIPHER_DONE,
	NSS_GRE_TUNNEL_STATS_SESSION_CRYPTO_NOSUPP,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_DROPPED_MH_VERSION,
	NSS_GRE_TUNNEL_STATS_SESSION_RX_UNALIGNED_PKT,
	NSS_GRE_TUNNEL_STATS_SESSION_MAX,
};

/*
 * GRE Tunnel session debug statistics
 */
struct nss_gre_tunnel_stats_session_debug {
	uint64_t stats[NSS_GRE_TUNNEL_STATS_SESSION_MAX + NSS_CRYPTO_CMN_RESP_ERROR_MAX];
	int32_t if_index;
	uint32_t if_num; /* nss interface number */
	bool valid;
};

/*
 * Data structures to store GRE Tunnel nss debug stats
 */
extern spinlock_t nss_gre_tunnel_stats_session_debug_lock;
extern struct nss_gre_tunnel_stats_session_debug nss_gre_tunnel_session_debug_stats[NSS_MAX_GRE_TUNNEL_SESSIONS];

/*
 * GRE Tunnel statistics APIs
 */
extern void nss_gre_tunnel_stats_session_sync(struct nss_ctx_instance *nss_ctx, struct nss_gre_tunnel_stats *stats_msg, uint16_t if_num);
extern void nss_gre_tunnel_stats_dentry_create(void);

#endif /* __NSS_GRE_TUNNEL_STATS_H */