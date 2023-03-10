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
int po_x=0,po_y=0;
bool likai=false;
struct xl{
    int len=0;
    int angle=0;
};
vector <xl> P;
void analyze(){
    
}
void merge(){
    
}
void print(){
    
}
int main(){
    initgraph(1366,768);
    while(true){
        analyze();
        merge();
        print();
    }
    system("pause");
}