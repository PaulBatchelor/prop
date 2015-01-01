#include "main.h"

int test_1(PRP_DATA *d)
{
    /* 
    Initial conceptual test of this string of code:
    + 4(+ + + +) 3(+ + +) 
    should create a table that matches:
    [1, 4, 4, 4, 4, 3, 3, 3]
    then processed
    [12, 3, 3, 3, 3, 4, 4, 4]
    */
    int i;
    int data_error = 0;
    //long ref[] = {1, 4, 4, 4, 4, 3, 3, 3};
    long ref[] = {12, 3, 3, 3, 3, 4, 4, 4};
    long ref_ds = 8; 

    fprintf(stderr,"Testing 1... ");
    prp_create(&d);
    prp_add_note(d);
    prp_mul(d, 4);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
    prp_return(d);
    prp_mul(d, 3);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
    prp_return(d);
    prp_process(d);

    fprintf(stderr, "the max res is %d\n", d->max_res);
    if(d->data_size != ref_ds) {
        fprintf(stderr, "ERROR: data_size is %d, when it should be 10\n",
                d->data_size);
        prp_destroy(&d);
        return 0;
    }
    for(i = 0; i < ref_ds; i++)
    {
        if(d->data[i] != ref[i])
        {
            fprintf(stderr, "ERROR: position a position %d (%d) does not match reference (%d)\n",
                    i, d->data[i], ref[i]);
            data_error = 1;
        }
    }

    if(data_error)
    {
        fprintf(stderr,"generated table does not match reference!\n");
        fprintf(stderr, "ref: ");
        for(i = 0; i < ref_ds; i++)
        {
            fprintf(stderr, "%d ", ref[i]);
        }
        fprintf(stderr, "\ngen: ");
        for(i = 0; i < ref_ds; i++)
        {
            fprintf(stderr, "%d ", d->data[i]);
        }
        fprintf(stderr, "\n");

        prp_destroy(&d);
        return 0;
    }

    prp_destroy(&d);
    return 1;
}

int test_2(PRP_DATA *d)
{
    /* 
    Initial conceptual test of this string of code:
    + + 3(+ + +) 2(+ + 3(+ + +))
    should create a table that matches:
    [1, 1, 3, 3, 3, 2, 2, 6, 6, 6]
    */
    int i;
    int data_error = 0;
    long ref[] = {1, 1, 3, 3, 3, 2, 2, 6, 6, 6};
    
    fprintf(stderr,"Testing 2... ");
    prp_create(&d);
    prp_add_note(d);
    prp_add_note(d);
    prp_mul(d,3);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
    prp_return(d);
    prp_mul(d,2);
        prp_add_note(d);
        prp_add_note(d);
        prp_mul(d,3);
            prp_add_note(d);
            prp_add_note(d);
            prp_add_note(d);
        prp_return(d);
    prp_return(d);


    if(d->data_size != 10) {
        fprintf(stderr, "ERROR: data_size is %d, when it should be 10\n",
                d->data_size);
        prp_destroy(&d);
        return 0;
    }
    for(i = 0; i < 10; i++)
    {
        if(d->data[i] != ref[i])
        {
            fprintf(stderr, "ERROR: position a position %d (%d) does not match reference (%d)\n",
                    i, d->data[i], ref[i]);
            data_error = 1;
        }
    }

    if(data_error)
    {
        fprintf(stderr,"generated table does not match reference!\n");
        fprintf(stderr, "ref: ");
        for(i = 0; i < 10; i++)
        {
            fprintf(stderr, "%d ", ref[i]);
        }
        fprintf(stderr, "\ngen: ");
        for(i = 0; i < 10; i++)
        {
            fprintf(stderr, "%d ", d->data[i]);
        }
        fprintf(stderr, "\n");

        prp_destroy(&d);
        return 0;
    }

    prp_destroy(&d);
    return 1;
}

