//#include "rrc\inc\rrc.h"
#include "rrc.h"
#include "../rlc/rlc.h"     /**RLC header is included because srb0_without security is defined in RLC,if you don't declare
                            you will get implicit declaration error**/
#include <stdio.h>
srb_0_type srb_0;
void rrc_init()
{

srb_0.rrc_connection_request.establishment_cause = mt_Access;
srb_0.rrc_connection_request.initial_ue_identity.randomValue= 0xff;
/*return srb_0;*/
srb0_without_security(srb_0);/**here function is passed whose definition is in rlc.c**/
                             /**here we are passing srb_0 argument because SRB carries message from RRC to RLC**/

}
