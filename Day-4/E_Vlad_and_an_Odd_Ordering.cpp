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
        ll n, k;
        cin>>n>>k;
        ll ans=0;
        for(int i=1; i<=log2(n)+1; i++)
        {
            ll x=pow(2,i); // find gap between two numbers;
            ll y=(n+(x/2))/x; // how many numbers in that gap
            if(k<=y)
            {
                if(k==1)
                {
                    ans=(x/2); // first value
                    break;;
                }
                else
                {
                    ans=(x/2)+((k-1)*x); 
                    // cout<<ans<<'\n';
                    break;
                }
            }
            else
            {
                k-=y;
            }
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}