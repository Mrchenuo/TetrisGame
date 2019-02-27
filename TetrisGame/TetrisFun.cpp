#include"TetrisFun.h"

char g_backgroundArray[VERTICAL_NUM][HORIZONTAL_NUM] = { 0 };//用于记录背景显示
char g_squareArray[2][4] = { 0 };//用于记录随机方块
int g_squareIndex = -1;//记录随机创建的是哪一种方块
int g_socre = 0;//记录分数

//0 0 0 3 3 3 0 0 0 0
//0 0 0 3 3 3 0 0 0 0
//0 0 0 3 3 3 0 0 0 0
int g_xIndex = 3;//记录随机块所在空间的左上角x
int g_yIndex = 0;//记录随机块所在空间的左上角y

//画背景图
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

//初始化一些操作
void onCreate()
{
	srand((int)time(NULL));
	//初始化时需要进行一次产生操作
	createRandomSquare();//产生随机方块,共7个
	copySquareToBack();//将随机块贴到背景上
}

//画方块  因为HDC是地址，所以不用使用引用
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

//产生随机方块,共7个
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

//将随机块贴到背景上
//从左起第四位开始，所以+3
void copySquareToBack()
{
	for(int i=0;i<2;i++)
	{ 
		for (int j = 0; j < 4; j++)
		{
			//因为将随机块显示在背景中间，所以列要+3
			g_backgroundArray[i][j + 3] = g_squareArray[i][j];
		}
	}
}

//按下回车键
void keyReturnProc(HWND hWnd)
{
	//开启定时器
	SetTimer(hWnd, TIMERID, 500, NULL);//最后一个参数设置为NULL后，会产生WM_TIMER消息
}

//使方块下落
void squareDown()
{
	//从下往上遍历
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
	//从左到右遍历
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
	//从右到左遍历
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

//定时器处理函数
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
		//将停下的方块数值改为2，否则新产生的方块无法下落
		change1To2();
		destoryOneLineSquare();
		if (IsGameOver())
		{
			MessageBox(hWnd, "Game Over", "提示", MB_OK);
			SendMessage(hWnd, WM_DESTROY, NULL, NULL);
			return;
		}
		//产生新的方块，并贴到背景上
		createRandomSquare();
		copySquareToBack();
	}
	//重绘界面
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
		//重绘界面
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
		//重绘界面
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
	//0-4为一类
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
	case 5://5为正方形，不需要变形
		break;	
	case 6://6为长条
		if(canLongSquareChange())
			changeLongSquareShape();
		break;
	}
	onPaint(hdc);
	ReleaseDC(hWnd, hdc);
}


