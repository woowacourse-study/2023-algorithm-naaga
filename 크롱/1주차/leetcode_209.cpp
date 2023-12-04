class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();

        // for(int windowSize = 1; windowSize <= size; windowSize++) {
        //     int sum = 0;
            
        //     for(int i = 0; i < windowSize; i++) {
        //         sum += nums[i];
        //     }

        //     for(int i = windowSize; i < size; i++) {
        //         if(sum >= target) {
        //             return windowSize;
        //         }

        //         sum -= nums[i - windowSize];
        //         sum += nums[i];
        //     }

        //     if(sum >= target) {
        //         return windowSize;
        //     }
        // }

        // vector<int> prefixSum;
        // int sum = 0;
        // for(int i = 0; i < size; i++) {
        //     sum += nums[i];
        //     prefixSum.push_back(sum);
        // }

        // 2 3 1 2 4 3
        // l
        //       r

        int left = 0;
        int right = 0;

        int sum = 0;
        int answer = 1000000002;
        while(left < size && right < size) {
            if(sum >= target) {
                answer = min(answer, right - left);

                sum -= nums[left];
                left++;
            }
            else {
                sum += nums[right];
                right++;
            }
        }

        while(left < size) {
            if(sum >= target) {
                answer = min(answer, right - left);
            }
            sum -= nums[left];
            left++;
        }

        if(answer == 1000000002) {
            return 0;
        }

        return answer;
    }
};