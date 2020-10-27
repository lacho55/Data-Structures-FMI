#include<iostream>
#include<string>

static unsigned currentNumber = 0;

class Table{
    private:
        std::string nameOfTable;
        enum Type {INT, STRING} typeOfData;
        int number;

    public:
        

        Table(){
            nameOfTable = "name1";
            typeOfData = Type::INT;
            number = ++currentNumber;
        }


        Table(const std::string&name,const std::string& type){
            nameOfTable = name;

            if(type == "INT"){
                typeOfData = Type::INT;

            }else{
                typeOfData = Type::STRING;
            }  
            number = ++currentNumber;

        }


        const std::string getType() const{
            if(typeOfData == Type::INT){
                return "INT";

            }else{
                return "STRING";
            }
        }


        void print() const{
            std::cout << "Name of table: " << nameOfTable << ", Type of data: " << getType() << ", Number: " << number << std::endl;
        }

};



int main(){
    Table table1;
    Table table2("name2", "INT");
    Table table3;

    table1.print();
    table2.print();
    table3.print();

    return 0;
}
