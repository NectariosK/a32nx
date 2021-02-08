#ifndef RTW_HEADER_AutopilotLaws_h_
#define RTW_HEADER_AutopilotLaws_h_
#include <cmath>
#include <cstring>
#ifndef AutopilotLaws_COMMON_INCLUDES_
# define AutopilotLaws_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "AutopilotLaws_types.h"

typedef struct {
  uint8_T is_active_c3_AutopilotLaws;
  uint8_T is_c3_AutopilotLaws;
} rtDW_Chart_AutopilotLaws_T;

typedef struct {
  uint8_T is_active_c1_AutopilotLaws;
  uint8_T is_c1_AutopilotLaws;
} rtDW_Chart_AutopilotLaws_i_T;

typedef struct {
  real_T u;
  real_T u_n;
} BlockIO_AutopilotLaws_T;

typedef struct {
  real_T Delay_DSTATE;
  real_T Delay1_DSTATE;
  real_T Delay_DSTATE_h;
  real_T Delay_DSTATE_f;
  real_T Delay_DSTATE_n;
  real_T Delay1_DSTATE_e;
  real_T Delay_DSTATE_hc;
  real_T Delay_DSTATE_e;
  real_T Delay1_DSTATE_a;
  real_T Delay_DSTATE_fr;
  real_T Delay_DSTATE_m;
  real_T Delay_DSTATE_k;
  real_T Delay1_DSTATE_d;
  real_T Delay_DSTATE_o;
  real_T Delay_DSTATE_l;
  real_T Delay1_DSTATE_h;
  real_T Delay_DSTATE_b;
  boolean_T Delay_DSTATE_lp[100];
  boolean_T Delay_DSTATE_h5[100];
  uint8_T icLoad;
  uint8_T icLoad_b;
  uint8_T is_active_c5_AutopilotLaws;
  uint8_T is_c5_AutopilotLaws;
  rtDW_Chart_AutopilotLaws_i_T sf_Chart_ol;
  rtDW_Chart_AutopilotLaws_T sf_Chart_o;
  rtDW_Chart_AutopilotLaws_T sf_Chart_jk;
  rtDW_Chart_AutopilotLaws_T sf_Chart_h;
  rtDW_Chart_AutopilotLaws_T sf_Chart_g;
  rtDW_Chart_AutopilotLaws_i_T sf_Chart_j;
  rtDW_Chart_AutopilotLaws_T sf_Chart;
} D_Work_AutopilotLaws_T;

typedef struct {
  ap_laws_input in;
} ExternalInputs_AutopilotLaws_T;

typedef struct {
  ap_laws_output out;
} ExternalOutputs_AutopilotLaws_T;

