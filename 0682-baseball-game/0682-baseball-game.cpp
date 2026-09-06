class Solution {
public:
    int calPoints(vector<string>& ops) {
       stack<int> temp;
       int ans=0;
       for(int i = 0; i<ops.size(); i++){
        
        if(ops[i] == "C"){
            temp.pop();
        }else if(ops[i] == "D"){
            int a = (temp.top())*2;
            temp.push(a);
        }else if(ops[i] == "+"){
            int res;
            int b = temp.top();
            temp.pop();
            res= b + temp.top();
            temp.push(b);
            temp.push(res);
        }else{
            temp.push(stoi(ops[i]));
        }


       }
       while(temp.size() > 0){
           ans += temp.top();
           temp.pop();
       }
       return ans;
    }
};