#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include "tools.h"

void Graphics_Init(void);
void Init_Graphics(void);
void Icon_Init(void);
void Text_Init(void);
void Open_Menu(void);
void Close_Menu(void);
void Mouse_Detection(void);
void Menu_Text(void);
void Menu_Mouse_Detection(void);
void Home_Photo(void);
void Menu(void); 
void Menu_Graphics(void);
void Monitoring(void);
void Clear(void);//清屏函数
void Statistical_Analysis(void);
//void Warning(void);  //这个坏掉了

static bool flag = false;

int main(void)
{
	
	Init_Graphics();
	while (1)
	{
		Mouse_Detection();
		//static bool Mouse_Flag = false;
		if (flag == true)
		{
			break;
			return 0;
		}
	}
	//_getch();							// 按任意键继续
	//closegraph();						// 关闭绘图窗口
	
	
 }

void Graphics_Init(void)				//绘制背景色
{
	setfillcolor(RGB(41, 57, 69));
	solidrectangle(0, 40, 210, 1080);


	//setlinecolor(RGB(0, 191, 255));	// 设置绘图色为浅蓝色
	
	int Bottom_Origin_Y_Coordinate = 160;//菜单栏的初始Y坐标
	int Top_Origin_Y_Coordinate = 120;
	for (int i = 0; i < 8; i ++)
	{
		const int Top_Left_X_Coordinate = 0;		
		const int Bottom_Right_X_Coordinate = 210;
		fillrectangle(Top_Left_X_Coordinate, Top_Origin_Y_Coordinate, Bottom_Right_X_Coordinate, Bottom_Origin_Y_Coordinate);
		Bottom_Origin_Y_Coordinate += 40;
		Top_Origin_Y_Coordinate += 40;
	}

}

