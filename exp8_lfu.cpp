//Input: page numbers, number of pages in memory
//Output: number of page faults, final pages in memory
//Least frquent first
#include <bits/stdc++.h>
using namespace std;
class lfu{
    public:
    map<int, int>unique, accessed;
    int faults=0;
    lfu(int n, vector<int> p){
        int least=p[0];
        int mem[n];
        for(int i=0; i<n; i++){
            mem[i]=-1;
        }
        for(int i=0; i<p.size(); i++){
            unique[p[i]]++;
        }
        int idx=0;
        for(int i=0; i<p.size(); i++){
            if(i<n){
                bool found=false;
                for(int j=0; j<n; j++){
                    if(mem[j]==p[i]){
                        found=true;
                        break;
                    }
                }
                if(found==true){
                    continue;
                }
                mem[i]=p[i];
                least=p[idx];
                idx++;
                accessed[p[i]]++;
                faults++;
            }
            else{
                int recent;
                for(auto it: accessed){
                    recent=it.first;
                    break;
                }
                bool found=false;
                for(int j=0; j<n; j++){
                    if(mem[j]==p[i]){
                        if(least==p[i]){
                            idx++;
                            least=p[idx];
                        }
                        found=true;
                        break;
                    }
                }
                if(found==false){
                for(int j=0; j<n; j++){
                    if(mem[j]==least){
                        idx++;
                        least=p[idx];
                        mem[j]=p[i];
                        accessed[p[i]]++;
                        faults++;
                    }
                    }
                }
            }
        }
        cout<<"Page Faults: "<<faults<<endl;
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
    cout<<"Enter number of pages: "<<endl;
    cin>>n;
    vector<int>p;
    while(1){
        cout<<"Enter 1 to put a page, 0 to quit: ";
        int x;
        cin>>x;
        if(x==1){
            cout<<endl;
            cout<<"Enter page number"<<endl;
            int y;
            cin>>y;
            p.push_back(y);
        }
        else{
            cout<<"Exiting"<<endl;
            break;
        }
    }
    lfu l(n, p);
}