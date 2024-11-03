//implement non-primitive CPU Scheduling to find TAT and WT, given AT and BT a)FCFS b) SJF
#include <bits/stdc++.h>
using namespace std;
void fcfs(vector<pair<int, int>> at, vector<int> b, int n){
    int wt[n], tat[n];
    wt[0]=0;
    cout<<"PN\tTAT\tWT"<<endl;
    cout<<at[0].second<<"\t"<<b[0]<<"\t"<<0<<endl;
    for(int i=1; i<n; i++){
        cout<<at[i].second<<"\t"<<wt[i-1]+at[i-1].second+b[i-1]-at[i].second+b[i]<<"\t"<<wt[i-1]+b[i-1]<<endl;
    }
}
int main(){
    int n;
    cout<<"Number of Processes"<<endl;
    cin>>n;
    vector<pair<int, int>>at, bt;
    for(int i=0; i<n; i++){
        cout<<"AT and BT for process"<<i+1<<endl;
        int a,b;
        cin>>a>>b;
        pair<int, int> temp1, temp2;
        temp1.first=a;
        temp1.second=i+1;
        temp2.first=b;
        temp2.second=i+1;
        at.push_back(temp1);
        bt.push_back(temp2);
    }
    sort(at.begin(), at.end());
    vector<int> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(at[i].second==bt[j].second){
                b.push_back(bt[j].first);
            }
        }
    }
    fcfs(at, b, n);
}