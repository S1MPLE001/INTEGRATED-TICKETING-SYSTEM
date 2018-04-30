//BFS
void bfs(int j){
	queue<int>q;
	q.push(j);
	visit[j]=1;
	while(!q.empty()){
	int a;
	a=q.front();
	q.pop();
	for(auto i : v[a]){
		if(!visit[i]){
		q.push(i);
		visit[i]=1;
			}
		}
	}
}
//DFS
void dfs(int n){
	vis[n]=1;
	for(int i=0;i<v[n].size();i++){
		 if(!vis[v[n][i]])
		dfs(v[n][i]);
	 }
}

// DSU
int root(int x){
 while(x!=go[x]){
	go[x]=go[go[x]];
	x=go[x];
 }
 return x;
}
void join(int x,int y){
	go[root(x)]=go[root(y)];
}

//BIT
void insert_data(int pos,int val)
{
  // cout<<pos<<" "<<val<<" "<<n<<endl;
	while(pos<=n){
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


// Floyd warshell algorithm --- ----------- >>> >> >> >>>
#include<bits/stdc++.h>
using namespace std;
int main () {
   int  n ;
   cin >> n;
   int a[n][n]={};
   for(int i = 1; i  <=  7; ++i){
	  int x, y, z;
	  cin >> x >> y >>z;
	  a[x][y]=z;
   }
   int dis[n][n]={};
   for(int i=1 ;i <= n;i++) {
	for(int j = 1; j<= n;j++){
		if(i== j )
			dis[i][j]=0;
		else if(a[i][j])
			dis[i][j] = a[i][j];
		else
			dis[i][j]=1e6;
	}
}
	for(int k=1;k<=n ;k++){
		for(int i =1 ;i <= n ;++i) {
			for(int j= 1 ;j <= n; ++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	int q;
	cin >> q;
	while(q--){
		int x ,y ;
		cin >> x >> y;
		cout << dis[x][y] << endl;
	}
}
//GCD
int gcd(int a,int b)
	{
			if(a==0)
			return b;
			else
			gcd(b%a,a);
		}

// THIS IS A GOOD METHOD TO FIND A LCA OF A TREE ......... BY EULER PATH
#include<bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int visit[N];
vector< int > v[N];
int euler[4*N];
int first[N];
int index;
int stmin[N][22];
void sparse_min() {
	int i, j;
	for(i = 0;i < index;i++)
	stmin[i][0]=euler[i];
	for(j = 1;(1<<j) <= index; j++){
			for(i = 0; i+(1<<j)-1<index; i++)
		stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<j)-(1<<(j-1))][j-1]);
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
void dfs(int node) {
	visit[node]=1;
	first[node]=index;
	euler[index++]=node;
	for(auto i : v[node]) {
		if(!visit[i])
			{dfs(i);
			euler[index++]=node;// for euler path --- :)
			}
	}
}
int lca(int a ,int b) {
	a=first[a];
	b=first[b];
	if(a>b)
		swap(a,b);
	return spmin_query(a,b);
	}
int main () {
   int  n;
   cin >> n;
   for(int i = 0 ; i < n-1 ; ++i) {
	int x , y ;
	cin >> x >> y;
	v[x].push_back(y);
	v[y].push_back(x);
   }
   dfs(1);

   for(int i = 0 ;i < index ;i++) {
	cout<<euler[i]<<' ';
   }
	sparse_min();
   cout<<endl;
   cout<<lca(4,7);
 }

 //MO

 struct query{
 	int l;
 	int r;
 	int idx;
 	bool operator < (const query &b)const {
 	if((l/SQN)==(b.l/SQN))
 	return r<b.r;
 	else
 		return l<b.l;
 	}

  };
  ll cnt[N];
  ll a[N];
  query q[N];
  ll ans[N];
  int temp=0;
  int n,m;
  /* ADD KRTE TIME CURR KO 0 AUR CURL KO 1 AUR 1 BASED INDEX;
   JB ADD KR RA HO TOH FIRSTLY INCREMENT INDEX OR DEC NII TOH MINUS KRNA;
   */
  void add(int num){
  	if(num<=n){
  	cnt[num]++;
  	if(cnt[num]==num)
 		temp++;
 	if(cnt[num]==num+1)
 		temp--;
  	}
   }
   void removo(int num){
   	if(num<=n){
   cnt[num]--;
   if(cnt[num]==num){
 	temp++;
   }
   if(cnt[num]==num-1)
 	temp--;
   	}
 	}


 while(curr<r)
 	{
 		curr++;
 		add(a[curr]);
 	}
 	while(curl>l)
 	{
 		curl--;
 		add(a[curl]);
 	}
 	while(curl<l)
 	{
 		removo(a[curl]);
 		curl++;
 	}
 	while(r<curr){
 	removo(a[curr]);
 		curr--;

    }

//NCR
ll power(ll base,ll exp,ll mod=MOD) {ll ans=1;base %= MOD;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
    ll modInverse(ll n)
    {
    	return power(n, MOD-2);
    }
  //SEGMENT TREE
  void bn_ja_bsdk(ll first,ll last,ll node){
  	if(first==last){
  		seg_tree[node]=a[first];
  		return ;
  	}
  	ll mid=(first+last)/2;
  	bn_ja_bsdk(first,mid,2*node);
  	bn_ja_bsdk(mid+1,last,2*node+1);
  	seg_tree[node]=__gcd(seg_tree[2*node],seg_tree[2*node+1]);
  }
  void update_query(ll pos,ll val,ll first,ll last,ll node){
  	if(first==last&&pos==last){
  		seg_tree[node]=val;
  		return ;
  	}
  	if(first > pos or last < pos)
  		return ;
  		ll mid= (first+last)/2;
  	update_query(pos,val,first,mid,2*node);
  	update_query(pos,val,mid+1,last,2*node+1);
  	seg_tree[node]=__gcd(seg_tree[2*node],seg_tree[2*node+1]);
  }
  int query(ll left,ll right,ll first,ll last,ll node,ll x) {

  	if(right<first or last < left)
  		return 0;
  	if(first==last){
  		if(seg_tree[node]%x==0)
  			return 0;
  		else
  			return 1;
  	}
  	if(left <= first && last <= right){
  		if(seg_tree[node]%x==0)
  			return 0;
  	}
  	ll mid = ( first + last ) / 2;
  	ll p1 = query(left,right,first,mid,2*node,x);
  	 ll p2 = query(left,right,mid+1,last,2*node+1,x);
  	 return p1+p2;
  }
