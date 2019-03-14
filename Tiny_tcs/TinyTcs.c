#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
struct S{ int x, y; struct S *n, *l; }*h, *e;
int _v[40][25] = { { 1 } }, d[] = { 0, 1, 0, -1 }, o = 0, g, l = 1, L = 3, x = 1, r; HANDLE u;
#define v(_w) (_v[((struct S*)_w)->x][((struct S*)_w)->y])
#define p(_w,_x,_y,_z) WriteConsoleOutputCharacter(u,_z,2,(COORD){(_x==-1?((struct S*)_w)->x:_x)*2,_y==-1?((struct S*)_w)->y:_y},(LPDWORD)&r)
int f(int i, int j, int k){
	for (i = k % 40, j = k % 25, k = 1200; ((i >= 40 ? i = 0, j >= 25 ? j = 0 : j++ : 1), _v[i][j]) && k; i++, k--);
	return k ? p(0, i, j, "○"), _v[i][j] = 1 : (o = 1);
}
int m(int dir){
	struct S *k = (struct S*)malloc(sizeof(struct S));
	k->x = h->x + d[dir], k->y = h->y + d[(dir + 3) % 4], k->n = h, h->l = k, h = k, v(e) = 0, p(e, -1, -1, "  ");
	if (k->x<0 || k->x>39 || k->y<0 || k->y>24 || v(h) == 2)return p(e, -1, -1, "□"), o = 2, 0;
	if ((p(h, -1, -1, "■"), p(h->n, -1, -1, "□"), v(h) == 1) && f(0, 0, rand() % 10000) || x)return v(h) = v(e) = 2, p(e, -1, -1, "□"), 1;
	return v(h) = 2, free((e = e->l)->n), (int)(e->n = 0);
}
int main(){
	SetConsoleScreenBufferSize(u = GetStdHandle(STD_OUTPUT_HANDLE), (COORD){ 80, 25 }), SetConsoleCursorInfo(u, &(CONSOLE_CURSOR_INFO){30, 0});
	h = (struct S*)malloc(sizeof(struct S)), h->x = h->y = 0, h->n = 0, e = h, srand(time(0)), m(1), m(1), f(0, 0, rand() % 10000);
	for (x = 0; !o; Sleep(100))switch (_kbhit() ? (g = _getch()) == 224 ? _getch() : g : 0){
	case 119:case 87:case 72:L += m(l != 2 ? l = 0 : l); break; case 100:case 68:case 77:L += m(l != 3 ? l = 1 : l); break;
	case 115:case 83:case 80:L += m(l != 0 ? l = 2 : l); break; case  97:case 65:case 75:L += m(l != 1 ? l = 3 : l); break; default:L += m(l);
	}
	sprintf((char*)_v, "%s了，蛇总长 %d 个单位", o - 1 ? "哈哈你输" : "哇哇你赢", L), MessageBox(NULL, TEXT((char*)_v), "游戏结束", 0x1040);
}