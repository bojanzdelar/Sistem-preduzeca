#include "Util.h"

vector<string> tokenizacija(string &linija, string separator)
{
    vector<string> elementi;
    size_t pos = 0;
    while (true)
    {   
        pos = linija.find(separator);
        if (pos == string::npos)
        {
            break;
        }
        elementi.push_back(linija.substr(0, pos));
        linija = linija.substr(pos + separator.length());
    }
    elementi.push_back(linija);
    return elementi;
}