int test_prp_process(PRP_DATA *d)
{
    /* 
    This test_1 code is run:
    + + 3(+ + +) 2(+ + 3(+ + +))
    Which creates a table like this (shuold have been testing in test_1):
    [1, 1, 3, 3, 3, 2, 2, 6, 6, 6]
    prp_process should create this table:
    [6, 6, 2, 2, 2, 3, 3, 1, 1, 1]

    */
    fprintf(stderr,"Testing prp_process()... ");
    int data_error = 0;
    int i;
    long ref[] = {6, 6, 2, 2, 2, 3, 3, 1, 1, 1};
    
    prp_create(&d);
    /*should be identical to test_1 code*/ 
    prp_add_note(d);
    prp_add_note(d);
    prp_mul(d,3);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
    prp_return(d);
    prp_mul(d,2);
        prp_add_note(d);
        prp_add_note(d);
        prp_mul(d,3);
            prp_add_note(d);
            prp_add_note(d);
            prp_add_note(d);
        prp_return(d);
    prp_return(d);

    /*this is the new bit */
    prp_process(d);
    
    for(i = 0; i < 10; i++)
    {
        if(d->data[i] != ref[i])
        {
            fprintf(stderr, "ERROR: position a position %d (%d) does not match reference (%d)\n",
                    i, d->data[i], ref[i]);
            data_error = 1;
        }
    }

    if(data_error)
    {
        fprintf(stderr,"generated table does not match reference!\n");
        fprintf(stderr, "ref: ");
        for(i = 0; i < 10; i++)
        {
            fprintf(stderr, "%d ", ref[i]);
        }
        fprintf(stderr, "\ngen: ");
        for(i = 0; i < 10; i++)
        {
            fprintf(stderr, "%d ", d->data[i]);
        }
        fprintf(stderr, "\n");

        prp_destroy(&d);
        return 0;
    }
    
    prp_destroy(&d);
    return 1;
}

int test_prp_free(PRP_DATA *d)
{
    /* simple create and destroy */
}

int test_prp_create(PRP_DATA *d)
{
    /* make sure everything is initialized properly */

    fprintf(stderr,"Testing prp_create()... ");
    prp_create(&d);
    if(d->res != 1) {
        fprintf(stderr, "ERROR: res is initialized at %d, when it should be 1\n",
                d->res);
        return 0;
    }

    if(d->mult_size != 1) {
        fprintf(stderr, "ERROR: mult_size is initialized at %d, when it should be 1\n",
                d->mult_size);
        return 0;
    }
    
    if(d->mult[0] != 1) {
        fprintf(stderr, "ERROR: index 0 of mult is initialized at %d, when it should be 1\n",
                d->mult[0]);
        return 0;
    }
    if(d->data[0] != -1) {
        fprintf(stderr, "ERROR: index 0 of data is initialized at %d, when it should be -1\n",
                d->data[0]);
        return 0;
    }
    if(d->max_res != 1) {
        fprintf(stderr, "ERROR: max_data is initialized at %d, when it should be 1\n",
                d->max_res);
        return 0;
    }
    
    
    if(d->data_size != 0) {
        fprintf(stderr, "ERROR: data_size is initialized at %d, when it should be 0\n",
                d->data_size);
        return 0;
    }
    
    if(d->ts != 1.0) {
        fprintf(stderr, "ERROR: ts is initialized at %g, when it should be 1.0\n",
                d->ts);
        return 0;
    }
    if(d->bpm != 120) {
        fprintf(stderr, "ERROR: tempo is initialized at %d, when it should be 120\n",
                d->bpm );
        return 0;
    }

    prp_destroy(&d);

    return 1;
}

