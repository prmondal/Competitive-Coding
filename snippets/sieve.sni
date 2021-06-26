const int nax = 1e8+7;
vector<bool> is_prime(nax+1, 1);

void sieve() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= nax; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= nax; j += i)
                is_prime[j] = 0;
        }
    }                                                           
}