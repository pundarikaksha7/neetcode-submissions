class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> stars;

        int n = s.length();

        for(int i = 0;i<n;i++){
            char c = s[i];

            if(c =='(') left.push(i);
            else if(c=='*') stars.push(i);
            else{
                if(left.empty() && stars.empty()) return false;
                if(!left.empty()) left.pop();
                else if(!stars.empty()) stars.pop();
            }
        }

        while(!left.empty() && !stars.empty()){
            if(stars.top()<left.top()) return false;
            if(stars.empty() && !left.empty()) return false;
            stars.pop();
            left.pop();
        }
        return left.empty()==true;
    }
};
