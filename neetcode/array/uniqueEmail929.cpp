

// E https://leetcode.com/problems/unique-email-addresses/description/
// use string manipulation techinques. like substr and replace
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (string email:emails) {
            string cleanemail;
            for(char c : email) {
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                cleanEmail += c;
            }
            cleanEmail += email.substr(email.find('@'));
            st.insert(cleanEmail);
            
        }
        return st.size();   
    }
};