const int N = 1e6 + 5;
int B1, MOD1;
int pw1[N];

struct SingleHash {
private:
  vector<int> prefix;
  int n;

  void hash_prefix(const string &str) {
    int h1 = 0;
    prefix.clear();
    prefix.reserve(str.size());
    for (char i: str) {
      h1 = (1LL * h1 * B1) % MOD1;
      h1 = (h1 + i) % MOD1;
      prefix.emplace_back(h1);
    }
  }

public:
  SingleHash() {}

  SingleHash(const string &s) { build(s); }

  void build(const string &s) {
    assert(B1);
    n = static_cast<long long>(s.size());
    hash_prefix(s);
  }

  int getPrefix(int l, int r) {
    auto ret = prefix[r];
    int sz = r - l + 1;
    l--;
    if (l >= 0) {
      ret -= 1LL * prefix[l] * pw1[sz] % MOD1;
      if (ret < 0)ret += MOD1;
    }
    return ret;
  }
};

void build() {
  if (B1)return;
  random_device rd;
  mt19937 mt(rd());
  auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l, r)(mt); };
  auto check = [](int x) {
    for (int i = 2; i <= x / i; ++i) if (!(x % i)) return false;
    return true;
  };
  B1 = rnd(100, 500);
  MOD1 = rnd(2e8, 2e9);
  while (!check(MOD1))MOD1--;
  pw1[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
  }
}
