/***********************************************************************
 * Assignmentprogrammingautumnversion2.c
 * Program to record marks of students and calculate grades
 * Mohammed Naeem
 * Version 5
***********************************************************************/

#include <stdio.h>
/*Prodotypes*/
void DisplaymainTitle(void);
void getnameofstudents(char studentNames[][30], int n);
void getStudentMarks(int StudentMarks[100][3], int n);
int numStu(int Getnumofstudents);
void Displaymenuoptions(void);
int ChooseMenuOption(int StudentMarks[100][3],int Getnumofstudents, 
                char studentNames[][30], int pin);
int Displaymarks(int Getnumofstudents, int StudentMarks[100][3],
                char studentNames[][30]);
void emptytheBuffer(void);
int  EnterPIN(int Getnumofstudents, int StudentMarks[100][3], 
                char studentNames[][30], int pin);
void Displaysupervisoroptions(void);
int Confirmstudentmark(int StudentMarks[100][3], int Getnumofstudents, 
                char studentNames[][30], int pin);
int displayandchoosemenuforoption3(int StudentMarks[100][3],
                int Getnumofstudents, char studentNames[][30], int pin);
int changepin(int pin);
int addstudent(int Getnumofstudents, char studentNames[][30]);
int changemark(int StudentMarks[100][3],int Getnumofstudents, 
                char studentNames[][30], int pin);
void changestudentname(int StudentMarks[100][3],int Getnumofstudents, 
                char studentNames[][30], int pin);

