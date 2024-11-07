#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,col;
bool  drow = false;

void display_board(){
	system("cls");
	cout<<"\n\n\t\t!!!\tTICK CROSS GAME\t    !!!\n";
	cout<<"\n\n\tPlayer1[X]\n\tPlayer2[O]\n\n\n";
	
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
	cout<<"\t\t\t_____|_____|_____\n";
	cout<<"\t\t\t     |     |     \n";
	cout<<"\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
	cout<<"\t\t\t     |     |     \n\n\n";
	
}
void player_turn(){
	
//	int choice;
	
	
	if(turn=='X')
        cout<<"\t\nEnter your location to mark[1-9] Player1 turn[X]:";
	if(turn=='O')
	   cout<<"\t\nEnter your location to mark[1-9]  Player2 turn[O]:";
	
	//cin>>choice;
	
	switch(getch()){
		case '1': row=0;col=0;break;
		case '2': row=0;col=1;break;
		case '3': row=0;col=2;break;
		case '4': row=1;col=0;break;
		case '5': row=1;col=1;break;
		case '6': row=1;col=2;break;
		case '7': row=2;col=0;break;
		case '8': row=2;col=1;break;
		case '9': row=2;col=2;break;
		
		default:
		    cout<<"Invalid choice.\n";
		    Sleep(3000);
			break;		
	}
	
	
	
	if(turn=='X' && board[row][col]!='X'&&board[row][col]!='O')
	{
		board[row][col]='X';
		turn='O';
	}
    else if(turn=='O' && board[row][col]!='X'&&board[row][col]!='O')
	{
		board[row][col]='O';
		turn='X';
	}
	else
	{
		cout<<"\n\tBOX Already filled!!\n\n";
		player_turn();
	}
	
	display_board();
	
}
bool gameover()
{ 
 // Check win conditions (rows, columns, diagonals)
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return false;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return false;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    // Check for draw
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    drow = true;
    return false;



	
}
void choose_turn() {
	system("cls");
   // int player_choice;
    cout<<"\n\n\t\t THIS IS TICK TACK TOE GAME!!!\n\n";
    cout << "\tChoose your player:";
    cout << "\n\n\t1. Player 1 [X]\n";
    cout << "\n\t2. Player 2 [O]\n";
    cout << "\n\tEnter your choice (1 or 2): ";
//start:
//    cin >> player_choice;
//
//
//    if (player_choice == 1) {
//        turn = 'X';  // Player 1 starts as 'X'
//    } else if (player_choice == 2) {
//        turn = 'O';  // Player 2 starts as 'O'
//    } else {
//        cout << "Invalid choice! Please choose again.\n";
//        //choose_turn();
//    goto    start;
//    } 
//    switch(player_choice){
//    	case 1:turn = 'X';break; 
//    	case 2:turn = 'O';break;
//    	default:cout << "Invalid choice! Please choose again.\n";
//                choose_turn();break;
//    		
//	}
//if(_kbhit()){
    switch(_getch())
     {
    	case '1':
		turn = 'X';
		break; 
    	case '2':
		turn = 'O';
		break;
    	default:
		cout << "Invalid choice! Please choose again.\n";
		Sleep(2000);
        choose_turn();
		break;	
	}
//}
}

int main(){
	choose_turn();
	while(gameover())
{
	
	display_board();
	player_turn();
}
 if (turn == 'X' && !drow)
        cout << "Player 2 [O] wins! Congratulations!\n";
    else if (turn == 'O' && !drow)
        cout << "Player 1 [X] wins! Congratulations!\n";
    else
        cout << "Game is a draw!\n";

    return 0;
	
}

