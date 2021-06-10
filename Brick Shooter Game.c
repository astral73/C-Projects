#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char field[50][50];
void print(int y,int x);
int s=0;
void throw(char tb,double c1,double c2,int p1,int p2);

int main()
{
	int x;
	int y;
	int i,j,l,p1,p2;
	double c1,c2;
	char bricks,tb;
	
	scanf("%d%d",&x,&y);

	for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
			if(j==0 || j==x-1)
			{
				field[i][j]='|';
			}

			else if(i==0 && j!=0 && j!=x-1)
			{
				field[i][j]='~';
			}

			else
			{
				field[i][j]=' ';
			}
		}
	}

	for(i=1;i<=y-2;i++)
	{
		for(j=1;j<=x-2;j++)
		{
			scanf("%c",&bricks);
			if(bricks=='\n')
			{
				j--;
				continue;
			}

			if(bricks=='e')
			{
				scanf("%c",&bricks);
				if(bricks=='n')
				{
					scanf("%c",&bricks);
					if(bricks=='d')
					{
						break;
					}
				}
			}

			field[i][j]=bricks;
		}
		if(bricks=='d')
		{
			break;
		}
	}
	
	scanf("%d%d",&p1,&p2);
	field[p2][p1]='_';

	for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
			printf("%c",field[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	while(1)
	{
		scanf("%c",&tb);
		if(tb=='R' || tb=='G' || tb=='B' || tb=='Y')
		{
			scanf("%lf%lf",&c1,&c2);
			if(c1/c2==1)
			{
				
			}
		while(1)	
		{
			if((c1>=1.0 || c1<=-1.0) || (c2>=1.0 || c2<=-1.0))
			{
				c1/=10.0;
				c2/=10.0;
			}
			if((c1<1 && c1>-1) && (c2<1 && c2>-1))
			{
				break;
			}
		}
			throw(tb,c1,c2,p1,p2);

			

print(y,x);
		}
		

		else if(tb=='q')
		{
			printf("Game is over. Your score is %d!",s);
			break;
		}
		
	}
	
	
}
void print(int y,int x)
{
int i=0;
int j=0;
for(i=0;i<y;i++)
	{
		for(j=0;j<x;j++)
		{
			printf("%c",field[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void throw(char tb,double c1,double c2,int p1,int p2)
{

	int y,k,x=1,new2,new1,coun=0;
	while(1)
	{
		float p1n,p2n;
			p2n=(float)p2+(float)x*c2;
			p1n=(float)p1+(float)x*c1;
			new2=p2n;
			new1=p1n;
			x++;
			if(field[new2-1][new1]!=' ')
			{
				break;
			}
			if(field[new2][new1-1]=='|')
			{
			break;			
			}
	}
	
	if(field[new2][new1-1]=='|')
	{
		x=1;
		int new_2;
		int new_1;
	while(1)
		{
			new_2=(float)new2+(float)(x*c2);
			new_1=(float)new1-(float)(x*c1);
			new2=new_2;
			new1=new_1;
			x++;
			
			if(field[new2-1][new1]!=' ')
			{
				break;
			}
	
		}
	}
	if(field[new2-1][new1]=='R' ||field[new2-1][new1]=='G' || field[new2-1][new1]=='B' || field[new2-1][new1]=='Y' || field[new2-1][new1]=='~' )
	{
		field[new2][new1]=tb;
		
	}
	for(y=-1;y<=1;y++)
	{
		for(k=-1;k<=1;k++)
		{
			if(field[new2+y][new1+k]==tb)
			{
				coun++;
			
			}
		}
	}

	if(coun>=3)
	{
		for(y=-1;y<=1;y++)
		{
			for(k=-1;k<=1;k++)
			{
				if(field[new2+y][new1+k]==tb)
				{
					field[new2+y][new1+k]=' ';
				}
			}
		}
	}
	
				if(coun==3)
				{
					s+=30;
					printf("You got 30 points. Score: %d\n",s);
				}

				else if(coun==4)
				{
					s+=40;
					printf("You got 40 points. Score: %d\n",s);
				}

				else if(coun>4)
				{
					s+=100;
					printf("You got 100 points. Score: %d\n",s);
				}

}
