/*
Name: Demetra Drizis
Section: 7
Due Date: 4/9/18
*/	
class Student
{
public:
    virtual double Average() = 0;
    virtual int Final() = 0;				//makes it an abstract class
    virtual char Final_Grade() = 0;
    const char * Get_First() const;			//returns student's first name
    const char * Get_Last() const;			//returns student's last name
    const char * Get_Course() const;			//returns student's course
     
protected:
    Student();
    Student (char * first, char * last, char * c);		//pointers to get the first, last and course
    char first_name[20];
    char last_name[20];
    char course[10];    
    
private:
    
};


class English : public Student
{
public:
    English (char * first, char * last, char * c, int A, int P, int M, int F);
    double Average();
    int Final();
    char Final_Grade();
    
private:
    int attendance;
    int project;			//private data to get what is needed for this subject
    int midterm;
    int final_ex;
    double english_average;
    
protected:
    
};

class History : public Student
{
public:
    History (char * first, char * last, char * c, int t, int M, int F);
    double Average();
    int Final();
    char Final_Grade();
    
private:
    int term_p;
    int midterm;						 //private data to get what is needed for this subject
    int final_ex;
    double history_average;
    
protected:
};

class Math : public Student
{
public:
    Math(char * first, char * last, char * c, int q1, int q2, int q3, int q4, int q5, int t1, int t2, int F);
    double Average();
    int Final();
    char Final_Grade();
    
private:
    int quiz1;
    int quiz2;						 //private data to get what is needed for this subject
    int quiz3;
    int quiz4;
    int quiz5;
    int test1;
    int test2;
    int final_ex;
    double math_average;
    
protected:
    
};

class StudentList
{
public:
    StudentList();		// starts out empty
    ~StudentList();		// cleanup (destructor)
    bool ImportFile(const char* filename);
    bool CreateReportFile(const char* filename);
    void ShowList() const;	// print basic list data
    void Sort(); 
protected:
    Student ** list;		//pointer to a pointer
    int count;
    void Grow();		//grows size of array
    
private:
    
};
