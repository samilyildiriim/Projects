#include <stdio.h>
void enterance(int *t, int x[10][10]);
void currentState(int x[10][10]);
void leave(int *t, int x[10][10]);

int main(){
    int ticket,command,park[10][10],i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            if(i>=j || i<=j)
                park[i][j]=-1;
    }
    printf("Welcome\nPlease input your command:\n");
    scanf("%d",&command);
    while(command<0 || command>3){
        printf("Incorrect command, new command needed. Please input your your command:\n");
        scanf("%d", &command);
    }
    do{
        if(command==1)
            currentState(park);
        if(command==2)
            enterance(&ticket, park);
        if(command==3)
            leave(&ticket, park);
        if(command>(0) && command<4){
            printf("Please input your command:\n");
            scanf("%d",&command);
        }
        else{
            printf("Incorrect command, new command needed. Please input your your command:\n");
            scanf("%d", &command);
        }
            
    }while((command!=(0)) && (command!= (1) || command!=2 || command!=3));
    if(command==0){
        printf("Goodbye. Here is the final Parking Lot:");
        for(i=0;i<10;i++){
            printf("\n");
            for(j=0;j<10;j++){
                printf("%d\t", park[i][j]);
            }
        }
    }
    
    printf("\n\n\n");
    
    return 0;
}

void enterance(int *t, int x[10][10]){
    int i,j,no;
    
    printf("A new car is entering. Please input a ticket number:\n");
    scanf("%d", &no);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(x[i][j] == -1){
                x[i][j] = no;
                if(x[i][j+1] == -1)
                    break;
            }
        }
        if(x[i][j+1]==-1)
           break;
    }
    *t = no;
}

void currentState(int x[10][10]){
    int i,j;
    
    printf("Parking Lot:\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
}

void leave(int *t, int x[10][10]){
    int i,j,no;
    
    printf("A car is leaving. Please input the ticket numbber of the leaving car.\n");
    scanf("%d", &no);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(x[i][j] == no)
                x[i][j] = -1;
        }
    }
    *t = no;
}