// Time: O(nlogn), Space: O(1)
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i + 1;
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        
        while (l < r) {
            while (l < r && nums[l] + nums[r] > target) {
                r--;
            }
            if (l < r && nums[l] + nums[r] == target) {
                auto res = vector<int>({mp[nums[l]], mp[nums[r]]});
                sort(res.begin(), res.end());
                return res;
            }
            l++;
        }
        return vector<int>({-1, -1});
    }
};

// Time: O(n), Space: O(n)

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int u = nums[i];
            int v = target - u;
            if (mp.find(v) != mp.end()) {
                return vector<int>({mp[v], i + 1});
            }
            mp[u] = i + 1;
        }
        return vector<int>();
    }
};


