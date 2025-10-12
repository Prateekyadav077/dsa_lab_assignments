class Solution {
public:
 int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
     for (int s : students) q.push(s);
 stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--) st.push(sandwiches[i]);        
    
    int count = 0;
    while(!q.empty()){
        if(q.front() == st.top()){
            q.pop();
            st.pop();
            count = 0;
        }
        else{
            int x = q.front();
            q.pop();
            q.push(x);
            count++;
        }
        if(q.size()==count){
            break;
        }
        
    }
    return count;}
};
