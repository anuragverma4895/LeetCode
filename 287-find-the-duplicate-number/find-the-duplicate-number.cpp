class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // for(int i = 0; i < arr.size(); i++) {
        //     int index = abs(arr[i]);
        //     if(arr[index] < 0) return index;
        //     arr[index] = -arr[index];
        // }
        // return -1;

        int slow=arr[0];
        int fast=arr[0];
        do{
            slow=arr[slow];
            fast=arr[arr[fast]];
        }while(slow!=fast);

        slow=arr[0];
        while(slow!=fast){
            slow=arr[slow];
            fast=arr[fast];
        }
        return slow;
    }
};
