#include <msp430.h>
#include <stdio.h>
#include <sancus/sm_support.h>
#include "../common.h"
#include "foo.h"
#include "bar.h"

int unpr_mul(int a, int b, int c)
{
    return (a * b) % c;
}

/* Also include a protected foo function here to test arithmetic inlining
   across compilation units. */
int SM_ENTRY(foo) foo_mul(int a, int b, int c)
{
    return (a * b) % c;
}

int main()
{
    int rv, u, f;
    msp430_init();

    pr_info("enabling SMs..");
    do_sancus_enable(&foo);
    do_sancus_enable(&bar);

    pr_info("entering foo..");
    rv = enter_foo(128);
    pr_info1("SM foo returned %d\n", rv);
    
    pr_info("comparing unprotected/SM calculations..");
    u = unpr_mul(rv, 100, 35);
    f = foo_mul(rv, 100, 35);
    ASSERT( u==f );

    pr_info("all done!");
    EXIT();
}
