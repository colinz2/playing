//
// Created by colin on 2018/11/13.
//

//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。
// 但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
// 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//
//示例 1:
//
//输入: "III"
//输出: 3
//示例 2:
//
//输入: "IV"
//输出: 4
//示例 3:
//
//输入: "IX"
//输出: 9
//示例 4:
//
//输入: "LVIII"
//输出: 58
//解释: L = 50, V= 5, III = 3.
//示例 5:
//
//输入: "MCMXCIV"
//输出: 1994
//解释: M = 1000, CM = 900, XC = 90, IV = 4.罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
// 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
// 同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//
//示例 1:
//
//输入: "III"
//输出: 3
//示例 2:
//
//输入: "IV"
//输出: 4
//示例 3:
//
//输入: "IX"
//输出: 9
//示例 4:
//
//输入: "LVIII"
//输出: 58
//解释: L = 50, V= 5, III = 3.
//示例 5:
//
//输入: "MCMXCIV"
//输出: 1994
//解释: M = 1000, CM = 900, XC = 90, IV = 4.


//Rules:
//* If I comes before V or X, subtract 1 eg: IV = 4 and IX = 9
//* If X comes before L or C, subtract 10 eg: XL = 40 and XC = 90
//* If C comes before D or M, subtract 100 eg: CD = 400 and CM = 900

#include "../leetcode.h"

class Solution {

public:
    int ToNum(char c, char l) {
        if (c == 'I') return 1;
        else if (c == 'V' && l == 'I') return 3;
        else if (c == 'V') return 5;
        else if (c == 'X' && l == 'I') return 8;
        else if (c == 'X') return 10;
        else if (c == 'L' && l == 'X') return 30;
        else if (c == 'L') return 50;
        else if (c == 'C' && l == 'X') return 80;
        else if (c == 'C') return 100;
        else if (c == 'D' && l == 'C') return 300;
        else if (c == 'D') return 500;
        else if (c == 'M' && l == 'C') return 800;
        else if (c == 'M') return 1000;
        else return 0;
    }

    int romanToInt(string s) {
        int b = 0;
        int n = 0;
        char l = 0;
        for (auto c : s) {
            b = ToNum(c, l);
            n = n + b;
            l = c;
        }
        return n;
    }

    //有顺序性
    int romanToInt2(string s) {

        unordered_map<char, int> map = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            if(i + 1 < s.size() && map[s[i]] < map[s[i + 1]]){
                res += map[s[i + 1]] - map[s[i]];
                i ++;
            }
            else
                res += map[s[i]];

        return res;
    }
};

int main()
{
    cout << Solution().romanToInt("LVIII") << endl;
    cout << Solution().romanToInt("III") << endl;
    cout << Solution().romanToInt("MCMXCIV") << endl;

    cout << Solution().romanToInt2("LVIII") << endl;
    cout << Solution().romanToInt2("III") << endl;
    cout << Solution().romanToInt2("MCMXCIV") << endl;
}






