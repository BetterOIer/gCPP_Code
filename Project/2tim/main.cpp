#include<easyx.h>
#include<cstdlib>
const int X=1920;
const int Y=1080;
int main(){
    initgraph(X,Y);
    HWND hwnd = GetHWnd();
    SetWindowLong(hwnd , GWL_STYLE , GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);
    SetWindowPos(hwnd , HWND_TOP , 0 , 0 , GetSystemMetrics(SM_CXSCREEN) , GetSystemMetrics(SM_CXSCREEN) , SWP_SHOWWINDOW);
    setorigin((X>>1),(Y>>1));
    setaspectratio(1,-1);
    //ExMessage m;
    while(true){
        /* setfillcolor(RGB(rand(),rand(),rand()));
        setlinecolor(RGB(rand(),rand(),rand())); */
        //m = getmessage(EX_MOUSE | EX_KEY);
        setfillcolor(RGB(255,255,255));
        setlinecolor(RGB(255,255,255));

        fillcircle(rand()%X-X/2,rand()%Y-Y/2,2);

        setfillcolor(RGB(0,0,0));
        setlinecolor(RGB(0,0,0));

        fillcircle(rand()%X-X/2,rand()%Y-Y/2,2);

        setfillcolor(RGB(200,200,200));
        setlinecolor(RGB(200,200,200));

        fillcircle(rand()%X-X/2,rand()%Y-Y/2,2);
        //if (m.vkcode == VK_ESCAPE)return 0;
        //else continue;
        //Sleep(2);
        /* int ran=rand()%5+1;
        if(ran==1)for(int j = 0;j<=255;j++){
            for(double i = -(X>>1);i<=(X>>1);i+=0.1){
                putpixel(i+j,i*i*i*0.00001,RGB(255, 255, j));
            }
        }
        if(ran==2)for(int j = 0;j<=255;j++){
            for(double i = -(X>>1);i<=(X>>1);i+=0.1){
                putpixel(i-j,i*i*i *0.00001,RGB(255, j, 255));
            }
        }
        if(ran==3)for(int j = 0;j<=255;j++){
            for(double i = -(X>>1);i<=(X>>1);i+=0.1){
                putpixel(i,i*i*i *0.00001+j,RGB(j, 255, 255));
            }
        }
        if(ran==4)for(int j = 0;j<=255;j++){
            for(double i = -(X>>1);i<=(X>>1);i+=0.1){
                putpixel(i,i*i*i *0.00001-j,RGB(j,j+1,j+2));
            }
        }
        if(ran==5){
            for(double i = -(X>>1);i<=(X>>1);i+=0.01){
                setfillcolor(RGB(rand(),rand(),rand()));
                fillcircle(rand()%X-X/2,rand()%Y-Y/2,rand()%100);
            }
        } */
    }
    system("pause");
    closegraph();
}   