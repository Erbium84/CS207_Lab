#include <bits/stdc++.h>
using namespace std;
void wait(int& s){
    if(s<=0){
        cout<<"Busy Wait, access denied. Please call signal() first"<<endl;
        cout<<"Value of s: "<<s<<endl;
        return;
    }
    s--;
    cout<<"Value of s: "<<s<<endl;
}

void signal(int& s, int& n){
    s++;
    if(s>n){
        cout<<"Buffer Full, please call wait()"<<endl;
        s--;
        cout<<"Value of s: "<<s<<endl;
        return;
    }
    cout<<"Value of s: "<<s<<endl;
}

int main(){
    cout<<"Kshitij Sinha, 23/CS/225"<<endl;
    int n;
    cout<<"Enter buffer size"<<endl;
    cin>>n;
    int val=true;
    int s=0;
    while(1){
        cout<<"Enter signal or wait by using 1 or 2 or quit using 0"<<endl;
        int x;
        cin>>x;
        if(x==1){
            signal(s, n);
        }
        else if(x==2){
            wait(s);
        }
        else{
            cout<<"Exiting"<<endl;
            break;
        }
    }
}