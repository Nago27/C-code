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
		printf("[%d회차 숫자야구]\n", count); 
		while (1) {
			printf("1부터 9까지 원하는 숫자 3개를  입력해주세요(입력시 숫자간 공백):");
			scanf("%d %d %d", &userball[0], &userball[1], &userball[2]);
			if(userball[0] < 1 || userball[0] > 9 || userball[1] < 1 || userball[1] > 9 || userball[2] < 1 || userball[2] > 9) {
				printf("범위 내외 숫자를 입력하시면 안됩니다.\n");
				continue;
			}			
			else if(userball[0] == userball[1] || userball[0] == userball[2] || userball[1] == userball[2]) {
				printf("중복된 숫자를 입력하시면 안됩니다.\n");
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
		printf("[결과]스트라이크 : %d, 볼 : %d\n\n", strike, ball); 
		
		if (strike == 3) {
			printf("*****승리하였습니다!!!*****\n");
			break;
		}
		else if (count == 10) {
			printf("***** 패배했습니다.. 정답 : %d %d %d *****\n\n", comball[0], comball[1], comball[2]); 
			break;
		}
		 count++;
	}
	return 0;
}
