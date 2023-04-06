#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct File {
    char name[50]; 
    int is_dir; 
    struct File *next; 
    struct File *child; 
};


struct File* create_file(char* name, int is_dir) {
    struct File* new_file = (struct File*)malloc(sizeof(struct File));
    strcpy(new_file->name, name);
    new_file->is_dir = is_dir;
    new_file->next = NULL;
    new_file->child = NULL;
    return new_file;
}


void add_file(struct File* parent, struct File* new_file) {
    if (parent->child == NULL) {
        parent->child = new_file;
    } else {
        struct File* curr = parent->child;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_file;
    }
}


void print_files(struct File* dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s", dir->name);
    if (dir->is_dir) {
        printf("/");
    }
    printf("\n");
    if (dir->is_dir) {
        struct File* curr = dir->child;
        while (curr != NULL) {
            print_files(curr, depth + 1);
            curr = curr->next;
        }
    }
}

int main() {
   
    struct File* root = create_file("/", 1);

    
    struct File* file1 = create_file("file1.txt", 0);
    struct File* dir1 = create_file("dir1", 1);
    struct File* file2 = create_file("file2.txt", 0);
    struct File* dir2 = create_file("dir2", 1);
    struct File* file3 = create_file("file3.txt", 0);

    
    add_file(root, file1);
    add_file(root, dir1);
    add_file(root, file2);
    add_file(root, dir2);
    add_file(dir2, file3);

    
    print_files(root, 0);

    return 0;
}
