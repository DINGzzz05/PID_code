#include "pid.h"

PID* PID_Init() {
	PID pid;
	PID* popid = &pid;
	return popid;
}


PID* PID_SetParameter(PID* popid) {
	PID* pid = PID_Init;
	memset(&pid, 0, sizeof(PID));
	printf("��ʼֵ�趨Ϊ0���밴�������ʽ���룺\nĿ��ֵ Kp Ki Kd �����޷�\n");
	scanf("%f %f %f %f %f", &pid->target, &pid->Kp, &pid->Ki, &pid->Kd, &pid->error_sum_max);
	return pid;
}


float PID_PostionalPID(PID* pid) {

	pid->error = pid->target - pid->current;
	pid->error_sum > +pid->error_sum_max ? +pid->error_sum_max : pid->error_sum + pid->error;
	pid->error_sum < -pid->error_sum_max ? -pid->error_sum_max : pid->error_sum + pid->error;//�����޷�
	pid->current = pid->output += (pid->Kp * pid->error + pid->Ki * pid->error_sum + pid->Kd * (pid->error - pid->error_last));
	pid->error_last = pid->error;
	return pid->output;

}

//����ʽPID��ʽ��
//=K_{p} ( e_{n}-e_{n-1} )+K_{i}e_{n}+K_{d}(e_{n}-2e_{n-1}+e_{n-2}) 
float PID_IncrementalPID(PID* pid) {

	float ep, ei, ed;

	pid->error = pid->target - pid->current;
	ep = pid->error - pid->error_last;
	ei = pid->error;
	ed = pid->error - 2 * pid->error_last + pid->error_llast;
	pid->output = pid->current = pid->Kp * ep + pid->Ki * ei + pid->Kd * ed;
	pid->error_llast = pid->error_last;
	pid->error_last = pid->error;
	return pid->output;

}