const int N = 1e6 + 5;
int B1, B2, MOD1, MOD2;
int pw1[N], pw2[N];

struct DoubleHash {
private:
  vector<pair<int, int>> prefix;
  int n;

  void hash_prefix(const string &str) {
    int h1 = 0, h2 = 0;
    prefix.clear();
    prefix.reserve(str.size());
    for (char i: str) {
      h1 = (1LL * h1 * B1) % MOD1;
      h1 = (h1 + i) % MOD1;
      h2 = (1LL * h2 * B2) % MOD2;
      h2 = (h2 + i) % MOD2;
      prefix.emplace_back(h1, h2);
    }
  }

public:
  DoubleHash() {}

  DoubleHash(const string &s) { build(s); }

  void build(const string &s) {
    assert(B1);
    n = static_cast<long long>(s.size());
    hash_prefix(s);
  }

  pair<int, int> getPrefix(int l, int r) {
    auto ret = prefix[r];
    int sz = r - l + 1;
    l--;
    if (l >= 0) {
      ret.first -= 1LL * prefix[l].first * pw1[sz] % MOD1;
      if (ret.first < 0)ret.first += MOD1;
      ret.second -= 1LL * prefix[l].second * pw2[sz] % MOD2;
      if (ret.second < 0)ret.second += MOD2;
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
  B2 = rnd(100, 500);
  MOD1 = rnd(2e8, 2e9);
  MOD2 = rnd(2e8, 2e9);
  while (!check(MOD1))MOD1--;
  while (MOD1 == MOD2 or !check(MOD2))MOD2--;
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
    pw2[i] = 1LL * pw2[i - 1] * B2 % MOD2;
  }
}
