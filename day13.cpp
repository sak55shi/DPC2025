#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    
    int n = s.size();
    if (n == 0) return "";
    int start = 0, maxLength = 1;

    for (int i = 0; i < n; i++) {
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }

        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "Input : ";
    getline(cin, s);
    cout << longestPalindrome(s) << endl;
    return 0;
}
