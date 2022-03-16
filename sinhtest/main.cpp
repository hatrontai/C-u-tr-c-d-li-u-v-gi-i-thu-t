#include  <bits/stdc++.h>

#define ll long long
#define rand rd

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const string NAME = "inp";
const int nTest = 8;

ll Rand(ll lo, ll hi) {
  assert(lo <= hi);
  return lo + 1LL * rd() * rd() % (hi - lo + 1);
}

void gen_increasing_array();
void gen_decreasing_array();
void gen_random_array();

int main() {
  srand(time(NULL));
  gen_increasing_array();
  gen_decreasing_array();
  gen_random_array();

  return 0;
}

void gen_increasing_array() {
  ofstream inp("inp1.txt");
    int n = Rand(5e5,1e6);
    inp << setprecision(13) <<n<< "\n";
    float divident = 17.0;
    int x = Rand(-1e5, 0);

    for (int i = 0; i < n; i++)
    {
      inp << x / divident << " ";
      x = Rand(x + 1, x + 1e1);
    }
  inp.close();
}

void gen_decreasing_array() {
    ofstream inp("inp2.txt");
    int n = Rand(5e5,1e6);
    inp << setprecision(13) <<n<< "\n";
    float divident = 17.0;
    int x = Rand(0, 1e6);

    for (int i = 0; i < n; i++)
    {
      inp << x / divident << " ";
      x = Rand(x -1e1, x -1);
    }
  inp.close();
}

void gen_random_array() {
    for (int iTest = 3; iTest < nTest + 3; iTest++)
  {
    ofstream inp(("inp" + to_string(iTest) + ".txt").c_str());
      int n = Rand(5e5, 1e6);
      inp << setprecision(13)<< n << "\n";
      float divident = 17.0;
      int x;

      for (int i = 0; i < n; i++)
      {
        x = Rand(-1e7, 1e7);
        inp << x / divident << " ";
      }
    inp.close();
  }
}

