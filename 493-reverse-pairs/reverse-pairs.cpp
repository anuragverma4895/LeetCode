class Solution {
public:
    int mergeSort(vector<int>& a, int l, int r){
        if(l >= r) return 0;
        
        int mid = (l + r) / 2;
        int count = 0;
        
        count += mergeSort(a, l, mid);
        count += mergeSort(a, mid + 1, r);
        
        int j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r && (long long)a[i] > 2LL * a[j]) j++;
            count += (j - (mid + 1));
        }
        
        vector<int> temp;
        int i = l;
        j = mid + 1;
        
        while(i <= mid && j <= r){
            if(a[i] <= a[j]) temp.push_back(a[i++]);
            else temp.push_back(a[j++]);
        }
        
        while(i <= mid) temp.push_back(a[i++]);
        while(j <= r) temp.push_back(a[j++]);
        
        for(int k = l; k <= r; k++){
            a[k] = temp[k - l];
        }
        
        return count;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return mergeSort(nums, 0, nums.size()-1);
    }
};