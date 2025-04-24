#ifndef FUN4_2_H
#define FUN4_2_H 
tree *create_buildtech_tree(char *path);
int research_buildtech(struct GameInfo *gameinfop,struct workfile *workfilep);
void free_buildtree(tree *buildtreep);
#endif