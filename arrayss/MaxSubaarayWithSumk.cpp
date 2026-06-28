int longestSubarray(vector<int>& arr, int k) {
    int left = 0, sum = 0, ans = 0;            
    
    /*REMEBER ELEMENTS CAN ONLY BE POSITIVE FOR NEGATIVE SILDIG WIN FAILS!*/

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

/*

Maan lo array hai:

[1, 2, 1, 1, 1, 3]
K = 3

Hum do pointers rakhte hain:

left → window ka start
right → window ka end

Aur ek sum maintain karte hain.

Logic:
right ko aage badhao aur element add karo.
Agar sum > K ho jaye, to left ko aage badha kar sum kam karo.
Agar sum == K, to window length update karo.

    */
