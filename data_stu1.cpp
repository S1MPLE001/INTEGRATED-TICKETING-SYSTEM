//SEGMENT SIEVE
void seg_sieve(){
	for(int i=0;i<v.size();i++){
		ll j=n/v[i];
		// N IS MY STARTING VALUE AND M IS MY LAST VALUE--->>
		if(n%v[i])
		{
			j=j*v[i]+v[i];
		}
		else
			j=j*v[i];
			j=max(j,2*v[i]); // if prime less then num then it will be else j=0 and i choose 2*v[i];
			for(;j<=m;j+=v[i]){
				mp[j-n]=1;
			}
			// 1 K LIYE SPECIAL CASE BNA LENA
	}
	for(int i=n;i<=m;i++){
		 if(!mp[i-n])
			v1.push_back(i);
	}
}

// SHOERTEST PATH ALOGORITHIM ----- >>>
#include<bits/stdc++.h>
using namespace std;
priority_queue< pair < int ,int > > pq;
vector< pair <int ,int > > v[1000];
int main () {

   int n;
	cin >> n;
	int dis[100]={},pro[1000]={};
	for(int i =1 ;i < n ;i++) {
		dis[i]=1e8;
	}
	dis[1]=0;
	pq.push({0,1});
	while( n-- ) {
		int x, y,z;
		cin>>x>>y>>z;
		v[x].push_back({y,z});
	}
	while(!pq.empty()){
		int a= pq.top().second;
		pq.pop();
		if(pro[a])
			continue;
		pro[a]=1;
		for(auto i : v[a]) {
				int b=i.first,w=i.second;
			if(dis[a]+w<dis[b]){
				dis[b]=dis[a]+w;
				pq.push({-dis[b],b});
			}
		}
	}
	for(int i=1;i<=5;i++)
		cout<<dis[i]<<" ";
}

	if(dist[n]==1e15) // IT MEANS THERE IS NO CONNECTION B/W THE SOURCE NODE AND END POINT
	return cout<<"-1", 0;
	vector<int>v1;
	while(n!=1){
		v1.push_back(n);
		for(i=0;i<v[n].size();i++){
			if(dist[n]==dist[v[n][i].first]+v[n][i].second){
				n=v[n][i].first;
				break;
				}
			}
		}
// THIS IS USED TO PRINT THE SHOREST PATH FROM SOURCE NODE TO LAST NODE ;
		cout<<"1"<<" ";
		for(i=v1.size()-1;i>=0;i--)
		cout<<v1[i]<<" ";
	}

SPARESH TABLE ---- >>>
//int stmin[N][22], stgcd[N][22], n, a[N];
void sparse_min() {

	int i, j;
	for(i = 0;i < n;i++)
	stmin[i][0]=a[i];
	for(j = 1;(1<<j) <= n; j++){
			for(i = 0; i+(1<<j)-1<n; i++)
		stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<j)-(1<<(j-1))][j-1]);
	}
}
void sparse_gcd(){
	int i , j;
	for(i = 0; i < n; i++)
	stgcd[i][0]=a[i];
	for(j = 1; (1<<j) <= n;j++){
		for(i = 0; i+(1<<j)-1<n; i++)
		  stgcd[i][j]=__gcd(stgcd[i][j-1],stgcd[i+(1<<j)-(1<<(j-1))][j-1]);
	}
}
int spmin_query(int l,int r) {

	int length, k, x, y;
	length = r-l+1;
	k = log2(length);
	x = stmin[l][k];
	y = stmin[l+length-(1<<k)][k];
	return min(x,y);
}
int spgcd_query(int l, int r) {
	int length, k, x, y;
	length = r-l+1;
	k = log2(length);
	x = stgcd[l][k];
	y = stgcd[l+length-(1<<k)][k];
	return __gcd(x,y);
}

