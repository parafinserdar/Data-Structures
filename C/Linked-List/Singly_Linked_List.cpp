#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  char *isim;
  int yas, id;
  float kilo, boy;
  struct node *next;
} node;

void listele(node *);
void ekle(node *, char *, int, float, float, int);
int ara(node *, int);
int guncelle(node *, node *, int);
void arayaEkle(node *, int, char *, int, float, float, int);
int idKontrol(node *, int);
void siraliEkle(node *, int, char *, int, float, float);
int sil(node *, int);

int main()
{
  node *root, *iter;
  root = (node *)malloc(sizeof(node));
  root->isim = strdup("parafinserdar (test amacli kayit) ");
  root->kilo = 80;
  root->boy = 1.80;
  root->yas = 20;
  root->id = 1;
  root->next = NULL;
  iter = root;
  int secim, yas, index, kontrol, neDondu, kokGittiMi = 0;
  char isim[50];
  int id;
  float boy, kilo;

  while (1)
  {
    printf("Yapmak istediginiz islemi seciniz : \n 1-Sona Ekle \n 2-Listele \n 3-Ara \n 4-Guncelle \n 5-Istedigin Yere Ekle  \n 6-Sirali Ekle (Kucukten Buyuge) \n 7-Sil \n 8-Cikis \n Seciminiz : ");
    scanf("%d", &secim);

    switch (secim)
    {
    case 1:
      printf("Eklenecek sporcunun id'sini giriniz: \n");
      scanf("%d", &id);
      kontrol = idKontrol(iter, id);
      if (kontrol == 1)
      {
        printf("Bu id daha once kullanilmis.Lutfen baska bir id degeri kullanin. \n");
        break;
      }
      printf("Eklenecek sporcunun ismini giriniz: \n");
      scanf(" %[^\n]", isim);
      printf("Eklenecek sporcunun yasini giriniz: \n");
      scanf("%d", &yas);
      printf("Eklenecek sporcunun boyunu giriniz: \n");
      scanf("%f", &boy);
      printf("Eklenecek sporcunun kilosunu giriniz: \n");
      scanf("%f", &kilo);
      ekle(iter,isim, yas, kilo, boy, id);
      printf("Sporcu basariyla eklendi ! \n");
      break;

    case 2:
      listele(iter);
      break;

    case 3:
      printf("Arama yapmak istediginiz sporcunun id'sini giriniz : \n");
      scanf("%d", &id);
      ara(iter, id);
      break;

    case 4:
      printf("Guncellemek istediginiz sporcunun id'sini giriniz : \n");
      scanf("%d", &id);
      neDondu = guncelle(iter, root, id);
      if (neDondu)
        break;
      printf("Sporcu basariyla guncellendi ! \n");
      break;

    case 5:
      printf("Sporcuyu kacinci indexe eklemek istiyorsunuz ? (Test kaydi -1.indextir. 0'dan itibaren ekleyiniz.)\n");
      scanf("%d", &index);
      printf("Eklenecek sporcunun id'sini giriniz: \n");
      scanf("%d", &id);
      kontrol = idKontrol(iter, id);
      if (kontrol == 1)
      {
        printf("Bu id daha once kullanilmis.Lutfen baska bir id degeri kullanin. \n");
        break;
      }
      printf("Eklenecek sporcunun ismini giriniz: \n");
      scanf(" %[^\n]", isim);
      printf("Eklenecek sporcunun yasini giriniz: \n");
      scanf("%d", &yas);
      printf("Eklenecek sporcunun boyunu giriniz: \n");
      scanf("%f", &boy);
      printf("Eklenecek sporcunun kilosunu giriniz: \n");
      scanf("%f", &kilo);
      arayaEkle(iter, index, isim, yas, kilo, boy, id);
      printf("Sporcu basariyla eklendi ! \n");
      break;

    case 6:
      printf("Eklenecek sporcunun id'sini giriniz: \n");
      scanf("%d", &id);
      kontrol = idKontrol(iter, id);
      if (kontrol == 1)
      {
        printf("Sporcu Eklenemedi ! (Bu id daha once kullanilmis).Lutfen baska bir id degeri kullanin. \n");
        break;
      }
      printf("Eklenecek sporcunun ismini giriniz: \n");
      scanf(" %[^\n]", isim);
      printf("Eklenecek sporcunun yasini giriniz: \n");
      scanf("%d", &yas);
      printf("Eklenecek sporcunun boyunu giriniz: \n");
      scanf("%f", &boy);
      printf("Eklenecek sporcunun kilosunu giriniz: \n");
      scanf("%f", &kilo);
      siraliEkle(iter, id, isim, yas, kilo, boy);
      printf("Sporcu basariyla eklendi !");
      break;

    case 7:
      printf("Silmek istediginiz sporcunun id'sini giriniz : ");
      scanf("%d", &id);
      kokGittiMi = sil(iter, id);
      if (kokGittiMi)
      {
        node *gecici = root;
        root = root->next;
        free(gecici);
        iter = root;
      }
      break;

    case 8:
      printf("Cikis yapiliyor...");
      exit(0);
      break;

    default:
      printf("Gecersiz islem.Lutfen 1-2-3-4-5-6 sayilarindan birini giriniz. \n");
      break;
    }
  }

  return 0;
}

// Fonksiyonlar

void listele(node *iter)
{
  if (iter == NULL)
  {
    printf("Listelenecek bir sporcu bulunamadi. \n");
    return;
  }
  else
  {
    while (iter != NULL)
    {
      printf("\n ************* \n\n Id : %d \n Isim : %s \n Yas: %d \n Kilo : %.2f \n Boy : %.2f \n\n ************* \n\n ", iter->id, iter->isim, iter->yas, iter->kilo, iter->boy);
      iter = iter->next;
    }
  }
}

