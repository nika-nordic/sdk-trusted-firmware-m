/*
 * Copyright (c) 2017-2018, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TFM_SST_VENEERS_H__
#define __TFM_SST_VENEERS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "tfm_sst_defs.h"

/**
 * \brief Gets handler for the given asset uuid. If an asset is deleted, the
 *        linked asset handle reference is no longer valid and will give
 *        TFM_SST_ERR_ASSET_REF_INVALID if used.
 *
 * \param[in]  app_id      Application ID
 * \param[in]  asset_uuid  Asset UUID
 * \param[out] hdl         Handle to be returned
 *
 * \return Returns asset handle. If asset is not found, it returns
 *         TFM_SST_ERR_ASSET_NOT_FOUND. If SST area is not prepared, it returns
 *         TFM_SST_ERR_ASSET_NOT_PREPARED.
 */
enum tfm_sst_err_t tfm_sst_veneer_get_handle(uint32_t app_id,
                                             uint16_t asset_uuid,
                                             uint32_t *hdl);
/**
 * \brief Allocates space for the asset, referenced by asset handler,
 *        without setting any data in the asset.
 *
 * \param[in] app_id      Application ID
 * \param[in] asset_uuid  Asset UUID
 *
 * \return Returns an asset handle. If SST area is not prepared, it returns
 *         TFM_SST_ERR_ASSET_NOT_PREPARED. If SST area is full, it returns
 *         TFM_SST_ERR_STORAGE_SYSTEM_FULL. If application id doesn't have the
 *         write rights, it returns TFM_SST_ERR_PERMS_NOT_ALLOWED.
 */
enum tfm_sst_err_t tfm_sst_veneer_create(uint32_t app_id, uint16_t asset_uuid);

/**
 * \brief Gets asset's information referenced by asset handler.
 *
 * \param[in]  app_id        Application ID
 * \param[in]  asset_handle  Asset handler
 * \param[out] info          Pointer to store the asset's information
 *                           \ref tfm_sst_asset_info_t
 *
 * \return Returns error code as specified in \ref tfm_sst_err_t
 */
enum tfm_sst_err_t tfm_sst_veneer_get_info(uint32_t app_id,
                                           uint32_t asset_handle,
                                           struct tfm_sst_asset_info_t *info);

/**
 * \brief Reads asset's data from asset referenced by asset handler.
 *
 * \param[in]     app_id         Application ID
 * \param[in]     asset_handle   Asset handler
 * \param[in/out] data           Pointer to data vector \ref tfm_sst_buf_t to
 *                               store data, size and offset
 *
 * \return Returns the number of bytes written or a castable \ref tfm_sst_err_t
 *         value
 */
enum tfm_sst_err_t tfm_sst_veneer_read(uint32_t app_id,
                                       uint32_t asset_handle,
                                       struct tfm_sst_buf_t *data);
/**
 * \brief Writes data into an asset referenced by asset handler.
 *
 * \param[in] app_id         Application ID
 * \param[in] asset_handle   Asset handler
 * \param[in] data           Pointer to data vector \ref tfm_sst_buf_t which
 *                           contains the data to write
 *
 * \return Returns the number of bytes written or a castable \ref tfm_sst_err_t
 *         value
 */
enum tfm_sst_err_t tfm_sst_veneer_write(uint32_t app_id,
                                        uint32_t asset_handle,
                                        struct tfm_sst_buf_t *data);
/**
 * \brief Deletes the asset referenced by the asset handler.
 *
 * \param[in] app_id        Application ID
 * \param[in] asset_handle  Asset handler
 *
 * \return Returns TFM_SST_ERR_PERMS_NOT_ALLOWED if the asset can't be deleted
 *         to by this app ID. Returns TFM_SST_ERR_ASSET_REF_INVALID, if asset
 *         no longer exists. Otherwise, TFM_SST_ERR_SUCCESS.
 */
enum tfm_sst_err_t tfm_sst_veneer_delete(uint32_t app_id,
                                         uint32_t asset_handle);
#ifdef __cplusplus
}
#endif

#endif /* __TFM_SST_VENEERS_H__ */
