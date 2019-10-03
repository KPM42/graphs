#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>
#include<set>
#include<map>
#include<cmath>
#include<iomanip>
#include<iterator>
#include<queue>
#include<stack>
#include<cctype>
#include<deque>
#include<time.h>
#include<bitset>

//by Skeef79

//НЕ ИСПОЛЬЗУЙ endl, есть свой en!!
//Иногда нужно не просто придумывать решение, а метматически расписать систему уравнений
//для задач с cin/cout в большом кол-ве - gnu , иначе вижуалки. А ваще пробуй два если TL

//для интерактивок - cout<<flush
// cin.tie и sync_with_stdio убирать для интерактивок

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define en '\n'
#define for0(i,n) for(int i = 0;i<n;i++)
#define for1(i,n) for(int i = 1;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vec vector
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

const int INF = 2000000000;
const ll LINF = 2000000000000000000;

template<typename T> void print(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
}

template<typename T> void print(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
}

template<typename T> void print(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}

template <typename T> void input(vector<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}

template<typename T> void input(deque<T>& a)
{
	for (int i = 0; i < a.size(); i++)
		cin >> a[i];
}

template<typename T> void input(vector<vector<T>>& a)
{
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			cin >> a[i][j];
}

vector<vector<int>> e;
int start = 1;

bool CheckEuler()
{
	int cnt = 0;
	for (int i = 1; i < e.size(); i++)
		if (e[i].size() % 2 != 0)
		{
			cnt++;
			start = i;
		}

	if (cnt == 0 || cnt == 2)
		return true;
	else
		return false;
}

vector<int> EulerPath()
{
	stack<int> st;
	vector<int> ans;

	st.push(start);
	set<pair<int, int>> used;

	while (!st.empty())
	{
		int v = st.top();
		
		for (auto to:e[v])
		{
			if (!used.count({ min(to,v),max(to,v) }))
			{
				st.push(to);
				used.insert({ min(to,v),max(to,v) });
				break;
			}
		}

		if (v == st.top())
		{
			st.pop();
			ans.pb(v);
		}
	}
	reverse(all(ans));

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	//freopen("tree.in", "r", stdin);
	//freopen("tree.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	e = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}

	if (!CheckEuler())
		cout << -1;
	else
	{
		vector<int> ans = EulerPath();
		for (auto to : ans)
			cout << to << ' ';
	}


}