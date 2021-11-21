#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    scanf("%lld", &n);
    vector<ll> sumas(n+1,0);
    int mod = 1e9+7;
    
    sumas[0] = 1;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= 6; j++){
            if(j>i) break;
            sumas[i] = (sumas[i] + sumas[i-j]) % mod;
        }
    }
    
    printf("%lld\n", sumas[n]);
}