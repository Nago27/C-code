#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define MAX 21 //�� ũ�Ⱚ(���� 21)   

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
	printf("0 1 2 3 4 5 6 7 8 9 1011121314151617181920\n"); // �� ũ�� ����� ũ�⿡ �°� �����ؾ��� 
	for (i=0;i<MAX;i++) {			
			for (j=0;j<MAX;j++) {
				if(board[i][j] == 0) printf("��");
				else if(board[i][j] == 1) printf("��");
				else if(board[i][j] == 2) printf("��");				
			}	
			printf("%d", i);
			printf("\n"); 
		} 
		
}

int overlap_error(int a, int *b){
	printf("�ߺ��Դϴ�. �ٽ� �Է����ּ���.\n");
	scanf("%d %d", &a, b);
	return a;
		
}

int main() {
	
	int i,j,p,q;
	int turn=0;
	int x,y;
	//ColorKinds colorkinds;
	printf("====���� ������ �����մϴ�====.\n");
	printf("==== ��Ģ(�ʵ�) ====\n");
	printf("ù��° ���ڴ� ����, �ι�° ���ڴ� �����Դϴ�.\n"); 
	printf("ù��° ���ڸ� �Է��ϰ� ������ ����� �ι�° ���ڸ� �Է��ؾ� �մϴ�.(ex. 1 5)\n");
	printf("3*3�� �����մϴ�.(3*3�� �����ϴ°��� ���� �̱���)\n");
	Sleep(4000);
	system("cls");
	
	while(1) {
		board_create(); 
		
		if (turn == 0) {
			printf("\n�浹�� �����Դϴ�.\n");
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
			printf("\n�鵹�� �����Դϴ�(0 �Է� ����).\n");
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
					if(board[p][q]==board[p+1][q]&&board[p][q]==board[p+2][q]&&board[p][q]==board[p+3][q]&&board[p][q]==board[p+4][q]) //����  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----�浹 �¸�------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----�鵹 �¸�------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p][q+1]&&board[p][q]==board[p][q+2]&&board[p][q]==board[p][q+3]&&board[p][q]==board[p][q+4]) //����  
					{
						if (board[p][q] == 1){
							system("cls"); 
							printf("\n\n!!!!-----�浹 �¸�------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----�鵹 �¸�------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p+1][q+1]&&board[p][q]==board[p+2][q+2]&&board[p][q]==board[p+3][q+3]&&board[p][q]==board[p+4][q+4]) //������ �밢��  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----�浹 �¸�------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----�鵹 �¸�------!!!!\n\n");
							return 0;
						}	
					}
					else if(board[p][q]==board[p-1][q+1]&&board[p][q]==board[p-2][q+2]&&board[p][q]==board[p-3][q+3]&&board[p][q]==board[p-4][q+4]) //���� �밢��  
					{
						if (board[p][q] == 1){
							system("cls");
							printf("\n\n!!!!-----�浹 �¸�------!!!!\n\n");
							return 0;
						}	
						else if(board[p][q] == 2){
							system("cls");
							printf("\n\n!!!!-----�鵹 �¸�------!!!!\n\n");
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
