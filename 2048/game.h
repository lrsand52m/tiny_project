#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include <graphics.h>
typedef enum Adjust
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}AD;
class Map
{
public:
	Map(int x = 4)
	: _size(x)
	, _range(x*x)
	, _map(new size_t[x*x])
	{
		for (int i = 0; i < x*x; i++)
			_map[i] = 0;
	}

	~Map()
	{
		delete[] _map;
		_map = nullptr;
		_range = 0;
		_size = 0;
	}

	bool initmap(int n = 2)
	{
		for (int i = 0; i < _range; i++)
			_map[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int pos = rand() % _range;
			if (_map[pos])
				_map[pos] *= 2;
			else
				_map[pos] += 2;
		}
		_score = getscore();
		return true;
	}

	bool isfull()
	{
		for (int i = 0; i < _range; i++)
		{
			if (!_map[i])return false;
		}
		return true;
	}
	bool isover()
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				int k = _map[i*_size + j];
				if (k == 0)return false;
				if (((i + 1)*_size + j) < _range &&  k == _map[(i + 1)*_size + j])
					return false;
				if (((i - 1)*_size + j) >= 0 && k == _map[(i - 1)*_size + j])
					return false;
				if ((i*_size + j + 1) < _range && j+1 <_size && k == _map[i*_size + j + 1])
					return false;
				if (j-1 >= 0 && k == _map[i*_size + j - 1])
					return false;
			}
		}
		return true;
	}
	
	int getscore()
	{
		int score = 0;
		for (int i = 0; i < _range; i++)
			score += _map[i];//*Log(_map[i]);
		return _score = score;
	}

	bool move(AD ad);
	bool painmap();
	bool creat();
	int Log(size_t x);


private:
	int _size;
	int _range;
	size_t* _map;
	int _score;
};
