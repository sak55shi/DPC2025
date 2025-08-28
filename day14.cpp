 #include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

int countAtMostKDistinct(string s, int k) {
    int n = s.length();
    unordered_map<char, int> freq;
    int left = 0;
    int count = 0;
    for (int right = 0; right < n; right++) {
        freq[s[right]]++;
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int countSubstringsWithExactlyKDistinct(string s, int k) {
    if (k == 0) return 0;
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}

int main() {
    string input;
    cout << "Input: ";
    getline(cin, input);

        string s;
    int k;
    size_t s_start = input.find('"');
    if (s_start != string::npos) {
        size_t s_end = input.find('"', s_start + 1);
        if (s_end != string::npos) {
            s = input.substr(s_start + 1, s_end - s_start - 1);
        }
    }

    size_t k_start = input.find("k = ");
    if (k_start != string::npos) {
        k_start += 4;
        size_t k_end = input.find_first_not_of("0123456789", k_start);
        if (k_end == string::npos) {
            k_end = input.length();
        }
        string k_str = input.substr(k_start, k_end - k_start);
        k = stoi(k_str);
    }

    cout << countSubstringsWithExactlyKDistinct(s, k) << endl;
    return 0;
}
