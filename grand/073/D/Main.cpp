#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

bool dbg = false;

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl
#else
#define dmp(x) void(0)
#endif

template <class t, class u>
bool chmax(t &a, u b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	else
		return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	else
		return false;
}

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;

using pi = pair<int, int>;
using vi = vc<int>;
using vvi = vc<vc<int>>;

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p)
{
	return os << "{" << p.a << "," << p.b << "}";
}

template <class t>
ostream &operator<<(ostream &os, const vc<t> &v)
{
	os << "{";
	for (auto e : v)
		os << e << ",";
	return os << "}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x, -1, sizeof(x))
#define zero(x) memset(x, 0, sizeof(x))
#ifdef LOCAL
void dmpr(ostream &os) { os << endl; }
template <class T, class... Args>
void dmpr(ostream &os, const T &t, const Args &...args)
{
	os << t << " ";
	dmpr(os, args...);
}
#define dmp2(...) dmpr(cerr, __LINE__, ##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint = unsigned;
using ull = unsigned long long;

template <class t, size_t n>
ostream &operator<<(ostream &os, const array<t, n> &a)
{
	return os << vc<t>(all(a));
}

ll rand_int(ll l, ll r)
{ //[l, r]
	// #ifdef LOCAL
	static mt19937_64 gen;
	/*#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif*/
	return uniform_int_distribution<ll>(l, r)(gen);
}

ll rand_int(ll k)
{ //[0,k)
	return rand_int(0, k - 1);
}
string rand_string(int n, char lw, char up)
{
	string s(n, '?');
	rep(i, n) s[i] = rand_int(lw, up);
	return s;
}

int current_run_id, run_batch_size = 1000;
int calc_random_limit()
{
	return current_run_id / run_batch_size + 1;
}
template <class t>
void generate_single(t &a)
{
	a = rand_int(1, calc_random_limit());
}
void generate_single(string &a)
{
	int n;
	generate_single(n);
	a = rand_string(n, 'a', 'b');
}
template <class t, class u>
void generate_single(pair<t, u> &a)
{
	generate_single(a.a);
	generate_single(a.b);
}
// https://trap.jp/post/1224/
template <class... Args>
void input(Args &...a)
{
	if (dbg)
	{
		(generate_single(a), ...);
	}
	else
	{
#ifdef USE_FAST_IO
		sc.read(a...);
#else
		(cin >> ... >> a);
#endif
	}
}
#define INT(...)     \
	int __VA_ARGS__; \
	input(__VA_ARGS__)
#define LL(...)     \
	ll __VA_ARGS__; \
	input(__VA_ARGS__)
#define ULL(...)     \
	ull __VA_ARGS__; \
	input(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	input(__VA_ARGS__)
#define CHR(...)      \
	char __VA_ARGS__; \
	input(__VA_ARGS__)
#define DBL(...)        \
	double __VA_ARGS__; \
	input(__VA_ARGS__)
#define LD(...)     \
	ld __VA_ARGS__; \
	input(__VA_ARGS__)
#define overload3(a, b, c, d, ...) d
#define VI2(name, size) \
	vi name(size);      \
	rep(i_##name, size) input(name[i_##name]);
#define VI3(name, size, offset) \
	vi name(size);              \
	rep(i_##name, size) input(name[i_##name]), name[i_##name] += offset;
#define VI(...) overload3(__VA_ARGS__, VI3, VI2)(__VA_ARGS__)
#define VPI(name, size) \
	vc<pi> name(size);  \
	rep(i_##name, size) input(name[i_##name].a, name[i_##name].b);
#define VVI(name, sizeN, sizeM) \
	vvi name(sizeN, vi(sizeM)); \
	rep(i_##name, sizeN) rep(j_##name, sizeM) input(name[i_##name][j_##name]);
#define VS(name, size)     \
	vc<string> name(size); \
	rep(i_##name, size) input(name[i_##name]);
#define VMI(name, size)              \
	vc<mint> name(size);             \
	rep(i_##name, size)              \
	{                                \
		INT(tmp_##name);             \
		name[i_##name] = tmp_##name; \
	};

#define overload5(a, b, c, d, e, f, ...) f
#define VVC4(type, name, sizeN, sizeM) vvc<type> name(sizeN, vc<type>(sizeM));
#define VVC5(type, name, sizeN, sizeM, ini) vvc<type> name(sizeN, vc<type>(sizeM, ini));
#define VVC(...) overload5(__VA_ARGS__, VVC5, VVC4)(__VA_ARGS__)

template <class T>
T vvvc(T v)
{
	return v;
}

template <class T, class... Args>
auto vvvc(int n, T v, Args... args)
{
	return vector(n, vvvc(v, args...));
}

template <int i, class T>
void print_tuple(ostream &, const T &)
{
}

template <int i, class T, class H, class... Args>
void print_tuple(ostream &os, const T &t)
{
	if (i)
		os << ",";
	os << get<i>(t);
	print_tuple<i + 1, T, Args...>(os, t);
}

template <class... Args>
ostream &operator<<(ostream &os, const tuple<Args...> &t)
{
	os << "{";
	print_tuple<0, tuple<Args...>, Args...>(os, t);
	return os << "}";
}

void printsuc(int suc)
{
#ifdef USE_FAST_IO
	if (suc == 1)
		pr.write('\n');
	if (suc == 2)
		pr.write(' ');
#else
	if (suc == 1)
	{
		if (dbg)
			cout << endl;
		else
		{
#ifdef LOCAL
			cout << endl;
#else
			cout << "\n";
#endif
		}
	}
	if (suc == 2)
		cout << " ";
#endif
}

template <class t>
void print_single(t x, int suc = 1)
{
#ifdef USE_FAST_IO
	pr.write(x);
#else
	cout << x;
#endif
	printsuc(suc);
}

template <class t, class u>
void print_single(const pair<t, u> &p, int suc = 1)
{
	print_single(p.a, 2);
	print_single(p.b, suc);
}

template <class T>
void print_single(const vector<T> &v, int suc = 1)
{
	rep(i, v.size())
		print_single(v[i], i == int(v.size()) - 1 ? 3 : 2);
	printsuc(suc);
}

template <class T, size_t N>
void print_single(const array<T, N> &v, int suc = 1)
{
	rep(i, N)
		print_single(v[i], i == int(N) - 1 ? 3 : 2);
	printsuc(suc);
}

template <class T>
void print(const T &t)
{
	print_single(t);
}

template <class T, class... Args>
void print(const T &t, const Args &...args)
{
	print_single(t, 2);
	print(args...);
}

template <class T>
void printvv(const vvc<T> &vs)
{
	for (const auto &row : vs)
		print(row);
}

string readString()
{
	string s;
	cin >> s;
	return s;
}

template <class T>
T sq(const T &t)
{
	return t * t;
}

void YES(bool ex = true)
{
	cout << "YES\n";
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}
void NO(bool ex = true)
{
	cout << "NO\n";
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}
void Yes(bool ex = true)
{
	cout << "Yes\n";
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}
void No(bool ex = true)
{
	cout << "No\n";
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}
// #define CAPITAL
/*
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}*/
void possible(bool ex = true)
{
#ifdef CAPITAL
	cout << "POSSIBLE" << "\n";
#else
	cout << "Possible" << "\n";
#endif
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}
void impossible(bool ex = true)
{
#ifdef CAPITAL
	cout << "IMPOSSIBLE" << "\n";
#else
	cout << "Impossible" << "\n";
#endif
	if (ex)
		exit(0);
#ifdef LOCAL
	cout.flush();
#endif
}

constexpr ll ten(int n)
{
	return n == 0 ? 1 : ten(n - 1) * 10;
}

const ll infLL = LLONG_MAX / 3;

#ifdef int
const int inf = infLL;
#else
const int inf = INT_MAX / 2 - 100;
#endif

int topbit(signed t)
{
	return t == 0 ? -1 : 31 - __builtin_clz(t);
}
int topbit(ll t)
{
	return t == 0 ? -1 : 63 - __builtin_clzll(t);
}
int topbit(ull t)
{
	return t == 0 ? -1 : 63 - __builtin_clzll(t);
}
int botbit(signed a)
{
	return a == 0 ? 32 : __builtin_ctz(a);
}
int botbit(ll a)
{
	return a == 0 ? 64 : __builtin_ctzll(a);
}
int botbit(ull a)
{
	return a == 0 ? 64 : __builtin_ctzll(a);
}
int popcount(signed t)
{
	return __builtin_popcount(t);
}
int popcount(ll t)
{
	return __builtin_popcountll(t);
}
int popcount(ull t)
{
	return __builtin_popcountll(t);
}
int bitparity(ll t)
{
	return __builtin_parityll(t);
}
bool ispow2(int i)
{
	return i && (i & -i) == i;
}
ll mask(int i)
{
	return (ll(1) << i) - 1;
}
ull umask(int i)
{
	return (ull(1) << i) - 1;
}
ll minp2(ll n)
{
	if (n <= 1)
		return 1;
	else
		return ll(1) << (topbit(n - 1) + 1);
}

bool inc(int a, int b, int c)
{
	return a <= b && b <= c;
}

template <class S>
void mkuni(S &v)
{
	sort(all(v));
	v.erase(unique(all(v)), v.ed);
}

template <class t>
bool isuni(vc<t> v)
{
	int s = si(v);
	mkuni(v);
	return si(v) == s;
}

bool isperm(const vi &p)
{
	int n = si(p);
	vc<bool> used(n);
	for (auto v : p)
	{
		if (!inc(0, v, n - 1))
			return false;
		if (used[v])
			return false;
		used[v] = true;
	}
	return true;
}

template <class t>
void myshuffle(vc<t> &a)
{
	rep(i, si(a)) swap(a[i], a[rand_int(0, i)]);
}

template <class S, class u>
int lwb(const S &v, const u &a)
{
	return lower_bound(all(v), a) - v.bg;
}
template <class t, class u>
bool bis(const vc<t> &v, const u &a)
{
	return binary_search(all(v), a);
}

// VERIFY: yosupo
// KUPC2017J
// AOJDSL1A
// without rank
struct unionfind
{
	vi p, s;
	int c;
	unionfind(int n) : p(n, -1), s(n, 1), c(n) {}
	void clear()
	{
		fill(all(p), -1);
		fill(all(s), 1);
		c = si(p);
	}
	int find(int a)
	{
		return p[a] == -1 ? a : (p[a] = find(p[a]));
	}
	// set b to a child of a
	bool unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)
			return false;
		p[b] = a;
		s[a] += s[b];
		c--;
		return true;
	}
	bool same(int a, int b)
	{
		return find(a) == find(b);
	}
	int sz(int a)
	{
		return s[find(a)];
	}
};

vvc<int> readGraph(int n, int m)
{
	vvc<int> g(n);
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		// sc.read(a,b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> initUG(int n, const vc<pi> &es)
{
	vvc<int> g(n);
	for (auto [a, b] : es)
	{
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> rand_tree(int n)
{
	vvc<int> t(n);
	unionfind uf(n);
	while (uf.c > 1)
	{
		int a = rand_int(n);
		int b = rand_int(n);
		if (uf.unite(a, b))
		{
			t[a].pb(b);
			t[b].pb(a);
		}
	}
	return t;
}

vvc<int> readTree(int n)
{
	if (dbg)
	{
		return rand_tree(n);
	}
	else
	{
		return readGraph(n, n - 1);
	}
}

vi readRooted(int n)
{
	assert(!dbg);
	vi par(n, -1);
	rng(i, 1, n)
	{
		input(par[i]);
		par[i]--;
		assert(inc(0, par[i], i - 1));
	}
	return par;
}

void printTree(const vvc<int> t)
{
	int n = si(t);
	int degsum = 0;
	rep(i, n) degsum += si(t[i]);
	if (degsum == n - 1)
	{
		// directed
		rep(i, si(t)) for (auto j : t[i])
		{
			print(i + 1, j + 1);
		}
	}
	else if (degsum == 2 * (n - 1))
	{
		// undirected
		rep(i, si(t)) for (auto j : t[i]) if (i < j)
		{
			print(i + 1, j + 1);
		}
	}
	else
	{
		assert(false);
	}
}

template <class t>
vc<t> presum(const vc<t> &a)
{
	vc<t> s(si(a) + 1);
	rep(i, si(a)) s[i + 1] = s[i] + a[i];
	return s;
}
vc<ll> presum(const vi &a)
{
	vc<ll> s(si(a) + 1);
	rep(i, si(a)) s[i + 1] = s[i] + a[i];
	return s;
}
// BIT で数列を管理するときに使う (CF850C)
template <class t>
vc<t> predif(vc<t> a)
{
	gnr(i, 1, si(a)) a[i] -= a[i - 1];
	return a;
}
template <class t>
vvc<ll> imos(const vvc<t> &a)
{
	int n = si(a), m = si(a[0]);
	vvc<ll> b(n + 1, vc<ll>(m + 1));
	rep(i, n) rep(j, m)
		b[i + 1][j + 1] = b[i + 1][j] + b[i][j + 1] - b[i][j] + a[i][j];
	return b;
}

// verify してないや
void transvvc(int &n, int &m)
{
	swap(n, m);
}
template <class t, class... Args>
void transvvc(int &n, int &m, vvc<t> &a, Args &...args)
{
	assert(si(a) == n);
	vvc<t> b(m, vi(n));
	rep(i, n)
	{
		assert(si(a[i]) == m);
		rep(j, m) b[j][i] = a[i][j];
	}
	a.swap(b);
	transvvc(n, m, args...);
}
// CF854E
void rotvvc(int &n, int &m)
{
	swap(n, m);
}
template <class t, class... Args>
void rotvvc(int &n, int &m, vvc<t> &a, Args &...args)
{
	assert(si(a) == n);
	vvc<t> b(m, vi(n));
	rep(i, n)
	{
		assert(si(a[i]) == m);
		rep(j, m) b[m - 1 - j][i] = a[i][j];
	}
	a.swap(b);
	rotvvc(n, m, args...);
}

// ソートして i 番目が idx[i]
// CF850C
template <class t>
vi sortidx(const vc<t> &a)
{
	int n = si(a);
	vi idx(n);
	iota(all(idx), 0);
	sort(all(idx), [&](int i, int j)
		 { return a[i] < a[j]; });
	return idx;
}
// vs[i]=a[idx[i]]
// 例えば sortidx で得た idx を使えば単にソート列になって返ってくる
// CF850C
template <class t>
vc<t> a_idx(const vc<t> &a, const vi &idx)
{
	int n = si(a);
	assert(si(idx) == n);
	vc<t> vs(n);
	rep(i, n) vs[i] = a[idx[i]];
	return vs;
}
// CF850C
vi invperm(const vi &p)
{
	int n = si(p);
	vi q(n);
	rep(i, n) q[p[i]] = i;
	return q;
}

template <class t, class s = t>
s SUM(const vc<t> &a)
{
	return accumulate(all(a), s(0));
}
template <class t, size_t K, class s = t>
s SUM(const array<t, K> &a)
{
	return accumulate(all(a), s(0));
}

template <class t>
t MAX(const vc<t> &a)
{
	return *max_element(all(a));
}

template <class t>
pair<t, int> MAXi(const vc<t> &a)
{
	auto itr = max_element(all(a));
	return mp(*itr, itr - a.bg);
}

template <class A>
auto MIN(const A &a)
{
	return *min_element(all(a));
}

template <class t>
pair<t, int> MINi(const vc<t> &a)
{
	auto itr = min_element(all(a));
	return mp(*itr, itr - a.bg);
}

vi vid(int n)
{
	vi res(n);
	iota(all(res), 0);
	return res;
}

template <class S>
void soin(S &s)
{
	sort(all(s));
}

template <class S, class F>
void soin(S &s, F &&f)
{
	sort(all(s), forward<F>(f));
}

template <class S>
S soout(S s)
{
	soin(s);
	return s;
}

template <class S>
void rein(S &s)
{
	reverse(all(s));
}

template <class S>
S reout(S s)
{
	rein(s);
	return s;
}

template <class t, class u>
pair<t, u> &operator+=(pair<t, u> &a, pair<t, u> b)
{
	a.a += b.a;
	a.b += b.b;
	return a;
}
template <class t, class u>
pair<t, u> &operator-=(pair<t, u> &a, pair<t, u> b)
{
	a.a -= b.a;
	a.b -= b.b;
	return a;
}
template <class t, class u>
pair<t, u> operator+(pair<t, u> a, pair<t, u> b) { return mp(a.a + b.a, a.b + b.b); }
template <class t, class u>
pair<t, u> operator-(pair<t, u> a, pair<t, u> b) { return mp(a.a - b.a, a.b - b.b); }
template <class t, class u, class v>
pair<t, u> &operator*=(pair<t, u> &a, v b)
{
	a.a *= b;
	a.b *= b;
	return a;
}
template <class t, class u, class v>
pair<t, u> operator*(pair<t, u> a, v b) { return a *= b; }
template <class t, class u>
pair<t, u> operator-(pair<t, u> a) { return mp(-a.a, -a.b); }
namespace std
{
	template <class t, class u>
	istream &operator>>(istream &is, pair<t, u> &a)
	{
		return is >> a.a >> a.b;
	}
}

template <class t, size_t n>
array<t, n> &operator+=(array<t, n> &a, const array<t, n> &b)
{
	rep(i, n) a[i] += b[i];
	return a;
}
template <class t, size_t n>
array<t, n> &operator-=(array<t, n> &a, const array<t, n> &b)
{
	rep(i, n) a[i] -= b[i];
	return a;
}
template <class t, size_t n, class v>
array<t, n> &operator*=(array<t, n> &a, v b)
{
	rep(i, n) a[i] *= b;
	return a;
}
template <class t, size_t n>
array<t, n> operator+(array<t, n> a, const array<t, n> &b) { return a += b; }
template <class t, size_t n>
array<t, n> operator-(array<t, n> a, const array<t, n> &b) { return a -= b; }
template <class t, size_t n, class v>
array<t, n> operator*(array<t, n> a, v b) { return a *= b; }

template <class t>
t gpp(vc<t> &vs)
{
	assert(si(vs));
	t res = move(vs.back());
	vs.pop_back();
	return res;
}

template <class t, class u>
void pb(vc<t> &a, const vc<u> &b)
{
	a.insert(a.ed, all(b));
}

template <class t, class... Args>
vc<t> cat(vc<t> a, Args &&...b)
{
	(pb(a, forward<Args>(b)), ...);
	return a;
}

template <class t, class u>
vc<t> &operator+=(vc<t> &a, u x)
{
	for (auto &v : a)
		v += x;
	return a;
}

template <class t, class u>
vc<t> operator+(vc<t> a, u x)
{
	return a += x;
}

template <class t>
vc<t> &operator+=(vc<t> &a, const vc<t> &b)
{
	a.resize(max(si(a), si(b)));
	rep(i, si(b)) a[i] += b[i];
	return a;
}

template <class t>
vc<t> operator+(const vc<t> &a, const vc<t> &b)
{
	vc<t> c(max(si(a), si(b)));
	rep(i, si(a)) c[i] += a[i];
	rep(i, si(b)) c[i] += b[i];
	return c;
}

template <class t, class u>
vc<t> &operator-=(vc<t> &a, u x)
{
	for (auto &v : a)
		v -= x;
	return a;
}
template <class t, class u>
vc<t> operator-(vc<t> a, u x)
{
	return a -= x;
}
template <class t>
vc<t> &operator-=(vc<t> &a, const vc<t> &b)
{
	a.resize(max(si(a), si(b)));
	rep(i, si(b)) a[i] -= b[i];
	return a;
}
template <class t>
vc<t> operator-(const vc<t> &a, const vc<t> &b)
{
	vc<t> c(max(si(a), si(b)));
	rep(i, si(a)) c[i] += a[i];
	rep(i, si(b)) c[i] -= b[i];
	return c;
}
template <class t, class u>
vc<t> &operator*=(vc<t> &a, u x)
{
	for (auto &v : a)
		v *= x;
	return a;
}
template <class t, class u>
vc<t> operator*(vc<t> a, u x)
{
	return a *= x;
}

template <class t, class u>
vc<t> &operator/=(vc<t> &a, u x)
{
	for (auto &v : a)
		v /= x;
	return a;
}
template <class t, class u>
vc<t> operator/(vc<t> a, u x)
{
	return a /= x;
}

template <class t>
vc<t> &operator<<=(vc<t> &a, int k)
{
	assert(k >= 0);
	a.insert(a.bg, k, t(0));
	return a;
}
template <class t>
vc<t> operator<<(vc<t> a, int k)
{
	return a <<= k;
}

template <class t>
vc<t> &operator>>=(vc<t> &a, int k)
{
	if (si(a) <= k)
		a.clear();
	else
		a.erase(a.bg, a.bg + k);
	return a;
}
template <class t>
vc<t> operator>>(vc<t> a, int k)
{
	return a >>= k;
}

// 消した要素の個数を返してくれる
// not verified
template <class t, class u>
int remval(vc<t> &a, const u &v)
{
	auto itr = remove(all(a), v);
	int res = a.ed - itr;
	a.erase(itr, a.ed);
	return res;
}
// 消した要素の個数を返してくれる
// UCUP 2-8-F
template <class t, class F>
int remif(vc<t> &a, F f)
{
	auto itr = remove_if(all(a), f);
	int res = a.ed - itr;
	a.erase(itr, a.ed);
	return res;
}
template <class t>
void rempos(vc<t> &a, int i)
{
	assert(inc(0, i, si(a) - 1));
	a.erase(a.bg + i);
}

template <class VS, class u>
void fila(VS &vs, const u &a)
{
	fill(all(vs), a);
}

template <class t, class u>
int findid(const vc<t> &vs, const u &a)
{
	auto itr = find(all(vs), a);
	if (itr == vs.ed)
		return -1;
	else
		return itr - vs.bg;
}

template <class t>
void rtt(vc<t> &vs, int i)
{
	rotate(vs.bg, vs.bg + i, vs.ed);
}

// Multiuni2023-8 C
// f(lw)=false,...,f(n-1)=false,f(n)=true,...,f(up)=true,
// のときに n を返す
template <class F>
int find_min_true(int lw, int up, F f)
{
	while (up - lw > 1)
	{
		const int mid = (lw + up) / 2;
		if (f(mid))
			up = mid;
		else
			lw = mid;
	}
	return up;
}
// f(lw)=true,f(up)=false
template <class F>
int find_max_true(int lw, int up, F f)
{
	while (up - lw > 1)
	{
		const int mid = (lw + up) / 2;
		if (f(mid))
			lw = mid;
		else
			up = mid;
	}
	return lw;
}

template <class t>
using pqmin = priority_queue<t, vc<t>, greater<t>>;
template <class t>
using pqmax = priority_queue<t>;
using T = tuple<int, int, int>;

// N() が単位元
// VERIFY: yosupo
// CF407E
template <class N>
struct segtree
{
	vc<N> x;
	int n, s;
	segtree() {}
	template <class t>
	segtree(const vc<t> &a)
	{
		n = a.size();
		s = 1;
		while (s < n)
		{
			s *= 2;
		}
		x.resize(s * 2);
		rep(i, n)
			x[s + i] = N(a[i]);
		gnr(i, 1, s)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	// NOT Verified
	segtree(int nn)
	{
		resize(nn);
	}
	void resize(int nn)
	{
		n = nn;
		s = 1;
		while (s < n)
		{
			s *= 2;
		}
		x.assign(s * 2, N());
		gnr(i, 1, s)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	template <class t>
	void init(const vc<t> &a)
	{
		n = a.size();
		s = 1;
		while (s < n)
		{
			s *= 2;
		}
		x.resize(s * 2);
		rep(i, n)
			x[s + i] = N(a[i]);
		rng(i, n, s)
			x[s + i] = N();
		gnr(i, 1, s)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	void clear()
	{
		rep(i, n)
			x[s + i] = N();
		gnr(i, 1, s)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	N point_get(int i)
	{
		assert(inc(0, i, n - 1));
		return x[i + s];
	}
	void point_set(int i, const N &t)
	{
		assert(inc(0, i, n - 1));
		i += s;
		x[i] = t;
		while (i >>= 1)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	void point_merge(int i, const N &t)
	{
		assert(inc(0, i, n - 1));
		i += s;
		x[i] = N::merge(x[i], t);
		while (i >>= 1)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	template <class F, class... Args>
	void point_change(int i, F f, Args &&...args)
	{
		assert(inc(0, i, n - 1));
		i += s;
		(x[i].*f)(forward<Args>(args)...);
		while (i >>= 1)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	N composite(int b, int e)
	{
		assert(0 <= b && b <= e && e <= n);
		N lf, rt;
		for (int l = b + s, r = e + s; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
			{
				lf = N::merge(lf, x[l]);
				l++;
			}
			if (r & 1)
			{
				r--;
				rt = N::merge(x[r], rt);
			}
		}
		return N::merge(lf, rt);
	}
	N getall()
	{
		return x[1];
	}
	// used in namori-bisect
	template <class F, class... Args>
	pair<int, N> max_right_withinit(int l, N sm, F f, Args &&...args)
	{
		assert((sm.*f)(forward<Args>(args)...));
		assert(0 <= l && l <= n);
		if (l == n)
			return mp(n, sm);
		l += s;

		assert((sm.*f)(forward<Args>(args)...));
		do
		{
			while (l % 2 == 0)
				l >>= 1;
			if (!(N::merge(sm, x[l]).*f)(forward<Args>(args)...))
			{
				while (l < s)
				{
					l = (2 * l);
					N tmp = N::merge(sm, x[l]);
					if ((tmp.*f)(forward<Args>(args)...))
					{
						sm = tmp;
						l++;
					}
				}
				return mp(l - s, sm);
			}
			sm = N::merge(sm, x[l]);
			l++;
		} while ((l & -l) != l);
		return mp(n, sm);
	}
	// UCUP-2-22-K
	template <class F, class... Args>
	pair<int, N> min_left_withinit(int r, N sm, F f, Args &&...args)
	{
		assert((sm.*f)(forward<Args>(args)...));
		assert(0 <= r && r <= n);
		if (r == 0)
			return mp(0, sm);
		r += s;
		do
		{
			r--;
			while (r > 1 && (r % 2))
				r >>= 1;
			if (!(N::merge(x[r], sm).*f)(forward<Args>(args)...))
			{
				while (r < s)
				{
					r = (2 * r + 1);
					N tmp = N::merge(x[r], sm);
					if ((tmp.*f)(forward<Args>(args)...))
					{
						sm = tmp;
						r--;
					}
				}
				return mp(r + 1 - s, sm);
			}
			sm = N::merge(x[r], sm);
		} while ((r & -r) != r);
		return mp(0, sm);
	}
	// UTPC2020E
	// n 超えるかもしれない
	template <class F, class... Args>
	pair<int, N> max_right(int l, F f, Args &&...args)
	{
		return max_right_withinit(l, N(), f, forward<Args>(args)...);
	}
	// UTPC2020E
	template <class F, class... Args>
	pair<int, N> min_left(int r, F f, Args &&...args)
	{
		return min_left_withinit(r, N(), f, forward<Args>(args)...);
	}
	// 行列とか乗せて必要なのはベクトルとの積，みたいなときに使える？
	// CF Goodbye 2016 E
	// CF 896 F
	template <class F, class T, class... Args>
	T accumulate(int l, int r, F f, T t, Args &&...args)
	{
		assert(0 <= l && l <= r && r <= n);
		static int buf[2][30];
		int cnt[2]{};
		for (l += s, r += s; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				buf[0][cnt[0]++] = l;
			if (r & 1)
				buf[1][cnt[1]++] = r - 1;
			l++;
		}
		rep(i, cnt[0]) t = (x[buf[0][i]].*f)(t, forward<Args>(args)...);
		per(i, cnt[1]) t = (x[buf[1][i]].*f)(t, forward<Args>(args)...);
		return t;
	}
};

// atcoder-library をまあまあコピーして使っている

// N() が単位元

// merge で片方が inactive のときはもう片方をそのまま返す，
// といったときに，lazy の情報までコピーして渡さないようにする

// クエリできる点が[0,s)だったのを[0,n)に変えた (UCUP1-21D)
// ch,max_rightは動くと思う
// ちゃんと test してないから assert とかが壊れたらごめん

// VERIFY:
// https://atcoder.jp/contests/practice2/tasks/practice2_k
template <class N, bool Beats = false>
struct seglazy
{
	vc<N> x;
	int n, L, s;
	seglazy() {}
	template <class T>
	seglazy(const vc<T> &a)
	{
		n = a.size();
		L = 0;
		while ((1 << L) < n)
			L++;
		s = 1 << L;
		x.resize(s * 2);
		rep(i, n) x[s + i] = N(a[i]);
		gnr(i, 1, s) upd(i);
	}
	seglazy(int nn)
	{
		n = nn;
		L = 0;
		while ((1 << L) < n)
			L++;
		s = 1 << L;
		x.assign(s * 2, N());
		gnr(i, 1, s) upd(i);
	}
	template <class t>
	void init(const vc<t> &a)
	{
		n = a.size();
		L = 0;
		while ((1 << L) < n)
			L++;
		s = 1 << L;
		x.resize(s * 2);
		rep(i, n)
			x[s + i] = N(a[i]);
		rng(i, n, s)
			x[s + i] = N();
		gnr(i, 1, s)
			x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	void upd(int i)
	{
		x[i] = N::merge(x[i * 2], x[i * 2 + 1]);
	}
	void push(int i)
	{
		x[i].push(x[i * 2], x[i * 2 + 1]);
	}
	// 空ノードなしで動く ver が segbeats_norec に書いてある
	N composite(int l, int r)
	{
		assert(0 <= l && l <= r && r <= n);
		if (l == r)
			return N();

		l += s;
		r += s;

		for (int i = L; i >= 1; i--)
		{
			if (((l >> i) << i) != l)
				push(l >> i);
			if (((r >> i) << i) != r)
				push((r - 1) >> i);
		}

		N sml, smr;
		while (l < r)
		{
			if (l & 1)
				sml = N::merge(sml, x[l++]);
			if (r & 1)
				smr = N::merge(x[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return N::merge(sml, smr);
	}
	//[l,r)内の極大区間について f(i) を呼ぶ
	// UCUP3-26-L
	template <class F>
	void foreach_range(int l, int r, F f)
	{
		assert(0 <= l && l <= r && r <= n);
		if (l == r)
			return;

		l += s;
		r += s;

		for (int i = L; i >= 1; i--)
		{
			if (((l >> i) << i) != l)
				push(l >> i);
			if (((r >> i) << i) != r)
				push((r - 1) >> i);
		}

		while (l < r)
		{
			if (l & 1)
				f(l++);
			if (r & 1)
				f(--r);
			l >>= 1;
			r >>= 1;
		}
	}
	// UCUP1-21 D
	// JSC2024FinalD
	template <class F, class... Args>
	void ch_beats(int i, F f, Args &&...args)
	{
		int ini = i;
		while (1)
		{
			if ((x[i].*f)(forward<Args>(args)...))
			{
				while (i > ini && (i & 1))
				{
					i >>= 1;
					upd(i);
				}
				if (i == ini)
					break;
				i++;
			}
			else
			{
				assert(i < s);
				push(i);
				i *= 2;
			}
		}
	}
	template <class F, class... Args>
	void ch(int l, int r, F f, Args &&...args)
	{
		assert(0 <= l && l <= r && r <= n);
		if (l == r)
			return;

		l += s;
		r += s;

		for (int i = L; i >= 1; i--)
		{
			if (((l >> i) << i) != l)
				push(l >> i);
			if (((r >> i) << i) != r)
				push((r - 1) >> i);
		}

		static int buf[2][30];
		int cnt[2]{};
		{
			int l2 = l, r2 = r;
			while (l < r)
			{
				if (l & 1)
				{
					//(x[l++].*f)(forward<Args>(args)...);
					buf[0][cnt[0]++] = l++;
				}
				if (r & 1)
				{
					//(x[--r].*f)(forward<Args>(args)...);
					buf[1][cnt[1]++] = --r;
				}
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}
		if constexpr (Beats)
		{
			rep(i, cnt[0]) ch_beats(buf[0][i], f, forward<Args>(args)...);
			per(i, cnt[1]) ch_beats(buf[1][i], f, forward<Args>(args)...);
		}
		else
		{
			rep(i, cnt[0])(x[buf[0][i]].*f)(forward<Args>(args)...);
			per(i, cnt[1])(x[buf[1][i]].*f)(forward<Args>(args)...);
		}

		for (int i = 1; i <= L; i++)
		{
			if (((l >> i) << i) != l)
				upd(l >> i);
			if (((r >> i) << i) != r)
				upd((r - 1) >> i);
		}
	}
	template <class F, class... Args>
	void chall(F f, Args &&...args)
	{
		if constexpr (Beats)
		{
			ch_beats(1, f, forward<Args>(args)...);
		}
		else
		{
			(x[1].*f)(forward<Args>(args)...);
		}
	}
	N getall() { return x[1]; }
	template <class F, class... Args>
	pair<int, N> max_right(int l, F f, Args &&...args)
	{
		assert(0 <= l && l <= n);
		if (l == n)
			return mp(n, N());
		l += s;

		for (int i = L; i >= 1; i--)
			push(l >> i);
		N sm;
		assert((sm.*f)(forward<Args>(args)...));
		do
		{
			while (l % 2 == 0)
				l >>= 1;
			if (!(N::merge(sm, x[l]).*f)(forward<Args>(args)...))
			{
				while (l < s)
				{
					push(l);
					l = (2 * l);
					N tmp = N::merge(sm, x[l]);
					if ((tmp.*f)(forward<Args>(args)...))
					{
						sm = tmp;
						l++;
					}
				}
				return mp(l - s, sm);
			}
			sm = N::merge(sm, x[l]);
			l++;
		} while ((l & -l) != l);
		return mp(n, sm);
	}
	// XXI Opencup Krakow M
	template <class F, class... Args>
	pair<int, N> min_left(int r, F f, Args &&...args)
	{
		assert(0 <= r && r <= n);
		if (r == 0)
			return mp(0, N());
		r += s;
		for (int i = L; i >= 1; i--)
			push((r - 1) >> i);
		N sm;
		do
		{
			r--;
			while (r > 1 && (r % 2))
				r >>= 1;
			if (!(N::merge(x[r], sm).*f)(forward<Args>(args)...))
			{
				while (r < s)
				{
					push(r);
					r = (2 * r + 1);
					N tmp = N::merge(x[r], sm);
					if ((tmp.*f)(forward<Args>(args)...))
					{
						sm = tmp;
						r--;
					}
				}
				return mp(r + 1 - s, sm);
			}
			sm = N::merge(x[r], sm);
		} while ((r & -r) != r);
		return mp(0, sm);
	}
	template <class F, class... Args>
	void point_change(int p, F f, Args &&...args)
	{
		assert(0 <= p && p < n);
		p += s;
		for (int i = L; i >= 1; i--)
			push(p >> i);
		(x[p].*f)(forward<Args>(args)...);
		for (int i = 1; i <= L; i++)
			upd(p >> i);
	}
	void point_merge(int p, const N &t)
	{
		assert(0 <= p && p < n);
		p += s;
		for (int i = L; i >= 1; i--)
			push(p >> i);
		x[p] = N::merge(x[p], t);
		for (int i = 1; i <= L; i++)
			upd(p >> i);
	}
	N point_get(int p)
	{
		assert(0 <= p && p < n);
		p += s;
		for (int i = L; i >= 1; i--)
			push(p >> i);
		return x[p];
	}
	void point_set(int p, N val)
	{
		assert(0 <= p && p < n);
		p += s;
		for (int i = L; i >= 1; i--)
			push(p >> i);
		x[p] = val;
		for (int i = 1; i <= L; i++)
			upd(p >> i);
	}
	void enumerater(int l, int r, int i, int b, int e, vc<N> &dst)
	{
		if (e <= l || r <= b)
			return;
		if (l + 1 == r)
		{
			dst.pb(x[i]);
			return;
		}
		push(i);
		int m = (l + r) / 2;
		enumerater(l, m, i * 2, b, e, dst);
		enumerater(m, r, i * 2 + 1, b, e, dst);
	}
	void enumerate(int b, int e, vc<N> &dst)
	{
		assert(0 <= b && b <= e && e <= n);
		return enumerater(0, s, 1, b, e, dst);
	}
};

struct MinNode
{
	int v;
	MinNode(int vv = inf) : v(vv) {}
	static MinNode merge(const MinNode &a, const MinNode &b)
	{
		return MinNode(min(a.v, b.v));
	}
	bool ok(int x) { return x <= v; }
};

// Range add,min
struct AddMin
{
	int lz, mn;
	AddMin(int v = inf) : lz(0), mn(v) {}
	void add(int v)
	{
		mn += v;
		lz += v;
	}
	void push(AddMin &x, AddMin &y)
	{
		x.add(lz);
		y.add(lz);
		lz = 0;
	}
	static AddMin merge(AddMin x, AddMin y)
	{
		return AddMin(min(x.getm(), y.getm()));
	}
	int getm() { return mn; }
	bool ok(int v)
	{
		return mn >= v;
	}
};

const int kmax = 4;
int globalW[kmax];
const pi none(inf, -1);
pi add(pi a, pi b)
{
	return pi(a.a + b.a, max(a.b, b.b));
}
struct N
{
	pi v[kmax + 1][kmax + 1];
	N(bool identity = true)
	{
		rep(i, kmax + 1) rep(j, kmax + 1) v[i][j] = none;
		if (identity)
			rep(i, kmax + 1) v[i][i] = pi(0, -1);
	}
	N(int best, bool star, int idx)
	{
		rep(i, kmax + 1) rep(j, kmax + 1) v[i][j] = none;
		rep(i, kmax)
		{
			int j = min(i, best);
			v[i][j] = pi(globalW[j], -1);
			if (!star)
				v[i][kmax] = pi(0, -1);
		}
		if (best < kmax)
		{
			v[kmax][best] = pi(globalW[best], idx);
		}
		if (!star)
			v[kmax][kmax] = pi(0, -1);
	}
	static N merge(const N &a, const N &b)
	{
		N res(false);
		rep(i, kmax + 1) rep(j, kmax + 1) rep(k, kmax + 1)
			chmin(res.v[i][k], add(a.v[i][j], b.v[j][k]));
		return res;
	}
};

int fast(vi w, vi a, vi b)
{
	int n = si(a);
	assert(is_sorted(all(w)));
	rep(i, si(w)) globalW[i] = w[i];
	rng(i, si(w), kmax) globalW[i] = inf;

	int base = 0;
	rep(i, n) base += w[a[i]] * b[i];
	rep(i, n) b[i] = n - b[i];

	vi idx = vid(n);
	soin(idx, [&](int i, int j)
		 { return a[i] > a[j]; });
	a = a_idx(a, idx);
	b = a_idx(b, idx);

	seglazy<AddMin> margin(vid(n) + 1);
	segtree<MinNode> best(vi(n, kmax));
	vc<N> init(n);
	rep(i, n) init[i] = N(kmax, 0, i);
	segtree<N> seg(init);

	VVC(int, cnt, n, kmax);
	vi star(n);
	set<int> ss;

	auto upd_best = [&](int i)
	{
		int val = kmax;
		rep(k, kmax) if (cnt[i][k]) chmin(val, k);
		best.point_set(i, val);
		seg.point_set(i, N(val, star[i], i));
	};

	int ans = 0;
	rep(step, n)
	{
		while (1)
		{
			int y = margin.max_right(0, &AddMin::ok, 1).a;
			if (y == n)
				break;
			star[y] = 1;
			ss.insert(y);
			margin.ch(y, y + 1, &AddMin::add, inf);
			seg.point_set(y, N(best.point_get(y).v, star[y], y));
		}
		int x = b[step];
		{
			int y = margin.max_right(x, &AddMin::ok, inf / 2).a;
			ans += (y - x) * w[a[step]];
			x = y;
		}
		cnt[x][a[step]]++;
		margin.ch(x, n, &AddMin::add, -1);
		upd_best(x);

		int tail = n;
		while (x < tail)
		{
			auto z = seg.composite(x, tail).v[kmax][kmax];
			if (z.b == -1)
			{
				assert(z.a == 0);
				break;
			}
			else
			{
				auto itr = ss.lower_bound(tail);
				assert(itr != ss.bg);
				itr--;
				int l = z.b, r = *itr + 1;
				margin.ch(l, r, &AddMin::add, 1);
				int cost = 0;
				while (l < r)
				{
					int val = best.point_get(l).v;
					assert(val < kmax);
					int mid = min(best.max_right(l, &MinNode::ok, val).a, r);
					cnt[l][val]--;
					cnt[mid][val]++;
					cost += (mid - l) * w[val];
					upd_best(l);
					l = min(mid, r);
				}
				upd_best(r);
				ans += cost;
				tail = z.b;
			}
		}
	}

	return base - ans;
}

void slv()
{
	INT(n, K);
	assert(K == kmax);
	VI(w, kmax);
	vi a(n), b(n);
	rep(i, n)
	{
		input(a[i], b[i]);
		a[i]--;
	}

	int ans = fast(w, a, b);
	print(ans);
}

signed main(signed argc, char *argv[])
{
	if (argc > 1 && strcmp(argv[1], "D") == 0)
		dbg = true;

	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(20);

	if (dbg)
	{
		while (1)
		{
			if (current_run_id % run_batch_size == 0)
			{
				cerr << "Current Run " << current_run_id << endl;
			}
			slv();
			current_run_id++;
		}
	}
	else
	{
		// INT(t);rep(_,t)
		slv();
	}
}
