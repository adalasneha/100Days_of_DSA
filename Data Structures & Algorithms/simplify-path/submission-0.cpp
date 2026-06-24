class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr;

        stringstream ss(path);

        while (getline(ss, curr, '/')) {
            if (curr.empty() || curr == ".") {
                continue;
            }
            else if (curr == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(curr);
            }
        }

        string result = "";

        for (string dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};