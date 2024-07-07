#include <iostream>
#define ll long long

using namespace std;

ll findPow(ll a, ll b){
    if(b==0)
    return 1;
    ll res=findPow(a,b/2);
    if(b%2)
        return res*res*a;
    else
        return res*res;
}

int main(){
    //finding power of a number in most optimised way
    cout<<findPow(2,20);
}