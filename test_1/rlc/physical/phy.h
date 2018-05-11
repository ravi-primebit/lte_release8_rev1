#ifndef PHY_H_INCLUDED
#define PHY_H_INCLUDED

void physical_layer_call(ul_sch_type mac_pdu);/**mac_pdu is ULSCH channel passed from MAC layer**/
                                              /**ul_sch_type is taken from MAC layer**/

struct pusch_type {
ul_sch_type pusch_sdu;
int rscp:7;

};

typedef struct pusch_type pusch_type;

void physical_layer_stub(rrc_connection_setup_type);



#endif // PHY_H_INCLUDED
