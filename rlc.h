#ifndef RLC_H_INCLUDED
#define RLC_H_INCLUDED


union ccch_type{
srb_0_type ul_ccch;
int16_t a;
/*dl_ccch*/
};
typedef union ccch_type ccch_type;
                                                /**ccch_type data type is for CCCH cahnnel it is union because
                                                CCCH is bi-directional it may use UL-CCCH channel or DL-CCCH channel**/

void srb0_without_security(srb_0_type rrc_pdu); /**rrc_pdu is the value passed from rrc layer i.e srb0  **/
                                                /** srb0_without_security function is used to pass ccch
                                                channel from rlc to mac**/






#endif // RLC_H_INCLUDED

