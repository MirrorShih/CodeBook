for(int i=0;i<n;i++)
    for(int j=w;j>=v[i].first;j--)
        dp[j]=max(dp[j],dp[j-v[i].first]+v[i].second);