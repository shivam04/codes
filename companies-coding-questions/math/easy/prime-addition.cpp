bool isPrime(int n) {
    if (n == 1) {
    return false;
  }

  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}
int Solution::solve(int A) {
    if(isPrime(A)) {
        return 1;
    } else if(A%2==0) {
        return 2;
    } else {
        if(isPrime(A-2)) {
            return 2;
        } else {
            return 3;
        }
    }
}
