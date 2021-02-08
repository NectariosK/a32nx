#include "AutopilotLaws.h"
#include "AutopilotLaws_private.h"
#include "look1_binlxpw.h"
#include "rt_modd.h"

const uint8_T AutopilotLaws_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T AutopilotLaws_IN_any = 1U;
const uint8_T AutopilotLaws_IN_left = 2U;
const uint8_T AutopilotLaws_IN_right = 3U;
const uint8_T AutopilotLaws_IN_NO_ACTIVE_CHILD_o = 0U;
const uint8_T AutopilotLaws_IN_any_a = 1U;
const uint8_T AutopilotLaws_IN_left_a = 2U;
const uint8_T AutopilotLaws_IN_right_l = 3U;
const uint8_T AutopilotLaws_IN_InAir = 1U;
const uint8_T AutopilotLaws_IN_NO_ACTIVE_CHILD_n = 0U;
const uint8_T AutopilotLaws_IN_OnGround = 2U;
const ap_laws_output AutopilotLaws_rtZap_laws_output = {
  {
    0.0,
    0.0
  },

  {
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    false,
    0.0,
    0.0,
    0.0,
    false,
    0.0,
    false,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    false,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0
  },

  {
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    false,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    false
  },

  {
    0.0,

    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    }
  }
} ;

const ap_laws_input AutopilotLaws_rtZap_laws_input = { { 0.0, 0.0 }, { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, false, 0.0, 0.0, 0.0, false, 0.0, false, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, false, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, false, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, false } };

void AutopilotLawsModelClass::AutopilotLaws_Chart_Init(rtDW_Chart_AutopilotLaws_T *localDW)
{
  localDW->is_active_c3_AutopilotLaws = 0U;
  localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_NO_ACTIVE_CHILD;
}

void AutopilotLawsModelClass::AutopilotLaws_Chart(real_T rtu_right, real_T rtu_left, real_T rtu_use_short_path, real_T
  *rty_out, rtDW_Chart_AutopilotLaws_T *localDW)
{
  real_T tmp;
  real_T tmp_0;
  if (localDW->is_active_c3_AutopilotLaws == 0U) {
    localDW->is_active_c3_AutopilotLaws = 1U;
    localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_any;
    if (std::abs(rtu_left) < std::abs(rtu_right)) {
      *rty_out = rtu_left;
    } else {
      *rty_out = rtu_right;
    }
  } else {
    switch (localDW->is_c3_AutopilotLaws) {
     case AutopilotLaws_IN_any:
      tmp = std::abs(rtu_right);
      tmp_0 = std::abs(rtu_left);
      if ((rtu_use_short_path == 0.0) && (tmp < tmp_0) && (tmp >= 10.0) && (tmp <= 20.0)) {
        localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_right;
        *rty_out = rtu_right;
      } else if ((rtu_use_short_path == 0.0) && (tmp_0 < tmp) && (tmp_0 >= 10.0) && (tmp_0 <= 20.0)) {
        localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_left;
        *rty_out = rtu_left;
      } else if (tmp_0 < tmp) {
        *rty_out = rtu_left;
      } else {
        *rty_out = rtu_right;
      }
      break;

     case AutopilotLaws_IN_left:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if ((rtu_use_short_path != 0.0) || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_any;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_left;
      }
      break;

     default:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if ((rtu_use_short_path != 0.0) || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_AutopilotLaws = AutopilotLaws_IN_any;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_right;
      }
      break;
    }
  }
}

void AutopilotLawsModelClass::AutopilotLaws_Chart_p_Init(rtDW_Chart_AutopilotLaws_i_T *localDW)
{
  localDW->is_active_c1_AutopilotLaws = 0U;
  localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_NO_ACTIVE_CHILD_o;
}

void AutopilotLawsModelClass::AutopilotLaws_Chart_j(real_T rtu_right, real_T rtu_left, boolean_T rtu_use_short_path,
  real_T *rty_out, rtDW_Chart_AutopilotLaws_i_T *localDW)
{
  real_T tmp;
  real_T tmp_0;
  boolean_T tmp_1;
  if (localDW->is_active_c1_AutopilotLaws == 0U) {
    localDW->is_active_c1_AutopilotLaws = 1U;
    localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_any_a;
    if (std::abs(rtu_left) < std::abs(rtu_right)) {
      *rty_out = rtu_left;
    } else {
      *rty_out = rtu_right;
    }
  } else {
    switch (localDW->is_c1_AutopilotLaws) {
     case AutopilotLaws_IN_any_a:
      tmp = std::abs(rtu_right);
      tmp_0 = std::abs(rtu_left);
      tmp_1 = !rtu_use_short_path;
      if (tmp_1 && (tmp < tmp_0) && (tmp >= 10.0) && (tmp <= 20.0)) {
        localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_right_l;
        *rty_out = rtu_right;
      } else if (tmp_1 && (tmp_0 < tmp) && (tmp_0 >= 10.0) && (tmp_0 <= 20.0)) {
        localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_left_a;
        *rty_out = rtu_left;
      } else if (tmp_0 < tmp) {
        *rty_out = rtu_left;
      } else {
        *rty_out = rtu_right;
      }
      break;

     case AutopilotLaws_IN_left_a:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if (rtu_use_short_path || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_any_a;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_left;
      }
      break;

     default:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if (rtu_use_short_path || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c1_AutopilotLaws = AutopilotLaws_IN_any_a;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_right;
      }
      break;
    }
  }
}

