class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=1,r=1e16;
        while(l<r){
            long long mid=(l+r)/2;
            long long h=0;
            for(int w:workerTimes){
                h+=sqrt((2.0*mid)/w+0.25)-0.5;
                if(h>=mountainHeight) break;
            }
            if(h>=mountainHeight) r=mid;
            else l=mid+1;
        }
        return l;
    }
};