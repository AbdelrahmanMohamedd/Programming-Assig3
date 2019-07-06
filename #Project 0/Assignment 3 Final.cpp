#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
/*
Faculty of Computers and Info, Cairo University.
Authors: Abdelrahman Mohamed Ahmed Mahmoud.   ID:20170148   G6
         Sayed Ali Sayed Mohamed.             ID:20170122   G5
         Abdelaziz Mohsen Abdelaziz Mahdy.    ID:20170155   G6
Assignment 3 in Programmig 1
Date: 10 April 2018
*/
void load();
void creat(char[]);
void display();
void save(char[]);
int wcount();
int chcount();
void searching(string);
void deleting();
void AddContent();
void Replace();
void ToUpper();
void ToLower();
void AddFile();
void ROT13Cipher();
fstream datafile;
char filename[81];

int main()
{
    while (true)
    {
        cout<<"Welcome ya user ya habib alb albe \n "<<endl;
i:
        cout<<"What would you like to do now ?! \n"<<endl;
        cout<<"  1- Load an Existing file"<<endl;
        cout<<"  2- Create a new file "<<endl;
        cout<<"  3- Display a file content"<<endl;
        cout<<"  4- Save the loaded text to the same file again or different one "<<endl;
        cout<<"  5- Count the words and charachters in the file"<<endl;
        cout<<"  6- Search for a word if a file "<<endl;
        cout<<"  7- Empty file content "<<endl;
        cout<<"  8- Add more content to the end of the file "<<endl;
        cout<<"  9- Replace a word in the file with another word "<<endl;
        cout<<" 10- Turn all the content file to upper case"<<endl;
        cout<<" 11- Turn all the content file to lower case"<<endl;
        cout<<" 12- Add another file to the end of the current file"<<endl;
        cout<<" 13- Encrypt and decrypt the file"<<endl;
        break;
    }


    string name;
    string sword;
    char newfile[81];
    int result;
    cin >> result;

    if(result==1) load();
    else if (result==2)  creat(filename);
    else if (result==3)  display();
    else if (result==4)  save(newfile);
    else if (result==5)
    {
        cout << "The Number of Words is:" << wcount() << endl;
        cout << "The Number of characters is: " << chcount() << endl;
    }
    else if (result==6)  searching(sword);
    else if (result==7)  deleting();
    else if (result==8)  AddContent();
    else if (result==9)  Replace();
    else if (result==10) ToUpper();
    else if (result==11) ToLower();
    else if (result==12) AddFile();
    else if (result==13) ROT13Cipher();
    goto i ;
    return 0;
}
void load()
{
    fstream file;
    cout<<"Enter the File Name and its extension: ";
    cin.get();
    cin.getline(filename, 81);
    file.open(filename,ios::in);
    if(file.fail())
    {
        cout << "File can't open!" << endl;
    }
    else cout<<"\n The File "<<filename<<" is opened successfully"<<endl;
    cout<<"\n"<<endl;
    datafile.close() ;

}
////////////////////////////////////////////////////////////////////////////////////////////////
void creat(char filename[81])
{
    cin.ignore();
    cout<<"Enter the new File name.txt: ";
    cin.getline(filename,81);
    datafile.open(filename,ios::out);
    cout<<"\n The File "<<filename<<" is created successfully.\n"<<endl;
    cout<<"\n"<<endl;
    datafile.close() ;

}
////////////////////////////////////////////////////////////////////////////////////////////////
void display()
{
    char data[1000];
    datafile.open(filename,ios::in);
    while(!datafile.eof() && !datafile.fail())
    {
        datafile.getline(data,1000);
        cout <<"\n"<< data << '\n';
    }
    cout<<"\n"<<endl;
    datafile.close() ;

}
////////////////////////////////////////////////////////////////////////////////////////////////
void save(char newfile[81])
{
    int x;
    cout<<" 1- Save at the same File."<<endl
        <<" 2- Save at new File."<<endl
        <<" 3- Back to The Main Menu"<<endl;
    cin>>x;
    ifstream datafile;
    datafile.open(filename);
    while(!datafile.fail())
    {   if(x==1)
        {
            cout<<"\n Done!"<<endl;
            break;
        }
        if(x==2)
        {
            //char newfile[81];
            ifstream datafile;
            ofstream infile;
            string text;
            cin.ignore();
            cout<<"Enter the another File Name.txt: ";
            cin.getline(newfile,81);
            datafile.open(filename);
            infile.open(newfile);
            while(!datafile.eof())
            {
                datafile>>text;
                infile<<text<<" ";
            }
            cout<<"\n The File data is saved in another file "<<endl;
            infile.close();
            cout<<"\n"<<endl;
            break;
        }
        if(x==3) {
            cout<<"Ended"<<endl;
            break;
            }
    }
    cout<<"\n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int wcount()
{   string words;
    int counter =0;
    ifstream datafile ;
    datafile.open(filename,ios::in);
    while(!datafile.eof() && !datafile.fail())
    {
        datafile >> words;
        counter+=1;
    }
    cout << "The Number of Words is:" << counter <<endl;
    cout<<"\n"<<endl;
    datafile.close() ;
    return counter;
}
int chcount()
{
    string words;
    char ch;
    int counter2=0;
    ifstream datafile ;
    datafile.open(filename,ios::in);
    while(!datafile.eof() && !datafile.fail())
    {
        datafile >> words;
        counter2+=words.size();
    }
    cout <<"The Number of characters is: " << counter2 <<endl;
    cout<<"\n"<<endl;
    datafile.close() ;
    return counter2;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void searching(string sword)
{
    string word;
    ifstream datafile;
    cout<<"Enter Word to search for: ";
    cin>>sword;
    datafile.open(filename) ;
    while(!datafile.eof())
    {
        datafile >> word;
        if(word==sword)
        {
            cout<<"The Word is Existed"<<endl;
            break;
        }
        else
        {
            cout<<"The Word is NOT Existed"<<endl;
            break;
        }
    }
    datafile.close() ;

    cout<<"\n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void deleting()
{
    datafile.open(filename,ios::out);
    cout<<"The File became empty now."<<endl;
    datafile.close();
    cout<<"\n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void AddContent()
{   string text;
    fstream file;
    file.open(filename,ios::out|ios::app);
    cout<<"\n Enter the content that you want to add to the file... \n";
    cin.ignore();
    getline(cin,text);
    cout <<"\n the Content: "<< text <<" is Added to the file data successfully \n \n "<< endl;
    file << text << " " ;
    file.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void Replace()
{
    fstream file, temp;
    string word, rep, data;
    file.open(filename, ios::in);
    temp.open("temp.txt", ios::out);
    cout << "Enter the existed word : ";
    cin >> word;
    cout << "Enter the new word : ";
    cin >> rep;
    file >> data;
    while(!file.eof() && !file.fail())
    {
        if(data != word) temp << data << " ";
        else temp << rep << " ";
        file >> data;
    }
    file.close();
    temp.close();
    file.open(filename,ios::out | ios :: trunc);
    temp.open("temp.txt", ios::in);
    temp >> data;
    while(!temp.eof() && !temp.fail())
    {
        file << data << " ";
        temp >> data;
    }
    file.close();
    temp.close();
    cout<<"\n the new word is REPLACED by the Existed word \n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ToUpper()
{
    char data;
    fstream file;
    vector<char> content;
    file.open(filename, ios::in);
    while(!file.eof() && !file.fail())
    {
        file >> data;
        content.push_back(toupper(data));
    }
    file.close();
    file.open(filename, ios:: out);
    for(int i=0 ; i<content.size() ; ++i)
    {
        file << content[i];
    }
    cout<<"\n Now The file data is in UPPER case"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ToLower()
{
    ifstream filename1;
    ofstream temp("temp1.txt");
    filename1.open(filename);
    string word;
    while (!filename1.eof())
    {
        filename1 >> word;
        for (size_t j=0; j< word.length(); ++j)
        {
            word[j] = tolower(word[j]);
        }
        cout<<word;
       temp << word;
    }
    filename1.close();
    temp.close();
    ifstream temp1("temp1.txt");
    ofstream filename11(filename);
    while(!temp1.eof())
    {
        char line[1000];
        temp1.getline(line,1000);
        filename11 << line;
        if(!temp1.eof())
            filename11 << "\n";
    }
    cout<<" \n "<<endl;
    cout<<"Now the file content is in LOWER case \n \n"<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void AddFile()
{
    char file1[81], file2[81];
    cout << "Enter the main file name: ";
    cin >> file1;
    cout << "Enter the second file name: ";
    cin >> file2;
    ifstream ifile(file1, ios::in);
    ofstream ofile(file2,  ios::out | ios::app);
    if (!ifile.is_open())
    {
        cout<<"The file is not found \n\n";
    }
    else
    {   ofile << ifile.rdbuf();
        cout<<"the file is added to the second file successfully \n\n";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ROT13Cipher ()
{
    fstream file;
    file.open(filename, ios::in);
    int x ;
    while(true)
    {
        cout<<endl;
        cout<<endl;
        cout << " \n Welcome to ROT13 Cipher & Decipher \n \n"<<endl;
        cout << " what do like to do ?"<<endl;
        cout << " 1- Cipher a message "<<endl;
        cout << " 2- Decipher a message"<<endl;
        cout << " 3- End\n  " <<endl;
        cin >> x ;
        if ( x == 1)
        {
            string text ;
            char message[1000];
            while(!file.eof() && !file.fail())
            {
                file.getline(message,1000);
                for (int i = 0 ; message[i]!='\0'; ++i )
                {
                    if (( (int) message[i]>= 65 && (int) message[i] <= 77 ) || ((int) message[i]>= 97 && (int) message [i] <= 109  ))
                    {
                        text += ( (char)( (int) message[i] + 13 )  );
                    }
                    else if (( (int) message[i]>= 78 && (int) message[i] <= 90 ) || ((int) message[i]>= 110 && (int) message [i] <= 122  ))
                    {
                        text +=  ( (char) ( (int) message[i]-13 ) ) ;
                    }
                    else
                    {
                        text += message[i] ;
                        continue ;
                    }
                }
                text+='\n';
                file.close();
                ofstream file1(filename);
                file1 << text;
                cout << text;
                text = " ";
            }
                file.close();
                ofstream file1(filename);
                file1 << text;
                file1.close();
        }
        else if ( x == 2)
        {
            string  text ;
            char message[1000];
            while(!file.eof() && !file.fail())
            {
                file.getline(message,1000);
                for(int i=0;message[i]!='\0';++i)
                {
                    if( (int(message[i])>=78&&int(message[i])<=90) || (int(message[i])>=110&&int(message[i])<=122) )
                    {
                        text+=char(int(message[i])-13);
                    }
                    else if( (int(message[i])>=65&&int(message[i])<78) || (int(message[i])>=97&&int(message[i])<110) )
                    {
                        text+=char(int(message[i])+13);
                    }
                    else
                        text+=message[i];
                }
                cout << text ;
                 file.close();
                ofstream file1(filename);
                file1 << text;
                file1.close();
                text = " ";
            }
        }
        else{
            cout << " Good Bye \n " ;
            break;
        }
    }
}
