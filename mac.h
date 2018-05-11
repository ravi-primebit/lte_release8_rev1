#ifndef MAC_H_INCLUDED
#define MAC_H_INCLUDED

void mac_layer_call(ccch_type);
struct ul_sch_type{
ccch_type ul_ccch_;
int32_t b;
/*extensions*/
};                          /**ul_sch_type is ULSCH channel which will carry other info.elements along with ULCCH
                            so it is created as structure**/
typedef struct ul_sch_type ul_sch_type;

#endif // MAC_H_INCLUDED
