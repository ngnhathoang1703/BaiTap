//#include "Exception.h"
//
//bool CheckName(string name) {     
//    try {
//        stringstream ss(name);
//        string token;
//        while (ss >> token)
//        {
//            for (int i = 0; i < token.length(); i++) {
//                if ((token[i] > 47) && (token[i] < 58)) {
//                    throw NameException("Invalid name!");
//                }
//            }
//        }
//    }
//    catch (NameException& ex1) {
//        cout << ex1.what() << endl;
//        return false;
//    }
//    return true;
//}
//bool CheckDate(string date) {
//    try {                                    
//        stringstream ss(date);             
//        string token;                      
//        while (ss >> token)
//        {
//            if (token.length() != 8) {
//                throw DateException("Invalid date! - dd/mm/yy");
//            }
//            if ((token[2] != '/') || (token[5] != '/')) {
//                throw DateException("Invalid date! - dd/mm/yy");
//            }
//            for (int i = 0; i < token.length(); i++) {
//                
//                if ((i != 2) && (i != 5)) {
//                    if ((token[i] < 48) || (token[i] > 57)) {
//                        throw DateException("Invalid date! - dd/mm/yy");
//                    }
//                }
//            }
//        }
//        stringstream ss1;
//        int day, month, year;
//        ss1 << date.substr(0, 2);
//        ss1 >> day; ss1.clear();
//        ss1 << date.substr(3, 2);
//        ss1 >> month; ss1.clear();
//        ss1 << date.substr(6, 2);
//        ss1 >> year; ss1.clear();
//        if ((day < 1) || (day > 31) || (month < 1) || (month > 12)) {
//            throw DateException("Ngay khong hop le! (4) Sai form: dd/mm/yy");
//        }
//    }
//    catch (DateException& ex2) {
//        cout << ex2.what() << endl;
//        return false;
//    }
//    return true;
//}
//bool CheckPhone(string phone) {
//    try {
//        stringstream ss(phone);
//        string token;
//        while (ss >> token)
//        {
//            if (token.length() != 10) {
//                throw PhoneException("Invalid phone number!");
//            }
//            for (int i = 0; i < token.length(); i++) {
//                if ((token[i] < 48) || (token[i] > 57)) {
//                    throw PhoneException("Invalid phone number!");
//                }
//            }
//        }
//    }
//    catch (PhoneException& ex3) {
//        cout << ex3.what() << endl;
//        return false;
//    }
//    return true;
//}
//bool CheckMail(string mail, string mail_template) 
//{
//    try {
//        stringstream ss(mail);                          
//        string token;                                                 
//        string temp = "";                             
//        if (mail_template.length() == 0) {
//            return false;
//        }
//        while (ss >> token)
//        {
//            if (token.length() < mail_template.length() + 1) {
//                throw EmailException("Invalid email! Mail form: \"...\" + " + mail_template);
//            }
//            for (int i = token.length() - mail_template.length(); i < token.length(); i++) {
//                temp += token[i];
//            }
//        }
//        if (temp != mail_template) {
//            throw EmailException("Invalid email! Mail form: \"...\" + " + mail_template);
//        }
//    }
//    catch (EmailException& ex4) {
//        cout << ex4.what() << endl;
//        return false;
//    }
//    return true;
//}