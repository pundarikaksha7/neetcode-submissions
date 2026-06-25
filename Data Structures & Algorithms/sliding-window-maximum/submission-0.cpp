class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> maxheap;
        unordered_set<int> indexallowed;

        vector<int> ans;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; r++) {

            maxheap.push({nums[r], r});
            indexallowed.insert(r);

            if (r - l + 1 == k) {

                while (!maxheap.empty() &&
                       indexallowed.find(maxheap.top().second) == indexallowed.end()) {
                    maxheap.pop();
                }

                ans.push_back(maxheap.top().first);

                indexallowed.erase(l);
                l++;
            }
        }

        return ans;
    }
};