int test_prp_add(PRP_DATA *d)
{
    /* Make sure everything is initialized properly */

    fprintf(stderr,"Testing prp_add()... ");
    prp_create(&d);
    prp_add_note(d);
    if(d->data[0] != 1) {
        fprintf(stderr, "ERROR: prp_data should now be 1, but it is %d instead\n",
                d->data[0]);
        prp_destroy(&d);
        return 0;
    }

    prp_destroy(&d);
    return 1;

}

int test_prp_mul(PRP_DATA *d)
{
    /*
    Multiply by 4, then multiply by 2. res should stay at 4 since 2 is multiple
    of 2.
    */
    fprintf(stderr,"Testing prp_mul()... ");
    prp_create(&d);
    prp_mul(d, 4);
    prp_mul(d, 2);
    if(d->res != 4)
    {
        fprintf(stderr, "ERROR: res should now be 4, but it is %d instead\n",
                d->res);
        prp_destroy(&d);
        return 0;
    }

    prp_destroy(&d);
    return 1;
}

int test_prp_return(PRP_DATA *d)
{
    fprintf(stderr,"Testing prp_return()... ");

    prp_create(&d);
    /*create multiplier of 2*/
    prp_mul(d, 2);
    /*create multiplier of 3*/
    prp_mul(d, 3);
    /*break out of 3 multiplier */
    prp_return(d);

    if(d->res != 2) {
        fprintf(stderr, "ERROR: res should now be 2, but it is %d instead\n",
                d->res);
        prp_destroy(&d);
        return 0;
    }
    
    prp_return(d);
    
    if(d->res != 1) {
        fprintf(stderr, "ERROR: res should now be 2, but it is %d instead\n",
                d->res);
        prp_destroy(&d);
        return 0;
    }

    prp_destroy(&d);
    return 1;
}

int test_prp_print(PRP_DATA *d)
{
    fprintf(stderr,"Testing prp_print()... \n");
    fprintf(stderr,"Using expression {+ + 3(+ + +) 2(+ + 3(+ + +))}\n");
    prp_create(&d);
    prp_add_note(d);
    prp_add_note(d);
    prp_mul(d,3);
        prp_add_note(d);
        prp_add_note(d);
        prp_add_note(d);
    prp_return(d);
    prp_mul(d,2);
        prp_add_note(d);
        prp_add_note(d);
        prp_mul(d,3);
            prp_add_note(d);
            prp_add_note(d);
            prp_add_note(d);
        prp_return(d);
    prp_return(d);
    prp_process(d);

    prp_print(d);
    prp_destroy(&d);
    return 1;
}

int main()
{
    PRP_DATA *d;
    
    if(test_prp_create(d)){
        fprintf(stderr,"prp_create() passed!\n");    
    }else{
        fprintf(stderr,"prp_create() failed!\n");    
    }
    
    if(test_prp_add(d)){
        fprintf(stderr,"prp_add() passed!\n");    
    }else{
        fprintf(stderr,"prp_add() failed!\n");    
    }
    if(test_prp_mul(d)){
        fprintf(stderr,"prp_mul() passed!\n");    
    }else{
        fprintf(stderr,"prp_mul() failed!\n");    
    }
    
    if(test_prp_return(d)){
        fprintf(stderr,"prp_return() passed!\n");    
    }else{
        fprintf(stderr,"prp_return() failed!\n");    
    }
    
    if(test_1(d)){
        fprintf(stderr,"Test 1 passed!\n");    
    }else{
        fprintf(stderr,"Test 1 failed!\n");    
    }
    
    if(test_2(d)){
        fprintf(stderr,"Test 2 passed!\n");    
    }else{
        fprintf(stderr,"Test 2 failed!\n");    
    }
    
    if(test_prp_process(d)){
        fprintf(stderr,"prp_process() passed!\n");    
    }else{
        fprintf(stderr,"prp_process() failed!\n");    
    }
    
    if(test_prp_print(d)){
        fprintf(stderr,"prp_print() passed!\n");    
    }else{
        fprintf(stderr,"prp_print() failed!\n");    
    }

    return 0;
}

