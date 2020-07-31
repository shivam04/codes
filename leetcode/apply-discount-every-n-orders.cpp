class Cashier {
public:
    int n,discount;
    vector<int> prices;
    map<int,int> mp;
    int cnt = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        for(int i=0;i<products.size();i++) {
            this->mp[products[i]] = i;
        }
        this->prices = prices;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double bill = 0.0; 
        for(int i=0;i<product.size();i++) {
            bill += prices[mp[product[i]]]*amount[i];
        }
        if(cnt%n == 0) {
            bill = bill - (discount*bill/100.0);
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */