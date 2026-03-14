class Solution {
public:
    string maxValue(string n, int x) {
        char c = x + '0';
        
        if(n[0]=='-'){
            for(int i=1;i<n.size();i++){
                if(n[i]-'0' > x){
                    n.insert(n.begin()+i,c);
                    return n;
                }
            }
            n.push_back(c);
        } 
        else{
            for(int i=0;i<n.size();i++){
                if(n[i]-'0' < x){
                    n.insert(n.begin()+i,c);
                    return n;
                }
            }
            n.push_back(c);
        }
        
        return n;
    }
};