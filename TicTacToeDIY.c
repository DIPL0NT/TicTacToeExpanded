#include <stdio.h>

typedef struct{
	int b[17][17];
	int rows;
	int columns;
	int winCon;
	int turn;
	int turnPlayer;
	int lastMove[3];
	int gameOver;
} tipoBoard;

void resetBoard(tipoBoard * puntBoard){
	int i,j;
	
	for (i=0;i<=(*puntBoard).rows;i++){
		for (j=0;j<=(*puntBoard).columns;j++){
			(*puntBoard).b[i][j] = 0;
		}
	}
	//printf("\nBoard reset %d", board.b[1][1]);
}

int sign(int x){
	if (x==0)
		return 0;
	else if (x>0)
		return 1;
	else if (x<0)
		return -1;
}

void gameOverCheck2(tipoBoard * puntBoard){
	
	int s, i, j, a, b, x, y, lfWin;
	s=(*puntBoard).lastMove[0];
	i=(*puntBoard).lastMove[1];
	j=(*puntBoard).lastMove[2];
	int sX, sY;
	
	
	for (a=-1;a<2;a++){
		for (b=-1;b<2;b++){
			
			if (a!=0 || b!=0){
				//printf("\n checking for a= %d e b= %d", a, b);
				
				x=a;
				y=b;
				sX=sign(x);
				sY=sign(y);
				lfWin= (*puntBoard).winCon -1 ;
				while ( (*puntBoard).b[i+x][j+y]==s ){
					lfWin--;
					x += 1*sX;
					y += 1*sY;
				}
				x=-sX;
				y=-sY;
				sX=sign(x);
				sY=sign(y);
				while ( (*puntBoard).b[i+x][j+y]==s ){
					lfWin--;
					x += 1*sX;
					y += 1*sY;
				}
				
				if (lfWin<=0)
					(*puntBoard).gameOver=1;
				
			}
		
		}
	}
	
}

void playTurn(tipoBoard * puntBoard){
	(*puntBoard).turn++;
	
	int i=-1, j=-1; //inizializzate invalide in modo che se l'utente sbaglia a inserire gli venga chiesto di nuovo
	
	do{
		//fflush(stdin);
		printf("\n Player %d , type the coordinates of your next move: ", (*puntBoard).turnPlayer);
		scanf("%d%d", &i, &j);
	} while ( i<1 || i>(*puntBoard).rows || j<1 || j>(*puntBoard).columns || (*puntBoard).b[i][j]!=0 ); //per checkare che la mossa sia valida
	
	
	//if ( !( (*puntBoard).b[i][j]!=0 || i<1 || i>(*puntBoard).rows || j<1 || j>(*puntBoard).columns ) ){
		(*puntBoard).b[i][j] = (*puntBoard).turnPlayer;
		(*puntBoard).lastMove[0] = (*puntBoard).turnPlayer;
		(*puntBoard).lastMove[1] = i;
		(*puntBoard).lastMove[2] = j;
		
		//gameOverCheckAll(puntBoard);
		gameOverCheck2(puntBoard);
		
		if (!(*puntBoard).gameOver){
			if ((*puntBoard).turnPlayer == 1)
				(*puntBoard).turnPlayer = 2;
			else if ((*puntBoard).turnPlayer == 2)
				(*puntBoard).turnPlayer = 1;
		}
	//}
		
}

void drawBoard(tipoBoard board){
	
	int i, j;
	
	printf("\n");
	printf("     |");
	for (j=1;j<=board.columns;j++){
		printf(" %2d |", j);
	}
	printf("\n ");
	for (j=0;j<=board.columns;j++){
		printf("____|");
	}
	
	for (i=1;i<=board.rows;i++){
		printf("\n");
		printf("  %2d |", i);
		for (j=1;j<=board.columns;j++){
			if (board.b[i][j]==1)
				printf("  X |");
			else if (board.b[i][j]==2)
				printf("  O |");
			else
				printf("    |");
		}
		printf("\n ");
		for (j=0;j<=board.columns;j++){
			printf("____|");
		}
	}
	
	printf("\n");
	
}

void checkDraw2(tipoBoard * puntBoard){
	if ( (*puntBoard).gameOver==0 && (*puntBoard).turn==(*puntBoard).rows * (*puntBoard).columns +1)
		(*puntBoard).gameOver=2;
}




int main(){
	
	int gameActive=1, i, j;
	char bin;
	
	while (gameActive){
		
		int customRows, customColumns, customWinCon;
		
		printf("\n Welcome to TicTacToe expanded\n");
		do{
			printf("\n Choose the number of rows of the board (2<n<16) : ");
			scanf("%d", &customRows);
		} while (customRows<3 || customRows>15);
		do{
			printf(" Choose the number of columns of the board (2<n<16) : ");
			scanf("%d", &customColumns);
		} while (customColumns<3 || customColumns>15);
		do{
			printf(" Choose the number of the win condition (2<n<16) : ");
			scanf("%d", &customWinCon);
		} while (customRows<3 || customRows>15);
	
	
		tipoBoard board1;
		board1.rows=customRows;
		board1.columns=customColumns;
		board1.winCon=customWinCon;
		board1.turn=1;
		board1.turnPlayer=1;
		board1.gameOver=0;
		
		tipoBoard * puntBoard1=&board1;
		
		
		resetBoard(puntBoard1);
		
		
		while (!board1.gameOver){
			
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printf(" Turn %d\n", board1.turn);
			drawBoard(board1);
			playTurn(puntBoard1);
			checkDraw2(puntBoard1);
			
		}
		
		if (board1.gameOver==1){
			printf("\n");
			printf("\n Player %d won!\n*", board1.turnPlayer);
			for (j=0;j<=board1.columns;j++)
				printf("*****");
				printf("*");
			drawBoard(board1);
			printf("*");
			for (j=0;j<=board1.columns;j++)
				printf("*****");
				printf("*");
		}
		if (board1.gameOver==2){
			printf("\n");
			printf("\n The game ended in a draw!\n*");
			for (j=0;j<=board1.columns;j++)
				printf("*****");
				printf("*");
			drawBoard(board1);
			printf("*");
			for (j=0;j<=board1.columns;j++)
				printf("*****");
				printf("*");
		}
		
		do{
			fflush(stdin);
			printf("\n\nDo you want to play again? [y/n] : ");
			scanf("%c", &bin);
		} while (bin!='y'&&bin!='Y'&&bin!='n'&&bin!='N');
		
		if (bin=='n'||bin=='N')
			gameActive=0;
		else if (bin=='y'||bin=='Y')
			resetBoard(puntBoard1);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	
	printf("\nPress any key to close: ");
	scanf("%c", &bin);
	printf("\n");
	
	return 0;
}

