#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


//Function Prototypes Declarations
void rizveeStartWork(void);
char* rizveeReadLine(void);
char **rizveeSplitLine(char * commandLine);
int rizveeCd(char ** commandLineSplit);
int rizveeEcho(char ** commandLineSplit);
int rizveeExit(char ** commandLineSplit);
int rizveeHelp(char ** commandLineSplit);
int rizveePwd(char **commandLineSpit);
int rizveeCreatingFork(char **commandLineSplit);
int checkingIOSigns(char **commandLineSplit); //checking IO redirection signs is present or not
int rizveeIOredirection(char **commandLineSplit); // simple IO redirection
int rizveePipeChecking(char **commandLineSplit); //checking if there is pipe in the istruction or not
int rizveePipeExecution(char **commandLineSplit); //Scheduling of pipe command
int rizveeCopyFromOneFileToOther(char whereToCopy[], char whomToCopy[]); //copy from one file to other
int rizveeShowWhatIsInFile(char thePlaceWhereIkeptData[]); // to show what is in the file
int checkingBackgroundWork(char **commandLineSplit); //checking if it's a back ground work or not
int rizveeCreatingZombie(char **commandLineSplit); // function to create zombie
//Global Variables

#define MAX_INPUT_STRING_LENGTH 1000
#define DELIM " "

FILE *myInputFile,*myOutputFile; //myInput File and output file pointer
char  myInputFileName[100], myOutputFileName[100]; // my input file name and output file name
char  tempInputFileName[100],tempOutputFileName[100]; //temp output file and output file name
int   whereOutputWillBe; // destintion file descriptor
int   tempOutputFileInt,tempOutputFileInt; //tempInput and output file descriptor
int   ioDirection; // io direction is on or not
int   writeAppend; //both write and append
int   w,r; // onle write and read only command
int   rizveePipeInstruction; //identifies if it's a pipe instruction or not
int   ioDirectionInPipe; //if there is IO redirection in  pipe
int   rizveeShowWhatIsInFile(char thePlaceWhereIkeptData[]); //Showing what is in the file
int   backGroundProcess;

char *function_names[] = {
   "cd" ,
   "exit",
   "help",
   "echo",
   "pwd",
   "cat >",
   "cat ",
   "cat >>",
    NULL
};

char *function_names_discription[] = {
  ": Change directory",
  ": exit from shell",
  ": to know about the functions of the shell",
  ": echo what are you writing",
  ": to konw the directory",
  ": write to a file",
  ": show what is in that file",
  ": append to a file",
  NULL

};

int (*functionPointers[])(char **) = {
 &rizveeCd,
 &rizveeExit,
 &rizveeHelp,
 &rizveeEcho,
 &rizveePwd,
 NULL
};




int main(int argC, char **argV)   // argument constants and argument variables giving in
{
    strcpy(myInputFileName,"myInputFile");
    strcpy(myOutputFileName,"myOutputFile");
    rizveeStartWork();
    return EXIT_SUCCESS; //Ending of My Shell Code
}


//declaration of Functions

void rizveeStartWork(void)
{
    char *commandLine; //given input command
    char **commandLineSplit; // spiliting the command
    int workStatus;

    do
    {
        printf("Rizvee@SHELL ^_^: "); //my Emoticon
        ioDirection=0; // default to console
        w=0;
        r=0;
        writeAppend=0;
        rizveePipeInstruction = 0; //Default instruction no pipe
        ioDirectionInPipe = 0; //Default no piping
        backGroundProcess = 0; //Default there is no bacakgroudnd Process
        commandLine=rizveeReadLine(); //Rizvee Reading Line
        commandLineSplit=rizveeSplitLine(commandLine);
        workStatus=rizveeExecution(commandLineSplit);
        free(commandLine);
        free(commandLineSplit);
    }
    while(workStatus);
}

//Reading Line

