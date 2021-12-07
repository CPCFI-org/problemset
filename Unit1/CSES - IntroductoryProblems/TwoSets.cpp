//c++ TwoSets.cpp -o test.o; ./test.o < test.in
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define si(x)           scanf("%d", &x);

void solve(){
    int n; si(n)
    /*
    Your task is to divide the numbers 1,2,…,n into two sets of equal sum. 
    */
    if(n%4 == 1 || n%4 == 2) { //There are no possible options
        printf("NO\n");
        
    } else if(n%4 == 3){ 

        printf("YES\n");
        printf("%d\n", n/2);
        for(int i = 2; i <= n/2; i += 2){ 
            printf("%d %d ", i, n-i);
        }
        printf("%d\n%d\n", n, n/2+1); 
        for(int i = 1; i <= n/2; i += 2){ 
            printf("%d %d ", i, n-i);
        }
    } else {

        printf("YES\n");
        printf("%d\n", n/2);
        for(int i = 2; i <= n/2; i += 2){ 
            printf("%d %d ", i, n-i+1);
        }
        printf("\n%d\n", n/2); 
        for(int i = 1; i <= n/2; i += 2){
            printf("%d %d ", i, n-i+1);
        }
    }
}

/* TIME LIMIT EXCEEDED */ 
// void solve() {
//     int n; si(n)

//     //All values
//     vector<int> weights; 
//     for (int i=1; i<=n; i++){
//         weights.push_back(i);
//     }

//     bool posible_sum = false;
//     for (int i=0; i<(1<<n); i++){
//         //All posible combinations
//         vector<int> A; 
//         vector<int> B; 
//         int sumA = 0; 
//         int sumB = 0; 
//         for (int j=0; j<n; j++){
//             if(i&(1<<j)) {
//                 A.push_back(weights[j]);
//                 sumA += weights[j]; //With 0
//             } else {
//                 B.push_back(weights[j]);
//                 sumB += weights[j]; //With 1
//             }
//         }
//         if (sumA == sumB){
//             posible_sum = true;
//             printf("YES\n");
//             printf("%ld \n", A.size());
//             for (int i=0;i<A.size(); i++){
//                 printf("%d ", A[i]);
//             }
//             printf("\n%ld \n", B.size());
//             for (int i=0;i<B.size(); i++){
//                 printf("%d ", B[i]);
//             }
//             break;
//         }
//     }

//     if (!posible_sum){
//         printf("NO");
//     }
// }

int main() {
    int T=1;
    FO(tc, T){
        solve();
    }
    return 0;
}