void Menu_Graphics(void)
{
	int Bottom_Origin_Y_Coordinate = 160;//菜单栏的初始Y坐标
	int Top_Origin_Y_Coordinate = 120;
	for (int i = 0; i < 8; i++)
	{
		const int Top_Left_X_Coordinate = 0;
		const int Bottom_Right_X_Coordinate = 210;
		fillrectangle(Top_Left_X_Coordinate, Top_Origin_Y_Coordinate, Bottom_Right_X_Coordinate, Bottom_Origin_Y_Coordinate);
		Bottom_Origin_Y_Coordinate += 40;
		Top_Origin_Y_Coordinate += 40;
	}

}
void Menu(void)
{
	Graphics_Init();
	Icon_Init();
	Text_Init();
	Menu_Text();
	
}
void Icon_Init(void)
{
	IMAGE Set_Icon, Logout_Icon, Admin_Icon;
	loadimage(&Admin_Icon, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\11.jpg"));
	loadimage(&Set_Icon, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\780(1).jpg"));
	loadimage(&Logout_Icon, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\781(1).png"));
	putimage(129, 83, &Set_Icon);
	putimage(70, 83, &Logout_Icon);
	putimage(12, 54, &Admin_Icon);
}

void Text_Init(void)
{
	wchar_t Admin[] = L"管理员";
	wchar_t Logout[] = L"注销";
	wchar_t Set[] = L"设置";

	setbkmode(TRANSPARENT);			//设置当前设备图案填充和文字输出时的背景模式。
	outtextxy(70, 60, Admin);
	outtextxy(93, 85, Logout);
	outtextxy(154, 85, Set);
}
void Init_Graphics(void)
{
	initgraph(1920, 1080);		       // 创建绘图窗口，大小为 640x480 像素
	setbkcolor(WHITE);			       // 设置背景色为白色
	cleardevice();					   // 用背景色清空屏幕

	setfillcolor(RGB(48, 156, 202));   //绘制蓝色窗口头
	solidrectangle(200, 0, 1920, 40);  // 画无边框的填充矩形。

	setfillcolor(RGB(35, 123, 166));
	solidrectangle(0, 0, 210, 40);		//绘制标题背景蓝色矩形

	wchar_t Tirtle[] = L"智能船舶管理系统";
	setbkmode(TRANSPARENT);			    //设置当前设备图案填充和文字输出时的背景模式。
	outtextxy(33, 14, Tirtle);          //绘制标题

	IMAGE Menu_Icon;
	loadimage(&Menu_Icon, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\782.jpg")); 
	putimage(211, 1, &Menu_Icon);       //40*40,绘制菜单栏图标

	Home_Photo();

	/*wchar_t Roll[] = L"ROLL AND PITCH";
	setbkmode(TRANSPARENT);			//设置当前设备图案填充和文字输出时的背景模式。
	outtextxy(200, 360, Roll);
	*/

}

void Home_Photo(void)
{
	IMAGE Location;
	loadimage(&Location, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\783.png"));//GPS坐标
	putimage(211, 40, &Location);

	IMAGE ROLL;
	loadimage(&ROLL, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\999.png"));   //偏航
	putimage(211, 340, &ROLL);

	IMAGE Map;
	loadimage(&Map, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\111.png"));    //地图
	putimage(811, 40, &Map);

	IMAGE Speed;
	loadimage(&Speed, _T("C:\\Users\\ASUS\\Desktop\\智能船舶界面\\智能船舶界面\\res\\25.png"));	//速度图
	putimage(850, 540, &Speed);

}

void Close_Menu(void)
{
	
	setfillcolor(WHITE);
	solidrectangle(0, 40, 210, 1080);
	//flag = true;

}

void Mouse_Detection(void)
{
	ExMessage Mouse_Mes;				//这个结构体用于保存鼠标消息
	//static bool Mouse_Flag = true;
	while (peekmessage(&Mouse_Mes)) //当检测到鼠标消息后peekmessage返回true
	{
		switch (Mouse_Mes.message)
		{
		case WM_LBUTTONDOWN:
			
			if (Mouse_Mes.x > 210 && Mouse_Mes.x < 250 && Mouse_Mes.y > 1 && Mouse_Mes.y < 41)
			{

				Graphics_Init();
				Icon_Init();
				Text_Init();
				Menu_Text();

				Home_Photo();
				
				/*if (Mouse_Flag == false)
				{
					Close_Menu();
					Home_Photo();
					Mouse_Flag = true;
				}*/
			}

			

			else if ((Mouse_Mes.x > 210 && Mouse_Mes.x < 1920 && Mouse_Mes.y > 40 && Mouse_Mes.y < 1080) || (Mouse_Mes.x > 210 && Mouse_Mes.x < 250 && Mouse_Mes.y > 1 && Mouse_Mes.y < 41))
			{
				Close_Menu();
				Home_Photo();
				
				//Mouse_Flag = true;
			}
			else if (Mouse_Mes.x > 70 && Mouse_Mes.x < 120 && Mouse_Mes.y > 83 && Mouse_Mes.y < 103)
			{
				closegraph();
				flag = false;

			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 120 && Mouse_Mes.y < 160)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 120}, {210, 120}, {230, 140},  {210, 160}, {0, 160} };
				solidpolygon(Point, 5);
				wchar_t Home_Page[] = L"首页";
				setbkmode(TRANSPARENT);
				outtextxy(50, 133, Home_Page);
				

			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 160 && Mouse_Mes.y < 200)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 160}, {210, 160}, {230, 180},  {210, 200}, {0, 200} };
				solidpolygon(Point, 5);
				wchar_t Ship_Monitoring[] = L"船舶监测";
				setbkmode(TRANSPARENT);
				outtextxy(50, 173, Ship_Monitoring);
				Monitoring();
			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 250 && Mouse_Mes.y > 200 && Mouse_Mes.y < 240)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 200}, {210, 200}, {230, 220},  {210, 240}, {0, 240} };
				solidpolygon(Point, 5);
				wchar_t Log_Management[] = L"日志管理";
				setbkmode(TRANSPARENT);
				outtextxy(50, 213, Log_Management);
			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 240 && Mouse_Mes.y < 280)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 240}, {210, 240}, {230, 260},  {210, 280}, {0, 280} };
				solidpolygon(Point, 5);
				wchar_t Statistic_Analysis[] = L"统计分析";
				setbkmode(TRANSPARENT);
				outtextxy(50, 253, Statistic_Analysis);
				Statistical_Analysis();
			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 280 && Mouse_Mes.y < 320)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 280}, {210, 280}, {230, 300},  {210, 320}, {0, 320} };
				solidpolygon(Point, 5);
				wchar_t Early_Warning[] = L"预警告警";
				setbkmode(TRANSPARENT);
				outtextxy(50, 293, Early_Warning);
				IMAGE Warning;
				loadimage(&Warning, _T("C:\\Users\\ASUS\\Desktop\\智能船舶素材\\114.png"));   //偏航
				putimage(210, 40, &Warning);

			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 320 && Mouse_Mes.y < 360)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 320}, {210, 320}, {230, 340},  {210, 360}, {0, 360} };
				solidpolygon(Point, 5);
				wchar_t Energy_Management[] = L"能耗监控";//
				setbkmode(TRANSPARENT);
				outtextxy(50, 333, Energy_Management);
			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 360 && Mouse_Mes.y < 400)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 360}, {210, 360}, {230, 380},  {210, 400}, {0, 400} };
				solidpolygon(Point, 5);
				wchar_t Ship_Management[] = L"船舶管理";
				setbkmode(TRANSPARENT);
				outtextxy(50, 373, Ship_Management);
			}
			else if (Mouse_Mes.x > 0 && Mouse_Mes.x < 210 && Mouse_Mes.y > 400 && Mouse_Mes.y < 440)
			{
				Clear();
				Home_Photo();
				Menu();
				setfillcolor(RGB(35, 123, 166));
				POINT Point[] = { {0, 400}, {210, 400}, {230, 420},  {210, 440}, {0, 440} };
				solidpolygon(Point, 5);
				wchar_t Report_Center[] = L"报表中心";
				setbkmode(TRANSPARENT);
				outtextxy(50, 413, Report_Center);
			}
			break;
		}
		//Mouse_Flag = !Mouse_Flag;//->false

	}
}



