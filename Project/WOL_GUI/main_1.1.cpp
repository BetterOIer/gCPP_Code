#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <WinSock2.h>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <easyx.h>
using namespace std;

struct node{
    int id;
    string host_name;
    string name;
    unsigned int mac[6];
    int port;
};
vector <node> mach;
hostent *host;

bool new_to_use = false;

int idx=0;

bool wol(int which){
    unsigned char packet[102];
    struct sockaddr_in addr;
    int sockfd, i,j, on = 1; 

    for(i=0;i<6;i++){
        packet[i] = 0xFF;    
    }
    for(i=1;i<17;i++){
        for(j=0;j<6;j++){
            packet[i*6+j] = mach[which].mac[j];
        }
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST,(char*)&on, sizeof(on));
    if(sockfd < 0){
        return false;
    }
    memset((void*)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(mach[which].port);
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
    sendto(sockfd,(char*)&packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    return true;
}

void update(){

}

void init(){
    ifstream DATADB("data.db",ios::in|ios::binary);
    if (!DATADB){
        new_to_use=true;
        return;
    }
    DATADB.read((char*)&mach, sizeof(mach));
    DATADB.close();
    idx=mach.size();
}
void save(){
    ofstream DATADB("data.db", ios::out | ios::binary);
    DATADB.write((char*)&mach, sizeof(mach));
    DATADB.close();
}
string lower(string str){
    for(auto &i : str){
        i = tolower(i);
    }    
    return str;
}
void add_new_machine(){
    node new_machine;
    cout<<"ÓòÃû: ";
    cin>>new_machine.host_name;
    cout<<"¶Ë¿Ú: ";
    cin>>new_machine.port;
    cout<<"MACµØÖ·£¨¡°-¡±ºÅ¸ô¿ªAA-BB-CC-DD-EE-FF£©: ";
    scanf("%x-%x-%x-%x-%x-%x",&new_machine.mac[0],&new_machine.mac[1],&new_machine.mac[2],&new_machine.mac[3],&new_machine.mac[4],&new_machine.mac[5]);
    cout<<"êÇ³Æ: ";
    cin>>new_machine.name;
    new_machine.id=++idx;
    mach.push_back(new_machine);
}
void show_machines(){
    for(auto i:mach){
        printf("%5d %s\n",i.id,i.name.c_str());
    }
}
void wake_on_lan(){
    int id;
    cin>>id;
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    host = gethostbyname(mach[id].host_name.c_str());
    if(wol(id)){
        printf("Success!");
    }else printf("Failed!");
}
void run(){
    while(true){
        cout<<">>>";
        string opt;
        cin>>opt;
        if(lower(opt)=="new"){
            add_new_machine();
        }else if(lower(opt)=="show"){
            show_machines();
        }else if(lower(opt)=="wol"){
            wake_on_lan();
        }else {
            return;
        }
    }
}
int main(){
    update();
    init();
    run();
    save();
    return 0;
}