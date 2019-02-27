#include "stdafx.h"
#include <time.h>


#define SINGLE_SQUARE_SIZE 30 //��������ߴ�
#define VERTICAL_NUM   20   //��ֱ���򷽿���
#define HORIZONTAL_NUM 10	//ˮƽ���򷽿���
//��Ϸ��ʾ����ߴ�
#define DISPLAY_WIDTH  (HORIZONTAL_NUM*SINGLE_SQUARE_SIZE)
#define DISPLAY_HEIGHT (VERTICAL_NUM*SINGLE_SQUARE_SIZE)


#define TIMERID 1234


//��ʼ��һЩ����
void onCreate();


//������ͼ
void onPaint(HDC hdc);
//������
void paintScore(HDC hMemDc);
//������  ��ΪHDC�ǵ�ַ�����Բ���ʹ������
void paintSquare(HDC hMemDc);
//�����������,��7��
int createRandomSquare();
//�����������������
void copySquareToBack();


//ʹ��������
void squareDown();
//ʹ��������
void squareLeft();
//ʹ��������
void squareRight();


//�س���������
void keyReturnProc(HWND hWnd);
//��ʱ��������
void onTimerProc(HWND hWnd);
//���������
void onLeftProc(HWND hWnd);
//�Ҽ�������
void onRightProc(HWND hWnd);
//�¼�������
void onDownProc(HWND hWnd);
//���Σ����ϼ�������
void onChangeProc(HWND hWnd);


//��������ƶ�������1,���򷵻�0
//�˺������ж�����ķ����Ƿ��˶���ֹͣ�ķ����Ϸ�
int canSquareDown();
//�˺������ж����Ƶķ����Ƿ��˶���ֹͣ�ķ����ұ�
int canSquareLeft();
//�˺������ж����Ƶķ����Ƿ��˶���ֹͣ�ķ������
int canSquareRight();
//�˺����Ƿ�ֹ�˶��ķ�����λ�Ӱ���Ѿ�ֹͣ�ķ���
//�ͷ����Ѿ�����߽磬g_xIndex<0��g_xIndex+2 >9�������
//���ֹ�����������ͼ�ڶ������������0�Ѿ������߽磩
//1 1 2    0 1 0 
//0 1 2    0 1 1 
//0 1 2    0 1 0
int canSquareChange();

//Ϊ���жϳ��������Ƿ���Ա���
int canLongSquareChange();

//���δ����߽磬����1,���򷵻�0
//��������Ƿ�ֹ�������䳬���±߽�
int IsSquareReachBottom();
//��������Ƿ�ֹ�������Ƴ�����߽�
int IsSquareReachLeft();
//��������Ƿ�ֹ�������Ƴ����ұ߽�
int IsSquareReachRight();

int IsGameOver();

//��ͣ�µķ�����ֵ��Ϊ2(���������������Ե�1���2)�������²����ķ����޷�����
void change1To2();

//�仯0-4����5�ַ������״
void change0To4SquareShape();


//�仯6��������
void changeLongSquareShape();

void destoryOneLineSquare();