void ekle(node* iter, char *isim, int yas, float kilo, float boy, int id)
{
  if (iter == NULL) 
  {
    node *eklenecek = (node *)malloc(sizeof(node));
    eklenecek->id = id;
    eklenecek->isim = isim;
    eklenecek->kilo = kilo;
    eklenecek->yas = yas;
    eklenecek->next = NULL;
    return;
  }
  else
  {
    while (iter->next != NULL)
    {
      iter = iter->next;
    }
    iter->next = (node *)malloc(sizeof(node));
    iter->next->isim = strdup(isim);
    iter->next->kilo = kilo;
    iter->next->boy = boy;
    iter->next->id = id;
    iter->next->yas = yas;
    iter->next->next = NULL;
  }
}

int ara(node *iter, int id)
{

  while (iter != NULL)
  {
    if (iter->id == id)
    {
      printf(" Id : %d \n Isim : %s \n Yas: %d \n Kilo : %.2f \n Boy : %.2f \n\n ************* \n\n ", iter->id, iter->isim, iter->yas, iter->kilo, iter->boy);
      return 1;
    }
    iter = iter->next;
  }
  printf("Sporcu bulunamadi. \n");
  return 0;
}

int guncelle(node *iter, node *root, int id)
{
  int secim, yas, sonuc;
  float kilo, boy;
  char isim[50];
  sonuc = ara(iter, id);
  if (sonuc == 1)
  {
    iter = root;
    while (iter->id != id)
    {
      iter = iter->next;
    }

    printf("Hangi bilgiyi guncellemek istiyorsunuz ? -> (1-Isim 2-Yas 3-Kilo 4-Boy 5-Id 6-Menuye don) ");
    scanf("%d", &secim);
    switch (secim)
    {
    case 1:
      printf("Yeni isim ne olsun ? \n");
      scanf(" %[^\n]", isim);
      iter->isim = strdup(isim);
      printf("Isim basariyla guncellendi. \n");
      break;
    case 2:
      printf("Yeni yas ne olsun ? \n");
      scanf("%d", &yas);
      iter->yas = yas;
      printf("Yas basariyla guncellendi. \n");
      break;

    case 3:
      printf("Yeni kilo ne olsun ? \n");
      scanf("%f", &kilo);
      iter->kilo = kilo;
      printf("Kilo basariyla guncellendi. \n");
      break;
    case 4:
      printf("Yeni boy ne olsun ? \n");
      scanf("%f", &boy);
      iter->boy = boy;
      printf("Boy basariyla guncellendi. \n");
      break;
    case 5:
      printf("Yeni id ne olsun ? \n");
      scanf("%d", &id);
      iter->id = id;
      printf("Id basariyla guncellendi. \n");
      break;
    case 6:
      printf("Ana menuye donuluyor...");
      return 1;

    default:
      printf("Gecersiz islem \n");
      break;
    }
  }
}

void arayaEkle(node *iter, int index, char *isim, int yas, float kilo, float boy, int id)
{
  if (iter == NULL)
  {
    node *root = (node *)malloc(sizeof(node));
    root->id = id;
    root->isim = isim;
    root->kilo = kilo;
    root->yas = yas;
    root->next = NULL;
    iter = root;
    return;
  }

  for (int i = 0; i < index - 1; i++)
  {
    iter = iter->next;
  }
  node *eklenecek = (node *)malloc(sizeof(node));
  eklenecek->next = iter->next;
  iter->next = eklenecek;
  eklenecek->id = id;
  eklenecek->isim = strdup(isim);
  eklenecek->kilo = kilo;
  eklenecek->boy = boy;
  eklenecek->yas = yas;
}

int idKontrol(node *iter, int id)
{
  while (iter != NULL)
  {
    if (iter->id == id)
    {
      return 1;
    }
    iter = iter->next;
  }
  return 0;
}

void siraliEkle(node *iter, int id, char *isim, int yas, float kilo, float boy)
{
  if (iter == NULL)
  {
    node *root = (node *)malloc(sizeof(node));
    root->id = id;
    root->isim = isim;
    root->kilo = kilo;
    root->yas = yas;
    iter = root;
    root->next = NULL;
    return;
  }

  else if (id < iter->id)
  {
    node *eklenecek = (node *)malloc(sizeof(node));
    eklenecek->id = id;
    eklenecek->isim = strdup(isim);
    eklenecek->kilo = kilo;
    eklenecek->boy = boy;
    eklenecek->yas = yas;
    eklenecek->next = iter;
    eklenecek = iter;
    return;
  }

  while (iter->next != NULL && id > iter->next->id)
  {
    iter = iter->next;
  }
  node *eklenecek = (node *)malloc(sizeof(node));
  eklenecek->next = iter->next;
  iter->next = eklenecek;
  eklenecek->id = id;
  eklenecek->isim = strdup(isim);
  eklenecek->kilo = kilo;
  eklenecek->boy = boy;
  eklenecek->yas = yas;
}

int sil(node *iter, int id)
{
  node *gecici;
  int sonuc = ara(iter, id);
  if (sonuc == 0)
  {
    return 0;
  }

  else if (iter->id == id)
  { // Silinecek eleman  kok ise
    gecici = iter;
    iter = iter->next;
    free(gecici);
    printf("id'si %d olan kayit basariyla silindi. \n", id);
    return 1;
  }
  else
  {
    while (iter->next->id != id && iter->next != NULL)
    { // Kayit ortada bir yerde ise
      iter = iter->next;
    }

    gecici = iter->next;
    iter->next = gecici->next;
    free(gecici);
    printf("id'si %d olan kayit basariyla silindi. \n", id);
    return 0;
  }
}
