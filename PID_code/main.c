#include<stdio.h>
#include<string.h>
#include"pid.h"

int main()
{
	PID* pid = PID_Init;
	PID_SetParameter(pid);

	int i = 0;
	char key;

	printf("������ѭ��������\n");
	scanf("%n", &i);
	printf("ѡ��λ��ʽPID����'p'��ѡ������ʽPID����'i':\n");
	scanf("%c", &key);

	while (i>0)                                                                
	{
		i--;
		if (key == 'p')
			PID_PostionalPID(pid);
		else if (key == 'i')
			PID_IncrementalPID(pid);
	}

return 0;
}
