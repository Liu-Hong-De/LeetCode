/* Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed. */

// Difficulty: Easy
// Runtime: 3 ms, faster than 79.33% of C++ online submissions for Maximum Number of Balloons.
// Memory Usage: 6.5 MB, less than 85.71% of C++ online submissions for Maximum Number of Balloons.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        for(int i = 0; i < text.length(); i++) {
            switch(text[i]) {
                case 'b':
                    count[0] += 1;
                    break;
                case 'a':
                    count[1] += 1;
                    break;
                case 'l':
                    count[2] += 1;
                    break;
                case 'o':
                    count[3] += 1;
                    break;
                case 'n':
                    count[4] += 1;
                    break;
                default:
                    break;
            }
        }
        
        ans = count[0];
        for(int i = 1; i < 5; i++) {
            if(i != 2 && i != 3) {
                ans = count[i] < ans ? count[i] : ans;
            }
            else {
                ans = count[i] / 2 < ans ? count[i] / 2 : ans;
            }
        }
        return ans;
    }
    
private:
    int count[5] = {0};
    int ans;
};
