class Solution {
public:

    string encode(vector<string>& a) {
        string ans;

        for (string &s : a) {
            for (char ch : s) {
                int ascii = (int)ch;
                ans += to_string(ascii);
                ans.push_back(',');
            }

            ans.push_back('_');
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string current;

        int num = 0;
        bool readingNum = false;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                readingNum = true;
            }

            else if (ch == ',') {
                if (readingNum) {
                    current += (char)num;
                    num = 0;
                    readingNum = false;
                }
            }

            else if (ch == '_') {
                if (readingNum) {
                    current += (char)num;
                    num = 0;
                    readingNum = false;
                }

                result.push_back(current);
                current.clear();
            }
        }

        return result;
    }
};