char * rizveeReadLine(void)
{
    int commandLineSize = MAX_INPUT_STRING_LENGTH;
    int index = 0;
    char *commandLine = malloc(sizeof(char)*commandLineSize); // space allocation
    int character;
    if (!commandLine)
    {
        fprintf(stderr,"Rizvee : error in taking command, space allocation problem\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        //Reading Input Character in Integer ;
        character = getchar();
        //EOF or NULL
        if(character == '\n' || character == EOF)
        {
            commandLine[index] = '\0';
            return commandLine;
        }
        //Precaution about string length;
        if(index>=commandLineSize)
        {
            commandLineSize += MAX_INPUT_STRING_LENGTH;
            commandLine=realloc(commandLine,commandLineSize); //Reallocating Space;
            if(!commandLine)
            {
                fprintf(stderr,"Rizvee : error in taking command, space allocation problem\n");
                exit(EXIT_FAILURE);
            }
        }
        // Making the character array
        commandLine[index] = character;
        index++;
    }

}

//Spliting the line
char ** rizveeSplitLine(char *commandLine)
{
    int commandLineSizeSplit = MAX_INPUT_STRING_LENGTH;
    int index = 0;
    char **commandLineSplit = malloc(sizeof(char*)*commandLineSizeSplit);
    if(!commandLineSplit)
    {
           fprintf(stderr,"Rizvee : Error in Splitting the commands\n");
           exit(EXIT_FAILURE);
    }
    char *temp;

    temp = strtok(commandLine,DELIM);
    while(temp != NULL)
    {
       commandLineSplit[index] = temp;

       if(index>=commandLineSizeSplit)
       {
         commandLineSizeSplit = commandLineSizeSplit + MAX_INPUT_STRING_LENGTH;
         commandLineSplit = realloc(commandLineSplit,commandLineSizeSplit);
         if(!commandLineSplit)
         {
           fprintf(stderr,"Rizvee : Error in Splitting the commands\n");
           exit(EXIT_FAILURE);
         }
       }
       index++;
       temp = strtok(NULL,DELIM);
    }
    commandLineSplit[index]=NULL;
    return commandLineSplit;

}

int rizveePwd(char **commandLineSplit) {
  char buf[1024];
  char *cwd;
  cwd = getcwd(buf,1025);
  if(cwd != NULL) {
    printf("%s\n",cwd);
  }
  return 1;
}

//Change Directory Command

int rizveeCd(char **commandLineSplit) {
  int v;
  if(commandLineSplit[1] == NULL) {
    v=chdir(getenv("HOME"));
  }
  else {
    v=chdir(commandLineSplit[1]);
  }
  if(v != 0) {//printf("v= %d\n",v);
   fprintf(stderr,"No Such directory. use ls  or ls-l\n");
  }
  return 1;
}

//ECHO Command

int rizveeEcho(char **commandLineSplit)
{

    int i;
    for(i=1; ;i++)
    {
      if(commandLineSplit[i]==NULL) break;
      else printf("%s ",commandLineSplit[i]);
      //fprintf(stdout," ");
    }
    printf("\n");
    return 1;
}

//EXIT Command
int rizveeExit(char **commandLineSplit)
{
  return 0;
}

//Counting the number of used functions

int countUsedFunctionsNumber()
{
  int i;
  for(i=0; ;i++)
  {
    if(function_names[i]== NULL) return i;
  }
}

//Help Command
int rizveeHelp(char **commandLineSplit)
{
   printf("The used commands in this shell:\n");
   for(int i=0; ;i++)
   {
     if(function_names[i]==NULL) break;
     else printf("%s %s\n",function_names[i],function_names_discription[i]);
   }
   return 1;
}

//Rizvee Creating Fork

int rizveeCreatingFork(char **commandLineSplit)
{
   pid_t pid,wPid;
   int presentStatus;
   pid=fork();
   if(pid==0)
   {
     int v;
     if(ioDirection==1) {
       if(writeAppend== 1) {
       tempOutputFileInt=open(tempOutputFileName,O_APPEND | O_WRONLY); //APPENDING
       }
       else if(r==1)  {
       tempOutputFileInt=open(tempOutputFileName,O_RDONLY); //JUST READING
       }
       else if(w==1) {
       remove(tempOutputFileName); //deleting the previous file
       FILE *file = fopen(tempOutputFileName,"w"); // creating a file named previous name
       fclose(file); //closing the file pointer
       tempOutputFileInt=open(tempOutputFileName,O_WRONLY); // just normal int file  open
       }
       if(tempOutputFileInt<0) {
        printf("No such file in the directory problem.\n");
       }
       else {
       dup2(tempOutputFileInt,1);
       v= execvp(commandLineSplit[0],commandLineSplit); // doing exec there
       close(tempOutputFileInt);
       }
     }
     else {
      v= execvp(commandLineSplit[0],commandLineSplit);
     }
     if(v==-1)
     {
       perror("Error in running into new environment");
     }
   }
   else if(pid<0)
   {
     perror("Error while forking");
   }
   else
   {
    do
    {
    wPid= waitpid(pid,&presentStatus,WUNTRACED);
    }while(!WIFEXITED(presentStatus) && !WIFSIGNALED(presentStatus));
   }
   return 1;
}


//Execution of shell

int rizveeExecution(char **commandLineSplit)
{
   if(commandLineSplit[0] == NULL) return 1;

   //The Pipe command is being checked

     rizveePipeInstruction = rizveePipeChecking(commandLineSplit);
     if(rizveePipeInstruction == 1) {
        return rizveePipeExecution(commandLineSplit); // calling to scheduling the pipe instructions
     }

   //The Without Pipe IO redirections works
   int ioSigns=0;
   ioSigns=checkingIOSigns(commandLineSplit);
   if(ioSigns==1) {
      return rizveeIOredirection(commandLineSplit);
   }

   int backGroundProcess = checkingBackgroundWork(commandLineSplit); // checking if it's a background process or not
   if(backGroundProcess == 1) {
     //printf("aseche");
     return backGroundSetUp(commandLineSplit);
   }

   for(int i=0;;i++)
   {
     if(function_names[i]==NULL) break;
     if(strcmp(function_names[i],commandLineSplit[0])==0)
     {
       return (*functionPointers[i])(commandLineSplit);
     }
   }
   return rizveeCreatingFork(commandLineSplit);
}


int rizveeIOredirection(char ** commandLineSplit) {


  char **tempCommandLineSplit,*tempCommandLine; //copy of the commandLineSplit
  whereOutputWillBe = 1; // default output will be standard out
  //tempCommandLineSplit = malloc(sizeof(char*)* 1024);
  int totalSize=1024;
  tempCommandLine=malloc(sizeof(char) * totalSize);
  int idx=0; // moving pointer
  for(int i=0; commandLineSplit[i] != NULL ; i++) {
    if(commandLineSplit[i][0] == '>' && commandLineSplit[i][1] == '>') {
         if(commandLineSplit[i+1] == NULL) {
           printf("File Not Found.\n");
           break;
           //return 1;
         }
         for(int j=0;j<i;j++) {
            if(idx+strlen(commandLineSplit[j])>= totalSize) {
              totalSize = totalSize + strlen(commandLineSplit[j]) + 1024;
               tempCommandLine = realloc(tempCommandLine,totalSize);
            }
            for(int k=0; k< strlen(commandLineSplit[j]); k++) {
               tempCommandLine[idx]=commandLineSplit[j][k];
               idx++;
            }
            if(j != (i-1)) {
                tempCommandLine[idx]=' ';
                idx++;
            }
         }
         idx++;
         tempCommandLine[idx]='\0'; // new command complit
         tempCommandLineSplit=rizveeSplitLine(tempCommandLine); // new command argument
         ioDirection=1; // the bit is done on
         writeAppend=1;
         strcpy(tempOutputFileName,commandLineSplit[i+1]);
         rizveeCreatingFork(tempCommandLineSplit);
         //free(tempCommandLine); /****Important space free*/
         //free(tempCommandLineSplit); /****Important space free*/
         ioDirection = 0;
         w = 0;
         r = 0;
         writeAppend=0;
         //return 1;
    }
     else if(commandLineSplit[i][0] == '>') {
       if(commandLineSplit[i+1] == NULL) {
           printf("File Not Found.\n");
           break;
           //return 1;
         }
         for(int j=0;j<i;j++) {
            if(idx+strlen(commandLineSplit[j])>= totalSize) {
              totalSize = totalSize + strlen(commandLineSplit[j]) + 1024;
              tempCommandLine = realloc(tempCommandLine,totalSize);
            }
            for(int k=0; k< strlen(commandLineSplit[j]); k++) {
               tempCommandLine[idx]=commandLineSplit[j][k];
               idx++;
            }
            if(j != (i-1)) {
                tempCommandLine[idx]=' ';
                idx++;
            }
         }
         idx++;
         tempCommandLine[idx]='\0'; // new command complit
         tempCommandLineSplit=rizveeSplitLine(tempCommandLine); // new command argument
         ioDirection=1; // the bit is done on
         writeAppend=0;
         w=1;
         r=0;
         strcpy(tempOutputFileName,commandLineSplit[i+1]);
         rizveeCreatingFork(tempCommandLineSplit);
         //free(tempCommandLine); /****Important space free*/
         //free(tempCommandLineSplit); /****Important space free*/
         ioDirection = 0;
         w = 0;
         r = 0;
         writeAppend=0;
         //return 1;

     }
     else if(commandLineSplit[i][0] == '<') { // cat  file1 << file2   or cat file1 < file2  or cat < file1
          if(commandLineSplit[i+1] == NULL) {  // cat file1 <
            fprintf(stderr,"Expected argument missing Error.\n");
            break;
            //return 1;
           }
           //situation 1 cat file1 << file2
          else if(commandLineSplit[i][1] != NULL && commandLineSplit[i][1] == '<') {
             for(int j = 0; j<i-1; j++) {  //inst -ls  filename << file 2
                if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                    if(j != (i-2)) {
                      tempCommandLine[idx] = ' ';
                      idx++;
                    }
                }
             }
             //adding the input file name
             for(int j=i+1;commandLineSplit[j] != NULL; j++) {
                  tempCommandLine[idx] = ' ';
                  idx++;
                  if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                }
             }
             idx++;
             tempCommandLine[idx]='\0';
             tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
             //instruction is completely made
             strcpy(tempOutputFileName,commandLineSplit[i-1]); //cat final << final2
             ioDirection=1; // the bit is done on
             writeAppend=1;
             rizveeCreatingFork(tempCommandLineSplit);
             //free(tempCommandLine); /****Important space free*/
             //free(tempCommandLineSplit); /****Important space free*/
             ioDirection = 0;
             w = 0;
             r = 0;
             writeAppend=0;
             //return 1;
          }
          else if(commandLineSplit[i][0] == '<') {  //Now I will check these two cat < final1  or cat final2 << final1
              int specialCase = 0; // special case 1 is cat < file2
                                   // special case 2 is cat file < file2
              if((i-1) == 0) {
                specialCase = 1 ;  //cat < file1
              }
              else if((i-1) != 0 && commandLineSplit[i-1][0] == '-') {
                specialCase = 1; //ls -l  < file1
              }
              else {
                specialCase = 2;  // cat file1 < file2
              }
              if(specialCase == 1) { // cat < file1
                 for(int j=0; j<=i-1; j++) { //console is my desired output place
                  if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    break;
                    //return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                    if(j != (i-1)) {
                      tempCommandLine[idx] = ' ';
                      idx++;
                    }
                }
                }
              //adding the input file name
             for(int j=i+1;commandLineSplit[j] != NULL; j++) { // to the end
                  tempCommandLine[idx] = ' ';
                  idx++;
                  if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                }
             }
             idx++;
             tempCommandLine[idx]='\0';
             tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
             //as my output is actually on the screen so my destination folder is my built in folder
             strcpy(tempOutputFileName,myOutputFileName); // done here
             ioDirection = 1;
             w = 1;
             r = 0;
             writeAppend = 0;
             rizveeCreatingFork(tempCommandLineSplit);
             //free(tempCommandLine); /****Important space free*/
             //free(tempCommandLineSplit); /****Important space free*/
             ioDirection = 0;
             w = 0;
             r = 0;
             writeAppend = 0;
             if(rizveePipeInstruction == 0) {
               rizveeShowWhatIsInFile(tempOutputFileName);
             }
             //return 1; //Shutting down this
             }
             else {
               //Checking the special case
                for(int j = 0; j<i-1; j++) {  //inst -ls  filename << file 2
                if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    break;
                    return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                    if(j != (i-2)) {
                      tempCommandLine[idx] = ' ';
                      idx++;
                    }
                }
             }
             //adding the input file name
             for(int j=i+1;commandLineSplit[j] != NULL; j++) {
                  tempCommandLine[idx] = ' ';
                  idx++;
                  if(idx+strlen(commandLineSplit[j]) <= totalSize) {
                  totalSize = totalSize + 1024 + strlen(commandLineSplit[j]);
                  tempCommandLine = realloc(tempCommandLine,totalSize); //space allocating
                  int check = 1;
                  if(check == 0) {
                    fprintf(stderr,"Exception in allocating space.\n");
                    return 1;
                  }
                  for(int k = 0; k < strlen(commandLineSplit[j]); k++) {
                    tempCommandLine[idx] = commandLineSplit[j][k]; //just making the string
                    idx++;
                  }
                }
             }
             idx++;
             tempCommandLine[idx]='\0';
             tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
             //instruction is completely made
             strcpy(tempOutputFileName,commandLineSplit[i-1]); //cat final << final2
             /*free(tempCommandLine); /****Important space free*/
             //free(tempCommandLineSplit); /****Important space free*/
             ioDirection = 1;
             w = 1;
             r = 0;
             writeAppend = 0;
             rizveeCreatingFork(tempCommandLineSplit);
             ioDirection = 0;
             w = 0;
             r = 0;
             writeAppend = 0;
             //return 1;
             }

          }

     }

  }
  free(tempCommandLineSplit);
  free(tempCommandLine);
  return 1;
}

