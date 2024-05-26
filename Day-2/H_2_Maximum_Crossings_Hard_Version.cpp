#include <bits/stdc++.h>
#define ll long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        vector<ll> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        pbds<ll> pb;
        ll cnt=0;
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                pb.insert(a[i]);
            }
            else
            {
                cnt+=pb.size()-pb.order_of_key(a[i]);
                pb.insert(a[i]);
            }
        }
        cout<<cnt<<'\n';
    }
    
    return 0;
}