//Input: page numbers, number of pages in memory
//Output: number of page faults, final pages in memory
#include <bits/stdc++.h>
using namespace std;
class fifo{
    public:
    fifo(int n, vector<int> p){
        int faults=0;
        int mem[n];
        for(int i=0; i<n; i++){
            mem[i]=-1;
        }
        int prev=0;
        for(int i=0; i<p.size(); i++){
            if(i<n){
                 bool found=false;
                for(int j=0; j<n; j++){
                    if(mem[j]==p[i]){
                        found=true;
                        break;
                    }
                }
                if(found==false){
                mem[i]=p[i];
                faults++;
                }
            }
            else{
                bool found=false;
                for(int j=0; j<n; j++){
                    if(mem[j]==p[i]){
                        found=true;
                        break;
                    }
                }
                if(found==false){
                    for(int j=0; j<n; j++){
                        if(mem[j]==p[prev]){
                            mem[j]=p[i];
                            prev++;
                            faults++;
                            break;
                        }
                    }
                }
            }
        }
        cout<<"Number of Faults are :"<<faults<<endl;
        cout<<"The pages in memory are :"<<endl;
        for(int i=0; i<n; i++){
            cout<<mem[i]<<" ";
        }
    }
};

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
        int faults=0;
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
                    faults++;
                }
            }
            else{
                int search=accessed[0];
                for(int j=0; j<n; j++){
                    if(mem[j]==search){
                        mem[j]=p[i];
                        faults++;
                    }
                }
                accessed.erase(accessed.begin());
                accessed.push_back(p[i]);
            }
        }
        cout<<"Number of Faults: "<<faults<<endl;
        cout<<"Memory: "<<endl;
        for(int i=0; i<n; i++){
            cout<<mem[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    cout<<"Kshitij Sinha, 23/CS/225"<<endl;
    int n;
    cout<<"Enter page capacity in Main Memory"<<endl;
    cin>>n;
    vector<int> pages;
    while(1){
        cout<<"Enter 1 to Add page number, 0 to stop :";
        int x;
        cin>>x;
        if(x==1){
            cout<<"Enter page number: ";
            int p;
            cin>>p;
            pages.push_back(p);
        }
        else{
            break;
        }
    }
    cout<<"Using FIFO: "<<endl;
    fifo f1(n, pages);
    cout<<endl;
    cout<<"Using LRU: "<<endl;
    lru l1(n, pages);
}