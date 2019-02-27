#include"TetrisFun.h"

char g_backgroundArray[VERTICAL_NUM][HORIZONTAL_NUM] = { 0 };//���ڼ�¼������ʾ
char g_squareArray[2][4] = { 0 };//���ڼ�¼�������
int g_squareIndex = -1;//��¼�������������һ�ַ���
int g_socre = 0;//��¼����

//0 0 0 3 3 3 0 0 0 0
//0 0 0 3 3 3 0 0 0 0
//0 0 0 3 3 3 0 0 0 0
int g_xIndex = 3;//��¼��������ڿռ�����Ͻ�x
int g_yIndex = 0;//��¼��������ڿռ�����Ͻ�y

//������ͼ
void onPaint(HDC hdc)
{
	HDC hMemDc=CreateCompatibleDC(hdc);
	HBITMAP hBitmap =CreateCompatibleBitmap(hdc, 500/*DISPLAY_WIDTH*/, 600/*DISPLAY_HEIGHT*/);
	SelectObject(hMemDc, hBitmap);

	paintScore(hMemDc);
	paintSquare(hMemDc);
	BitBlt(hdc, 0, 0, 500/*CLIENT_WIDTH*/, 600/*CLIENT_HEIGHT*/, hMemDc, 0, 0, SRCCOPY);
	DeleteObject(hBitmap); 
	DeleteDC(hMemDc);
}

void paintScore(HDC hMemDc)
{
	char strScore[10] = { 0 };

	Rectangle(hMemDc, DISPLAY_WIDTH, 0, 500/*DISPLAY_WIDTH*/, 600/*DISPLAY_HEIGHT*/);
	_itoa_s(g_socre, strScore, 10, 10);
	TextOut(hMemDc, DISPLAY_WIDTH + 100, 50, strScore, strlen((char *)strScore));
}

//��ʼ��һЩ����
void onCreate()
{
	srand((int)time(NULL));
	//��ʼ��ʱ��Ҫ����һ�β�������
	createRandomSquare();//�����������,��7��
	copySquareToBack();//�����������������
}

//������  ��ΪHDC�ǵ�ַ�����Բ���ʹ������
void paintSquare(HDC hMemDc)
{
	Rectangle(hMemDc, 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);

	//g_backgroundArray[2][4] = 1;
	//g_backgroundArray[1][4] = 1;
	//g_backgroundArray[2][5] = 1;
	//g_backgroundArray[2][3] = 1;
	HBRUSH hMovingSquare = CreateSolidBrush(RGB(124, 224, 24));
	HBRUSH hEndSquare = CreateSolidBrush(RGB(24, 17, 224));
	HBRUSH hOldBrush=NULL;
	for (int i = 0; i < VERTICAL_NUM; i++)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if(g_backgroundArray[i][j] ==1)
			{
				hOldBrush = (HBRUSH)SelectObject(hMemDc, hMovingSquare);
				Rectangle(hMemDc, j*SINGLE_SQUARE_SIZE, 
					i*SINGLE_SQUARE_SIZE,
					j*SINGLE_SQUARE_SIZE+ SINGLE_SQUARE_SIZE,
					i*SINGLE_SQUARE_SIZE+ SINGLE_SQUARE_SIZE);
			}
			if (g_backgroundArray[i][j] == 2)
			{
				SelectObject(hMemDc, hEndSquare);
				Rectangle(hMemDc, j*SINGLE_SQUARE_SIZE,
					i*SINGLE_SQUARE_SIZE,
					j*SINGLE_SQUARE_SIZE + SINGLE_SQUARE_SIZE,
					i*SINGLE_SQUARE_SIZE + SINGLE_SQUARE_SIZE);
			}
		}
	}
	if(hOldBrush)
		SelectObject(hMemDc, hOldBrush);
	DeleteObject(hMovingSquare);
	DeleteObject(hEndSquare);

}

