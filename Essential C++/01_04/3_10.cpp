#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string word;
    vector<string> text;

    while (cin >> word)
        text.push_back(word);

    sort(text.begin(), text.end());

    for (int ix = 0; ix < text.size(); ++ix)
        cout << text[ix] << ' ';

    // 新方法
    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> svec;
    copy(is, eof, back_inserter(svec));

    sort(svec.begin(), svec.end());

    ostream_iterator<string> os(cout, " ");
    copy(svec.begin(), svec.end(), os);

    //从文件读取
    ifstream in_file("input_file.txt");
    ofstream out_file("output_file.txt");

    if (!in_file || !out_file)
    {
        cerr << "!! unable to open the necessary files.\n";
        return -1;
    }

    istream_iterator<string> isf(in_file);
    istream_iterator<string> eoff;

    vector<string> fvec;
    copy(isf, eoff, back_inserter(fvec));

    sort(fvec.begin(), fvec.end());

    ostream_iterator<string> osf(out_file, " ");
    copy(fvec.begin(), fvec.end(), osf);
    
    return 0;
}