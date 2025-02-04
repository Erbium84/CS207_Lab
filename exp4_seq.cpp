# include <bits/stdc++.h>
using namespace std;

int block_size;
const int disk_size = 20;
int empty_blocks = 0;
int num_files = 0;
map<string, pair<int, int>> directory;
vector<bool> disk_avail(20, false);
vector<pair<string, int>> disk(20);

class file{
    public:
    string file_name;
    int file_size;
    int partitions;

    file() {};
    file(string &fname, int fsize) : file_name(fname), file_size(fsize) {
        partitions = (file_size + block_size - 1)/block_size;
    };
};

void initialise(){
    cout<<"Enter block size: "; cin>>block_size;
    cout<<"Enter number of empty blocks: "; cin>>empty_blocks;
    cout<<"Enter indices of empty blocks: ";
    for(int i = 0; i < empty_blocks; i++){
        int x; cin>>x;
        disk_avail[x] = true;
    }
}

void sequential_file_allocation(){
    cout<<"Enter number of files: "; cin>>num_files;
    for(int i = 0; i < num_files; i++){
        string fname; int fsize;
        cout<<"Enter file name: "; cin>>fname;
        cout<<"Enter file size: "; cin>>fsize;
        file f(fname, fsize);
        bool avail = false; int count = 0, startblock = -1;
        for(int j = 0; j < 20; j++){
            if(disk_avail[j]) count++;
            else count = 0;
            if(count == 1) startblock = j;
            if(count == f.partitions){
                avail = true; break;
            }
        }
        if(avail){
            directory[f.file_name] = {startblock, f.file_size};
            int count = 1;
            for(int j = startblock; count <= f.partitions; j++, count++){
                disk_avail[j] = false;
                disk[j] = {f.file_name, count};
            } 
            cout<<"File "<<f.file_name<<" has been allocated successfully"<<endl;
        }
        else{
            cout<<"File "<<f.file_name<<" could not be allocated"<<endl;
        }
    } 
}

void display_directory(){
    for(pair<string, pair<int, int>> entry: directory){
        string fname = entry.first; int startblock = entry.second.first;
        int fsize = entry.second.second;
        int endblock = startblock + (fsize + block_size - 1)/block_size - 1;
        cout<<"File Name: "<<fname<<endl;
        cout<<"File Size: "<<fsize<<endl;
        cout<<"Memory Block\tFile\t\tPartition"<<endl;
        for(int j = startblock; j <= endblock; j++){
            cout<<j<<"\t\t"<<disk[j].first<<"\t\t"<<disk[j].second<<endl;
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Kshitij Sinha, 23/CS/225"<<endl;
    initialise();
    sequential_file_allocation();
    display_directory();
}