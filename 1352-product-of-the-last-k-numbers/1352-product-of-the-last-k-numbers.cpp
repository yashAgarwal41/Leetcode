class ProductOfNumbers {
public:
    //TC-O(n)..
    vector<int> prod;       //prefixProduct of product
    vector<int> cntZero;    //prefixSum of no of zeros
    int last, i, cnt;   
    //last-product till now, i-current index, cnt-no of zeros till now
    ProductOfNumbers() {
        //initialsiing all variables..
        last = 1;
        i=0;
        cnt=0;
        prod.push_back(1);
        cntZero.push_back(0);
    }
    
    void add(int num) {
        if(num==0)
        {
            last = 1;
            cnt++;
            prod.push_back(0);
        }
        else 
        {
            last *= num;
            prod.push_back(last);
        }
        i++;
        cntZero.push_back(cnt);
    }
    
    int getProduct(int k) {
        int l = i-k;
        int r = i;
        int zero = cntZero[r] - cntZero[l];
        if(zero>0)  return 0;   //if zero exist in between product
        if(prod[l]==0)    return prod[r];   //else if the just left value of startInd is zero 
        return prod[r]/prod[l]; //else return product of the window..
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */