#include <iostream>
#include <stdlib.h>
#include <time.h>
int main();
int * generatesudoku(int k);
bool usedincol(int * matrix, int * num, int col);
bool usedinrow(int * matrix, int * num, int row);
bool usedinbox(int * matrix, int * num, int row, int col);
void fillbox(int * matrix, int row, int col);
void filldiag(int * matrix);
void fillremain(int * matrix);
void removeval(int * matrix, int k);
void printsudoku(int * matrix);


int * generatesudoku(int k){
    int * matrix = new int[81];
    filldiag(matrix);
    fillremain(matrix);
    removeval(matrix, k);
    return matrix;
}
void fillbox(int * matrix, int row, int col){
    srand((unsigned)time(0)); 
    int * n = new int{rand()%9+1};
    for (int i{0}; i<3; ++i){
        for(int j{0}; j<3; ++j){
            while(usedinbox(matrix, n, row, col)){
                    * n = rand()%9+1;
                }
            matrix[col+j+row*i] = * n;
        }
    }
    delete n;
    n = nullptr;
}
void filldiag(int * matrix){
    for(int i{0}; i<9; i+=3){
        fillbox(matrix, i, i);
    }
}
void fillremain(int * matrix){
    int * m = new int{rand()%9+1};
    
    for(int i{1}; i<9; i+=3){
        for (int j{1}; j<9; j+=3){
            if(i==j){

            }else{
                for(int k{-1}; k<2; ++k){
                    for (int l{-1}; l<2; ++l){
                        while(usedinbox(matrix, m, (i-1), (j-1)), usedincol(matrix, m, (l+j)), usedinrow(matrix, m, (i+k))){
                            * m = rand()%9+1;
                        }
                        matrix[(i+k)*9+(l+j)] = * m;
                    }
                }
            }
        }
    }
    delete m;
    m = nullptr;
        
}
void removeval(int * matrix, int k){
    
    for(int i{0}; i<k; ++k){
        int * position = new int{rand()% 81};
        while(matrix[(*position)] == 0){
            * position = rand()% 81;
        }
        matrix[(*position)] = 0;
        delete position;
        position = nullptr;
    }   
}
bool usedincol(int * matrix, int * num, int col){
    for(int row{0}; row<9; ++row){
        if( matrix[col+(row*9)] == (*num) ){
            return true;
        }
    }
return false;
}
bool usedinrow(int * matrix, int * num, int row){
    for (int col{0}; col<9; ++col){
        if(matrix[col+(row*9)]==(*num)){
            return true;
        }
    }
return false;
}
bool usedinbox(int * matrix, int * num, int row, int col){
    for(int i{0}; i<3; ++i){
        for(int j{0}; j<3; ++j){
            if(matrix[(row+i)*9+(col+j)]==(* num)){
                return true;
            }
        }
    }
    return false;

}
void printsudoku(int k){
    int * grid = generatesudoku(k);
    for(int i{0}; i<9; ++i){
        for (int j{0}; j<9; ++j){
            std::cout<< grid[(i*9)+j];
        }
        std::cout<<std::endl;
    }
}
int main(){
    printsudoku(8);
    return 0;
}

