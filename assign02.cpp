#include <iostream> // for cin/cout
#include <fstream>  // for file input
#include <vector>   // for vector

using namespace std;

int getDistance(pair<int,int> from, pair<int,int> to){
    int result;
    result = abs(from.first-to.first) + abs(from.second-to.second);

    return result;
}

int TPS(pair<int,int> check, vector<pair<int,int> > pos, int n){
    if(n==0)
        return 0;
    vector<int> distance;
    int minIndex;
    int min=0;

    for(int i=0; i<n; i++){
        distance[i] = getDistance(check, pos[i]);
        if(distance[i] < min){
            min = distance[i];
            minIndex = i;
        }
    }
    pair<int,int> checkNext = pos[minIndex];
    pos.erase(pos.begin()+minIndex);
    
    return TPS(checkNext, pos, n-1);
}

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
