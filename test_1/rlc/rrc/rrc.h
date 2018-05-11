#ifndef RRC_H
#define RRC_H

#include <stdint.h>

typedef enum{
rrc_conn_req_e = 0x1,
rrc_conn_setup_e,
rrc_setup_comp_e,
rrc_ie_max = 0xd
}rrc_info_ele_for_ulcch_enum_t;

typedef enum{
  emergency = 0x1,
  highPriorityAccess,
  mt_Access,
  mo_Signalling,
  mo_Data,
  spare1,
  spare2,
  establishment_cause_max=0xd
}establishment_cause_enum_type;  /**as we have only six values in establishment cause and we have select only one value
                                we have taken establishment cause as enum type**/

typedef struct {
  int mmec;
  int m_tmsi;
}s_tmsi_type;

typedef union {
  s_tmsi_type s_tmsi;
  long randomValue;
}ue_identity_type;              /**in RRC Connection Request we send either S-TMSI or random value so we created
                                ue_identity as union*/

typedef struct  {
  ue_identity_type initial_ue_identity;
  establishment_cause_enum_type establishment_cause;
}rrc_connection_request_type;

typedef union {
  rrc_connection_request_type rrc_connection_request;
  #if 0
  rrc_conc_reestablishment_req_type rrc_conc_reestablishment_req;
  #endif // 0
}rrc_procedure_type;

typedef struct
{
  rrc_procedure_type             rrc_procedure;
  rrc_info_ele_for_ulcch_enum_t  rrc_info_ele_for_ulcch_enum;
}rrc_pdu_type;


/*srb_0_type srb0_func();*/
void rrc_init();                /**RRC_Init is a function used to pass SRB0 to RLC Layer**/
                                /**srb_0 is a union which have info.elements as RRC Connection Request**/


void rrc_stub(int);
#endif
