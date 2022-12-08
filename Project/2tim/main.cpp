#include<easyx.h>
#include<cstdlib>
const int X=1366;
const int Y=768;
int main(){
    initgraph(1366,768);
    setorigin((X>>1),(Y>>1));
    setaspectratio(1,-1);
    while(true){
        int ran=rand()%4+1;
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
    }
    system("pause");
    closegraph();
}   