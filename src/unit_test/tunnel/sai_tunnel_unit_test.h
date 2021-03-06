/************************************************************************
* LEGALESE:   "Copyright (c) 2016, Dell Inc. All rights reserved."
*
* This source code is confidential, proprietary, and contains trade
* secrets that are the sole property of Dell Inc.
* Copy and/or distribution of this source code or disassembly or reverse
* engineering of the resultant object code are strictly forbidden without
* the written consent of Dell Inc.
*
************************************************************************/
/**
* @file  sai_tunnel_unit_test_utils.h
*
* @brief This file contains class definition, utility and helper
*        function prototypes for testing the SAI Tunnel functionalities.
*
*************************************************************************/

#ifndef __SAI_TUNNEL_UNIT_TEST_H__
#define __SAI_TUNNEL_UNIT_TEST_H__

#include "gtest/gtest.h"

extern "C" {
#include "saitypes.h"
#include "saistatus.h"
#include "saiswitch.h"
#include "saitunnel.h"
#include <stdarg.h>
}

class saiTunnelTest : public ::testing::Test
{
    public:
        /* Method to setup the Tunnel API table pointers. */
        static void sai_test_tunnel_api_table_get (void);

        /* Method to setup default underlay router objects for the tests. */
        static void sai_test_tunnel_underlay_router_setup (void);
        static void sai_test_tunnel_underlay_router_tear_down (void);

        /* Methods for Tunnel object functionality SAI API testing. */
        static sai_status_t sai_test_tunnel_create (
                                               sai_object_id_t *tunnel_id,
                                               unsigned int attr_count, ...);
        static sai_status_t sai_test_tunnel_remove (
                                               sai_object_id_t tunnel_id);
        static sai_status_t sai_test_tunnel_get (sai_object_id_t tunnel_id,
                                                 sai_attribute_t *p_attr_list,
                                                 unsigned int attr_count, ...);
        static void sai_test_tunnel_attr_value_fill (unsigned int attr_count,
                                                     va_list *p_varg_list,
                                                     sai_attribute_t *p_attr_list);

        /* Methods for Tunnel Termination Entry SAI API testing. */
        static sai_status_t sai_test_tunnel_term_entry_create(
                                               sai_object_id_t *tunnel_term_id,
                                               unsigned int attr_count, ...);
        static sai_status_t sai_test_tunnel_term_entry_remove (
                                               sai_object_id_t tunnel_term_id);
        static sai_status_t sai_test_tunnel_term_entry_get (
                                                 sai_object_id_t tunnel_term_id,
                                                 sai_attribute_t *p_attr_list,
                                                 unsigned int attr_count, ...);
        static void sai_test_tunnel_term_attr_value_fill (unsigned int attr_count,
                                                          va_list *p_varg_list,
                                                          sai_attribute_t *p_attr_list);

        /* Methods for Tunnel Encap Next Hop functionality SAI API testing. */
        static sai_status_t sai_test_tunnel_encap_nh_create (
                                               sai_object_id_t *tunnel_nh_id,
                                               unsigned int attr_count, ...);
        static sai_status_t sai_test_tunnel_encap_nh_remove (
                                               sai_object_id_t tunnel_nh_id);
        static sai_status_t sai_test_tunnel_encap_nh_get (
                                                 sai_object_id_t tunnel_nh_id,
                                                 sai_attribute_t *p_attr_list,
                                                 unsigned int attr_count, ...);

        static sai_object_id_t sai_test_tunnel_port_id_get (uint32_t port_index);

        /* Util for converting to attribute index based status code */
        static inline sai_status_t sai_test_invalid_attr_status_code (
                                                       sai_status_t status,
                                                       unsigned int attr_index)
        {
            return (status + SAI_STATUS_CODE (attr_index));
        }

        /* Method for retrieving the switch API table pointer */
        static inline sai_switch_api_t* switch_api_tbl_get (void)
        {
            return p_sai_switch_api_tbl;
        }

        /* Method for retrieving the Tunnel API table pointer */
        static inline sai_tunnel_api_t* tunnel_api_tbl_get (void)
        {
            return p_sai_tunnel_api_tbl;
        }

    protected:
        static void SetUpTestCase (void);
        static void TearDownTestCase (void);

        static const unsigned int max_tunnel_obj_attr_count = 18;
        static const unsigned int dflt_tunnel_obj_attr_count = 4;
        static const unsigned int max_tunnel_term_attr_count = 6;
        static const unsigned int dflt_tunnel_encap_nh_attr_count = 4;
        static const unsigned int SAI_TEST_MAX_PORTS = 256;
        static const unsigned int test_vlan = 100;

        static sai_object_id_t   dflt_vr_id;
        static sai_object_id_t   dflt_overlay_vr_id;
        static sai_object_id_t   dflt_port_rif_id;
        static sai_object_id_t   dflt_vlan_rif_id;
        static sai_object_id_t   dflt_overlay_rif_id;
        static sai_object_id_t   dflt_underlay_port_nh_id;
        static sai_object_id_t   dflt_underlay_vlan_nh_id;
        static sai_object_id_t   dflt_underlay_nhg_id;
        static const char       *nh_ip_str_1;
        static const char       *nh_ip_str_2;

    private:

        static sai_switch_api_t   *p_sai_switch_api_tbl;
        static sai_tunnel_api_t   *p_sai_tunnel_api_tbl;
        static unsigned int        port_count;
        static sai_object_id_t     port_list[SAI_TEST_MAX_PORTS];
};

#endif /* __SAI_TUNNEL_UNIT_TEST_H__ */
