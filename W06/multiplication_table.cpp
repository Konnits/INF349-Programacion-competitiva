#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

ll f(ll x){
    ll cnt = 0;
    for(ll i = 1; i <= N; i++){
        cnt += min(x / i, N);
    }
    return cnt;
}

int main(){
    
    scanf("%lld", &N);
    ll lo = 0, hi = N*N;
    while(hi - lo > 1){
        ll mid = (lo + hi) / 2;
        if(f(mid) >= (N * N + 1) / 2){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    printf("%lld\n", hi);
}