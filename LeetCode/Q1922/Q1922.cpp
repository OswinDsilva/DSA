long long binaryExponentHelper(long long base, long long power){
    const int mod = (1e9) + 7;
    if(power == 0){
        return 1;
    }
    if(power % 2 != 0){
        return (base * binaryExponentHelper((base*base) % mod, power/2)) % mod;
    }else{
        return binaryExponentHelper((base*base) % mod, power/2);
    }
}
int countGoodNumbers(long long n) {
    if(n == 0){
        return 1;
    }
    const int mod = (1e9) + 7;
    long long a = binaryExponentHelper(5,(n+1)/2) % mod;
    long long b = binaryExponentHelper(4,n/2) % mod;
    return (a * b) % mod;
}