#include <stdio.h>
#include <stdlib.h>

// lijevo, manji
// desno, veći

struct _Node;
typedef struct _Node* Position;
typedef struct _Node {
    int value;
    Position left;
    Position right;
}
Node;

Position find_the_best_position(Position root, int value);
Position find_the_best_position(Position root, int value) {
    if (root == NULL) return NULL;

    Position temp = root;
    Position status = NULL;

    if (temp->value == value) {
        return status;
    }

    if (temp->left && value < temp->left->value) {
        status = find_the_best_position(temp->left, value);

    }
    else if (temp->right && value < temp->right->value) {
        status = find_the_best_position(temp->right, value);
    }

    return status;
}

Position create_node(Position root, int value);
Position create_node(Position root, int value) {
    Position search = find_the_best_position(root, value);

    if (search) {
        if (search->value == value) {
            return search;
        }
    }

    Position new_node = NULL;
    new_node = (Position)malloc(sizeof(Node));

    if (search) {
        if (search->left) {
            if (value < search->left->value) {
                search->left = new_node;
            }
        }

        if (search->right) {
            if (value > search->right->value) {
                search->right = new_node;
            }
        }
    }

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = value;

    return new_node;
}

int print_inorder(Position node);
int print_inorder(Position node) {
    if (node == NULL) {
        return 0;
    }

    print_inorder(node->left);

    printf(" %i ", node->value);

    print_inorder(node->right);

    return 0;
}

int print_preorder(Position root);
int print_preorder(Position node) {
    if (node == NULL) {
        return 0;
    }

    printf(" %i ", node->value);

    print_preorder(node->left);

    print_preorder(node->right);

    return 0;
}

int print_postorder(Position node);
int print_postorder(Position node) {
    if (node == NULL) {
        return 0;
    }

    print_postorder(node->left);

    print_postorder(node->right);

    printf(" %i ", node->value);

    return 0;
}

int print_level_order_current(Position root, int i);
int print_level_order_current(Position root, int i) {
    if (i == 1) {
        printf(" %i ", root->value);
    }
    else if (i > 1) {
        print_level_order_current(root->left, i - 1);
        print_level_order_current(root->right, i - 1);
    }
    return 0;
}

int get_tree_depth(Position root);
int get_tree_depth(Position root) {
    int left_count = 0;
    int right_count = 0;
    Position temp = NULL;

    temp = root;
    while (temp) {
        left_count++;
        temp = temp->left;
    }

    temp = root;
    while (temp) {
        right_count++;
        temp = temp->right;
    }

    if (left_count > right_count) {
        return left_count;
    }
    else if (right_count > left_count) {
        return right_count;
    }

    return left_count;

}

int print_level_order(Position root);
int print_level_order(Position root) {
    Position temp = root;

    printf("\n");
    int height = get_tree_depth(root);
    for (int i = 1; i < height; i++) {
        print_level_order_current(root, i);
    }
    printf("\n");

    return 0;
}

int insert_node_in_tree(Position root, Position node);
int insert_node_in_tree(Position root, Position node) {
    if (root->value == node->value) return root;
    if (node->value < root->value) {
        root->left = node;

    }
    else if (node->value > root->value) {
        root->right = node;
    }

}

int main() {
    Position root = create_node(NULL, 10);

    Position a2 = create_node(root, 5);
    Position a8 = create_node(root, 15);
    Position a6 = create_node(root, 7);
    Position a5 = create_node(root, 4);

    root->left = a2;
    root->right = a8;
    root->left->left = a5;

    printf("\n inorder \n");
    print_inorder(root);
    printf("\n");

    printf("\n preorder \n");
    print_preorder(root);
    printf("\n");

    printf("\n postorder \n");
    print_postorder(root);
    printf("\n");

    printf("\n inorder \n");
    print_level_order(root);
    printf("\n");

    return 0;
}