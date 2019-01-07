// AfmMessage.h
// Afm����ͨ�Ų���Ϣ����
#pragma once

#include <qt_windows.h>
#pragma comment(lib, "user32.lib")

/******************* ��ϢID *******************/

#define AFM_MSG						(WM_USER+100)	// �û���Ϣ��׼ID

// �����򷢸�GUI����Ϣ
#define AFM_MSG_PG_FOUR_QUAD_DATA			(AFM_MSG+1)		// 10������������
#define AFM_MSG_PG_SCAN_DATA				(AFM_MSG+2)		// 11��ɨ������
#define AFM_MSG_PG_OVER_LINE				(AFM_MSG+3)		// һ��ɨ�����
#define AFM_MSG_PG_SCAN_OVER				(AFM_MSG+4)		// ɨ�����
#define AFM_MSG_PG_PROBE_COOR				(AFM_MSG+5)		// ̽�������
#define AFM_MSG_PG_SAMPLE_COOR				(AFM_MSG+6)		// ��Ʒ̨����
#define AFM_MSG_PG_GET_CCD_IMG				(AFM_MSG+7)		// ��ȡCCDͼ��
#define AFM_MSG_PG_RESET_OVER				(AFM_MSG+8)		// �������
#define AFM_MSG_PG_DROP_PROBE_OVER			(AFM_MSG+9)		// �������
//#define AFM_MSG_PG_DROP_PROBE_OVER	(AFM_MSG+9)		// �Զ��������

// GUI�������������Ϣ
#define AFM_MSG_GP_SATRT_DEVICE				(AFM_MSG+11)	// 1�������豸
#define AFM_MSG_GP_DROP_PROBE				(AFM_MSG+12)	// 2��4 ����
#define AFM_MSG_GP_START_SCAN				(AFM_MSG+13)	// 5����ʼɨ��
#define AFM_MSG_GP_GET_PROBE_COOR			(AFM_MSG+14)	// ��ȡ̽�������
#define AFM_MSG_GP_GET_SAMPLE_COOR			(AFM_MSG+15)	// ��ȡ��Ʒ̨����
#define AFM_MSG_GP_SET_PID					(AFM_MSG+16)	// 8������PID
#define AFM_MSG_GP_SET_PSD_THRESHOLD		(AFM_MSG+17)	// 9������PSD����ֵ
#define AFM_MSG_GP_RESET					(AFM_MSG+18)	// 6������
#define AFM_MSG_GP_MOVE_SAMPLE				(AFM_MSG+19)	// 3���ƶ���Ʒ̨��΢�ף�
#define AFM_MSG_GP_STOP_SCAN				(AFM_MSG+20)	// 7��ֹͣɨ��
#define AFM_MSG_GP_SHOW_WINDOW				(AFM_MSG+21)	// ��ʾ����
#define AFM_MSG_GP_RAISE_PROBE				(AFM_MSG+22)	// ����


/******************* ��Ϣ���� *******************/

#define AFM_MSG_PARAM(MsgID) MsgID##_PARAM

// ����������
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA)
{
    float up_down;		// ����λ��
    float left_right;	// ����λ��
    float sum;			// 0~3000 �ܹ�ǿ -1 ��߳���4����
};

// ɨ������
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA)
{
    int x;			// x��������
    int y;			// y��������
    float h;		// �߶�ֵ
    float f;		// ��������ֵ
    float yang;		// ����ģģ��
};

// һ��ɨ�����
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_OVER_LINE){ ; };

// ɨ�����
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SCAN_OVER){ ; };

// ̽�������
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR)
{
    int x;			// x��������
    int y;			// y��������
    int z;			// z��������
};

// ��Ʒ̨����
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR)
{
    int x;			// x��������
    int y;			// y��������
    int z;			// z��������
};

// ��ȡCCDͼ��
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_GET_CCD_IMG){ ; };

// �������
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_RESET_OVER){ ; };

// �Զ��������
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_DROP_PROBE_OVER)
{
    unsigned int type;	// 1:�ֽ�������� 2:����������� 3:�쳣������
};

// �����豸
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SATRT_DEVICE){ ; };

// �Զ�����
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_DROP_PROBE)
{
    unsigned int type;	// 1:�ֽ��룻 2:������
};

// ��ʼɨ��
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_START_SCAN){ ; };

// ��ȡ̽�������
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_GET_PROBE_COOR){ ; };

// ��ȡ��Ʒ̨����
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_GET_SAMPLE_COOR){ ; };

// ����PID
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SET_PID)
{
    float P;	// ����P
    float I;	// ����I
    float D;	// ����D
};

// ����PSD����ֵ
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SET_PSD_THRESHOLD)
{
    float value;	// PSD����ֵ
};

// ����
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_RESET){ ; };

// �ƶ���Ʒ̨��΢�ף�
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_MOVE_SAMPLE)
{
    unsigned int direction;	// �˶����� 1:X������; 2:X������; 3:Y������; 4:Y������; 5:Z������; 6:Z������
};

// ��ʼɨ��
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_STOP_SCAN){ ; };

// ��ʾ����
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SHOW_WINDOW)
{
    bool bShow;	// �Ƿ���ʾ���� 0������ʾ�� 1����ʾ
};

typedef struct AFM_MSG_PARAM(AFM_MSG_GP_RAISE_PROBE){ ; };

