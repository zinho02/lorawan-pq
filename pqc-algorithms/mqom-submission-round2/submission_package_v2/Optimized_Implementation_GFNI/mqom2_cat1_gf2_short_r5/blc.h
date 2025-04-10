#ifndef __BLC_H__
#define __BLC_H__

/* MQOM2 parameters */
#include "mqom2_parameters.h"
#include "enc.h"
#include "prg.h"
#include "xof.h"
#include "fields.h"

typedef struct blc_key_t {
    uint8_t node[MQOM2_PARAM_TAU][MQOM2_PARAM_FULL_TREE_SIZE + 1][MQOM2_PARAM_SEED_SIZE];
    uint8_t ls_com[MQOM2_PARAM_TAU][MQOM2_PARAM_NB_EVALS][MQOM2_PARAM_DIGEST_SIZE];
    uint8_t partial_delta_x[MQOM2_PARAM_TAU][BYTE_SIZE_FIELD_BASE(MQOM2_PARAM_MQ_N)-MQOM2_PARAM_SEED_SIZE];
} blc_key_t;

int BLC_Commit(const uint8_t mseed[MQOM2_PARAM_SEED_SIZE], const uint8_t salt[MQOM2_PARAM_SALT_SIZE], const field_base_elt x[FIELD_BASE_PACKING(MQOM2_PARAM_MQ_N)], uint8_t com1[MQOM2_PARAM_DIGEST_SIZE], blc_key_t* key, field_ext_elt x0[MQOM2_PARAM_TAU][FIELD_EXT_PACKING(MQOM2_PARAM_MQ_N)], field_ext_elt u0[MQOM2_PARAM_TAU][FIELD_EXT_PACKING(MQOM2_PARAM_ETA)], field_ext_elt u1[MQOM2_PARAM_TAU][FIELD_EXT_PACKING(MQOM2_PARAM_ETA)]);

int BLC_Open(const blc_key_t* key, const uint16_t i_star[MQOM2_PARAM_TAU], uint8_t opening[MQOM2_PARAM_OPENING_SIZE]);

int BLC_Eval(const uint8_t salt[MQOM2_PARAM_SALT_SIZE], const uint8_t com1[MQOM2_PARAM_DIGEST_SIZE], const uint8_t opening[MQOM2_PARAM_OPENING_SIZE], const uint16_t i_star[MQOM2_PARAM_TAU], field_ext_elt x_eval[MQOM2_PARAM_TAU][FIELD_EXT_PACKING(MQOM2_PARAM_MQ_N)], field_ext_elt u_eval[MQOM2_PARAM_TAU][FIELD_EXT_PACKING(MQOM2_PARAM_ETA)]);

#endif /* __BLC_H__ */
