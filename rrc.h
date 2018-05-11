#ifndef RRC_H
#define RRC_H

#include <stdint.h>

#define RANDOM_VLAUE 0xff

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
  uint8_t mmec;
  uint32_t m_tmsi;
}s_tmsi_type;

typedef union {
  s_tmsi_type s_tmsi;
  uint64_t randomValue;
}ue_identity_type;              /**in RRC Connection Request we send either S-TMSI or random value so we created
                                ue_identity as union*/

typedef struct  {
  ue_identity_type initial_ue_identity;
  establishment_cause_enum_type establishment_cause;
}rrc_connection_request_type;

union srbtype{
rrc_connection_request_type rrc_connection_request;
#if 0
rrc_conc_reestablishment_req_type rrc_conc_reestablishment_req;
#endif // 0
};
typedef union srbtype srb_0_type;


/*srb_0_type srb0_func();*/
void rrc_init();                /**RRC_Init is a function used to pass SRB0 to RLC Layer**/
                                /**srb_0 is a union which have info.elements as RRC Connection Request**/


#endif
