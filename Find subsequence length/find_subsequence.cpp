#include <iostream>
#include <unordered_map>
using namespace std;
int find(string mainStr, string subStr)
{
    int l1 = subStr.length();
    int l2 = mainStr.length();
    if (l2 < l1)
    {
        return -1;
    }
    unordered_map<char, int> sub_count, main_count, flag_map;
    for (int i = 0; i < l2; i++)
    {
        if (i < l1)
        {
            sub_count[subStr[i]]++;
        }
        main_count[mainStr[i]]++;
    }
    int start = -1, end = -1, count = 0;
    for (int i = 0; i < l2; i++)
    {
        if (sub_count[mainStr[i]] && main_count[mainStr[i]] >= sub_count[mainStr[i]])
        {
            if (start == -1)
            {
                start = end = i;
            }
            else
            {
                end = i;
            }
            if (!flag_map[mainStr[i]])
            {
                count += sub_count[mainStr[i]];
                flag_map[mainStr[i]] = 1;
            }
        }
    }
    if (count == l1)
    {
        return end - start + 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string mainStr, subStr;
        cin >> mainStr >> subStr;
        cout << find(mainStr, subStr) << endl;
    }
}
