struct node{
      int value;
      int index;
};
node a[1000000];
bool cmp(node a,node b){
    return a.value<b.value;
}
    
class Solution {
private:
   
    node bs(int re,int l,int r){
        node t;
        t.index=-1;
        r--;
        while(l<=r){
            int mid=(r-l)/2+l;
           if(a[mid].value==re){
                t=a[mid];
                break;
           }
        else if (a[mid].value>re)
            high = mid - 1;
        else
            low = mid + 1;
        }
        return t;
        
    }
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            a[i].value=nums[i];
            a[i].index=i;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            int re=target-a[i].value;
            node t=bs(re,0,n);
            if(t.index!=-1&&t.index!=i){
                ans.push_back(a[i].index);
                ans.push_back(t.index);
                break;
            }
        }
        return ans;
    }
    
};