#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int main() 
{
	srand(time(NULL));
	int com, user;
	int sum, i, count=0;

	for (i = 0; i < 3; i++) {
		printf("����[0], �ָ�[1], ���ڱ�[2]:");
		scanf_s("%d", &user);

		com = rand() % 3;

		sum = com - user;

		if (sum == 0) {
			printf("�����ϴ�.\n");
			printf("��ǻ���� ����: %d\n", com);
		}
		else if (sum == -1 || sum == 2) {
			printf("�̰���ϴ�.\n");
			printf("��ǻ���� ����: %d\n", com);
			count++;
		}
		else {
			printf("�����ϴ�.\n");
			printf("��ǻ���� ����: %d\n", com);
		} 
	}

	printf("�̱�Ƚ��: %d", count);
	
	return 0;
}


