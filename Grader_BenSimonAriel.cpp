#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void calcGrade(const vector<pair<string,string> > & , const string &);

int main()
{
  ifstream testInfo("testinformation.txt");
  if (!testInfo)
    throw -1;
  string Ans;
  testInfo >> Ans; // test answers key
  Ans.insert(0," ");
  cout << "Key : " << Ans << endl;
  vector<pair<string,string> > students; //lists all the students after the answer key
  while (!testInfo.fail())
  {
    pair<string, string> student; //first = id, second = test answers
    testInfo >> student.first;
    getline(testInfo, student.second);
    students.push_back(student);
  }
  students.pop_back();
  calcGrade(students, Ans);
  return 0;
}

void calcGrade(const vector<pair<string,string> > &students , const string &testAns)
{
  ofstream output2("Grades_BenSimonAriel.txt");
  for (int i = 0 ; i < students.size(); ++i)
  {
    char grade = ' ';
    int score = 0;
    pair<string, string> currStudent = students[i];
    ofstream output(currStudent.first + "_BenSimonAriel.txt");
    for (int j = 1 ; j < testAns.size(); ++j)
    {
      if (testAns[j] == currStudent.second[j])
        score += 2;
      else if ((testAns[j] != currStudent.second[j]) && currStudent.second[j] != 'b')
        score -= 1;
    }
    if (score > 35 && score <= 40)
      grade = 'A';
    else if (score > 32 && score <= 35)
      grade = 'B';
    else if (score > 28 && score <= 32)
      grade = 'C';
    else if (score > 24 && score <= 28)
      grade = 'D';
    else if (score <= 24)
      grade = 'F';
    output << score;
    cout << students[i].first << " " << students[i].second << " " << score << " " << grade << endl;
    output2 << students[i].first << " " << students[i].second << " " << score << " " << grade << endl;
  }
}
