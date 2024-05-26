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
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    pbds<ll> pb;
    for(int i=0; i<k; i++)
    {
        pb.insert(a[i]);
    }
    ll sum=0;
    ll m= *pb.find_by_order(((k+1)/2)-1);
    for(int i=0; i<k; i++)
    {
        sum+=abs(a[i]-m);
    }
    cout<<sum<<" ";
    for(int i=0; i<n-k; i++)
    {
        pb.erase(pb.find_by_order(pb.order_of_key(a[i])));
        pb.insert(a[i+k]);
        ll mm= *pb.find_by_order(((k+1)/2)-1);
        sum=sum+abs(mm-a[i+k])-abs(m-a[i]);
        if(k%2==0)
        {
            sum-=(mm-m);
        }
        m=mm;
        cout<<sum<<" ";
    }
    cout<<'\n';
    return 0;
}