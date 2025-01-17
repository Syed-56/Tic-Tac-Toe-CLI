#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <limits.h> //is library ka kia kaam hai
#include <string.h> 
//return wali chizein samajh ni ayin is program mein
char game[3][3]; //main ke bahir kese declare kr rahe char or int
int currentplayer=1;

void loadingScreen() {
    printf("\n\n\n\n\t\t\t\tTic-Tac-Toe\n\n\t\t\tLoading ");
    for (int i = 0; i < 20; i++) {
        printf("=");
        fflush(stdout);  // Ensure each '#' prints immediately
        Sleep(100);      // Delay for loading animation in milliseconds
    }
    printf("\n\n");
    Sleep(1000);         // Pause for 1000ms before moving to the next screen
    system("cls");       // Clear screen for Windows CLI
}
void InitializeBoard() //ye samjha
{
	int n='1';
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			game[i][j]=n;
			n=n+1;
		}
	}
}

void DisplayBoard()
{
	printf("+---+---+---+\n");
	for (int i=0;i<3;i++)
	{
		printf("|");
		for (int j=0;j<3;j++)
		{
			printf(" %c |",game[i][j]);
		}
		printf("\n");
		printf("+---+---+---+\n");
	}
}

int PlayerMove(char name1[],char name2[])
{
	int position,row,col;
	if (currentplayer==1)
	{
		printf(" -) Where would you like to place your 'X' %s : ",name1);
	}
	else if (currentplayer==2)
	{
		printf(" -) Where would you like to place your 'O' %s : ",name2);
	}
	scanf("%d", &position);
	if (position<1 || position>9)
	{
		printf(" -) Invalid position entered\n");
		return 0;
	}
	else
	{ //ye samjha pura
		row=(position-1)/3;
		col=(position-1)%3;
		if (game[row][col]=='X'||game[row][col]=='O')
		{
			printf(" -) Already occupied\n");
			return 0;
		}
		else
		{
			if (currentplayer==1)
			{
				game[row][col]='X';
				currentplayer=2;
			}
			else
			{
				game[row][col]='O';
				currentplayer=1;
			}
			return 1;
		}
	}

}

int CheckWin()
{
	if (game[0][0]==game[0][1] && game[0][1]==game[0][2])
	{
		if (game[0][0]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[1][0]==game[1][1] && game[1][1]==game[1][2])
	{
		if (game[1][0]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[2][0]==game[2][1] && game[2][1]==game[2][2])
	{
		if (game[2][0]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][0]==game[1][0] && game[1][0]==game[2][0])
	{
		if (game[0][0]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		} 
	}
	else if (game[0][1]==game[1][1] && game[1][1]==game[2][1])
	{
		if (game[0][1]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][2]==game[1][2] && game[1][2]==game[2][2])
	{
		if (game[0][2]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][0]==game[1][1] && game[1][1]==game[2][2])
	{
		if (game[0][0]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (game[0][2]==game[1][1] && game[1][1]==game[2][0])
	{
		if (game[0][2]=='X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{	
		return 0;
	}  //is pure me sirf X kelie hai O keie nahi
	
}

int CheckTie()
{
	int flag=0;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (game[i][j]>='1' && game[i][j]<='9') //ye tu character ke sath kia kr raha
			{
				flag=1;
				break;
			}
		}
		if (flag==1)
		{
			break;
		}
	}
	if (flag==0) //game has tied
	{
		return 1;
	}
	else
	{
		return 0; // game is stil left
	}
}
int main() 
{
	loadingScreen();
	printf("\t\t\t\t---- Welcome to Tic Tac Toe ---\n\n");
	printf(" -) Creators : Syed Sultan Ahmed | Muhammad Taha Anwar | Yash Raj\n\n");
	InitializeBoard();
	char player1[50];
	char player2[50];
	printf(" -) Enter the name of Player 1 : ");
	gets(player1);
	printf(" -) Enter the name of Player 2 : ");
	gets(player2);
	Sleep(1000);         // Short pause before starting game
    system("cls");
	printf("\n\t The Game begins\n\t==================\n\n");
	printf("Player 1 : %s\nPlayer 2 : %s\n\n", player1, player2);
	int flag=0;
	while(flag==0)
	{
		DisplayBoard();
		if (PlayerMove(player1,player2)==0)
		{
			continue; //ye kia scn hai
		}
		if (CheckWin()==1)
		{
			DisplayBoard();
			printf("\t%s wins\n",player1);
			flag=1;
		}
		else if(CheckWin()==2)
		{
			DisplayBoard();
			printf("\t%s wins\n",player2);
			flag=1;
		}
		else if(CheckTie()==1)
		{
			DisplayBoard();
			printf("\t Game is tied\n");
			flag=1;
		}
	}
}