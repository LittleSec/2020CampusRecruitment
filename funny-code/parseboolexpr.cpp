#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int findMatchRightBracketIdx(string &s, int start) {
        if (s.empty() || s[start] != '(') {
            return 0;
        }
        int bracketslevel = 1;
        for (int i = start+1; i < s.length(); i++) {
            if (s[i] == '(') {
                bracketslevel++;
            }
            else if (s[i] == ')') {
                bracketslevel--;
                if (bracketslevel == 0) {
                    return i;
                }
            }
        }
        cout << "input invalid!" << endl;
        return s.length()-1; // should not here!
    }

    bool parseBoolExprHelper(string& exp, int *end) { // handler brackets!
        // cout << "parseBoolExprHelper: " << exp << endl;
        if (exp.length() == 1) {
            return exp == "t";
        }
        int tmpend = *end;
        string curexp;
        bool res = false;
        switch (exp[0]) {
            case '!': 
                tmpend = findMatchRightBracketIdx(exp, 1);
                curexp = exp.substr(2, tmpend-2);
                res = parseNotExpr(curexp); 
                break;
            case '|': 
                tmpend = findMatchRightBracketIdx(exp, 1);
                curexp = exp.substr(2, tmpend-2);
                res = parseAndOr(curexp, false); 
                break;
            case '&': 
                tmpend = findMatchRightBracketIdx(exp, 1); 
                curexp = exp.substr(2, tmpend-2);
                res = parseAndOr(curexp, true); 
                break;
            // case 't': break;
            // case 'f': break;
            default: cout << "should not here(parseBoolExprHelper)" << endl;;
        }
        *end = tmpend;
        return res;
    }

    bool parseNotExpr(string& exp) { // not brackets
        // cout << "parseNotExpr " << exp << endl;
        int tmpend = exp.length()-1;
        switch (exp[0]) {
            case 't': return false;
            case 'f': return true;
            default: return !parseBoolExprHelper(exp, &tmpend);
        }
    }

    // andor: and is true, or is false;
    bool parseAndOr(string& exp, bool aoflag) {
        // cout << "parseAndOr " << exp << endl;
        bool res = aoflag;
        string curexp;
        for (int i = 0; i < exp.length(); i++) {
            int tmpend = 0;
            switch (exp[i]) {
                case 't': 
                    if (aoflag == false) {
                        return true;
                    }
                    break;
                case 'f':
                    if (aoflag) {
                        return false;
                    }
                    break;
                case ',': break;
                default:
                    curexp = exp.substr(i);
                    if (aoflag) {
                        res &= parseBoolExprHelper(curexp, &tmpend);
                        // cout << "parseAndOr: " << curexp << " -- " << res << endl;
                    }
                    else {
                        res |= parseBoolExprHelper(curexp, &tmpend);
                        // cout << "parseAndOr: " << curexp << " -- " << res << endl;
                    }
                    break;
            } 
            i += tmpend;
        }
        return res;
    }

    bool parseBoolExpr(string expression) {
        if (expression.length() == 1) {
            return expression == "t";
        }
        int tmpend = expression.length()-1;
        return parseBoolExprHelper(expression, &tmpend);
    }
};

int main() {
    Solution sol;
    cout << sol.parseBoolExpr("&(t,!(t),t)") << endl;

    return 0;
}

