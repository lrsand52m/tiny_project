#define _CRT_SECURE_NO_WARNINGS
#include"Prints.h"
int speed = 4;//2:fast;4:namal;5:slow 
int wan = 120;//图片对比度数据越大输出的内容越多
int getMapArray(char *mapname, unsigned char *maparray, int* mapwidth, int* mapheight)
{
	int bytes ;//24位图为3，32位图为4，类推
	//typedef struct tagBITMAPINFOHEADER
	//{
	//DWORD      biSize;
	//LONG       biWidth;
	//LONG       biHeight;
	//WORD       biPlanes;
	//WORD       biBitCount;
	//DWORD      biCompression;
	//DWORD      biSizeImage;
	//LONG       biXPelsPerMeter;
	//LONG       biYPelsPerMeter;
	//DWORD      biClrUsed;
	//DWORD      biClrImportant;
	//} BITMAPINFOHEADER
	BITMAPINFOHEADER ih;
	//typedef struct tagBITMAPFILEHEADER {
	//	WORD    bfType;
	//	DWORD   bfSize;
	//	WORD    bfReserved1;
	//	WORD    bfReserved2;
	//	DWORD   bfOffBits;
	//} BITMAPFILEHEADER;
	BITMAPFILEHEADER fh;
	int Row, Col;
	int i;// j, k;
	int j;
	int added;
	int index = 0;
	FILE *f;// *p;
	unsigned char *imagearray = (unsigned char*)calloc(8000 * 8000, sizeof(unsigned char));
	unsigned char *imagearray_tmp = (unsigned char*)calloc(8000 * 8000, sizeof(unsigned char));
	if ((f = fopen(mapname, "rb")) == NULL)
	{
		printf("open %s error,please check\n", mapname);
		return 0;
	}
	fread(&fh, sizeof(BITMAPFILEHEADER), 1, f);
	if (fh.bfType != 'MB')//不是MB表示不是BMP格式
	{
		printf("This is not a BMP picture, type is %s\n", fh.bfType);
		return 0;
	}
	//读取图片信息
	fh.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
	fread(&ih, sizeof(BITMAPINFOHEADER), 1, f);
	mapheight[0] = Row = ih.biHeight;
	mapwidth[0] = Col = ih.biWidth;
	bytes = ih.biBitCount/8;
	printf("%d", bytes);
	//added = 4 - (Col*bytes) % 4;
	added = 4 - (Col*bytes) % 4;
	if (added == 4)added = 0;
	printf("added = %d\n", added);system("pause");
	if (Row>2000 || Col>2000)
	{
		printf("BMP picture is too large, please choose a smaller one, row=%d col=%d\n", Row, Col);
		return -1;
	}
	//每个像素点用若干个字节表示(RGB),windows 会将图片的每一行4字节补齐，所以会多出一些字节，必须过滤掉这些字节
	fread(imagearray_tmp, sizeof(unsigned char), Row*(Col + 1)*bytes, f);
	//过滤补齐的点
	for (i = 0; i<Row*(Col*bytes + added); i++)
	{
		for (j = 0; j<added; j++)
		{
			if (i%(Col * bytes+ added) == (Col * bytes + j))
				i++;
		}
		imagearray[index++] = imagearray_tmp[i];
	}
	////每个像素点用3个字节表示(RGB),windows 会将图片的每一行4字节补齐，所以会多出一些字节，必须过滤掉这些字节  
	//fread(imagearray_tmp, sizeof(unsigned char), Row*(Col + 1)*bytes, f);

	////过滤补齐的点  
	//for (i = 0; i<Row*(Col*bytes + added); i++){
	//	for (j = 0; j<added; j++){
	//		if (i % (Col * 3 + added) == Col * 3 + j) i++;
	//	}
	//	imagearray[index++] = imagearray_tmp[i];
	//}

	//二值化  
	int sum;
	index = 0;
	//灰度取整gray=(30*R+59*G+11*B)/100
	for (i = 0; i<Row*(Col*bytes + added); i += bytes)
	{
		int R, G, B, gray;
		int j = 0;
		sum = 0;
		for (; j<bytes; j++)
		{
			if (bytes == 4)
			{
				if (j == 1)
					R = imagearray[i + j];
				if (j == 2)
					G = imagearray[i + j];
				if (j == 3)
					B = imagearray[i + j];
			}
			sum += imagearray[i + j];
		}
		
		if (bytes == 4)
			gray = (30 * R + 59 * G + 11 * B) / 100;
		else
			gray = sum / 3;
		if (gray<80)
			maparray[index++] = 0;
		else if (gray<100)
			maparray[index++] = 1;
		else if (gray<wan)
			maparray[index++] = 2;
		else 
			maparray[index++] = 3;
	}
	fclose(f);
	return 0;
}
unsigned int printimg(char* argv)
{
	int mapwidth[1];
	int mapheight[1];
	int i = 0;
	int x = 0;
	int y = 0; 
	unsigned int c1; 
	unsigned int c2;
	//int tmp;
	char* mapname = argv;
	unsigned char* maparray = (unsigned char*)calloc(2000 * 2000, sizeof(unsigned char));
	int color = 3;
	getMapArray(mapname, maparray, mapwidth, mapheight);
	//打开画图
	system("start /b C:/Windows/system32/mspaint.exe");
	//画图有时并不能瞬间打开，留几秒缓冲
	Sleep(5000);
	c1 = clock();
	int startx = (1920 - mapwidth[0]) / 2;
	int starty = (1080 + mapheight[0]) / 2;
	move(startx, starty);
	for (i = 0; i<mapheight[0] * mapwidth[0]; i++)
	{
		if (maparray[i] == 3) continue;
		//else if ((maparray[i] == 0) && (color !=0))
		//{
		//	//移动鼠标
		//	move(920, 80);
		//	//Sleep(speed);
		//	//点击
		//	click(0, 0);// click(0, 0);
		//	//Sleep(speed*3);
		//	color = 0;
		//}
		//else if ((maparray[i] == 1) && (color != 1))
		//{
		//	//移动鼠标
		//	move(945, 80);
		//	//Sleep(speed);
		//	//点击
		//	click(0, 0); //click(0, 0);
		//	//Sleep(speed*3);
		//	color = 1;
		//}
		//else if ((maparray[i] == 2) && (color != 2))
		//{
		//	//移动鼠标
		//	move(945, 105);
		//	//Sleep(speed);
		//	//点击
		//	click(0, 0);// click(0, 0);
		//	//Sleep(speed*3);
		//	color = 2;
		//}
		x = startx + i%mapwidth[0];
		y = starty - i / mapwidth[0];
		//移动鼠标
		move(x, y);
		//点击
		click(0, 0);
		//给画图软件缓冲(不然可能会奔溃)
		Sleep(speed);
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			bre:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			while (1)
			{
				Sleep(500);
				if (GetAsyncKeyState(VK_SPACE))
					break;
				if (GetAsyncKeyState(VK_ESCAPE))
				{
					goto bre;
				}
			}
		}
	}
	c2 = clock();
	return (c2-c1)/clt;
}