#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

void AllUppercase(char*, int);
void reverse(char*, int);


int main()
{
  string text;
  cout << "Please enter your text : ";
  getline(cin, text);
  cout << "The keyboard input was : " << text << endl << endl;
  cout << "The uppercase output is : ";
  char arr[text.size()];
  char arr2[text.size()];

  for (int i = 0; i < text.size(); ++i)
  {
    arr[i] = text[i];
  }
  for (int i = 0; i < text.size(); ++i)
  {
    arr2[i] = text[i];
  }
  char *ptr = arr;
  char *ptr2 = arr2;
  AllUppercase(ptr, text.size());
  cout << arr << endl;

  reverse(ptr2, text.size());
  cout << "The reverse output is : ";
  for (int i = 0; i < text.size(); ++i)
  {
    cout << arr2[i];
  }
  cout << endl;

  return 0;
}

void AllUppercase(char *ptr, int n)
{
  for (int i = 0; i < n; ++i)
  {
    ptr[i] = toupper(ptr[i]);
  }
}

void reverse(char *ptr, int n)
{
  char temp;
  for (int i = 0; i < n/2; ++i)
  {
    temp = ptr[i];
    ptr[i] = ptr[n-1-i];
    ptr[n-1-i] = temp;
  }
  //std::reverse(ptr, ptr+n);
}
