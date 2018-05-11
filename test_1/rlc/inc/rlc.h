#ifndef RLC_H_INCLUDED
#define RLC_H_INCLUDED
#include "../mac/mac.h"

typedef enum{
  srb_0_e=0x1,
  srb_1_e,
  srb_2_e,
  srb_spare_e,
  drb_0_e,
  drb_1_e,
  drb_2_e,
  drb_spare_e,
  srb_drb_max =0xd
}ccch_info_ele_enum_t;

typedef rrc_pdu_type srb_0_type;

typedef union {
srb_0_type srb_0;
#if 0
srb_1_type srb_1;
#endif // srb_1_type
}ul_ccch_type;

typedef union {
ul_ccch_type ul_ccch;
#if 0
dl_ccch_type dl_cch;
#endif // dl_ccch_type
}ccch_type;

typedef struct
{
  ccch_type             ccch;
  ccch_info_ele_enum_t   ccch_info_ele_enum;
}ccch_pdu_type;

/**rrc_pdu is the value passed from rrc layer i.e srb0  **/
 /** srb0_without_security function is used to pass ccch
 channel from rlc to mac**/
void rlc_ul_ccch(rrc_pdu_type rrc_pdu);

#if 0
void rlc_ul_ccch_srb_1(srb_1_type srb_1);
#endif // 0

//void rlc_stub(srb_to_add_type srb_to_add);


#endif // RLC_H_INCLUDED

