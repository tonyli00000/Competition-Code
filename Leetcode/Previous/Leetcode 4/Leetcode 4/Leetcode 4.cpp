class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		int stot = nums1.size() + nums2.size();

		ret.resize(stot);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ret.begin());
		if (stot % 2) return ret[stot / 2];
		else return ((ret[stot / 2 - 1] + ret[stot / 2]) / 2.0);
	}
};