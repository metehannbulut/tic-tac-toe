#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

//pcor2p int. used for defining the it's against machine mode or 2p mode and specialize the functions about that. It set 1 for machine; set 0 for 2p.
void instructions();  //To show instructions if user doesn't know the game.
void winorlosecheck();  //Checks smb. won or lost the game.
void winboard();  //Shows win display.
void loseboard(); //Shows lose display.
void board(); //Shows current display.
void checkopponentsthirds(); //In against machine mode, this func. checks that can opponent make triple his 'X'.
void checkthirds();  //In against machine mode, this func. checks that can machine make triple its 'O'.
void againstmachine();  //Against machine mode's func.
void twoplayer(); //Two player modes func..


void hard(char mark[],int counter,int pcor2p,int random,int count){
    count++;
    if(mark[1]=='X' && mark[4]!='O' && count==1 || mark[5]=='X' && mark[4]!='O' || mark[3]=='X'&& mark[4]!='O' && count==1 || mark[7]=='X' && mark[4]!='O' && count==1){
        mark[4]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[4]='O';
    }
    else{
        medium(mark,counter,pcor2p,random);
    }
}
void medium(char mark[],int counter,int pcor2p,int random){
    srand(time(NULL));
    if (mark[1]=='X' && mark[3]=='X' && mark[0]!='O'){
        mark[0]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[0]='O';
    }
    else if(mark[1]=='X' && mark[5]=='X' && mark[2]!='O'){
        mark[2]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[2]='O';
    }
    else if(mark[3]=='X' && mark[7]=='X' && mark[6]!='O'){
        mark[6]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[6]='O';
    }
    else if(mark[5]=='X' && mark[7]=='X' && mark[8]!='O'){
        mark[8]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[8]='O';
    }
    else{
        easy(mark,counter,pcor2p,random);
    }
}
void easy(char mark[],int counter,int pcor2p,int random){
    for(int i=0;mark[random]!='O';i++){
        random=rand()%9;
        if(mark[random]!='X' && mark[random]!='O'){
            mark[random]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[random]='O';
        }
        else{}
    }
}
void instructions(){
    system("cls");
    system("color 06");
    for(int i=3;i>-1;i--){
        if(i==3){
            printf("\n  Instructions\n\n");
            sleep(1);
            printf("There is 3x3 table and numbered 1-9 with an order.");
            sleep(1);
            printf("\n To win, you have to complete triple 'X' side by side, up to down, or cross.\n");
            sleep(1);
            printf("  Choose a place with pressing 1-9 for places.\n");
            sleep(3);
            printf("    Good luck!!!\n\n");
            sleep(2);
        }
        sleep(1);
        if(i>0)
            printf("Game will start in %d...\n",i);

        if(i==0)
            printf("\n  Go!!!");
        sleep(1);
    }
}
void winorlosecheck(char mark[],int counter,int pcor2p){
    int shut=3; //Provides shut the program after the game finished
    if(mark[0]=='X' && mark[1]=='X' && mark[2]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[1]='\0';
            mark[2]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[0]='X';
            mark[1]='X';
            mark[2]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[2]=='X' && mark[4]=='X' && mark[6]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[2]='\0';
            mark[4]='\0';
            mark[6]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[2]='X';
            mark[4]='X';
            mark[6]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[0]=='X' && mark[4]=='X' && mark[8]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[4]='\0';
            mark[8]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[0]='X';
            mark[4]='X';
            mark[8]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[0]=='X' && mark[3]=='X' && mark[6]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[3]='\0';
            mark[6]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[0]='X';
            mark[3]='X';
            mark[6]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[3]=='X' && mark[4]=='X' && mark[5]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[3]='\0';
            mark[4]='\0';
            mark[5]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[3]='X';
            mark[4]='X';
            mark[5]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[6]=='X' && mark[7]=='X' && mark[8]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[6]='\0';
            mark[7]='\0';
            mark[8]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[6]='X';
            mark[7]='X';
            mark[8]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[2]=='X' && mark[5]=='X' && mark[8]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[2]='\0';
            mark[5]='\0';
            mark[8]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[2]='X';
            mark[5]='X';
            mark[8]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[1]=='X' && mark[4]=='X' && mark[7]=='X'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[1]='\0';
            mark[4]='\0';
            mark[7]='\0';
            system("color 0b");
            winboard(mark,counter,shut,pcor2p);
            mark[1]='X';
            mark[4]='X';
            mark[7]='X';
            sleep(1);
            system("color 0a");
            winboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[0]=='O' && mark[1]=='O' && mark[2]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[1]='\0';
            mark[2]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[0]='O';
            mark[1]='O';
            mark[2]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[0]=='O' && mark[4]=='O' && mark[8]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[4]='\0';
            mark[8]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[0]='O';
            mark[4]='O';
            mark[8]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[2]=='O' && mark[4]=='O' && mark[6]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[2]='\0';
            mark[4]='\0';
            mark[6]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[2]='O';
            mark[4]='O';
            mark[6]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[0]=='O' && mark[3]=='O' && mark[6]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[0]='\0';
            mark[3]='\0';
            mark[6]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[0]='O';
            mark[3]='O';
            mark[6]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[3]=='O' && mark[4]=='O' && mark[5]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[3]='\0';
            mark[4]='\0';
            mark[5]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[3]='O';
            mark[4]='O';
            mark[5]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[6]=='O' && mark[7]=='O' && mark[8]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[6]='\0';
            mark[7]='\0';
            mark[8]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[6]='O';
            mark[7]='O';
            mark[8]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[2]=='O' && mark[5]=='O' && mark[8]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[2]='\0';
            mark[5]='\0';
            mark[8]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[2]='O';
            mark[5]='O';
            mark[8]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
    if(mark[1]=='O' && mark[4]=='O' && mark[7]=='O'){
        while(1){
            shut--;
            if (shut==-2)
                exit(0);
            else{}
            mark[1]='\0';
            mark[4]='\0';
            mark[7]='\0';
            system("color 0d");
            loseboard(mark,counter,shut,pcor2p);
            mark[1]='O';
            mark[4]='O';
            mark[7]='O';
            sleep(1);
            system("color 04");
            loseboard(mark,counter,shut,pcor2p);
            sleep(1);
        }
    }
}
void winboard(char mark[],int turn,int shut,int pcor2p){
    turn=turn%2+1;
    system("cls");
    printf("\n          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[0],mark[1],mark[2]);
    printf("          ||       ||       \n");
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[3],mark[4],mark[5]);
    printf("          ||       ||       \n");
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[6],mark[7],mark[8]);
    printf("          ||       ||       \n");
    if(pcor2p==0)
        printf("\n\n      !!!PLAYER 1 WON!!!\n\n");
    else if(pcor2p==1)
        printf("\n\n      !!!YOU WON!!!\n\n");
    printf("Game will be shutted down in %d...\n\n\n",shut+1);
}
void loseboard(char mark[],int turn,int shut,int pcor2p){
    turn=turn%2+1;
    system("cls");
    printf("\n          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[0],mark[1],mark[2]);
    printf("          ||       ||       \n");
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[3],mark[4],mark[5]);
    printf("          ||       ||       \n");
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[6],mark[7],mark[8]);
    printf("          ||       ||       \n");
    if(pcor2p==0)
        printf("\n\n      !!!PLAYER 2 WON!!!\n\n");
    else if(pcor2p==1)
        printf("\n\n      !!!YOU LOST!!!\n\n");
    printf("Game will be shutted down in %d...\n\n\n",shut+1);
}
void board(char mark[],int turn,int pcor2p){
    system("color 07");
    turn=turn%2+1;
    system("cls");
    printf("\n          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[0],mark[1],mark[2]);
    printf("          ||       ||       \n");
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    if(pcor2p==0){
        printf("     %c    ||   %c   ||    %c           PLAYER 1: X\n",mark[3],mark[4],mark[5]);
        printf("          ||       ||                PLAYER 2: O\n");
    }
    else if(pcor2p==1){
        printf("     %c    ||   %c   ||    %c           YOU: X\n",mark[3],mark[4],mark[5]);
        printf("          ||       ||                PC: O\n");
    }
    printf(" =========||=======||=========\n");
    printf("          ||       ||       \n");
    printf("     %c    ||   %c   ||    %c   \n",mark[6],mark[7],mark[8]);
    printf("          ||       ||       \n");
    if(pcor2p==1)
        printf("\n      Your Turn!\n      Place:",turn);
    else if(pcor2p==0)
        printf("\n      Player %d's Turn!\n      Place:",turn);
}
void checkopponentsthirds(char mark[],int counter,int pcor2p,int difficulty){
    srand(time(NULL));
    int random=rand()%9;
    int count=0;
    if (mark[1]=='X' && mark[2]=='X' && mark[0]=='1' || mark[3]=='X' && mark[6]=='X' && mark[0]=='1' || mark[4]=='X' && mark[8]=='X' && mark[0]=='1'){
        mark[0]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[0]='O';
    }
        else if(mark[7]=='X' && mark[4]=='X' && mark[1]=='2' || mark[0]=='X' && mark[2]=='X' && mark[1]=='2'){
            mark[1]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[1]='O';
        }
        else if(mark[0]=='X' && mark[1]=='X' && mark[2]=='3' || mark[8]=='X' && mark[5]=='X' && mark[2]=='3' || mark[6]=='X' && mark[4]=='X' && mark[2]=='3'){
            mark[2]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[2]='O';
        }
        else if(mark[5]=='X' && mark[4]=='X' && mark[3]=='4' || mark[0]=='X' && mark[6]=='X' && mark[3]=='4'){
            mark[3]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[3]='O';
        }
        else if(mark[3]=='X' && mark[5]=='X' && mark[4]=='5' || mark[1]=='X' && mark[7]=='X' && mark[4]=='5' || mark[0]=='X' && mark[8]=='X' && mark[4]=='5' || mark[2]=='X' && mark[6]=='X' && mark[4]=='5'){
            mark[4]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[4]='O';
        }
        else if(mark[3]=='X' && mark[4]=='X' && mark[5]=='6' || mark[2]=='X' && mark[8]=='X' && mark[5]=='6'){
            mark[5]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[5]='O';
        }
        else if(mark[8]=='X' && mark[7]=='X' && mark[6]=='7' || mark[0]=='X' && mark[3]=='X' && mark[6]=='7' || mark[2]=='X' && mark[4]=='X' && mark[6]=='7'){
            mark[6]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[6]='O';
        }
        else if(mark[1]=='X' && mark[4]=='X' && mark[7]=='8' || mark[6]=='X' && mark[8]=='X' && mark[7]=='8'){
            mark[7]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[7]='O';
        }
        else if(mark[6]=='X' && mark[7]=='X' && mark[8]=='9' || mark[2]=='X' && mark[5]=='X' && mark[8]=='9' || mark[0]=='X' && mark[4]=='X' && mark[8]=='9'){
            mark[8]='\0';
            board(mark,counter,pcor2p);
            sleep(1);
            mark[8]='O';
        }
        else if(difficulty==3)
           hard(mark,counter,pcor2p,random,count);
        else if(difficulty==2)
            medium(mark,counter,pcor2p,random);
        else if(difficulty==1){
            easy(mark,counter,pcor2p,random);
        }
}
void checkthirds(char mark[],int counter,int pcor2p,int difficulty){
    if (mark[1]=='O' && mark[2]=='O' && mark[0]!='X' || mark[3]=='O' && mark[6]=='O' && mark[0]!='X' || mark[4]=='O' && mark[8]=='O' && mark[0]!='X'){
        mark[0]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[0]='O';
    }
    else if(mark[7]=='O' && mark[4]=='O' && mark[1]!='X' || mark[0]=='O' && mark[2]=='O' && mark[1]!='X'){
        mark[1]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[1]='O';
    }
    else if(mark[0]=='O' && mark[1]=='O' && mark[2]!='X' || mark[8]=='O' && mark[5]=='O' && mark[2]!='X' || mark[6]=='O' && mark[4]=='O' && mark[2]!='X'){
        mark[2]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[2]='O';
    }
    else if(mark[5]=='O' && mark[4]=='O' && mark[3]!='X' || mark[0]=='O' && mark[6]=='O' && mark[3]!='X'){
        mark[3]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[3]='O';
    }
    else if(mark[3]=='O' && mark[5]=='O' && mark[4]!='X' || mark[1]=='O' && mark[7]=='O' && mark[4]!='X' || mark[0]=='O' && mark[8]=='O' && mark[4]!='X' || mark[2]=='O' && mark[6]=='O' && mark[4]!='X'){
        mark[4]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[4]='O';
    }
    else if(mark[3]=='O' && mark[4]=='O' && mark[5]!='X' || mark[2]=='O' && mark[8]=='O' && mark[5]!='X'){
        mark[5]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[5]='O';
    }
    else if(mark[8]=='O' && mark[7]=='O' && mark[6]!='X' || mark[0]=='O' && mark[3]=='O' && mark[6]!='X' || mark[2]=='O' && mark[4]=='O' && mark[6]!='X'){
        mark[6]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[6]='O';
    }
    else if(mark[1]=='O' && mark[4]=='O' && mark[7]!='X' || mark[6]=='O' && mark[8]=='O' && mark[7]!='X'){
        mark[7]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[7]='O';
    }
    else if(mark[6]=='O' && mark[7]=='O' && mark[8]!='X' || mark[2]=='O' && mark[5]=='O' && mark[8]!='X' || mark[0]=='O' && mark[4]=='O' && mark[8]!='X'){
        mark[8]='\0';
        board(mark,counter,pcor2p);
        sleep(1);
        mark[8]='O';
    }
    else{
        checkopponentsthirds(mark,counter,pcor2p,difficulty);
    }
}
void twoplayer(){
    char mark[9]={'1','2','3','4','5','6','7','8','9'};
    int causeof2p=0;
    int counter=0;
    int decision;
    char choosen;
    int know;
    system("cls");
    printf("  If you know how to play Tic-Tac-Toe press \"1\"; else press \"0\".\n\n   ");
    scanf("%d",&know);
    if(know==1){
        system("cls");
        printf("\n  Game will start in a sec... Good luck!!!");
        sleep(1);
    }
    else if(know==0){
        instructions();
    }
    for(int i=0;i<9;i++){
        board(mark,counter,causeof2p);
        again:
        scanf("%d",&decision);
        if(mark[decision-1]=='O' || mark[decision-1]=='X'){
            printf("That place captured!!\nPlease choose another:");
            goto again;
        }
        else{}
        if(counter%2==0)
            mark[decision-1]='X';
        else{
            mark[decision-1]='O';
        }
        winorlosecheck(mark,counter,causeof2p);
        counter++;
    }
    board(mark,counter,causeof2p);
    printf("\n\n    !!IT'S DRAW!!\n\n\n");
    system("color 06");
}
void againstmachine(){
    char mark[9]={'1','2','3','4','5','6','7','8','9'};
    int counter=0;
    int decision,know,difficulty;
    char choosen;
    int causeofmachine=1;
    system("cls");
    printf(" Please choose the difficulty\n\n");
    printf("   Easy    [1]\n");
    printf("   Medium  [2]\n");
    printf("   Hard    [3]\n\nDecision: ");
    scanf("%d",&difficulty);
    system("cls");
    printf("  If you know how to play Tic-Tac-Toe press \"1\"; else press \"0\".\n\n   ");
    scanf("%d",&know);
    if(know==1){
        system("cls");
        printf("\n  Game will start in a sec... Good luck!!!");
        sleep(1);
    }
    else if(know==0){
        instructions();
    }
    for(int i=0;i<5;i++){
        board(mark,counter,causeofmachine);
        again:
        scanf("%d",&decision);

        if(mark[decision-1]=='O' || mark[decision-1]=='X'){
            printf("That place captured!!\nPlease choose another:");
            goto again;
        }
        else{}

        mark[decision-1]='X';
        checkthirds(mark,counter,causeofmachine,difficulty);
        winorlosecheck(mark,counter,causeofmachine);
        counter++;
    }
    board(mark,counter,causeofmachine);
    printf("\n\n    !!IT'S DRAW!!\n\n\n");
    system("color 06");
}
int main(){
    int start;
    char know;
    printf(" TicTacToe!\n\n   Against Machine   [1]\n   2 Player          [2]\n\nDecision: ");
    scanf("%d",&start);
    switch(start){
        case 1:
            againstmachine();
            break;
        case 2:
            twoplayer();
            break;
    }
    return 0;
}
