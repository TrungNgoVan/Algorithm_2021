#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    int score;
    string name;

    Student()
    {
        score = 0;
        name = "";
    }

    const bool operator<(const Student &student)
    {
        bool b = score < student.score;
        if (b == false)
        {
            if (score == student.score)
            {
                int k = name.compare(student.name);
                return k < 0;
            }
            else
                return false;
        }

        return true;
    }
};

int main()
{
    vector<Student> studentList;
    string str_n;
    getline(cin, str_n);
    int n = stoi(str_n);

    for (int i = 0; i < n; i++)
    {
        Student student;
        string score;
        getline(cin, student.name);
        getline(cin, score);

        student.score = stoi(score);

        studentList.push_back(student);
    }

    sort(studentList.begin(), studentList.end());

    int min = studentList[0].score;

    int secondMin;

    for (int i = 1; i < n; i++)
    {
        if (studentList[i].score != min)
        {
            secondMin = studentList[i].score;
            break;
        }
        else
            continue;
    }

    vector<string> studentName;

    for (int i = 1; i < n; i++)
    {
        if (studentList[i].score == secondMin)
        {
            studentName.push_back(studentList[i].name);
        }
        else if (studentList[i].score > secondMin)
        {
            break;
        }
    }

    for (int i = 0; i < studentName.size(); i++)
    {
        cout << studentName[i] << endl;
    }

    return 0;
}
//-----------------------------------------------------------------------------------------
#include <iostream>
#include <string>
void swap(std::string a, std::string b)
{
    std::string temp;
    temp = a;
    a = b;
    b = temp;
}
struct people
{
    people(std ::string st, int t)
    {
        name = st;
        point = t;
    }
    std ::string name;
    int point;
};

int main()
{
    people student[5]{
        people("Trung", 20),
        people("Bao", 80),
        people("An", 100),
        people("Anh", 80),
        people("Hoang", 10),
    };
    int max = student[0].point;

    for (int i = 1; i < 5; i++)
    {
        if (student[i].point > max)
        {
            max = student[i].point;
        }
    }
    // std ::cout << max;
    int min = max - student[0].point, kq = student[0].point;
    for (int i = 1; i < 5; i++)
    {
        if (max - student[i].point < min && student[i].point != max)
        {
            min = max - student[i].point;
            kq = student[i].point;
        }
    }
    std ::string xau[1000];
    int index = 0;
    for (int i = 1; i < 5; i++)
    {
        if (student[i].point == kq)
        {
            xau[index] = student[i].name;
            index++;
        }
    }
    for (int i = 0; i < index; i++)
        for (int j = i + 1; j < index; j++)
        {
            if (xau[i] > xau[j])
            {
                swap(xau[i], xau[j]);
            }
        }
    for (int i = 0; i < index; i++)
    {
        std::cout << xau[i] << std ::endl;
    }
    return (0);
}