class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        for(int i=0,j=n-1;i<j && i<n && j>=0;) {
            while(!(isalpha(s[i]) || isdigit(s[i])) && i<n)
                i++;
            while(!(isalpha(s[j]) || isdigit(s[i])) && j>=0)
                j--;
            if(i>j)
                return true;
            if((i<=j && i<n && j>=0 && tolower(s[i])==tolower(s[j])) == false)
                return false;
            // cout<<s[i]<< " " <<s[j]<<"\n";
            i++;
            j--;
        }
        return true;
    }
};
