int missingNumber(int* nums, int numsSize) {
    int i;
    int *tmp = (int*)calloc(numsSize + 1, sizeof(int));
    for (i = 0; i < numsSize; i++){
        tmp[nums[i]] = -1;
    }

    for (i = 0; i <= numsSize; i++){
        if (tmp[i] != -1){
            return i;
        }
    }
    return -1;
}