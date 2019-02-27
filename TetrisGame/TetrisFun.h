#include "stdafx.h"
#include <time.h>


#define SINGLE_SQUARE_SIZE 30 //单个方块尺寸
#define VERTICAL_NUM   20   //竖直方向方块数
#define HORIZONTAL_NUM 10	//水平方向方块数
//游戏显示界面尺寸
#define DISPLAY_WIDTH  (HORIZONTAL_NUM*SINGLE_SQUARE_SIZE)
#define DISPLAY_HEIGHT (VERTICAL_NUM*SINGLE_SQUARE_SIZE)


#define TIMERID 1234


//初始化一些操作
void onCreate();


//画背景图
void onPaint(HDC hdc);
//画分数
void paintScore(HDC hMemDc);
//画方块  因为HDC是地址，所以不用使用引用
void paintSquare(HDC hMemDc);
//产生随机方块,共7个
int createRandomSquare();
//将随机块贴到背景上
void copySquareToBack();


//使方块下落
void squareDown();
//使方块左移
void squareLeft();
//使方块右移
void squareRight();


//回车键处理函数
void keyReturnProc(HWND hWnd);
//定时器处理函数
void onTimerProc(HWND hWnd);
//左键处理函数
void onLeftProc(HWND hWnd);
//右键处理函数
void onRightProc(HWND hWnd);
//下键处理函数
void onDownProc(HWND hWnd);
//变形，即上键处理函数
void onChangeProc(HWND hWnd);


//如果可以移动，返回1,否则返回0
//此函数是判断下落的方块是否运动到停止的方块上方
int canSquareDown();
//此函数是判断左移的方块是否运动到停止的方块右边
int canSquareLeft();
//此函数是判断右移的方块是否运动到停止的方块左边
int canSquareRight();
//此函数是防止运动的方块变形会影响已经停止的方块
//和方块已经到达边界，g_xIndex<0或g_xIndex+2 >9的情况。
//如防止下面情况（下图第二个，左侧三个0已经超出边界）
//1 1 2    0 1 0 
//0 1 2    0 1 1 
//0 1 2    0 1 0
int canSquareChange();

//为了判断长条方块是否可以变形
int canLongSquareChange();

//如果未到达边界，返回1,否则返回0
//这个函数是防止方块下落超出下边界
int IsSquareReachBottom();
//这个函数是防止方块左移超出左边界
int IsSquareReachLeft();
//这个函数是防止方块右移超出右边界
int IsSquareReachRight();

int IsGameOver();

//将停下的方块数值改为2(即背景数组里所以的1变成2)，否则新产生的方块无法下落
void change1To2();

//变化0-4，共5种方块的形状
void change0To4SquareShape();


//变化6，即长条
void changeLongSquareShape();

void destoryOneLineSquare();
