#include <iostream>
#include <easyx.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#define Over 90
using namespace std;
struct Map
{
	IMAGE Max[999];
};
struct LOPxy
{
	int x; int y;
	int sin;
};
struct Plas
{
	LOPxy Set[Over];
	int vb;
};
struct NelMap
{
	int Ma[3][3];
};
/*Basic AI Function , Developed For C++*/
void JaZaiDongHua()
{
	for (int i = 0; i <= 100; i++) {
		cout << i << endl;
		Sleep(10);
		system("cls");
	}
	return;
}
int ZhuCaiDang(Map *m){
	clearcliprgn();
	loadimage(&m->Max[1], "01.jpg");
	loadimage(&m->Max[2], "02.jpg");
	initgraph(1000, 500, EX_SHOWCONSOLE);
	int Cx=-20; int Cy=-20;
	while (true) 
	{
		Q1:
		BeginBatchDraw();
		//Helloset
		setbkmode(TRANSPARENT);
		putimage(0, 0, &m->Max[1]);
		setcolor(RGB(170, 170, 170));
		circle(300, 500, 40);
		putimage(0, 0, &m->Max[2]);
		settextcolor(WHITE);
		settextstyle(50, NULL, "微软雅黑");
		outtextxy(301, 0, "OperSedr");
		settextstyle(20, NULL, "微软雅黑");
		outtextxy(301, 50, "SL.Ofesstr");
		settextstyle(30, NULL, "微软雅黑");
		settextcolor(BLACK);
		outtextxy(50, 70, "SetGames");
		outtextxy(50, 120, "MultiplayerGame");
		outtextxy(50, 170, "AiPlayerGame");
		outtextxy(50, 220, "MyHome");
		outtextxy(50, 270, "ExitGame");
		/*XunZahoZuzBiaoQiu*/
		circle(Cx,Cy,5);
		EndBatchDraw();
		/*get the msg to ther*/
		if (MouseHit()) 
		{
			MOUSEMSG msg = GetMouseMsg();
			cout << msg.x << " " << msg.y << endl;
			if (msg.x >= 50 && msg.x <= 230 && msg.y >= 70 && msg.y <= 100)
			{Cx = 50, Cy = 70;}
			if (msg.x >= 50 && msg.x <= 230 && msg.y >= 120 && msg.y <= 150)
			{Cx = 50, Cy =120;}
			if (msg.x >= 50 && msg.x <= 230 && msg.y >= 170 && msg.y <= 200)
			{Cx = 50, Cy = 170;}
			if (msg.x >= 50 && msg.x <= 230 && msg.y >= 220 && msg.y <= 250)
			{Cx = 50, Cy = 220;}
			if (msg.x >= 50 && msg.x <= 230 && msg.y >= 270 && msg.y <= 300)
			{Cx = 50, Cy = 270;}
			/*set gitch*/
			switch (msg.uMsg)
			{
			  case WM_LBUTTONDOWN: 
			  {
				if(msg.x>=50&&msg.x<=230&&msg.y>=70&&msg.y<=100)
				{
					cout << "over srt  1" << endl;
					HWND winds = GetHWnd();
					MessageBox(winds,"设置游戏参数","SetGames",MB_OK);
					return 1926;//1926==SetGames
				}
				if (msg.x >= 50 && msg.x <= 230 && msg.y >= 120 && msg.y <= 150)
				{
					cout << "over srt  2" << endl;
					HWND winds = GetHWnd();
					MessageBox(winds, "多人游戏", "MultiplayerGame", MB_OK);
					return 1932;
					//1932==MultiplayerGame;
				}
				if (msg.x >= 50 && msg.x <= 230 && msg.y >= 170 && msg.y <= 200)
				{cout << "over srt  3" << endl;}
				if (msg.x >= 50 && msg.x <= 230 && msg.y >= 220 && msg.y <= 250)
				{
					cout << "over srt  4" << endl;
					HWND winds = GetHWnd();
					MessageBox(winds, "这是个恶作剧", "xxx", MB_OK);
					while (true)
					{
						MessageBox(winds, "这是个恶作剧", "xxx", MB_OK);
					}
				}
				if (msg.x >= 50 && msg.x <= 230 && msg.y >= 270 && msg.y <= 300)
				{
					HWND winds = GetHWnd();
					cout << "over srt  5" << endl;
					MessageBox(winds, "确定退出AIspece？","退出程序",MB_OK);
					return 1914; //ExitGames
				}
				 cout << "oner paset" << endl;
			   }
			}
		}
	}
}
void ChuShi(NelMap *M, Plas *p)
{
	for (int i = 0; i < 3; i++)
	{
		for (int i1 = 0; i1 < 3; i1++)
		{
			M->Ma[i][i1]=0;
		}
	}
	for(int i1=0;i1<=9;i1++)
	{
		p->Set[i1].sin = NULL;
	}
}
int CaiPan(Plas *p, NelMap *M)
{
	for(int i=0;i<3;i++)
	{
		for(int i1=0;i1<3;i1++)
		{
			cout << M->Ma[i][i1]<<" ";
		}
		cout << endl;
	}
	if (M->Ma[0][0] ==1&&M->Ma[0][1] == 1&&M->Ma[0][2]==1)
	{
		return 1990;
	}
	if (M->Ma[0][0] == 5 && M->Ma[0][1] == 5 && M->Ma[0][2] == 5)
	{
		return 1990;
	}
	//2lien
	if (M->Ma[0][0] == 1 && M->Ma[1][0] == 1 && M->Ma[2][0] == 1)
	{
		return 1990;
	}
	if (M->Ma[0][0] == 5 && M->Ma[1][0] == 5 && M->Ma[2][0] == 5)
	{
		return 1990;
	}
	//3line
	if (M->Ma[2][2] == 1 && M->Ma[1][2] == 1 && M->Ma[0][2] == 1)
	{
		return 1990;
	}
	if (M->Ma[2][2] == 5 && M->Ma[1][2] == 5 && M->Ma[0][2] == 5)
	{
		return 1990;
	}
	//4line
	if (M->Ma[2][2] == 1 && M->Ma[2][1] == 1 && M->Ma[2][0] == 1)
	{
		return 1990;
	}
	if (M->Ma[2][2] == 5 && M->Ma[2][1] == 5 && M->Ma[2][0] == 5)
	{
		return 1990;
	}
	//5line
	if (M->Ma[1][1] == 1 && M->Ma[0][1] == 1 && M->Ma[2][1] == 1)
	{
		return 1990;
	}
	if (M->Ma[1][1] == 5 && M->Ma[0][1] == 5 && M->Ma[2][1] == 5)
	{
		return 1990;
	}
	//6line
	if (M->Ma[1][0] == 5 && M->Ma[1][1] == 5 && M->Ma[1][2] == 5)
	{
		return 1990;
	}
	if (M->Ma[1][0] == 1 && M->Ma[1][1] == 1 && M->Ma[1][2] == 1)
	{
		return 1990;
	}
	//7line
	if (M->Ma[0][0] == 1 && M->Ma[1][1] == 1 && M->Ma[2][2] == 1)
	{
		return 1990;
	}
	if (M->Ma[0][0] == 5 && M->Ma[1][1] == 5 && M->Ma[2][2] == 5)
	{
		return 1990;
	}
	//8line
	if (M->Ma[0][2] == 5 && M->Ma[1][1] == 5 && M->Ma[2][0] == 5)
	{
		return 1990;
	}
	if (M->Ma[0][2] == 1 && M->Ma[1][1] == 1 && M->Ma[2][0] == 1)
	{
		return 1990;
	}
	return 0;
}
int MultiplayerGame(Plas *p, NelMap *M,int a)//P thes player xy
{
	A1:
	int a1=0, a2=0;
	int caip;
	p->vb = 1;
	ChuShi(&*M,&*p);
	closegraph();
	initgraph(403, 403, EX_SHOWCONSOLE);
	if (a == 1)
	{
		setbkcolor(RED);
	}
	else if(a==2)
	{
		setbkcolor(BLUE);
	}
	else if (a == 3)
	{
		setbkcolor(GREEN);
	}
	else if (a == 3)
	{
		setbkcolor(YELLOW);
	}
	else
	{
		setbkcolor(RGB(255,255,255));
	}
	clearcliprgn();
	while (true)
	{
		BeginBatchDraw();
		setcolor(RGB(0, 0, 0));
		line(0, 0, 303, 0);
		line(0, 0, 0, 303);
		line(0, 303, 303, 303);
		line(303, 0, 303, 303);
		line(101, 0, 101, 303);
		line(202, 0, 202, 303);
		line(0, 101, 303, 101);
		line(0, 202, 303, 202);
		outtextxy(p->Set[1].x, p->Set[1].y, p->Set[1].sin);
		outtextxy(p->Set[2].x, p->Set[2].y, p->Set[2].sin);
		outtextxy(p->Set[3].x, p->Set[3].y, p->Set[3].sin);
		outtextxy(p->Set[4].x, p->Set[4].y, p->Set[4].sin);
		outtextxy(p->Set[5].x, p->Set[5].y, p->Set[5].sin);
		outtextxy(p->Set[6].x, p->Set[6].y, p->Set[6].sin);
		outtextxy(p->Set[7].x, p->Set[7].y, p->Set[7].sin);
		outtextxy(p->Set[8].x, p->Set[8].y, p->Set[8].sin);
		outtextxy(p->Set[9].x, p->Set[9].y, p->Set[9].sin);
		setbkmode(TRANSPARENT);
		outtextxy(0, 350,"ExitGame");
		outtextxy(280, 350, "Ruans");
		EndBatchDraw();
		caip = CaiPan(&*p, &*M);
		if (caip == 1990)
		{
			cout << "piout" << endl;
			HWND winds = GetHWnd();
			MessageBox(winds, "游戏结束了", "Games", MB_OK);
			return 0;
		}
		//The HUB to a1 a2 a3 b1 b2 b3 c1 c2 c3
		if(MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			cout << msg.x << " " << msg.y << endl;
			switch(msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if(msg.x<=303&&msg.y<=303)
				{
					cout << "OverSrrGame" << endl;
					if(msg.x<=101&&msg.y<=101)//A1
					{
						cout << "Ther A1" << endl;
						if(p->vb%2==1)
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 1;
							M->Ma[0][0] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 5;
							M->Ma[0][0] = 5;
							p->vb++;
						}
					}
					if(msg.x>101&&msg.x<=202&&msg.y<=101)//A2
					{
						cout << "Ther A2" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 1;
							M->Ma[0][1] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 5;
							M->Ma[0][1] = 5;
							p->vb++;
						}
					}
					if(msg.x>202&&msg.x<=303&&msg.y<=101)//A3
					{
						cout << "Ther A3" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 1;
							M->Ma[0][2] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 50;
							p->Set[p->vb].sin = 5;
							M->Ma[0][2] = 5;
							p->vb++;
						}
					}
					if(msg.x<=101&&msg.y>101&&msg.y<=202)//B1
					{
						cout << "Ther B1" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 1;
							M->Ma[1][0] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 5;
							M->Ma[1][0] = 5;
							p->vb++;
						}
					}
					if(msg.x>101&&msg.x<=202&& msg.y > 101 && msg.y <= 202)//B2
					{
						cout << "Ther B2" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 1;
							M->Ma[1][1] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 5;
							M->Ma[1][1] = 5;
							p->vb++;
						}
					}
					if(msg.x>202&&msg.x<= 303&&msg.y > 101 && msg.y <= 202)//B3
					{
						cout << "Ther B3" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 1;
							M->Ma[1][2] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 151;
							p->Set[p->vb].sin = 5;
							M->Ma[1][2] = 5;
							p->vb++;
						}
					}
					if (msg.x <= 101 && msg.y > 202 && msg.y <= 303)//C1
					{
						cout << "Ther C1" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 1;
							M->Ma[2][0] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 50;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 5;
							M->Ma[2][0] = 5;
							p->vb++;
						}
					}
					if(msg.x>101&&msg.x<=202&&msg.y>202&&msg.y<=303)//C2
					{
						cout << "Ther C2" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 1;
							M->Ma[2][1] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 151;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 5;
							M->Ma[2][1] = 5;
							p->vb++;
						}
					}
					if (msg.x > 202 && msg.x <= 303 && msg.y > 202 && msg.y <= 303)//C3 
					{
						cout << "Ther C3" << endl;
						if (p->vb % 2 == 1)
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 1;
							M->Ma[2][2] = 1;
							p->vb++;
						}
						else
						{
							p->Set[p->vb].x = 252;
							p->Set[p->vb].y = 252;
							p->Set[p->vb].sin = 5;
							M->Ma[2][2] = 5;
							p->vb++;
						}
					}
				}
				if (msg.x >= 0 && msg.x <= 60 && msg.y >= 350 && msg.y <= 360)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "游戏结束了", "Games", MB_OK);
					return 0;
				}
				if (msg.x >= 280 && msg.x <= 325 && msg.y >= 350 && msg.y <= 360)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "重新开始", "Games", MB_OK);
					goto A1;
					return 0;
				}
				break;
			}
		}
	}
}
int SetGame()
{
	closegraph();
	initgraph(400, 400, EX_SHOWCONSOLE);
	setbkcolor(RGB(255, 255, 255));
	clearcliprgn();
	while (true)
	{
		BeginBatchDraw();
		settextstyle(30, NULL, "微软雅黑");
		settextcolor(RED);
		outtextxy(50, 200, "Red");
		settextcolor(BLUE);
		outtextxy(100, 200, "Blue");
		settextcolor(GREEN);
		outtextxy(150, 200, "Green");
		settextcolor(YELLOW);
		outtextxy(200, 200, "Yellow");
		EndBatchDraw();
		if (MouseHit)
		{
			MOUSEMSG msg = GetMouseMsg();
			cout << msg.x << " " << msg.y << endl;
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if(msg.x>=50&&msg.x<=90&&msg.y>=205&&msg.y<=225)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "设置RED", "SetGames", MB_OK);
					return 1;
				}
				if (msg.x >= 100 && msg.x <= 145 && msg.y >= 205 && msg.y <= 225)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "设置BLUE", "SetGames", MB_OK);
					return 2;
				}
				if (msg.x >= 147 && msg.x <= 198 && msg.y >= 205 && msg.y <= 225)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "设置GREEN", "SetGames", MB_OK);
					return 3;
				}
				if (msg.x >= 200 && msg.x <= 270 && msg.y >= 205 && msg.y <= 225)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "设置YELLOW", "SetGames", MB_OK);
					return 4;
				}
				if (msg.y>330)
				{
					HWND winds = GetHWnd();
					MessageBox(winds, "退出", "SetGames", MB_OK);
					return 0;
				}
				break;
			}
		}
	}
}
int main() {
	int setvc = 0;
	NelMap Mr;
	Plas pr;
	Map Ms;
	JaZaiDongHua();
	initgraph(700, 300, EX_SHOWCONSOLE);
	while (true) {
		for (int i = 0; i <= 1400; i++) {
			BeginBatchDraw();
			settextcolor(WHITE);
			settextstyle(30, NULL, "微软雅黑");
			outtextxy(0, 0, "OperSedr");
			line(0, 300, i, 300);
			line(0, 299, i, 300);
			line(0, 328, i, 300);
			line(0, 397, i, 300);
			EndBatchDraw();
			Sleep(10);
			cleardevice();
			cout << i << endl;
	 }
		break;
	}
	int GetrMuse;
	while (true) 
	{
		GetrMuse = ZhuCaiDang(&Ms);
	switch(GetrMuse)
	 {
	 case 1926://SetGame
		 setvc= SetGame();
		 break;
	 case 1932://MultiplayerGame
		 MultiplayerGame(&pr,&Mr, setvc);
		 break;
	 case 1914:
		 return 0;
		 break;
	 }
	}
}