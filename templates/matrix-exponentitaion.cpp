#define i64 long long
#define ld long double
const i64 MOD = 1000000007;
const i64 base[2][2] = {{1, 1}, {1, 0}};
const i64 unit[2][2] = {{1, 0}, {0, 1}};
inline void mul(i64 a[2][2], i64 b[2][2]) {
	i64 r[2][2];
	r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
	r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
	r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
	r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
	a[0][0]=r[0][0];
	a[0][1]=r[0][1];
	a[1][0]=r[1][0];
	a[1][1]=r[1][1];
}

// r = base ^ n
inline void pwr(i64 r[2][2], long long n) {
	i64 b[2][2];
	r[0][0]=unit[0][0];
	r[0][1]=unit[0][1];
	r[1][0]=unit[1][0];
	r[1][1]=unit[1][1];
	b[0][0]=base[0][0];
	b[0][1]=base[0][1];
	b[1][0]=base[1][0];
	b[1][1]=base[1][1];
	while(n > 0) {
		if(n & 1) mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

// nth fib % MOD
inline i64 fibo(long long n) {
	i64 r[2][2];
	if(!n) return 0;
	pwr(r, n-1);
	return r[0][0];
}