//�����������,��7��
int createRandomSquare()
{
	int randIndex= rand() % 7;
	switch (/*randIndex*/6)
	{
	case 0:
		//1 1 0 0
		//0 1 1 0
		g_squareArray[0][0] = 1;g_squareArray[0][1] = 1;g_squareArray[0][2] = 0;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 0;g_squareArray[1][1] = 1;g_squareArray[1][2] = 1;g_squareArray[1][3] = 0;
		
		g_xIndex = 3;
		g_yIndex = 0;
		break;
	case 1:
		//0 1 1 0
		//1 1 0 0
		g_squareArray[0][0] = 0;g_squareArray[0][1] = 1;g_squareArray[0][2] = 1;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 1;g_squareArray[1][1] = 1;g_squareArray[1][2] = 0;g_squareArray[1][3] = 0;
		
		g_xIndex = 3;
		g_yIndex = 0;
		break;
	case 2:
		//0 0 1 0
		//1 1 1 0
		g_squareArray[0][0] = 0;g_squareArray[0][1] = 0;g_squareArray[0][2] = 1;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 1;g_squareArray[1][1] = 1;g_squareArray[1][2] = 1;g_squareArray[1][3] = 0;
		
		g_xIndex = 3;
		g_yIndex = 0;
		break;
	case 3:
		//1 0 0 0
		//1 1 1 0
		g_squareArray[0][0] = 1;g_squareArray[0][1] = 0;g_squareArray[0][2] = 0;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 1;g_squareArray[1][1] = 1;g_squareArray[1][2] = 1;g_squareArray[1][3] = 0;
		
		g_xIndex = 3;
		g_yIndex = 0;
		break;
	case 4:
		//0 0 0 0 1 0 0 0 0 0 
		//0 0 0 1 1 1 0 0 0 0 
		g_squareArray[0][0] = 0;g_squareArray[0][1] = 1;g_squareArray[0][2] = 0;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 1;g_squareArray[1][1] = 1;g_squareArray[1][2] = 1;g_squareArray[1][3] = 0;
		
		g_xIndex = 3;
		g_yIndex = 0;
		break;
	case 5:
		//0 0 0 0 1 1 0 0 0 0
		//0 0 0 0 1 1 0 0 0 0
		g_squareArray[0][0] = 0;g_squareArray[0][1] = 1;g_squareArray[0][2] = 1;g_squareArray[0][3] = 0;
		g_squareArray[1][0] = 0;g_squareArray[1][1] = 1;g_squareArray[1][2] = 1;g_squareArray[1][3] = 0;
		
		g_xIndex = 4;
		g_yIndex = 0;
		break;
	case 6:
		//0 0 0 1 1 1 1 0 0 0 
		//0 0 0 0 0 0 0 0 0 0
		g_squareArray[0][0] = 1;g_squareArray[0][1] = 1;g_squareArray[0][2] = 1;g_squareArray[0][3] = 1;
		g_squareArray[1][0] = 0;g_squareArray[1][1] = 0;g_squareArray[1][2] = 0;g_squareArray[1][3] = 0;
		
		g_xIndex = 4;
		g_yIndex = 0;
		break;
	default:
		break;
	}
	g_squareIndex = randIndex;
	return randIndex;
}

//�����������������
//���������λ��ʼ������+3
void copySquareToBack()
{
	for(int i=0;i<2;i++)
	{ 
		for (int j = 0; j < 4; j++)
		{
			//��Ϊ���������ʾ�ڱ����м䣬������Ҫ+3
			g_backgroundArray[i][j + 3] = g_squareArray[i][j];
		}
	}
}

//���»س���
void keyReturnProc(HWND hWnd)
{
	//������ʱ��
	SetTimer(hWnd, TIMERID, 500, NULL);//���һ����������ΪNULL�󣬻����WM_TIMER��Ϣ
}

