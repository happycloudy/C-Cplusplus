using namespace std;
class Shoes{
    private:
        string Model;
        string Company;
        int Price;
        int Amount;

    public:
    void BuyShoes(){
        cout<< "Shoes has been bought!" <<endl;
    }
    Shoes(){}
    Shoes(string Model , string Company , int Price , int Amount){  //void SetData
        this -> Model = Model;
        this -> Company = Company;
        this -> Price = Price;
        this -> Amount = Amount;
    }
    string GetModel(){
        return Model;
    }
    string GetCompany(){
        return Company;
    }
    int GetPrice(){
        return Price;
    }
    int GetAmount(){
        return Amount;
    }
    void ShowDataInConsole(){
        cout << Model << setw(30) << Company << setw(30) << Price << setw(30) << Amount << endl;
    }

    Shoes(const Shoes &child){
        this->Model = child.Model;
        this->Company = child.Company;
        this->Price = child.Price;
        this->Amount = child.Amount;
    }
    
};