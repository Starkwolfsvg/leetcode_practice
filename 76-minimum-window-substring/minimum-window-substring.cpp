class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (n>m) return "";
        unordered_map<char, int> mp;
        //store t in map
        for(char& ch: t){
            mp[ch]++;
        }
        int requiredCount = n;
        int i =0, j=0;
        int min_windowSize = INT_MAX;
        int start_i = 0;
        while(j<m){
            char ch = s[j];
            if(mp[ch]>0)
                requiredCount--;
            mp[ch]--;
            //try to shrink window if required count =0;
            while(requiredCount ==0){
                int curr_windowSize = j-i+1;
                if(min_windowSize>curr_windowSize){
                    min_windowSize = curr_windowSize;
                    start_i = i;
                } 
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    requiredCount++;
                }
                i++;

            }
            j++;
            
        }
        if(min_windowSize ==INT_MAX) return "";
        else return s.substr(start_i, min_windowSize);
    }
};