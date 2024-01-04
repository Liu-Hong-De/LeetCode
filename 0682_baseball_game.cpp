/* You are keeping score for a baseball game with strange rules. 
The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. 
You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record. */

// Difficulty: Easy
// Runtime: 4 ms, faster than 71.34% of C++ online submissions for Baseball Game.
// Memory Usage: 8.3 MB, less than 69.92% of C++ online submissions for Baseball Game.

class Solution {
public:
    void remove(vector<int>& score) {
        score.pop_back();
    }
    
    void double_score(vector<int>& score) {
        score.push_back(score.back()*2);
    }
    
    void add_score(vector<int>& score) {
        score.push_back(score.back()+score[score.size()-2]);
    }
    
    int calPoints(vector<string>& ops) {
        vector<int> score;
        int sum = 0;
        
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "C")
                remove(score);
            else if(ops[i] == "D")
                double_score(score);
            else if(ops[i] == "+")
                add_score(score);
            else
                score.push_back(stoi(ops[i]));
        }
        
        for(auto i : score)
            sum += i;
        
        return sum;
    }
};
