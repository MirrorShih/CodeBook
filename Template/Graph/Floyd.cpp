for(int k=0;k<dp.size();k++)
    for(int i=0;i<dp.size();i++)
        for(int j=0;j<dp.size();j++)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);