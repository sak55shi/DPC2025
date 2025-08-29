#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_set<char> charSet;
    int left = 0, maxLength = 0;
    
    for (int right = 0; right < n; right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "Input s = "
    getline(cin, s);
    
    
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
