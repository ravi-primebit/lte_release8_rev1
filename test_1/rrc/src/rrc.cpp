//#include "rrc\inc\rrc.h"
#include <stdio.h>
#include "rrc.h"
#include "../rlc/rlc.h"     /**RLC header is included because srb0_without security is defined in RLC,if you don't declare
                            you will get implicit declaration error**/

void rrc_init()
{
  /* variable to have srb_0 values*/
  rrc_pdu_type rrc_pdu;

  /*intializing RRC connection request */
  rrc_pdu.rrc_procedure.rrc_connection_request.establishment_cause             = mt_Access;
  rrc_pdu.rrc_procedure.rrc_connection_request.initial_ue_identity.randomValue = 20;
  rrc_pdu.rrc_info_ele_for_ulcch_enum = rrc_conn_req_e;

  /**printf("random value %ld",srb_0.rrc_connection_request.initial_ue_identity.randomValue);**/
  if (rrc_pdu.rrc_info_ele_for_ulcch_enum == rrc_conn_req_e)
  {
    printf("\nSRB0 is passed to RLC");
    /**here function is passed whose definition is in rlc.c**/
     /**here we are passing srb_0 argument because SRB carries message from RRC to RLC**/
     rlc_ul_ccch(rrc_pdu);
  }
  else
  {
    printf("rrc crash");
  }
}

void rrc_stub(int srb0)
{
    printf("\nrrc_stub= %d",srb0);
}
