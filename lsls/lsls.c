// // #include <stdio.h>
// // #include <dirent.h>

// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <dirent.h>
// #include <unistd.h>
// #include <stdlib.h>

// /**
//  * Main
//  */
// int main(int argc, char **argv)
// {
//   // Parse command line
//   // struct dirent *de;

//   // int path = argc;
//   // if (argv != NULL) {
//   //   path = argc + argv;
//   // } 

//   if(2 != argc) {
//     printf("directory name missing.\n");
//     return 0;
//   }

//   DIR *dp = NULL;
//   struct dirent *dptr = NULL;
//   FILE *input_file;
//   // FILE *next_file;
//   char c,cwd[256]; // create new char array;

//   if (NULL == (dp = opendir(argv[1]))) {
//     printf("Cant open the given directory %s", argv[1]);
//     exit(1);
//   }
//   else {
//     while ((dptr = readdir(dp)) != NULL) {
//       if(!strcmp (dptr->d_name, "."))
//         {
//             continue;
//         }
//         if(!strcmp (dptr->d_name, ".."))
//         {
//             continue;
//         }
//     if(getcwd(cwd, sizeof(cwd)) == NULL) //this is important
//     {
//         printf("No such file or directory");
//         continue;
//     }
//     if(dptr->d_name[0]=='.')  //Files never begin with '.' 
//         continue;
//     strcat(cwd,"/");   //For windows "\"
//     strcat(cwd,argv[1]);
//     strcat(cwd,"/");   //For windows "\"
//     strcat(cwd,dptr->d_name);
//     printf("%s",cwd);  //check for working directory
//         input_file = fopen(cwd, "r");
//     printf("%s\n",dptr->d_name); //validation check
//         if(input_file == NULL)
//         {
//             perror("Cannot open file or no file exists\n");
//             fclose(input_file);
//             return 0;
//         }
//         c = fgetc(input_file);
//         while(c != EOF)
//         {
//             printf("%d", c);
//         }
//         printf("%s\n", dptr->d_name);
//     }
//     closedir(dp);
// }
// return 0;
// }
// //     }
// //   }

// //   // Open directory
// //   DIR *dr = *opendir();

// //   // Repeatly read and print entries
// //   if (dr == NULL) {
// //     printf("Could not open directory");
// //     exit(1);
// //   }

// //   while ((de = readdir(dr)) != NULL) {
// //     printf("%s\n", de->d_name);
// //   }

// //   // Close directory
// //   closedir(dr);

// //   return 0;
// // }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main (int argc, char *argv[])
{
    if(2 != argc)
    {
        argv[1] = ".";
    }

    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    struct stat buf;
    // Buffer for storing the directory path
    char buff[128];
    memset(buff,0,sizeof(buff));

    //copy the path set by the user
    strcpy(buff,argv[1]);

    // Open the directory stream
    if(NULL == (dp = opendir(argv[1])) )
    {
        printf("\n Cannot open Input directory [%s]\n",argv[1]);
        exit(1);
    }
    else
    {
       
        printf("\n The contents of directory [%s] are as follows: \n",argv[1]);

        while(NULL != (dptr = readdir(dp)) )
        {
            char *path = malloc(strlen(argv[1]) + strlen(dptr->d_name)+1);
            strcat(path, argv[1]);
            strcat(path, "/");
            strcat(path, dptr->d_name);
            stat(path, &buf);
            printf(" [%s], %lld  ",dptr->d_name, buf.st_size);
        }
        // Close the directory stream
        closedir(dp);
        // Remove the new directory created by us
        rmdir(buff);
        printf("\n");
    }

    return 0;
}