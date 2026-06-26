1#include <ext/pb_ds/assoc_container.hpp>
2#include <ext/pb_ds/tree_policy.hpp>
3
4using namespace __gnu_pbds;
5
6template<class T>
7using ordered_set = tree<
8    T,
9    null_type,
10    less<T>,
11    rb_tree_tag,
12    tree_order_statistics_node_update
13>;
14class Solution {
15public:
16    long long countMajoritySubarrays(vector<int>& nums, int target) {
17        int n=nums.size();
18        vector<int> pref(n,0);
19        for(int i=0;i<n;i++){
20            if(nums[i]==target){
21                  pref[i]=1;
22            }else{
23                pref[i]=-1;
24
25            }
26            if(i){
27                pref[i]+=pref[i-1];
28            }
29        }
30        long long ans=0;
31        ordered_set<pair<int,int>> st;
32        st.insert({0,0});
33        for(int i=0;i<n;i++){
34            ans+=st.order_of_key({pref[i],-1});
35            st.insert({pref[i],i});
36        }
37      return ans;
38    }
39};