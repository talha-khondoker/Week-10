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
    priority_queue<pair<ll, ll>> pq;
    vector<bool> flag;
    ll i=0, idx=0;
    ll q;
    cin>>q;
    while (q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll m;
            cin>>m;
            pq.push({m, -idx});
            idx++;
            flag.push_back(false);
        }
        else if(x==2)
        {
            while (flag[i])
            {
                i++;
            }
            flag[i]=true;
            cout<<i+1<<" ";
        }
        else if(x==3)
        {
            // cout<<pq.top().first<<" ";
            // cout<<pq.top().second<<" ";
            // pq.pop();
            // i--;
            while (flag[-pq.top().second])
            {
                pq.pop();
            }
            cout<<-pq.top().second+1<<" ";
            flag[-pq.top().second]=true;
            pq.pop();
        }
    }
    
    return 0;
}