#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	char* A = argv[1];
	char* B = (char*)calloc(sizeof(char), strlen(A));
	while (1)
	{
		gets_s(B, sizeof(B));
		if (strlen(B) == 0) break;
		int ascii[256] = { 0 };// в аски 255 символов
		
		for (int i = 0; i < strlen(A); i++)
		{
			ascii[A[i]]++;
		}
		int flag = 1;
		for (int i = 0; i < strlen(B); i++)
		{
			if (ascii[B[i]] == 0)
			{
				printf_s("FALSE\n");
				flag = 0;
				break;
			}
		}
		if (flag == 1) printf_s("TRUE\n");
	}
	free(B);
	return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	unsigned x = 0;
	for (int i = 0; i < argc; i++)
	{
		unsigned tmp = atoi(argv[i]);
		x |= (1 << tmp);
	}
	unsigned Day;
	while (1)
	{
		printf_s("Enter a day number:\n");
		scanf_s("%u", &Day);
		if (Day > 31)
		{
			printf_s("Error\n");
			continue;
		}
		if (Day == 0) break;
		if ((x & (1 << Day)) == 0) printf_s("Great morning to coffee!\n");
		else printf_s("Time to sleep!\n");
	}
}
//https://volstr.ru/?p=36
