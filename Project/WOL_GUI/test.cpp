#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include<iostream>
#include<fstream>
using namespace std;
struct CStudent{
    int age;
    int szName;
    int szId;
};
CStudent s;
int main(){
    s.age = 100;
    s.szName = 322342;
    s.szId = 324242;
    ofstream outFile("students.dat", ios::out | ios::binary);
    outFile.write((char*)&s, sizeof(s));
    outFile.close();
}