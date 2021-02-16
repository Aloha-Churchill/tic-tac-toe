#include <iostream>

enum Type{x, o, empty};

class Board{
    int arr[3][3];
    public:
        void CreateBoard(); 
};

void Board::CreateBoard(){
    for(int r = 0; r< 3; r++){
        for(int c = 0; c<3; c++){
            this->arr[r][c] = empty;
        }
    }
}

int main(){
    Board b1;
}