//Scheduling of Pipe WORKS

int rizveePipeExecution(char **commandLineSplit) {


  int prevInstFin=0; //where previous instruction was finished

  char *tempCommandLine;
  char **tempCommandLineSplit;
  int  totalSize = 1024;
  // allocating the size
   int countingPipes = 0; // counting how many pipes
   int saveLast = 0; // the last of i
  for(int i=0;commandLineSplit[i]!= NULL;i++) { //itterating through the commands first_instruction | second_instruction | ......
    ioDirectionInPipe = 0; //io direction in pipe
    saveLast = i;
    int counter;
    if(commandLineSplit[i][0] == '|') {
        int idx=0;  // moving pointer;
        free(tempCommandLine);
        countingPipes++;
        counter = i-prevInstFin;
        tempCommandLine = malloc(sizeof(char) * totalSize); //allocating the space
        for(int j=prevInstFin;j<i;j++) {
            if(idx+totalSize <= strlen(commandLineSplit[j])) {
              totalSize = totalSize + 1024 + strlen(commandLineSplit[j]); // measuring new size
              tempCommandLine = realloc(tempCommandLine,totalSize); // reallocatig space
             }
            for(int k=0;k<strlen(commandLineSplit[j]); k++) { // Putting into
                tempCommandLine[idx] = commandLineSplit[j][k];
                idx++;
            }
            if(j != (i-1)) {
              tempCommandLine[idx] = ' ';
              idx++;
            }

        }
        prevInstFin=i+1;
        tempCommandLine[idx]='\0'; //ending of the merge string
        tempCommandLineSplit = rizveeSplitLine(tempCommandLine); // parsing the main command string into splited strings
        ioDirectionInPipe = checkingIOSigns(tempCommandLineSplit); // checking if the broken command has any > or >> directions
        if(ioDirectionInPipe == 1) {
            int v = rizveeIOredirection(tempCommandLineSplit);
            rizveeCopyFromOneFileToOther(myInputFileName,myOutputFileName); // copying from my output file to my input file

        }
        else {
            if(countingPipes==1) {
              ioDirection = 1;
              strcpy(tempOutputFileName,myOutputFileName);
              writeAppend = 0;
              w = 1;
              r = 0;
              rizveeCreatingFork(tempCommandLineSplit);
              ioDirection = 0;
              w = 0;
              r = 0;
              writeAppend = 0;
              rizveeCopyFromOneFileToOther(myInputFileName,myOutputFileName);
            }
            else {
              //free(tempCommandLine);
              tempCommandLine = malloc(sizeof(char) * totalSize);
              idx = 0;
              for(int j = 0; tempCommandLineSplit[j] != NULL; j++) {
                 if(idx+totalSize<=strlen(tempCommandLineSplit[j])) {
                   totalSize = totalSize + 1024 + strlen(tempCommandLineSplit[j]);
                   tempCommandLine = realloc(tempCommandLine,totalSize);
                 }
                 for(int k = 0; k< strlen(tempCommandLineSplit[j]); k++) {
                  tempCommandLine[idx] = tempCommandLineSplit[j][k];
                  idx++;
                 }
                 tempCommandLine[idx]=' ';
                 idx++;
              }
              if(idx+strlen(myInputFileName)<=totalSize) {
                 totalSize = totalSize + 1024 + strlen(myInputFileName);
                 tempCommandLine=realloc(tempCommandLine,totalSize);
              }
              for(int j=0;j<strlen(myInputFileName); j++) {
                 tempCommandLine[idx]=myInputFileName[j];
                 idx++;
               }
               tempCommandLine[idx] = '\0';
               tempCommandLineSplit=rizveeSplitLine(tempCommandLine);
               ioDirection = 1;
               w = 1;
               r = 0;
               writeAppend = 0;
               strcpy(tempOutputFileName,myOutputFileName);
               rizveeCreatingFork(tempCommandLineSplit);
               rizveeCopyFromOneFileToOther(myInputFileName,myOutputFileName);
            }
        }

        }
    }
    int idx=0;
    //free(tempCommandLine);
    tempCommandLine=malloc(sizeof(char) * totalSize); // allocating space
    for(int i=prevInstFin; i<= saveLast; i++) {

       if(idx+totalSize<=strlen(commandLineSplit[i])) {
         totalSize = totalSize + 1024 + strlen(commandLineSplit[i]);
         tempCommandLine = realloc(tempCommandLine,totalSize);
       }
       for(int k=0;k<strlen(commandLineSplit[i]); k++) {
           tempCommandLine[idx]=commandLineSplit[i][k];
           idx++;
       }
       if(i != saveLast) {
        tempCommandLine[idx]=' ';
        idx++;
       }

    }
     tempCommandLine[idx]='\0';
     tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
     ioDirectionInPipe = checkingIOSigns(tempCommandLineSplit); // checking if the broken command has any > or >> directions
     if(ioDirectionInPipe == 1) {

     //free(tempCommandLine);
     idx = 0;
     tempCommandLine = malloc(sizeof(char) * totalSize);
     int save=0;
     for(int i=0;tempCommandLineSplit[i] != NULL; i++) {
       if(tempCommandLineSplit[i][0] =='>') {
         save=i;
         break;
       }
       else {
         if(idx+totalSize <= strlen(tempCommandLineSplit[i])) {
           totalSize = totalSize + 1024 + strlen(tempCommandLineSplit[i]);
           tempCommandLine = realloc(tempCommandLine,totalSize);
         }
         for(int k = 0; k<strlen(tempCommandLineSplit[i]); k++) {
            tempCommandLine[idx] = tempCommandLineSplit[i][k];
            idx++;
         }
         tempCommandLine[idx] = ' ';
         idx++;
       }
     }
     if(idx+strlen(myInputFileName) <= totalSize) {
      totalSize = totalSize + 1024 + strlen(myInputFileName);
      tempCommandLine = realloc(tempCommandLine,totalSize);
     }
     for(int j = 0; j< strlen(myInputFileName) ; j++) {
       tempCommandLine[idx] = myInputFileName[j];
       idx++;
     }
     for(int i = save; tempCommandLineSplit[i]; i++) {
        tempCommandLine[idx] = ' ';
        idx++;
        if(idx+strlen(tempCommandLineSplit[i]) <= totalSize){
           totalSize = totalSize + 1024 + strlen(tempCommandLineSplit[i]);
           tempCommandLine = realloc(tempCommandLine,totalSize);
        }
        int s=0;
        for(int k = 0; k<strlen(tempCommandLineSplit[i]); k++) {
           tempCommandLine[idx] = tempCommandLineSplit[i][k];
           idx++;
           tempOutputFileName[k] = tempCommandLineSplit[i][k];
           s = k;
        }
     }
        tempCommandLine[idx] = '\0';
        tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
        int v = rizveeIOredirection(tempCommandLineSplit);
     }
     else {
              //free(tempCommandLine);
              tempCommandLine = malloc(sizeof(char) * totalSize);
              char *anotherspecialcase;
              anotherspecialcase = malloc(sizeof(char) * totalSize);
              idx = 0;
              for(int j = 0; tempCommandLineSplit[j] != NULL; j++) {
                 if(idx+totalSize<=strlen(tempCommandLineSplit[j])) {
                   totalSize = totalSize + 1024 + strlen(tempCommandLineSplit[j]);
                   tempCommandLine = realloc(tempCommandLine,totalSize);
                   anotherspecialcase = realloc(anotherspecialcase,totalSize);
                 }
                 for(int k = 0; k< strlen(tempCommandLineSplit[j]); k++) {
                  tempCommandLine[idx] = tempCommandLineSplit[j][k];
                  anotherspecialcase[idx] = tempCommandLineSplit[j][k];
                  idx++;
                 }
                 tempCommandLine[idx]=' ';
                 anotherspecialcase[idx] = ' ';
                 idx++;
              }
              if(idx+totalSize<=strlen(myInputFileName)) {
                 totalSize = totalSize + 1024 + strlen(myInputFileName);
                 tempCommandLine = realloc(tempCommandLine,totalSize);
                 anotherspecialcase=realloc(anotherspecialcase,totalSize);
              }
              anotherspecialcase[idx] = '\0';
              for(int j=0;j<strlen(myInputFileName); j++) {
                 tempCommandLine[idx]=myInputFileName[j];
                 idx++;
               }
               tempCommandLine[idx] = '\0';
              // printf("%s\n",tempCommandLine);
               tempCommandLineSplit=rizveeSplitLine(tempCommandLine);
               ioDirection = 1;
               w = 1;
               r = 0;
               writeAppend = 0;
               strcpy(tempOutputFileName,myOutputFileName);
               rizveeCreatingFork(tempCommandLineSplit);
               ioDirection = 0;
               w = 0;
               r = 0;
               rizveeShowWhatIsInFile(myOutputFileName);
     }

  return 1; //work done
}

