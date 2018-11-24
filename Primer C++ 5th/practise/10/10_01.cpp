#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr == 1) ? word : word + ending;
}

void elimDups(vector<string> &words)
{
    // 按字典排序words，以便查找重复单词
    sort(words.begin(), words.end());
    // unique重排输入范围，使得每个单词值出现一次
    // 排列在范围的前部，返回指向不重复区域之后的一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    // 使用向量操作erase删除重复的单词
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words,
             vector<string>::size_type sz)
{
    elimDups(words);    // 将words按字典序排序，删除重复单词
    // 按长度排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                    { return a.size() < b.size(); });
    // 获取一个迭代器，指向第一个满足size()>= sz 的元素
    auto wc = find_if(words.begin(), words.end(),
                    [sz](const string &a)
                        { return a.size() >= sz; });
    // 计算满足size >= sz 的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<string> strVec = 
        {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
        
    biggies(strVec, 4);

    return 0;
}
