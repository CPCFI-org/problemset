#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string input_file = file + "in";
    string output_file = file + "out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}

bool compareTask(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    if (getenv("CP_IO")) { setIO(); }
    
    long long t,a,d,f,reward=0,time=0;
    
    vector<pair<long, long> > tasks;
    
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&a,&d);
        tasks.push_back(make_pair(a,d));
    }
    sort(tasks.begin(),tasks.end(),compareTask);

    for(auto& t : tasks){
        a = t.first; 
        f = time + a;
        time += a;
        reward += t.second - f;
    }

    printf("%lld\n",reward);
    return 0;
}