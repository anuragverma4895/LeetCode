class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>freq1(26,-1);
        vector<int>freq2(26,-1);
        for(int i=0;i<n;i++){
            char aq=word[i];
            if(islower(aq)){
                freq1[aq-'a']=0;
            }else{
                freq2[aq-'A']=0;
            }
        }
        int count=0;
        for(int i=0;i<freq1.size();i++){
            if(freq1[i]==0 && freq2[i]==0) count++;
        }
        return count;
    }
};