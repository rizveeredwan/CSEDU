//Header Files 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

void* findMetaData(char *argv){
   /*functions to find the metadata of a file
    int stat (const char *path, struct stat *buf);
   int fstat (int fd, struct stat *buf);
   int lstat (const char *path, struct stat *buf);
   returns 0
   
   code:
    finding metadata
    struct stat buf;
    stat(argv[1],&buf);
 
   the informations:
   struct stat {
dev_t st_dev; //id of device
ino_t st_ino; //inode number
mode_t st_mode; //permissions
nlink_t st_nlink; //num of hard links
uid_t st_uid; //user id
gid_t st_gid; //group id
dev_t st_rdev;//device num of special files
off_t st_size; //total size in bytes
blksize_t st_blksize;//block size file system IO
blkcnt_t st_blocks; // num of blocks allocated
time_t st_atime; //last access time
time_t st_mtime; //last modification time
time_t st_ctime; //last change time
};
*/ 
}
void permissions(){
   /*
   this functions change permission
   int chmod (const char *path, mode_t mode);
   int fchmod (int fd, mode_t mode);
   return 0 
   */
   /*
     code:
     int v = chmod(path,777);
   */
}
void ownership(){
   /*
    this function change the ownership
   int chown (const char *path, uid_t owner, gid_t group);
int lchown (const char *path, uid_t owner, gid_t group);
int fchown (int fd, uid_t owner, gid_t group);
   */
   /*
     code:
     int v = chown(path,user_id,group_id);
   */
}
void currentWorkingDirectory(){
   /*
      this function change directory
      1.char * getcwd (char *buf, size_t size);
      information is saved into buf
      size_t size buf
      2. char * get_current_dir_name (void);
   */
   /*
     code1:
     char buffer[1025];
     getcwd(argv[1],sizeof(buffer));
     printf("%s\n",buffer);
     code2:
     char *buffer;
     buffer = getcwd(NULL,0);
     printf("%s\n",buffer);
     free(cwd); 
     code3:
     char *cwd;
     cwd = get_current_dir_name();
     printf("%s\n",cwd);     
*/
}

void changingDirectory(){
   /*
     this functions chagne directory
     int chdir (const char *path);
     int fchdir (int fd);
   */
   /*
     code:
     int v = chdir(argv[1]);
     return 0 if ok 
      else -1
   
*/
}
void creatingDirectories(){
    /*
      this function creates directories
      int mkdir (const char *path, mode_t mode); 
      return 0 if ok 
      else -1
    */
    /*
        int v = mkdir(argv[1],01777); 
    */
}
void removingDirectories(){
    /*
      this function removes an empty directory
      int rmdir (const char *path);
      return 0 if ok
      else -1 
    */ 
}
void openDirectory(){
   /*
    this function opens a directory
    DIR * opendir (const char *name);
   */
   /*
      code:
      DIR *dir;
      dir = opendir(argv[1]);
   */
}
int directoryFileDescriptor(){
   /*
     This function returns a successful file descriptor 
     int dirfd (DIR *dir);
   */
   /*
    code:
    DIR *dir;
    dir = opendir(argv[1]);
    if(dir != NULL) {
      int v = dirfd(dir);
      printf("%d\n",v);
    }
  */
}
void readingFromDirectory(){
   /*
     This function reads from a directory 
     struct dirent * readdir (DIR *dir);
     struct dirent {
     ino_t d_ino; /* inode number */
     //off_t d_off; /* offset to the next dirent */ 
     //unsigned short d_reclen; /* length of this record */
    //unsigned char d_type; /* type of file */
    //char d_name[256]; /* filename */ }
}    
int closingDirectory(){
   /*
    This function closes a directory
    closedir(DIR *dir); 
   */
   /*
    DIR *dir;
    dir = opendir(argv[1]);
    if(dir != NULL) {
      printf("YES\n");
      closedir(dir);
    }
  */
}
int hardLinks(){
  /*
   This function creates hard links 
   int link (const char *oldpath, const char *newpath);
   if ok return 0
   else return -1
   */
   /*
      int v = link(argv[1],argv[2]); for files 
   */
}

int symboliclink(){
   /*
     int symlink (const char *oldpath, const char *newpath);
     for files 
    */
}
int unlinking(){
  /*
     int unlink (const char *pathname);
     for file 
   */
}
int _remove(){
  /*
   this function removes 
   int remove (const char *path);
A successful call to remove() deletes path from the filesystem and returns 0 . If path is
a file, remove() invokes unlink() ; if path is a directory, remove() calls rmdir() .
   */
}
int copy(){
  /*
  must be implemented
  */
}
int moving(){
  /*this function moves directories
   int rename (const char *oldpath, const char *newpath);
  */
}
int main(int argc, char **argv) {
     int v = link(argv[1],argv[2]);
     printf("%d\n",v);
}
