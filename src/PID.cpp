#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  
  PID::Kp = Kp;
  PID::Kd = Kd;
  PID::Ki = Ki;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  
  double prev_cte = p_error;
  p_error = cte;
  d_error = cte - prev_cte;
  i_error += cte;
}

double PID::TotalError() {
  return (-Kp * p_error) + (-Kd * d_error) + (-Ki * i_error);  
}

