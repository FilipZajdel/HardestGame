#include <stdio.h>
#include "../components/game.h"

int main(int argc, char*argv[]){
    
    dummy();
    for(int i=0; i<argc; i++){
        printf("[%d] %s\n", i ,argv[i]);
    }

    return 0;
}