#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    bool visited[401][201] = {false};
    int x=201;
    int y=0;
    bool danger=false;
    visited[x][y]=true;
    for(int i = 0 ; i < 3; i++){
        y++;
        visited[x][y]=true;
    }
    for(int i = 0 ; i < 3; i++){
        x++;
        visited[x][y]=true;
    }
    for(int i = 0; i < 2; i++){
        y++;
        visited[x][y]=true;
    }
    for(int i = 0; i < 2; i++){
        x++;
        visited[x][y]=true;
    }
    for(int i = 0; i < 2; i++){
        y--;
        visited[x][y]=true;
    }
    for(int i = 0 ; i < 2; i++){
        x++;
        visited[x][y]=true;
    }
    for(int i = 0 ; i < 4; i++){
        y++;
        visited[x][y]=true;
    }
    for(int i = 0 ; i < 8; i++){
        x--;
        visited[x][y]=true;
    }
    for(int i = 0 ; i < 2; i++){
        y--;
        visited[x][y]=true;
    }
    for(;;){
        char udlrq; cin>>udlrq;
        int n; cin>>n;
        if(udlrq=='q'){
            exit(0);
        }
        if(udlrq=='u'){
            for(int i = 0 ; i < n; i++){
                y--;
                if(visited[x][y]==true){
                    danger=true;
                }
                else{
                    visited[x][y]=true;
                }
            }
            if(danger==true){
                cout<<x-201<<" "<<-y<<" DANGER"<<endl;
                exit(0);
            }
            else{
                cout<<x-201<<" "<<-y<<" safe"<<endl;
            }
        }
        else if(udlrq=='d'){
            for(int i = 0 ; i < n; i++){
                y++;
                if(visited[x][y]==true){
                    danger=true;
                }
                else{
                    visited[x][y]=true;
                }
            }
            if(danger==true){
                cout<<x-201<<" "<<-y<<" DANGER"<<endl;
                exit(0);
            }
            else{
                cout<<x-201<<" "<<-y<<" safe"<<endl;
            }
        }
        else if(udlrq=='l'){
            for(int i = 0 ; i < n; i++){
                x--;
                if(visited[x][y]==true){
                    danger=true;
                }
                else{
                    visited[x][y]=true;
                }
            }
            if(danger==true){
                cout<<x-201<<" "<<-y<<" DANGER"<<endl;
                exit(0);
            }
            else{
                cout<<x-201<<" "<<-y<<" safe"<<endl;
            }
        }
        else if(udlrq=='d'){
            for(int i = 0 ; i < n; i++){
                y++;
                if(visited[x][y]==true){
                    danger=true;
                }
                else{
                    visited[x][y]=true;
                }
            }
            if(danger==true){
                cout<<x-201<<" "<<-y<<" DANGER"<<endl;
                exit(0);
            }
            else{
                cout<<x-201<<" "<<-y<<" safe"<<endl;
            }
        }
        else if(udlrq=='r'){
            for(int i = 0 ; i < n; i++){
                x++;
                if(visited[x][y]==true){
                    danger=true;
                }
                else{
                    visited[x][y]=true;
                }
            }
            if(danger==true){
                cout<<x-201<<" "<<-y<<" DANGER"<<endl;
                exit(0);
            }
            else{
                cout<<x-201<<" "<<-y<<" safe"<<endl;
            }
        }

    }
    return 0;
}
