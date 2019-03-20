#include <iostream> // for cin/cout
#include <fstream>  // for file input
#include <vector>   // for vector

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    int N;
    int x,y;
    string line;
    vector<pair<int, int> > pos;

    // Read file & Save into vector<pair<>> structure
    fstream fin;
    fin.open("input.txt");
    fin>>N;

    for(int i=0; i<N; i++){
        fin>>x>>y;
        pos.push_back(make_pair(x,y));
    }
    fin.close();

    // Check input data 
    cout<<N<<endl;
    for(auto &p: pos)
        cout<<p.first<<" "<<p.second<<endl;

    return 0;
}
