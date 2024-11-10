//
//  main.c
//  hashes
//
//  Created by Thomas Dean on 2024-11-02.
//

#include <stdio.h>

#define NUMWORDS 40
char * words[NUMWORDS] = {
    "splitCommandLine", "commandBuffer", "nargs"
    "fgets", "stdin", "skipChar", "charPtr", "nextSpace",
    "cmd_path", "stat_buff", "doExternalCommand", "fork",
    "perror", "execv", "getcwd", "dirent", "strcmp", "exitFunc",
    "st_mode", "malloc", "maxargs", "skip", "doInternalCommand",
    "fopen", "fclose", "fprintf", "printf", "scandir", "strlen",
    "getpwuid","getuid","atoi","cmdData", "path",
    "argc", "argv", "main",
    "S_ISREG","free","childpid", "filter",
};

#define HASHSIZE 60
unsigned long hashTable[HASHSIZE];

void eraseHashTable(unsigned long ht[], unsigned long);

// hash functions
unsigned long sumHash(char * str, unsigned long sz);
unsigned long multHash(char * str, unsigned long sz);
unsigned long djb2(char *str, unsigned long sz);

// statistics
double clusterFactor(unsigned long ht[], unsigned long sz, unsigned long numElements);
int countEmpty(unsigned long ht[], unsigned long sz);

int main(int argc, const char * argv[]) {
    return 0;
}


void eraseHashTable(unsigned long ht[], unsigned long sz){
    
}

unsigned long sumHash(char * str, unsigned long sz){
    
    return 0;
}

unsigned long multHash(char * str, unsigned long sz){

    return 0;
}

unsigned long djb2(char *str, unsigned long sz) {
    
    return 0;
}

double clusterFactor(unsigned long ht[], unsigned long sz, unsigned long numElements){
    
    return 0.0;
}

int countEmpty(unsigned long ht[], unsigned long sz){
    
    return 0;
}
