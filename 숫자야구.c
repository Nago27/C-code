#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	int comball[3];
	int i,j;
	int temp;
	int userball[3];
	int count = 1;
	int strike, ball;
	
	srand((unsigned)time(NULL));
	
	for (i=0;i<3;i++) {
		temp = (rand() % 9) + 1;
		comball[i] = temp;
		for (j=0;j < i; j++) {
			if (temp == comball[j] && i != j) i--;
	
		}
		
	}
	while (1) {
		printf("[%dȸ�� ���ھ߱�]\n", count); 
		while (1) {
			printf("1���� 9���� ���ϴ� ���� 3����  �Է����ּ���(�Է½� ���ڰ� ����):");
			scanf("%d %d %d", &userball[0], &userball[1], &userball[2]);
			if(userball[0] < 1 || userball[0] > 9 || userball[1] < 1 || userball[1] > 9 || userball[2] < 1 || userball[2] > 9) {
				printf("���� ���� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
				continue;
			}			
			else if(userball[0] == userball[1] || userball[0] == userball[2] || userball[1] == userball[2]) {
				printf("�ߺ��� ���ڸ� �Է��Ͻø� �ȵ˴ϴ�.\n");
				continue;
			}
			break;
		}
		
		ball = 0; strike=0;
		for (i=0;i<3;i++) {
			for (j=0;j<3;j++) {
				if (comball[i] == userball[j]) {
					if (i == j) strike++;
					else ball++;
				}		
			} 
		}
		printf("[���]��Ʈ����ũ : %d, �� : %d\n\n", strike, ball); 
		
		if (strike == 3) {
			printf("*****�¸��Ͽ����ϴ�!!!*****\n");
			break;
		}
		else if (count == 10) {
			printf("***** �й��߽��ϴ�.. ���� : %d %d %d *****\n\n", comball[0], comball[1], comball[2]); 
			break;
		}
		 count++;
	}
	return 0;
}
