#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "mac.h"
#include"../physical/phy.h"
void mac_layer_call(ccch_type rlc_pdu)  /**ccch_type is taken from rlc header file**/
                                        /**rlc_pdu is ccch channel passed rom rlc**/
{
ul_sch_type ul_sch;                     /**ul_sch variable is created and passed to physical layer**/

ul_sch.ul_ccch_=rlc_pdu;
ul_sch.b=20;                            /**here we gave ul_sch.b because ul_sch contains different elements and
                                        it will be of struct  so we gave another element in ul_sch**/
physical_layer_call(ul_sch);
/*return ul_sch;*/
}