int main(void)
{
    DisplaymainTitle();
    int Getnumofstudents = 100;
    char a[Getnumofstudents][30];
	int StudentMarks[100][3];
	for(int i = 0; i < 100; i++)
	{
	    for(int j = 0; j < 3; j++)
	    {
	        StudentMarks[i][j] = 0;
        }
    }
	int pin = 2468;
	Getnumofstudents = numStu(Getnumofstudents);
    char studentNames[Getnumofstudents][30];
    getnameofstudents(studentNames, Getnumofstudents); 
    Displaymenuoptions();
    ChooseMenuOption(StudentMarks, Getnumofstudents, studentNames,2468);
  	float Courseworkmarks[Getnumofstudents][3];	
}
void DisplaymainTitle(void)
{
    printf("\tAssesment marks for course module\n");
    printf("\t=================================\n\n");
}
void getnameofstudents(char studentNames[][30], int n)
{
	int counter;
    for(counter = 0; counter < n; counter++)
	{
        printf("Enter name of student: ");
        scanf("%s", studentNames[counter]);
    } 
}
void getStudentMarks(int StudentMarks[100][3], int n)
{
	int counter;
	int coursework;
	printf("\nwhich coursework - 1, 2 or 3?: ");
	scanf("%d", &coursework);
	emptytheBuffer();    
    for(counter = 0; counter < n; counter++)
	{
	    do
	    {
	       printf("Enter marks of students in same order: ");
           scanf("%d", &StudentMarks[counter][coursework - 1]);
           if(StudentMarks[counter][coursework - 1]> 100)
           {
               puts("\nERROR - Enter mark out of 100");
           }
        } while(StudentMarks[counter][coursework - 1] > 100);    
    } 
}
int numStu(int Getnumofstudents)
{
    while(Getnumofstudents > 75)
    {
        printf("Enter number of students: ");
        scanf("%d", &Getnumofstudents);
        if(Getnumofstudents > 75)
        {
        	printf("\nERROR - You cannot have more than "
                            "75 students\n\n");
    	} 
    }    
    return Getnumofstudents;
}
void Displaymenuoptions(void)
{
    printf("\n1. MARKS\n");
    printf("2. DISPLAY MARKS\n");
    printf("3. SUPERVISOR MODE\n");
    printf("4. EXIT\n");
}
int ChooseMenuOption(int StudentMarks[100][3],int Getnumofstudents, 
                        char studentNames[][30], int pin)
{
    int num = 5;
    while(num != 4)
    {
        printf("\n\nChoose a menu option 1,2,3 or 4?: ");
        scanf("%d", &num);
        if(num > 4 || num < 1)
        {
            printf("\nError - Enter a number option from 1-4\n");    
        }
        else if(num == 1)
        {
            printf("\nYou have chosen MARKS\n");
            getStudentMarks(StudentMarks, Getnumofstudents);
            Confirmstudentmark(StudentMarks, Getnumofstudents, 
                                studentNames, pin); 
        }
        else if(num == 2)
        {
            printf("\nYou have chosen DISPLAY MARKS");
            Displaymarks(Getnumofstudents, StudentMarks, studentNames);
            ChooseMenuOption(StudentMarks,Getnumofstudents, 
                                studentNames, pin); 
        }  
        else if(num == 3)
        {
            printf("\nYou have chosen SUPERVISOR MODE");
            EnterPIN(Getnumofstudents, StudentMarks, studentNames, pin);
            displayandchoosemenuforoption3(StudentMarks, 
                            Getnumofstudents, studentNames, pin);  
        }   
        return Getnumofstudents; 
    }         
}
int Displaymarks(int Getnumofstudents, int StudentMarks[100][3], 
                    char studentNames[][30])
{
      for(int i = 0; i <= Getnumofstudents - 1; i++)
      {
          printf("\n%s's Mark: %d %d %d ",
          studentNames[i], StudentMarks[i][0], 
          StudentMarks[i][1], StudentMarks[i][2]);
          printf("Overall Grade: %%%.2f  ", 
          StudentMarks[i][0] * 0.2 + StudentMarks[i][1] * 0.3
           + StudentMarks[i][2] * 0.5);
      }
      return Getnumofstudents; 
}
int  EnterPIN(int Getnumofstudents, int StudentMarks[100][3],
                     char studentNames[][30], int pin)
{
    int PIN;   
    printf("\nEnter PIN: ");
    scanf("%d", &PIN);
    if(PIN == pin)
    {
        printf("\nCorrect PIN");
        printf("\n1. Change PIN Number\n");
        printf("2. Change Mark\n");
        printf("3. Add Student\n");
        printf("4. Change Student Name\n");       
    }
    else
    {
        printf("\nIncorrect PIN, try again");
        EnterPIN(Getnumofstudents, StudentMarks, studentNames, pin);
    }   
void Displaysupervisoroptions(void)                 
    {
    printf("\n1. Change PIN Number\n");
    printf("2. Change Mark\n");
    printf("3. Add Student\n");
    printf("4. Change Student Name\n");
    }  
}
int Confirmstudentmark(int StudentMarks[100][3], int Getnumofstudents, 
                        char studentNames[][30], int pin) 
{
    int yesorno;
    printf("\nConfirm student mark - 1.yes or 2.no: ");
    scanf("%d", &yesorno);
    if(yesorno == 1)
    {
        printf("\nStudent marks confirmed");
        ChooseMenuOption(StudentMarks, Getnumofstudents, studentNames,
                             pin);
    }
    else if(yesorno == 2)
    {
        getStudentMarks(StudentMarks, Getnumofstudents);
        Confirmstudentmark(StudentMarks,Getnumofstudents,studentNames, 
                            pin);
    }
    else
    {
        printf("\nERROR - Please enter 1 for yes or 2 for no");
        Confirmstudentmark(StudentMarks, Getnumofstudents,
                             studentNames, pin);
    }  
    return Getnumofstudents;  
}
int displayandchoosemenuforoption3(int StudentMarks[100][3],
                int Getnumofstudents, char studentNames[][30], int pin)
{
    int num;
    while(num != 5)
    {
        printf("\nChoose a supervisor menu option 1, 2, 3 or 4?");
        printf("\n(Press 5 to return back to menu) : ");
        scanf("%d", &num);
        if(num == 1)
        {
            printf("\nYou have chosen CHANGE PIN");
            pin = changepin(pin);
        }
        else if(num == 2)
        {
            printf("\nYou have chosen CHANGE MARK");
            changemark(StudentMarks,Getnumofstudents,studentNames, pin);
        }
        else if(num == 3)
        {
            printf("\nYou have chosen ADD STUDENT");
            Getnumofstudents = addstudent(Getnumofstudents,
                                     studentNames);
        }
        else if(num == 4)
        {
            printf("\nYou have chosen CHANGE STUDENT NAME");
            changestudentname(StudentMarks,Getnumofstudents, 
                                studentNames, pin);
        }
       else if (num == 5)
       {
           ChooseMenuOption(StudentMarks, Getnumofstudents, 
                            studentNames, pin);
       } 
       else
       {
       	printf("\n\nERROR - Choose an option 1 - 5");
	   }
    }     
    return Getnumofstudents; 
}
int changepin(int pin)
{
	int newpin;
	printf("\nPIN was %d ", pin);
	printf("\n Enter new pin: ");
	scanf("%d", &newpin);
	newpin;
	printf("The new PIN is %d", newpin);
	return newpin;
}
int addstudent(int Getnumofstudents, char studentNames[][30])
{
    printf("\nEnder name of student: ");
    scanf("%s%*c", &studentNames[Getnumofstudents]);
    Getnumofstudents++;
    return Getnumofstudents;
}
int changemark(int StudentMarks[100][3],int Getnumofstudents, 
                        char studentNames[][30], int pin)
{
    int selectstudent;
    int choosecoursework;
    printf("\nEnter student number: ");
    scanf("%d", &selectstudent);
    printf("choose coursework: ");
    scanf("%d", &choosecoursework);
    switch(choosecoursework)
    {
        case 1:
            printf("The current coursework 1 mark is %d\n", 
                            StudentMarks[selectstudent - 1][0]);
            printf("Enter new coursework 1 mark: ");
            scanf("%d", &StudentMarks[selectstudent - 1][0]);
            printf("Coursework 1 mark has been changed\n");
            displayandchoosemenuforoption3(StudentMarks,
                                    Getnumofstudents,studentNames,pin);
            break;
        case 2:
            printf("The current coursework 2 mark is %d\n", 
                                StudentMarks[selectstudent - 1][1]);
            printf("Enter new coursework 2 mark: ");
            scanf("%d", &StudentMarks[selectstudent - 1][1]);
            printf("Coursework 2 mark has been changed\n");
            displayandchoosemenuforoption3(StudentMarks,
                                    Getnumofstudents,studentNames,pin);
            break;
        case 3:
            printf("The current coursework 3 mark is %d\n", 
                                StudentMarks[selectstudent - 1][2]);
            printf("Enter new coursework 3 mark: ");
            scanf("%d", &StudentMarks[selectstudent - 1][2]);
            printf("Coursework 3 mark has been changed\n");
            displayandchoosemenuforoption3(StudentMarks,
                                Getnumofstudents,studentNames,pin);
            break;
        default:
            printf("Please enter 1, 2 or 3\n");
            changemark(StudentMarks,Getnumofstudents, studentNames, 
                                    pin);
    }
}
void changestudentname(int StudentMarks[100][3],int Getnumofstudents, 
                        char studentNames[][30], int pin)
{
    int choosestudent;
    printf("\nWhich student to change - pick a number: ");
    scanf("%d", &choosestudent);
    printf("\nThe name to be changed is %s", 
                            studentNames[choosestudent - 1]);
    printf("\nEnter the new name: ");
    scanf("%s", &studentNames[choosestudent - 1]);
    printf("\nThe name has been changed");
    displayandchoosemenuforoption3(StudentMarks,Getnumofstudents,
                            studentNames, pin);
}
void emptytheBuffer(void)
{
        while(getchar() != '\n')
            {
                ;  
            }
}





