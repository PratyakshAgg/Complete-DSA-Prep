/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getPeak(MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;

        while(l < r){
            int mid = l + (r-l)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1)) l = mid+1;
            else r = mid;
        }
        return r;
    }

    int bs1(MountainArray &mountainArr, int l, int r, int target){
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

    int bs2(MountainArray &mountainArr, int l, int r, int target){
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = getPeak(mountainArr);

        int ans = bs1(mountainArr, 0, idx, target);
        if(ans != -1) return ans;

        ans = bs2(mountainArr, idx+1, n-1, target);
        return ans;
    }
};