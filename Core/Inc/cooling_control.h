#ifndef COOLING_CONTROL_H
#define COOLING_CONTROL_H

#include "bms_lv_config.h"

#if COOLING_TYPE == COOLING_TYPE_POLYNOMIAL

#define COOLING_OFF_THRESHOLD (40.0f)

#if COOLING_AGGRESSIVENESS == COOLING_AGGRESSIVENESS_LOW
#define PUMPS_COEFFICIENTS    {0.06267081819754365, -4.42371562013492, 77.31101885486927}
#define RADIATOR_COEFFICIENTS {0.06860264519838995, -5.620327774583103, 108.79025301897668}
#elif COOLING_AGGRESSIVENESS == COOLING_AGGRESSIVENESS_NORMAL
#define PUMPS_COEFFICIENTS    {0.12628672845592465, -9.320252415697114, 168.96963123644622}
#define RADIATOR_COEFFICIENTS {0.10048676874059574, -8.098327285600545, 157.13956987344554}
#elif COOLING_AGGRESSIVENESS == COOLING_AGGRESSIVENESS_HIGH
#define PUMPS_COEFFICIENTS    {0.2689248895434452, -19.290132547864452, 339.2268041237107}
#define RADIATOR_COEFFICIENTS {0.169047619047619, -11.964285714285769, 208.16666666666936}
#endif

#elif COOLING_TYPE == COOLING_TYPE_PID

#define COOLING_PID_PUMPS_EFFORT     (0.8f)
#define COOLING_PID_RADIATORS_EFFORT (0.2f)

void cooling_pid_init(float kp, float ki, float kd, float sample_time, float anti_windUp);

#endif  // COOLING_TYPE

float from_temperature_to_pumps_percentage(float);
float from_temperature_to_radiator_percentage(float);

#endif  // COOLING_CONTROL_H