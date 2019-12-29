#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main()
{

int n=128;


/*int n;
printf("Give maximum bit range:");
scanf("%d",&n);*/

//~~~~~~Initializations and declarations~~~~~~~//
 mpz_t g;
 mpz_init(g);

 mpz_t p;
 mpz_init(p);

 mpz_t x;
 mpz_init(x);

  mpz_t y;
  mpz_init(y);

  mpz_t k;
  mpz_init(k);

  mpz_t c1;
  mpz_init(c1);


 gmp_randstate_t state;
 gmp_randinit_default(state);


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


 mpz_urandomb(g,state,n); //Random number x bit
 mpz_nextprime(g,g); //Make it prime number


 mpz_urandomb(p,state,n); //Random number x bit



 while( mpz_cmp(g,p)<0)
 {
     mpz_urandomb(p,state,n);
 }


 gmp_printf("The value of g is %Zd \n",g);
 gmp_printf("The value of p is %Zd \n",p);


mpz_urandomb(x,state,n);

 while( mpz_cmp(g,x)<0 )
 {
     mpz_urandomb(x,state,n);

 }

 gmp_printf("The value of x is %Zd \n",x);


 mpz_powm(y,p,x,g);

 gmp_printf("The value of y is %Zd \n",y);


 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Encryption~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//G
 //Dynamic allocation of mememory depanding of the input//

	//char temp;
	//char *message;
	//message = (char*)malloc(sizeof(char));
	int count = 0;
    char message[12];
    strcpy(message, "Good Morning");

    //printf("\nGive message: ");

	//while(temp!='\n')
	//{
	//	temp = getchar();
		//message[count]=temp;
		//count++;
	//	message =(char*)realloc(message,count*(sizeof(char)));

	//}



    mpz_urandomb(k,state,n);

    while( mpz_cmp(g,k)<0 )
 {
     mpz_urandomb(k,state,n);

 }

    gmp_printf("The value of k is %Zd \n",k);

    mpz_powm(c1,p,k,g);

    gmp_printf("\n\nThe value of C1 is %Zd \n",c1);


    //~~Initialize the encrypted array~~~~//
    int i;
    mpz_t c2;
    mpz_init(c2);





    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    mpz_t temp2;
    mpz_init(temp2);

    mpz_t temp3;
    mpz_init(temp3);

    mpz_powm(temp2,y,k,g); //temp2 = (y^k)mod p

    gmp_printf("\n\ntemp2 = (y^k)mod p :%Zd \n",temp2);



    mpz_mul_si(c2,temp2,message[0]);

    gmp_printf("C2 = %Zd\n",c2);



	mpz_clear(temp2);
	mpz_clear(temp3);
	mpz_clear(k);


    //free(c2);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Decryption~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    mpz_t temp4;
    mpz_init(temp4);

    mpz_t temp5;
    mpz_init(temp5);

    mpz_t temp6;
    mpz_init(temp6);

    mpz_t temp7;
    mpz_init(temp7);


    mpz_set_si(temp7,1);



    mpz_powm(temp5,c1,x,g);
    gmp_printf("C2 = %Zd\n",temp5);

    mpz_cdiv_q(temp6,c2,temp5);

    gmp_printf("\n\n\nResult:%Zd\n",temp6);



}
