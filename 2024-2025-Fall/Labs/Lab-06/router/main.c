//
//  main.c
//  networkRouter
//
//  Created by Thomas Dean on 2024-11-01.
//

#include <stdio.h>

typedef struct {
    int src;
    int dst;
    int priority;
    char * data;
} Packet;

typedef enum {
    insertPacket, getPacket, endOfCommands
} CommandName;

typedef struct {
    CommandName comm;
    Packet packet;
} Command;

#define BUFFERSIZE 100
typedef struct {
    // add the appropriate fields
    // for a heap of packets
} Router;

Router theRouter;

void initRouter(Router * r);
int addPacket(Router * r, Packet p);
int getNextPacket(Router * r, Packet *p);
void heapify(Router * r, int parent);

Command input[] = {
    {insertPacket, {10,20,3,"packet1"}},
    {insertPacket, {20,30,4,"packet2"}},
    {insertPacket, {20,35,7,"packet3"}},
    {insertPacket, {20,30,4,"packet2"}},
    {insertPacket, {20,35,7,"packet4"}},
    {insertPacket, {12,20,1,"packet1"}},
    {insertPacket, {20,35,7,"packet5"}},
    {getPacket},
    {getPacket},
    {getPacket},
    {endOfCommands},
};

void printPacket(Packet p);

int main(int argc, const char * argv[]) {

    initRouter(&theRouter);
    
    int i = 0;
    while (input[i].comm != endOfCommands){
        // implement the insertPacket and getPacket commands
        // provide appropriate output to show the packets are retrieved in the correct
        // order
        i++;
    }
    return 0;
}


void printPacket(Packet p){
    printf("Priority = %d, ", p.priority);
    printf("src = %d, dst = %d, ", p.src, p.dst);
    printf("data = %s",p.data);
    printf("\n");
}


void initRouter(Router * r){
}

void insertFixer(Router * r, int child)
{
}

int addPacket(Router * r, Packet p){
    return 0;
}

int getNextPacket(Router * r, Packet *p){
    return 0;
}

void heapify(Router * r, int parent){
}