void AutopilotLawsModelClass::step()
{
  real_T result[3];
  real_T x[3];
  real_T rtb_Minup;
  real_T rtb_Divide_e;
  real_T rtb_Divide_p;
  boolean_T rtb_Compare_d4;
  real_T rtb_GainTheta;
  real_T rtb_GainTheta1;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  int32_T rtb_on_ground;
  int32_T rtb_BusAssignment_output_ap_on;
  real_T rtb_ManualSwitch;
  real_T rtb_Mod1_k;
  real_T rtb_Mod2;
  real_T rtb_Mod1_g;
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_k0;
  real_T rtb_Mod1_e;
  real_T rtb_Mod2_h;
  real_T rtb_Sum_f2;
  real_T rtb_out_i;
  real_T rtb_out_d;
  int32_T i;
  real_T tmp[9];
  uint32_T rtb_Divide_o;
  real_T u0;
  boolean_T rtb_Divide_g;
  real_T u0_tmp;
  rtb_Compare_d4 = ((AutopilotLaws_U.in.input.enabled_AP1 != 0.0) || (AutopilotLaws_U.in.input.enabled_AP2 != 0.0));
  rtb_GainTheta = AutopilotLaws_P.GainTheta_Gain * AutopilotLaws_U.in.data.Theta_deg;
  rtb_GainTheta1 = AutopilotLaws_P.GainTheta1_Gain * AutopilotLaws_U.in.data.Phi_deg;
  rtb_Saturation1 = 0.017453292519943295 * rtb_GainTheta;
  rtb_Mod1_e = 0.017453292519943295 * rtb_GainTheta1;
  rtb_out_d = std::tan(rtb_Saturation1);
  rtb_Saturation = std::sin(rtb_Mod1_e);
  rtb_Mod1_e = std::cos(rtb_Mod1_e);
  tmp[0] = 1.0;
  tmp[3] = rtb_Saturation * rtb_out_d;
  tmp[6] = rtb_Mod1_e * rtb_out_d;
  tmp[1] = 0.0;
  tmp[4] = rtb_Mod1_e;
  tmp[7] = -rtb_Saturation;
  tmp[2] = 0.0;
  rtb_Mod1_k = 1.0 / std::cos(rtb_Saturation1);
  tmp[5] = rtb_Mod1_k * rtb_Saturation;
  tmp[8] = rtb_Mod1_k * rtb_Mod1_e;
  rtb_Saturation = AutopilotLaws_P.Gain_Gain_de * AutopilotLaws_U.in.data.p_rad_s * AutopilotLaws_P.Gainpk_Gain;
  rtb_Saturation1 = AutopilotLaws_P.Gain_Gain_d * AutopilotLaws_U.in.data.q_rad_s * AutopilotLaws_P.Gainqk_Gain;
  rtb_out_d = AutopilotLaws_P.Gain_Gain_m * AutopilotLaws_U.in.data.r_rad_s;
  for (rtb_on_ground = 0; rtb_on_ground < 3; rtb_on_ground++) {
    result[rtb_on_ground] = tmp[rtb_on_ground + 6] * rtb_out_d + (tmp[rtb_on_ground + 3] * rtb_Saturation1 +
      tmp[rtb_on_ground] * rtb_Saturation);
  }

  rtb_Saturation = AutopilotLaws_P.Gain_Gain_n * AutopilotLaws_U.in.data.gear_strut_compression_1 -
    AutopilotLaws_P.Constant1_Value_b;
  if (rtb_Saturation > AutopilotLaws_P.Saturation_UpperSat) {
    rtb_Saturation = AutopilotLaws_P.Saturation_UpperSat;
  } else {
    if (rtb_Saturation < AutopilotLaws_P.Saturation_LowerSat) {
      rtb_Saturation = AutopilotLaws_P.Saturation_LowerSat;
    }
  }

  rtb_Saturation1 = AutopilotLaws_P.Gain1_Gain_ll * AutopilotLaws_U.in.data.gear_strut_compression_2 -
    AutopilotLaws_P.Constant1_Value_b;
  if (rtb_Saturation1 > AutopilotLaws_P.Saturation1_UpperSat) {
    rtb_Saturation1 = AutopilotLaws_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < AutopilotLaws_P.Saturation1_LowerSat) {
      rtb_Saturation1 = AutopilotLaws_P.Saturation1_LowerSat;
    }
  }

  if (AutopilotLaws_DWork.is_active_c5_AutopilotLaws == 0U) {
    AutopilotLaws_DWork.is_active_c5_AutopilotLaws = 1U;
    AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_OnGround;
    rtb_on_ground = 1;
  } else if (AutopilotLaws_DWork.is_c5_AutopilotLaws == AutopilotLaws_IN_InAir) {
    if ((rtb_Saturation > 0.1) || (rtb_Saturation1 > 0.1)) {
      AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_OnGround;
      rtb_on_ground = 1;
    } else {
      rtb_on_ground = 0;
    }
  } else {
    if ((rtb_Saturation == 0.0) && (rtb_Saturation1 == 0.0)) {
      AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_InAir;
      rtb_on_ground = 0;
    } else {
      rtb_on_ground = 1;
    }
  }

  rtb_BusAssignment_output_ap_on = ((AutopilotLaws_U.in.input.enabled_AP1 != 0.0) ||
    (AutopilotLaws_U.in.input.enabled_AP2 != 0.0));
  rtb_Saturation = AutopilotLaws_P.Gain2_Gain * AutopilotLaws_U.in.data.zeta_pos;
  rtb_Saturation1 = rt_modd((AutopilotLaws_U.in.data.nav_loc_deg - (AutopilotLaws_U.in.data.Psi_magnetic_deg +
    AutopilotLaws_P.Constant3_Value_c)) + AutopilotLaws_P.Constant3_Value_c, AutopilotLaws_P.Constant3_Value_c);
  AutopilotLaws_Chart(rtb_Saturation1, AutopilotLaws_P.Gain_Gain_j * rt_modd(AutopilotLaws_P.Constant3_Value_c -
    rtb_Saturation1, AutopilotLaws_P.Constant3_Value_c), AutopilotLaws_P.Constant2_Value_l, &rtb_out_d,
                      &AutopilotLaws_DWork.sf_Chart_jk);
  if (AutopilotLaws_U.in.data.H_radio_ft <= AutopilotLaws_P.CompareToConstant_const) {
    rtb_Saturation1 = AutopilotLaws_P.Gain_Gain_a * rtb_out_d;
  } else {
    rtb_Saturation1 = AutopilotLaws_P.Constant1_Value;
  }

  rtb_out_d = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.LagFilter1_C1;
  rtb_Minup = rtb_out_d + AutopilotLaws_P.Constant_Value_f;
  AutopilotLaws_DWork.Delay1_DSTATE = 1.0 / rtb_Minup * (AutopilotLaws_P.Constant_Value_f - rtb_out_d) *
    AutopilotLaws_DWork.Delay1_DSTATE + (rtb_Saturation1 + AutopilotLaws_DWork.Delay_DSTATE) * (rtb_out_d / rtb_Minup);
  if (AutopilotLaws_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = AutopilotLaws_P.Constant_Value;
  } else {
    rtb_ManualSwitch = AutopilotLaws_U.in.input.lateral_law;
  }

  if (AutopilotLaws_U.in.data.nav_dme_nmi > AutopilotLaws_P.Saturation_UpperSat_o) {
    rtb_Mod1_k = AutopilotLaws_P.Saturation_UpperSat_o;
  } else if (AutopilotLaws_U.in.data.nav_dme_nmi < AutopilotLaws_P.Saturation_LowerSat_o) {
    rtb_Mod1_k = AutopilotLaws_P.Saturation_LowerSat_o;
  } else {
    rtb_Mod1_k = AutopilotLaws_U.in.data.nav_dme_nmi;
  }

  rtb_out_d = std::sin(AutopilotLaws_P.Gain1_Gain_f * AutopilotLaws_U.in.data.nav_loc_error_deg) * rtb_Mod1_k *
    AutopilotLaws_P.Gain2_Gain_g;
  if (rtb_out_d > AutopilotLaws_P.Saturation1_UpperSat_g) {
    rtb_out_d = AutopilotLaws_P.Saturation1_UpperSat_g;
  } else {
    if (rtb_out_d < AutopilotLaws_P.Saturation1_LowerSat_k) {
      rtb_out_d = AutopilotLaws_P.Saturation1_LowerSat_k;
    }
  }

  if (rtb_ManualSwitch != AutopilotLaws_P.CompareToConstant_const_k) {
    AutopilotLaws_DWork.Delay_DSTATE_h = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_InitialCondition;
  }

  AutopilotLaws_DWork.Delay_DSTATE_h += AutopilotLaws_P.Gain6_Gain * rtb_out_d *
    AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_Gain * AutopilotLaws_U.in.time.dt;
  if (AutopilotLaws_DWork.Delay_DSTATE_h > AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_UpperLimit) {
    AutopilotLaws_DWork.Delay_DSTATE_h = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_UpperLimit;
  } else {
    if (AutopilotLaws_DWork.Delay_DSTATE_h < AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_LowerLimit) {
      AutopilotLaws_DWork.Delay_DSTATE_h = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_LowerLimit;
    }
  }

  rtb_Mod1_e = AutopilotLaws_U.in.data.nav_loc_error_deg + AutopilotLaws_U.in.data.nav_loc_deg;
  rtb_Mod1_k = rt_modd((AutopilotLaws_U.in.data.Psi_magnetic_deg - (rt_modd(rt_modd(rtb_Mod1_e,
    AutopilotLaws_P.Constant3_Value_j) + AutopilotLaws_P.Constant3_Value_j, AutopilotLaws_P.Constant3_Value_j) +
    AutopilotLaws_P.Constant3_Value_o2)) + AutopilotLaws_P.Constant3_Value_o2, AutopilotLaws_P.Constant3_Value_o2);
  rtb_Mod2 = rt_modd(AutopilotLaws_P.Constant3_Value_o2 - rtb_Mod1_k, AutopilotLaws_P.Constant3_Value_o2);
  if (rtb_Mod1_k < rtb_Mod2) {
    rtb_Mod1_k *= AutopilotLaws_P.Gain1_Gain_i;
  } else {
    rtb_Mod1_k = AutopilotLaws_P.Gain_Gain_an * rtb_Mod2;
  }

  rtb_out_d = rt_modd((rt_modd(rt_modd(((rtb_out_d * look1_binlxpw(AutopilotLaws_U.in.data.V_gnd_kn,
    AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1, AutopilotLaws_P.ScheduledGain_Table, 2U) +
    AutopilotLaws_DWork.Delay_DSTATE_h) + AutopilotLaws_P.Gain1_Gain_fq * rtb_Mod1_k) +
    AutopilotLaws_U.in.data.Psi_magnetic_deg, AutopilotLaws_P.Constant3_Value_ox) + AutopilotLaws_P.Constant3_Value_ox,
    AutopilotLaws_P.Constant3_Value_ox) - (AutopilotLaws_U.in.data.Psi_magnetic_deg + AutopilotLaws_P.Constant3_Value_o))
                      + AutopilotLaws_P.Constant3_Value_o, AutopilotLaws_P.Constant3_Value_o);
  AutopilotLaws_Chart(rtb_out_d, AutopilotLaws_P.Gain_Gain_jq * rt_modd(AutopilotLaws_P.Constant3_Value_o - rtb_out_d,
    AutopilotLaws_P.Constant3_Value_o), AutopilotLaws_P.Constant1_Value_e, &rtb_Mod1_k, &AutopilotLaws_DWork.sf_Chart_o);
  switch (static_cast<int32_T>(rtb_ManualSwitch)) {
   case 0:
    rtb_out_d = AutopilotLaws_P.beta_Value_ed;
    break;

   case 1:
    rtb_out_d = AutopilotLaws_P.beta_Value_e;
    break;

   case 2:
    rtb_out_d = AutopilotLaws_P.beta_Value_b;
    break;

   case 3:
    rtb_out_d = AutopilotLaws_P.beta_Value_m;
    break;

   case 4:
    rtb_out_d = AutopilotLaws_P.beta_Value;
    break;

   case 5:
    rtb_out_d = AutopilotLaws_DWork.Delay1_DSTATE;
    break;

   default:
    rtb_out_d = (AutopilotLaws_P.Gain5_Gain * rtb_Mod1_k + AutopilotLaws_P.Gain_Gain_b * result[2]) + rtb_Saturation;
    break;
  }

  rtb_Mod2 = look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn, AutopilotLaws_P.ROLLLIM1_bp01Data,
    AutopilotLaws_P.ROLLLIM1_tableData, 4U);
  rtb_Mod1_g = rt_modd((AutopilotLaws_U.in.input.Psi_c_deg - (AutopilotLaws_U.in.data.Psi_magnetic_deg +
    AutopilotLaws_P.Constant3_Value_e)) + AutopilotLaws_P.Constant3_Value_e, AutopilotLaws_P.Constant3_Value_e);
  rtb_Compare_c = ((rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant5_const) == static_cast<int32_T>
                   (AutopilotLaws_P.CompareToConstant_const_h));
  rtb_Divide_e = AutopilotLaws_P.Subsystem_Value / AutopilotLaws_U.in.time.dt;
  if (!rtb_Compare_c) {
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_lp[i] = AutopilotLaws_P.Delay_InitialCondition_h;
    }
  }

  if (rtb_Divide_e > 100.0) {
    rtb_Divide_o = 100U;
  } else {
    if (rtb_Divide_e < 0.0) {
      rtb_Mod1_k = std::ceil(rtb_Divide_e);
    } else {
      rtb_Mod1_k = std::floor(rtb_Divide_e);
    }

    rtb_Mod1_k = std::fmod(rtb_Mod1_k, 4.294967296E+9);
    rtb_Divide_o = rtb_Mod1_k < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>(-rtb_Mod1_k))) :
      static_cast<uint32_T>(rtb_Mod1_k);
  }

  if (rtb_Divide_e < 1.0) {
    rtb_Compare_k0 = rtb_Compare_c;
  } else {
    rtb_Compare_k0 = AutopilotLaws_DWork.Delay_DSTATE_lp[100U - rtb_Divide_o];
  }

  AutopilotLaws_Chart_j(rtb_Mod1_g, AutopilotLaws_P.Gain_Gain_o * rt_modd(AutopilotLaws_P.Constant3_Value_e - rtb_Mod1_g,
    AutopilotLaws_P.Constant3_Value_e), rtb_Compare_c != rtb_Compare_k0, &rtb_Divide_e, &AutopilotLaws_DWork.sf_Chart_j);
  rtb_Mod1_g = rt_modd((AutopilotLaws_U.in.input.Psi_c_deg - (AutopilotLaws_U.in.data.Psi_magnetic_track_deg +
    AutopilotLaws_P.Constant3_Value_b)) + AutopilotLaws_P.Constant3_Value_b, AutopilotLaws_P.Constant3_Value_b);
  rtb_Compare_k0 = ((rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant4_const) == static_cast<int32_T>
                    (AutopilotLaws_P.CompareToConstant_const_e));
  rtb_Divide_p = AutopilotLaws_P.Subsystem_Value_n / AutopilotLaws_U.in.time.dt;
  if (!rtb_Compare_k0) {
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_h5[i] = AutopilotLaws_P.Delay_InitialCondition_b;
    }
  }

  if (rtb_Divide_p > 100.0) {
    rtb_Divide_o = 100U;
  } else {
    if (rtb_Divide_p < 0.0) {
      rtb_Mod1_k = std::ceil(rtb_Divide_p);
    } else {
      rtb_Mod1_k = std::floor(rtb_Divide_p);
    }

    rtb_Mod1_k = std::fmod(rtb_Mod1_k, 4.294967296E+9);
    rtb_Divide_o = rtb_Mod1_k < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<uint32_T>(-rtb_Mod1_k))) :
      static_cast<uint32_T>(rtb_Mod1_k);
  }

  if (rtb_Divide_p < 1.0) {
    rtb_Divide_g = rtb_Compare_k0;
  } else {
    rtb_Divide_g = AutopilotLaws_DWork.Delay_DSTATE_h5[100U - rtb_Divide_o];
  }

  AutopilotLaws_Chart_j(rtb_Mod1_g, AutopilotLaws_P.Gain_Gain_bn * rt_modd(AutopilotLaws_P.Constant3_Value_b -
    rtb_Mod1_g, AutopilotLaws_P.Constant3_Value_b), rtb_Compare_k0 != rtb_Divide_g, &rtb_Divide_p,
                        &AutopilotLaws_DWork.sf_Chart_ol);
  rtb_Mod1_g = AutopilotLaws_P.Gain_Gain_nu * AutopilotLaws_U.in.data.flight_guidance_xtk_nmi;
  if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_k) {
    rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_p) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_p;
    }
  }

  rtb_Mod1_k = rt_modd((rt_modd(rt_modd((AutopilotLaws_P.Gain2_Gain_f * AutopilotLaws_U.in.data.flight_guidance_tae_deg
    + rtb_Mod1_g) * AutopilotLaws_P.Gain1_Gain_n + AutopilotLaws_U.in.data.Psi_magnetic_track_deg,
    AutopilotLaws_P.Constant3_Value_h) + AutopilotLaws_P.Constant3_Value_h, AutopilotLaws_P.Constant3_Value_h) -
                        (AutopilotLaws_U.in.data.Psi_magnetic_track_deg + AutopilotLaws_P.Constant3_Value_p)) +
                       AutopilotLaws_P.Constant3_Value_p, AutopilotLaws_P.Constant3_Value_p);
  AutopilotLaws_Chart(rtb_Mod1_k, AutopilotLaws_P.Gain_Gain_b2 * rt_modd(AutopilotLaws_P.Constant3_Value_p - rtb_Mod1_k,
    AutopilotLaws_P.Constant3_Value_p), AutopilotLaws_P.Constant_Value_c, &rtb_out_i, &AutopilotLaws_DWork.sf_Chart);
  rtb_Mod1_e = rt_modd((AutopilotLaws_U.in.data.Psi_magnetic_track_deg - (rt_modd(rt_modd(rtb_Mod1_e,
    AutopilotLaws_P.Constant3_Value_f) + AutopilotLaws_P.Constant3_Value_f, AutopilotLaws_P.Constant3_Value_f) +
    AutopilotLaws_P.Constant3_Value_ju)) + AutopilotLaws_P.Constant3_Value_ju, AutopilotLaws_P.Constant3_Value_ju);
  rtb_Mod2_h = rt_modd(AutopilotLaws_P.Constant3_Value_ju - rtb_Mod1_e, AutopilotLaws_P.Constant3_Value_ju);
  if (AutopilotLaws_U.in.data.nav_dme_nmi > AutopilotLaws_P.Saturation_UpperSat_m) {
    rtb_Mod1_k = AutopilotLaws_P.Saturation_UpperSat_m;
  } else if (AutopilotLaws_U.in.data.nav_dme_nmi < AutopilotLaws_P.Saturation_LowerSat_k) {
    rtb_Mod1_k = AutopilotLaws_P.Saturation_LowerSat_k;
  } else {
    rtb_Mod1_k = AutopilotLaws_U.in.data.nav_dme_nmi;
  }

  rtb_Mod1_g = std::sin(AutopilotLaws_P.Gain1_Gain_g * AutopilotLaws_U.in.data.nav_loc_error_deg) * rtb_Mod1_k *
    look1_binlxpw(AutopilotLaws_U.in.data.nav_dme_nmi, AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_a,
                  AutopilotLaws_P.ScheduledGain_Table_p, 4U);
  if (rtb_Mod1_g > AutopilotLaws_P.Saturation1_UpperSat_i) {
    rtb_Mod1_g = AutopilotLaws_P.Saturation1_UpperSat_i;
  } else {
    if (rtb_Mod1_g < AutopilotLaws_P.Saturation1_LowerSat_g) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation1_LowerSat_g;
    }
  }

  if (rtb_Mod1_e < rtb_Mod2_h) {
    rtb_Mod1_e *= AutopilotLaws_P.Gain1_Gain;
  } else {
    rtb_Mod1_e = AutopilotLaws_P.Gain_Gain * rtb_Mod2_h;
  }

  rtb_Mod1_e = rt_modd((rt_modd(rt_modd((rtb_Mod1_g + rtb_Mod1_e) * AutopilotLaws_P.Gain3_Gain +
    AutopilotLaws_U.in.data.Psi_magnetic_track_deg, AutopilotLaws_P.Constant3_Value_pr) +
    AutopilotLaws_P.Constant3_Value_pr, AutopilotLaws_P.Constant3_Value_pr) -
                        (AutopilotLaws_U.in.data.Psi_magnetic_track_deg + AutopilotLaws_P.Constant3_Value_ou)) +
                       AutopilotLaws_P.Constant3_Value_ou, AutopilotLaws_P.Constant3_Value_ou);
  AutopilotLaws_Chart(rtb_Mod1_e, AutopilotLaws_P.Gain_Gain_p * rt_modd(AutopilotLaws_P.Constant3_Value_ou - rtb_Mod1_e,
    AutopilotLaws_P.Constant3_Value_ou), AutopilotLaws_P.Constant_Value_e, &rtb_Mod1_g, &AutopilotLaws_DWork.sf_Chart_g);
  rtb_Mod1_e = AutopilotLaws_P.DiscreteDerivativeVariableTs_Gain * AutopilotLaws_U.in.data.nav_loc_error_deg;
  rtb_Mod1_k = (rtb_Mod1_e - AutopilotLaws_DWork.Delay_DSTATE_f) / AutopilotLaws_U.in.time.dt *
    AutopilotLaws_P.Gain3_Gain_i + AutopilotLaws_U.in.data.nav_loc_error_deg;
  rtb_Mod2_h = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.LagFilter_C1;
  rtb_Minup = rtb_Mod2_h + AutopilotLaws_P.Constant_Value_h;
  AutopilotLaws_DWork.Delay1_DSTATE_e = 1.0 / rtb_Minup * (AutopilotLaws_P.Constant_Value_h - rtb_Mod2_h) *
    AutopilotLaws_DWork.Delay1_DSTATE_e + (rtb_Mod1_k + AutopilotLaws_DWork.Delay_DSTATE_n) * (rtb_Mod2_h / rtb_Minup);
  rtb_Mod2_h = rt_modd((rt_modd(rt_modd(AutopilotLaws_DWork.Delay1_DSTATE_e * look1_binlxpw
    (AutopilotLaws_U.in.data.H_radio_ft, AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_ea,
     AutopilotLaws_P.ScheduledGain_Table_pf, 4U) + AutopilotLaws_U.in.data.Psi_magnetic_track_deg,
    AutopilotLaws_P.Constant3_Value_cr) + AutopilotLaws_P.Constant3_Value_cr, AutopilotLaws_P.Constant3_Value_cr) -
                        (AutopilotLaws_U.in.data.Psi_magnetic_track_deg + AutopilotLaws_P.Constant3_Value_ot)) +
                       AutopilotLaws_P.Constant3_Value_ot, AutopilotLaws_P.Constant3_Value_ot);
  AutopilotLaws_Chart(rtb_Mod2_h, AutopilotLaws_P.Gain_Gain_l * rt_modd(AutopilotLaws_P.Constant3_Value_ot - rtb_Mod2_h,
    AutopilotLaws_P.Constant3_Value_ot), AutopilotLaws_P.Constant_Value_p, &rtb_Minup, &AutopilotLaws_DWork.sf_Chart_h);
  switch (static_cast<int32_T>(rtb_ManualSwitch)) {
   case 0:
    rtb_Mod2_h = rtb_GainTheta1;
    break;

   case 1:
    rtb_Mod2_h = rtb_Divide_e * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_e, AutopilotLaws_P.ScheduledGain_Table_b, 5U);
    break;

   case 2:
    rtb_Mod2_h = rtb_Divide_p * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_k, AutopilotLaws_P.ScheduledGain_Table_m, 5U);
    break;

   case 3:
    rtb_Mod2_h = rtb_out_i * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_ep, AutopilotLaws_P.ScheduledGain_Table_j, 5U);
    break;

   case 4:
    rtb_Mod2_h = rtb_Mod1_g * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_o, AutopilotLaws_P.ScheduledGain_Table_d, 5U);
    break;

   case 5:
    rtb_Mod2_h = rtb_Minup * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_p, AutopilotLaws_P.ScheduledGain_Table_i, 5U);
    break;

   default:
    rtb_Mod2_h = AutopilotLaws_P.Constant3_Value;
    break;
  }

  if (rtb_Mod2_h > rtb_Mod2) {
    rtb_Mod2_h = rtb_Mod2;
  } else {
    rtb_ManualSwitch = AutopilotLaws_P.Gain1_Gain_l * rtb_Mod2;
    if (rtb_Mod2_h < rtb_ManualSwitch) {
      rtb_Mod2_h = rtb_ManualSwitch;
    }
  }

  if (!rtb_Compare_d4) {
    AutopilotLaws_DWork.icLoad = 1U;
  }

  if (AutopilotLaws_DWork.icLoad != 0) {
    AutopilotLaws_DWork.Delay_DSTATE_hc = rtb_GainTheta1;
  }

  rtb_Mod1_g = rtb_Mod2_h - AutopilotLaws_DWork.Delay_DSTATE_hc;
  rtb_Divide_p = AutopilotLaws_P.Constant2_Value_h * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod1_g < rtb_Divide_p) {
    rtb_Divide_p = rtb_Mod1_g;
  }

  rtb_Mod1_g = AutopilotLaws_P.Gain1_Gain_k * AutopilotLaws_P.Constant2_Value_h * AutopilotLaws_U.in.time.dt;
  if (rtb_Divide_p > rtb_Mod1_g) {
    rtb_Mod1_g = rtb_Divide_p;
  }

  AutopilotLaws_DWork.Delay_DSTATE_hc += rtb_Mod1_g;
  rtb_Divide_p = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.LagFilter_C1_l;
  rtb_Minup = rtb_Divide_p + AutopilotLaws_P.Constant_Value_ey;
  AutopilotLaws_DWork.Delay1_DSTATE_a = 1.0 / rtb_Minup * (AutopilotLaws_P.Constant_Value_ey - rtb_Divide_p) *
    AutopilotLaws_DWork.Delay1_DSTATE_a + (AutopilotLaws_DWork.Delay_DSTATE_hc + AutopilotLaws_DWork.Delay_DSTATE_e) *
    (rtb_Divide_p / rtb_Minup);
  rtb_Mod1_g = static_cast<real_T>(rtb_BusAssignment_output_ap_on) - AutopilotLaws_DWork.Delay_DSTATE_fr;
  rtb_Divide_p = AutopilotLaws_P.RateLimiterVariableTs_up * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod1_g < rtb_Divide_p) {
    rtb_Divide_p = rtb_Mod1_g;
  }

  rtb_Mod1_g = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.RateLimiterVariableTs_lo;
  if (rtb_Divide_p > rtb_Mod1_g) {
    rtb_Mod1_g = rtb_Divide_p;
  }

  AutopilotLaws_DWork.Delay_DSTATE_fr += rtb_Mod1_g;
  if (AutopilotLaws_DWork.Delay_DSTATE_fr > AutopilotLaws_P.Saturation_UpperSat_b) {
    rtb_Divide_e = AutopilotLaws_P.Saturation_UpperSat_b;
  } else if (AutopilotLaws_DWork.Delay_DSTATE_fr < AutopilotLaws_P.Saturation_LowerSat_j) {
    rtb_Divide_e = AutopilotLaws_P.Saturation_LowerSat_j;
  } else {
    rtb_Divide_e = AutopilotLaws_DWork.Delay_DSTATE_fr;
  }

  rtb_ManualSwitch = AutopilotLaws_DWork.Delay1_DSTATE_a * rtb_Divide_e;
  rtb_Divide_e = AutopilotLaws_P.Constant_Value_cc - rtb_Divide_e;
  rtb_Divide_e *= rtb_GainTheta1;
  AutopilotLaws_Y.out.output.autopilot.Phi_c_deg = rtb_ManualSwitch + rtb_Divide_e;
  AutopilotLaws_Y.out.output.flight_director.Phi_c_deg = rtb_Mod2_h;
  if (AutopilotLaws_P.ManualSwitch_CurrentSetting_b == 1) {
    rtb_out_i = AutopilotLaws_P.Constant_Value_m;
  } else {
    rtb_out_i = AutopilotLaws_U.in.input.vertical_law;
  }

  if (rtb_out_i != AutopilotLaws_P.CompareToConstant5_const_e) {
    AutopilotLaws_B.u_n = (AutopilotLaws_U.in.input.H_c_ft + AutopilotLaws_U.in.data.H_ft) -
      AutopilotLaws_U.in.data.H_ind_ft;
  }

  rtb_Mod2_h = AutopilotLaws_U.in.input.H_c_ft - AutopilotLaws_U.in.data.H_ind_ft;
  if (rtb_Mod2_h < 0.0) {
    rtb_Minup = -1.0;
  } else if (rtb_Mod2_h > 0.0) {
    rtb_Minup = 1.0;
  } else {
    rtb_Minup = rtb_Mod2_h;
  }

  rtb_Divide_e = AutopilotLaws_P.Gain1_Gain_b * AutopilotLaws_U.in.data.alpha_deg;
  rtb_Divide_p = AutopilotLaws_U.in.data.bz_m_s2 * std::sin(rtb_Divide_e);
  rtb_Divide_e = std::cos(rtb_Divide_e);
  rtb_Divide_e *= AutopilotLaws_U.in.data.bx_m_s2;
  rtb_Sum_f2 = rtb_Divide_p + rtb_Divide_e;
  rtb_ManualSwitch = AutopilotLaws_P.DiscreteDerivativeVariableTs_Gain_l * AutopilotLaws_U.in.data.nav_gs_error_deg;
  rtb_Mod2 = (rtb_ManualSwitch - AutopilotLaws_DWork.Delay_DSTATE_m) / AutopilotLaws_U.in.time.dt *
    AutopilotLaws_P.Gain3_Gain_o + AutopilotLaws_P.Gain1_Gain_jl * AutopilotLaws_U.in.data.nav_gs_error_deg;
  rtb_Divide_e = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.LagFilter_C1_n;
  rtb_Divide_p = rtb_Divide_e + AutopilotLaws_P.Constant_Value_eu;
  AutopilotLaws_DWork.Delay1_DSTATE_d = 1.0 / rtb_Divide_p * (AutopilotLaws_P.Constant_Value_eu - rtb_Divide_e) *
    AutopilotLaws_DWork.Delay1_DSTATE_d + (rtb_Mod2 + AutopilotLaws_DWork.Delay_DSTATE_k) * (rtb_Divide_e / rtb_Divide_p);
  if (AutopilotLaws_U.in.data.H_radio_ft <= AutopilotLaws_P.CompareToConstant_const_j) {
    AutopilotLaws_B.u = AutopilotLaws_U.in.data.H_dot_ft_min;
  }

  rtb_Divide_e = AutopilotLaws_P.Gain1_Gain_lf * AutopilotLaws_U.in.data.alpha_deg;
  rtb_Divide_p = AutopilotLaws_U.in.data.bz_m_s2 * std::sin(rtb_Divide_e);
  rtb_Divide_e = std::cos(rtb_Divide_e);
  rtb_Divide_e *= AutopilotLaws_U.in.data.bx_m_s2;
  u0_tmp = AutopilotLaws_U.in.data.V_ias_kn - AutopilotLaws_U.in.input.V_c_kn;
  rtb_Mod1_g = u0_tmp * AutopilotLaws_P.Gain1_Gain_h;
  u0 = AutopilotLaws_P.kntoms_Gain_f * AutopilotLaws_U.in.data.V_tas_kn;
  if (u0 > AutopilotLaws_P.Saturation_UpperSat_pe) {
    u0 = AutopilotLaws_P.Saturation_UpperSat_pe;
  } else {
    if (u0 < AutopilotLaws_P.Saturation_LowerSat_b) {
      u0 = AutopilotLaws_P.Saturation_LowerSat_b;
    }
  }

  u0 = (AutopilotLaws_P.Constant_Value_i - AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_k / u0;
  x[0] = AutopilotLaws_P.Constant1_Value_d - rtb_GainTheta;
  if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_bc) {
    rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_bc;
  } else {
    if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_au) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_au;
    }
  }

  x[1] = (rtb_Divide_p + rtb_Divide_e) * AutopilotLaws_P.Gain_Gain_cu * AutopilotLaws_P.Gain_Gain_ej *
    AutopilotLaws_P.Gain_Gain_h2 + rtb_Mod1_g;
  if (u0 > 1.0) {
    u0 = 1.0;
  } else {
    if (u0 < -1.0) {
      u0 = -1.0;
    }
  }

  x[2] = AutopilotLaws_P.Gain_Gain_f5 * std::asin(u0) * AutopilotLaws_P.VS_Gain_c;
  switch (static_cast<int32_T>(rtb_out_i)) {
   case 0:
    rtb_Divide_e = rtb_GainTheta;
    break;

   case 1:
    rtb_Mod1_g = (AutopilotLaws_B.u_n - AutopilotLaws_U.in.data.H_ft) * AutopilotLaws_P.Gain_Gain_f;
    u0 = AutopilotLaws_P.kntoms_Gain * AutopilotLaws_U.in.data.V_tas_kn;
    if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_n) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_n;
    } else {
      if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_d) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_d;
      }
    }

    if (u0 > AutopilotLaws_P.Saturation_UpperSat_kv) {
      u0 = AutopilotLaws_P.Saturation_UpperSat_kv;
    } else {
      if (u0 < AutopilotLaws_P.Saturation_LowerSat_a) {
        u0 = AutopilotLaws_P.Saturation_LowerSat_a;
      }
    }

    rtb_Mod1_g = (rtb_Mod1_g - AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain / u0;
    if (rtb_Mod1_g > 1.0) {
      rtb_Mod1_g = 1.0;
    } else {
      if (rtb_Mod1_g < -1.0) {
        rtb_Mod1_g = -1.0;
      }
    }

    rtb_Divide_e = AutopilotLaws_P.Gain_Gain_og * std::asin(rtb_Mod1_g) * AutopilotLaws_P.VS_Gain;
    break;

   case 2:
    rtb_Mod1_g = AutopilotLaws_P.kntoms_Gain_e * AutopilotLaws_U.in.data.V_tas_kn;
    if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_p) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_p;
    } else {
      if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_c) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_c;
      }
    }

    rtb_Mod1_g = ((AutopilotLaws_P.Constant_Value_b * rtb_Minup + rtb_Mod2_h) * AutopilotLaws_P.Gain_Gain_e -
                  AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_o / rtb_Mod1_g;
    if (rtb_Mod1_g > 1.0) {
      rtb_Mod1_g = 1.0;
    } else {
      if (rtb_Mod1_g < -1.0) {
        rtb_Mod1_g = -1.0;
      }
    }

    rtb_Divide_e = AutopilotLaws_P.Gain_Gain_nz * std::asin(rtb_Mod1_g) * AutopilotLaws_P.VS_Gain_a;
    break;

   case 3:
    if (rtb_Mod2_h > AutopilotLaws_P.Switch_Threshold_k) {
      rtb_Mod1_g = (AutopilotLaws_U.in.data.V_ias_kn - AutopilotLaws_U.in.input.V_c_kn) * AutopilotLaws_P.Gain1_Gain_j;
      u0 = AutopilotLaws_P.kntoms_Gain_i * AutopilotLaws_U.in.data.V_tas_kn;
      if (u0 > AutopilotLaws_P.Saturation_UpperSat_l) {
        u0 = AutopilotLaws_P.Saturation_UpperSat_l;
      } else {
        if (u0 < AutopilotLaws_P.Saturation_LowerSat_me) {
          u0 = AutopilotLaws_P.Saturation_LowerSat_me;
        }
      }

      u0 = (AutopilotLaws_P.Constant_Value_k - AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_c /
        u0;
      if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_e) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_e;
      } else {
        if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_m) {
          rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_m;
        }
      }

      rtb_Mod1_g += AutopilotLaws_P.Gain_Gain_jc * rtb_Sum_f2 * AutopilotLaws_P.Gain_Gain_k *
        AutopilotLaws_P.Gain_Gain_h;
      if (u0 > 1.0) {
        u0 = 1.0;
      } else {
        if (u0 < -1.0) {
          u0 = -1.0;
        }
      }

      rtb_Divide_e = AutopilotLaws_P.Gain_Gain_dy * std::asin(u0) * AutopilotLaws_P.VS_Gain_j;
      if (rtb_Mod1_g > rtb_Divide_e) {
        rtb_Divide_e = rtb_Mod1_g;
      }
    } else {
      rtb_Mod1_g = u0_tmp * AutopilotLaws_P.Gain1_Gain_j;
      u0 = AutopilotLaws_P.kntoms_Gain_i * AutopilotLaws_U.in.data.V_tas_kn;
      if (u0 > AutopilotLaws_P.Saturation_UpperSat_l) {
        u0 = AutopilotLaws_P.Saturation_UpperSat_l;
      } else {
        if (u0 < AutopilotLaws_P.Saturation_LowerSat_me) {
          u0 = AutopilotLaws_P.Saturation_LowerSat_me;
        }
      }

      u0 = (AutopilotLaws_P.Constant_Value_k - AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_c /
        u0;
      if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_e) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_e;
      } else {
        if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_m) {
          rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_m;
        }
      }

      rtb_Mod1_g += AutopilotLaws_P.Gain_Gain_jc * rtb_Sum_f2 * AutopilotLaws_P.Gain_Gain_k *
        AutopilotLaws_P.Gain_Gain_h;
      if (u0 > 1.0) {
        u0 = 1.0;
      } else {
        if (u0 < -1.0) {
          u0 = -1.0;
        }
      }

      rtb_Divide_e = AutopilotLaws_P.Gain_Gain_dy * std::asin(u0) * AutopilotLaws_P.VS_Gain_j;
      if (rtb_Mod1_g < rtb_Divide_e) {
        rtb_Divide_e = rtb_Mod1_g;
      }
    }
    break;

   case 4:
    rtb_Mod1_g = AutopilotLaws_P.kntoms_Gain_a * AutopilotLaws_U.in.data.V_tas_kn;
    if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_md) {
      rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_md;
    } else {
      if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_mz) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_mz;
      }
    }

    rtb_Mod1_g = (AutopilotLaws_U.in.input.H_dot_c_fpm - AutopilotLaws_U.in.data.H_dot_ft_min) *
      AutopilotLaws_P.ftmintoms_Gain_ok / rtb_Mod1_g;
    if (rtb_Mod1_g > 1.0) {
      rtb_Mod1_g = 1.0;
    } else {
      if (rtb_Mod1_g < -1.0) {
        rtb_Mod1_g = -1.0;
      }
    }

    rtb_Divide_e = AutopilotLaws_P.Gain_Gain_lg * std::asin(rtb_Mod1_g) * AutopilotLaws_P.VS_Gain_h;
    break;

   case 5:
    rtb_Divide_e = (AutopilotLaws_U.in.input.FPA_c_deg - (rtb_GainTheta - std::cos(AutopilotLaws_P.Gain1_Gain_c *
      rtb_GainTheta1) * AutopilotLaws_U.in.data.alpha_deg)) * AutopilotLaws_P.Gain_Gain_c;
    break;

   case 6:
    rtb_Divide_e = AutopilotLaws_DWork.Delay1_DSTATE_d * look1_binlxpw(AutopilotLaws_U.in.data.H_radio_ft,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_h, AutopilotLaws_P.ScheduledGain_Table_ir, 4U);
    break;

   case 7:
    if (rtb_on_ground > AutopilotLaws_P.Switch_Threshold) {
      rtb_Divide_e = (rtb_GainTheta - AutopilotLaws_P.Constant2_Value) * AutopilotLaws_P.Gain4_Gain;
    } else {
      rtb_Divide_p = AutopilotLaws_B.u / AutopilotLaws_P.Constant_Value_pg * AutopilotLaws_U.in.data.H_radio_ft;
      rtb_Mod1_g = AutopilotLaws_P.kntoms_Gain_av * AutopilotLaws_U.in.data.V_tas_kn;
      if (AutopilotLaws_P.Constant3_Value_n < rtb_Divide_p) {
        rtb_Divide_p = AutopilotLaws_P.Constant3_Value_n;
      }

      if (rtb_Mod1_g > AutopilotLaws_P.Saturation_UpperSat_g) {
        rtb_Mod1_g = AutopilotLaws_P.Saturation_UpperSat_g;
      } else {
        if (rtb_Mod1_g < AutopilotLaws_P.Saturation_LowerSat_p3) {
          rtb_Mod1_g = AutopilotLaws_P.Saturation_LowerSat_p3;
        }
      }

      rtb_Mod1_g = (rtb_Divide_p - AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_a / rtb_Mod1_g;
      if (rtb_Mod1_g > 1.0) {
        rtb_Mod1_g = 1.0;
      } else {
        if (rtb_Mod1_g < -1.0) {
          rtb_Mod1_g = -1.0;
        }
      }

      rtb_Divide_e = AutopilotLaws_P.Gain_Gain_c1 * std::asin(rtb_Mod1_g) * AutopilotLaws_P.VS_Gain_e;
    }
    break;

   default:
    if (x[0] < x[1]) {
      if (x[1] < x[2]) {
        i = 1;
      } else if (x[0] < x[2]) {
        i = 2;
      } else {
        i = 0;
      }
    } else if (x[0] < x[2]) {
      i = 0;
    } else if (x[1] < x[2]) {
      i = 2;
    } else {
      i = 1;
    }

    rtb_Divide_e = x[i];
    break;
  }

  rtb_Divide_e += rtb_GainTheta;
  if (rtb_Divide_e > AutopilotLaws_P.Constant1_Value_i) {
    rtb_Divide_e = AutopilotLaws_P.Constant1_Value_i;
  } else {
    rtb_Mod1_g = AutopilotLaws_P.Gain1_Gain_p * AutopilotLaws_P.Constant1_Value_i;
    if (rtb_Divide_e < rtb_Mod1_g) {
      rtb_Divide_e = rtb_Mod1_g;
    }
  }

  if (!rtb_Compare_d4) {
    AutopilotLaws_DWork.icLoad_b = 1U;
  }

  if (AutopilotLaws_DWork.icLoad_b != 0) {
    AutopilotLaws_DWork.Delay_DSTATE_o = rtb_GainTheta;
  }

  rtb_Mod1_g = rtb_Divide_e - AutopilotLaws_DWork.Delay_DSTATE_o;
  rtb_Divide_p = AutopilotLaws_P.Constant2_Value_h1 * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod1_g < rtb_Divide_p) {
    rtb_Divide_p = rtb_Mod1_g;
  }

  rtb_Mod1_g = AutopilotLaws_P.Gain1_Gain_a * AutopilotLaws_P.Constant2_Value_h1 * AutopilotLaws_U.in.time.dt;
  if (rtb_Divide_p > rtb_Mod1_g) {
    rtb_Mod1_g = rtb_Divide_p;
  }

  AutopilotLaws_DWork.Delay_DSTATE_o += rtb_Mod1_g;
  rtb_Divide_p = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.LagFilter_C1_f;
  rtb_Mod2_h = rtb_Divide_p + AutopilotLaws_P.Constant_Value_el;
  AutopilotLaws_DWork.Delay1_DSTATE_h = 1.0 / rtb_Mod2_h * (AutopilotLaws_P.Constant_Value_el - rtb_Divide_p) *
    AutopilotLaws_DWork.Delay1_DSTATE_h + (AutopilotLaws_DWork.Delay_DSTATE_o + AutopilotLaws_DWork.Delay_DSTATE_l) *
    (rtb_Divide_p / rtb_Mod2_h);
  rtb_Mod1_g = static_cast<real_T>(rtb_BusAssignment_output_ap_on) - AutopilotLaws_DWork.Delay_DSTATE_b;
  rtb_Divide_p = AutopilotLaws_P.RateLimiterVariableTs_up_i * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod1_g < rtb_Divide_p) {
    rtb_Divide_p = rtb_Mod1_g;
  }

  rtb_Mod1_g = AutopilotLaws_U.in.time.dt * AutopilotLaws_P.RateLimiterVariableTs_lo_o;
  if (rtb_Divide_p > rtb_Mod1_g) {
    rtb_Mod1_g = rtb_Divide_p;
  }

  AutopilotLaws_DWork.Delay_DSTATE_b += rtb_Mod1_g;
  if (AutopilotLaws_DWork.Delay_DSTATE_b > AutopilotLaws_P.Saturation_UpperSat_j) {
    rtb_Divide_p = AutopilotLaws_P.Saturation_UpperSat_j;
  } else if (AutopilotLaws_DWork.Delay_DSTATE_b < AutopilotLaws_P.Saturation_LowerSat_pj) {
    rtb_Divide_p = AutopilotLaws_P.Saturation_LowerSat_pj;
  } else {
    rtb_Divide_p = AutopilotLaws_DWork.Delay_DSTATE_b;
  }

  rtb_Mod1_g = AutopilotLaws_DWork.Delay1_DSTATE_h * rtb_Divide_p;
  rtb_Divide_p = AutopilotLaws_P.Constant_Value_d - rtb_Divide_p;
  rtb_Divide_p *= rtb_GainTheta;
  AutopilotLaws_Y.out.output.autopilot.Theta_c_deg = rtb_Mod1_g + rtb_Divide_p;
  AutopilotLaws_Y.out.time = AutopilotLaws_U.in.time;
  AutopilotLaws_Y.out.data.Theta_deg = rtb_GainTheta;
  AutopilotLaws_Y.out.data.Phi_deg = rtb_GainTheta1;
  AutopilotLaws_Y.out.data.qk_deg_s = result[1];
  AutopilotLaws_Y.out.data.rk_deg_s = result[2];
  AutopilotLaws_Y.out.data.pk_deg_s = result[0];
  AutopilotLaws_Y.out.data.V_ias_kn = AutopilotLaws_U.in.data.V_ias_kn;
  AutopilotLaws_Y.out.data.V_tas_kn = AutopilotLaws_U.in.data.V_tas_kn;
  AutopilotLaws_Y.out.data.V_mach = AutopilotLaws_U.in.data.V_mach;
  AutopilotLaws_Y.out.data.V_gnd_kn = AutopilotLaws_U.in.data.V_gnd_kn;
  AutopilotLaws_Y.out.data.alpha_deg = AutopilotLaws_U.in.data.alpha_deg;
  AutopilotLaws_Y.out.data.H_ft = AutopilotLaws_U.in.data.H_ft;
  AutopilotLaws_Y.out.data.H_ind_ft = AutopilotLaws_U.in.data.H_ind_ft;
  AutopilotLaws_Y.out.data.H_radio_ft = AutopilotLaws_U.in.data.H_radio_ft;
  AutopilotLaws_Y.out.data.H_dot_ft_min = AutopilotLaws_U.in.data.H_dot_ft_min;
  AutopilotLaws_Y.out.data.Psi_magnetic_deg = AutopilotLaws_U.in.data.Psi_magnetic_deg;
  AutopilotLaws_Y.out.data.Psi_magnetic_track_deg = AutopilotLaws_U.in.data.Psi_magnetic_track_deg;
  AutopilotLaws_Y.out.data.Psi_true_deg = AutopilotLaws_U.in.data.Psi_true_deg;
  AutopilotLaws_Y.out.data.bx_m_s2 = AutopilotLaws_U.in.data.bx_m_s2;
  AutopilotLaws_Y.out.data.by_m_s2 = AutopilotLaws_U.in.data.by_m_s2;
  AutopilotLaws_Y.out.data.bz_m_s2 = AutopilotLaws_U.in.data.bz_m_s2;
  AutopilotLaws_Y.out.data.nav_valid = AutopilotLaws_U.in.data.nav_valid;
  AutopilotLaws_Y.out.data.nav_loc_deg = AutopilotLaws_U.in.data.nav_loc_deg;
  AutopilotLaws_Y.out.data.nav_dme_valid = AutopilotLaws_U.in.data.nav_dme_valid;
  AutopilotLaws_Y.out.data.nav_dme_nmi = AutopilotLaws_U.in.data.nav_dme_nmi;
  AutopilotLaws_Y.out.data.nav_loc_valid = AutopilotLaws_U.in.data.nav_loc_valid;
  AutopilotLaws_Y.out.data.nav_loc_error_deg = AutopilotLaws_U.in.data.nav_loc_error_deg;
  AutopilotLaws_Y.out.data.nav_gs_valid = AutopilotLaws_U.in.data.nav_gs_valid;
  AutopilotLaws_Y.out.data.nav_gs_error_deg = AutopilotLaws_U.in.data.nav_gs_error_deg;
  AutopilotLaws_Y.out.data.flight_guidance_xtk_nmi = AutopilotLaws_U.in.data.flight_guidance_xtk_nmi;
  AutopilotLaws_Y.out.data.flight_guidance_tae_deg = AutopilotLaws_U.in.data.flight_guidance_tae_deg;
  AutopilotLaws_Y.out.data.flight_phase = AutopilotLaws_U.in.data.flight_phase;
  AutopilotLaws_Y.out.data.V2_kn = AutopilotLaws_U.in.data.V2_kn;
  AutopilotLaws_Y.out.data.VAPP_kn = AutopilotLaws_U.in.data.VAPP_kn;
  AutopilotLaws_Y.out.data.VLS_kn = AutopilotLaws_U.in.data.VLS_kn;
  AutopilotLaws_Y.out.data.is_flight_plan_available = AutopilotLaws_U.in.data.is_flight_plan_available;
  AutopilotLaws_Y.out.data.altitude_constraint_ft = AutopilotLaws_U.in.data.altitude_constraint_ft;
  AutopilotLaws_Y.out.data.thrust_reduction_altitude = AutopilotLaws_U.in.data.thrust_reduction_altitude;
  AutopilotLaws_Y.out.data.thrust_reduction_altitude_go_around =
    AutopilotLaws_U.in.data.thrust_reduction_altitude_go_around;
  AutopilotLaws_Y.out.data.acceleration_altitude = AutopilotLaws_U.in.data.acceleration_altitude;
  AutopilotLaws_Y.out.data.acceleration_altitude_engine_out = AutopilotLaws_U.in.data.acceleration_altitude_engine_out;
  AutopilotLaws_Y.out.data.acceleration_altitude_go_around = AutopilotLaws_U.in.data.acceleration_altitude_go_around;
  AutopilotLaws_Y.out.data.cruise_altitude = AutopilotLaws_U.in.data.cruise_altitude;
  AutopilotLaws_Y.out.data.on_ground = rtb_on_ground;
  AutopilotLaws_Y.out.data.zeta_deg = rtb_Saturation;
  AutopilotLaws_Y.out.data.throttle_lever_1_pos = AutopilotLaws_U.in.data.throttle_lever_1_pos;
  AutopilotLaws_Y.out.data.throttle_lever_2_pos = AutopilotLaws_U.in.data.throttle_lever_2_pos;
  AutopilotLaws_Y.out.data.flaps_handle_index = AutopilotLaws_U.in.data.flaps_handle_index;
  AutopilotLaws_Y.out.input = AutopilotLaws_U.in.input;
  AutopilotLaws_Y.out.output.ap_on = rtb_Compare_d4;
  AutopilotLaws_Y.out.output.flight_director.Theta_c_deg = rtb_Divide_e;
  AutopilotLaws_Y.out.output.flight_director.Beta_c_deg = rtb_out_d;
  AutopilotLaws_Y.out.output.autopilot.Beta_c_deg = rtb_out_d;
  AutopilotLaws_DWork.Delay_DSTATE = rtb_Saturation1;
  for (rtb_on_ground = 0; rtb_on_ground < 99; rtb_on_ground++) {
    AutopilotLaws_DWork.Delay_DSTATE_lp[rtb_on_ground] = AutopilotLaws_DWork.Delay_DSTATE_lp[rtb_on_ground + 1];
    AutopilotLaws_DWork.Delay_DSTATE_h5[rtb_on_ground] = AutopilotLaws_DWork.Delay_DSTATE_h5[rtb_on_ground + 1];
  }

  AutopilotLaws_DWork.Delay_DSTATE_lp[99] = rtb_Compare_c;
  AutopilotLaws_DWork.Delay_DSTATE_h5[99] = rtb_Compare_k0;
  AutopilotLaws_DWork.Delay_DSTATE_f = rtb_Mod1_e;
  AutopilotLaws_DWork.Delay_DSTATE_n = rtb_Mod1_k;
  AutopilotLaws_DWork.icLoad = 0U;
  AutopilotLaws_DWork.Delay_DSTATE_e = AutopilotLaws_DWork.Delay_DSTATE_hc;
  AutopilotLaws_DWork.Delay_DSTATE_m = rtb_ManualSwitch;
  AutopilotLaws_DWork.Delay_DSTATE_k = rtb_Mod2;
  AutopilotLaws_DWork.icLoad_b = 0U;
  AutopilotLaws_DWork.Delay_DSTATE_l = AutopilotLaws_DWork.Delay_DSTATE_o;
}

