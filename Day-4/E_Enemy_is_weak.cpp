#include <bits/stdc++.h>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pbds<ll> pb1;
    pbds<ll> pb2;
    for (ll i = 1; i < n; i++)
    {
        pb1.insert(a[i]);
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = pb2.size() - pb2.order_of_key(a[i] + 1);
        ll y = pb1.order_of_key(a[i]);
        cnt += x * y;
        pb2.insert(a[i]);
        pb1.erase(a[i + 1]);
    }
    cout << cnt << '\n';
    return 0;
}