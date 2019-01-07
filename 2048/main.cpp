#include"game.h"
void test()
{
	srand((unsigned)time(NULL));
	initgraph(640, 480);
	Map g(4);
	AD ad = UP;
	g.initmap();
	while (1)
	{
		char p[20] = {0};
		int i = rand() % 4;
		switch (i)
		{
		case 0:
			ad = UP;
			sprintf(p, "UP");
			break;
		case 1:
			ad = DOWN;
			sprintf(p, "DOWN");
			break;
		case 2:
			ad = LEFT;
			sprintf(p, "LEFT");
			break;
		case 3:
			ad = RIGHT;
			sprintf(p, "RIGHT");
			break;
		}
		bool b = g.move(ad);
		if(b)
			g.creat();
		g.painmap();
		outtextxy(180, 440, p);
		sprintf(p, "SCORE: %d", g.getscore());
		outtextxy(140, 420, p);
		if (g.isover())
		{
			outtextxy(160, 440, "GAME OVER");
			Sleep(3000);
			break;
		}
		Sleep(100);
		
	}
	closegraph();
	test();
}

void testai()
{
	srand((unsigned)time(NULL));
	initgraph(800, 640);
	Map g(4);
	AD ad = UP;
	g.initmap();
	int change = 1;
	while (1)
	{
		char p[20] = { 0 };
		bool b;
		if (change)
		{
			if (b = g.move(DOWN));
			else if (b = g.move(RIGHT));
			else if (b = g.move(LEFT));
			else if (b = g.move(UP));
			change = 0;
		}
		else
		{
			if (b = g.move(RIGHT));
			else if (b = g.move(UP));
			else if (b = g.move(LEFT));
			else if (b = g.move(UP));
			change = 1;
		}
		if(b)g.creat();
		g.painmap();
		outtextxy(180, 440, p);
		sprintf(p, "SCORE: %d", g.getscore());
		outtextxy(140, 420, p);
		if (g.isover())
		{
			outtextxy(160, 440, "GAME OVER");
			Sleep(3000);
			break;
		}
		Sleep(20);

	}
	closegraph();
	//testai();
}

void play()
{
	Map g(4);
	AD ad;
	int f = 1;
	while (1)
	{
		g.initmap();
		initgraph(640, 480);
		g.painmap();
		if (f)
		{
			outtextxy(460, 240, "press enter");
			outtextxy(460, 260, "to start");
			while (1)
			{
				if (GetAsyncKeyState(VK_RETURN))
					break;
			}
			f = 0;
		}
		g.painmap();
		while (1)
		{
			char p[20];
			bool b = false;
			if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
			{
				b = g.move(UP);
			}
			else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
			{
				b = g.move(DOWN);
			}
			else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
			{
				b = g.move(LEFT);
			}
			else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
			{
				b = g.move(RIGHT);
			}
			Sleep(200);
			if (b)
			{
				g.creat();
				g.painmap();
				sprintf(p, "SCORE: %d", g.getscore());
				outtextxy(140, 420, p);
			}
			if (g.isover())
			{
				outtextxy(160, 440, "GAME OVER");
				Sleep(3000);
				break;
			}
		}
		outtextxy(422, 240, "enter: restart");
		outtextxy(422, 260, "escape: exit");
		while (1)
		{
			if (GetAsyncKeyState(VK_RETURN))
				break;
			else if (GetAsyncKeyState(VK_ESCAPE))
				return;
		}
		closegraph();
	}
}

int main()
{
	//test();
	while (1)
	testai();
	play();
	return 0;
}