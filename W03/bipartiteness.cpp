#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

using namespace std;

void color_graph(int node, vector<int>& colors, int color, unordered_map<int, unordered_set<int>>& nodes_dict, unordered_set<int>& colored) {
    colors[node] = color;
    colored.insert(node);
    for (const auto& neighbor : nodes_dict[node]) {
        if (colors[neighbor] == -1) {
            color_graph(neighbor, colors, 1 - color, nodes_dict, colored);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> nodes(n - 1);
    unordered_map<int, unordered_set<int>> nodes_dict;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nodes[i] = make_pair(a, b);
        nodes_dict[a - 1].insert(b - 1);
        nodes_dict[b - 1].insert(a - 1);
    }

    vector<int> colors(n, -1);
    unordered_set<int> colored {0};

    color_graph(0, colors, 0, nodes_dict, colored);

    int count = 0;
    double n_left = 0.0;
    for (const auto& color : colors) {
        if (color == 0) {
            n_left++;
        }
    }

    cout << fixed << setprecision(0) << n_left * (static_cast<double>(n) - n_left) - static_cast<double>(n) + 1.0 << endl;

    return 0;
}
