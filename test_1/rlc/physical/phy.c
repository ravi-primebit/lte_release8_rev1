#include <stdio.h>
#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "../mac/mac.h"
#include "phy.h"
#include "../sturb/stub.h"
void physical_layer_call(ul_sch_type mac_pdu)/**mac_pdu is USLCH channel passed from MAC layer**/
{
    /*while(1)
    {
    pusch_type pusch;
    int rs;

    printf("\n%d",mac_pdu.b);*/

                                            /**the below if else statement is written just to check
                                                whether the arguments passed correct or not**/

    if((mac_pdu.ul_ccch_.ul_ccch.rrc_connection_request.establishment_cause == mt_Access)&&
               (mac_pdu.ul_ccch_.ul_ccch.rrc_connection_request.initial_ue_identity.randomValue==20))
            {
                printf("\nargument passed");
            }
    else
        {
           printf("\ncrash in physical layer");


        }


/*pusch.pusch_sdu=mac_pdu;
pusch.rscp=rs;

printf("\nenter the reference signal:");

scanf("%d",&rs);*/ /**here we are giving rs i.e rscp manually**/

/*printf("%d\n",(rs>-120)&&(rs<0));*/
        /**rs is rscp of the ue,rscp should be between 0 and -120 if it exceeds -120 it means
                radio quality is poor so unable to send frame**/

/*if((rs>-120)&&(rs<0))
    {
        radio_frame(pusch);
        break;
    }
else
    printf("\npoor rscp can't transmit pdsch to enodeb");
}*/
}
/**void physical_layer_sturb(rrc_connection_setup_type pdsch)
{
Radio_resource_config_type dlsch;
dlsch=pdsch.Radio_resource_config;
mac_layer_stub(dlsch);

}**/
void physical_layer_stub(rrc_connection_setup_type pdsch)
{
    radio_resource_config_type dlsch;
    dlsch=pdsch.radio_resource_config;
    if(dlsch.srb_to_add.srbidentity==1)
    {
        printf("dlsch=%d",dlsch.srb_to_add.srbidentity);
      mac_layer_stub(dlsch);

    }
    else
    {
         printf("crash in physical stub");


    }
}
