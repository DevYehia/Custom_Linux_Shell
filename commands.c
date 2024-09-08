#include "commands.h"

void echo(char *text)
{
    while (*text != '\n')
    {
        write(STDOUT, text, 1);
        text++;
    }

    write(STDOUT, "\n", 1); // write a newline
}

void print_working_directory(char *env_vars[])
{
    char *currDir = myGetEnv(env_vars, "PWD");
    while (*currDir != '\0')
    {
        write(STDOUT, currDir, 1);
        currDir++;
    }

    write(STDOUT, "\n", 1);
}

void print_current_user(char *env_vars[])
{
    char *currUser = myGetEnv(env_vars, "USER");
    myPrintfBlank(currUser);
}

void meow(char *file_path)
{
    int fd = open(file_path, O_RDONLY);

    if (fd < 0)
    {
        myPrintfRed("File Not Found.");
        return;
    }
    char c;
    int bytes_read = read(fd, &c, 1);

    while (bytes_read != 0)
    {
        write(STDOUT, &c, 1);
        bytes_read = read(fd, &c, 1);
    }
}

int create_files(char *file_paths)
{

    // handle multiple files

        // Create files
    int fd = open(file_paths, O_WRONLY | O_CREAT,  00750);
    //chmod(file_paths, 00750);

    close(fd);
}

void list(char* dir_path){

    //save directory path in buffer to append it to directory items
    char static_dir_path[1024];
    int i;
    for(i = 0 ; dir_path[i] != '\0'; i++){
        static_dir_path[i] = dir_path[i];
    }

    //end path name with /
    if(static_dir_path[i-1] != '/'){
        static_dir_path[i] = '/';
        i++;
    }
    int static_dir_path_end = i;

    DIR* dirInfo = opendir(dir_path);
    struct dirent *currDirItemPtr = readdir(dirInfo);
    while(currDirItemPtr != 0){
        //get item type
        struct stat dirItemInfo;

        //append item name to path
        int j,k;
        for(j = static_dir_path_end, k = 0 ; currDirItemPtr->d_name[k] != '\0' ; j++, k++){
            static_dir_path[j] = currDirItemPtr->d_name[k];
        }
        static_dir_path[j] = '\0';


        //get file type
        stat(static_dir_path, &dirItemInfo);

        
        //st_mode anded with the file type mask gets file type
        switch(dirItemInfo.st_mode & S_IFMT){

            //regular file
            case S_IFREG:
                myPrintfBlank(currDirItemPtr->d_name);
                break;
            
            //directory
            case S_IFDIR:
                myPrintfMagenta(currDirItemPtr->d_name);
                break;

        }
        write(STDOUT, "   ", 3);
        currDirItemPtr = readdir(dirInfo);
    }

}