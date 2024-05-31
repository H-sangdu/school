#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define LEN_MIN 15 //기차 길이
#define LEN_MAX 50
#define STM_MIN 0 //마동석 체력
#define STM_MAX 5
#define PROB_MIN 10
#define PROB_MAX 90
#define AGGRO_MIN 0 //어그로 범위
#define AGGRO_MAX 5

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

//좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ATK_PULL 2

//초기 입력값 다시 받기
int insert_tl(int tl) {
	int i = 1;
	while (i != 0)
	{
		printf("train length(15~50)>>");
		scanf_s("%d", &tl);
		if (tl >= 15 && tl <= 50)
		{
			i = 0;
		}
	}
	return tl;

}

int insert_ma(int ms) {
	int i = 1;
	while (i != 0)
	{
		printf("madongseok stamina(0~5)>>");
		scanf_s("%d", &ms);
		if (ms >= 0 && ms <= 5)
		{
			i = 0;
		}
	}

	return ms;
}
int insert_pp(int pp) {
	int i = 1;
	while (i != 0)
	{
		printf("percentile probability \'p\'(10~90)>>");
		scanf_s("%d", &pp);
		if (pp >= 10 && pp <= 90)
		{
			i = 0;
		}
	}
	return pp;
}

int start_scene() {
	printf("**********************************************\n");
	printf("----------------------------------------------\n");
	printf("llllllllllllllllㅁㅁㅁ시작ㅁㅁㅁlllllllllllllll\n");
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("                Pusan haeng\n");
	return 0;
}
int initial_pos(int tl) {
	int i = 0;
	int c_position, p = 0, z_position, z = 0, z_turn = 0;
	for (i = 0; i < tl; i++)
	{
		printf("#");
	}
	printf("\n#");
	for (i = 0; i < tl - 7; i++)
	{
		printf(" ");
	}
	printf("C");
	printf("  ");
	printf("Z");
	printf("M");
	printf("#\n");
	c_position = tl - 6;
	z_position = tl - 3;
	for (i = 0; i < tl; i++)
	{
		printf("#");
	}
	return 0;
}
//사람 움직임
char board[LEN_MAX] = "";

int move(int tl, int m, int c_f, int z_f, int m_f, int ma) {
	printf("\n");
	char board[LEN_MAX] = {'\0'};
	if (ma == 1) {
		c_f -= 1;
	}
	if (ma == 0) {
		z_f -= 1;
	}

	if (ma == 1) {
		m_f -= 1;
	}
	for (int i = 0; i < tl; i++) {
		printf("z");
	}
	printf("\n#");
	for (int i = 0; i <(tl-1); i++) {
		if (i == 0) {
			board[i] = 'C';
		}
		if (i == z_f) {
			board[i] = "Z";
		}
		if (i == m_f) {
			board[i] = "M";
		}
		if (i == tl-1) {
			board[i] = "#";
		}
		
		else {
			board[i] = 'z';
		}
		
		

	}

	printf("%s", board);
	printf("\n");
	for (int i = 0; i < tl; i++) {
		printf("#");
	}

	return 0;


	

}


int pandok(int r, int p, int z_turn) {
	if (r > p)
	{
		//인간 성공
		return  1;
	}
	if (z_turn % 2 == 0)
	{
		if (r > (100 - p))
		{
			//좀비성공
			return  0;
		}
		
	}
	return -1;
}

int comment(int aggro, int c_position, int z_position, int  z_turn, int r, int p) {
	if (r > p)
	{
		//인간 성공
		aggro += 1;
		printf("citizen: %d -> %d (aggro: %d)", c_position + 1, c_position, aggro);
	}
	else
	{
		//인간 실패
		printf("citizen: stay %d (aggro: %d)", c_position, aggro);

	}
	if (z_turn % 2 == 0)
	{
		if (r > (100 - p))
		{

			//좀비 성공
			printf("\nzombie: %d -> %d", z_position + 1, z_position);
			return 1;
		}
		else
		{
			//좀비 실패
			printf("\nzombie: stay %d", z_position);
			return 0;
		}
	}
	else
	{
		printf("\nzombie: stay %d  (cannot move)", z_position);

	}	
	return 0;
}
int ma_move() {
	int a=2;
	int i = 1;//마동석 움직임 만들고 스태미너 까지 코멘트, 어그로 수 좀비가 따라가게 만들기 마동석 잡기쓰기
	int m = 0;
	while (i <= 1) {
		printf("\nmadongseok move(0:stay, 1:left)>>");
			scanf_s("%d", &a);
			if (a == 1 || a == 0) {
				i += 1;
				if (a == 1) {
					m = 1;
				}
				else {
					m = 0;
				}
				
			}
	}

	return m;
}
// 행동
int behavior(int z, int m,int a, int b) {

	if (z == 1) {	
		printf("citizen does nothing.");
	}
	else if(z!=1) {
		printf("zombie attacked nobody.");
	}
	if ("m==1") {
		printf("madongseok: %d (aggro: %d, stamina: %d)");

	}
	else{
		printf("madongseok rests...");

	}
}


int main() {
	int  ms, pp, n = 0;
	int tl = 1;
	int i = 0;
	int z_turn = 1;
	int p=0;
	int m;
	int aggro=1, c_position=0,z_position=0;
	


	start_scene();

	tl = insert_tl(n);
	ms = insert_ma(n);
	pp = insert_pp(n);
	initial_pos(tl);

	z_position = tl - 7;
	c_position = tl - 4;
	int c_f = 1, z_f = 1, m_f = 1;
	c_f = tl - 7;
	z_f = tl - 4;
	m_f = tl - 3;
	int ma = 0;
	while (1) {
		srand((unsigned int)time(NULL));
		int r = rand() % 100;
		printf("\n\n");
		m = pandok(r, pp, z_turn);

		move(tl, m, c_f, z_f, m_f, ma);


		comment(aggro, c_position, z_position, z_turn, r, p);
		ma = ma_move();
		int mp = 0;
		mp = move(tl, m, c_f, z_f, m_f, ma);


		printf("\n");
		if (ma == 0) {

			printf("\nmadongseok: stay %d(aggro: %d, stamina: %d)", mp, aggro, ms);
		}
		if (ma == 1) {
			printf("\nmadongseok: %d (aggro: %d, stamina: %d)", mp, aggro, ms);
		}
		behavior();
	}

}