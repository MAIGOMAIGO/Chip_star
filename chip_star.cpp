#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kuji();       //ゲームの先攻を決める関数
int play(int);    //ゲームの内容を決める関数
int take(int);    //kikaiがchipstarを食べる関数

int main(void) {
	int ban, chip = 21;
	printf("chipstarが21枚あります。\n先攻、後攻はくじで決まります。\n");
	ban = kuji();
	printf("chipの最後の一枚を食べたほうの負けです\n\n");
	while (chip > 0) {
		//ゲームを交互に行います。//
		if (ban == 0) {
			printf("Aのターン\n\n");
			chip = play(chip);
			ban++;
		}
		else if (ban == 1) {
			printf("kikaiのターン\n\n");
			chip = take(chip);
			ban--;
		}
		else {
			printf("エラー\n");
			break;
		}

	}


	//勝者発表//
	if (ban == 0)printf("Aの勝利です\n");
	else if (ban == 1)printf("kikaiの勝利です\n");

	return 0;
}



/*くじ引き関数*/
int kuji(void) {
	int val;
	srand((unsigned int)time(0))
	rand(); rand(); rand(); rand(); rand();  //5回くらいやるとちゃんとランダムになる
	val = rand() % 2;   //0～1の乱数を作る。
	return val;
}



/*ゲームの内容関数*/
int play(int chip) {
	int eat;
	printf("chipの残り枚数%d枚\n何枚食べますか？(1～3の整数を入力して下さい)\n", chip);
	scanf("%d", &eat);

	//ちゃんと枚数入れて貰えないときの//
	if (0 >= eat || eat > 3) {
		while (1) {
			scanf("%*[^\n]%*c");
			printf("もう一回\n");
			scanf("%d", &eat);
			if (0 < eat && eat <= 3)break;
		}
	}

	chip -= eat;
	if (chip < 1)printf("chipは0枚\n");

	//相手に残した枚数あげた//
	return chip;
}



//機械が食べたい関数//
int take(int chip) {
	int i, z, eat = 0;

	//zは食べた枚数//
	for (i = 1; eat < chip; i++) {
		eat = 4 * i + 1;
	}
	z = (4 - (eat - chip));

	//humanが強かった時にやけになる機械のための乱数//
	if (z == 4 || z == 0) {
		srand((unsigned int)time(0));
		rand(); rand(); rand(); rand(); rand();
		z = rand() % 3 + 1;  //1～3の乱数作った
	}

	printf("%d 枚食べた\n", z);
	chip -= z;
	//食べ残した枚数返してる//
	return chip;
}