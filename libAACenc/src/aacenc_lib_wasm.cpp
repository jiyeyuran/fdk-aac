#include <stdlib.h>
#include <stdint.h>
#include "aacenc_lib_wasm.h"

void aacEncoder_CreateInBufDesc(AACENC_BufDesc **desc, int16_t *inbuf, unsigned int length) {
    AACENC_BufDesc *in_buf = (AACENC_BufDesc *) malloc(sizeof(AACENC_BufDesc));

    int16_t **in_ptr = (int16_t **) malloc(sizeof(int16_t *));
    INT *in_identifier = (INT *) malloc(sizeof(INT));
    INT *size = (INT *) malloc(sizeof(INT)), *in_elem_size = (INT *) malloc(sizeof(INT));

    *in_ptr = inbuf;
    *in_identifier = IN_AUDIO_DATA;
    *size = length*2, *in_elem_size = 2;

    in_buf->numBufs = 1;
    in_buf->bufs = (void **)in_ptr;
    in_buf->bufferIdentifiers = in_identifier;
    in_buf->bufSizes = size;
    in_buf->bufElSizes = in_elem_size;

    *desc = in_buf;
}

void aacEncoder_CreateOutBufDesc(AACENC_BufDesc **desc, uint8_t *outbuf, unsigned int length) {
    AACENC_BufDesc *out_buf = (AACENC_BufDesc *) malloc(sizeof(AACENC_BufDesc));

    uint8_t **out_ptr = (uint8_t **) malloc(sizeof(uint8_t *));
    INT *out_identifier = (INT *) malloc(sizeof(INT));
    INT *size = (INT *) malloc(sizeof(INT)), *out_elem_size = (INT *) malloc(sizeof(INT));

    *out_ptr = outbuf;
    *out_identifier = OUT_BITSTREAM_DATA;
    *size = length, *out_elem_size = 1;

    out_buf->numBufs = 1;
    out_buf->bufs = (void **)out_ptr;
    out_buf->bufferIdentifiers = out_identifier;
    out_buf->bufSizes = size;
    out_buf->bufElSizes = out_elem_size;

    *desc = out_buf;
}

void aacEncoder_CreateInArgs(AACENC_InArgs **in_args, unsigned int length) {
    AACENC_InArgs *args = (AACENC_InArgs *) malloc(sizeof(AACENC_InArgs));

    args->numInSamples = length <= 0 ? -1 : length;

    *in_args = args;
}

int aacEncoder_GetNumOutBytes(AACENC_OutArgs *out_args) {
    return out_args->numOutBytes;
}

void aacEncoder_FreeBufDesc(AACENC_BufDesc *desc) {
    free(desc->bufs);
    free(desc->bufferIdentifiers);
    free(desc->bufSizes);
    free(desc->bufElSizes);
    free(desc);
}
