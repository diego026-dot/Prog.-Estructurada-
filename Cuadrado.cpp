#include <stdio.h>
#include <stdlib.h>


int main() {
	
	int largo=20, ancho=10,i,j,k,x;
	while(x<2)
	{
		for(i=1;i<=largo+2;i++)
		{
			if(i==1||i==22)
			{
				printf("+");
			}else{
				printf("-");
			}
		}
		printf("\n");
		if(x==0)
		{
			for(j=1;j<=ancho;j++)
			{
				printf("I		     I\n");
			}
		}
		x+=1;
	}
	return 0;
}
