//Name:Mohsin Zia.
//Reg#2020244.
//2-D Array Implementation.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include<iomanip>

using namespace std;

	//To Show Tic-Tac-Toe Board.
	void show_board(char position[][3]){

	system("Color 70");
	cout<<endl;
		
	    cout<<"\t\t\t\t\t     |    |     \n";
	    cout<<"\t\t\t\t\t  "<<position[0][0]<<"  | "<<position[0][1]<<"  |  "<<position[0][2]<<"  \n";
	    cout<<"\t\t\t\t\t_____|____|_____\n";
	    cout<<"\t\t\t\t\t     |    |     \n";
	    cout<<"\t\t\t\t\t  "<<position[1][0]<<"  | "<<position[1][1]<<"  |  "<<position[1][2]<<"  \n";
	    cout<<"\t\t\t\t\t_____|____|_____\n";
	    cout<<"\t\t\t\t\t     |    |     \n";
	    cout<<"\t\t\t\t\t  "<<position[2][0]<<"  | "<<position[2][1]<<"  |  "<<position[2][2]<<"  \n";
	    cout<<"\t\t\t\t\t     |    |     \n";		

}
	
	//To Show Timer Before Computers Move.
	void timer(int counter){
		
		while(counter>=0){
			
			cout<<"\rComputer is making its move in "<<counter<<" seconds ";
			Sleep(900);
			counter--;

		}
		
}
	
	//Whole game play coding is done in this function.
	void game_play(char &move,char playersMove,char computersMove,int rows , int columns , char position[][3],int choice,int &turns,string name,int &playerWins,int &computerWins,int counter);
	
	//This updates the array according to move made.
	void updateArray(int &choice , int &rows , int &columns );
		
	//This function finds the winner.	
	bool findWinner(char playersMove,char computersMove,char position[][3],int rows,int &turns,string name,int &playerWins,int &computerWins,int &gameDraw);


