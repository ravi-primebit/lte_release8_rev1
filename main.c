#include <stdio.h>
#include "../rrc/rrc.h"
#include "../rlc/rlc.h"
#include "../mac/mac.h"
#include "../physical/phy.h"



int main()
{

  printf("starting project");/**project starts to compile from here**/

  /*srb_0_type srb_0;
  srb_0=srb0_func();*/

  rrc_init();                 /**srb0_func() is called which is defined in rrc.c**/

  /*ccch_type ccch;
  ccch=srb0_without_security(srb_0);
  ul_sch_type ul_sch;
  ul_sch=ccch_func(ccch);
  ul_sch_func(ul_sch);*/

}
