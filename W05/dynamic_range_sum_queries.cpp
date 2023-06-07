#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

double sum(double a, double b) {
    return a + b;
}

class Node {
public:
    Node* left;
    Node* right;
    double value;
    std::pair<int, int> interval;

    Node(Node* left, Node* right, double value, std::pair<int, int> interval)
        : left(left), right(right), value(value), interval(interval) {}
};

Node* create_tree(std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return new Node(nullptr, nullptr, arr[left], std::make_pair(left, right));
    }

    int mid = (left + right) / 2;
    Node* n_left = create_tree(arr, left, mid);
    Node* n_right = create_tree(arr, mid + 1, right);

    return new Node(n_left, n_right, sum(n_left->value, n_right->value), std::make_pair(left, right));
}

void modify_tree(Node* head, int value, int pos) {
    if (!head) {
        return;
    }
    if (head->interval.first == pos && head->interval.second == pos) {
        head->value = value;
    } else if (head->interval.first <= pos && pos <= head->interval.second) {
        modify_tree(head->left, value, pos);
        modify_tree(head->right, value, pos);
        head->value = sum(head->left->value, head->right->value);
    }
}

void find_sum(Node* head, int a, int b, std::vector<double>& prevs) {
    if (!head || b < head->interval.first || a > head->interval.second) {
        return;
    }
    if (a <= head->interval.first && head->interval.second <= b) {
        prevs.push_back((double)head->value);
    } else {
        find_sum(head->left, a, b, prevs);
        find_sum(head->right, a, b, prevs);
    }
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<double> sums;
    Node* head = create_tree(arr, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int types, a, b;
        std::cin >> types >> a >> b;
        if (types == 1) {
            modify_tree(head, b, a - 1);
        } else {
            std::vector<double> m;
            find_sum(head, a - 1, b - 1, m);
            sums.push_back(std::accumulate(m.begin(), m.end(), 0.0));
        }
    }

    for (int i = 0; i < (int)sums.size(); i++) {
        std::cout.precision(0);
        std::cout<< std::fixed << sums[i] << std::endl;
    }

    return 0;
}