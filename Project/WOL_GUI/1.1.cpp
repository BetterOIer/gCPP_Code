#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<easyx.h>
using namespace std;
class CStudent
{
    public:
        char szName[20];
        int age;
};
int main()
{
    CStudent s;       
    ifstream inFile("students.dat",ios::in|ios::binary); //二进制读方式打开
    if(!inFile) {
        cout << "error" <<endl;
        return 0;
    }
    while(inFile.read((char *)&s, sizeof(s))) { //一直读到文件结束
        cout << s.szName << " " << s.age << endl;   
    }
    inFile.close();
    return 0;
}