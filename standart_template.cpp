#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#pragma optimize("O3")
#pragma comment(linker, "/stack:200000000")

//vector
#define ALL(v) (v).begin(), (v).end()
#define RZ resize
#define UNIQUE(v) (v).RZ(unique(ALL(v)) - (v).begin())
#define PB push_back
#define EB emplace_back
#define EMP emplace
#define _PB pop_back
#define SZ(v) ((int)(v).size())
#define MP make_pair
#define SND second
#define fst first
#define E empty
#define MT make_tuple //use with tie, ignore and emplace
//use move to asignar container

//for
#define REP(i,n) for (int i = 0; i < n; ++i) 
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REV(i,n) for (int i = n-1; i >= 0; --i)

//bit
#define ONES __builtin_popcount
#define CL __builtin_clz
#define LSO(x) ((x)&-(x))

//debug
#define DEBUG(x) cerr << #x << "is " << (x) << endl;

//limits
#define oo 1e9
#define oo2 2e9
#define OO 1e18

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

template<typename T>
T MAX() {return 0;}
template<typename T, typename... Args>
T MAX(T x, Args... args) {return max(x, MAX(args...));}

using namespace std;
