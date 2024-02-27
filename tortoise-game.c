#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h> // for ceil function because mulberry and pit should be at least once in the game.

void  printBoard(int n){
	srand(time(NULL));
	char action,direction; 
    char board[n][n];
    int tr,tc,energy=20,move=1,i,j,tortoise=1; // tr and tc for saving tortoise's raw and column information.
       printf("Time = %d   Energy = %d\n",move,energy);
    for(i=0;i<n;i++){   // declared all board with '_'
		for(j=0;j<n;j++)
			board[i][j] = '_';
	}
	int mulberry=ceil(n*n*0.15); // for how many mulberries are going to be in the game according to board size.
    int pit=ceil(n*n*0.05);     // for how many pits are going to be in the game according to board size.

    for(i=0;i<mulberry;i++){ // declaration of mulberries randomly
	int x=rand()%n;
	int y=rand()%n;
    if(board[x][y]=='*'){ // for protecting mulberry count if we get same location from rand.
    	i--;
	}
	else{
	board[x][y]='*';
    } 
	}
    for(i=0;i<pit;i++){ // decleration of pits randomly.
	int x=rand()%n;
	int y=rand()%n;
	if(board[x][y]=='*' || board[x][y]=='O'){ // for protecting accurate pit count. 
		i--;
	}
	else{
	board[x][y]='O';
    } 
    }
	int count=1;
	while(count==1){ // decleration of tortoise randomly.
	    int x=rand()%n;
	    int y=rand()%n;
	    if(board[x][y]=='_'){
	       board[x][y]='@';
	       tr = x;
	       tc = y;
	       count=0;
        }
	}
	for(i=0;i<n;i++){ // printing the board
		for(j=0;j<n;j++)
		    printf("%c ",board[i][j]);
		printf("\n");
	}
		while(energy>0 && mulberry>0 && tortoise>0 ){
		printf("\nPlease enter an action:");
		scanf(" %c %c",&action,&direction);
		// START OF CODES OF MOVE ACTION
	    if((action=='m'||action=='M') && (direction=='n'|| direction=='N') && board[tr-1][tc]!='*' && tr!=0 && board[tr-1][tc]!='O'){
	        energy--;
	        move++;
            board[tr-1][tc]='@';
            board[tr][tc]='_';
            tr=tr-1;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='e'|| direction=='E') && board[tr][tc+1]!='*' && tc!=n-1 && board[tr][tc+1]!='O'){
	        energy--;
	        move++;
            board[tr][tc+1]='@';
            board[tr][tc]='_';
            tc=tc+1;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='w'|| direction=='W') && board[tr][tc-1]!='*' && tc!=0 && board[tr][tc-1]!='O'){
	        energy--;
	        move++;
            board[tr][tc-1]='@';
            board[tr][tc]='_';
            tc=tc-1;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='s'||direction=='S') && board[tr+1][tc]!='*' && tr!=n-1 && board[tr+1][tc]!='O'){
	        energy--;
	        move++;
            board[tr+1][tc]='@';
            board[tr][tc]='_';
            tr=tr+1;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }   //FINISH OF CODES OF MOVE ACTION
	        //START FOR THE PIT SITUATIONS
	    else if((action=='m'||action=='M') && (direction=='e'||direction=='E') && board[tr][tc+1]=='O' && tc!=n-1){
	        energy--;
	        move++;
	        tortoise--;
            board[tr][tc]='_';
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='w'||direction=='W') && board[tr][tc-1]=='O' && tc!=0){
	        energy--;
	        move++;
	        tortoise--;
            board[tr][tc]='_';
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='n'||direction=='N') && board[tr-1][tc]=='O' && tr!=0){
	        energy--;
	        move++;
	        tortoise--;
            board[tr][tc]='_';
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='m'||action=='M') && (direction=='s'||direction=='S') && board[tr+1][tc]=='O' && tr!=n-1){
	        energy--;
	        move++;
	        tortoise--;
            board[tr][tc]='_';
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    //END FOR THE PIT SITUATIONS
	    //START OF CODES OF EAT ACTION
	    else if((action=='e'||action=='E') && (direction=='s'||direction=='S') && board[tr+1][tc]=='*'){
	        energy+=10;
            board[tr+1][tc]='_';
            mulberry--;
            move++;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
        }
	    else if((action=='e'||action=='E') && (direction=='n'||direction=='N') && board[tr-1][tc]=='*'){
	        energy+=10;
            board[tr-1][tc]='_';
            mulberry--;
            move++;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='e'||action=='E') && (direction=='e'||direction=='E') && board[tr][tc+1]=='*' && tc!=n-1){
	        energy+=10;
            board[tr][tc+1]='_';
            mulberry--;
            move++;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
	    }
	    else if((action=='e'||action=='E') && (direction=='w'||direction=='W') && board[tr][tc-1]=='*' && tc!=0){
	        energy+=10;
            board[tr][tc-1]='_';
            mulberry--;
            move++;
            printf("\nTime = %d   Energy = %d\n",move,energy);
        for(i=0;i<n;i++){
    	   for(j=0;j<n;j++)
              printf("%c ",board[i][j]);
              printf("\n");
        }
        }   // FINISH OF CODES OF EAT ACTION
        else{
            printf("This is invalid action!");
	    }}
	    if(mulberry==0)
	       printf("\n\nCONGRATULATIONS, YOU WON !!! :)))");
	       else{
	       	   printf("\n\nYOU LOST :((\n");
	       	   printf("THE GAME IS OVER.");
		   }
	       
        }
int main(void){
	int n;
	printf("Welcome to the Tortoise Game.\n");
	printf("Please specify the size of the board:");
	scanf("%d",&n);
	printf("\n\n");
	printBoard(n);

	}
