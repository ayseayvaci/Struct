#include <stdio.h>
#include <stdlib.h>

struct urunler{

    char *urunad;
    int fiyat;
};
struct satislar{

    int satisid;
    int urunsayisi;
    struct urunler * urun;
};
struct calisan{

    char *ad;
    char *soyad;
    int id;
    int satismiktari;
    struct satislar *satis;
};
int main()
{
    
    struct calisan *calisanliste,*cptr,*ayineleman;
    struct satislar*sptr;
     struct urunler*uptr;
    ayineleman=(struct calisan*)malloc(sizeof(struct calisan)*1);
    int calisansayisi,satismiktari,urunsayisi;
    int i=0,j=0,k=0,id;
    int encsatis=0,top=0;
    printf("calisan sayisini giriniz:");
    scanf("%d",&calisansayisi);
     calisanliste=(struct calisan*)malloc(sizeof(struct calisan)*calisansayisi);
     cptr=calisanliste;
    for(i=0;i<calisansayisi;i++)
    {
        printf("%d.calisanin adi:",i+1);
        scanf("%s",&cptr->ad);
         printf("%d.calisanin soyadi:",i+1);
        scanf("%s",&cptr->soyad);
         printf("%d.calisanin id:",i+1);
        scanf("%d",&cptr->id);
        printf("%d.calisan kisinin satis adetini giriniz:",i+1);
        scanf("%d",&cptr->satismiktari);
        cptr->satis=(struct satislar*)malloc(sizeof(struct satislar)*cptr->satismiktari);
        sptr=cptr->satis;
        for(j=0;j<cptr->satismiktari;j++)
        {
            printf("%d.satis kisinin satis id giriniz",j+1);
            scanf("%d",&sptr->satisid);
            printf("%d.satis icin urun sayisini girinz:",j+1);
            scanf("%d",&sptr->urunsayisi);
            sptr->urun=(struct urunler*)malloc(sizeof(struct urunler)*sptr->urunsayisi);
            uptr=sptr->urun;
            for(k=0;k<sptr->urunsayisi;k++)
            {

                printf("%d.urunun adi:",k+1);
                scanf("%s",&uptr->urunad);
                printf("%d.urunun fiyati:",k+1);
                scanf("%d",&uptr->fiyat);
                uptr++;
            }
            sptr++;

        }
         cptr++;

    }
    for(i=0;i<calisansayisi;i++)
    {
         calisanliste=calisanliste+i;
        // printf("%s\t%s\t%d\t",calisanliste->ad,calisanliste->soyad,calisanliste->id);
         for(j=0;j<calisanliste->satismiktari;j++)
         {
            calisanliste->satis=calisanliste->satis+j;
              //printf("%d\t",calisanliste->satis->satisid);
              top=0;
            for(k=0;k<calisanliste->satis->urunsayisi;k++)
            {


                calisanliste->satis->urun=calisanliste->satis->urun+k;
                 //printf("%s\t%d\t",calisanliste->satis->urun->urunad,calisanliste->satis->urun->fiyat);
                top+=calisanliste->satis->urun->fiyat;

                if(top>encsatis)
                {

                    encsatis=top;
                    strcpy(&ayineleman->ad,&calisanliste->ad);
                    strcpy(&ayineleman->soyad,&calisanliste->soyad);
                    ayineleman->id=calisanliste->id;
                    id=calisanliste->satis->satisid;


                }

            }

         }
        // printf("\n");
    }
    printf("en max satis:%d\n",encsatis);
    printf("**************************\n");
    printf("ad:%s\tsoyad:%s\tid:%d\n",&ayineleman->ad,&ayineleman->soyad,ayineleman->id);
    printf("satis id:%d\n",id);


    return 0;
}
