
#include "../rrc/rrc.h"
#include "rlc.h"
#include"../mac/mac.h"

void srb0_without_security(srb_0_type rrc_pdu)
{
    ccch_type ccch;
    ccch.ul_ccch=rrc_pdu;   /** we gave ccch.ul_ccch =rrc pdu because ccch is the channel transmitted between
                            RRC and RLC it will carry the rrc pdu**/
    /*return ccch;*/

    mac_layer_call(ccch);   /**mac_layer_call()is defined in mac.c**/
                            /**passing ccch in above function because CCCH is a channel between RLC and MAC**/
}


