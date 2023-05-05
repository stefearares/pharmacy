#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void meniu_principal()
{
    printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\nAlegeti o cifra de la 1-3:\033[0m\n\n\033[0;31m1.Modificare produse.\033[0m\n\033[0;33m2.Optiuni cautare produse.\033[0m\n\033[0;34m3.Optiuni afisare produse.\033[0m\n\n\033[0;32m0.Exit                9.Ajutor\033[0m\n-----------------------------------------------------------------\n");

}
void meniu_modificare()
{
printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n\033[0;31mMeniu modificare produse.\n\n1.Adauga produs.\n2.Sterge produs.\n3.Rezerva produs.\033[0m\n\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
}
void meniu_cautare()
{
 printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n\033[0;33mMeniu de cautare produse.\n\n1.Cautare in functie de nume.\n2.Cautare in functie de disponibilitate.\033[0m\n\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
}
void meniu_afisare()
{
   printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n\033[0;34mMeniu afisare produse.\n\n1.Afisare produse indisponibile.\n2.Afisare produse disponibile.\n3.Afiseaza toate produsele.\033[0m\n\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");

}
void ajutor()
{
    printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\nInstructiuni de utilizare:\n\n*Stocul farmaciei este organizat in produse disponibile, marcate cu cuvantul disponibil si indisponibile, marcate cu cuvantul epuizat.\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");

}
int main()
{   struct alegere1{
    int adauga_sterge;
    char numeprodusadaugatsters[10000];
    }alegere1;

    struct alegere2{
    int alegere_meniu2;
    char numecautare[10000];
    }alegere2;

    struct alegere3{
    int rezervat_disponibil;
    }alegere3;

    struct alegere4{
    int optiune_ajutor;
    }alegere4;

   int alegere=1000,z=0,k,hk=0;
   char aux[1000];

   FILE *f;
    FILE *faux;
   while(alegere!=0)
   {
        system("cls");
        meniu_principal();
        k=0;
       do
       {    if(k==1)
                printf("Valoare incorecta, va rog introduceti o valoare valida:");
            k=1;
           scanf("%d",&alegere);
       }while(alegere!=1 && alegere!=2 && alegere!=3 && alegere!=9 && alegere!=0);
       if(alegere==1)
        {   system("cls");
            meniu_modificare();

            scanf("%d",&alegere1.adauga_sterge);
            if(alegere1.adauga_sterge==1)
            {   system("cls");
               printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\nIntroduceti numele produsului dorit:");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","a+");
                fflush(stdin);
                gets(alegere1.numeprodusadaugatsters);
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,alegere1.numeprodusadaugatsters)!=NULL)
                        z=1;
                }
                if(z==1)
                {fclose(f);
                    printf("\nProdusul exista!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");}
                else
                { fprintf(f,"%s disponibil\n",alegere1.numeprodusadaugatsters);

                    fclose(f);
                    printf("\nProdus salvat!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");}
                z=0;
                scanf("%d",&alegere1.adauga_sterge);
            }

            if(alegere1.adauga_sterge==2)
            {
                system("cls");
               printf("-----------------------------------------------------------------\n                    \033[0;32m-=FARMACIE=-\033[0m\nIntroduceti numele produsului dorit:");

                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","r");
                faux=fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSEAUXILIAR.txt","w");
                fflush(stdin);
                gets(alegere1.numeprodusadaugatsters);
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,alegere1.numeprodusadaugatsters)==NULL)
                        fprintf(faux,"%s",aux);
                    else
                        z=1;
                }
                if(z==1)
                {f=freopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","w",f);
                faux=freopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSEAUXILIAR.txt","r",faux);
                while(fgets(aux,1000,faux))
                {

                    fprintf(f,"%s",aux);
                }
                fclose(f);
                    fclose(faux);
                    printf("\nProdusul a fost eliminat cu succes!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");

                }
                else{
                    fclose(f);
                    fclose(faux);
                    printf("\nProdusul nu exista!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");

                }
                z=0;
                scanf("%d",&alegere1.adauga_sterge);
            }
            if(alegere1.adauga_sterge==3)
            {   hk=0;
                system("cls");
                printf("-----------------------------------------------------------------\n                    \033[0;32m-=FARMACIE=-\033[0m\nIntroduceti numele produsului dorit:");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","r");
                faux=fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSEAUXILIAR.txt","w");
                fflush(stdin);
                gets(alegere1.numeprodusadaugatsters);
                 while(fgets(aux,1000,f))
                 {
                     if(strstr(aux,alegere1.numeprodusadaugatsters)!=NULL)
                     {  z=1;
                         if(strstr(aux,"disponibil")!=NULL)
                            fprintf(faux,"%s rezervat\n",alegere1.numeprodusadaugatsters);
                        else
                        {fprintf(faux,"%s",aux);
                        hk=1;}
                     }
                     else
                     {
                         fprintf(faux,"%s",aux);
                     }
                 }
                 if(z==1)
                 {f=freopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","w",f);
                faux=freopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSEAUXILIAR.txt","r",faux);
                while(fgets(aux,1000,faux))
                {

                    fprintf(f,"%s",aux);
                }
                fclose(f);
                fclose(faux);
                if(hk==1)
                printf("\nProdusul este deja rezervat!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                else
                    printf("\nProdusul a fost rezervat cu succes!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                 }
                 else
                 {
                     fclose(f);
                fclose(faux);
                printf("\nProdusul nu exista!\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");

                 }

                z=0;
                scanf("%d",&alegere1.adauga_sterge);
            }
            if(alegere1.adauga_sterge==0)
                alegere=0;
            if(alegere1.adauga_sterge==5)
                system("pause");
        }
        else if(alegere==2)
        {   system("cls");
            meniu_cautare();
            scanf("%d",&alegere2.alegere_meniu2);

            if(alegere2.alegere_meniu2==1)
            {  z=0;
                system("cls");

               printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\nIntroduceti numele produsului dorit:");
                scanf("%s",&alegere2.numecautare);
                system("cls");
            printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","a+");
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,alegere2.numecautare)!=NULL)
                        {printf("%s",aux);
                        z=1;}
                }
                if(z==0)
                    {fclose(f);
                        printf("\nProdusul nu exista!\n");
                    }
                fclose(f);
                printf("\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                scanf("%d",&alegere2.alegere_meniu2);
            }
            if(alegere2.alegere_meniu2==2)
            {    z=0;
                system("cls");
                printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\nIntroduceti disponibilitatea produsului dorit:");
               scanf("%s",&alegere2.numecautare);
                system("cls");
            printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","a+");
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,alegere2.numecautare)!=NULL)
                        {printf("%s",aux);
                        z=1;}
                }
                if(z==0 && strcmp(alegere2.numecautare,"disponibil")!=0)
                    {fclose(f);
                        printf("\nNu exista produse disponibile!");
                    }

                if(z==0 && strcmp(alegere2.numecautare,"rezervat")!=0)
                    {fclose(f);
                        printf("\nToate produsele sunt disponibile!");
                    }
                fclose(f);
                printf("\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                scanf("%d",&alegere2.alegere_meniu2);
            }
            if(alegere2.alegere_meniu2==0)
                alegere=0;
            if(alegere2.alegere_meniu2==5)
                system("pause");
        }

        else if(alegere==3)
        {   system("cls");
            meniu_afisare();
            scanf("%d",&alegere3.rezervat_disponibil);
            if(alegere3.rezervat_disponibil==1)
            {   system("cls");
            printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","r");
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,"rezervat")!=NULL)
                        printf("%s",aux);
                }
                fclose(f);
                printf("\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                scanf("%d",&alegere3.rezervat_disponibil);
            }
            if(alegere3.rezervat_disponibil==2)
            {   system("cls");
                printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n");
                f= fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","r");
                while(fgets(aux,1000,f))
                {
                    if(strstr(aux,"disponibil")!=NULL)
                        printf("%s",aux);
                }
                fclose(f);
                printf("\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                scanf("%d",&alegere3.rezervat_disponibil);
            }
            if(alegere3.rezervat_disponibil==3)
            {
                system("cls");
                 printf("-----------------------------------------------------------------\n                     \033[0;32m-=FARMACIE=-\033[0m\n");
                 f=fopen("C:\\Users\\rares\\OneDrive\\Desktop\\PROIECTC\\PROIECTCPRODUSE.txt","r");
                 while(fgets(aux,1000,f))
                 {
                     printf("%s",aux);
                 }
                 fclose(f);
                printf("\n\033[0;32m5.Inapoi                0.Exit\033[0m\n-----------------------------------------------------------------\n");
                scanf("%d",&alegere3.rezervat_disponibil);

            }
            if(alegere3.rezervat_disponibil==0)
                alegere=0;
            if(alegere3.rezervat_disponibil==5)
                system("pause");
        }
       else if(alegere==9)
        {   system("cls");
            ajutor();
            scanf("%d",&alegere4.optiune_ajutor);
            if(alegere4.optiune_ajutor==0)
                alegere=0;
            if(alegere4.optiune_ajutor==1)
               system("pause");
        }

   }
   return 0;
}
