#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
std::ifstream fin("poetry.in");
std::ofstream fout("poetry.out");
const int P=1000000007;
#define modp(x) do {if (x>1000007) {x= x%P;}} while(0)

int N, M, K;
int s[5001], c[5001], e[26];
long long dp[5001];
vector<int> b;
map<int, long long> ppp;
//int ppp[1000][5001];
long long ans;

void print()
{
    cout << "base: \n";
    for (int i =0; i< b.size(); ++i) {
        cout << b[i] << ' ';
    } cout << endl;

    cout << "rhymes: \n";
    int sss=0;
    for (int i =0; i< M; ++i) {
        cout << e[i] << ' ';
        sss += e[i];
    } cout << endl;
    cout << "total m: " << sss << endl;
}

void printc()
{
    for (int k=0; k<=K; ++k) {
        cout << dp[k] << ' ';
    } cout << endl;
}


long long power(int base, int exp)
{
    if (exp ==0) return 1;
    if(exp==1) return b[base];

    int state = (exp<<16)|base;
    if(ppp[state]>0) {
        return ppp[state];
    }

    long long tmp = power(base, exp/2);
    long long t=tmp*tmp;
    modp(t);
    if(exp&1) {
        t*=b[base];
        modp(t);
    }

    ppp[state] = int(t);
    return ppp[state];
}

int getsum()
{
    long long sum = 0;
    long long p= 1;
    //cout << "b size is "<< b.size() << endl;
    for (int i =0; i<M; ++i) {
        sum =0;
        for (int j =0; j<b.size()-2; ++j) {
            sum += power(j, e[i]);
            //cout << "sum is " << sum << endl;
            modp(sum);
        }
        p*=sum;
        modp(p);
    }
    //cout << "P is "<<p << endl;
    return p;
}

void coins()
{
    dp[0] = 1;
    //printc();
    for (int j = 1; j<=K; ++j) {
        for (int i = 0; i<N; ++i) {
            int w = s[i];
            if(j>=w) {
                dp[j] += dp[j-w];
                modp(dp[j]);
            }
        }
        modp(dp[j]);
        //printc();
    }
#if 0
    for (int j = 1; j<=K; ++j) {
        modp(dp[j]);
    }
#endif

    map<int, int> m;
    for(int i=0; i<N; ++i) {
        m[c[i]] += dp[K-s[i]];
        modp(m[c[i]]);
    }

    for (auto &i:m) {
        //cout << i.first << ' ' << i.second << endl;
        if(i.second>0) b.push_back(i.second);
    }
    N = b.size();
    b.push_back(dp[K]);
    b.push_back(N);

    int cnt=0;
    for (int i=0; i<26; ++i) {
        if (e[i] == 1) cnt++;
    }

#if 0
    for (int i=0; i<=N; ++i) {
        ppp[i] = 1;
        ppp[(1<<16)|i] = b[i];
    }
#endif


    M = 0;
    for (int i=0; i<26; ++i) {
        if (e[i] > 1) e[M++] = e[i];
    }

    //print();
    //cout << "cnt " << cnt << endl;
    //cout << "M " << M << endl;
    ans = power(b.size()-2, cnt);
//    ans *= power(b.size()-1,M-1);

    //cout << "ans " << ans << endl;
    modp(ans);

    ans *= getsum();
    modp(ans);
}

int main()
{
    fin >> N >> M >> K;
    //cout << "N=" << N << ' ' << M << ' '<< K << endl;
    for(int i = 0; i < N; i++){
        fin >> s[i] >> c[i];
        //cout << s[i] << ' ' << c[i] << endl;
    }
    for(int i = 0; i < M; i++){
        char ch;
        fin >> ch;
        e[ch-'A']++;
        //cout << ch << endl;
    }

    coins();
    //cout << "N=" << N << ' ' << M << ' '<< K << endl;
    fout << ans << endl;
    //cout << ans << endl;
    return 0;
}
