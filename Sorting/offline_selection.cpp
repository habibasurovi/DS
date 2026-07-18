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
void insertionSort()
{
    for(int i = 1; i<books.size(); i++)
    {
        book key = books[i];
        int j = i - 1;
        while(j>=0)
        {
            if(books[j].year < key.year)
            {
                books[j+1] = books[j];
                j--;
            }
            else if(books[j].year == key.year)
            {
                if(books[j].author> key.author)
                {
                    books[j+1] = books[j];
                    j--;
                }
                else if(books[j].author == key.author)
                {
                     if(books[j].title> key.title)
                     {
                        books[j+1] = books[j];
                        j--;
                     }
                     else
                        break;
                }
                else
                    break;
            }
            else
                break;
        }
        books[j+1]= key;
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
        int titleIndex = line.find(",");
            //finds the index of comma
        int authorIndex = line.find(",", titleIndex + 1);
            //finds the 2nd index of comma

        b.title = line.substr(0,titleIndex);
            //substr(startIndex, length)
            //length-> if length is 7, will take characters of index (0-6)
        b.author = line.substr(titleIndex + 1, authorIndex - titleIndex - 1);
        b.year = stoi(line.substr(authorIndex + 1 ));
            //will convert string to integer till last index
        books.push_back(b);
    }
    insertionSort();
    //selectionSort();
    for(int i = 0; i<books.size(); i++)
    {
        cout<< books[i].title << ","<< books[i].author << ", "<< books[i].year << endl;
    }

}
