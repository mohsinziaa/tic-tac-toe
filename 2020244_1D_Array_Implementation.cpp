//Name:Mohsin Zia.
//Reg#2020244.
//1-D Array Implementation.

#include<iostream>
#include<ctime>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<iomanip>

using namespace std;

	//To Show Tic-Tac-Toe Board.	
	void show_board(char positions[]){
		
		
		system("Color 70");
		cout<<endl;		
				
		cout<<"\t\t\t\t\t      |    |      "<<endl;
		cout<<"\t\t\t\t\t   "<<positions[0]<<"  | "<<positions[1]<<"  |  "<<positions[2]<<endl;	
		cout<<"\t\t\t\t\t______|____|______"<<endl;
		cout<<"\t\t\t\t\t      |    |      "<<endl;
		cout<<"\t\t\t\t\t   "<<positions[3]<<"  | "<<positions[4]<<"  |  "<<positions[5]<<endl;	
		cout<<"\t\t\t\t\t______|____|______"<<endl;
		cout<<"\t\t\t\t\t      |    |      "<<endl;
		cout<<"\t\t\t\t\t   "<<positions[6]<<"  | "<<positions[7]<<"  |  "<<positions[8]<<endl;			
		cout<<"\t\t\t\t\t      |    |      "<<endl;
	
	}
	
	//To Show Timer Before Computers Move.	
	void timer(int counter){
		
		while(counter>=0){
			
			cout<<"\rComputer is making its move in "<<counter<<" seconds "<<flush;
			Sleep(900);
			counter--;
		}
		
	}
	
	//Whole game play coding is done in this function.	
	void game_play(char &move,char playersMove,char computersMove,char positions[],int choice,int grid,int &turns,string name,int counter);	
	
	//This updates the array according to move made.	
	void updatePositions(int &choice , int &grid);
	
	//This function finds the winner.
	bool checkWinner(char playersMove,char computersMove,char positions[],int grid,int &turns,string name,int &playerWins,int &computerWins,int &draws);
	
	
