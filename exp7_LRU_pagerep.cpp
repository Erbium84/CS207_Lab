//Input: page numbers, number of pages in memory
//Output: number of page faults, final pages in memory
//Least recent first
#include <bits/stdc++.h>
using namespace std;
class lru{
    public:
    lru(int n, vector<int> p){
        int mem[n];
        map<int, int> mpp;
        for(int i=0; i<p.size(); i++){
            mpp[p[i]]++;
        }
        vector<int> accessed;
        for(int i=0; i<n; i++){
            mem[i]=-1;
        }
        for(int i=0; i<p.size(); i++){
            if(i<n){
                bool avail=false;
                for(int j=0; j<n; j++){
                    if(mem[j]==p[i]){
                        avail=true;
                        accessed.push_back(accessed[0]);
                        accessed.erase(accessed.begin());
                        break;
                    }
                }
                if(avail==true){
                    continue;
                }
                else{
                    accessed.push_back(p[i]);
                    mem[i]=p[i];
                    
                }
            }
            else{
                int search=accessed[0];
                for(int j=0; j<n; j++){
                    if(mem[j]==search){
                        mem[j]=p[i];
                    }
                }
                accessed.erase(accessed.begin());
                accessed.push_back(p[i]);
                
            }
        }
        cout<<"Number of Faults: "<<mpp.size()<<endl;
        cout<<"Memory: "<<endl;
        for(int i=0; i<n; i++){
            cout<<mem[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    vector<int> p;
    int n;
    cout<<"Enter number of pages in memory"<<endl;
    cin>>n;
    while(1){
        bool exit=false;
        int x;
        cout<<"Press 0 to exit, 1 to enter page"<<endl;
        cin>>x;
        if(x==0){
            cout<<"Exiting"<<endl;
            break;
        }
        else{
            cout<<"Enter Page number to be added"<<endl;
            int y;
            cin>>y;
            p.push_back(y);
        }
    }
    lru lru(n, p);
}