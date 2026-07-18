#include<bits/stdc++.h>
using namespace std;
struct book
{
   string title;
   string author;
   int year;

};
vector<book> books;

void selectionSort()
{
    for(int i = 0; i<books.size()-1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j< books.size(); j++)
        {
            if(books[j].year > books[minIndex].year)
            {
                minIndex = j;
            }
            else if(books[j].year == books[minIndex].year )
            {
                if(books[j].author < books[minIndex].author)
                {
                    minIndex = j;
                }
                else if(books[j].author == books[minIndex].author)
                {
                    if(books[j].title < books[minIndex].title)
                    {
                        minIndex = j;
                    }
                }
            }
        }
        swap(books[i],books[minIndex]);
    }

}


int main()
{
    int n;
    book b;
    string line;
    cin>>n;
    cin.ignore();
    for(int i = 0; i<n; i++)
    {
        getline(cin, line);
        int titleIndex = line.find( ",");
        int authorIndex = line.find(",", titleIndex + 1);
        b.title = line.substr(0,titleIndex);
        b.author = line.substr(titleIndex + 1, authorIndex - titleIndex - 1);
        b.year = stoi(line.substr(authorIndex + 1 ));
        books.push_back(b);
    }
    selectionSort();
    for(int i = 0; i<books.size(); i++)
    {
        cout<< books[i].title << ","<< books[i].author << ", "<< books[i].year << endl;
    }
}
