#include <bits/stdc++.h>
using namespace std;
bool search(int x, int mem[], int n){
    for(int i=0; i<n; i++){
        if(mem[i]==x){
            return true;
        }
    }
    return false;
}
class optimal{
    public:
    
    optimal(vector<int>p, int n){
        int mem[n];
        for(int i=0; i<n; i++){
            mem[i]=-1;
        }
        for(int i=0; i<p.size(); i++){
            if(search(p[i], mem, n)){
                continue;
            }
            if(i<n){
                mem[i]=p[i];
            }
            else{
                int forward[n];
                for(int t=0; t<n; t++){
                    forward[i]=-1;
                }
                int maxx=INT_MIN;
                for(int j=0; j<n; j++){
                    for(int k=i+1; k<p.size(); k++){
                        if(p[k]==mem[j]){
                            forward[j]=k;
                            maxx=max(k, maxx);
                        }
                    }
                }
                bool found=false;
                for(int j=0; j<n; j++){
                    if(forward[j]==-1){
                        mem[j]=p[i];
                        found=true;
                    }
                }
                if(found==true){
                    continue;
                }
                else{
                    for(int j=0; j<n; j++){
                        if(forward[j]==maxx){
                            mem[j]=p[i];
                            break;
                        }
                    }
                }
            }
        }
        map<int, int> mpp;
        for(int i=0; i<p.size(); i++){
            mpp[p[i]]++;
        }
        cout<<"Number of page faults: "<<mpp.size()<<endl;
        cout<<"Memory: ";
        for(int i=0; i<n; i++){
            cout<<mem[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter the page capacity :";
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
    optimal(p, n);
}