#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "animation.h"

int main() {
    srand(time(NULL));

    //printing empty list
    printf("list with nothing\n");
    struct animation *l=NULL;
    print_list(l);

    //filling and then printing list
    printf("filled list and then printed\n");
    int part_7_len = 11;
    char part[8] = "part ";
    char i;
    for(i = 9; i > 0; i--) {
        part[5] = i+'0';
        if(i == 7) {
            l = insert_front(l,part, part_7_len);
            continue;
        }
        l = insert_front(l,part,rand()%20+1);
    }
    print_list(l);

    //remove node 7
    printf("try to remove no existing node and then remove node seven then print\n");
    l = remove_node(l,"part 199", part_7_len);
    l = remove_node(l,"part 7", part_7_len);
    print_list(l);

    //free and then print nothing
    printf("free list and print nothing\n");
    l = free_list(l);
    //should be nothing
    print_list(l);
    return 0;
}
