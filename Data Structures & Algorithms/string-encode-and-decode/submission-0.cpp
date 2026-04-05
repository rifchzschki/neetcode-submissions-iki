class Solution {

public:
    const char DEL = '^';
    string encode(vector<string>& strs) {
        string res;
        for(string s: strs){
            res = res + to_string(s.size()) + DEL + s;
        }
        // cout << "encode res: " << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int it = 0;
        while(it<s.size()){
            string sizeStr;
            while(s[it]!=DEL) {sizeStr += s[it]; it++;}
            // cout << "size: " << sizeStr << endl;
            int size = stoi(sizeStr);
            it++;
            string tmp;
            while(size>0){tmp+=s[it];it++;size--;}
            // cout << "str: " << tmp << endl;
            res.push_back(tmp);
        }
        return res;
    }
};
