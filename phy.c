#include <stdio.h>
#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "../mac/mac.h"
#include "phy.h"
void physical_layer_call(ul_sch_type mac_pdu)/**mac_pdu is USLCH channel passed from MAC layer**/
{
    printf("\n%d",mac_pdu.b);

                                            /**the below if else statement is written just to check
                                                whether the arguments passed correct or not**/

    if((mac_pdu.ul_ccch_.ul_ccch.rrc_connection_request.establishment_cause == mt_Access)&&
               (mac_pdu.ul_ccch_.ul_ccch.rrc_connection_request.initial_ue_identity.randomValue==20))
            {
                printf("\n argument passed");
            }
    else
        {
           printf("\nargument not passed");


        }
}
