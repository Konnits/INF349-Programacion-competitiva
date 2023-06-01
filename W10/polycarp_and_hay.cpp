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
 
void print_graph(map<tuple<short, short>, set<tuple<short, short>>> graph){
    cout << "Graph:" << endl;
    map<tuple<short, short>, set<tuple<short, short>>>::iterator it;
    for(it = graph.begin(); it != graph.end(); it++){
        cout << "(" << get<0>(it->first) << ", " << get<1>(it->first) << ") -> ";
        set<tuple<short, short>>::iterator neighbour;
        for(neighbour = it->second.begin(); neighbour != it->second.end(); neighbour++){
            cout << "(" << get<0>(*neighbour) << ", " << get<1>(*neighbour) << ") ";
        }
        cout << endl;
    }
    cout << endl;
}
 
void get_graph(map<tuple<short, short>, set<tuple<short, short>>>& graph, unsigned int** matrix, int n, int m){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != 0){
                set<tuple<short, short>> neighbours;
 
                if(i > 0 && matrix[i - 1][j] != 0){
                    neighbours.insert(tuple<short, short>(i - 1, j));
                }
 
                if(j > 0 && matrix[i][j - 1] != 0){
                    neighbours.insert(tuple<short, short>(i, j - 1));
                }
 
                if(i < n - 1 && matrix[i + 1][j] != 0){
                    neighbours.insert(tuple<short, short>(i + 1, j));
                }
 
                if(j < m - 1 && matrix[i][j + 1] != 0){
                    neighbours.insert(tuple<short, short>(i, j + 1));
                }
 
                tuple<short, short> key = make_tuple(i, j);
                graph.insert(pair<tuple<short, short>, set<tuple<short, short>>>(key, neighbours));
            }
        }
    }
}
 
void print_matrix(unsigned int** matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
 
void get_neighbours(map<tuple<short, short>, set<tuple<short, short>>>& graph, const tuple<short, short>& actual, bool**& visited, unsigned int& n_visited, int& max_size){
    if (n_visited >= max_size) {
        return;
    }
 
    visited[get<0>(actual)][get<1>(actual)] = true;
    n_visited++;
 
    for (const auto& neighbor : graph[actual]){
        if (visited[get<0>(neighbor)][get<1>(neighbor)]) {
            continue;
        }

        get_neighbours(graph, neighbor, visited, n_visited, max_size);
    }
}
 
 
void get_neighbours_of_size(bool**& neighbours, map<tuple<short, short>, set<tuple<short, short>>>& graph, unsigned int** matrix, int size, unsigned int value, unsigned short n, unsigned short m, unsigned int& n_visited){
 
    set<tuple<short, short>> nodes;
    for (const auto& entry : graph){
        if (matrix[get<0>(entry.first)][get<1>(entry.first)] == value){
            nodes.emplace(entry.first);
        }
    }
 
    bool** visited;
    bool found_neighbours = false;

    visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
        memset(visited[i], false, m * sizeof(bool));
    }
 
    while(!nodes.empty()){
        auto node = *nodes.begin();
        nodes.erase(nodes.begin());
 
        if(visited[get<0>(node)][get<1>(node)]) {
            continue;
        }

        n_visited = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                neighbours[i][j] = false;
            }
        }
        
        get_neighbours(graph, node, neighbours, n_visited, size);
 
        if (n_visited >= size){
            found_neighbours = true;
            visited[get<0>(node)][get<1>(node)] = true;
            break;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(neighbours[i][j]){
                    visited[i][j] = true;
                }
            }
        }
    }

    if (!found_neighbours){
        n_visited = 0;
    }
}
 
void print_neighbours(bool** neighbours, unsigned short n, unsigned short m){
    cout << "Neighbours:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << neighbours[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
int main() {
 
    string value;
    getline(cin, value);
 
    int start = 0;
 
    unsigned long long n = get_number(value, start), m = get_number(value, start), k = get_number(value, start);
    unsigned int** matrix = new unsigned int*[n];
 
    set<unsigned int> divisors;
 
    for(int i = 0; i < n; i++){
        matrix[i] = new unsigned int[m];
    }
 
    for(int i = 0; i < n; i++){
 
        getline(cin, value);
        int start = 0;
        for(int j = 0; j < m; j++){
            matrix[i][j] = get_number(value, start);
            if(matrix[i][j] != 0 && k % (unsigned long long)matrix[i][j] == 0){
                divisors.insert(matrix[i][j]);
            }
        }
    }
 
    bool polycarp = false;
 
    unsigned int** matrix_copy = new unsigned int*[n];
 
    for(unsigned int i = 0; i < n; i++){
        matrix_copy[i] = new unsigned int[m];
    }
 
    set<unsigned int>::iterator it;
    for(it = divisors.begin(); it != divisors.end(); it++){
        int n_divisors_allowed = 0;
        unsigned long long sum = 0;
 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix_copy[i][j] = matrix[i][j];
                if(matrix_copy[i][j] < *it){
                    matrix_copy[i][j] = 0;
                }else{
                    n_divisors_allowed++;
                }
            }
        }
 
        if((unsigned long long)n_divisors_allowed * (unsigned long long)*it < k){
            continue;
        }
 
        map<tuple<short, short>, set<tuple<short, short>>> graph;
        get_graph(graph, matrix_copy, n, m);
 
        if(graph.size() == 0){
            continue;
        }
 
        unsigned long size = k / *it;
        
        unsigned int n_neighbours;
        bool** neighbours = new bool*[n];

        for(int i = 0; i < n; i++){
            neighbours[i] = new bool[m];
            memset(neighbours[i], false, m * sizeof(bool));
        }
 
        get_neighbours_of_size(neighbours, graph, matrix_copy, size, *it, n, m, n_neighbours);

        if(n_neighbours < size){
            continue;
        }
 
        sum = (unsigned long long)n_neighbours * (unsigned long long)*it;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(neighbours[i][j]){
                    matrix_copy[i][j] = *it;
                }else{
                    matrix_copy[i][j] = 0;
                }
            }
        }
 
        if(sum == k){
            map<tuple<short, short>, set<tuple<short, short>>>().swap(graph);
            polycarp = true;
            break;
        }
 
    }
 
    if(polycarp){
        cout << "YES" << endl;
        print_matrix(matrix_copy, n, m);
    }else{
        cout << "NO" << endl;
    }
 
    return 0;
}