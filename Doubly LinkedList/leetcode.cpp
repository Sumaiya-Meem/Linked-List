class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int cnt = nums.size();
    vector<pair<int, int>> mp(cnt);

    for (int i = 0; i < cnt; ++i) {
        int originalNum = nums[i];
        string s = "";
        
        if (originalNum == 0) {
            s = to_string(mapping[0]);
        } else {
            while (originalNum > 0) {
                int digit = originalNum % 10;
                s = to_string(mapping[digit]) + s;
                originalNum /= 10;
            }
        }

        int mappedNum = stoi(s);
        mp[i] = {mappedNum, i};
    }

    sort(mp.begin(), mp.end());

    vector<int> ans;
    for (const auto& pair : mp) {
        ans.push_back(nums[pair.second]);
    }

    return ans;
}
};