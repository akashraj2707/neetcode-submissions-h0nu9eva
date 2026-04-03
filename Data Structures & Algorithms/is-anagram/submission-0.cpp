class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> charS(26,0);

        for(int i=0;i<s.size();i++)
            charS[s[i]-'a']++;

        for(int i=0;i<t.size();i++){
            if(charS[t[i]-'a']==0)
                return false;

            charS[t[i]-'a']--;    
        }

        return true;    
    }
};
