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
} rtDW_Chart_AutopilotLaws_d_T;

typedef struct {
  real_T u;
  real_T u_n;
} BlockIO_AutopilotLaws_T;

typedef struct {
  real_T Delay_DSTATE;
  real_T Delay1_DSTATE;
  real_T Delay_DSTATE_h;
  real_T Delay_DSTATE_n;
  real_T Delay_DSTATE_k;
  real_T Delay1_DSTATE_j;
  real_T Delay_DSTATE_hc;
  real_T Delay_DSTATE_j;
  real_T Delay1_DSTATE_m;
  real_T Delay_DSTATE_f;
  real_T Delay_DSTATE_l;
  real_T Delay_DSTATE_ni;
  real_T Delay1_DSTATE_jp;
  real_T Delay_DSTATE_fa;
  real_T Delay_DSTATE_hl;
  real_T Delay1_DSTATE_h;
  real_T Delay_DSTATE_kg;
  boolean_T Delay_DSTATE_lp[100];
  boolean_T Delay_DSTATE_h5[100];
  uint8_T icLoad;
  uint8_T icLoad_j;
  uint8_T is_active_c5_AutopilotLaws;
  uint8_T is_c5_AutopilotLaws;
  rtDW_Chart_AutopilotLaws_d_T sf_Chart_my;
  rtDW_Chart_AutopilotLaws_T sf_Chart_md;
  rtDW_Chart_AutopilotLaws_T sf_Chart_g;
  rtDW_Chart_AutopilotLaws_T sf_Chart_i;
  rtDW_Chart_AutopilotLaws_T sf_Chart_d;
  rtDW_Chart_AutopilotLaws_d_T sf_Chart_m;
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
  real_T ScheduledGain_BreakpointsForDimension1_a[6];
  real_T ScheduledGain_BreakpointsForDimension1_av[6];
  real_T ScheduledGain_BreakpointsForDimension1_f[6];
  real_T ScheduledGain_BreakpointsForDimension1_ah[5];
  real_T ScheduledGain_BreakpointsForDimension1_e[6];
  real_T ScheduledGain_BreakpointsForDimension1_ea[5];
  real_T ScheduledGain_BreakpointsForDimension1_n[6];
  real_T ScheduledGain_BreakpointsForDimension1_h[5];
  real_T LagFilter1_C1;
  real_T LagFilter_C1;
  real_T LagFilter_C1_l;
  real_T LagFilter_C1_n;
  real_T LagFilter_C1_nz;
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
  real_T ScheduledGain_Table_g[6];
  real_T ScheduledGain_Table_k[6];
  real_T ScheduledGain_Table_n[6];
  real_T ScheduledGain_Table_p[5];
  real_T ScheduledGain_Table_gp[6];
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
  real_T Gain_Gain_c;
  real_T Gain1_Gain_e;
  real_T Gain1_Gain_l;
  real_T Constant_Value_m;
  real_T Y_Y0;
  real_T Constant2_Value;
  real_T Gain4_Gain;
  real_T Y_Y0_n;
  real_T Switch_Threshold;
  real_T Switch_Threshold_k;
  real_T Gain1_Gain_g;
  real_T Gain1_Gain_a;
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
  real_T Constant3_Value_g;
  real_T Gain_Gain_f;
  real_T Constant2_Value_l;
  real_T Delay_InitialCondition;
  real_T Constant_Value_a;
  real_T Delay1_InitialCondition;
  real_T Constant3_Value_j;
  real_T Constant3_Value_d;
  real_T Gain1_Gain_gb;
  real_T Saturation_UpperSat_o;
  real_T Saturation_LowerSat_o;
  real_T Gain2_Gain_g;
  real_T Saturation1_UpperSat_g;
  real_T Saturation1_LowerSat_k;
  real_T Gain6_Gain;
  real_T Constant3_Value_m;
  real_T Constant3_Value_jz;
  real_T Gain1_Gain_f;
  real_T Gain_Gain_i;
  real_T Constant1_Value_e;
  real_T ROLLLIM1_tableData[5];
  real_T ROLLLIM1_bp01Data[5];
  real_T Constant3_Value_p;
  real_T Gain_Gain_ml;
  real_T Constant3_Value_o;
  real_T Gain_Gain_fh;
  real_T Constant3_Value_oe;
  real_T Constant3_Value_b;
  real_T Gain_Gain_nu;
  real_T Saturation_UpperSat_k;
  real_T Saturation_LowerSat_p;
  real_T Gain2_Gain_f;
  real_T Gain1_Gain_n;
  real_T Gain_Gain_ai;
  real_T Constant_Value_c;
  real_T Constant3_Value_da;
  real_T Constant3_Value_a;
  real_T Gain1_Gain_m;
  real_T Saturation_UpperSat_m;
  real_T Saturation_LowerSat_k;
  real_T Saturation1_UpperSat_i;
  real_T Saturation1_LowerSat_g;
  real_T Constant3_Value_ax;
  real_T Constant3_Value_n;
  real_T Gain3_Gain;
  real_T Gain_Gain_k;
  real_T Constant_Value_e;
  real_T Constant3_Value_gm;
  real_T Constant3_Value_mj;
  real_T Gain3_Gain_i;
  real_T Delay_InitialCondition_c;
  real_T Constant_Value_i;
  real_T Delay1_InitialCondition_f;
  real_T Gain_Gain_h;
  real_T Constant_Value_p;
  real_T Constant2_Value_h;
  real_T Gain1_Gain_k;
  real_T Delay_InitialCondition_g;
  real_T Constant_Value_ck;
  real_T Delay1_InitialCondition_o;
  real_T Saturation_UpperSat_m0;
  real_T Saturation_LowerSat_ou;
  real_T Constant_Value_b;
  real_T Gain_Gain_ft;
  real_T Saturation_UpperSat_n;
  real_T Saturation_LowerSat_d;
  real_T ftmintoms_Gain;
  real_T kntoms_Gain;
  real_T Saturation_UpperSat_a;
  real_T Saturation_LowerSat_m;
  real_T Gain_Gain_hl;
  real_T Constant_Value_b0;
  real_T Gain_Gain_e;
  real_T ftmintoms_Gain_e;
  real_T kntoms_Gain_e;
  real_T Saturation_UpperSat_l;
  real_T Saturation_LowerSat_l;
  real_T Gain_Gain_i3;
  real_T Gain1_Gain_mk;
  real_T Gain_Gain_j;
  real_T Gain_Gain_ei;
  real_T Gain1_Gain_h;
  real_T Saturation_UpperSat_j;
  real_T Saturation_LowerSat_b;
  real_T Constant_Value_k;
  real_T ftmintoms_Gain_e5;
  real_T kntoms_Gain_i;
  real_T Saturation_UpperSat_ad;
  real_T Saturation_LowerSat_h;
  real_T Gain_Gain_m5;
  real_T ftmintoms_Gain_j;
  real_T kntoms_Gain_a;
  real_T Saturation_UpperSat_ah;
  real_T Saturation_LowerSat_dg;
  real_T Gain_Gain_jh;
  real_T Gain1_Gain_ff;
  real_T Gain_Gain_c3;
  real_T Gain1_Gain_j;
  real_T Gain3_Gain_o;
  real_T Delay_InitialCondition_p;
  real_T Constant_Value_o;
  real_T Delay1_InitialCondition_j;
  real_T Constant3_Value_nc;
  real_T Constant_Value_pg;
  real_T ftmintoms_Gain_a;
  real_T kntoms_Gain_av;
  real_T Saturation_UpperSat_ku;
  real_T Saturation_LowerSat_e;
  real_T Gain_Gain_b0;
  real_T Switch_Threshold_c;
  real_T Constant1_Value_d;
  real_T Gain1_Gain_d;
  real_T Gain_Gain_n0;
  real_T Gain_Gain_o;
  real_T Gain1_Gain_fr;
  real_T Saturation_UpperSat_e;
  real_T Saturation_LowerSat_py;
  real_T Constant_Value_in;
  real_T ftmintoms_Gain_ef;
  real_T kntoms_Gain_f;
  real_T Saturation_UpperSat_ax;
  real_T Saturation_LowerSat_j;
  real_T Gain_Gain_fa;
  real_T Constant1_Value_i;
  real_T Gain_Gain_kg;
  real_T Gain_Gain_b2;
  real_T Constant2_Value_h1;
  real_T Gain1_Gain_c;
  real_T Delay_InitialCondition_l;
  real_T Constant_Value_j;
  real_T Delay1_InitialCondition_o1;
  real_T Saturation_UpperSat_b;
  real_T Saturation_LowerSat_hd;
  real_T Constant_Value_pk;
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
  void AutopilotLaws_Chart_j_Init(rtDW_Chart_AutopilotLaws_d_T *localDW);
  void AutopilotLaws_Chart_m(real_T rtu_right, real_T rtu_left, boolean_T rtu_use_short_path, real_T *rty_out,
    rtDW_Chart_AutopilotLaws_d_T *localDW);
  void AutopilotLaws_Voter(real_T rtu_u1, real_T rtu_u2, real_T rtu_u3, real_T *rty_Y);
};

#endif

