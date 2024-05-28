#include <bits/stdc++.h>
#define ll long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc;
    cin>>tc;
    while (tc--)
    {
        ll n;
        cin>>n;
        vector<pair<ll, ll> > a(n);
        for(auto &x: a)
        {
            cin>>x.second>>x.first;
        }
        // for(auto x: a)
        // {
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        // cout<<"\n";
        sort(a.begin(), a.end());
        ll cnt=0;
        pbds<ll> pb;
        for(auto x: a)
        {
            // cout<<pb.size()<<" "<<pb.order_of_key(x.second)<<"\n";
            cnt+=pb.size()-pb.order_of_key(x.second);
            pb.insert(x.second);
        }
        cout<<cnt<<'\n';
    }
    
    return 0;
}