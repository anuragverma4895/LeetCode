class Solution {
public:
    int numberOfSubstrings(string s){
        // // TLE O(N^3)
        // int n = s.size();
        // int ans=0;
        // for (int i = 0; i < n; i++) {
        //     string t = "";
        //     for (int j = i; j < n; j++) {
        //         t += s[j];
        //         if (t.find('a') != string::npos && t.find('b') !=
        //         string::npos && t.find('c') != string::npos){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // // O(N^3) time and space both ||  not good approach MLE
        // int n = s.size();
        // int ans = 0;
        // vector<string> ss;
        // for (int i = 0; i < n; i++) {
        //     string t = "";
        //     for (int j = i; j < n; j++) {
        //         t += s[j];
        //         ss.push_back(t);
        //     }
        // }
        // for (int i = 0; i < ss.size(); i++) {
        //     string t=ss[i];
        //     if(t.size()>2){
        //     if (t.find('a') != string::npos && t.find('b') != string::npos &&
        //     t.find('c') != string::npos){
        //         ans++;
        //     }}
        // }
        // return ans;

        // BY using two pointer
        int n = s.size();

        int cnt[3] = {0};
        int l = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] && cnt[1] && cnt[2]) {
                ans += n - r;
                cnt[s[l] - 'a']--;
                l++;
            }
        }

        return ans;
    }
};