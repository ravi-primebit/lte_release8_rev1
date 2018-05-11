#include<stdio.h>
#include "../rrc/rrc.h"
#include "rlc.h"
#include "../mac/mac.h"
#include "../sturb/stub.h"
void rlc_ul_ccch(rrc_pdu_type rrc_pdu)
{
    ccch_pdu_type ccch_pdu;

    /** we gave ccch.ul_ccch =rrc pdu because ccch is the channel transmitted between
     RRC and RLC it will carry the rrc pdu**/
    ccch_pdu.ccch.ul_ccch.srb_0 = rrc_pdu;
    ccch_pdu.ccch_info_ele_enum = srb_0_e;
    /*return ccch;*/
   if(ccch_pdu.ccch_info_ele_enum == srb_0_e)
   {
       printf("\nccch channel is passed to mac layer");
       //mac_layer_call(ccch);
   }
   else
   {
       printf("crash in mac layer");
   }
      /**mac_layer_call()is defined in mac.c**/
                            /**passing ccch in above function because CCCH is a channel between RLC and MAC**/
}

/*void rlc_stub(srb_to_add_type rlc_sdu)
{
    int srb0;
    srb0=rlc_sdu.srbidentity;
    printf("srb.identity=%d",rlc_sdu.srbidentity);
rrc_stub(srb0);
}*/
