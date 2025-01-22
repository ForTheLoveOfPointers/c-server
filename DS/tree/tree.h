#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct DirInfo
{
    char* route;
    char* file;
} DirInfo;


typedef struct RouterTree {
   DirInfo dirs;
   RouterTree** children; 
} RouterTree;

RouterTree** tree_depth_first(RouterTree* tree, DirInfo info);
void tree_insert(RouterTree* tree, DirInfo info);
RouterTree read_routes(char* base_dir);

#endif