#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<easyx.h>
using namespace std;
int main(){
    
    default_random_engine e;
    e.seed(time(NULL));
    //srand((unsigned int )time(NULL));
    int r=400,t=10000000,cnt=0,ok=0;
    uniform_real_distribution<double>rd(-r,r);
    //cin>>r>>t;
    initgraph((r<<1)+30,(r<<1)+30);
    setorigin(15+r,15+r);
    //setaspectratio(1, -1);
    setlinecolor(WHITE);
    rectangle(-r,r,r,-r);
    circle(0,0,r);
    while(t--){
        cnt++;
        //int x=rand()%((r<<1)+1)-r,y=rand()%((r<<1)+1)-r;
        double x=rd(e),y=rd(e);
        if(1.0*x*x+1.0*y*y<=1.0*r*r){
            ok++;
            putpixel(x,y,YELLOW);
        }else putpixel(x,y,RED);
        outtextxy(-0,-0,to_string(4.0*ok/cnt).c_str());
        //cout<<cnt<<" "<<ok<<" "<<4.0*ok/cnt<<endl;
    }
    //setbkmode(TRANSPARENT);
    /* for(int x = -r;x<=r;x++){
        for(int y = -r;y<=r;y++){
            cnt++;
            if(x*x+y*y<=r*r){
                ok++;
                putpixel(x,y,YELLOW);
            }else putpixel(x,y,RED);
            //cout<<cnt<<" "<<ok<<" ";
            outtextxy(-0,-0,to_string(4.0*ok/cnt).c_str());
            //printf("%d %d %.10f\n",cnt,ok,4.0*ok/cnt);
        }
    } */
    cout<<4.0*ok/cnt<<endl;
    system("pause");
}