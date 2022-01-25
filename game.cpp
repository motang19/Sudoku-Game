#include <iostream>

#include <iostream>
#include "./gamemech.cpp"
int main();
bool prog();
char getAction();
sudoku startgame();
int main(){
    prog();
}
 
bool prog(){
    sudoku a = startgame();
    char curaction{'\0'};
    while(curaction!='Q'){
        switch(curaction){
            case 'E':
            {
                a.enter();
                break;
            }
            case 'V':
            {
                if(a.validate()){
                    std::cout<< "Congratulations you completed the sudoku";
                }else{
                    std::cout<<"Something is not right please try again";
                }
                break;

            }
            case 'S':
            {
                a.solve(a.findunassigned());
                break;
            }
            case 'R':
            {
                a = startgame();
                break;
            }
        }
        a.printsudoku();
        if(a.validate()){
            std::cout<< "you have won congratulations";
            a.printsudoku();
            std::cout<<"restarting board";
            a = startgame();
        }
        curaction = getAction();
    }
    return true;
}
char getAction(){
    char action {0};

    std::cout<<"Enter the action, (\'E\') to enter numbers, (\'V\') to validate solution, (\'S\') to auto-complete, (\'R\') go back to start, (\'Q\') to quit"<<std::endl;
    std::cin>>action;

    return action;
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
            break;
        }
        case 'M':
        {
            a.generatesudoku(44);
            break;
        }
        case 'E':
        {
            a.generatesudoku(34);
            break;
        }
    }
    return a;

}
