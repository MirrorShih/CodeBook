vector<ll> tmp(v.begin(),v.end());
sort(tmp.begin(),tmp.end());
tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
for(auto &e:v) e=lower_bound(tmp.begin(),tmp.end(),e)-tmp.begin()+1;