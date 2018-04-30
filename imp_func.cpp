// TO FIND PRIME NUMBER
int isprime(int n){
		int i;
		for(i=2;i*i<=n;i++){
			if(!(n%i))
			return 0;
			}
			return 1;
		}

// POWER FXN
ll power(ll base,ll exp,ll mod=MOD)
{ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}

// TO FIND ALL SUBSET
for(int i=0 ;i < (1<<n ); i++ ) {
	 for( int j=0 ; j < n; j++) {
		 if(i & (1 << j))
			cout<<a[j]<<' ';
	 }
	 cout<<"\n";
   }
}
 // CONVERT TO BINARY FORM - >>
 string binary(int n){
   	int x;
   	string s;
   	while(n!=0){
		x=n%2;
		s+=x+'0';
		n=n/2;
	}
	return s;
}
 //CONVERT TO DECIMAL FORM -- >>
 int decimal(string s){
	int i,sum=0;
   	for(i=0;i<s.length();i++)
		sum+=(pow(2,i)*(s[s.length()-1-i]-'0'));
   	return sum;
}
