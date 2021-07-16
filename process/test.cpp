//
// Created by xzh on 2021/7/15.
//

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include<fcntl.h>
using namespace std;
int main(){

  char arr[6];
  memset(arr,' ',6);
  arr[4]='n';
  cout<<arr<<endl;
    return 0;
}