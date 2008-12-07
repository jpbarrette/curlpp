#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <ctime>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>

#define CURLPP_ALLOW_NOT_AVAILABLE

#include <curlpp/Infos.hpp>
#include <curlpp/Options.hpp>

using namespace std;

using namespace cURLpp;
using namespace cURLpp::Options;


class YesNo {
public:
    explicit YesNo(bool yn) : yesno(yn) {}
    string operator()() const {
        return yesno ? "Yes" : "No";
    }
    friend ostream &operator<<(ostream &strm, const YesNo &yn) {
        strm << yn();
        return strm;
    }
private:
    bool yesno;
};

struct MyCookie {
    string name;
    string value;
    string domain;
    string path;
    time_t expires;
    bool tail;
    bool secure;
};

ostream &
operator<<(ostream &strm, const MyCookie &cook)
{
    strm << "Cookie: '" << cook.name << "' (secure: " << YesNo(cook.secure) << ", tail: "
        << YesNo(cook.tail) << ") for domain: '" << cook.domain << "', "
        << "path: '" << cook.path << "'.\n";
    strm << "Value: '" << cook.value << "'.\n";
    strm << "Expires: '" << ctime(&cook.expires) << "'.\n";

    return strm;
}

vector<string> &
split_cookie_str(const string &str, vector<string> &in)
{
    string part;

    istringstream strm(str);
    while (getline(strm, part, '\t'))
        in.push_back(part);

    return in;
}

vector<string>
splitCookieStr(const string &str)
{
    vector<string> split;
    split_cookie_str(str, split);
    return split;
}

vector<string> &
splitCookieStr(const string &str, vector<string> &in)
{
    return split_cookie_str(str, in);
}

int StrToInt(const string &str)
{
    istringstream strm(str);
    int i = 0;
    if (!(strm >> i)) {
        throw RuntimeError("Unable to convert string '" + str + "' to integer!");
    }
    return i;
}

MyCookie
MakeCookie(const string &str_cookie)
{
    vector<string> vC = splitCookieStr(str_cookie);
    MyCookie cook;

    cook.domain = vC[0];
    cook.tail = vC[1] == "TRUE";
    cook.path = vC[2];
    cook.secure = vC[3] == "TRUE";
    cook.expires = StrToInt(vC[4]);
    cook.name = vC[5];
    cook.value = vC[6];

    return cook;
}

int
main(void)
{
    try {
        Cleanup myCleanup;
        Easy exEasy;
        vector<string> cookieList;

        // a cookie as in HTTP header
        cookieList.push_back("Set-Cookie: GMAIL_AT=EXPIRED;expires=Sun, 17-Jan-2038 19:14:07 GMT; path=/; domain=.google.com");

        // a Netscape style cookie with \t
        cookieList.push_back(".google.com\tTRUE\t/\tFALSE\t2147483647\tLSID\tI like you GOOGLE");

        // a Netscape style cookie with tabs in string
        cookieList.push_back(".yahoo.com	TRUE	/	FALSE	0	YAHOO_COOKIE	I like you yahoo, too");
        
        exEasy.setOpt(new Url("http://www.google.com"));
        exEasy.setOpt(new FileTime(true));
        exEasy.setOpt(new Verbose(true));

        // loop throught the cookies and add one by one
        //
        for (vector<string>::iterator it = cookieList.begin();
            it != cookieList.end();
            ++it)
        {
	  exEasy.setOpt(CookieList(*it));
        }
        exEasy.perform();
        
        // see what cookies we got
        //
        cout << "\nCookies from cookie engine:" << endl;
        list< string > cookies;
        Infos::CookieList::get(exEasy, cookies);
        int i = 1;
        for (list< string >::const_iterator it = cookies.begin();
            it != cookies.end();
            ++it, i++)
        {
            cout << "[" << i << "]: " << MakeCookie(*it) << endl;
        }

        exit(EXIT_SUCCESS);
    }
    catch(RuntimeError &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch(LogicError &e)
    {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}