int checkingIOSigns(char ** commandLineSplit) { //checking IO redirection sign is present or not

   for(int i=0; commandLineSplit[i] != NULL ;i++) {
       if(commandLineSplit[i][0] == '>') return 1; // > this >> signs
       if(commandLineSplit[i][0] == '<') return 1; // <  or << this signs
   }
   return 0;
}

int rizveecopyFromOtherFilesToMyInputFile(char *otherFileName,char type) { //Copying to myInputFile
   myInputFile = fopen(otherFileName,type); //opening myInputFile
   FILE *f = fopen(otherFileName,"r");
   if(f==NULL) {
    printf("Input file %s is not present.\n",otherFileName);
    return 1;
   }
   int c;
   while(1) {
     c=fgetc(f);
     if(c==EOF) break;
     fprintf(myInputFile,"%c",c);
   }
   fclose(myInputFile);
   fclose(f);
   return 1;
}

int rizveePipeChecking(char **commandLineSplit) {

  for(int i=0; commandLineSplit[i] != NULL; i++) {
   if(commandLineSplit[i][0] == '|') return 1;
  }
 return 0;
}
int rizveeShowWhatIsInFile(char thePlaceWhereIkeptData[]) {

  FILE *file = fopen(thePlaceWhereIkeptData,"r");

  if(file == NULL) {
    printf("No such file in the directory"); // File not ound error
    return 1;
  }
  while(1) {
    int c;
    c = fgetc(file); //Taking the characters
    if(c==EOF) {
      return 1;
    }
    printf("%c",c);

  }
}

