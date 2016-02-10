/**
 * @defgroup rp_xp Request Processor's xpath Helpers
 * @{
 * @brief Functions for creating xpath.
 * @file rp_xpath.h
 * @author Rastislav Szabo <raszabo@cisco.com>, Lukas Macko <lmacko@cisco.com>
 * @brief
 *
 * @copyright
 * Copyright 2015 Cisco Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_RP_DT_XPATH_H_
#define SRC_RP_DT_XPATH_H_

#include <libyang/libyang.h>
#include "data_manager.h"
#include "xpath_processor.h"

/**
 * @brief Creates xpath for the selected node. Function walks from the node
 * up to the top-level node. Namespace is explictly specified for top level node
 * and augment nodes.
 * @param [in] node
 * @param [out] xpath
 * @return Error code (SR_ERR_OK on success)
 */
int rp_dt_create_xpath_for_node(const struct lyd_node *node, char **xpath);

/**
 * @brief Validates the location_id with schema. Functions does the following checks:
 * - tests if the top level node's namespace is specified
 * - tests if the model exists (if not returns SR_ERR_UNKNOWN_MODEL)
 * - tests if the nodes exists in the model (if not returns SR_ERR_BAD_ELEMENT)
 * - tests if the keys name and key count are valid (if not returns SR_ERR_BAD_ELEMENT) 
 * @param [in] dm_ctx
 * @param [in] loc_id input to be validated
 * @param [out] module pointer to the module where the xpath is pointing (in case of augement, augmented module)
 * @param [out] match schema node is returned if NULL is not passed
 * @return Error code (SR_ERR_OK on success)
 */
int rp_dt_validate_node_xpath(dm_ctx_t *dm_ctx, const xp_loc_id_t *loc_id, const struct lys_module **matched_module, struct lys_node **match);

/**
 * @}
 */
#endif /* SRC_RP_DT_XPATH_H_ */
