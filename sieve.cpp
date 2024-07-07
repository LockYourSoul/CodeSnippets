#include <iostream>
#include <vector>

using namespace std;

// seive of erastothenes
// returns primes until n (inlcusive)
vector <int> sieve(int n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j]=false;
        }
    }
    for(int i=0; i<=n ; i++){
        if(is_prime[i]==true)
            primes.push_back(i);
    }
    return primes;
}

int32_t main(){
    vector<int> primes;
    int n = 10;
    primes = sieve(n);
    for(auto it: primes)
        cout << it << " ";
    cout << endl;
}
