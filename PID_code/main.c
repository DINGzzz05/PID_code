#include<stdio.h>
#include<string.h>
#include"pid.h"

int main()
{
	PID* pid = PID_Init;
	PID_SetParameter(pid);

	int i = 0;
	char key;

	printf("请输入循环次数：\n");
	scanf("%n", &i);
	printf("选择位置式PID输入'p'，选择增量式PID输入'i':\n");
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
