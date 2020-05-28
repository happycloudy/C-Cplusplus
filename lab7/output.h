void Output(Shoes arrObj[]){
    int isoutputConsole;
    cout << "Output in console?(1 - yes , 0 - no)";
    cin >> isoutputConsole;
    if(isoutputConsole == 1){
        cout << "Model" << setw(30) << "Company" << setw(30) << "Price" << setw(30) << "Amount" << endl;
        for (int i = 0; i < N; i++)
            arrObj[i].ShowDataInConsole();
        cout << "Do you need to show shoes , which have price more then Adidas?(1 - yes ; 0 - no) ";
        bool consoleAnswer;
        cin >> consoleAnswer;
        if (consoleAnswer == true)
        {
            cout << endl
                 << "Price more then Adidas" << endl;
            int sr, sum, kol = 0;
            for (int i = 0; i < N; i++)
                if (arrObj[i].GetCompany() == "Adidas")
                {
                    sum = arrObj[i].GetPrice();
                    kol++;
                }
            sr = sum / kol;
            for (int i = 0; i < N; i++)
            {
                if (arrObj[i].GetPrice() > sr && arrObj[i].GetCompany() != "Adidas")
                {
                    arrObj[i].ShowDataInConsole();
                }
            }
        }
    }else if( isoutputConsole == 0){
        cout << "Writing in file..." << endl;
        ofstream out("output.txt");
        out << "Model" << setw(30) << "Company" << setw(30) << "Price" << setw(30) << "Amount" << endl;
        for (int i = 0; i < N; i++)
            out << arrObj[i].GetModel() << setw(30) << arrObj[i].GetCompany() << setw(30) << arrObj[i].GetPrice() << setw(30) << arrObj[i].GetAmount()  << endl;
        
        cout << "Do you need to show shoes , which have price more then Adidas?(1 - yes ; 0 - no) ";
        bool consoleAnswer;
        cin >> consoleAnswer;
        if(consoleAnswer == true){
            out << endl
                << "Price more then Adidas" << endl;
            int sr, sum, kol = 0;
            for (int i = 0; i < N; i++)
                if (arrObj[i].GetCompany() == "Adidas")
                {
                    sum = arrObj[i].GetPrice();
                    kol++;
                }
            sr = sum / kol;
            for (int i = 0; i < N; i++)
            {
                if (arrObj[i].GetPrice() > sr)
                {
                    out << arrObj[i].GetModel() << setw(30) << arrObj[i].GetCompany() << setw(30) << arrObj[i].GetPrice() << setw(30) << arrObj[i].GetAmount() << endl;
                }
            }
        }
        
        cout << "Writed!";
    }else{
        cout << "Input Error, restart programm";
        exit(1);
    }
}