class Transaction {
    public:
    string name;
    int time; 
    int amount;
    string city;
    Transaction(string name, int time, int amount, string city) {
        this->name = name;
        this->time = time;
        this->amount = amount;
        this->city = city;
    }
};
class Solution {
    public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<bool> isValid(n, true);
        vector<Transaction> v;
        for(int i=0; i<n; i++) {
            string curr = transactions[i], name = "", time = "", amount = "", city = "";
            int j = 0;
            while(curr[j] != ',') name += curr[j++];
            j++;
            while(curr[j] != ',') time += curr[j++];
            j++;
            while(curr[j] != ',') amount += curr[j++];
            j++;
            while((j < curr.size()) && (curr[j] != ',')) city += curr[j++];
            Transaction newTransaction(name, stoi(time), stoi(amount), city);
            v.push_back(newTransaction);
        }  
        for(int i=0;i<(v.size()); i++) {
            if(v[i].amount > 1000) {
                isValid[i] = false;
                continue;
            } 
            for(int j=0; j<v.size(); j++) {
                if(i == j) continue;
                int timeDiff = abs(v[j].time - v[i].time);
                if(timeDiff <= 60) {
                    if((v[j].name == v[i].name) && (v[j].city != v[i].city)) {
                        isValid[i] = false;
                        isValid[j] = false;
                    }
                }
            }
        }   
        vector<string> output;
        for(int i=0;i<v.size(); i++) {
            if(!isValid[i]) output.push_back(transactions[i]);
        }
        return output;
    }
};