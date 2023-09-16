#define _CRT_SECURE_NO_WARNINGS 1
#include "Sequenlist.h"
int main()
{
	Sequenlist s;
	SetSequenlist(&s);
	RearInsert(&s, 1);
	RearInsert(&s, 2);
	RearInsert(&s, 3);
	RearInsert(&s, 4);
	RearInsert(&s, 5);
	ShowSequenlist(&s);
	/*RearDelete(&s);*/
	/*HeadDelete(&s);*/
	RandomDelete(&s, 4);
	ShowSequenlist(&s);
	/*HeadInsert(&s, 0);
	ShowSequenlist(&s);
	RandomInsert(&s, -1,1);
	ShowSequenlist(&s);*/
	return 0;
}