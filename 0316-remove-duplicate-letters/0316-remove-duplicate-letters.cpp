class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        stack<char> stack;
        unordered_set<char> vis;
        unordered_map<char, int> occ;
        for (int i = 0; i < s.size(); i++) {
            occ[s[i]] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (vis.find(c) == vis.end()) {
                while (!stack.empty() && c < stack.top() && i < occ[stack.top()]) {
                    vis.erase(stack.top());
                    stack.pop();
                }
                vis.insert(c);
                stack.push(c);
            }
        }
        
        string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};