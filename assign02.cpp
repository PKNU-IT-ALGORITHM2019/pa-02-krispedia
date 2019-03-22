#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <stack>
#include <ctime>

using namespace std;

int N;

map<int,pair<int,int> > node;
vector<bool> visited;
stack<int> tour;
vector<int> tour_temp;
stack<int> minTour;
double minDist = numeric_limits<double>::max();

// Read file & make node vector
void readFile(string fileName){
    int x,y;
    fstream fin;
    fin.open(fileName);
    fin>>N;
    for(int i=0; i<N; i++){
        fin>>x>>y;
        pair<int,int> temp = make_pair(x,y);
        node[i] = temp;
    }
    fin.close();
}
// Init vector size
void init(){
    visited = vector<bool> (N, false); 
}
double getDistance(pair<int,int> node1, pair<int,int> node2){
    return sqrt(pow(node1.first-node2.first, 2.0) + pow(node1.second-node2.second, 2.0));
}
void printMinTour(){
    cout<<"[ ";
    for(int i=0; i<N; i++){
        cout<<minTour.top()<<' ';
        minTour.pop();
    }
    cout<<"]"<<'\n';
}
void printVisited() {
    cout<<"--visited--"<<'\n';
    for(auto it = visited.begin(); it!=visited.end(); ++it)
        cout<<*it<<' ';
    cout<<'\n';
}
void switchTour(){
    tour_temp.clear();
    for(int i=0; i<N; i++){
        int temp;
        temp = tour.top();
        minTour.push(temp);
        tour_temp.push_back(temp);
        tour.pop();
    }  
    for(auto it=tour_temp.end()-1; it!=tour_temp.begin(); --it){
        tour.push(*it);
    }
    tour.push(*tour_temp.begin());

}
void TSP(int checkIndex, int n, double dist){
    cout<<"TSP START!"<<'\n';
    if(n == 0){
        double checkToStart = getDistance(node.find(checkIndex)->second, node.find(0)->second);
        dist += checkToStart;
        tour.push(checkIndex);

        if(dist<minDist){
            minDist = dist;
            switchTour();
        }
        visited[checkIndex] = false;
        tour.pop();

    }
    else{
        visited[checkIndex] = true;
        tour.push(checkIndex);

        for(int i=0; i<N; i++){
            if(i == checkIndex)
                continue;
            if(visited[i] == false){
                double checkToI = getDistance(node.find(checkIndex)->second, node.find(i)->second);
                TSP(i, n-1, dist+checkToI);
            }
        }
        visited[checkIndex] = false;
        tour.pop();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    time_t start, end;
    start = time(NULL);

	readFile("input4.txt");

    init();

    TSP(0, N-1, 0);    
    
    end = time(NULL);
    double result = (double)(end-start);
    cout<<"걸린 시간: "<<result<<"s"<<'\n';

    cout<<fixed;
    cout.precision(14);
    cout<<"최소 거리: "<<minDist<<'\n';
    printMinTour();

    return 0;
}