//ʹ��������
void squareDown()
{
	//�������ϱ���
	for (int i = VERTICAL_NUM - 1; i >= 0; i--)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)
			{
				g_backgroundArray[i + 1][j] = g_backgroundArray[i][j];
				g_backgroundArray[i][j] = 0;
			}
		}
	}
}

void squareLeft()
{
	//�����ұ���
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)
			{
				g_backgroundArray[i][j-1] = g_backgroundArray[i][j];
				g_backgroundArray[i][j] = 0;
			}
		}
	}
}

void squareRight()
{
	//���ҵ������
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = HORIZONTAL_NUM - 1; j >=0; j--)
		{
			if (g_backgroundArray[i][j] == 1)
			{
				g_backgroundArray[i][j + 1] = g_backgroundArray[i][j];
				g_backgroundArray[i][j] = 0;
			}
		}
	}
}

//��ʱ��������
void onTimerProc(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);

	if(IsSquareReachBottom() && canSquareDown())
	{
		g_yIndex++;

		squareDown();
	}		
	else
	{
		//��ͣ�µķ�����ֵ��Ϊ2�������²����ķ����޷�����
		change1To2();
		destoryOneLineSquare();
		if (IsGameOver())
		{
			MessageBox(hWnd, "Game Over", "��ʾ", MB_OK);
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
			return;
		}
		//�����µķ��飬������������
		createRandomSquare();
		copySquareToBack();
	}
	//�ػ����
	onPaint(hdc);
	//SendMessage(hWnd, WM_PAINT, NULL, NULL);
	ReleaseDC(hWnd, hdc);
}

void onLeftProc(HWND hWnd)
{
	if (IsSquareReachLeft() && canSquareLeft())
	{
		g_xIndex--;

		HDC hdc = GetDC(hWnd);
		squareLeft();
		//�ػ����
		onPaint(hdc);
		//SendMessage(hWnd, WM_PAINT, NULL, NULL);
		ReleaseDC(hWnd, hdc);
	}
}

void onRightProc(HWND hWnd)
{
	if (IsSquareReachRight() && canSquareRight())
	{
		g_xIndex++;

		HDC hdc = GetDC(hWnd);
		squareRight();
		//�ػ����
		onPaint(hdc);
		//SendMessage(hWnd, WM_PAINT, NULL, NULL);
		ReleaseDC(hWnd, hdc);
	}
}

void onDownProc(HWND hWnd)
{
	onTimerProc(hWnd);
}

void onChangeProc(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	switch (/*g_squareIndex*/6)
	{
	//0-4Ϊһ��
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		if(canSquareChange())
		{
			change0To4SquareShape();
		}		
		else
		{
			return;
		}
		break;	
	case 5://5Ϊ�����Σ�����Ҫ����
		break;	
	case 6://6Ϊ����
		if(canLongSquareChange())
			changeLongSquareShape();
		break;
	}
	onPaint(hdc);
	ReleaseDC(hWnd, hdc);
}


