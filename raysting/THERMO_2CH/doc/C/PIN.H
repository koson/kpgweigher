// Ӳ����ض���, �����ʵ��Ӳ���޸ı��ļ�

#include <reg52.h>
#include <intrins.h>
#pragma NOAREGS		// ���MCS51ʹ�ü����жϹ��ܣ���ô�������˱���ѡ��

//#define		ENABLE_2_CH452		1	// ��2�߽ӿ���֧������CH452оƬ����

/* ��ʱ1uS�ӳ���,��Ҫ����2�߽ӿ�,�뵥Ƭ���ٶ��й� */
//#define		DELAY_1US		{}				// MCS51<=10MHz
//#define		DELAY_1US		{_nop_();}		// MCS51<=20MHz
#define		DELAY_1US		{_nop_();_nop_();}	// MCS51<=30MHz

/* 2�߽ӿڵ�����,��ʵ�ʵ�·�й� */
sbit	CH452_SCL=P1^7;
sbit	CH452_SDA=P1^6;   // ���ʹ��������2�߽ӿ�,��ôSDA���ж�����P3^3/INT1,��SDAֱ�����ж����
//sbit	CH452_ADDR=P1^5;  // ʵ�ʵ�·Ӧ��Ӳ����GND����VCC
sbit	CH452_INT=P3^3;   // ��׼��2�߽ӿ�ʹ�ø���������ж�

/* 4�߽ӿڵ�����,��ʵ�ʵ�·�й� */
sbit   CH452_DCLK=P1^7;                     // ��������ʱ�������Ӽ���
sbit   CH452_DIN=P1^6;		                // ���������������CH452����������
sbit   CH452_LOAD=P1^5;                     // ����������أ������Ӽ���
sbit   CH452_DOUT=P3^3;                     // INT1�������жϺͼ�ֵ�������룬��CH452���������

/* 2�߽ӿڵ�λ����,�뵥Ƭ���й� */
#define		CH452_SCL_SET		{CH452_SCL=1;}
#define		CH452_SCL_CLR		{CH452_SCL=0;}
#define		CH452_SCL_D_OUT		{}				// ����SCLΪ�������,����˫��I/O���л�Ϊ���
#define		CH452_SDA_SET		{CH452_SDA=1;}
#define		CH452_SDA_CLR		{CH452_SDA=0;}
#define		CH452_SDA_IN		(CH452_SDA)
#define		CH452_SDA_D_OUT		{}				// ����SDAΪ�������,����˫��I/O���л�Ϊ���
#define		CH452_SDA_D_IN		{CH452_SDA=1;}	// ����SDAΪ���뷽��,����˫��I/O���л�Ϊ����

/* 4�߽ӿڵ�λ����,�뵥Ƭ���й� */
#define		CH452_DCLK_SET		{CH452_DCLK=1;}
#define		CH452_DCLK_CLR		{CH452_DCLK=0;}
#define		CH452_DCLK_D_OUT	{}				// ����DCLKΪ�������,����˫��I/O���л�Ϊ���
#define		CH452_DIN_SET		{CH452_DIN=1;}
#define		CH452_DIN_CLR		{CH452_DIN=0;}
#define		CH452_DIN_D_OUT		{}				// ����DINΪ�������,����˫��I/O���л�Ϊ���
#define		CH452_LOAD_SET		{CH452_LOAD=1;}
#define		CH452_LOAD_CLR		{CH452_LOAD=0;}
#define		CH452_LOAD_D_OUT	{}				// ����LOADΪ�������,����˫��I/O���л�Ϊ���
#define		CH452_DOUT_D_IN		{CH452_DOUT=1;}	// ����DOUTΪ���뷽��,����˫��I/O���л�Ϊ����

/* �뵥Ƭ���й�,���ж����ӷ�ʽ�й� */
//#define		USE_CH452_KEY		1			// ʹ����CH452�İ����ж�
#ifdef USE_CH452_KEY
#define		DISABLE_KEY_INTERRUPT	{EX1=0;}
#define		ENABLE_KEY_INTERRUPT	{EX1=1;}
#define		CLEAR_KEY_INTER_FLAG	{IE1=0;}
#else
#define		DISABLE_KEY_INTERRUPT	{}
#define		ENABLE_KEY_INTERRUPT	{}
#define		CLEAR_KEY_INTER_FLAG	{}
#endif