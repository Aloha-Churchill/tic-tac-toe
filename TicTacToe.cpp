/*
Name: Aloha Churchill
This is a Tic Tac Toe game. It allows for two players and lets the players choose their position.
*/

#include <iostream>
#include <cstdlib>

/*
The Board is implemented as a two dimensional array.
*/
class Board{
    int arr[3][3];
    public:
        void CreateBoard();
        void DisplayBoard();
        int GetPlayerChoice(); 
        void PlaceMarker(int location);
};


/*
Initializes all board values to 0
*/
void Board::CreateBoard(){
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){
            this->arr[r][c] = 0;
        }
    }
}

/*
Display board prints out the 3x3 current board
Player 1 (positive position values) is represented as an X
Player 2 (negative position values) is represented as an O
*/
void Board::DisplayBoard(){
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){ 
            //0 if nobody has played
            if(this->arr[r][c] == 0){
                std::cout << "   -   ";
            }
            //+ if player 1 (uses X)
            if(this->arr[r][c] > 0){
                std::cout << "   X   ";
            }
            //- if player 2 (uses O)
            if(this->arr[r][c] < 0){
                std::cout << "   O   ";
            }       
        }
        std::cout << "\n";
    }    
}

/*
Get player choice determines which player is playing and also the location that 
the player chooses. It prints out all positions indicating them as open or closed for the player
and then takes the returns the players choice*player where player is either 1 or -1 to indicate player 1
or player 2.

Displays board as choices
(1,1) (1,2) (1,3)
(2,1) (2,2) (2,3)
(3,1) (3,2) (3,3)

*/
int Board::GetPlayerChoice(){
    int player;
    std::cout << "Which player are you: 1, 2?";
    std::cin >> player;

    if(player == 2){
        player = -1;
    }

    std::cout << "Choose an open choice of where to play: \n";
    int user_choice;
    int choice = 1;
    for(int r = 0; r<3; r++){
        for(int c = 0; c<3; c++){
            if(this->arr[r][c] == 0){
                std::cout << choice << ". [Open]  (" << r+1 << "," << c+1 << ") \n";
            }
            else{
                std::cout << choice << ". [Taken] (" << r+1 << "," << c+1 << ") \n";
            }
            choice ++;
        }
    }
    std::cin >> user_choice;
    return user_choice*player; //return positive if player 1 and negative if player 2;
}


/*
Takes in weighted location (pos/neg indicating which player) from GetPlayerChoice and fills in the value
at that position. The choices coorespond to the follwoing positions on the board.

1 2 3
4 5 6
7 8 9
*/

void Board::PlaceMarker(int location){
    int absolute_location = abs(location);
    int pos = 1;
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){
            if(pos == absolute_location){
                this->arr[r][c] = location;
                return;
            }
            pos ++;
        }
    }     

}

/*
Function runs until the entire board is filled out. Players can determine if anybody has won the game
at any point in time.
*/

int main(){
    Board b1;
    b1.CreateBoard();
    
    int num_turns = 0;
    while(num_turns < 9){
        b1.DisplayBoard();
        int choice = b1.GetPlayerChoice();
        b1.PlaceMarker(choice);
        num_turns ++;
    }

}
