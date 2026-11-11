#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::vector<int> pCount(26, 0);  // 统计目标字符串 p
        std::vector<int> window(26, 0);  // 统计当前窗口
        std::vector<int> result;
        int left = 0;

        if (p.size() > s.size())
        {
            return {};
        }

        // 统计目标字符串 p
        for (int i = 0; i < static_cast<int>(p.size()); i++)
        {
            pCount[p[i] - 'a']++;
        }

        // 统计第一个窗口
        for (int i = 0; i < static_cast<int>(p.size()); i++)
        {
            window[s[i] - 'a']++;
        }

        if (window == pCount)
        {
            result.push_back(0);
        }

        for (int right = static_cast<int>(p.size()); right < static_cast<int>(s.size()); right++)
        {
            window[s[left] - 'a']--;    // 旧字符离开
            window[s[right] - 'a']++;   // 新字符进入
            left++;

            if (window == pCount)
            {
                result.push_back(left);
            }
        }

        return result;
    }
};
