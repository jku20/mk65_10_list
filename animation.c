#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "animation.h"

void print_animation(struct animation *an) {
    printf("%s: %df\n",an->name,an->length);
}

void print_list(struct animation *an) {
    while(an) {
        print_animation(an);
        an=an->next;
    }
}

struct animation *insert_front(struct animation *lst, char* nm, int l) {
    struct animation *na = new_animation(nm,l);
    na->next = lst;

    return na;
}

struct animation *remove_node(struct animation *lst, char* nm, int l) {
    struct animation *cur = lst;
    struct animation *last = NULL;
    while(cur) {
        if(!strcmp(cur->name,nm) && cur->length == l) {
            if(!last) {
                last = cur->next;
                free(cur);
                return last;
            } else if(!(cur->next)) {
                free(cur);
                return lst;
            } else {
                last->next = cur->next;
                free(cur);
                return lst;
            }
        }
        last = cur;
        cur = cur->next;
    }
    return lst;
}

struct animation *free_list(struct animation *an) {
    struct animation* tmp = an;
    while(tmp) {
        tmp = an->next;
        free(an);
        an = tmp;
    }

    return NULL;
}
struct animation *new_animation(char* n, int l) {
    struct animation *an;

    an = malloc(sizeof(struct animation));
    strncpy(an->name,n,sizeof(an->name)-1);
    an->length = l;
    an->next = NULL;

    return an;
}

void change_length(struct animation *an, int l) {
    an->length = l;
}

void change_name(struct animation *an, char* n) {
    strncpy(an->name,n,sizeof(an->name)-1);
}
