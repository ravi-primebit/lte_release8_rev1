#ifndef STURB_H_INCLUDED
#define STURB_H_INCLUDED



enum T_status_prohibited{ms_s1=5,ms_s2=10,ms_s3=15,ms_4=20,ms_5=25,ms_s6=30,ms_s7=35,ms_s8=40};

/**status prohibit is an acknowledgement sent from RLC receiver to RLC transmitter about PDCP packets**/
/**T_status_prohibit is a timer which tells the gap(in milli seconds) to be between two acknowledgments**/
/**T_status_prohibit value will be between 5 to 500 ms,but as of now i took only upto 40 ms**/

typedef enum T_status_prohibited t_status_prohibited;

enum T_reordering {ms_t1=5,ms_t2=10,ms_t3=15,ms_t4=20,ms_t5=25,ms_t6=30,ms_t7=35,ms_t8=40};

/**T_reordering is a timer used to  re-order the PDCP packets, if the timer expires before arranging all the packets
 it sends un-acknowledgment using status report**/

 typedef enum T_reordering t_reordering;

 /**info.elements present in am rlc
    pollbyte
    pollpdu
    T_poll_retransmit
    SN_field **/

/**struct ul_am_rlc {
    T_poll_retransmit T_poll_retransmit;
    Poll_pdu Poll_pdu;
    Poll_byte Poll_byte;
    SN_field SN_field;
};
**/
struct dl_am_rlc{
    t_status_prohibited T_status_prohibited;
    t_reordering T_reordering;

};
/**dl_am_rlc is one of the info element in am_rlc**/

typedef struct dl_am_rlc dl_am_rlc;

struct am_rlc
{
    dl_am_rlc Dl_am_rlc;
    /**ul_am_rlc Ul_am_rlc;**/
};
typedef struct am_rlc am_rlc;

union rlc_config_type
{
 am_rlc Am_rlc;
 /**um_rlc Um_rlc;**/

};
typedef union rlc_config_type rlc_config_type;

typedef struct {
int srbidentity :3;
rlc_config_type RLC_config;

}srb_to_add_type;


typedef struct  {
int ccch;
int dcch;
}mac_lcid;          /**here we have created mac_lcid structure the elements in it are just for example,it will have othe rinfo.elements**/


typedef struct {
 srb_to_add_type srb_to_add;
 mac_lcid lcid;
 /**mac config**/
 /**physical config**/
 /**drb to add**/
}radio_resource_config_type;
/**we created a stucture and saved it as radio_resource_config_type**/

typedef struct{
radio_resource_config_type radio_resource_config;

}rrc_connection_setup_type;
#endif // STURB_H_INCLUDED
void radio_frame();
