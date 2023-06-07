#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Node {
public:
    Node* left;
    Node* right;
    int value;
    std::pair<int, int> interval;

    Node(Node* left, Node* right, int value, std::pair<int, int> interval)
        : left(left), right(right), value(value), interval(interval) {}
};

Node* create_tree(std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return new Node(nullptr, nullptr, arr[left], std::make_pair(left, right));
    }

    int mid = (left + right) / 2;
    Node* n_left = create_tree(arr, left, mid);
    Node* n_right = create_tree(arr, mid + 1, right);

    return new Node(n_left, n_right, std::min(n_left->value, n_right->value), std::make_pair(left, right));
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
        head->value = std::min(head->left->value, head->right->value);
    }
}

void find_min(Node* head, int a, int b, std::vector<int>& prevs) {
    if (!head || b < head->interval.first || a > head->interval.second) {
        return;
    }
    if (a <= head->interval.first && head->interval.second <= b) {
        prevs.push_back(head->value);
    } else {
        find_min(head->left, a, b, prevs);
        find_min(head->right, a, b, prevs);
    }
}

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> mins;
    Node* head = create_tree(arr, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int types, a, b;
        std::cin >> types >> a >> b;
        if (types == 1) {
            modify_tree(head, b, a - 1);
        } else {
            std::vector<int> m;
            find_min(head, a - 1, b - 1, m);
            mins.push_back(*std::min_element(m.begin(), m.end()));
        }
    }

    for (int i = 0; i < mins.size(); i++) {
        std::cout << mins[i] << std::endl;
    }

    return 0;
}