class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = speed.size();

        for(int i = 0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());

        stack<double> times;
        //if the time of a car from the behind is less than or equal to 
        // the car infront of it ie speed is more then we dont consider it

        for(int i = 0;i<n;i++){
            auto car = cars[i];
            double timecar = (double)(target-car.first)/car.second;

            if(times.empty() || times.top()<timecar){
                times.push(timecar);
            }
        }
        return times.size();
    }
};
