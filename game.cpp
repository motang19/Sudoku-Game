#include <iostream>
#include "gamemech.cpp"
bool game();
sudoku startgame();
int main(){
    game();
}

bool game(){
    sudoku a = startgame();
    game b = a;
    while(true){
        char curaction{'\0'};
        std::cout<<"Enter the action, (\'E\') to enter numbers, (\'V\') to validate solution, (\'S\') to auto-complete, (\'R\') go back to start"<<std::endl;
        switch(curaction){
            case 'E':
            {
                b.enter()
                break;
            }
            case 'V':
            {
                if(b.validate()){
                    std::cout<< "Congratulations you completed the sudoku"
                }else{
                    std::cout<<"Something is not right please try again"
                }
                break;
            }
            case 'S':
            {
                b.solve(blksize_t.findunassigned());
                break;
            }
            case 'R':
            {
                b = startgame();
                break;
            }
        }
        b.printsudoku();  

    }
}
sudoku startgame(){
    char mode{'\0'};
    sudoku a;
    std::cout<< "Enter (\'H\') for hard mode, (\'M\') for medium mode or (\'E\') for easy mode"<<std::endl;
    std::cin>>mode;
    switch(mode){
        case 'H' :
        {
            a.generatesudoku(54);
            return a;
        }
        case 'M':
        {
            a.generatesudoku(44);
            return a;
        }
        case 'E':
        {
            a.generatesudoku(34);
            return a;
        }
        default :
        {
            std::cout<<mode<<" is not a valid mode please retry"<<std::endl;
            startgame();
        }
    }
}