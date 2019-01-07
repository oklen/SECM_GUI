// AfmMessage.h
// Afm程序通信层消息定义
#pragma once

#include <qt_windows.h>
#pragma comment(lib, "user32.lib")

/******************* 消息ID *******************/

#define AFM_MSG						(WM_USER+100)	// 用户消息基准ID

// 检测程序发给GUI的消息
#define AFM_MSG_PG_FOUR_QUAD_DATA			(AFM_MSG+1)		// 10、四象限数据
#define AFM_MSG_PG_SCAN_DATA				(AFM_MSG+2)		// 11、扫描数据
#define AFM_MSG_PG_OVER_LINE				(AFM_MSG+3)		// 一行扫描结束
#define AFM_MSG_PG_SCAN_OVER				(AFM_MSG+4)		// 扫描结束
#define AFM_MSG_PG_PROBE_COOR				(AFM_MSG+5)		// 探针架坐标
#define AFM_MSG_PG_SAMPLE_COOR				(AFM_MSG+6)		// 样品台坐标
#define AFM_MSG_PG_GET_CCD_IMG				(AFM_MSG+7)		// 获取CCD图像
#define AFM_MSG_PG_RESET_OVER				(AFM_MSG+8)		// 重置完成
#define AFM_MSG_PG_DROP_PROBE_OVER			(AFM_MSG+9)		// 进针结束
//#define AFM_MSG_PG_DROP_PROBE_OVER	(AFM_MSG+9)		// 自动对针完成

// GUI发给检测程序的消息
#define AFM_MSG_GP_SATRT_DEVICE				(AFM_MSG+11)	// 1、启动设备
#define AFM_MSG_GP_DROP_PROBE				(AFM_MSG+12)	// 2、4 进针
#define AFM_MSG_GP_START_SCAN				(AFM_MSG+13)	// 5、开始扫描
#define AFM_MSG_GP_GET_PROBE_COOR			(AFM_MSG+14)	// 获取探针架坐标
#define AFM_MSG_GP_GET_SAMPLE_COOR			(AFM_MSG+15)	// 获取样品台坐标
#define AFM_MSG_GP_SET_PID					(AFM_MSG+16)	// 8、设置PID
#define AFM_MSG_GP_SET_PSD_THRESHOLD		(AFM_MSG+17)	// 9、设置PSD门限值
#define AFM_MSG_GP_RESET					(AFM_MSG+18)	// 6、重置
#define AFM_MSG_GP_MOVE_SAMPLE				(AFM_MSG+19)	// 3、移动样品台（微米）
#define AFM_MSG_GP_STOP_SCAN				(AFM_MSG+20)	// 7、停止扫描
#define AFM_MSG_GP_SHOW_WINDOW				(AFM_MSG+21)	// 显示窗口
#define AFM_MSG_GP_RAISE_PROBE				(AFM_MSG+22)	// 退针


/******************* 消息参数 *******************/

#define AFM_MSG_PARAM(MsgID) MsgID##_PARAM

// 四象限数据
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_FOUR_QUAD_DATA)
{
    float up_down;		// 上下位置
    float left_right;	// 左右位置
    float sum;			// 0~3000 总光强 -1 光斑超出4象限
};

// 扫描数据
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SCAN_DATA)
{
    int x;			// x方向坐标
    int y;			// y方向坐标
    float h;		// 高度值
    float f;		// 反馈力度值
    float yang;		// 杨氏模模量
};

// 一行扫描结束
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_OVER_LINE){ ; };

// 扫描结束
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SCAN_OVER){ ; };

// 探针架坐标
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_PROBE_COOR)
{
    int x;			// x方向坐标
    int y;			// y方向坐标
    int z;			// z方向坐标
};

// 样品台坐标
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_SAMPLE_COOR)
{
    int x;			// x方向坐标
    int y;			// y方向坐标
    int z;			// z方向坐标
};

// 获取CCD图像
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_GET_CCD_IMG){ ; };

// 重置完成
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_RESET_OVER){ ; };

// 自动对针完成
typedef struct AFM_MSG_PARAM(AFM_MSG_PG_DROP_PROBE_OVER)
{
    unsigned int type;	// 1:粗进针结束； 2:精进针结束； 3:异常结束；
};

// 启动设备
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SATRT_DEVICE){ ; };

// 自动进针
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_DROP_PROBE)
{
    unsigned int type;	// 1:粗进针； 2:精进针
};

// 开始扫描
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_START_SCAN){ ; };

// 获取探针架坐标
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_GET_PROBE_COOR){ ; };

// 获取样品台坐标
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_GET_SAMPLE_COOR){ ; };

// 设置PID
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SET_PID)
{
    float P;	// 参数P
    float I;	// 参数I
    float D;	// 参数D
};

// 设置PSD门限值
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SET_PSD_THRESHOLD)
{
    float value;	// PSD门限值
};

// 重置
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_RESET){ ; };

// 移动样品台（微米）
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_MOVE_SAMPLE)
{
    unsigned int direction;	// 运动方向 1:X正方向; 2:X负方向; 3:Y正方向; 4:Y负方向; 5:Z正方向; 6:Z负方向
};

// 开始扫描
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_STOP_SCAN){ ; };

// 显示窗口
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SHOW_WINDOW)
{
    bool bShow;	// 是否显示窗口 0：不显示； 1：显示
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

/******************* 消息响应函数指针类型定义 *******************/

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

#define AFM_MSG_GP_SENT_CCD_IMG		(AFM_MSG+517)	// 发送CCD图像
#define AFM_MSG_GP_MOVE			    (AFM_MSG+519)	// 位移平台移动
#define AFM_MSG_GP_AUTO_END         (AFM_MSG+520)    // 进针结束
#define AFM_MSG_GP_AUTO_PROBE		(AFM_MSG+521)	// 自动进针

typedef struct AFM_MSG_PARAM(AFM_MSG_GP_SENT_CCD_IMG)
{
    unsigned char* CCDImg;  // CCD图像
    int height;             // 图像高度
    int width;              // 图像宽度
};

// 位移平台移动
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_MOVE)
{
     AFM_MSG_PARAM(AFM_MSG_GP_MOVE)(int a)
     {
         movePos= a;
     }
    int movePos; //上下左右 0123
};


typedef struct AFM_MSG_PARAM(AFM_MSG_GP_AUTO_END)
{
    int success; //进针是否成功
};
typedef struct AFM_MSG_PARAM(AFM_MSG_GP_AUTO_PROBE)
{};
