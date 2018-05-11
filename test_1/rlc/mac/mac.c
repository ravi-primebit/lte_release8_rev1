#include <stdio.h>
#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "mac.h"
#include "../physical/phy.h"
#include "../sturb/stub.h"

void mac_layer_call(ccch_type rlc_pdu)  /**ccch_type is taken from rlc header file**/
                                        /**rlc_pdu is ccch channel passed rom rlc**/
{
ul_sch_type ul_sch;                     /**ul_sch variable is created and passed to physical layer**/

ul_sch.ul_ccch_=rlc_pdu;
ul_sch.b=20;                            /**here we gave ul_sch.b because ul_sch contains different elements and
                                        it will be of struct  so we gave another element in ul_sch**/
if(ul_sch.b<=20)
{
    physical_layer_call(ul_sch);
/*return ul_sch;*/
}
else
    {
        printf("\ncrash\nwrong argument passed can't call physical layer");
}
}
void mac_layer_stub(radio_resource_config_type physical_pdu)
{

    srb_to_add_type ccch;
    ccch.srbidentity=physical_pdu.srb_to_add.srbidentity;
    rlc_stub(ccch);

}
