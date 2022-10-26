#include<stdio.h>

int verificarSentenca(char *sentenca);

int main()
{
	char sentenca[1100];
	
	while(scanf("%s", sentenca) != EOF)
	{
		if(verificarSentenca(sentenca) == 0)
			printf("correct\n");
		else
			printf("incorrect\n");
	}
	
	return 0;
}

int verificarSentenca(char *sentenca)
{
	int parenteses = 0;
	
	if(*sentenca == ')')
		return -1;
	
	while(*sentenca != '\0' && parenteses >= 0)
	{
		if(*sentenca == '(')
			parenteses++;
		else if(*sentenca == ')')
			parenteses--;
			
		sentenca++;
	}
	
	return parenteses;
}
