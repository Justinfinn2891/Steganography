
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cout<<"What type of operation are you running?(E or D/)"<<endl;
  char operation;
  cin>>operation;
  operation=tolower(operation);
  if(operation=='c'){
    cout<<"success"<<endl;
  }
  else if(operation=='d'){
    cout<<"success"<<endl;
  }
  else{
    cout<<"Error"<<endl;
  }
  return 0;
}
