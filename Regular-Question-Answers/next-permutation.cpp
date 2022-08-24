//Author: Toygun Görmüş
//Problem Link : https://leetcode.com/problems/next-permutation/
/*Using two pointers will be efficient in this problem. The two pointers will point to the first not sorted element and the first greater element after it. Thus, by swapping these numbers and sorting the rest of the array from the first not sorted element should yield the next permutation.  */
class Solution {
public:
    //Declaring a function to check if the given array is in descending order.
    bool descending(vector<int>& nums)
{
        //If every number is smaller than the previous number in every iteration, the array is descendant. 
    for(int i =nums.size()-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
             return 0;
        }
    }
    return 1;
}
void nextPermutation(vector<int>& nums) {
    //Checking if the array is descending. If so, the reverse of the array is the next permutation(i.e. Input: nums = [3,2,1] Output: [1,2,3]).
    if(descending(nums))
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    // We use l pointer to detect first not sorted element
    //We use r pointer to detect the first greater element than left
    int l = nums.size()-2;
    int r = nums.size()-1;
    
    while(nums[l]>=nums[l+1]) l--;
    while(nums[l]>=nums[r])r--;
    //Swapping the numbers at indexes l and r to find the next permutation in lexicographical order
    swap(nums[l],nums[r]);
    //Sorting the rest of the array yields the answer
    sort(nums.begin()+l+1,nums.end());
    }
};