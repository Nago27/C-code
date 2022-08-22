#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define MAX 21 //맵 크기값(기준 21)   

int board[MAX][MAX]={0,};

/*void ColorSet(int backGroundColor, int TextColor) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,(backGroundColor << 4) + TextColor)
}
typedef enum ColorKinds
{
	black,
	white,
	gray,
}ColorKinds;*/

void board_create() {
	int i,j;
	printf("0 1 2 3 4 5 6 7 8 9 1011121314151617181920\n"); // 맵 크기 변경시 크기에 맞게 변경해야함 
	for (i=0;i<MAX;i++) {			
			for (j=0;j<MAX;j++) {
				if(board[i][j] == 0) printf("□");
				else if(board[i][j] == 1) printf("◎");
				else if(board[i][j] == 2) printf("●");				
			}	
			printf("%d", i);
			printf("\n"); 
		} 
		
}

int overlap_error(int a, int *b){
	printf("중복입니다. 다시 입력해주세요.\n");
	scanf("%d %d", &a, b);
	return a;
		
}

int main() {
	
	int i,j,p,q;
	int turn=0;
	int x,y;
	//ColorKinds colorkinds;
	printf("====오목 게임을 시작합니다====.\n");
	printf("==== 규칙(필독) ====\n");
	printf("첫번째 숫자는 세로, 두번째 숫자는 가로입니다.\n"); 
	printf("첫번째 숫자를 입력하고 공백을 남기고 두번째 숫자를 입력해야 합니다.(ex. 1 5)\n");
	printf("3*3은 가능합니다.(3*3을 금지하는것은 아직 미구현)\n");
	Sleep(4000);
	system("cls");
	
	while(1) {
		board_create(); 
		
		if (turn == 0) {
			printf("\n흑돌의 차례입니다.\n");
			scanf("%d %d", &y, &x);
			while (1) {
				if(board[y][x]==0){
					break;
				}
				else {
					y=overlap_error(y,&x);
				}
			}			
			if(board[y][x]==0) {
				board[y][x]=1;
			}
			turn=1;
		}
		else if (turn == 1) {
			printf("\n백돌의 차례입니다(0 입력 금지).\n");
			scanf("%d %d", &y, &x);
			while (1) {
					if(board[y][x]==0){
						break;
					}
					else {
						y=overlap_error(y,&x);
					}
				}	
			if(board[y][x]==0) {
				board[y][x]=2;
			}
			turn=0;
		}
		
		for(p=0;p<MAX;p++) {
			for(q=0;q<MAX;q++){
				if(board[p][q] != 0){
					if(board[p][q]==board[p+1][q]&&board[p][q]==board[p+2][q]&&board[p][q]==board[p+3][q]&&board[p][q]==board[p+4][q]) //가로  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----흑돌 승리------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----백돌 승리------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p][q+1]&&board[p][q]==board[p][q+2]&&board[p][q]==board[p][q+3]&&board[p][q]==board[p][q+4]) //세로  
					{
						if (board[p][q] == 1){
							system("cls"); 
							printf("\n\n!!!!-----흑돌 승리------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----백돌 승리------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p+1][q+1]&&board[p][q]==board[p+2][q+2]&&board[p][q]==board[p+3][q+3]&&board[p][q]==board[p+4][q+4]) //오른쪽 대각선  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----흑돌 승리------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----백돌 승리------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p-1][q+1]&&board[p][q]==board[p-2][q+2]&&board[p][q]==board[p-3][q+3]&&board[p][q]==board[p-4][q+4]) //왼쪽 대각선  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----흑돌 승리------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----백돌 승리------!!!!\n\n");
							return 0;
						}	
					}
				}
			}
		}		
		system("cls");
	}	
	return 0;
}
