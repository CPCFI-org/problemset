#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)   for (int i = (a); i > (b); i--)
#define TR(v, arr)      for(auto& (v) : (arr))
#define pint(x)         printf("%d\n", x);
#define pll(x)          printf("%lld\n", x);
#define si(x)           scanf("%d", &x);
#define sl(x)           scanf("%lld", &x);
#define all(x)          x.begin(), x.end()

typedef vector<int> vi;
typedef vector<long long> vll;

// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------

/*
Let a[i] be the number of times the number i appears in the input. 
Fill in this array as you take in the input. 
Afterwards, search through from a[0] to a[65535], summing up all of the values, until you exceed n/2.
The bin that puts you over n/2 must be the median. 
Of course, it's possible that two different values are the median if n is even, 
so watch out for that.
There are basically two cases for this problem:
Case 1: The median is unique (that is, n is odd, or n is even but the median is still unique)
- A is the median
- The number of numbers in the input that are A is a[A]
- Only 1 distinct integer could possibly be A.
Case 2: n is even, and there is no unique median
- A is the lower of the two medians
- The number of numbers in the input that could be A is a[low median] + a [high median]
- The number of distinct integers that could be A is (high median - low median + 1)
*/
void solve() {
    int n, a, number, numbers[65537] = {0}, lmedian, hmedian, sum, median;
    while (scanf("%d", &n) != EOF){
        sum = 0;
        FO(i, n){
            scanf("%d", &number);            
            numbers[number]++;
        }
        
        if(n % 2 != 0){
            median = (n/2)+1;
            FOR(i, 1, 65537){
                sum += numbers[i];
                if(sum>=median){ 
                    a = i;
                    break;
                }
            }
            printf("%d %d 1\n", a, numbers[a]);        
        } else {
            median = n/2;
            FOR(i, 1, 65537){
                sum += numbers[i];
                if(sum==median){ 
                    lmedian = i;
                    int j = i+1;
                    while(j<65537){
                        if(numbers[j]!=0){
                            hmedian = j;
                            break;
                        }
                        j++;
                    }
                    printf("%d %d %d\n", lmedian, numbers[lmedian]+numbers[hmedian], hmedian-lmedian+1);
                    break;
                }
                if(sum>median){
                    lmedian = i;
                    hmedian = i;
                    printf("%d %d 1\n", lmedian, numbers[lmedian]);
                    break;
                }
            }
        }
        memset(numbers, 0, sizeof(numbers));
    }
}

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}