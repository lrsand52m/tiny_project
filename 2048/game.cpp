#include"game.h"
COLORREF color[15] = { 0,
				YELLOW,
				MAGENTA,
				LIGHTRED,
				LIGHTMAGENTA,
				RED, 
				RGB(255, 128, 64),
				RGB(128, 0, 255),
				RGB(255, 0, 128),
				RGB(0, 0, 255),
				RGB(128, 0, 255),
				RGB(128, 64, 0),
				RGB(128, 0, 128),
				RGB(128, 128, 0),
				RGB(20, 30, 40)};

inline int Map::Log(size_t x)
{
	int n = 0;
	while (x - 1)
	{
		n++;
		x /= 2;
	}
	return n;
}
//待改进
bool Map::move(AD ad)
{
	int i = 0;
	int flag = 0;
	size_t *pre  = nullptr;
	size_t *cur  = nullptr;
	switch (ad)
	{
	case UP:
		while (i < _size)
		{
			pre = &_map[i];
			cur = &_map[i + _size];
			while (cur<_map+_range)
			{
				if (*pre == 0 && *cur)
				{
					*pre = *cur;
					flag = 1;
					*cur = 0;
				}
				else if (*cur == 0)
					cur += _size;
				else if (*pre != 0 && *pre == *cur)
				{
					*pre *= 2;
					*cur = 0;
					pre += _size;
					flag = 1;
					cur += _size;
				}
				else if (*pre != 0 && *cur != 0 && *pre != *cur)
				{
					pre += _size;
					if (pre == cur)
					{
						cur += _size;
					}
					else
					{
						*pre = *cur;
						*cur = 0;
						flag = 1;
						cur += _size;
					}
				}
			}
			i++;
		}
		break;
	case DOWN:
		while (i < _size)
		{
			pre = &_map[_range-i-1];
			cur = &_map[_range-i-1-_size];
			while (cur>=_map)
			{
				if (*pre == 0 && *cur)
				{
					*pre = *cur;
					flag = 1;
					*cur = 0;
				}
				else if (*cur == 0)
					cur -= _size;
				else if (*pre != 0 && *pre == *cur)
				{
					*pre *= 2;
					*cur = 0;
					pre -= _size;
					flag = 1;
					cur -= _size;
				}
				else if (*pre != 0 && *cur != 0 && *pre != *cur)
				{
					pre -= _size;
					if (pre == cur)
					{
						cur -= _size;
					}
					else
					{
						*pre = *cur;
						*cur = 0;
						flag = 1;
						cur -= _size;
					}
				}
			}
			i++;
		}
		break;
	case LEFT:
		while (i < _size)
		{
			pre = &_map[i*_size];
			cur = pre + 1;
			while (cur<_map+(i+1)*_size)
			{
				if (*pre == 0 && *cur)
				{
					*pre = *cur;
					flag = 1;
					*cur = 0;
				}
				else if (*cur == 0)
					cur++;
				else if (*pre && *pre == *cur)
				{
					*pre *= 2;
					*cur = 0;
					pre++;
					flag = 1;
					cur++;
				}
				else if (*pre  && *cur  && *pre != *cur)
				{
					pre++;
					if (pre == cur)
					{
						cur++;
					}
					else
					{
						*pre = *cur;
						*cur = 0;
						flag = 1;
						cur++;
					}
				}
			}
			i++;
		}
		break;
	case RIGHT:
		while (i < _size)
		{
			pre = &_map[(i + 1)*_size - 1];
			cur = pre - 1;
			while (cur>_map + i*_size - 1)
			{
				if (*pre == 0 && *cur)
				{
					*pre = *cur;
					flag = 1;
					*cur = 0;
				}
				else if (*cur == 0)
					cur--;
				else if (*pre != 0 && *pre == *cur)
				{
					*pre *= 2;
					*cur = 0;
					pre--;
					flag = 1;
					cur--;
				}
				else if (*pre != 0 && *cur != 0 && *pre != *cur)
				{
					pre--;
					if (pre == cur)
					{
						cur--;
					}
					else
					{
						*pre = *cur;
						flag = 1;
						*cur = 0;
						cur--;
					}
				}
			}
			i++;
		}
		break;
	}
	return flag == 1;
}

bool Map::painmap()
{
	cleardevice();
	BeginBatchDraw();
	setlinecolor(LIGHTCYAN);
	settextcolor(LIGHTGREEN);
	setlinestyle(PS_SOLID, 4);
	int i = 0;
	while (i < _range)
	{
		rectangle(10 + (i / _size) * 100, 10 + (i % _size) * 100, 110 + (i / _size) * 100, 110 + (i % _size) * 100);
		i++;
	}
	settextstyle(20, 15, _T("宋体"));
	for (i = 0; i < _range; i++)
	{
		char p[20] = { 0 };
		if (_map[i])
		{
			int c = color[Log(_map[i])];
			setfillcolor(c);
			setbkcolor(c);
			solidrectangle(12 + (i % _size) * 100, 12 + (i / _size) * 100, 108 + (i % _size) * 100, 108 + (i / _size) * 100);
			sprintf(p, "%d", _map[i]);
			outtextxy(12 + (i % _size) * 100 + 47 - 7 * strlen(p), 12 + (i / _size) * 100 + 40, p);//根据字符长度进行位置微调使其保持在中中央
		}
	}
	setbkcolor(BLACK);
	EndBatchDraw();
	return 0;
}

bool Map::creat()
{
	int i = rand() % 4 == 0 ? 4 : 2;//概率生成4而不是总是2
	if (isfull())return false;
	int k = 0;
	while (k<1000)
	{
		int r = rand() % _range;
		if (!_map[r])
		{
			_map[r] = i;
			return 1;
		}
		k++;
	}
	return 0;
}