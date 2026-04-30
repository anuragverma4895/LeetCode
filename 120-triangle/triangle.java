class Solution {
    public int minimumTotal(List<List<Integer>> t) {
        int n=t.size();
        for(int i = 1;i<t.size();i++){
            for(int j = 0;j<t.get(i).size();j++){
                if(j == 0){
                    int x = t.get(i).get(j);
                    t.get(i).set(j,x + t.get(i-1).get(j));
                }
                else if(j == t.get(i).size()-1){
                    t.get(i).set(j,(t.get(i).get(j)+t.get(i-1).get(j-1))) ;
                }
                else{
                    int a = t.get(i-1).get(j);
                    int b = t.get(i-1).get(j-1);
                    t.get(i).set(j, t.get(i).get(j)+ Math.min(a,b));
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        int m = t.get(n-1).size();
        for(int i = 0;i<t.size();i++){
            ans = Math.min(ans, t.get(n-1).get(i));
        }
        return ans;
    }
}