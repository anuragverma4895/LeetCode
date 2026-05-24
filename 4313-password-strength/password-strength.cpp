class Solution {
public:
    int ans=0;
    int passwordStrength(string pas) {
        sort(pas.begin(),pas.end());
        int n=pas.size();
        for(int i=0;i<n;i++){
            char c =pas[i];
            if(i+1 && pas[i]!=pas[i+1]){
            if(islower(c)) ans+=1;
            else if(isupper(c)) ans+=2;
            else if(isdigit(c)) ans+=3;
            else ans+=5;}
        }
        return ans;
    }
};