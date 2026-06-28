int longestSubarray(vector<int>& arr, int k) {
    int left = 0, sum = 0, ans = 0;

    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];

        while(sum > k) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            ans = max(ans, right - left + 1);
        }
    }

    return ans;
}