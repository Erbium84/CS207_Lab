#include <bits/stdc++.h>
using namespace std;
void worst_allocate(vector<pair<int, int>> inp){
    //return the order in which processes get executed
    int mem[]={250, 200, 150, 400, 200};
    for(int i=0; i<5; i++){
        cout<<"Segment #"<<i+1<<" Segment Size: "<<mem[i]<<endl;
    }
    for(int i=0; i<inp.size(); i++){
        if(inp[i].second>400){
            cout<<"External Fragmentation"<<endl;
        }
        else{
            cout<<"Process number "<<i+1<<" Allocated segment number 4"<<endl;
        }
    }
}

void best_allocate(vector<pair<int, int>> inp){
    int mem[]={150, 200, 200, 250, 400};
    for(int i=0; i<5; i++){
        cout<<"Segment #"<<i+1<<" Segment Size: "<<mem[i]<<endl;
    }
    for(int i=0; i<inp.size(); i++){
        if(inp[i].second>400){
            cout<<"External Fragmentation"<<endl;
        }
        else{
            for(int j=0; j<5; j++){
                if(mem[j]>=inp[i].second){
                    cout<<"process # "<<i+1<<"Allocated Segment number "<<j+1<<endl;
                    break;
                }
            }
        }
    }
}

void first_allocated(vector<pair<int, int>> inp){
    int mem[]={250, 200, 150, 400, 200};
    for(int i=0; i<5; i++){
        cout<<"Segment #"<<i+1<<" Segment Size: "<<mem[i]<<endl;
    }
    for(int i=0; i<inp.size(); i++){
        if(inp[i].second>400){
            cout<<"External Fragmentation"<<endl;
        }
        else{
            for(int j=0; j<5; j++){
                if(mem[j]>=inp[i].second){
                    cout<<"process # "<<i+1<<"Allocated Segment number "<<j+1<<endl;
                    break;
                }
            }
        }
    }
}
int main(){
    cout<<"Kshitij Sinha, 23/CS/225"<<endl;
    int n;
    cout<<"Number of processes "<<endl;
    cin>>n;
    vector<pair<int, int>> inp;
    for(int i=0; i<n; i++){
        int mem;
        cout<<"Memory for process "<<i+1<<" ?"<<endl;
        cin>>mem;
        pair<int, int> temp;
        temp.first=i+1;
        temp.second=mem;
        inp.push_back(temp);
    }
    worst_allocate(inp);
    best_allocate(inp);
    first_allocated(inp);
}