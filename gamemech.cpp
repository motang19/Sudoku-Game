#include <iostream>
#include <stdlib.h>
#include <time.h>
 
class sudoku{
  public:
    sudoku();
    ~sudoku();
    bool usedinbox(int & num, int row, int col);
    bool usedincol(int num, int col);
    bool usedinrow(int num, int row);
    void fillbox( int row, int col);
    void filldiag();
    bool fillremain(int row, int col );
    void generatesudoku(int k);
    int * getMatrix();
    void removeval(int k);
    void printsudoku();
    bool validrow(int row);
    bool validcol(int col);
    bool validbox(int row, int col);
    bool validate();
    int findunassigned();
    bool solve(int index);
    void enter();
    void operator = (sudoku b);

  private:
    int * matrix;
    
};
sudoku::sudoku(){
  matrix = new int[81];
}
 
sudoku::~sudoku(){
  delete matrix;
  matrix = nullptr;
}
 
 
bool sudoku::usedinbox(int & num, int row, int col){
    for(int i{0}; i<3; ++i){
        for(int j{0}; j<3; ++j){
            if(matrix[(row+i)*9+(col+j)]==num ){
                return true;
            }
        }
    }
    return false;
 
}
bool sudoku::usedincol(int num, int col){
    for(int row{0}; row<9; ++row){
        if( matrix[col+(row*9)] == num ){
            return true;
        }
    }
return false;
}
bool sudoku::usedinrow(int num, int row){
    for (int col{0}; col<9; ++col){
        if(matrix[col+(row*9)]==num){
            return true;
        }
    }
return false;
}
void sudoku::fillbox(int row, int col){
    srand((unsigned)time(0));
    int n = rand()%9+1;
    for (int i{0}; i<3; ++i){
        for(int j{0}; j<3; ++j){
            while(usedinbox(n, row, col)){
                    n = rand()%9+1;
                }
            matrix[col+j+(row+i)*9] = n;
        }
    }
   
}
void sudoku::filldiag(){
    for(int i{0}; i<9; i+=3){
        fillbox(i, i);
    }
}
bool sudoku::fillremain(int row, int col){
  if((row == 9)&&(col<8)){
    row = 0;
    col += 1;
  }
  if((row==9)&&(col==8)){
    return true;
  }
  if(col<3){
    if(row<3){
      row = 3;
    }
  }else if(col<6){
    if(row==col/3*3){
      row+=3;
    }
  }else{
    if(row == 6){
      col +=1;
      row = 0;
      if(col > 8){
        return true;
      }
    }
   
 
  }
  for(int i{1}; i<10; ++i){
    if(!(((usedinbox(i, row - row%3, col-col%3))||(usedincol(i, col)||usedinrow(i, row))))){
      matrix[row*9+col] = i;
      if(fillremain(row+1, col)){
        return true;
      }
      matrix[row*9+col] = 0;
    }
   
 
  }  
  return false;  
}
int * sudoku::getMatrix(){
  return matrix;
}
void sudoku::generatesudoku(int k){
  filldiag();
  fillremain(0,3);
  removeval(k);
}
void sudoku::removeval(int k){
 
    for(int i{0}; i<k; ++i){
       
        int position = rand()% 81;
        while(matrix[position] == 0){
            position = rand()% 81;
        }
        matrix[position] = 0;
       
    }  
}
 
void sudoku::printsudoku(){
    for(int i{0}; i<81; ++i){
      if((i+1)%9==0){
        std::cout<<matrix[i]<<std::endl;
      }else{
        std::cout<<matrix[i];
      }
     
    }
}
bool sudoku::validrow(int row){
  int row_elem = 0;
  while (row_elem<9){
    for (int i{0}; i<9; ++i){
      if(row_elem>=i){
      }else{
        if(matrix[row_elem+9*row] == matrix[i+row*9]){
          return false;
        }
      }
    }
    ++row_elem;
  }
  return true;
}
bool sudoku::validcol(int col){
  int col_elem = 0;
  while (col_elem<9){
    for (int i{0}; i<9; ++i){
      if(col_elem>=i){
      }else{
        if(matrix[col_elem*9+col] == matrix[col+i*9]){
          return false;
        }
      }
    }
    ++col_elem;
  }
  return true;
}
bool sudoku::validbox(int row, int col){
  int n_row = row;
  int n_col = col;
  while(n_row<(row+3)){
    if (n_col==col+3){
      n_col = col;
      ++n_row;
    }
    for (int i{0}; i<3; ++i){
      for (int j{0}; j<3; ++j){
        if((n_row*9+n_col)>=((row+i)*9+(col+j))){
        }else{
          if(matrix[(n_row)*9+(n_col)] == matrix[row*9+col]){
            return false;
          }
        }
      }
    }
    ++n_col;
  }
  return true;
}
bool sudoku::validate(){
  for(int row{0}; row<9; ++row){
    if(!validrow(row)){
      return false;
    }
    for(int col{0}; col<9; ++col){
      if(!validcol(col)){
        return false;
      }
      if((col%3 == 0)&&(row%3 == 0)){
        if(!validbox(row, col)){
          return false;
        }
      }
    }
  }
  return true;
}
int sudoku::findunassigned(){
  for(int i{0}; i<81; ++i){
    if(matrix[i] == 0){
      return i;
    }
  }
  return 82;
}
bool sudoku::solve(int index){
  int row = index/9;
  int col = index%9;
  if(index>=81){
    return true;
  }
  for (int i{1}; i<10; ++i){
    if(!(((usedinbox(i, row - row%3, col-col%3))||(usedincol(i, col)||usedinrow(i, row))))){
      matrix[row*9+col] = i;
      if(solve(findunassigned())){
        return true;
      }
      matrix[row*9+col] = 0;
    }
  }
  return false;
}
void sudoku::enter(){
  std::cout<<"Please enter the row and column of the box you wish to make an entry in: "<<std::endl;
  int row{0};
  int col{0};
  std::cin>> row;
  std::cin>>col;
  if((col > 8)||(row>8)){
    std::cout<<"Not a valid coordinate please try again";
  }
  std::cout<<"Enter the number you want to enter: "<<std::endl;
  int num{0};
  std::cin>>num;
  matrix[row*9 + col] = num;
  if(findunassigned()==82){
    validate();
  }
}
void sudoku::operator = (sudoku b){
  for(int i{0}; i<81; ++i){
    this->getMatrix()[i] = b.getMatrix()[i];
  }
}
 
 
