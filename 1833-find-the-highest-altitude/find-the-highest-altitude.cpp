class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> gainVector(n+1);
        gainVector[0] = 0;
        for ( int i =1; i<n+1; i++){
            gainVector[i] = gainVector[i-1] + gain [i-1];
        }
        int max = 0;
        for(int j = 0; j<n+1; j++){
            if(gainVector[j]> max)
                max = gainVector[j];
        }
        for(int num: gainVector){
            cout<<num<<" ";
        }
        return max;
    }
};
