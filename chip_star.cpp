#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kuji();       //�Q�[���̐�U�����߂�֐�
int play(int);    //�Q�[���̓��e�����߂�֐�
int take(int);    //kikai��chipstar��H�ׂ�֐�

int main(void) {
	int ban, chip = 21;
	printf("chipstar��21������܂��B\n��U�A��U�͂����Ō��܂�܂��B\n");
	ban = kuji();
	printf("chip�̍Ō�̈ꖇ��H�ׂ��ق��̕����ł�\n\n");
	while (chip > 0) {
		//�Q�[�������݂ɍs���܂��B//
		if (ban == 0) {
			printf("A�̃^�[��\n\n");
			chip = play(chip);
			ban++;
		}
		else if (ban == 1) {
			printf("kikai�̃^�[��\n\n");
			chip = take(chip);
			ban--;
		}
		else {
			printf("�G���[\n");
			break;
		}

	}


	//���Ҕ��\//
	if (ban == 0)printf("A�̏����ł�\n");
	else if (ban == 1)printf("kikai�̏����ł�\n");

	return 0;
}



/*���������֐�*/
int kuji(void) {
	int val;
	srand((unsigned int)time(0))
	rand(); rand(); rand(); rand(); rand();  //5�񂭂炢���Ƃ����ƃ����_���ɂȂ�
	val = rand() % 2;   //0�`1�̗��������B
	return val;
}



/*�Q�[���̓��e�֐�*/
int play(int chip) {
	int eat;
	printf("chip�̎c�薇��%d��\n�����H�ׂ܂����H(1�`3�̐�������͂��ĉ�����)\n", chip);
	scanf("%d", &eat);

	//�����Ɩ�������ĖႦ�Ȃ��Ƃ���//
	if (0 >= eat || eat > 3) {
		while (1) {
			scanf("%*[^\n]%*c");
			printf("�������\n");
			scanf("%d", &eat);
			if (0 < eat && eat <= 3)break;
		}
	}

	chip -= eat;
	if (chip < 1)printf("chip��0��\n");

	//����Ɏc��������������//
	return chip;
}



//�@�B���H�ׂ����֐�//
int take(int chip) {
	int i, z, eat = 0;

	//z�͐H�ׂ�����//
	for (i = 1; eat < chip; i++) {
		eat = 4 * i + 1;
	}
	z = (4 - (eat - chip));

	//human�������������ɂ₯�ɂȂ�@�B�̂��߂̗���//
	if (z == 4 || z == 0) {
		srand((unsigned int)time(0));
		rand(); rand(); rand(); rand(); rand();
		z = rand() % 3 + 1;  //1�`3�̗��������
	}

	printf("%d ���H�ׂ�\n", z);
	chip -= z;
	//�H�׎c���������Ԃ��Ă�//
	return chip;
}