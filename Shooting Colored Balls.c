#include <stdio.h>
int main()
{
	int row,column,s1,s2,x,y,score=0;
	scanf("%d%d",&row,&column);
	char array[row][column];
	char flag,a;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(i==0||i==row-1||j==0||j==column-1)
			{
				array[i][j]='#';
			}

			else
			{
				array[i][j]=' ';
			}
		}
	}
	scanf(" %c %d%d ",&a,&s1,&s2);
	array[s1][s2]='X';
	
	x=1;
	y=1;
	while(1)
	{
		scanf("%c",&flag);

		if(flag=='\n')
		{
			break;
		}

		else if(flag=='B'||flag=='G'||flag=='R')
		{ 
			array[x][y]=flag;
			y++;

			if(array[x][y]=='#')
			{
				x++;
				y=1;
			}				
		}
	}

	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("%c",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int r=2023;
	while(r--)
	{
		scanf("%c",&flag);	
		if(flag=='q'|| flag==EOF)
		{
			printf("Game Over, Total Score : %d \n",score);			
			return 0;
		}

		if(flag=='p')
		{
			scanf(" %c",&flag);
			if(flag=='q')
			{
			printf("Game Over, Total Score : %d \n",score);			
			return 0;
			}
		}
		
		while(flag==' ' || flag=='\n')
		{
			if(r==0)
			{
				break;
			}
			scanf("%c",&flag);;
			if(flag=='q')
			{
			printf("Game Over, Total Score : %d \n",score);			
			return 0;
			}
			r--;
		}

		if(flag=='A')
		{
			if(array[s1][s2-1]!='#')
			{
				array[s1][s2]=' ';			
				s2--;
				array[s1][s2]='X';
			}
		}

		else if(flag=='D')
		{
			if(array[s1][s2+1]!='#')
			{				
				array[s1][s2]=' ';			
				s2++;
				array[s1][s2]='X';
			}
		}

		else if(flag=='B')
		{			
			for(int i=s1;i>0;i--)
			{
			
				if(array[s1-1][s2]!=' ' && array[s1-1][s2]!='B')
				{
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
					printf("Game Over, Total Score : %d \n",score);			
					return 0;
				}
				
				if(array[i][s2]=='B')
				{
					array[i][s2]=' ';
					score+=1;
					printf("Score: %d\n",score);
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					if(array[i-1][s2]!='B')
					{
						break;
					}
				}

				else if(array[i-1][s2]=='#')
				{
					array[i][s2]='B';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

				else if(array[i-1][s2]=='R')
				{
					array[i][s2]='B';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

				else if(array[i-1][s2]=='G')
				{
					array[i][s2]='B';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

			}
		}

		else if(flag=='R')
		{			
			for(int i=s1;i>0;i--)
			{
				if(array[s1-1][s2]!=' ' && array[s1-1][s2]!='R')
				{
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					printf("Game Over, Total Score : %d \n",score);			
					return 0;
				}
				
				if(array[i][s2]=='R')
				{
					array[i][s2]=' ';
					score+=3;
					printf("Score: %d\n",score);
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					if(array[i-1][s2]!='R')
					{
						break;
					}
				}

				else if(array[i-1][s2]=='#')
				{
					array[i][s2]='R';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

				else if(array[i-1][s2]=='B')
				{
					array[i][s2]='R';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

				else if(array[i-1][s2]=='G')
				{
					array[i][s2]='R';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

			}
		}

		else if(flag=='G')
		{
			for(int i=s1;i>0;i--)
			{
				if(array[s1-1][s2]!=' ' && array[s1-1][s2]!='G')
				{
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					printf("Game Over, Total Score : %d \n",score);			
					return 0;
				}
				
				if(array[i][s2]=='G')
				{
					array[i][s2]=' ';
					score+=2;
					printf("Score: %d\n",score);
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					if(array[i-1][s2]!='G')
					{
						break;
					}
				}

				else if(array[i-1][s2]=='#')
				{
					array[i][s2]='G';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}			

				else if(array[i-1][s2]=='B')
				{
					array[i][s2]='G';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}

				else if(array[i-1][s2]=='R')
				{
					array[i][s2]='G';
					for(int i=0;i<row;i++)
					{
						for(int j=0;j<column;j++)
						{
							printf("%c",array[i][j]);
						}
						printf("\n");
					}
					printf("\n");
					break;
				}
			}
		}
	}
	printf("Game Over, Total Score : %d \n",score);
}
