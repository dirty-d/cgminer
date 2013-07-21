#ifndef KECCAK_H
#define KECCAK_H

#ifdef HAVE_OPENCL
#ifdef __APPLE_CC__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif
#endif

#ifdef USE_KECCAK

#define KECCAK_BUFFER_SIZE (20*4)

struct _clState;
struct dev_blk_ctx;
struct thr_info;
struct work;

cl_int queue_keccak_kernel(struct _clState *clState, struct dev_blk_ctx *blk, cl_uint threads);
bool keccak_prepare_work(struct thr_info *thr, struct work *work);
extern int keccak_test(unsigned char *pdata, const unsigned char *ptarget, uint32_t nonce);
extern void keccak_regenhash(struct work *work);

#endif /* USE_KECCAK */

#endif /* KECCAK_H */
