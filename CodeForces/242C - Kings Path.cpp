#include<bits/stdc++.h>

using namespace std;
#define ll long long
map<pair<ll , ll> , ll> allowed;
queue<pair<ll , ll> > q;
ll dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0};
ll dy[] = {1 , 0 , -1 , 1 , 0 , -1 , 1 , -1};
int main()
{
    ll  n , x0 , y0 , x1 , y1 , r , a , b;
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> r >> a >> b;
        for(ll j = a ; j <= b ; j++)
        {
            allowed[make_pair(r , j)] = -1;
        }
    }
    allowed[pair<ll , ll>(x0 , y0)] = 0;
    q.push(make_pair(x0 , y0));
    while(!q.empty())
    {
        pair<ll , ll> u = q.front();
        q.pop();
        for(ll i = 0 ; i < 8 ; i++)
        {
            pair<ll , ll> v = pair<ll , ll>(u.first+dx[i] , u.second+dy[i]);
            if(allowed.count(v) && allowed[v] == -1)
            {
                allowed[v] = allowed[u] + 1;
                q.push(v);
            }
        }
    }
    cout << allowed[pair<ll , ll>(x1 , y1)];
    return 0;
}