//SUBTREE QUERY
// subtree quries ---- >>>> :)  imp h bhai /// find number of zeros in subtree
#include<bits/stdc++.h>
using namespace std;
const int N =  1 << 20;
int in[N];
int out[N];
int visit[N];
int a[N];
int BIT[N];
int ct;
vector< int > v[N];
void insert_data(int pos,int val)
{
  // cout<<pos<<" "<<val<<" "<<n<<endl;
	while(pos<=N){
		BIT[pos]+=val;
		pos+=pos&(-pos);
	}
}
int query(int pos)
{
	int sum=0;
	while(pos>0){
		sum+=BIT[pos];
		pos-=pos&(-pos);
	}
	return sum;
}
void dfs(int n) {
	visit[n]=1;
	in[n]=++ct;
	for(auto i : v[n]) {
		if(visit[i]==0)
			dfs(i);
	}
	out[n]=ct;
}
int main () {
	int n ,  m;
	cin >> n >> m;
	for(int i =0 ;i < n-1 ; i++ ) {
		int x ,y;
		cin >> x >>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	/*
	for(int i =1; i <= n ;i++){
		cout<<out[i]<<' '<<in[i]<<endl;
	}
	*/
	// size of subtree is outdegree- in degree //
	int a[n];
	for(int i=1;i <= n;i++) {
		cin >> a[i];
		if(a[i]==0)
			insert_data(in[i],1);

	}
  ///cout<<query(out[x])-query(in[x]-1)<<endl,N TAK JANE DE KOI PRBLM NII H Bhai ;

// //STRONGLY CONNECTED COMPONENTS------------ >> >> > >> >>  >>  >> >> >  >> > >
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int cost[N],comp[N],com,Count[N],minval[N];
int visited[N];
vector<int> G[N],GT[N];
vector<int> order;

int dfs(int x)
{
	visited[x]=true;
	for(auto i:G[x])
		if(!visited[i])
			dfs(i);
	order.emplace_back(x);
}
void kosaraju(int x,int com)
{
	visited[x]=true;
	comp[x]=com;
	for(auto i:GT[x])
		if(!visited[i])
			kosaraju(i,com);
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	int edges;
	scanf("%d",&edges);
	for (int i = 0; i < edges; ++i)
	{
		scanf("d",&u,&v);
		G[u].emplace_back(v);
		GT[v].emplace_back(u);
	}
	for (int i = 1; i <=n; ++i)
	{
		if(!visited[i])
			dfs(i);
	}
	memset(visited,0,sizeof(visited));
	for(int i=(int)order.size()-1;i>=0;i--)
	{
		if(!visited[order[i]])
			kosaraju(order[i],++com);
	}

/// LAZY PROPAGATION
	void build(ll node,ll start ,ll end ,ll left ,ll right, ll val)  {
			if(lazy[node]!=0) {
				seg_tree[node] += (end - start + 1) * lazy[node] ;
				if(start!=end) {
					lazy[2 * node] += lazy[node] ;
					lazy[2*node+1] += lazy[node] ;
				}
				lazy[node] = 0 ;
			}
			if(start > end | start > right || end < left )
				return ;
			if(start >= left && end <= right) {
				seg_tree[node] += ( end - start + 1) * val ;
			if(start!=end) {
					lazy[2 * node] += val ;
					lazy[2*node+1] += val ;
				}
				return ;
			}
			ll mid = ( start + end ) / 2 ;
			build(2*node ,start,mid,left,right,val);
			build(2*node+1 ,mid+ 1,end,left,right,val);
			seg_tree[node] = seg_tree[2*node] + seg_tree[2* node +1];

	}
	ll query(ll node , ll start ,ll end , ll left ,ll right )  {
		if(lazy[node]) {
			seg_tree[node] += (end - start + 1) * lazy[node] ;
			if(start != end ){
				lazy[2* node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(start > end || start > right || end < left )
			return 0;
		if(start >= left && end <= right) {
			return seg_tree[node];
		}
		ll mid = ( start + end ) / 2;
		ll p = query(2*node ,start , mid , left ,right );
		ll q = query(2*node+1 ,mid+1 , end , left ,right );
		return p + q ;
	 }
// C++ program to implement bitwise Sieve
// of Eratosthenes.
#include <bits/stdc++.h>
using namespace std;
vector<int > v ;
bool ifnotPrime(int prime[], int x)
{
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}
bool makeComposite(int prime[], int x)
{
	prime[x/64] = (1 << ((x >> 1) & 31));
}


/// ALL PRIME NUMBER SMALLER THAN N
// Prints all prime numbers smaller than n.
void bitWiseSieve(int n)
{
	int prime[n/64];
	memset(prime, 0, sizeof(prime));
   for (int i = 3; i * i <= n; i += 2) {
		if (!ifnotPrime(prime, i))
			for (int j = i * i, k = i << 1; j < n; j += k)
				makeComposite(prime, j);
	}
	 v.push_back(2);
	for (int i = 3; i <= n; i += 2)
		if (!ifnotPrime(prime, i))
			v.push_back(i);
}
int main()
{
	int n = 3e7;
	bitWiseSieve(n);
	//cout <<(int) v.size() << endl;
	int t ;
	cin >> t;
	while(t-- ) {
		int k;
		cin >> k ;
		cout << v[k-1] <<endl;
	}
	return 0;
}

