#include<stdio.h>

int minerar(char *mina);

int main()
{
	char mina[1000];
	int casosTeste, quantidadeDiamantes;
	
	scanf("%i", &casosTeste);
	
	while(casosTeste > 0)
	{
		scanf("%s", mina);
		
		quantidadeDiamantes = minerar(mina);
		
		printf("%d\n", quantidadeDiamantes);
		
		casosTeste--;	
	}
	
	return 0;
}

int minerar(char *mina)
{
	int i, diamantes, comecoDiamante;
	
	i = diamantes = comecoDiamante = 0;
	
	while(*(mina + i) != '\0')
	{
		if(*(mina + i) == '<')
		{
			comecoDiamante++;
		}
		else if(*(mina + i) == '>' && comecoDiamante > 0)
		{
			diamantes++;
			comecoDiamante--;
		}
		
		i++;
	}
	
	return diamantes;
}
