#include <stdio.h>
#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "../mac/mac.h"
#include "../physical/phy.h"
#include "stub.h"

 rrc_connection_setup_type rrc_connection_setup;
void radio_frame()
        /**created radio_frame to send PUSCH channel info to stub,once stub got PUSCH it will
            work as enodeb and send pdsch channel info to PHYSICAL layer**/
{

    rrc_connection_setup.radio_resource_config.srb_to_add.srbidentity=1;
    rrc_connection_setup.radio_resource_config.srb_to_add.RLC_config.Am_rlc.Dl_am_rlc.T_reordering=30;
    /*if((pusch.pusch_sdu.ul_ccch_.ul_ccch.rrc_connection_request.establishment_cause == mt_Access)&&
               (pusch.pusch_sdu.ul_ccch_.ul_ccch.rrc_connection_request.initial_ue_identity.randomValue==20))

    {*/
printf("\nsrbidentity=%d",rrc_connection_setup.radio_resource_config.srb_to_add.srbidentity);
physical_layer_stub(rrc_connection_setup);
    /*}
        else
            printf("crash in stub");*/
}