void AutopilotLawsModelClass::initialize()
{
  (void) std::memset((static_cast<void *>(&AutopilotLaws_B)), 0,
                     sizeof(BlockIO_AutopilotLaws_T));
  (void) std::memset(static_cast<void *>(&AutopilotLaws_DWork), 0,
                     sizeof(D_Work_AutopilotLaws_T));
  AutopilotLaws_U.in = AutopilotLaws_rtZap_laws_input;
  AutopilotLaws_Y.out = AutopilotLaws_rtZap_laws_output;

  {
    int32_T i;
    AutopilotLaws_DWork.Delay_DSTATE = AutopilotLaws_P.Delay_InitialCondition;
    AutopilotLaws_DWork.Delay1_DSTATE = AutopilotLaws_P.Delay1_InitialCondition;
    AutopilotLaws_DWork.Delay_DSTATE_h = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_InitialCondition;
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_lp[i] = AutopilotLaws_P.Delay_InitialCondition_h;
      AutopilotLaws_DWork.Delay_DSTATE_h5[i] = AutopilotLaws_P.Delay_InitialCondition_b;
    }

    AutopilotLaws_DWork.Delay_DSTATE_f = AutopilotLaws_P.DiscreteDerivativeVariableTs_InitialCondition;
    AutopilotLaws_DWork.Delay_DSTATE_n = AutopilotLaws_P.Delay_InitialCondition_e;
    AutopilotLaws_DWork.Delay1_DSTATE_e = AutopilotLaws_P.Delay1_InitialCondition_a;
    AutopilotLaws_DWork.icLoad = 1U;
    AutopilotLaws_DWork.Delay_DSTATE_e = AutopilotLaws_P.Delay_InitialCondition_p;
    AutopilotLaws_DWork.Delay1_DSTATE_a = AutopilotLaws_P.Delay1_InitialCondition_d;
    AutopilotLaws_DWork.Delay_DSTATE_fr = AutopilotLaws_P.RateLimiterVariableTs_InitialCondition;
    AutopilotLaws_DWork.Delay_DSTATE_m = AutopilotLaws_P.DiscreteDerivativeVariableTs_InitialCondition_h;
    AutopilotLaws_DWork.Delay_DSTATE_k = AutopilotLaws_P.Delay_InitialCondition_n;
    AutopilotLaws_DWork.Delay1_DSTATE_d = AutopilotLaws_P.Delay1_InitialCondition_n;
    AutopilotLaws_DWork.icLoad_b = 1U;
    AutopilotLaws_DWork.Delay_DSTATE_l = AutopilotLaws_P.Delay_InitialCondition_p2;
    AutopilotLaws_DWork.Delay1_DSTATE_h = AutopilotLaws_P.Delay1_InitialCondition_b;
    AutopilotLaws_DWork.Delay_DSTATE_b = AutopilotLaws_P.RateLimiterVariableTs_InitialCondition_p;
    AutopilotLaws_DWork.is_active_c5_AutopilotLaws = 0U;
    AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_NO_ACTIVE_CHILD_n;
    AutopilotLaws_Chart_Init(&AutopilotLaws_DWork.sf_Chart_jk);
    AutopilotLaws_Chart_Init(&AutopilotLaws_DWork.sf_Chart_o);
    AutopilotLaws_Chart_p_Init(&AutopilotLaws_DWork.sf_Chart_j);
    AutopilotLaws_Chart_p_Init(&AutopilotLaws_DWork.sf_Chart_ol);
    AutopilotLaws_Chart_Init(&AutopilotLaws_DWork.sf_Chart);
    AutopilotLaws_Chart_Init(&AutopilotLaws_DWork.sf_Chart_g);
    AutopilotLaws_Chart_Init(&AutopilotLaws_DWork.sf_Chart_h);
    AutopilotLaws_B.u_n = AutopilotLaws_P.Y_Y0;
    AutopilotLaws_B.u = AutopilotLaws_P.Y_Y0_n;
  }
}

void AutopilotLawsModelClass::terminate()
{
}

AutopilotLawsModelClass::AutopilotLawsModelClass()
{
}

AutopilotLawsModelClass::~AutopilotLawsModelClass()
{
}
