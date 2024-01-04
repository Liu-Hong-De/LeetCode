/* You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, 
all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API. */

// Difficulty: Easy
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 5.8 MB, less than 89.70% of C++ online submissions for First Bad Version.

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binary_search(1, n);
    }
    
    int binary_search(int low, int high) {
        if(low+1 >= high) {
            return isBadVersion(low) ? low : high;
        }
        int mid = low / 2 + high / 2;	// in order to avoid overflow, do not use (low+high)/2
        if(!isBadVersion(mid)) {
            if(isBadVersion(mid+1)) {
                return mid+1;
            }
            return binary_search(mid+1, high);
        }
        else {
            if(!isBadVersion(mid-1)) {
                return mid;
            }
            return binary_search(low, mid-1);
        }
    }
};
