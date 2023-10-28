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
void Clear(void);//��������
void Statistical_Analysis(void);
//void Warning(void);  //���������

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
	//_getch();							// �����������
	//closegraph();						// �رջ�ͼ����
	
	
 }

void Graphics_Init(void)				//���Ʊ���ɫ
{
	setfillcolor(RGB(41, 57, 69));
	solidrectangle(0, 40, 210, 1080);


	//setlinecolor(RGB(0, 191, 255));	// ���û�ͼɫΪǳ��ɫ
	
	int Bottom_Origin_Y_Coordinate = 160;//�˵����ĳ�ʼY����
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
	int Bottom_Origin_Y_Coordinate = 160;//�˵����ĳ�ʼY����
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
	loadimage(&Admin_Icon, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\11.jpg"));
	loadimage(&Set_Icon, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\780(1).jpg"));
	loadimage(&Logout_Icon, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\781(1).png"));
	putimage(129, 83, &Set_Icon);
	putimage(70, 83, &Logout_Icon);
	putimage(12, 54, &Admin_Icon);
}

void Text_Init(void)
{
	wchar_t Admin[] = L"����Ա";
	wchar_t Logout[] = L"ע��";
	wchar_t Set[] = L"����";

	setbkmode(TRANSPARENT);			//���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ��
	outtextxy(70, 60, Admin);
	outtextxy(93, 85, Logout);
	outtextxy(154, 85, Set);
}
void Init_Graphics(void)
{
	initgraph(1920, 1080);		       // ������ͼ���ڣ���СΪ 640x480 ����
	setbkcolor(WHITE);			       // ���ñ���ɫΪ��ɫ
	cleardevice();					   // �ñ���ɫ�����Ļ

	setfillcolor(RGB(48, 156, 202));   //������ɫ����ͷ
	solidrectangle(200, 0, 1920, 40);  // ���ޱ߿�������Ρ�

	setfillcolor(RGB(35, 123, 166));
	solidrectangle(0, 0, 210, 40);		//���Ʊ��ⱳ����ɫ����

	wchar_t Tirtle[] = L"���ܴ�������ϵͳ";
	setbkmode(TRANSPARENT);			    //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ��
	outtextxy(33, 14, Tirtle);          //���Ʊ���

	IMAGE Menu_Icon;
	loadimage(&Menu_Icon, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\782.jpg")); 
	putimage(211, 1, &Menu_Icon);       //40*40,���Ʋ˵���ͼ��

	Home_Photo();

	/*wchar_t Roll[] = L"ROLL AND PITCH";
	setbkmode(TRANSPARENT);			//���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ��
	outtextxy(200, 360, Roll);
	*/

}

void Home_Photo(void)
{
	IMAGE Location;
	loadimage(&Location, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\783.png"));//GPS����
	putimage(211, 40, &Location);

	IMAGE ROLL;
	loadimage(&ROLL, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\999.png"));   //ƫ��
	putimage(211, 340, &ROLL);

	IMAGE Map;
	loadimage(&Map, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\111.png"));    //��ͼ
	putimage(811, 40, &Map);

	IMAGE Speed;
	loadimage(&Speed, _T("C:\\Users\\ASUS\\Desktop\\���ܴ�������\\���ܴ�������\\res\\25.png"));	//�ٶ�ͼ
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
	ExMessage Mouse_Mes;				//����ṹ�����ڱ��������Ϣ
	//static bool Mouse_Flag = true;
	while (peekmessage(&Mouse_Mes)) //����⵽�����Ϣ��peekmessage����true
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
				wchar_t Home_Page[] = L"��ҳ";
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
				wchar_t Ship_Monitoring[] = L"�������";
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
				wchar_t Log_Management[] = L"��־����";
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
				wchar_t Statistic_Analysis[] = L"ͳ�Ʒ���";
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
				wchar_t Early_Warning[] = L"Ԥ���澯";
				setbkmode(TRANSPARENT);
				outtextxy(50, 293, Early_Warning);
				IMAGE Warning;
				loadimage(&Warning, _T("C:\\Users\\ASUS\\Desktop\\���ܴ����ز�\\114.png"));   //ƫ��
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
				wchar_t Energy_Management[] = L"�ܺļ��";//
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
				wchar_t Ship_Management[] = L"��������";
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
				wchar_t Report_Center[] = L"��������";
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
	wchar_t Home_Page[] = L"��ҳ";
	wchar_t Ship_Monitoring[] = L"�������";
	wchar_t Log_Management[] = L"��־����";
	wchar_t Statistic_Analysis[] = L"ͳ�Ʒ���";
	wchar_t Early_Warning[] = L"Ԥ���澯";
	wchar_t Energy_Management[] = L"�ܺļ��";
	wchar_t Ship_Management[] = L"��������";
	wchar_t Report_Center[] = L"��������";

	int Bottom_Origin_X_Coordinate =50;//�˵����ĳ�ʼY����
	int Top_Origin_Y_Coordinate = 133;

	setbkmode(TRANSPARENT);			//���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ��
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
	loadimage(&Ship_Monitoring, _T("C:\\Users\\ASUS\\Desktop\\���ܴ����ز�\\3.jpg"));   //ƫ��
	putimage(210, 40, &Ship_Monitoring);
}

void Statistical_Analysis(void)
{
	IMAGE Statistical_Analysis;
	loadimage(&Statistical_Analysis, _T("C:\\Users\\ASUS\\Desktop\\���ܴ����ز�\\6.jpg"));   //ƫ��
	putimage(210, 40, &Statistical_Analysis);
}



void Clear(void)
{
	POINT Clear[] = { {210, 40}, {1920, 40}, {1920, 1080}, {210, 1080} };
	clearpolygon(Clear, 4);
}