int canSquareDown()
{
	//���µ���,�����ұ���
	for (int i = VERTICAL_NUM - 1; i >= 0; i--)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)//�ҵ�����ķ�����·����
			{
				if (g_backgroundArray[i + 1][j] == 2)//����ķ����Ѿ��˶���ֹͣ�ķ����Ϸ�
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int canSquareLeft()
{
	//���ϵ��£����ұ���
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)//�ҵ����Ƶķ�����·����
			{
				if (g_backgroundArray[i][j-1] == 2)//���Ƶķ����Ѿ��˶���ֹͣ�ķ����ұ�
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int canSquareRight()
{
	//���ϵ��£��ҵ������
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = HORIZONTAL_NUM; j >=0; j--)
		{
			if (g_backgroundArray[i][j] == 1)//�ҵ����Ƶķ�����ҷ����
			{
				if (g_backgroundArray[i][j + 1] == 2)//���Ƶķ����Ѿ��˶���ֹͣ�ķ������
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int canSquareChange()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (g_backgroundArray[g_yIndex+i][g_xIndex+j] == 2)
				return 0;
		}
	}

	//��һ�ַ���������߽粻�������
	if (g_xIndex < 0 || g_xIndex + 2 >9)
	{
		return 0;
	}

	////�ڶ��ַ���������߽���������Σ���g_xIndex�ƶ�һλ��ʹ���ڱ߽���
	//if (g_xIndex < 0)
	//{
	//	g_xIndex = 0;
	//}
	//else if (g_xIndex + 2 > 9)
	//{
	//	g_xIndex = 7;
	//}
	return 1;
}

int canLongSquareChange()
{
	int i = 1, j = 1;

	for (; i < 4;)//�ж������ұ߾���߽����ֵΪ2�ķ����ж�Զ
	{
		if (g_backgroundArray[g_yIndex][g_xIndex + i] == 2 ||
			g_xIndex + i > 9)
		{
			i--;
			break;
		}
		i++;
	}

	for (; j < 4;)//�ж�������߾���߽����ֵΪ2�ķ����ж�Զ
	{
		if (g_backgroundArray[g_yIndex][g_xIndex - j] == 2 ||
			g_xIndex -j < 0 )
		{
			j--;//��Ϊ��һ���ȼ���1�����������жϵģ����Բ���������Ҫ��ȥ1
			break;
		}
		j++;
	}

	if (i + j < 3)
	{
		return 0;
	}

	return 1;
}

//�жϷ����ܷ����䣬����������䣬����1 �����򷵻�0
//��������Ƿ�ֹ�������䳬���±߽�
int IsSquareReachBottom()
{
	for (int i = 0; i < HORIZONTAL_NUM; i++)
	{
		//�Ѿ������±߽�,�ڴ�֮ǰ�Ѿ�ͣ���±߽�ķ���ֵ�Ѿ���Ϊ2
		if (g_backgroundArray[VERTICAL_NUM - 1][i] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int IsSquareReachLeft()
{

	for (int i = 0; i < VERTICAL_NUM; i++)
	{
		//�Ѿ�������߽�,�ڴ�֮ǰ�Ѿ�ֹͣ�ķ���ֵ�Ѿ���Ϊ2
		if (g_backgroundArray[i][0] == 1)
		{
			return 0;
		}
	}
	return 1;

}

int IsSquareReachRight()
{
	for (int i = 0; i < VERTICAL_NUM; i++)
	{
		//�Ѿ������ұ߽�,�ڴ�֮ǰ�Ѿ�ֹͣ�ķ���ֵ�Ѿ���Ϊ2
		if (g_backgroundArray[i][9] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int IsGameOver()
{
	for (int i = 0; i < HORIZONTAL_NUM; i++)
	{
		if (g_backgroundArray[0][i] == 2)
		{
			return 1;
		}
	}
	return 0;
}

//��ͣ�µķ�����ֵ��Ϊ2(���������������Ե�1���2)�������²����ķ����޷�����
void change1To2()
{
	for (int i = 0; i < VERTICAL_NUM; i++)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)
				g_backgroundArray[i][j] = 2;
		}
	}
}

void change0To4SquareShape()
{
	char tempArray[3][3] = { 0 };
	//��3*3����ӱ����������
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempArray[i][j] = g_backgroundArray[g_yIndex + i][g_xIndex + j];
		}
	}

	//���任����ٸ�ֵ��ȥ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			g_backgroundArray[g_yIndex + i][g_xIndex + j]= tempArray[2-j][i];
		}
	}
}

