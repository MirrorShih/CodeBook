    dp.push_back(vec[0]);
    for(ll i=1;i<n;i++)
    {
        if(vec[i]>dp.back()) dp.push_back(vec[i]);
        else *lower_bound(dp.begin(),dp.end(),vec[i])=vec[i];
    }