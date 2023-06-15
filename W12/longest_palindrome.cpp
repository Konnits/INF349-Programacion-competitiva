#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string transformedStr = "#";
    for (char c : str) {
        transformedStr += c;
        transformedStr += "#";
    }

    int n = transformedStr.length();
    vector<int> P(n, 0);
    int center = 0;
    int right = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            P[i] = min(right - i, P[mirror]);
        }

        int leftBoundary = i - (P[i] + 1);
        int rightBoundary = i + (P[i] + 1);
        while (leftBoundary >= 0 && rightBoundary < n && transformedStr[leftBoundary] == transformedStr[rightBoundary]) {
            P[i]++;
            leftBoundary--;
            rightBoundary++;
        }

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    int maxLength = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLength) {
            maxLength = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLength) / 2;
    string longestPalindrome = str.substr(start, maxLength);

    cout << longestPalindrome << endl;

    return 0;
}