void changeLongSquareShape()
{
	//���ŵ����
	if (g_backgroundArray[g_yIndex][g_xIndex-1]==1)//���ĵ����Ϊ1��˵������
	{
		//�Ƚ�ԭ����������
		g_backgroundArray[g_yIndex][g_xIndex - 1] = 0;
		g_backgroundArray[g_yIndex][g_xIndex + 0] = 0;//����
		g_backgroundArray[g_yIndex][g_xIndex + 1] = 0;
		g_backgroundArray[g_yIndex][g_xIndex + 2] = 0;

		// 1 1 1 1 
		// 2 2 2 2 
		if (g_backgroundArray[g_yIndex+1][g_xIndex] == 2)
		{
			//��ֹ
			// 2 2 2 2		2 2 2 2
			// 1 1 1 1	��	0 0 0 0
			// 2 2 2 2		1 1 1 1
			//				2 2 2 2
			if (g_backgroundArray[g_yIndex - 3][g_xIndex] != 2 &&
				g_backgroundArray[g_yIndex - 2][g_xIndex] != 2 &&
				g_backgroundArray[g_yIndex - 1][g_xIndex] != 2)
			{
				//Ȼ�����ϱ��κ��
				g_backgroundArray[g_yIndex - 3][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 2][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//����
			}
	
		
		}
		else if (g_backgroundArray[g_yIndex + 2][g_xIndex] == 2)
		{
			// 2 2 2 2
			// 1 1 1 1
			// 0 0 0 0
			// 2 2 2 2	
			if (g_backgroundArray[g_yIndex - 1][g_xIndex] != 2 &&
				g_backgroundArray[g_yIndex - 2][g_xIndex] != 2)
			{
				//Ȼ�����ϱ��κ��
				g_backgroundArray[g_yIndex - 2][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//����
				g_backgroundArray[g_yIndex + 1][g_xIndex] = 1;
			}

		}
		else
		{
			//��ֹ
			//2 2 2 2
			//1 1 1 1
			//0 0 0 0
			//0 0 0 0
			if (g_backgroundArray[g_yIndex - 1][g_xIndex] != 2)
			{
				//Ȼ�����ϱ��κ��
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//����
				g_backgroundArray[g_yIndex + 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 2][g_xIndex] = 1;
			}

		}

	}
	else//���ŵ�
	{
		//�Ƚ�ԭ����������
		g_backgroundArray[g_yIndex - 1][g_xIndex] = 0;
		g_backgroundArray[g_yIndex + 0][g_xIndex] = 0;//����
		g_backgroundArray[g_yIndex + 1][g_xIndex] = 0;
		g_backgroundArray[g_yIndex + 2][g_xIndex] = 0;

		if ( g_backgroundArray[g_yIndex][g_xIndex + 1] == 2 || g_xIndex == 9)
		{	//��������ƽ��2λ
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 2] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 3] = 1;

			//������ĸı�
			g_xIndex -= 2;
		}
		else if (g_backgroundArray[g_yIndex][g_xIndex + 2] == 2 || g_xIndex == 8)
		{	//��������ƽ��1λ
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 2] = 1;

			//������ĸı�
			g_xIndex -= 1;
		}
		else if (g_backgroundArray[g_yIndex][g_xIndex - 1] == 2 || g_xIndex == 0)
		{	//��������ƽ��1λ
			g_backgroundArray[g_yIndex][g_xIndex + 3] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 2] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			
			//������ĸı�
			g_xIndex += 1;
		}
		else
		{
			//Ȼ�����ϱ��κ��
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;//����
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 2] = 1;
		}
	}
}

void destoryOneLineSquare()
{
	int nSum = 0;//��¼һ�з���ֵ
	for (int i = 19; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			nSum += g_backgroundArray[i][j];
		}

		if (nSum == 20)//һ������
		{
			//����һ��
			int iTempI = i-1;
			for (; iTempI > 0; iTempI--)
			{
				for (int iTempJ = 0; iTempJ < 19; iTempJ++)
				{
					g_backgroundArray[iTempI][iTempJ] = g_backgroundArray[iTempI-1][iTempJ];
				}
			}
			g_socre++;//����+1
			i++;//��Ϊforѭ����ÿ��-1�����Դ˴�+1��������Ȼ�Ӹ��п�ʼ

		}

		nSum = 0;//����
	}
}
