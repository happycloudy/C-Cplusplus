int Read(Shoes arrObj[]){
    int isConsole;
    cout << "Read from console?(1 - yes ; 0 - no) ";
    cin >> isConsole;
    if(isConsole == 1){
        for (int i = 0; i < N; i++)
        {
            cout << "Write Model , Company , Price and Amount(in correct position)";
            string Model, Company;
            int Price, Amount;
            cin >> Model >> Company >> Price >> Amount;
            arrObj[i] = Shoes(Model,Company,Price,Amount);
        }
    }
    else if(isConsole == 0){
        cout << "Reading from file..." << endl;
        ifstream in("input.txt");
        if (in.is_open())
        {
            for (int i = 0; i < N; i++)
            {
                string Model, Company;
                int Price, Amount;
                in >> Model >> Company >> Price >> Amount;
                arrObj[i] = Shoes(Model,Company,Price,Amount);
            }
        }
        in.close();
    }
    else{
        cout << "Input Error, restart programm";
        exit(1);
    }
}