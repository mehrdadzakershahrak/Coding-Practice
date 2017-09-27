int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for(int start = n; start >= 1; --start)
            for(int end = start; end <= n; ++end)
                for(int lastdelete = start; lastdelete <= end; ++lastdelete)
                    dp[start][end] = max(dp[start][end], dp[start][lastdelete-1] +
                        nums[start-1] * nums[lastdelete] * nums[end+1] +
                        dp[lastdelete+1][end]);

        return dp[1][n];
    }
