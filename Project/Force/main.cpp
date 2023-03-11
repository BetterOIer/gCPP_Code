/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<easyx.h>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int x;
    int y;
};
vector <node> P;
double vx=-10,vy=0;
double x=1366,y=180;
void merge(double &F,double &X,double &Y,double fn,double xn,double yn){
	F=F*F+fn*fn+fn*F*2*((X/sqrt(X*X+Y*Y))*(xn/sqrt(xn*xn+yn*yn))+(Y/sqrt(X*X+Y*Y))*(yn/sqrt(xn*xn+yn*yn)));
	X=X+xn;
	Y=Y+yn;
}
void pri(){
	double F=0,X=-1,Y=0;
    for(node f:P){
		circle(f.x, f.y, 5);
        double f1=500/((f.x-x)*(f.x-x)+(f.y-y)*(f.y-y));
		merge(F,X,Y,f1,f.x-x,f.y-y);
    }
	vx+=F*X/sqrt(X*X+Y*Y);
	vy+=F*Y/sqrt(X*X+Y*Y);
}
int main(){
    initgraph(1366,768);
	line(1366,200,0,200);
    ExMessage m;		// 定义消息变量

	while(true)
	{
		// 获取一条鼠标或按键消息
		m = getmessage(EX_MOUSE | EX_KEY);
		switch(m.message){
			case WM_LBUTTONDOWN:
				// 画一个小方块
				setfillcolor(BLACK);
				fillrectangle(0,0,1366,768);
				setfillcolor(WHITE);
                circle(m.x, m.y, 5);
				x=1366,y=200;
				vx=-10,vy=0;
                P.push_back((node){m.x,m.y});
                pri();
				while(x>=0&&x<=1366&&y>=0&&y<=768){
					x+=vx;
					y+=vy;
					fillcircle(x, y, 4);
					Sleep(4);
					pri();
				}
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					return 0;	// 按 ESC 键退出程序
		}
	}
	closegraph();
	return 0;
}