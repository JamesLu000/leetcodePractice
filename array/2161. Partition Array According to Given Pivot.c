

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize){
    // int ans[numsSize];
    int* ans = malloc(sizeof(int)*numsSize);
    int ansIndex = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] < pivot){
            ans[ansIndex] = nums[i];
            ansIndex += 1;
        }
    }
        for (int i = 0; i < numsSize; i++){
        if (nums[i] == pivot){
            ans[ansIndex] = pivot;
            ansIndex += 1;

        }
    }
        for (int i = 0; i < numsSize; i++){
        if (nums[i] > pivot){
            ans[ansIndex] = nums[i];
            ansIndex += 1;

        }
    }
    *returnSize = numsSize;
    return ans;

    

}