typedef union AFM_MSG_PARAM
{
    AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA)			FourQuardDataParam;
    AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA)					ScanDataParam;
    AFM_MSG_PARAM(AFM_MSG_PG_OVER_LINE)					OverLineParam;
    AFM_MSG_PARAM(AFM_MSG_PG_SCAN_OVER)					OverScanParam;
    AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR)				ProbeCoorParam;
    AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR)				SampleCoorParam;
    AFM_MSG_PARAM(AFM_MSG_PG_GET_CCD_IMG)				GetCCDImgParam;
    AFM_MSG_PARAM(AFM_MSG_PG_RESET_OVER)				ResetOverParam;
    AFM_MSG_PARAM(AFM_MSG_PG_DROP_PROBE_OVER)	AutoAdjustProbeOverParam;

    AFM_MSG_PARAM(AFM_MSG_GP_SATRT_DEVICE)				StartDeviceParam;
    AFM_MSG_PARAM(AFM_MSG_GP_DROP_PROBE)				DropProbeParam;
    AFM_MSG_PARAM(AFM_MSG_GP_START_SCAN)				StartScanParam;
    AFM_MSG_PARAM(AFM_MSG_GP_GET_PROBE_COOR)			GetProbeCoorParam;
    AFM_MSG_PARAM(AFM_MSG_GP_GET_SAMPLE_COOR)			GetSampleCoorParam;
    AFM_MSG_PARAM(AFM_MSG_GP_SET_PID)					SetPIDParam;
    AFM_MSG_PARAM(AFM_MSG_GP_SET_PSD_THRESHOLD)			SetPsdThresholdgParam;
    AFM_MSG_PARAM(AFM_MSG_GP_RESET)						ResetParam;
    AFM_MSG_PARAM(AFM_MSG_GP_MOVE_SAMPLE)				MoveSampleParam;
    AFM_MSG_PARAM(AFM_MSG_GP_STOP_SCAN)					StoptScanParam;
};

#define AMF_MSG_PARAM_MAX_SIZE sizeof(AFM_MSG_PARAM)

/******************* ��Ϣ��Ӧ����ָ�����Ͷ��� *******************/

#define AFM_MSG_FUNC(MsgID) PF_##MsgID

typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_FOUR_QUAD_DATA))(AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_SCAN_DATA))(AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_OVER_LINE))(AFM_MSG_PARAM(AFM_MSG_PG_OVER_LINE));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_SCAN_OVER))(AFM_MSG_PARAM(AFM_MSG_PG_SCAN_OVER));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_PROBE_COOR))(AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_SAMPLE_COOR))(AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_GET_CCD_IMG))(AFM_MSG_PARAM(AFM_MSG_PG_GET_CCD_IMG));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_RESET_OVER))(AFM_MSG_PARAM(AFM_MSG_PG_RESET_OVER));
typedef void(*AFM_MSG_FUNC(AFM_MSG_PG_DROP_PROBE_OVER))(AFM_MSG_PARAM(AFM_MSG_PG_DROP_PROBE_OVER));

typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_SATRT_DEVICE))(AFM_MSG_PARAM(AFM_MSG_GP_SATRT_DEVICE));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_DROP_PROBE))(AFM_MSG_PARAM(AFM_MSG_GP_DROP_PROBE));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_START_SCAN))(AFM_MSG_PARAM(AFM_MSG_GP_START_SCAN));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_GET_PROBE_COOR))(AFM_MSG_PARAM(AFM_MSG_GP_GET_PROBE_COOR));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_GET_SAMPLE_COOR))(AFM_MSG_PARAM(AFM_MSG_GP_GET_SAMPLE_COOR));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_SET_PID))(AFM_MSG_PARAM(AFM_MSG_GP_SET_PID));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_SET_PSD_THRESHOLD))(AFM_MSG_PARAM(AFM_MSG_GP_SET_PSD_THRESHOLD));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_RESET))(AFM_MSG_PARAM(AFM_MSG_GP_RESET));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_MOVE_SAMPLE))(AFM_MSG_PARAM(AFM_MSG_GP_MOVE_SAMPLE));
typedef void(*AFM_MSG_FUNC(AFM_MSG_GP_STOP_SCAN))(AFM_MSG_PARAM(AFM_MSG_GP_STOP_SCAN));

#define AFM_MSG_GP_SENT_CCD_IMG		(AFM_MSG+517)	// ����CCDͼ��
#define AFM_MSG_GP_MOVE			    (AFM_MSG+519)	// λ��ƽ̨�ƶ�
#define AFM_MSG_GP_AUTO_END         (AFM_MSG+520)    // �������
#define AFM_MSG_GP_AUTO_PROBE		(AFM_MSG+521)	// �Զ�����

typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SENT_CCD_IMG)
{
    unsigned char* CCDImg;  // CCDͼ��
    int height;             // ͼ��߶�
    int width;              // ͼ����
};

// λ��ƽ̨�ƶ�
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_MOVE)
{
     AFM_MSG_PARAM(AFM_MSG_GP_MOVE)(int a)
     {
         movePos= a;
     }
    int movePos; //�������� 0123
};


typedef struct AFM_MSG_PARAM(AFM_MSG_GP_AUTO_END)
{
    int success; //�����Ƿ�ɹ�
};
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_AUTO_PROBE)
{};
