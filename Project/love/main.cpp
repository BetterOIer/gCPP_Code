 
///
// 程序名称：《点燃我，温暖你》爱心程序
// 编译环境：Mictosoft Visual Studio 2013,+EasyX_20200315(beta)
// 作　　者：爱编程的胡桃
// 源码获取加q群：724050348   想学习更多项目、和同行交流学习都可以进来 ~
// 
 
#include<easyx.h>
#include<conio.h>
#include<ctime>
#include<cmath>
#include<sys/timeb.h>
 
struct MyLove
{
  int NUMS;  //  编号
  double m;
  double n;
  double size;
  bool Is_show;
  int x;
  int y;
};
 
MyLove mylove[400];
int CenterX = 320;
int CenterY = 180;
double Size = 60;
void initdata();  // 初始化数据
void updata();    // 更新
void movedata();  // 平移
void showdata();  // 显示
int* GetRand(int* buf, int count, int range);  // 随机数的生成
void heart(int x0, int y0, int size, COLORREF C);
void HpSleep(int ms);
 
int main()
{
  initgraph(640, 480);
  initdata();
  BeginBatchDraw();
  while (true)
  {
    updata();
    showdata();
    HpSleep(30);    // 改为精确延时
    FlushBatchDraw();
    cleardevice();
  }
  EndBatchDraw();
  _getch();
  return 0;
}
 
void updata()
{
  int* buf = (int*)malloc(sizeof(int)* 20);
  buf = GetRand(buf, 20, (int)(2 * Size / 0.01));
  movedata();
  for (int i = 0; i < 20; i++)
  {
    mylove[i].m = buf[i] * 0.01;
    mylove[i].n = (((sin(buf[(int)i] * 0.01) * sqrt(fabs(cos(buf[(int)i] * 0.01)))) / (sin(buf[(int)i] * 0.01) + 1.4142)) - 2 * sin(buf[(int)i] * 0.01) + 2);
    mylove[i].size = Size;
    mylove[i].NUMS = i / 20;
    mylove[i].Is_show = true;
    mylove[i].x = (int)(-Size *mylove[i].n * cos(mylove[i].m) + CenterX);
    mylove[i].y = (int)(-Size *mylove[i].n * sin(mylove[i].m) + CenterY - mylove[i].size);
  }
  for (int i = 20; i < 400; i++)
  {
    mylove[i].size = mylove[i].size + 1;
    if (mylove[i].size>80)
    {
      mylove[i].size = 80;
    }
    mylove[i].NUMS = i / 20;
    mylove[i].x = (int)(-mylove[i].size *mylove[i].n * cos(mylove[i].m) + CenterX);
    mylove[i].y = (int)(-mylove[i].size *mylove[i].n * sin(mylove[i].m) + CenterY - mylove[i].size);
  }
}
 
void movedata()
{
  for (int i = 399; i > 19; i--)
  {
    mylove[i] = mylove[i - 20];
  }
}
 
void showdata()
{
  settextcolor(RED);
  wchar_t c = 0x59;    // 0x28 是电话机在 Wingdings 字体中的对应编码
  for (int i = 0; i < 400; i++)
  {
    settextstyle(mylove[i].NUMS + 10, 0, "Webdings");
    setbkmode(TRANSPARENT);
    outtextxy(mylove[i].x + 20, mylove[i].y + 20, c);
  }
}
 
int* GetRand(int* buf, int count, int range)
{
  struct timeb timeSeed;
  ftime(&timeSeed);
  srand(timeSeed.time * 1000 + timeSeed.millitm);  // milli time
  for (int i = 0; i < count; i++)
  {
    int randTmp = rand() % range;
    for (int j = 0; j < i; j++)
    {
      if (buf[j] == randTmp)
      {
        break;//检查重复。
      }
    }
    buf[i] = randTmp;
  }
  return buf;
}
 
void initdata()
{
  for (int i = 0; i < 400; i++)
  {
    mylove[i].NUMS = 0;
    mylove[i].m = 0;
    mylove[i].n = 0;
    mylove[i].size = 0;
    mylove[i].Is_show = false;
    mylove[i].x = 0;
    mylove[i].y = 0;
  }
}
 
// 精确延时函数(可以精确到 1ms，精度 ±1ms)
// by yangw80<yw80@qq.com>, 2011-5-4
void HpSleep(int ms)
{
  static clock_t oldclock = clock();    // 静态变量，记录上一次 tick
  oldclock += ms * CLOCKS_PER_SEC / 1000;  // 更新 tick
  if (clock() > oldclock)          // 如果已经超时，无需延时
    oldclock = clock();
  else
  while (clock() < oldclock)      // 延时
    Sleep(1);            // 释放 CPU 控制权，降低 CPU 占用率，精度 10~16ms
  //      Sleep(0);            // 更高精度、更高 CPU 占用率，精度 1ms
}