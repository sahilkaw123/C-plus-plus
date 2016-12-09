#include <iostream>
#include <cmath>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <limits.h>
#include <array>


using namespace std;


//to define the maximum functionality
int max(int a, int b) 
{ 
return (a > b)? a : b; 
}
int max(int a, int b, int c) 
{
return max(max(a, b), c); 
}

 
//to find the crossing array if its sum is maximum
int maxMiddleSum(int array[], int l, int m, int h)
{
int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + array[i];



        if (sum > left_sum)
          left_sum = sum;

    }
 
// Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + array[i];


        if (sum > right_sum)
          right_sum = sum;

    }


// Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

int maxArraySum(int array[], int l, int h){


//dividing the array in two halves
if (l == h)
return array[l];
int m = (l+h)/2;

//method to return the maximum of the value from left array or right array or middle one.
return max (maxArraySum(array, l, m),maxArraySum(array, m+1, h),maxMiddleSum(array, l, m, h));   
}
//end of divide and conquer method.





//main program method. The program would start from here.
//passing the arguments to be read from the command line

int main(int argc,char *argv[])

{
//global variable decleration.
    string error_line;       //to concate the error inputs in the input file.       
    string d;                // input string stream.
    char name_file; //name of the input file passed as an argument through command line.
    ifstream inpfile; //reading the input file in a stream of data. 
    


unsigned dig = 0;
unsigned filelength = 1;  // setting the initial value of the input file count to be 1 .
unsigned error_count = 0; // setting the initial value of the error_count flag to be 0.

/*
parsing the command line arguments if the arguments are passed or not and if not then
throwing the error.
*/     
    if (argc!=1)
    {
    fstream inpfile;
    inpfile.open(argv[1],ios::in);     
//checking if the input file is open by the process else throwing an error to user.
                if (inpfile.is_open())
                {
char mychar;  //assigning the inputs as data type character.
inpfile>>mychar; //reading the first character of inpfile.
//
//checking the input file if it is empty. If empty then throw the error and exit from the program.
// 
if( inpfile.eof() ) {
cout<<endl;
cerr<<"The input file is empty. Enter the data into the input file and then run the program."<<endl;
cout<<endl;
exit(1);
}

//resetting the pointer to the beginning of the file.
inpfile.clear();
inpfile.seekg(0, ios::beg);

//reading till the end of the file.             

                        while (inpfile.good())
                        {
                         char mychar;
                         inpfile>>mychar;




//breaking the loop if the end of file reached.
                          if( inpfile.eof() ) {

break;
}

// detemining the length of the file and parsing the data of the file.
else{


     
                         if(isdigit(mychar) || mychar ==',' || mychar ==' ' || mychar =='-')
{


                            

if(isdigit(mychar) || mychar ==',' || mychar =='-')
 { 
d+=mychar;

if(mychar ==','){

                         filelength++;

}

if(isdigit(mychar)){
dig++;
}



}}

//incrementing the count if an invalid data is found.
else{
error_line=mychar;  
error_count++;


// validating the input data of the file and error handling and along with the position of the error.
if (error_line =="."){
cout<<endl;
cerr<<error_count<<"."<<" "<<"A decimal is inserted at position -" <<" "<<filelength<<" in the input-file. "<<endl; 

}
else
{
if ((error_line>="a" && error_line<="z") || (error_line>="A" && error_line<="Z")){
cout<<endl;
cerr<<error_count<<"."<<" "<<"An alphabet "<<"'"<<error_line<<"'"<<" is enterd at position -"<<" "<<filelength<<" in the input-file. "<<endl;

}
else
{
cout<<endl;
cerr<<error_count<<"."<<" "<<"Unsupported special character '"<<error_line<<"' enterd at position -" <<"  "<<filelength<<" in the input-file. "<<endl;

}}}
                       
                          


}}

// letting the user know the number of the errors and the action to be taken 


if (dig==0){
cout<<endl;
cout<<"Input file has no digit to process"<<endl;
cout<<"Please enter the digits in Input-file to process"<<endl;
cout<<endl;
cerr<<"Note: To track error in input file the position of input data" <<endl;
cerr<<"increases by 1 after ever comma in the record of input file "<<endl;
cout<<endl;
exit(1);
}
else{
if(error_count>0)
{
cout<<endl;
cerr<<"The Program would produce output ignoring above mentioned"<<" "<<error_count<<" "<<" errors in the input file"<<endl;
cout<<endl;
cerr<<"Note: To track error in input file the position of input data" <<endl;
cerr<<"increases by 1 after ever comma in the record of input file "<<endl;
cout<<endl;

}


//Seperating the digits from the String and putting them to array.
string array1[filelength];   //string array.
string arr[filelength];
int array[filelength];       //integer array.
int i12 =0;
int i1=0;
istringstream ss(d);           //reading the input stream data
string token1;
while(getline(ss, token1, ','))  //deliminating the input record 
{
if (token1==""){
i1++;
}
else{
array1[i12] = token1;
i12++;
}}




                        
//Converting the string array to integer array.
for (int t=0;t<=i12-1;t++){
array[t] = atoll(array1[t].c_str());

}

            
/*    
Brute force Cubic method to find the Maximum contigious sum and 
Running the loop twice as the clock time is to be taken for the second run. 
Taking the Maximum Sum(MaxSum_cont initial value to be -2147483648 as it is the lowest limit 
of the long int and the inputs can have negative values too.
*/                     
int o = 0;
int y1;
int MaxSum_cont = -2147483648 ;

while(o<2){                      //logic to run the loop twice.
clock_t startTime = clock();    //clock method - start of loop.

for(int k = 0;k<i12;k++)
{
for(int l = k; l < i12;l++)
{
int Sum = 0;
for(int m = k; m<=l; m++)
{
Sum += array[m];                    // summing the array possibility
if (Sum> MaxSum_cont)               // finding the max sum by comparing the values 
MaxSum_cont = Sum;                  // setting the value of the max sum
}}}
clock_t endTime = clock();
y1 = double( endTime- startTime ) / (double)CLOCKS_PER_SEC;  //clock - endtime of loop 
o++;
if (o==2)                                 // printing the values if the loop has run twice
{cout << "   "<<MaxSum_cont<<"     "<<y1 << " seconds." << endl;
}}
//end of brute force cubi method.


/*    
Divide and Conquer method to find the Maximum contigious sum and 
Running the loop twice as the clock time is to be taken for the second run. 
*/ 
int y2;
int q1=0;
int max_sum_cont=0;

while(q1<2){                     //logic to run the loop twice
clock_t startTime = clock();     //clock method - start of loop

int max_sum_cont = maxArraySum(array, 0, i12-1);   //calling the function
clock_t endTime = clock();       
y2 = (double( endTime - startTime ) / (double)CLOCKS_PER_SEC) ;  //clock - endtime of loop

q1++;
if(q1==2)                                // printing the values if the loop has run twice
{
cout << "   "<<max_sum_cont<<"     "<<y2 << " seconds." << endl;
}}

} //digit logic end.
//}               //closing the input file.
inpfile.close();
}
else
//throwing the error if file not found in the path or file name is correct.
                {
                        cerr << "File not found or the name passed is not correct"<<endl;
                }}
else {
//throwing thr error if the file name is not passed as an argument.
cerr<<"Please pass the name of the file or the path of the file location with the file name"<<endl;
}}

//end of program.
