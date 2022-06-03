#ifndef WASM_LIB_H
#define WASM_LIB_H

#include "aacenc_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

void aacEncoder_CreateInBufDesc(AACENC_BufDesc **desc, int16_t *inbuf, unsigned int length);

void aacEncoder_CreateOutBufDesc(AACENC_BufDesc **desc, uint8_t *outbuf, unsigned int length);

void aacEncoder_CreateInArgs(AACENC_InArgs **in_args, unsigned int length);

int aacEncoder_GetNumOutBytes(AACENC_OutArgs *out_args);

void aacEncoder_FreeBufDesc(AACENC_BufDesc *desc);

#ifdef __cplusplus
}
#endif

#endif /* WASM_LIB_H */
