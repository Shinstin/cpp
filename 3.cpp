// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <unordered_map>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int nRet = 0;
    int nLeft = 0;
    unordered_map<char, int> mPos;
    for (int i=0; i<s.size(); i++) {
        if (mPos.find(s[i]) != mPos.end()) {
            // yes
            if (nLeft < mPos[s[i]] + 1) 
                nLeft = mPos[s[i]] + 1; 
            mPos[s[i]] = i;
        } else {
            mPos[s[i]] = i;
        }
        if (i - nLeft + 1 > nRet)
            nRet = i - nLeft + 1;
    }
    return nRet;
}

int main() 
{ 
    string sTest = "abba";
    cout << lengthOfLongestSubstring(sTest); 
    return 0; 
} 
