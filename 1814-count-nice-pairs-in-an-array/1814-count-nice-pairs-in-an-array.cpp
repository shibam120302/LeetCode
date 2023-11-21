class Solution {
public:
    int countNicePairs(std::vector<int>& nums) {
        std::unordered_map<int, int> numbers;

        for (int num : nums) {
            int temporaryNumber = num - reverse(num);

            if (numbers.find(temporaryNumber) != numbers.end()) {
                numbers[temporaryNumber]++;
            } else {
                numbers[temporaryNumber] = 1;
            }
        }

        long result = 0;
        int mod = 1000000007;
        for (const auto& entry : numbers) {
            result = (result % mod + ((long)entry.second * ((long)entry.second - 1) / 2)) % mod;
        }

        return static_cast<int>(result);
    }

private:
    int reverse(int number) {
        int reversedNumber = 0;
        while (number > 0) {
            reversedNumber = reversedNumber * 10 + number % 10;
            number /= 10;
        }
        return reversedNumber;
    }
};