#include <iostream>

class Board{
    int arr[3][3];
    public:
        void CreateBoard();
        void DisplayBoard(); 
};

void Board::CreateBoard(){
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){
            this->arr[r][c] = 0;
        }
    }
}

void Board::DisplayBoard(){
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){ 
            if(this->arr[r][c] == 0){
                std::cout << "   -   ";
            }
            if(this->arr[r][c] == -1){
                std::cout << "   X   ";
            }
            if(this->arr[r][c] == 1){
                std::cout << "   O   ";
            }       
        }
        std::cout << "\n";
    }    
}

int main(){
    Board b1;
    b1.CreateBoard();
    b1.DisplayBoard();
}

