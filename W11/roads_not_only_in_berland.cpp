#include <map>
#include <tuple>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
 
using namespace std;

unsigned long long get_number(string value, int& start, char separator = ' '){
    unsigned long long number = 0;
    int i = start;
    
    while(value[i] != '\0'){
        if(value[i] == separator){
            break;
        }
        number = number * (unsigned long long)10 + (unsigned long long)(value[i] - '0');
        i++;
    }
    start = i + 1;
 
    return number;
}

void get_neighbours(bool*& visited, const int actual, map<int, set<int>>& graph){

    visited[actual - 1] = true;

    set<int>::iterator it;
    for(it = graph[actual].begin(); it != graph[actual].end(); it++){
        if(!visited[*it - 1]){
            get_neighbours(visited, *it, graph);
        }
    }
}

void print_representant(set<int> representant){
    cout << "Representant:" << endl;
    set<int>::iterator it;
    for(it = representant.begin(); it != representant.end(); it++){
        cout << *it << " ";
    }
}

void print_visited(bool* visited, int n){
    cout << "Visited:" << endl;
    for(int i = 0; i < n; i++){
        cout << visited[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cin >> n;

    map<int, set<int>> graph = map<int, set<int>>();
    set<int> representant = set<int>();
    bool* visited = new bool[n];
    memset(visited, false, n);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    map<int, set<int>>::iterator it;
    for(it = graph.begin(); it != graph.end(); it++){

        if(visited[it->first - 1]){
            continue;
        }

        representant.insert(it->first);
        get_neighbours(visited, it->first, graph);

    }

    print_representant(representant);

    return 0;
}