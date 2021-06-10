#include <stdio.h>

int main()
{  
    int row = 0;
    int column = 0;

    int score = 0;
    int player_row = 0;
    int player_column = 0;
    char player_operator = '+';

    char input;

    scanf("%d%d", &row, &column);
    char maze[row][column];
    
    for(int i = 0; i < row; i++)
    {
        for(int k = 0; k < column; k++)
        {
            maze[i][k] = ' ';
        }
    }
    
    char dump;
    dump = getchar();

    int right = 0;
    int down = 0;

    while(1)
    {
        scanf("%c", &input);

        if (input == 'q')
            break;

        maze[down][right] = input;
        right++;

        if(input == '\n')
        {
            down++;
            right = 0;
        }

        if (down == row)
            break;
    }

    /*Printing maze*/
    for(int i = 0; i < row; i++)
    {
        for(int k = 0; k < column; k++)
        {
            printf("%c", maze[i][k]);
        }
        printf("\n");
    }
    printf("\n");

    scanf("%d%d", &player_row, &player_column);
    dump=getchar();

    int temp = 0;
    while(1)
    {
        scanf("%c", &input);

        printf("command:%c\n", input);

        if (input == 'q')
            break;
        
        if (input == 'r')
        {
            if (0 <= player_column && player_column < column - 1)
            {
                maze[player_row][player_column] = ' ';
                player_column++;
            }
        }

        else if (input == 'l')
        {
            if (0 <= player_column && player_column < column - 1)
            {
                maze[player_row][player_column] = ' ';
                player_column--;
            }
        }

        else if (input == 'd')
        {
            if (0 <= player_row && player_row < row - 1)
            {
                maze[player_row][player_column] = ' ';
                player_row++;
            }
        }

        else if (input == 'u')
        {
            if (0 <= player_row && player_row < row - 1)
            {
                maze[player_row][player_column] = ' ';
                player_row--;
            }
        }

        if (maze[player_row][player_column] == '*' )
        {
            player_operator = '*';
            printf("Operator changed to *\n");
        }

        else if (maze[player_row][player_column] == '+' )
        {
            player_operator = '+';
            printf("Operator changed to +\n");
        }

        else if (maze[player_row][player_column] == '-' )
        {
            player_operator = '-';
            printf("Operator changed to -\n");
        }

        else
        {
            if (maze[player_row][player_column] == '[' )
            {
                maze[player_row][player_column] = ' ';
                player_column++;

                while(maze[player_row][player_column] != ']')
                {
                    temp = temp*10 + maze[player_row][player_column] - '0';
                    maze[player_row][player_column] = ' ';
                    player_column++;
                }

                maze[player_row][player_column] = ' ';
            }

            else if (maze[player_row][player_column] == ']' )
            {
                maze[player_row][player_column] = ' ';
                player_column--;

                while(maze[player_row][player_column] != '[')
                {
                    temp = temp*10 + maze[player_row][player_column] - '0';
                    maze[player_row][player_column] = ' ';
                    player_column--;
                }

                maze[player_row][player_column] = ' ';
            }

            else if ('0' <= maze[player_row][player_column] && maze[player_row][player_column] <= '9')
            {
                temp = maze[player_row][player_column] - '0';
            }

            if (player_operator == '*')
            {
                printf("%d * %d = %d\n", score, temp, score*temp);
                score = score * temp;
            }
                
            else if (player_operator == '+')
            {
                printf("%d + %d = %d\n", score, temp, score+temp);
                score = score + temp;
            }
        
            else if (player_operator == '-')
            {
                printf("%d - %d = %d\n", score, temp, score-temp);
                score = score - temp;
            }

        }

        temp = 0;
    }

    printf("Game is over. Your score is %d!\n", score);
}