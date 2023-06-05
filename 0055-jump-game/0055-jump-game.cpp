class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        //start at the beggining
        int pos = 0;

        //target is at the end of the array
        int target = nums.size() - 1;

        //let the current position go to the possible position
        for(int curr = 0; curr<=pos; curr++)
        {
            //if you can jump further from the current position set the possible position to that
            //nums[curr] == jump
            pos = max(pos, nums[curr] + curr);

            //look if the possible position is beyond the target
            if(pos >= target)
            {
                return true;
            }
        }
        return false;
    }
};