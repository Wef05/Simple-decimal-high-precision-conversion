#include <iostream>
#include <string>
using namespace  std;
#define MAX_ARRAY 2007
class highCount{
private:
    int TheMax(int a,int b){
        if(a>b)return a;
        return b;
    }
    int TheMin(int a,int b){
        if(a<b)return a;
        return b;
    }
protected:
    int ConvertCharToint(char a){
        return int(a)-48;
    }
    char ConvertIntToChar(int a){
        return char(a+48);
    }
public:
    string theNumber;
    string aAndB(highCount a,highCount b){
        string  c;
        int MAX_length= TheMax(a.theNumber.length(),b.theNumber.length());
        int MIN_length= TheMin(a.theNumber.length(),b.theNumber.length());
        int hadMore=0;
        for(int i=MIN_length-1;i>=0;i--){
            int sum= ConvertCharToint(a.theNumber[i])+ConvertCharToint(b.theNumber[i])+hadMore;
            if(sum>=10){
                hadMore=sum-9;
                sum-=10;
            }
            else{
                hadMore=0;
            }
            c[i]=ConvertIntToChar(sum);
        }

    }
};
class toBeConvertNumber:highCount{
private:
    string theNumber;
    int nowBase;
    int targetBase;
    int base10Number;
    int convertedNumberList[MAX_ARRAY];
    int totalLength;//
    int pf(int a,int b){
        int result=1;
        for(int i=1;i<=b;i++){
            result*=a;
        }
        return result;
    }
    int return10BaseNumber(){
        base10Number = 0;
        for (int i = theNumber.length() - 1; i >= 0; i--) {
            int nowNumber;
            if (theNumber[i] >= 48 and theNumber[i] <= 58) {
                nowNumber = (int(theNumber[i]) - 48);
            } else {
                nowNumber = int(theNumber[i]) - 55;
            }
            base10Number += nowNumber * pf(nowBase, theNumber.length() - i - 1);
        }
        return base10Number;
    }
    void convert10BaseToOtherBase(){
        for (totalLength = 0; base10Number > 0; totalLength++) {
            convertedNumberList[totalLength] = base10Number % targetBase;
            base10Number -= base10Number % targetBase;
            base10Number /= targetBase;
        }
    }
    void PrintResult(){
        for (totalLength--; totalLength >= 0; totalLength--) {
            if (convertedNumberList[totalLength] < 10) {
                cout << convertedNumberList[totalLength];
            } else {
                cout << char(convertedNumberList[totalLength] + 55);
            }
        }
        cout << endl;
    }
public:
    void getTheNumber(){
        cin>>theNumber;
        cin>>nowBase;
        cin>>targetBase;
    }
    void ConvertAndPrint(){
        return10BaseNumber();
        convert10BaseToOtherBase();
        PrintResult();
    }

};
void ConvertNumber(toBeConvertNumber item){
    item.ConvertAndPrint();
}
int main() {
    while (1) {
        toBeConvertNumber item;
        item.getTheNumber();
        ConvertNumber(item);
    }
    return 0;
}
