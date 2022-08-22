#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() 
{
	srand(time(NULL));
	int com, user;
	int sum, i, count=0;

	for (i = 0; i < 3; i++) {
		printf("가위[0], 주먹[1], 보자기[2]:");
		scanf_s("%d", &user);

		com = rand() % 3;

		sum = com - user;

		if (sum == 0) {
			printf("비겼습니다.\n");
			printf("컴퓨터의 숫자: %d\n", com);
		}
		else if (sum == -1 || sum == 2) {
			printf("이겼습니다.\n");
			printf("컴퓨터의 숫자: %d\n", com);
			count++;
		}
		else {
			printf("졌습니다.\n");
			printf("컴퓨터의 숫자: %d\n", com);
		} 
	}

	printf("이긴횟수: %d", count);
	
	return 0;
}


