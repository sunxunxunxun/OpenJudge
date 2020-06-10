class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost=0;
        int n = costs.size();
        int refund[n];
        //send all people to city A
        for(int i=0;i<n;i++){
            totalCost += costs[i][0];
            //refund repensents invalid pay or more needed pay
            refund[i] = costs[i][1] - costs[i][0];
        }
        //ensure there are exactly n/2 people in A & B 
        sort(refund, refund + n); //ascending order
        int cnt = 0;
        while(cnt<n/2){
                totalCost += refund[cnt];
                cnt++;
            }
        return totalCost;
    }
};
