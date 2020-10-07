/*
Auteur --> aiglematth
*/

//Includes
#include <stdio.h>

void vuln(void)
{
	int size   = 10;
	char win[] = {56, 14, 20, 65, 22, 8, 15, 65, 64, 64};
	char key   = 97;

	for(int i=0; i<size; i+=1)
	{
		printf("%c", win[i]^key);
	}
	printf("\n");
}

int main(void)
{
	int impossible = 1;

	printf("Vous n'aurez jamais mon flag !!!!\n");
	if(impossible == 0)
	{
		vuln();
	}

	return 0;
}