struct Parameters_AutopilotLaws_T_ {
  ap_laws_output ap_laws_output_MATLABStruct;
  real_T ScheduledGain_BreakpointsForDimension1[3];
  real_T ScheduledGain_BreakpointsForDimension1_e[6];
  real_T ScheduledGain_BreakpointsForDimension1_k[6];
  real_T ScheduledGain_BreakpointsForDimension1_ep[6];
  real_T ScheduledGain_BreakpointsForDimension1_a[5];
  real_T ScheduledGain_BreakpointsForDimension1_o[6];
  real_T ScheduledGain_BreakpointsForDimension1_ea[5];
  real_T ScheduledGain_BreakpointsForDimension1_p[6];
  real_T ScheduledGain_BreakpointsForDimension1_h[5];
  real_T LagFilter1_C1;
  real_T LagFilter_C1;
  real_T LagFilter_C1_l;
  real_T LagFilter_C1_n;
  real_T LagFilter_C1_f;
  real_T DiscreteTimeIntegratorVariableTs_Gain;
  real_T DiscreteDerivativeVariableTs_Gain;
  real_T VS_Gain;
  real_T VS_Gain_a;
  real_T VS_Gain_j;
  real_T VS_Gain_h;
  real_T DiscreteDerivativeVariableTs_Gain_l;
  real_T VS_Gain_e;
  real_T VS_Gain_c;
  real_T DiscreteTimeIntegratorVariableTs_InitialCondition;
  real_T DiscreteDerivativeVariableTs_InitialCondition;
  real_T RateLimiterVariableTs_InitialCondition;
  real_T DiscreteDerivativeVariableTs_InitialCondition_h;
  real_T RateLimiterVariableTs_InitialCondition_p;
  real_T DiscreteTimeIntegratorVariableTs_LowerLimit;
  real_T ScheduledGain_Table[3];
  real_T ScheduledGain_Table_b[6];
  real_T ScheduledGain_Table_m[6];
  real_T ScheduledGain_Table_j[6];
  real_T ScheduledGain_Table_p[5];
  real_T ScheduledGain_Table_d[6];
  real_T ScheduledGain_Table_pf[5];
  real_T ScheduledGain_Table_i[6];
  real_T ScheduledGain_Table_ir[5];
  real_T DiscreteTimeIntegratorVariableTs_UpperLimit;
  real_T Subsystem_Value;
  real_T Subsystem_Value_n;
  real_T CompareToConstant_const;
  real_T CompareToConstant_const_k;
  real_T CompareToConstant5_const;
  real_T CompareToConstant4_const;
  real_T CompareToConstant5_const_e;
  real_T CompareToConstant_const_j;
  real_T RateLimiterVariableTs_lo;
  real_T RateLimiterVariableTs_lo_o;
  real_T RateLimiterVariableTs_up;
  real_T RateLimiterVariableTs_up_i;
  boolean_T CompareToConstant_const_h;
  boolean_T CompareToConstant_const_e;
  real_T Constant_Value;
  real_T Gain_Gain;
  real_T Gain1_Gain;
  real_T Constant1_Value;
  real_T Gain_Gain_a;
  real_T Gain_Gain_b;
  real_T Gain5_Gain;
  real_T beta_Value;
  real_T beta_Value_m;
  real_T beta_Value_b;
  real_T beta_Value_e;
  real_T beta_Value_ed;
  real_T Constant3_Value;
  real_T Gain_Gain_an;
  real_T Gain1_Gain_i;
  real_T Gain1_Gain_l;
  real_T Constant2_Value;
  real_T Gain4_Gain;
  real_T Switch_Threshold;
  real_T Gain1_Gain_c;
  real_T Gain_Gain_c;
  real_T Switch_Threshold_k;
  real_T Constant_Value_m;
  real_T Y_Y0;
  real_T Y_Y0_n;
  real_T Gain1_Gain_p;
  real_T GainTheta_Gain;
  real_T GainTheta1_Gain;
  real_T Gain_Gain_d;
  real_T Gainqk_Gain;
  real_T Gain_Gain_m;
  real_T Gain_Gain_de;
  real_T Gainpk_Gain;
  real_T Gain_Gain_n;
  real_T Constant1_Value_b;
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Gain1_Gain_ll;
  real_T Saturation1_UpperSat;
  real_T Saturation1_LowerSat;
  real_T Gain2_Gain;
  real_T Constant3_Value_c;
  real_T Gain_Gain_j;
  real_T Constant2_Value_l;
  real_T Delay_InitialCondition;
  real_T Constant_Value_f;
  real_T Delay1_InitialCondition;
  real_T Constant3_Value_o;
  real_T Constant3_Value_ox;
  real_T Gain1_Gain_f;
  real_T Saturation_UpperSat_o;
  real_T Saturation_LowerSat_o;
  real_T Gain2_Gain_g;
  real_T Saturation1_UpperSat_g;
  real_T Saturation1_LowerSat_k;
  real_T Gain6_Gain;
  real_T Constant3_Value_o2;
  real_T Constant3_Value_j;
  real_T Gain1_Gain_fq;
  real_T Gain_Gain_jq;
  real_T Constant1_Value_e;
  real_T ROLLLIM1_tableData[5];
  real_T ROLLLIM1_bp01Data[5];
  real_T Constant3_Value_e;
  real_T Gain_Gain_o;
  real_T Constant3_Value_b;
  real_T Gain_Gain_bn;
  real_T Constant3_Value_p;
  real_T Constant3_Value_h;
  real_T Gain_Gain_nu;
  real_T Saturation_UpperSat_k;
  real_T Saturation_LowerSat_p;
  real_T Gain2_Gain_f;
  real_T Gain1_Gain_n;
  real_T Gain_Gain_b2;
  real_T Constant_Value_c;
  real_T Constant3_Value_ou;
  real_T Constant3_Value_pr;
  real_T Gain1_Gain_g;
  real_T Saturation_UpperSat_m;
  real_T Saturation_LowerSat_k;
  real_T Saturation1_UpperSat_i;
  real_T Saturation1_LowerSat_g;
  real_T Constant3_Value_ju;
  real_T Constant3_Value_f;
  real_T Gain3_Gain;
  real_T Gain_Gain_p;
  real_T Constant_Value_e;
  real_T Constant3_Value_ot;
  real_T Constant3_Value_cr;
  real_T Gain3_Gain_i;
  real_T Delay_InitialCondition_e;
  real_T Constant_Value_h;
  real_T Delay1_InitialCondition_a;
  real_T Gain_Gain_l;
  real_T Constant_Value_p;
  real_T Constant2_Value_h;
  real_T Gain1_Gain_k;
  real_T Delay_InitialCondition_p;
  real_T Constant_Value_ey;
  real_T Delay1_InitialCondition_d;
  real_T Saturation_UpperSat_b;
  real_T Saturation_LowerSat_j;
  real_T Constant_Value_cc;
  real_T Gain_Gain_f;
  real_T Saturation_UpperSat_n;
  real_T Saturation_LowerSat_d;
  real_T ftmintoms_Gain;
  real_T kntoms_Gain;
  real_T Saturation_UpperSat_kv;
  real_T Saturation_LowerSat_a;
  real_T Gain_Gain_og;
  real_T Constant_Value_b;
  real_T Gain_Gain_e;
  real_T ftmintoms_Gain_o;
  real_T kntoms_Gain_e;
  real_T Saturation_UpperSat_p;
  real_T Saturation_LowerSat_c;
  real_T Gain_Gain_nz;
  real_T Gain1_Gain_b;
  real_T Gain_Gain_jc;
  real_T Gain_Gain_k;
  real_T Gain_Gain_h;
  real_T Gain1_Gain_j;
  real_T Saturation_UpperSat_e;
  real_T Saturation_LowerSat_m;
  real_T Constant_Value_k;
  real_T ftmintoms_Gain_c;
  real_T kntoms_Gain_i;
  real_T Saturation_UpperSat_l;
  real_T Saturation_LowerSat_me;
  real_T Gain_Gain_dy;
  real_T ftmintoms_Gain_ok;
  real_T kntoms_Gain_a;
  real_T Saturation_UpperSat_md;
  real_T Saturation_LowerSat_mz;
  real_T Gain_Gain_lg;
  real_T Gain1_Gain_jl;
  real_T Gain3_Gain_o;
  real_T Delay_InitialCondition_n;
  real_T Constant_Value_eu;
  real_T Delay1_InitialCondition_n;
  real_T Constant3_Value_n;
  real_T Constant_Value_pg;
  real_T ftmintoms_Gain_a;
  real_T kntoms_Gain_av;
  real_T Saturation_UpperSat_g;
  real_T Saturation_LowerSat_p3;
  real_T Gain_Gain_c1;
  real_T Constant1_Value_d;
  real_T Gain1_Gain_lf;
  real_T Gain_Gain_cu;
  real_T Gain_Gain_ej;
  real_T Gain_Gain_h2;
  real_T Gain1_Gain_h;
  real_T Saturation_UpperSat_bc;
  real_T Saturation_LowerSat_au;
  real_T Constant_Value_i;
  real_T ftmintoms_Gain_k;
  real_T kntoms_Gain_f;
  real_T Saturation_UpperSat_pe;
  real_T Saturation_LowerSat_b;
  real_T Gain_Gain_f5;
  real_T Constant1_Value_i;
  real_T Constant2_Value_h1;
  real_T Gain1_Gain_a;
  real_T Delay_InitialCondition_p2;
  real_T Constant_Value_el;
  real_T Delay1_InitialCondition_b;
  real_T Saturation_UpperSat_j;
  real_T Saturation_LowerSat_pj;
  real_T Constant_Value_d;
  boolean_T Delay_InitialCondition_h;
  boolean_T Delay_InitialCondition_b;
  uint8_T ManualSwitch_CurrentSetting;
  uint8_T ManualSwitch_CurrentSetting_b;
};

