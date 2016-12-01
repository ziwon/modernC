#include <stdio.h>
#include <math.h> //NAN

#define Setup_list(name, ...)                               \
    double *name ## _list = (double []){__VA_ARGS__, NAN};  \
    int name ## _len = 0;                                   \
    for (name ## _len =0;                                   \
            !isnan(name ## _list[name ## _len]);            \
            ) name ## _len ++;

#define Testclaim(assertion, returnval) if (!(assertion)) \
    {fprintf(stderr, #assertion " failed to be true. Returning " #returnval "\n"); \
        return returnval;}

#define Blankcheck(a) {int aval = (#a[0]=='\0') ? 2 : (a+0); \
    printf("I understand your input to be %i.\n", aval); \
    }

int main(){
    Setup_list(items, 1, 2, 4, 8); // generate items_len and items_list
    double sum=0;
    for (double *ptr= items_list; !isnan(*ptr); ptr++) // a loop using the NaN marker
        sum += *ptr;
    printf("total for items list: %g\n", sum);

    #define Length(in) in ## _len // some systems let you query an array for its own length

    sum=0;
    Setup_list(next_set, -1, 2.2, 4.8, 0.1);
    for (int i=0; i < Length(next_set); i++)
        sum += next_set_list[i];
    printf("total for next set list: %g\n", sum);

    Blankcheck(0);
    Blankcheck( );

    int x = 0, y = 1;
    Testclaim(x==y, -1);
    Testclaim(x==y, ); // proprocess.c:13:9: warning: ‘return’ with no value, in function returning non-void  return returnval;}

}