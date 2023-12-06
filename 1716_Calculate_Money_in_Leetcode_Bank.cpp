/* Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day. */

// Runtime: 0 ms, Beats 100.00%of users with C++
// Memory: 6.30 MB, Beats 70.53%of users with C++

class Solution {
public:
    int totalMoney(int n) {
        while (n >= 7) {
            total += current(n/7, n/7+6);
            n -= 7;
            count++;        
        }
        if (n != 0) {
            total += current(count+1, n+count);
        }
        return total;
    }
    int current(int start, int end) {
        return (start + end) * (end - start + 1) / 2;
    }
private:
    int total = 0;
    int count = 0;
};