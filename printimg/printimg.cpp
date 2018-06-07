#define _CRT_SECURE_NO_WARNINGS
#include"Prints.h"
int speed = 3;//2:fast;4:namal;5:slow 
int wan = 120;//ͼƬ�Աȶ�����Խ�����������Խ��
int getMapArray(char *mapname, unsigned char *maparray, int* mapwidth, int* mapheight)
{
	int bytes ;//24λͼΪ3��32λͼΪ4������
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
	if (fh.bfType != 'MB')//����MB��ʾ����BMP��ʽ
	{
		printf("This is not a BMP picture, type is %s\n", fh.bfType);
		return 0;
	}
	//��ȡͼƬ��Ϣ
	fh.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
	fread(&ih, sizeof(BITMAPINFOHEADER), 1, f);
	mapheight[0] = Row = ih.biHeight;
	mapwidth[0] = Col = ih.biWidth;
	bytes = ih.biBitCount/8;
	printf("%d", bytes);
	system("pause");
	added = 4 - (Col*bytes) % 4;
	printf("added = %d\n", added);
	if (Row>2000 || Col>2000)
	{
		printf("BMP picture is too large, please choose a smaller one, row=%d col=%d\n", Row, Col);
		return -1;
	}
	//ÿ�����ص������ɸ��ֽڱ�ʾ(RGB),windows �ὫͼƬ��ÿһ��4�ֽڲ��룬���Ի���һЩ�ֽڣ�������˵���Щ�ֽ�
	fread(imagearray_tmp, sizeof(unsigned char), Row*(Col + 1)*bytes, f);
	//���˲���ĵ�
	for (i = 0; i<Row*(Col*bytes + added); i++)
	{
		//for (j = 0; j<added; j++)
		//{
		//	if (i%(Col * bytes+ added) == (Col * 3 + j))
		//		i++;
		//}
		imagearray[index++] = imagearray_tmp[i];
	}

	//��ֵ��  
	int sum;
	index = 0;
	//�Ҷ�ȡ��gray=(30*R+59*G+11*B)/100
	for (i = 0; i<Row*(Col*bytes + added); i += bytes)
	{
		int R, G, B, gray;
		int j = (bytes == 4 ? 0 : 1);
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
		//gray = sum / 3;
		gray = (30 * R + 59 * G + 11 * B) / 100;
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
	//�򿪻�ͼ
	system("start /b C:/Windows/system32/mspaint.exe");
	//��ͼ��ʱ������˲��򿪣������뻺��
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
		//	//�ƶ����
		//	move(920, 80);
		//	//Sleep(speed);
		//	//���
		//	click(0, 0);// click(0, 0);
		//	//Sleep(speed*3);
		//	color = 0;
		//}
		//else if ((maparray[i] == 1) && (color != 1))
		//{
		//	//�ƶ����
		//	move(945, 80);
		//	//Sleep(speed);
		//	//���
		//	click(0, 0); //click(0, 0);
		//	//Sleep(speed*3);
		//	color = 1;
		//}
		//else if ((maparray[i] == 2) && (color != 2))
		//{
		//	//�ƶ����
		//	move(945, 105);
		//	//Sleep(speed);
		//	//���
		//	click(0, 0);// click(0, 0);
		//	//Sleep(speed*3);
		//	color = 2;
		//}
		x = startx + i%mapwidth[0];
		y = starty - i / mapwidth[0];
		//�ƶ����
		move(x, y);
		//���
		click(0, 0);
		//����ͼ�������(��Ȼ���ܻᱼ��)
		Sleep(speed);
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}
	c2 = clock();
	return (c2-c1)/clt;
}