class Solution {
public:

    string encode(vector<string>& strs) {
        
        string res;
        string str;
        int temp;
        for(auto it: strs){
            str = it;

            for(auto it2:str){
                temp = (int) it2;
                res+= to_string(temp);
                res+="_";
            }
            res+=",";
        }

        return res;

        
    }

    vector<string> decode(string s) {
        cout<< s;
        vector<string> res;
        string temp="";
        int ch;
        for(int i=0;i<s.size();i++){
            if(s[i]==','){
                res.push_back(temp);
                temp.clear();
                ch=0;
                
            }else if(s[i]=='_'){
                temp+= (char) ch;
                ch=0;
            }
            else{
                ch*=10;
                ch+= (s[i]-'0');
            }
        }
        return res;
    }
};
