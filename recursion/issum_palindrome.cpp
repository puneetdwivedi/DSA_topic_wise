class Solution {
  public:
    int  ispalindrome(string st,int l,int r){
        if(l>r){
            return 1;
        }
        if(st[l]!=st[r])return 0;
        else return ispalindrome(st,l+1,r-1);
    }
    int isDigitSumPalindrome(int n) {
        int sum=0;
        while(n !=0){
            sum+=(n%10);
            n/=10;
        }
        string st=to_string(sum);
        return ispalindrome(st,0,st.length()-1);
        
    }
};