//https://leetcode.com/problems/wiggle-sort-ii/



//1 1 2 2 2 5 6
//1 2 1 5 2 6 2

//1 1 2 2 5 6
//1 2 1 5 2 6


class Solution {
public:
		
	int kthNum(int k, vector<int> &a)
	{
		const int sz=a.size();
		if(sz==0)	return 1<<31;
		if(k<=1)	return a[0];
		if(k>=sz)	return a.back();
		for(int left=0, right=sz-1, mid; left<=right; )
		{
			mid=left+((right-left)>>1);
			int cnt=0, last=left;
			swap(a[left], a[mid]);
			for(int i=left+1; i<=right; ++i)
				if(a[i]<=a[left])
				{
					++cnt;
					swap(a[i], a[++last]);
				}
			if(cnt==k-1)
				return a[left];
			swap(a[left], a[last]);
			if(cnt>k-1)
				right=last-1;
			else
			{
				left=last+1;
				k-=cnt+1;
			}
		}
		return 1<<31;
	}


	void wiggleSort(vector<int> &a)
	{
		int sz=a.size(), k=(sz>>1)+(sz&1);
		int val=kthNum(k, a);
		cout<<val<<endl;
		int p1=(sz&1)?(sz-1):(sz-2), p2=1;
		for(int i=0; i<sz && (p1>=0 || p2<sz); ++i)			
			while(!(i<p2 && i%2==1) && !(i>p1 && i%2==0) && a[i]!=val)
			{			
				if(a[i]<val && p1>=0)
				{
					swap(a[i], a[p1]);
					p1-=2;
				}
				if(a[i]>val && p2<sz)
				{
					swap(a[i], a[p2]);
					p2+=2;
				}
			}	
	}
};









