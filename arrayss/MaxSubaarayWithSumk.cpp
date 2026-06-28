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

##### PREFIX SUM METHOD
    
    int longestSubarray(vector<int>& arr, int k) {
    unordered_map<long long, int> mp;
    long long sum = 0;
    int maxi = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == k)
            maxi = max(maxi, i + 1);

        if(mp.find(sum - k) != mp.end())
            maxi = max(maxi, i - mp[sum - k]);

        if(mp.find(sum) == mp.end())
            mp[sum] = i;   // store first occurrence only
    }

    return maxi;
}

/* yaha ek important baat h 
* for sum == k directly check the condition 
* if 0 is present in array may decrase lenght ( ex. [2,0,0,3]  so put condition 
 --if(mp.find(sum) == mp.end())
            mp[sum] = i;  
*/





