/*
1 2 3
4   5
6 7 8
*/

/*
int checkNextPos(tipoBoard *puntBoard, int * puntI, int * puntJ, int * puntA, int * puntB){
	
	int p=(*puntBoard).lastMove[0], i=*puntI , j=*puntJ ;
	int same;
	
	if (*puntA==*puntB && *puntA<0){
		if ((*puntBoard).b[i+*puntA-1][j+*puntB-1]==p){
			same=1;
			*puntA += -1;
			*puntB += -1;
		}
		else
			same=0;
	}
	else if (*puntA<0 && *puntB==0){
		if ((*puntBoard).b[i+*puntA-1][j+*puntB+0]==p){
			same=1;
			*puntA += -1;
			*puntB += 0;
		}
		else
			same=0;
	}
	else if (*puntA<0 && *puntB>0){
		if ((*puntBoard).b[i+*puntA-1][j+*puntB+1]==p){
			same=1;
			*puntA += -1;
			*puntB += +1;
		}
		else
			same=0;
	}
	else if (*puntA==0 && *puntB<0){
		if ((*puntBoard).b[i+*puntA+0][j+*puntB-1]==p){
			same=1;
			*puntA += 0;
			*puntB += -1;
		}
		else
			same=0;
	}
	else if (*puntA==0 && *puntB>0){
		if ((*puntBoard).b[i+*puntA+0][j+*puntB+1]==p){
			same=1;
			*puntA += 0;
			*puntB += +1;
		}
		else
			same=0;
	}
	else if (*puntA>0 && *puntB<0){
		if ((*puntBoard).b[i+*puntA+1][j+*puntB-1]==p){
			same=1;
			*puntA += +1;
			*puntB += -1;
		}
		else
			same=0;
	}
	if (*puntA>0 && *puntB==0){
		if ((*puntBoard).b[i+*puntA+1][j+*puntB+0]==p){
			same=1;
			*puntA += +1;
			*puntB += 0;
		}
		else
			same=0;
	}
	else if (*puntA>0 && *puntB>0){
		if ((*puntBoard).b[i+*puntA+1][j+*puntB+1]==p){
			same=1;
			*puntA += +1;
			*puntB += +1;
		}
		else
			same=0;
	}
	
	return same; //0 o 1
}
*/


/* doesnt detect the win if the last move completed a tris by putting symbol between 2 already there
void gameOverCheck(tipoBoard * puntBoard){
	
	int p=(*puntBoard).lastMove[0] , i=(*puntBoard).lastMove[1] , j=(*puntBoard).lastMove[2] ;
	int a, b, posToCheck=(*puntBoard).winCon -2, same;
	
	for (a=-1;a<=1 && !(*puntBoard).gameOver;a++){
		for (b=-1;b<=1 && !(*puntBoard).gameOver;b++){
			if (a!=0 || b!=0){
				if ( (*puntBoard).b[i+a][j+b] == p ){
					while (posToCheck && same && !(*puntBoard).gameOver){
						same=checkNextPos(puntBoard, &i, &j, &a, &b);
						posToCheck--;
					}
					if (same==1)
						(*puntBoard).gameOver=1;
				}
			}
		}
	}

}
*/

/*
void gameOverCheckAll(tipoBoard * puntBoard){
		
	int p=(*puntBoard).lastMove[0] , i, j;
	int a, b, posToCheck, same, tempA, tempB;
	
	for (i=1;i<=(*puntBoard).rows && !(*puntBoard).gameOver;i++){
		for (j=1;j<=(*puntBoard).columns && !(*puntBoard).gameOver;j++){
			
			printf("\nCheck del punto %d %d", i, j);
			
			if ((*puntBoard).b[i][j] == p && !(*puntBoard).gameOver){
				for (a=-1;a<=1 && !(*puntBoard).gameOver;a++){
					for (b=-1;b<=1 && !(*puntBoard).gameOver;b++){
						
						printf("\n\tCheck del punto %d %d", i+a, j+b);
						
						tempA=a;
						tempB=b;
						if (a!=0 || b!=0){
							if ( (*puntBoard).b[i+a][j+b] == p ){
								printf("  giusto simbolo");
								posToCheck=(*puntBoard).winCon -2;
								same=1;
								while (posToCheck && same && !(*puntBoard).gameOver){
									printf("\n\t\tcontrollo per a %d b %d", a, b);
									same=checkNextPos(puntBoard, &i, &j, &a, &b);
									printf(" same = %d", same);
									posToCheck--;
								}
								if (same==1)
									(*puntBoard).gameOver=1;
							}
						}
						a=tempA;
						b=tempB;
					}
				}
			}
			
		}
	}
	
}
*/

/*
void checkDraw(tipoBoard * puntBoard){
	int draw=1;
	int i, j;
	for (i=1;i<=(*puntBoard).rows;i++){
		for (j=1;j<=(*puntBoard).columns;j++){
			if ((*puntBoard).b[i][j]==0)
				draw=0;
		}
	}
	
	if (draw==1 && (*puntBoard).gameOver!=1){
		(*puntBoard).gameOver=2;
	}
}
*/