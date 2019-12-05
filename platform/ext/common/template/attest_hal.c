/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdint.h>
#include "platform/include/tfm_attest_hal.h"
#include "platform/include/tfm_plat_boot_seed.h"

/*!
 * \def BOOT_SEED
 *
 * \brief Fixed value for boot seed used for test.
 */
#define BOOT_SEED   0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, \
                    0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, \
                    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, \
                    0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF

static const uint8_t boot_seed[BOOT_SEED_SIZE] = {BOOT_SEED};

/* Example verification service URL for initial attestation token */
static const char verification_service_url[] = "www.trustedfirmware.org";

/* Example profile definition document for initial attestation token */
static const char attestation_profile_definition[] = "PSA_IOT_PROFILE_1";

enum tfm_security_lifecycle_t tfm_attest_hal_get_security_lifecycle(void)
{
    return TFM_SLC_SECURED;
}

const char *
tfm_attest_hal_get_verification_service(uint32_t *size)
{
    *size = sizeof(verification_service_url) - 1;

    return verification_service_url;
}

const char *
tfm_attest_hal_get_profile_definition(uint32_t *size)
{
    *size = sizeof(attestation_profile_definition) - 1;

    return attestation_profile_definition;
}

enum tfm_plat_err_t tfm_plat_get_boot_seed(uint32_t size, uint8_t *buf)
{
    /* FixMe: - This getter function must be ported per target platform.
     *        - Platform service shall provide an API to further interact this
     *          getter function to retrieve the boot seed.
     */

    uint32_t i;
    uint8_t *p_dst = buf;
    const uint8_t *p_src = boot_seed;

    if (size != BOOT_SEED_SIZE) {
        return TFM_PLAT_ERR_SYSTEM_ERR;
    }

    for (i = size; i > 0; i--) {
        *p_dst = *p_src;
        p_src++;
        p_dst++;
    }

    return TFM_PLAT_ERR_SUCCESS;
}