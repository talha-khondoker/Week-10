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
    while(tc--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        ll i=0;
        set<ll> st; // for store value
        ll sum=0;
        while (i<n)
        {
            if(a[i]<0) // check if a[i] negative
            {
                while (a[i]<0 && i<n) // As long as it is negative
                {
                    st.insert(a[i]); //  the value will enter
                    i++;
                }
                
            }
            else
            {
                while(a[i]>0 && i<n) // As long as it is positive
                {
                    st.insert(a[i]); //  the value will enter
                    i++;
                }
            }
            auto it=st.rbegin(); // find max value into that set, 
            sum+=*it; // add max value 
            st.clear(); // after one operation we must need clear the set
        }
        cout<<sum<<'\n';
    }
    return 0;
}