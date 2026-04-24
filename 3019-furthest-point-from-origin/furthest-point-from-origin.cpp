class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int L=count(s.begin(),s.end(),'L');
        int R=count(s.begin(),s.end(),'R');
        int D=count(s.begin(),s.end(),'_');
        return abs(L-R)+D;
    }
};