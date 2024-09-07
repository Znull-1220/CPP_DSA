#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *
 * @return
 */
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int mid = nums.size() / 2;
    int val = 0;

    vector<int> res;
    for(int i = 0, j = mid; i < mid; i++, j++){
        val += abs(nums[j] - nums.back());
        res.push_back(nums[j]);
        res.push_back(nums[i]);
        val += abs(nums[j] - nums[i]);
    }

    if(nums.size() % 2 != 0){
        int last = res.back();
        res.push_back(nums[nums.size() - 1]);
        val += abs(nums[nums.size() - 1] - last);
    }

    val += abs(res[0] - res[res.size() - 1]);

    cout << val << endl;
    for(int i = 0; i < res.size() - 1; i++){
        cout << res[i] << ' ';
    }

    cout << res.back();
}
// 64 位输出请用 printf("%lld")