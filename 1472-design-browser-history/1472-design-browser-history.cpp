class BrowserHistory {
public:
    int c=0;
int c_max=0;
unordered_map<int,string>mp;
BrowserHistory(string homepage) {
    mp[c]=homepage;
}

void visit(string url) {
    c++;
    mp[c]=url;
    c_max=c;
}

string back(int steps) {
    c=c-steps;
    if(c<0)c=0;
    return mp[c];
}

string forward(int steps) {
    c=c+steps;
    if(c>c_max)c=c_max;
    return mp[c];
}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */