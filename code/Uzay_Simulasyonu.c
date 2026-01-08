#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define gezegen_sayisi 8




/**gereken global degiskenler**/
char *GEZEGEN_ISIMLERI[gezegen_sayisi] =
{"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
double GEZEGEN_YERCEKIMI[gezegen_sayisi] =
{3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};


/*ftn to check if the entry is valid or not*/
int is_number(char number[])
{
    int i=0;
    while(number[i]==' ')
        i++;
    if(number[i]=='-' || number[i]=='+')
        i++;
    if (number[i]=='\0')
        return 0;
    while(number[i]>='0' && number[i]<='9')
        i++;
    while(number[i]==' ')
        i++;
    return (number[i]=='\0');
}

/*mutlak deger fonksiyonu*/
double mutlak_deger(double number)
{
    return (number<0)? -number : number;
}


/**deney ile ilgili fonksiyonlar**/
//1.Serbest Dusme Deneyi:
void serbest_dusme(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double sure,yukseklik;
    printf("\nSerbest dusme deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Alinan zamani giriniz!(s)\n");
    scanf("%lf",&sure);
    sure=mutlak_deger(sure);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        yukseklik= 0.5 * (*(g+i)) * sure * sure;
        printf("%s ->  Alinan yol: \t%.2f metre\n", *(gezegenler+i), yukseklik);
    }

}


//2.Yukari Atis Deneyi:
void yukari_ates(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double hiz,yukseklik;
    printf("\nYukari ates deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Ilk hizi giriniz!(m/s)\n");
    scanf("%lf",&hiz);
    hiz=mutlak_deger(hiz);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        yukseklik= 0.5 * hiz * hiz / (*(g+i));
        printf("%s ->  maksimum yukseklik: \t%.2f metre\n", *(gezegenler+i), yukseklik);
    }
}


//3.Agirlik Deneyi:
void agirlik(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double kutle,agirlik;
    printf("\nAgirlik deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Cismin kutlesini giriniz!(Kg)\n");
    scanf("%lf",&kutle);
    kutle=mutlak_deger(kutle);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        agirlik= kutle * (*(g+i));
        printf("%s ->  gezegendeki agirlik: \t%.2f Newton\n", *(gezegenler+i), agirlik);
    }
}


//4.Kutlecekimsel Potansiyel Enerji Deneyi:
void kotlecekimsel_potensiyel_energy(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double kutle,yukseklik,potensial_E;
    printf("\nKotlecekimsel Potensiyel Enerji deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Cismin yuksekligi giriniz!(m)\n");
    scanf("%lf",&yukseklik);
    printf("cismin kutlesini giriniz!(kg)\n");
    scanf("%lf",&kutle);
    kutle=mutlak_deger(kutle);
    yukseklik=mutlak_deger(yukseklik);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        potensial_E= kutle * yukseklik * (*(g+i));
        printf("%s ->  potential enerji: \t%.2f Joule\n", *(gezegenler+i), potensial_E);
    }
}


//5.Hidrostatik Basinc Deneyi:
void hidrostatik_basinc(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double yogunluk,derinlik,basinc;
    printf("\nHidrostatik basinc deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Sivinin birim hacmindeki kutlesini giriniz!(Kg/m^3)\n");
    scanf("%lf",&yogunluk);
    printf("Derinligini giriniz!(m)\n");
    scanf("%lf",&derinlik);
    derinlik=mutlak_deger(derinlik);
    yogunluk=mutlak_deger(yogunluk);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        basinc= yogunluk * derinlik * (*(g+i));
        printf("%s ->  basinc: \t%.2f Pa\n", *(gezegenler+i), basinc);
    }
}


//6.Arsimet Kaldirma Kuvveti Deneyi:
void arsimt_kaldirma_kuvvet(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double yogunluk,hacim,kuvvet;
    printf("\nArsimet Kaldirma Kuvvet deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Sivinin birim hacmindeki kutlesini giriniz!(Kg/m^3)\n");
    scanf("%lf",&yogunluk);
    printf("Cismin batan kisminin hacmi giriniz!(m^3)\n");
    scanf("%lf",&hacim);
    hacim=mutlak_deger(hacim);
    yogunluk=mutlak_deger(yogunluk);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        kuvvet= yogunluk * hacim * (*(g+i));
        printf("%s ->  Kaldirma kuvvet: \t%.2f N\n", *(gezegenler+i), kuvvet);
    }
}


//7.Basit Sarkaç Periyodu Deneyi:
void basit_sarkac_periyodu(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double uzunluk,period;
    printf("\nBasit Sarkac deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Sarkacin uzunlugunu giriniz!(m)\n");
    scanf("%lf",&uzunluk);
    uzunluk=mutlak_deger(uzunluk);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        period= 2 * M_PI * sqrt(uzunluk/(*(g+i)));
        printf("%s ->  period: \t%.2f Saniye\n", *(gezegenler+i), period);
    }

}


//8.Sabit Ip Gerilmesi Deneyi:
void sabit_ip_gerilmesi(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double girilme_kuvvet,kutle;
    printf("\nSabit Ip Gerilme deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Asilan cismin kutlesini giriniz!(Kg)\n");
    scanf("%lf",&kutle);
    kutle=mutlak_deger(kutle);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        girilme_kuvvet= kutle * (*(g+i));
        printf("%s ->  ipin gerilme kuvveti: \t%.2f Newton\n", *(gezegenler+i), girilme_kuvvet);
    }

}


//9.Asansor Deneyi:
void asansor(double *g, char **gezegenler, char bilim_insanin_adi[])
{
    double kutle, ivme, n_kuvvet;
    int durum;
    printf("\nAsansor deneyi:\n");
    printf("Lutfen birimlerin metrik oldugundan emin olun.\n");
    printf("Cismin kutlesini giriniz!(Kg)\n");
    scanf("%lf",&kutle);
    printf("Asansorun ivmesini giriniz!(m/s^2)\n");
    scanf("%lf",&ivme);
    printf("Durumu seciniz:\n");
    printf("1 - Yukari cikarken hizlaniyor\n");
    printf("2 - Asagi inerken yavasliyor\n");
    printf("3 - Asagi inerken hizlaniyor\n");
    printf("4 - Yukari cikarken yavasliyor\n-->");
    scanf("%d", &durum);
    kutle=mutlak_deger(kutle);
    ivme = mutlak_deger(ivme);
    printf("%s'tarafindan yapilan deneyin bulgulari:\n",bilim_insanin_adi);
    for (int i=0; i<gezegen_sayisi; i++)
    {
        if (durum==1 || durum==2)
            n_kuvvet= ( (*(g+i)) + ivme ) * kutle;
        else if (durum==4 || durum==3)
            n_kuvvet= ( (*(g+i)) - ivme ) * kutle;
        else
        {
            printf("Gecersiz secim!\n");
            return;
        }
        printf("%s ->  Normal Kuvvet: \t%.2f Newton\n", *(gezegenler+i), n_kuvvet);
    }

}







int main()
{
    /**gerkecek olan degiskenler**/
    char bilim_insanin_adi [51];
    char choise[10];
    int I_choise;


    /**programin baslangici**/
    printf("--------------------*--------------------\n");
    printf("Bu program, Gunes Sistemi gezegenleri uzerinde gerceklestirilen bazi fizik deneylerinin hesaplanmasini amaclamaktadir.\n");
    printf("Ismini lutfen giriniz!\n");
    //gets() fonksiyonu guvenlik acisindan onerilmemekle birlikte, ders yonergesi geregi bilincli olarak kullanilmistir.
    gets(bilim_insanin_adi);
    printf("Hos geldiniz %s\n",bilim_insanin_adi);
    printf("Uzay Simulasyon Programi Basliyor...!\n\n");
    printf("---------------------------------------------------------------------------------\n");
    while(1)
    {
        /**deney secemi**/
        printf("istediginiz deneyini yapmak icin, ilgili sayiyi giriniz!\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkaç Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("programi sonlandirmak icin -1 giriniz!\n");
        //kullanicidan bir SAYI almak:
        while(1)
        {
            gets(choise);
            if (is_number(choise)!=1)
            {
                printf("lutfen bir SAYI giriniz!");
            }
            else
            {
               I_choise=atoi(choise);
               break;
            }
        }
        if (I_choise==-1)
            break;
        switch(I_choise)
        {
            case 1:
                serbest_dusme(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 2:
                yukari_ates(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 3:
                agirlik(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 4:
                kotlecekimsel_potensiyel_energy(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 5:
                hidrostatik_basinc(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 6:
                arsimt_kaldirma_kuvvet(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 7:
                basit_sarkac_periyodu(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 8:
                sabit_ip_gerilmesi(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            case 9:
                asansor(GEZEGEN_YERCEKIMI, GEZEGEN_ISIMLERI, bilim_insanin_adi);
                break;

            default:
                printf("\nnumara 1-9 arasinda olmalidir!!!");
                break;
        }

        printf("\n============================================================\n");
    }
    //programin bittiginde:
    printf("\n\n\n\n\nprogramimizi kullanmadiginizdan size tesekkur ederiz!\n");
    printf("program sonlandirildi!\n\n\n\n");
    return 0;
}
