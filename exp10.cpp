#include <bits/stdc++.h>
using namespace std;
class fcfs{
    public:
    fcfs(vector<int> p){
        int moved=0;
        moved+=abs(p[0]);
        cout<<"moved from "<<0<<" to "<<p[0]<<endl;
        for(int i=1; i<p.size(); i++){
            cout<<"moved from "<<p[i-1]<<" to "<<p[i]<<endl;
            moved+=abs(p[i]-p[i-1]);
        }
        cout<<"Total Moved: "<<moved<<endl;
    }
};

class scan{
    public:
    scan(vector<int> p){
        int moved=0;
        moved+=abs(p[0]);
        int head=p[0];
        int taken[p.size()]={0};
        cout<<"moved from "<<0<<" to "<<p[0]<<endl;
        for(int i=1; i<p.size(); i++){
            if(p[i]>=head){
                cout<<"moved from "<<head<<" to "<<p[i]<<endl;
                moved+=abs(p[i]-head);
                head=p[i];
                taken[i]=1;
            }
        }
        for(int i=p.size()-1; i>=1; i--){
            if(taken[i]==0){
                cout<<"moved from "<<head<<" to "<<p[i]<<endl;
                moved+=abs(p[i]-head);
                head=p[i];
            }
        }
        cout<<"Total moved by head: "<<moved<<endl;
    }
};

int main(){
    vector<int>p;
    while(1){
        cout<<"press 1 to enter track or 0 to exit"<<endl;
        int x;
        cin>>x;
        if(x==1){
            int y;
            cin>>y;
            p.push_back(y);
        }
        else{
            cout<<"exiting"<<endl;
            break;
        }
    }
    cout<<"Using fcfs: "<<endl;
    fcfs f(p);
    cout<<"using SCAN: "<<endl;
    scan s(p);
}