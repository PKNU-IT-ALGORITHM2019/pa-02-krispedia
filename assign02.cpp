#include <iostream> // for cin/cout
#include <fstream>  // for file input
#include <vector>   // for vector
#include <map>      // for map

using namespace std;

vector <int> route;
map<pair<int,int>,int> pos;

void routePrint(vector<int> route);
int getDistance(pair<int,int> from, pair<int,int> to);
int TSP(pair<int,int> check, multimap<int, pair<int,int> > loc, int n);

// Function to convert a std::map<K,V> to std::multimap<V,K>
template<typename K, typename V>
multimap<V,K> invertMap(map<K,V> const &map)
{
	multimap<V,K> multimap;

	for (auto const &pair: map) {
		multimap.insert(make_pair(pair.second, pair.first));
	}

	return multimap;
}

void routePrint(vector<int> route){
    cout<<"[ ";
    for(auto it=route.begin(); it!=route.end(); ++it)
        cout<<*it<<" ";
    cout<<"]"<<'\n';
}

int getIndex(map<pair<int,int>,int> pos, pair<int,int> check){
    
    return pos.find(check)->second;
}

int getDistance(pair<int,int> from, pair<int,int> to){
    int result;
    result = abs(from.first-to.first) + abs(from.second-to.second);

    return result;
}

int TSP(pair<int,int> check, multimap<int, pair<int,int> > loc, int n){
    if(n==1){
        route.push_back(loc.begin()->first);
        return 0;
    }
    int dist;
    int min=0;
    pair<int,int> checkNext;

    for(auto it=loc.begin(); it!=loc.end(); ++it){
        dist = getDistance(check, it->second);
        if(dist < min){
            min = dist;
            checkNext = it->second;
        }
    }
    // Find min dist Index via pair<int,int>
    int index = getIndex(pos, checkNext);

    // Push min dist Index 
    route.push_back(index);
    loc.erase(index);
    
    return TSP(checkNext, loc, n-1);

}

int main(void) {
    ios_base::sync_with_stdio(false);
    int N;
    int x,y;
    string line;

    // Read file & Save into vector<pair<>> structure
    fstream fin;
    fin.open("input.txt");
    fin>>N;

    for(int i=0; i<N; i++){
        fin>>x>>y;
        pos[make_pair(x,y)] = i;
    }
    fin.close();
    
    multimap<int,pair<int,int> > multimap = invertMap(pos);

    // print the multimap
	for (auto const &pair: multimap) {
		cout << '{' << pair.second.first << pair.second.second << "," << pair.first << '}' << '\n';
	}

    cout<<"multimap.begin()->first: "<<multimap.begin()->first<<'\n';
    cout<<"multimap.begin()->second: "<<multimap.begin()->second.first<<'\n';
    cout<<"multimap.begin()->second: "<<multimap.begin()->second.second<<'\n';

    route.push_back(multimap.begin()->first);
    multimap.erase(multimap.begin());

    TSP(multimap.begin()->second, multimap, N-1);
    
    routePrint(route);

    // Check input data 
    return 0;
    }
