# include <iostream>
#include <cmath>
bool issafe();
bool solvesudoku();
bool findunassignedlocation();
bool usedinrow();
bool usedincolumn();
bool usedinbox(); 

bool issafe(int * matrix, int capacity, int row, int col, int num){
    if  (!(usedinrow(matrix, capacity, row, num)
        &&usedincolumn(matrix, capacity, col, num)
        &&usedinbox( matrix, num, capacity, row, col))){
            return true;
        }else{
            return false;
        }
}
bool solvesudoku(int * matrix, int capacity){
    if(!findunassignedlocation(matrix, capacity)){
        return true;
    }
    for (int i{0}; i<9; ++i){

    }
}
bool findunassignedlocation(int * matrix, int capacity){
    for(int i{0}; i<sqrt(capacity); ++i){
        for (int t{0}; t<sqrt(capacity);++t){
            if(matrix[t+i*sqrt(capacity)]==0){
                return true;
            }
        }
    }
    return false;
}
bool usedinrow(int * matrix, int capacity, int row, int num){
    for(int i{0}; i<sqrt(capacity);++i){
        if(matrix[row*sqrt(capacity)+i]==num){
            return true;
        }
    }
    return false;
}
bool usedincolumn(int * matrix, int capacity, int col, int num){
    for (int i{0}; i<sqrt(capacity); ++i){
        if(matrix[col+sqrt(capacity)*i]==num){
            return true
        }
    }
    return false;
}
bool usedinbox(int * matrix, int num, int capacity, int row, int col){
    for(int i{0}; i<3; ++i){
        for (int t{0}; t<3; ++t){
            if(matrix[col+t+(sqrt(capacity)*i)] == num){
                return true;
            }
        }
    }
    return false;
}