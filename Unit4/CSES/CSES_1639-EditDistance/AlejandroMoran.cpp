#include<bits/stdc++.h>
using namespace std;
 
int main(){
    string str,str2;
    cin>>str>>str2;
    int res[str.length()+1][str2.length()+1]={INT_MAX};
    for(int i=0;i<=str.length();i++)
        res[i][0]=i;
    for(int i=0;i<=str2.length();i++)
        res[0][i]=i;
    for(int i=1;i<=str.length();i++){
        for(int j=1;j<=str2.length();j++){
            if(str[i-1]!=str2[j-1])
                res[i][j]=min(res[i-1][j],min(res[i][j-1],res[i-1][j-1]))+1;
            else
                res[i][j]=res[i-1][j-1];
        }
    }
    printf("%d",res[str.length()][str2.length()]);
    return 0;
}