void Menu_Mouse_Detection(void)
{
	ExMessage Menu_Mouse_Mes;
	while (peekmessage(&Menu_Mouse_Mes))
	{
		//switch (Menu_Mouse_Mes.message)
			//case WM_LBUTTONDOWN:

	}
}


void Menu_Text(void)
{
	wchar_t Home_Page[] = L"首页";
	wchar_t Ship_Monitoring[] = L"船舶监测";
	wchar_t Log_Management[] = L"日志管理";
	wchar_t Statistic_Analysis[] = L"统计分析";
	wchar_t Early_Warning[] = L"预警告警";
	wchar_t Energy_Management[] = L"能耗监控";
	wchar_t Ship_Management[] = L"船舶管理";
	wchar_t Report_Center[] = L"报表中心";

	int Bottom_Origin_X_Coordinate =50;//菜单栏的初始Y坐标
	int Top_Origin_Y_Coordinate = 133;

	setbkmode(TRANSPARENT);			//设置当前设备图案填充和文字输出时的背景模式。
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Home_Page);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Ship_Monitoring);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Log_Management);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Statistic_Analysis);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Early_Warning);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Energy_Management);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Ship_Management);
	Top_Origin_Y_Coordinate += 40;
	outtextxy(Bottom_Origin_X_Coordinate, Top_Origin_Y_Coordinate, Report_Center);
		
}

void Monitoring(void)
{
	IMAGE Ship_Monitoring;
	loadimage(&Ship_Monitoring, _T("C:\\Users\\ASUS\\Desktop\\智能船舶素材\\3.jpg"));   //偏航
	putimage(210, 40, &Ship_Monitoring);
}

void Statistical_Analysis(void)
{
	IMAGE Statistical_Analysis;
	loadimage(&Statistical_Analysis, _T("C:\\Users\\ASUS\\Desktop\\智能船舶素材\\6.jpg"));   //偏航
	putimage(210, 40, &Statistical_Analysis);
}



void Clear(void)
{
	POINT Clear[] = { {210, 40}, {1920, 40}, {1920, 1080}, {210, 1080} };
	clearpolygon(Clear, 4);
}