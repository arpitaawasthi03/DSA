class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<int> q;

        // Put all people (indices) into the queue
        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;

        while(!q.empty()) {

            int person = q.front();
            q.pop();

            tickets[person]--;
            time++;

            if(tickets[person] > 0) {
                q.push(person);
            }

            if(person == k && tickets[person] == 0) {
                break;
            }
        }

        return time;
    }
};