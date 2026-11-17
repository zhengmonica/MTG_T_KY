/*
 * Copyright (c) 2006, 2008 Alexey Vatchenko <av@bsdua.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * VPool: implementation of pool of data with a variable size.
 */
#ifndef _VPOOL_H_
#define _VPOOL_H_

#include <sys/types.h>
#include <limits.h>

typedef struct vpool {
	void	*v_basebuf;	/* pointer returned by (re|m)alloc() */
	void	*v_buf;		/* actual data starts here */
	size_t	v_off;
	size_t	v_size;

	//size_t	v_blksize;
	//size_t	v_limit;
	int	v_lasterr;
}vpool;

enum vpool_trunc {VPOOL_EXCLUDE, VPOOL_INCLUDE};
#define VPOOL_TAIL	UINT_MAX
#define SIZE_MAX INT_MAX

#ifdef __cplusplus
extern "C"
{
#endif

void	vpool_init(vpool *pool, size_t blksize, size_t limit);
void	vpool_final(vpool *pool);

void	vpool_reset(vpool *pool);
void	vpool_wipe(vpool *pool);

void *	vpool_insert(vpool *pool,
	    size_t where, void *data, size_t datsize);
void *	vpool_expand(vpool *pool, size_t where, size_t size);

int	vpool_truncate(vpool *pool,
	    size_t where, size_t size, enum vpool_trunc how);

#define vpool_is_empty(pool)		((pool)->v_off == 0)
#define vpool_get_buf(pool)		((pool)->v_buf)
#define vpool_get_length(pool)		((pool)->v_off)
#define vpool_get_error(pool)		((pool)->v_lasterr)

void	vpool_export(vpool *pool, void **buf, size_t *size);

#ifdef __cplusplus
}
#endif

#endif /* !_VPOOL_H_ */
