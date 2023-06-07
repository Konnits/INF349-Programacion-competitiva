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

void get_neighbours(bool*& visited, const unsigned short actual, map<unsigned short, set<unsigned short>>& graph, bool**& connections, unsigned short& n_nodes, int& count){

    if(visited[actual - 1]){
        return;
    }
    visited[actual - 1] = true;
    n_nodes++;

    set<unsigned short>::iterator it;
    for(it = graph[actual].begin(); it != graph[actual].end(); it++){
        if(!connections[actual - 1][*it - 1]){
            count++;
            connections[actual - 1][*it - 1] = true;
            get_neighbours(visited, *it, graph, connections, n_nodes, count);
        }
    }
}

tuple<unsigned short, unsigned short> get_cycle(unsigned short node, map<unsigned short, set<unsigned short>>& graph, bool*& visited, bool**& connections){
    visited[node - 1] = true;

    set<unsigned short>::iterator it;
    for(it = graph[node].begin(); it != graph[node].end(); it++){
        if(!connections[node - 1][*it - 1]){
            connections[node - 1][*it - 1] = true;
            connections[*it - 1][node - 1] = true;
            if(visited[*it - 1]){
                return make_tuple(node, *it);
            }else{
                tuple<unsigned short, unsigned short> cycle = get_cycle(*it, graph, visited, connections);
                if(get<0>(cycle) != 1001){
                    return cycle;
                }
            }
        }
    }

    return make_tuple(1001, 1001);
}

int main(){

    unsigned short n;
    cin >> n;

    map<unsigned short, set<unsigned short>> graph = map<unsigned short, set<unsigned short>>();

    bool* trees = new bool[n];
    memset(trees, false, n);

    bool* cycles = new bool[n];
    memset(cycles, false, n);
    unsigned short n_cycles = 0;

    bool** connections = new bool*[n];

    for(int i = 0; i < n; i++){
        connections[i] = new bool[n];
    }

    bool* visited = new bool[n];
    memset(visited, false, n);

    for(int i = 1; i <= n; i++){
        graph[i] = set<unsigned short>();
    }

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    

    map<unsigned short, set<unsigned short>>::iterator it;
    for(it = graph.begin(); it != graph.end(); it++){

        if(visited[it->first - 1]){
            continue;
        }

        for(int i = 0; i < n; i++){
            memset(connections[i], false, n);
        }
        unsigned short n_nodes = 0;
        int count = 0;

        get_neighbours(visited, it->first, graph, connections, n_nodes, count);

        if(count / 2 == n_nodes - 1){
            trees[it->first - 1] = true;
        }else{
            cycles[it->first - 1] = true;
            n_cycles++;
        }

    }

    set<tuple<unsigned short, unsigned short, unsigned short, unsigned short>> changes = set<tuple<unsigned short, unsigned short, unsigned short, unsigned short>>();

    while(n_cycles > 0){
        int node;
        int representant;

        for(int i = 0; i < n; i++){
            if(cycles[i]){
                node = i + 1;
                cycles[i] = false;
                break;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(trees[i]){
                representant = i + 1;
                trees[i] = false;
                break;
            }
        }

        n_cycles--;

        memset(visited, false, n);
        for(int i = 0; i < n; i++){
            memset(connections[i], false, n);
        }
        
        tuple<int, int> cycle = get_cycle(node, graph, visited, connections);
        int a = get<0>(cycle);
        int b = get<1>(cycle);

        changes.insert(make_tuple(a, b, a, representant));

        graph[a].erase(b);
        graph[b].erase(a);
        graph[a].insert(representant);
        graph[representant].insert(a);

        unsigned short n_nodes = 0;
        memset(visited, false, n);

        for(int i = 0; i < n; i++){
            memset(connections[i], false, n);
        }

        int count = 0;

        get_neighbours(visited, a, graph, connections, n_nodes, count);

        if(count / 2 == n_nodes - 1){
            trees[a - 1] = true;
        }else{
            cycles[a - 1] = true;
            n_cycles++;
        }
    }

    cout << changes.size() << endl;
    set<tuple<unsigned short, unsigned short, unsigned short, unsigned short>>::iterator it2;
    for(it2 = changes.begin(); it2 != changes.end(); it2++){
        cout << get<0>(*it2) << " " << get<1>(*it2) << " " << get<2>(*it2) << " " << get<3>(*it2) << endl;
    }

    return 0;
}