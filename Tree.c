#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *kiri;
  struct Node *kanan;
};

void tambah(struct Node **root, int dataku) {
  if (!(*root)) {
    struct Node *baru;
    baru = (struct Node *)malloc(sizeof(struct Node));
    baru->data = dataku;
    baru->kiri = NULL;
    baru->kanan = NULL;
    (*root) = baru;
    (*root)->kiri = NULL;
    (*root)->kanan = NULL;
    printf("\n\t\t===============\n");
    printf("\t\tData bertambah!\n");
    printf("\t\t===============");
  }
  // jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan
  // diletakkan di node sebelah kiri.
  else if (dataku < (*root)->data)
    tambah(&(*root)->kiri, dataku);
  // jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan
  // diletakkan di node sebelah kanan
  else if (dataku > (*root)->data)
    tambah(&(*root)->kanan, dataku);
  // jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan
  // data pada root
  else if (dataku == (*root)->data)
    printf("\t\tData sudah ada!");
}

void preOrder(struct Node *root) {
  if (root) {
    printf("\t\t%d ", root->data);
    preOrder(root->kiri);
    preOrder(root->kanan);
  }
}

void inOrder(struct Node *root) {
  if (root) {
    inOrder(root->kiri);
    printf("\t\t%d ", root->data);
    inOrder(root->kanan);
  }
}

void postOrder(struct Node *root) {
  if (root) {
    postOrder(root->kiri);
    postOrder(root->kanan);
    printf("\t\t%d ", root->data);
  }
}
void clear(struct Node **root) {
  free(*(root));
  *(root) = NULL;
  printf("\n\t\t==========================\n");
  printf("\t\tBerhasil hapus semua data!\n");
  printf("\t\t==========================\n");
}
int main() {
  int pil, data;
  struct Node *tree;
  tree = NULL;

  do {
    system("cls"); // bersihkan layar
    printf("\t\t==========================\n");
    printf("\t\t=====> PROGRAM TREE <=====\n");
    printf("\t\t==========================\n\n");
    printf("\t\t          MENU\n");
    printf("\t\t==========================\n");
    printf("\t\t|1. Input Data           |\n");
    printf("\t\t|2. Lihat pre-order      |\n");
    printf("\t\t|3. Lihat in-order       |\n");
    printf("\t\t|4. Lihat post-order     |\n");
    printf("\t\t|5. Kosongkan tree       |\n");
    printf("\t\t|6. Keluar               |\n");
    printf("\t\t==========================\n");
    printf("\t\tPilihan kamu? = ");
    scanf("%d", &pil);
    switch (pil) {
    case 1:
      printf("\n\t\tINPUT : ");
      printf("\n\t\t===========");
      printf("\n\t\tData baru : ");
      scanf("%d", &data);
      tambah(&tree, data);
      break;
    case 2:
      printf("\n\t\tOUTPUT PRE ORDER : ");
      printf("\n\t\t====================\n");
      if (tree)
        // panggil fungsi untuk mencetak data secara preOrder
        preOrder(tree);
      else
        printf("\t\tMasih kosong!");
      break;
    case 3:
      printf("\n\t\tOUTPUT IN ORDER : ");
      printf("\n\t\t===================\n");
      if (tree)
        // panggil fungsi untuk mencetak data secara preOrder
        inOrder(tree);
      else
        printf("\t\tMasih kosong!");
      break;
    case 4:
      printf("\n\t\tOUTPUT POST ORDER : ");
      printf("\n\t\t=====================\n");
      if (tree)
        // panggil fungsi untuk mencetak data secara postOrder
        postOrder(tree);
      else
        printf("\t\tMasih kosong!");
      break;
    case 5:
      if (tree)
        clear(&tree);
      else
        printf("\t\tMasih kosong!");
    }
    getch();
  } while (pil != 6);
  free(tree);
}