int main(){
	
	//Declaration in main.
	int rows;
	int columns;
	int choice;
	char play;
	int counter=5;
	string name;
	int playerWins=0;
	int computerWins=0;
	int gameDraw=0;
	char move;
	char playersMove;
	char computersMove;
	
	
		cout<<"\aEnter your name : " ;
		cin>>name;
		cout<<endl;
		
		cout<<"Hey "<<name<<" select which one you would like to set as your move (X,O) : " ;
		cin>>move;
		cout<<"\n\n";
	
	//Checking and updating the move.	
	if(move=='X'){
		
		playersMove='X';
		computersMove='O';
	
	}
	
	else if(move=='O'){
	
		playersMove='O';
		computersMove='X';
	
	}
	
	else{
	
		cout<<" Invalid input ! "<<endl;
		return 0;
	} 
	
	
		cout<<"				****** WELCOME TO MY GAME *******"<<endl ;
		cout<<"				****** CS103-L FINAL PROJECT *******"<<endl;
	
	do{
	
	int turns=0;
	char position[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};					//2-D Array Declaration of positions.
	cout<<endl;
	
	cout<<"				****** TIC-TAC-TOE GAMEPLAY! *******";
	cout<<"\n\n\n";
	
		while (findWinner(playersMove,computersMove,position,rows,turns,name,playerWins,computerWins,gameDraw)!=false){		//This loop runs until this function is NOT false.
		
					show_board(position);			
					findWinner(playersMove,computersMove,position,rows,turns,name,playerWins,computerWins,gameDraw);
					game_play(move,playersMove,computersMove,rows,columns,position,choice,turns,name,playerWins,computerWins,counter);
			
			}
		
	
			cout<<"\n\nTo proceed further,"<<endl;
			system("pause");
			system("cls");
			
			system("Color 0A");
			cout<<"\n\n\n\n";	

			//SCORE-BOARD:
		
			cout<<"\t\t\t\t\t ******SCORE BOARD****** "<<endl;
			cout<<"\t\t\t\t\t________________________"<<endl<<endl;
			cout<<"\n\n\n";
			
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t  Name		"<<setw(10)<<"|           Wins "<<endl;	
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;	
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t"<<name<<"		"<<setw(10)<<"|           "<<playerWins<<" times "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t"<<"Computer	"<<setw(10)<<"|           "<<computerWins<<" times "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;		
			cout<<"\t\t\t\t"<<"Draw Games	"<<setw(10)<<"|           "<<gameDraw<<" times "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
			cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
		
			
			cout<<"\n\n\n			Do You Want To Play Again? (y/n) : " ;
			cin>>play;
			system("cls");
	}		
	
	while(play == 'Y' || play == 'y');
	
	
	cout<<"\n\n\n\n";
	
	//Thanking the user for playing the game.		
	
	cout<<"						*******************************"<<flush<<"\n\n";
    cout<<"   					*THANKYOU FOR PLAYING THE GAME*"<<"\n\n";
    cout<<" 				*******************************"<<" \n\n ";

	return 0;
}

	void game_play(char &move , char playersMove,char computersMove, int rows , int columns , char position[][3],int choice,int &turns,string name,int &playerWins,int &computerWins,int counter){

		if(move==playersMove){
	
			cout<<"\nIt's "<<name<<"'s turn "<<endl;
			cout<<"Enter the position where you want to place your move: ";
			cin>>choice;			
			cout<<name<<" has made his move on position "<<choice<<" ! "<<endl;

		}
	
		if(move==computersMove){
		
			cout<<"\nIt's Computer's turn "<<endl;
			srand(time(NULL));
			choice=rand()%9+1;											//Random number generator from 1-9;
			timer(counter);												//Counter before computers turn.
			cout<<"\nComputer has made it's move on position "<<choice<<" ! "<<endl;		
		
		}
		
		updateArray(choice,rows,columns);								//For updating the position on table after the choice.
		 
			if(move==playersMove && position[rows][columns] !='X' && position[rows][columns] != 'O'){		
	
					position[rows][columns]=playersMove;
					turns++;
					cout<<"Board After "<<name<<"'s Move => "<<endl;
					move=computersMove;									//This gives computer the next turn if the condition is true.
		
		}
	
			else if(move==computersMove && position[rows][columns] !='X' && position[rows][columns] != 'O'){
			
					position[rows][columns]=computersMove;
					turns++;
					cout<<"Board After The Computers Move => "<<endl;
					move=playersMove;									//This gives user the next turn if the condition is true.
		
		}
	
			else{
					//In case of occupied position.
					
					cout<<"\nSorry ! the desired position is already occupied ! "<<endl;
					cout<<"Clearing up screen , enter your desired position once again! "<<endl<<endl ;
		
		}
						
				show_board(position);
				system("pause");
				system("cls");	
		
}
	
		void updateArray(int &choice , int &rows , int &columns ){
		
			switch(choice){

				case 1:
					
					rows=0 ;
					columns=0;		
					break;
				
				case 2:
		
					rows=0 ;
					columns=1;			
					break;
				
				case 3:
		
					rows=0 ;
					columns=2;
					break;
				
				case 4:
				
					rows=1 ;
					columns=0;
					break;
					
				case 5:
					
					rows=1 ;
					columns=1;
					break;
					
				case 6:
			
					rows=1 ;
					columns=2;
					break;
					
				case 7:
			
					rows=2 ;
					columns=0;
					break;
					
				case 8:
			
					rows=2 ;
					columns=1;
					break;
					
				case 9:
			
					rows=2 ;
					columns=2;	
					break;
					
				default:
			
					cout<<"Invalid move "<<endl;
					break;				
	
	}
}
	




			bool findWinner( char playersMove,char computersMove, char position[][3],int rows,int &turns,string name,int &playerWins,int &computerWins,int &gameDraw){
			
				if (position[0][2]==position[1][1] && position[1][1]==position[2][0] || position[0][0]==position[1][1] && position[1][1]==position[2][2]){		//To check winner from the diagonals.
				 
					if(position[1][1]==playersMove){
					
						show_board(position);
						cout<<endl<<endl;				
						cout<<"\n\n\n				"<<name<<" has won the game ! "<<endl;
						playerWins++;
						Beep(1500, 1000);
		
						return false;	
		
				}
			
					if(position[1][1]==computersMove){
		
						show_board(position);
						cout<<endl;				
						cout<<"\n\n\n				"<<"Computer has won the game ! ! "<<endl;
						computerWins++;
						Beep(1500, 1000);
				
						return false;	
			
				}	
		}
		
					rows=3;
					for(int i=0 ; i<rows ; i++){
			
						if(position[i][0]==position[i][1] && position[i][1]==position[i][2] || position[0][i]==position[1][i] && position[1][i]==position[2][i]){		//To check winner from rows and columns.
				
							if(position[i][0]==playersMove && position[i][1]==playersMove && position[i][2]==playersMove || position[0][i]==playersMove && position[1][i]==playersMove && position[2][i]==playersMove){
				
								show_board(position);	
								cout<<endl<<endl;				
								cout<<"\n\n\n					"<<name<<" has won the game ! "<<endl;
								playerWins++;		
								Beep(1800, 900);
				
								return false;	
				
					}
				
							if(position[i][0]==computersMove && position[i][1]==computersMove && position[i][2]==computersMove || position[0][i]==computersMove && position[1][i]==computersMove && position[2][i]==computersMove){
				
								show_board(position);				
								cout<<"\n\n\n					"<<"Computer has won the game ! ! "<<endl;
								computerWins++;
								Beep(1500, 1000);
		
								return false;	
		
					}
			}		
	}
							if((position[0][0]==computersMove || position[0][0]==playersMove) && (position[1][1]==computersMove || position[1][1]==playersMove)){	
	
								if(turns>8){											//To check if the game is draw.
	
									show_board(position);			
									cout<<"\n\n\n				"<<" It's A Draw ! "<<endl;
									gameDraw++;
									Beep(1500, 1000);

									return false;	

				}
	
		}
		
}


