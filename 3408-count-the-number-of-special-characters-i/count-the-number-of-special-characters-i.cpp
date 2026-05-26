class Solution {
public:
    // int numberOfSpecialChars(string word) {
    //     int n=word.size();
    //     vector<int>freq1(26,-1);
    //     vector<int>freq2(26,-1);
    //     for(int i=0;i<n;i++){
    //         char aq=word[i];
    //         if(islower(aq)){
    //             freq1[aq-'a']=0;
    //         }else{
    //             freq2[aq-'A']=0;
    //         }
    //     }
    //     int count=0;
    //     for(int i=0;i<freq1.size();i++){
    //         if(freq1[i]==0 && freq2[i]==0) count++;
    //     }
    //     return count;
    // }

    int numberOfSpecialChars(string word) {
        sort(word.begin(), word.end());

        int n = word.size();
        int pt2 = 0;

        for (int i = 0; i < n; i++) {
            if (islower(word[i])) {
                pt2 = i;
                break;
            }
        }

        int ans = 0;

        int i = 0;
        int j = pt2;

        while (i < pt2 && j < n) {

            int up = word[i] - 'A';
            int low = word[j] - 'a';

            if (up == low) {

                ans++;

                char cu = word[i];
                char cl = word[j];

                while (i < pt2 && word[i] == cu)
                    i++;
                while (j < n && word[j] == cl)
                    j++;

            } else if (up < low) {

                char cu = word[i];
                while (i < pt2 && word[i] == cu)
                    i++;

            } else {

                char cl = word[j];
                while (j < n && word[j] == cl)
                    j++;
            }
        }

        return ans;
    }
};