int main(){
	
	//Declaration of all variables.
	int counter=5;
	char move;
	int choice;
	int grid;
	char play;
	string name;
	int playerWins=0;
	int computerWins=0;
	int draws=0;
	char playersMove;	
	char computersMove;	
			
	
	cout<<"Enter your first name : ";
	cin>>name;
	cout<<endl;
	
	
	cout<<"Hey "<<name<<" select which one you would like to set as your move(X,O)? ";
	cin>>move;
	cout<<endl;
	
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
	cout<<"				*******CS-103L FINAL PROJECT*******"<<endl<<endl;

	
	
do{	
	
	int turns=0;  
	char positions[9]={'1','2','3','4','5','6','7','8','9'};		//1-D Array Declaration of positions.
	
	cout<<"				*******TIC-TAC-TOE GAMEPLAY*******"<<endl;
	
	while(checkWinner(playersMove,computersMove,positions,grid,turns,name,playerWins,computerWins,draws)!=false){			//This loop runs until this function is NOT false.

	show_board(positions);		
	checkWinner(playersMove,computersMove,positions,grid,turns,name,playerWins,computerWins,draws);
	game_play(move,playersMove,computersMove,positions,choice,grid,turns,name,counter);
	
	}
	
	cout<<"\n\n\n";

	cout<<"To proceed further, " <<endl;
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
		cout<<"\t\t\t\t"<<"Draw Games	"<<setw(10)<<"|           "<<draws<<" times "<<endl;
		cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
		cout<<"\t\t\t\t      		"<<setw(10)<<"|            "<<endl;
		
		cout<<"\n\n\n		Do You Want To Play Again? (y/n) : " ;
		cin>>play;
		system("cls");
						
}

while(play=='Y' || play=='y');
	
	cout<<"\n\n\n\n";
	cout<<endl;
	//Thanking the user for playing the game.
	
	cout<<"						*******************************"<<"\n\n";
    cout<<"   					*THANKYOU FOR PLAYING THE GAME*"<<"\n\n";
    cout<<" 				*******************************"<<"\n\n ";


	return 0;
}
		
		void game_play(char &move,char playersMove,char computersMove,char positions[],int choice,int grid,int &turns,string name,int counter){
			
			if(move==playersMove){
			
				cout<<endl;
				cout<<name<<"'s turn ! "<<endl;
				cout<<"Enter your desired position : " ;		
				cin>>choice;
				cout<<name<<" has chosen position "<<choice<<" ! "<<endl;

		}
	
	
			if(move==computersMove){
				
				cout<<endl;
				cout<<"It's Computers Turn ! "<<endl;
				srand(time(NULL));			
				choice=rand()%9 + 1;							//Random number generator from 1-9;
				timer(counter);									//Counter before computers turn.
				cout<<"\nComputer has chosen position "<<choice<<" ! "<<endl;
	
		}			
		
			updatePositions(choice , grid);						//For updating the position on table after the choice.
		
				if(move==playersMove && positions[grid]!='X' && positions[grid]!='O'){
					
					turns++;
					positions[grid]=playersMove;
					cout<<"Board after move of "<<name<<" => "<<endl;
					move=computersMove;							//This gives computer the next turn if the condition is true.
	
			}
		
				else if(move==computersMove && positions[grid]!='X' && positions[grid]!='O'){
					
					turns++;
					positions[grid]=computersMove;
					move=playersMove;							//This gives user the next turn if the condition is true.
					cout<<"Board after move of computer => "<<endl;

			}
				//In case of occupied position.
				
				else{

					cout<<"Sorry Your desired position is already occupied ! "<<endl;
					cout<<"Enter again ! "<<endl;

			}	
					
		show_board(positions);
		system("pause");								
		system("cls");


}
	

	void updatePositions(int &choice , int &grid){
		
		switch(choice){
		
		case 1:
				grid=0;		
				break;
		
		case 2:
				grid=1;	
				break;
		
		case 3:
				grid=2;
				break;
		
		case 4:
				grid=3;
				break;
		
		case 5:
				grid=4;
				break;
		
		case 6:
				grid=5;
				break;
		
		case 7:
				grid=6;
				break;
		
		case 8:
				grid=7;
				break;
		
		case 9:
				grid=8;
				break;
		
		default:	
				cout<<"Invalid choice ! ";					
				break;
		
	}
}

		bool checkWinner(char playersMove,char computersMove,char positions[],int grid,int &turns,string name,int &playerWins,int &computerWins,int &draws){
			
				if((positions[0]==positions[4] && positions[0]==positions[8]) || (positions[2]==positions[4] && positions[2]==positions[6])){		//To check winner from the diagonals of the board.
				
					if(positions[4]==playersMove){
				
						show_board(positions);
						cout<<"\n\n\n					"<<name<<" has won the game ! "<<endl;
						playerWins++;
						Beep(1800,1200);	
						
						return false;
				
					}
					
					if(positions[4]==computersMove){
					
						show_board(positions);
						cout<<"\n\n\n					"<<"Computer has won the game ! ! "<<endl;
						computerWins++;
						Beep(1800,1200);
						
						return false;
					
					}
				}
				
					
					for(grid=0;grid<9;grid+=3){
					
						if((positions[grid]==positions[grid+1]) && (positions[grid]==positions[grid+2])){											//To check winner row wise.
					
							if(positions[grid]==playersMove){
							
								show_board(positions);							
								cout<<"\n\n\n					"<<name<<" has won the game ! "<<endl;
								playerWins++;
								Beep(1800,1200);
						
								return false;
						
						}
						
							if(positions[grid]==computersMove){
						
								show_board(positions);								
								cout<<"\n\n\n					"<<"Computer has won the game ! ! "<<endl;
								computerWins++;
								Beep(1800,1200);
							
								return false;
							
						}	
				}
					
		}
					
						for(grid=0;grid<3;grid++){
							
							if((positions[grid]==positions[grid+3]) && (positions[grid]==positions[grid+6])){											//To check the winner column wise.
							
								if(positions[grid]==playersMove){
							
								show_board(positions);								
								cout<<"\n\n\n					"<<name<<" has won the game ! "<<endl;
								playerWins++;
								Beep(1800,1200);
							
								return false;
							
							}
							
							else if(positions[grid]==computersMove){
								show_board(positions);
								
								cout<<"\n\n\n					"<<"Computer has won the game ! ! "<<endl;
								computerWins++;
								Beep(1800,1200);

								return false;	
							
							}	
					
					}					
			
			}			
					
							if(positions[4]=='X' || positions[4]=='O'){																						//To check if the game is draw.
							
								if(turns>8){
									
									show_board(positions);
									cout<<"\n\n\n					"<<" It's A Draw ! "<<endl;
									draws++;
									Beep(1800,1200);
								
									return false;
						
						}
					
			}
					
}

