// #include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vs> vvs;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define accuracy (10e-6)
#define INF (1ll<<62)

void show(vs arr){
    for(string num : arr){
        cout << num << ' ';
    }
    cout << endl;
}


void show(vl arr){
    for(ll i=0; i<arr.size(); i++){
        if (i!=0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

void show(vvl mat){
    for(vl arr : mat){
        show(arr);
    }
    cout << endl;
}

void show(set<ll> s){
    for(ll num : s){
        cout << num << ' ';
    }
    cout << endl;
}

void show(map<pair<ll, ll>, ll> mp){
    for(pair<pair<ll, ll>, ll> p : mp){
        cout << p.first.first << ' ' << p.first.second << ": " << p.second << endl;
    }
    cout << endl;
}

void inputArray(vl &v){
    ll n = v.size();
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
}

void inputArray2(ll *ptr, ll n){
    for(ll i=0; i<n; i++){
        cin>>*(ptr+i);
    }
}

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    ll size = 7;
    bitset<7+5> file, ignore, tracked;

    for(ll i=0; i<m; i++){
        ll tmp; cin>>tmp;
        ignore[tmp]=1;
    }

    for(ll i=0; i<k; i++){
        ll tmp; cin>>tmp;
        tracked[tmp]=1;
    }


    bitset<7+5> ignoreTracked = ignore & tracked;
    bitset<7+5> unignoreUntracked = ~(ignore | tracked);
    // cout << ignore << endl;
    // cout << tracked << endl;
    // cout << ignoreTracked << endl;
    // cout << unignoreUntracked << endl;

    ll cntA = 0;
    for(ll i=1; i<=n; i++){
        cntA += (ignoreTracked[i]) ? 1 : 0;
    }

    ll cntB = 0;
    for(ll i=1; i<=n; i++){
        cntB += (unignoreUntracked[i]) ? 1 : 0;
    }

    cout << cntA << ' ' << cntB << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin>>tc;
    for(ll i=0; i<tc; i++){
        // cout << "Case #" << i+1 <<": ";
        solve();
    }
    return 0;
}