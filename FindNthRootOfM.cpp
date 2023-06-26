bool power(long long a, long long b, int num)
{
  long long res = 1;
  while(b)
  {
    if(a > num)
      return false;
    if(b & 1)
      res *= a;
    if(res > num)
      return false;
    a *= a;
    b >>= 1;
  }
  return true;
}

int powerr(int a, int b)
{
  int res = 1;
  while(b)
  {
    if(b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int l = 1, r = m + 1;
  while(r - l > 1)
  {
    int mid = l + (r - l) / 2;
    // cout << mid << ' ' << power(mid, n, m) << endl;
    if(power(mid, n, m))
      l = mid;
    else
      r = mid;
  }
  // cout << "L -> " << l << endl;
  if(power(l, n, m) && powerr(l, n) == m)
    return l;
  return -1;
}
