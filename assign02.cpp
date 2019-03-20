#include <iostream> // for cin/cout
#include <fstream>  // for file input
#include <vector>   // for vector

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    int N;
    string line;
    vector<pair<int, int> > pos;

    fstream fin;
    fin.open("input.txt");
    fin>>N;
    for(int i=0; i<N; i++){
        fin>>pos[i].first>>pos[i].second;
    }
    fin.close();

    cout<<N<<endl;
    for(auto &p: pos)
        cout<<p.first<<p.second<<endl;

    return 0;
}
