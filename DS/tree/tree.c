#include "tree.h"

RouterTree** tree_depth_first(RouterTree* tree, DirInfo info, DirInfo target) {

}

void tree_insert(RouterTree* tree, DirInfo info, DirInfo target) {
    RouterTree** children = tree_depth_first(tree, info, target);
}

RouterTree read_routes(char* base_dir) {
    char* routes = sprintf("%s/router.yml", base_dir);
    FILE* f = fopen(routes, 'r');
    RouterTree tree;
    DirInfo info;
    char line[500] = {0};
    char last_super_route[500] = {0};
    int depth = 2;
    while( fgets(line, 500, f) != NULL ) {
        int new_depth = 0;
        bool is_file = false;
        /* Detect if the line is a subroute or not */
        for(int i = 0; i < 500; i++) {
            if(line[i] != ' ' && line[i+1] == '/') {
                new_depth %= 2;
                memcpy(last_super_route, line, 500);
                break;
            } else if(line[i] != ' ') {
                is_file = true;
                break;
            } else {
                new_depth++;
            }
        }
        /* TODO: Trim lines */
        if(is_file) {
            info.file = line;
        } else {
            info.route = last_super_route;
        }
        if(info.file == NULL || info.route == NULL) {
            continue;
        }
        /*Insert info into tree*/
        
    }

    return tree;
}