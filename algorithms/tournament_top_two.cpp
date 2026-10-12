#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// Finds the largest and second-largest values without sorting the input.
// Requires at least two distinct-valued elements.
std::pair<int, int> findTopTwo(const std::vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    if (n < 2)
    {
        throw std::invalid_argument("At least two numbers are required");
    }

    // Each entry in alive is an index into nums.
    std::vector<int> alive;
    alive.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        alive.push_back(i);
    }

    // beaten[winner] stores the indices directly defeated by winner.
    std::vector<std::vector<int>> beaten(n);

    while (alive.size() > 1)
    {
        std::vector<int> next;
        next.reserve((alive.size() + 1) / 2);

        for (std::size_t i = 0; i < alive.size(); i += 2)
        {
            const int a = alive[i];

            // An unmatched contestant advances without a comparison.
            if (i + 1 == alive.size())
            {
                next.push_back(a);
                break;
            }

            const int b = alive[i + 1];
            if (nums[a] > nums[b])
            {
                next.push_back(a);
                beaten[a].push_back(b);
            }
            else
            {
                next.push_back(b);
                beaten[b].push_back(a);
            }
        }

        alive.swap(next);
    }

    const int champion = alive[0];
    int second = beaten[champion][0];
    for (std::size_t i = 1; i < beaten[champion].size(); ++i)
    {
        const int candidate = beaten[champion][i];
        if (nums[candidate] > nums[second])
        {
            second = candidate;
        }
    }

    return {nums[champion], nums[second]};
}

int main()
{
    const std::vector<int> nums = {5, 1, 9, 3, 12, 7, 4, 10};
    const auto result = findTopTwo(nums);
    std::cout << "Maximum: " << result.first << '\n';
    std::cout << "Second:  " << result.second << '\n';
}
