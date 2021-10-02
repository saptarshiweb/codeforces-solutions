/*
*   Author: Saptarshi Mandal
*   Platform: Codeforces
*   Problem_ID: 1574C
*   Language: C++
*   Problem url: https://codeforces.com/problemset/problem/1574/C
*/

// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pob pop_back
#define mk make_pair
#define deb(x) cout<< #x <<" = "<<x<<"\n"
#define deb2(x,y) cout<< #x <<" = "<<x<<","<< #y <<" = "<<y<<"\n"
#define red(x) int x;cin>>x;
#define read(x) long long int x; cin>>x
#define reads(x) string x; cin>>x
#define strto to_string
#define fo(i, n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define repr(i,a,b) for(ll i=a; i>=b; i--)
#define repj(i,a,b,c) for(ll i=a; i<b; i+=c)
#define tr(it,a) for(auto it = a.begin(); it != a.end(); it++)
#define input(v,n) vector <ll> v(n); rep(i,0,n) cin>>v[i];
#define output(v) rep(i,0,n) cout<<v[i]<<" "; cout<<"\n"
#define all(v) v.begin(),v.end()
#define allr(v) v.begin(),v.end(),greater<ll>()

#define clr(x) memset(x, 0, sizeof(x))
#define sortall(v) sort(all(v))
#define PI 3.1415926535897932384626
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)

#define arrin(ar,n) ll ar[n];for(ll i=0;i<n;i++) cin>>ar[i]
#define vecin(v,n) vector<ll> v;for(ll i=0;i<n;i++){ll temp;cin>>temp;v.pb(temp);} 


const int N = 1e9 +7;
using namespace std;

ll power(ll base,ll ex);
ll extended_gcd(ll a,ll b,ll &x,ll &y); 

void solve()
{
	read(n);vecin(a,n);read(m);
	vector<ll> x;vector<ll> y;
	
	fo(i,m)
	{
		ll temp;cin>>temp;
		x.pb(temp);
		cin>>temp;
		y.pb(temp);
	}
	
	
	vector<ll> a2(a);
	sortall(a2);
	
	
	ll sum=0;
	
	fo(i,n)
	{
		sum+=a[i];
	}
	
	ll big=a2[0];ll sm=a2[n-1];
	
	fo(i,m)
	{
		ll atk=x[i];ll def=y[i];
		
		
		
		// if(atk>big)
		// ans+=(atk-big);
// 		
		// if(def>(sum-big))
		// ans+=(def-(sum-big));
// 		
		// fo(j,n)
		// {
			// ll val=0;
// 			
			// if(atk>a2[j])
			// val+=(atk-a2[j]);
// 			
			// if(def>(sum-a2[j]))
			// val+=(def-(sum-a2[j]));
// 			
			// ans=min(ans,val);
// 			
			// if(ans==0)
			// {
				// break;
			// }
		// }
		
		
			auto it=lower_bound(a2.begin(),a2.end(),atk);
			
			if(it==a2.end())
			{
				ll val=(atk-a2[n-1]);
				
				if((def-(sum-a2[n-1]))>0)
				val+=(def-(sum-a2[n-1]));
				
				cout<<val<<"\n";
			}
			else
			{
			ll j=it-a2.begin();
			
			if(j==0)
			{
				ll ans=0;
				
				if(def-(sum-a2[0])>0)
				ans+=def-(sum-a2[0]);
				cout<<ans<<endl;
				
			}
			else
			{
			ll val1=0;ll val2=0;
			if((def-(sum-a2[j]))>0)
			val1=(def-(sum-a2[j]));
			
			val2=(atk-a2[j-1]);
			
			if((def-(sum-a2[j-1]))>0)
			val2+=(def-(sum-a2[j-1]));
			
			if((val1<0)||(val2<0))
			cout<<max(val1,val2)<<"\n";
			else
			cout<<min(val1,val2)<<"\n";
			}
			
			}
			
		
		
		
		
	}
	
	return;
	


}
	
int main()
{
    fastIO;
	solve();
	
	return 0;
}




ll extended_gcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll x1,y1;
	ll d = extended_gcd(b,a % b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
	return d;
}

ll power(ll base,ll ex){
	if(base == 0)
		return 0;
	if(ex == 0)
		return 1;
	ll y;
	if((ex & 1) == 0){
		y = power(base,ex/2);
		y = (y * y) % N;
	}
	else{
		y = base % N;
		y = (y * power(base,ex-1) % N) % N;
	}
	return (y+N)%N;
}
 