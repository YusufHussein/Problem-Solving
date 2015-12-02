class FenwickTree
{
#define data_type int
#define LSOne(a) ((a)&(-(a)))
private:
    vector<data_type> ft;
public:
    FenwickTree(data_type n)
    {
        ft.assign(n + 1, 0);
    }
    data_type rsq(int b){
        data_type sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    data_type rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }
    void adjust(int k, data_type v){
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
    void set(int k,data_type v){
        data_type diff= v - rsq(k,k);
        adjust(k,diff);
    }
};