extern const ap_laws_input AutopilotLaws_rtZap_laws_input;
extern const ap_laws_output AutopilotLaws_rtZap_laws_output;
class AutopilotLawsModelClass {
 public:
  ExternalInputs_AutopilotLaws_T AutopilotLaws_U;
  ExternalOutputs_AutopilotLaws_T AutopilotLaws_Y;
  void initialize();
  void step();
  void terminate();
  AutopilotLawsModelClass();
  ~AutopilotLawsModelClass();
 private:
  static Parameters_AutopilotLaws_T AutopilotLaws_P;
  BlockIO_AutopilotLaws_T AutopilotLaws_B;
  D_Work_AutopilotLaws_T AutopilotLaws_DWork;
  void AutopilotLaws_Chart_Init(rtDW_Chart_AutopilotLaws_T *localDW);
  void AutopilotLaws_Chart(real_T rtu_right, real_T rtu_left, real_T rtu_use_short_path, real_T *rty_out,
    rtDW_Chart_AutopilotLaws_T *localDW);
  void AutopilotLaws_Chart_p_Init(rtDW_Chart_AutopilotLaws_i_T *localDW);
  void AutopilotLaws_Chart_j(real_T rtu_right, real_T rtu_left, boolean_T rtu_use_short_path, real_T *rty_out,
    rtDW_Chart_AutopilotLaws_i_T *localDW);
};

#endif