int rizveeCopyFromOneFileToOther(char whereToCopy[], char whomToCopy[]) {
  remove(whereToCopy);
  FILE *file = fopen(whereToCopy,"w"); // myInputFile
  if(file==NULL) {
   printf("File not found in the directory.\n");
   return 1;
  }
  FILE *file1  = fopen(whomToCopy,"r"); //myOutputFile
  if(file1 == NULL) {
    printf("File not found in the directory.\n");
    return 1;
  }
  int c;
  while(1) {
   c = fgetc(file1);
   if(c==EOF) break;
   fprintf(file,"%c",c);
  }
  fclose(file);
  fclose(file1);
  return 1;
}

int checkingBackgroundWork(char **commandLineSplit) {
   for(int i=0;commandLineSplit[i] != NULL; i++) {
     if(commandLineSplit[i][0] == '&') return 1;
   }
   return 0;
}
int backGroundSetUp(char **commandLineSplit) {
   char *tempCommandLine;
   char **tempCommandLineSplit;
   int idx=0,totalSize=0;
   tempCommandLine = malloc(sizeof(char) * totalSize);
   for(int i=0; commandLineSplit[i] != NULL; i++) {
      if(idx+strlen(commandLineSplit[i])>= totalSize) {
        totalSize = totalSize + 1024 + strlen(commandLineSplit[i]);
        tempCommandLine = realloc(tempCommandLine,totalSize);
        }
        for(int k = 0; k<strlen(commandLineSplit[i]); k++) {
            tempCommandLine[idx] = commandLineSplit[i][k];
            idx++;
        }
        if(commandLineSplit[i+1][0] != '&') {
           tempCommandLine[idx] = ' ';
           idx++;
        }
        if(commandLineSplit[i+1][0] == '&') {
          tempCommandLine[idx] = '\0';
          break;
        }


  }
  tempCommandLineSplit = rizveeSplitLine(tempCommandLine);
  rizveeCreatingZombie(tempCommandLineSplit);

  return 1;
}

int rizveeCreatingZombie(char **commandLineSplit) {

  int pid;
  pid = fork(); //forking my process

  if(pid == 0) {
      //Now child will create the zombie
     // if(temp == 0) {
      int v=execvp(commandLineSplit[0],commandLineSplit);
  }
  else if(pid>0) {
      //parent just forget his child and frees it
      //don't wait for it to finish
      printf("A Background program is running. Can check it with ps.\n");
      return 1;
  }
  else {
     fprintf(stderr,"There was error while creating background prcess.\n");
  }
  return 1;
}
