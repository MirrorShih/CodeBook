for(ll i=1;i<=m.size();i++)
    for(ll j=1;j<=b.size();j++)
        if(m[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);