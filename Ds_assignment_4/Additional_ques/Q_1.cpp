class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> result;
        queue<string> q;
        q.push("1");
        for(int i = 0 ; i<n; i++){
            string s;
            s = q.front();
            q.pop();
            result.push_back(s);
            q.push(s+"0");
            q.push(s+"1");
        }
        return result;
    }
};