int canSquareDown()
{
	//从下到上,从左到右遍历
	for (int i = VERTICAL_NUM - 1; i >= 0; i--)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)//找到下落的方块的下方尖端
			{
				if (g_backgroundArray[i + 1][j] == 2)//下落的方块已经运动到停止的方块上方
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
	//从上到下，左到右遍历
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = 0; j < HORIZONTAL_NUM; j++)
		{
			if (g_backgroundArray[i][j] == 1)//找到左移的方块的下方尖端
			{
				if (g_backgroundArray[i][j-1] == 2)//左移的方块已经运动到停止的方块右边
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
	//从上到下，右到左遍历
	for (int i = 0; i <VERTICAL_NUM; i++)
	{
		for (int j = HORIZONTAL_NUM; j >=0; j--)
		{
			if (g_backgroundArray[i][j] == 1)//找到左移的方块的右方尖端
			{
				if (g_backgroundArray[i][j + 1] == 2)//左移的方块已经运动到停止的方块左边
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

	//第一种方案，到达边界不让其变形
	if (g_xIndex < 0 || g_xIndex + 2 >9)
	{
		return 0;
	}

	////第二种方案，到达边界仍让其变形，但g_xIndex移动一位，使其在边界上
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

	for (; i < 4;)//判断中心右边距离边界或者值为2的方块有多远
	{
		if (g_backgroundArray[g_yIndex][g_xIndex + i] == 2 ||
			g_xIndex + i > 9)
		{
			i--;
			break;
		}
		i++;
	}

	for (; j < 4;)//判断中心左边距离边界或者值为2的方块有多远
	{
		if (g_backgroundArray[g_yIndex][g_xIndex - j] == 2 ||
			g_xIndex -j < 0 )
		{
			j--;//因为上一轮先加了1，这轮再做判断的，所以不符合条件要减去1
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

//判断方块能否下落，如果可以下落，返回1 ，否则返回0
//这个函数是防止方块下落超出下边界
int IsSquareReachBottom()
{
	for (int i = 0; i < HORIZONTAL_NUM; i++)
	{
		//已经到达下边界,在此之前已经停在下边界的方块值已经改为2
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
		//已经到达左边界,在此之前已经停止的方块值已经改为2
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
		//已经到达右边界,在此之前已经停止的方块值已经改为2
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

//将停下的方块数值改为2(即背景数组里所以的1变成2)，否则新产生的方块无法下落
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
	//将3*3数组从背景中提出来
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempArray[i][j] = g_backgroundArray[g_yIndex + i][g_xIndex + j];
		}
	}

	//将变换后的再赋值回去
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
	//横着的情况
	if (g_backgroundArray[g_yIndex][g_xIndex-1]==1)//中心的左边为1，说明横着
	{
		//先将原背景里的清除
		g_backgroundArray[g_yIndex][g_xIndex - 1] = 0;
		g_backgroundArray[g_yIndex][g_xIndex + 0] = 0;//中心
		g_backgroundArray[g_yIndex][g_xIndex + 1] = 0;
		g_backgroundArray[g_yIndex][g_xIndex + 2] = 0;

		// 1 1 1 1 
		// 2 2 2 2 
		if (g_backgroundArray[g_yIndex+1][g_xIndex] == 2)
		{
			//防止
			// 2 2 2 2		2 2 2 2
			// 1 1 1 1	或	0 0 0 0
			// 2 2 2 2		1 1 1 1
			//				2 2 2 2
			if (g_backgroundArray[g_yIndex - 3][g_xIndex] != 2 &&
				g_backgroundArray[g_yIndex - 2][g_xIndex] != 2 &&
				g_backgroundArray[g_yIndex - 1][g_xIndex] != 2)
			{
				//然后填上变形后的
				g_backgroundArray[g_yIndex - 3][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 2][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//中心
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
				//然后填上变形后的
				g_backgroundArray[g_yIndex - 2][g_xIndex] = 1;
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//中心
				g_backgroundArray[g_yIndex + 1][g_xIndex] = 1;
			}

		}
		else
		{
			//防止
			//2 2 2 2
			//1 1 1 1
			//0 0 0 0
			//0 0 0 0
			if (g_backgroundArray[g_yIndex - 1][g_xIndex] != 2)
			{
				//然后填上变形后的
				g_backgroundArray[g_yIndex - 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 0][g_xIndex] = 1;//中心
				g_backgroundArray[g_yIndex + 1][g_xIndex] = 1;
				g_backgroundArray[g_yIndex + 2][g_xIndex] = 1;
			}

		}

	}
	else//竖着的
	{
		//先将原背景里的清除
		g_backgroundArray[g_yIndex - 1][g_xIndex] = 0;
		g_backgroundArray[g_yIndex + 0][g_xIndex] = 0;//中心
		g_backgroundArray[g_yIndex + 1][g_xIndex] = 0;
		g_backgroundArray[g_yIndex + 2][g_xIndex] = 0;

		if ( g_backgroundArray[g_yIndex][g_xIndex + 1] == 2 || g_xIndex == 9)
		{	//整体向左平移2位
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 2] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 3] = 1;

			//标记中心改变
			g_xIndex -= 2;
		}
		else if (g_backgroundArray[g_yIndex][g_xIndex + 2] == 2 || g_xIndex == 8)
		{	//整体向左平移1位
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex - 2] = 1;

			//标记中心改变
			g_xIndex -= 1;
		}
		else if (g_backgroundArray[g_yIndex][g_xIndex - 1] == 2 || g_xIndex == 0)
		{	//整体向右平移1位
			g_backgroundArray[g_yIndex][g_xIndex + 3] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 2] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;
			
			//标记中心改变
			g_xIndex += 1;
		}
		else
		{
			//然后填上变形后的
			g_backgroundArray[g_yIndex][g_xIndex - 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 0] = 1;//中心
			g_backgroundArray[g_yIndex][g_xIndex + 1] = 1;
			g_backgroundArray[g_yIndex][g_xIndex + 2] = 1;
		}
	}
}

void destoryOneLineSquare()
{
	int nSum = 0;//记录一行方块值
	for (int i = 19; i > 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			nSum += g_backgroundArray[i][j];
		}

		if (nSum == 20)//一行满了
		{
			//消除一行
			int iTempI = i-1;
			for (; iTempI > 0; iTempI--)
			{
				for (int iTempJ = 0; iTempJ < 19; iTempJ++)
				{
					g_backgroundArray[iTempI][iTempJ] = g_backgroundArray[iTempI-1][iTempJ];
				}
			}
			g_socre++;//分数+1
			i++;//因为for循环会每次-1，所以此处+1是让其仍然从该行开始

		}

		nSum = 0;//清零
	}
}
