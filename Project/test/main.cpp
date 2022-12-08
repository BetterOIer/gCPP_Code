#include<easyx.h>
#include<cstdlib>
const int X=1366;
const int Y=768;
int main(){
	initgraph(X,Y);
    setorigin(X>>1,Y>>1);
    setaspectratio(1, -1);
	for(int i = (Y>>1);i>=0;i--){
        setfillcolor(RGB(255, 255, i));
        setlinecolor(RGB(255, 255, i));
        fillcircle(0,0,i);
        Sleep(10);
    }
    system("pause");
	return 0;
}