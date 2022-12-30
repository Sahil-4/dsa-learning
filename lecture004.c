#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // P1 : 
    /*
        * * * *
        * * * *
        * * * *
        * * * *

    // for n = 4;
    */

    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void p2() {
    // P2 : 
    /*
        *
        * *
        * * *
        * * * *
    
    // for n = 4;
    */

    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void p3() {
    // P3 : 
    /*
        * * * *
        * * *
        * *
        *
    
    // for n = 4;
    */

    int n = 4;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void p4() {
    // P4 : 
    /*
        1 
        1 2 
        1 2 3 
        1 2 3 4 

    // for n = 4;
    */

    int n = 4;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void p5() {
    // P5 : 
    /*
        1 2 3 4 
        1 2 3 
        1 2 
        1 

    // for n = 4;
    */

    int n = 4;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void p6() {
    // P6 : 
    /*
        1 
        2 2 
        3 3 3 
        4 4 4 4 

    // for n = 4;    
    */

    int n = 4;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

void p7() {
    // P7 : 
    /*
           *   
          ***  
         ***** 
        *******

    // for n = 4;    
    */

    int n = 4;
    for (int i = 1; i <= n; i++) {
        // for spaces 
        for (int j = 1; j <= n-i; j++) {
            printf(" ");
        }

        // for stars 
        for (int j = 1; j <= (i*2)-1; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void p8() {
    // P8 : 
    /*
        *******
         ***** 
          ***  
           *   

    // for n = 4;    
    */

    int n = 4;
    for (int i = n; i > 0; i--) {
        // for spaces 
        for (int j = 1; j <= n-i; j++) {
            printf(" ");
        }

        // for stars 
        for (int j = 1; j <= (i*2)-1; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void p9() {
    // P9 : 
    /*
           *   
          * *  
         * * * 
        * * * *
        * * * *
         * * * 
          * *  
           *   

    // for n = 4;    
    */

    int n = 4;
    for (int i = 1; i <= n; i++) {
        // for spaces 
        for (int j = 1; j <= n-i; j++) {
            printf(" ");
        }

        // for stars 
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        // for new line 
        printf("\n");
    }
    for (int i = n; i > 0; i--) {
        // for spaces 
        for (int j = 1; j <= n-i; j++) {
            printf(" ");
        }

        // for stars 
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        // for new line 
        printf("\n");
    }
}

void p10() {
    // P10 : 
    /*
        *
        * *
        * * *
        * * * *
        * * *
        * *
        *
    */

    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void p11() {
    // P11 : 
    /*
        1 
        0 1 
        1 0 1 
        0 1 0 1 
        1 0 1 0 1 
    for n = 5;    
    */

    int n = 5;
    for (int i = 1; i <= n; i++) {
        int b = 0;
        if (i&1) {
            b = 1;
        }
        for (int j = 1; j <= i; j++) {
            printf("%d ", b);
            b = !b;
        }
        printf("\n");
    } 
}

void p12() {
    // P12 : 
    /*
        1      1 
        12    21 
        123  321 
        12344321 

    // for n = 4;
    */

    int n = 4;
    for (int i = 1; i <= n; i++) {
        int j;
        j = 1;
        while (j <= i) {
            printf("%d ", j);
            j++;
        }

        j = 0;
        while (j < (n-i)*4) {
            printf(" ");
            j++;
        }

        j = i;
        while (j >= 1) {
            printf("%d ", j);
            j--;
        }

        printf("\n");
    }
}

void p13() {
    // P13 : 
    /*
        1 
        2 3 
        4 5 6 
        7 8 9 10 
        11 12 13 14 15 

        for n = 5;
    */

    int n = 5;
    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", c);
            c++;
        }
        printf("\n");
    }
}

void p14() {
    // P14 : 
    /*
        A
        AB
        ABC
        ABCD

    // for n = 4;
    */
   
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            char ch = 'A'+j;
            printf("%c", ch);
        }
        printf("\n");
    }
}

void p15() {
    // P15 : 
    /*
        ABCD
        ABC
        AB
        A

    // for n = 4;
    */

    int n = 4;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            char ch = 'A'+j;
            printf("%c", ch);
        }
        printf("\n");
    }
}

void p16() {
    // P16 : 
    /*
        A 
        B B 
        C C C 
        D D D D 

    // for n = 4;    
    */

    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", 'A'+i);
        }
        printf("\n");
    }
}

void p17() {
    // P17 : 
    /*
           A
          ABA
         ABCBA
        ABCDCBA

    // for n = 4;
    */

    int n = 4;
    for (int i = 0; i < n; i++) {
        // for space 
        int j;
        j = 0;
        while (j < (n-i-1)*2) {
            printf(" ");
            j++;
        }

        // for chars 
        j = 0;

        // first half 
        while (j <= i) {
            printf("%c ", 'A'+j);
            j++;
        }

        // Second half 
        j -= 2;
        while (j >= 0) {
            printf("%c ", 'A'+j);
            j--;
        }

        printf("\n");
    }
}

void p18() {
    // P18 : 
    /*
        E
        E D
        E D C
        E D C B
        E D C B A

    // for n = 5;
    */

    int n = 5;
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= i; j--) {
            printf("%c ", 'A'+j);
        }
        printf("\n");
    }
}

void p19() {
    // P19 : 
    /*
        **********
        ****  ****
        ***    ***
        **      **
        *        *
        *        *
        **      **
        ***    ***
        ****  ****
        **********

    // for n = 5;
    */

    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            printf("*");
        }

        for (int j = i * 2; j > 0; j--) {
            printf(" ");
        }

        for (int j = 0; j < n-i; j++) {
            printf("*");
        }

        printf("\n");
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n-i; j++) {
            printf("*");
        }
        
        for (int j = i * 2; j > 0; j--) {
            printf(" ");
        }
        
        for (int j = 0; j < n-i; j++) {
            printf("*");
        }
        
        printf("\n");
    }
}

void p20() {
    // P20 : 
    /*
        *        *
        **      **
        ***    ***
        ****  ****
        **********
        ****  ****
        ***    ***
        **      **
        *        *

    // for n = 5;
    */

    int n = 5;
    for (int i = 1; i < n; i++) {
	    for (int j = 1; j <= i; j++) {
	        printf("*");
	    }
	    
	    for (int j = 1; j <= (n-i) * 2; j++) {
	        printf(" ");
	    }
	    
	    for (int j = 1; j <= i; j++) {
	        printf("*");
	    }
	    
	    printf("\n");
	}
	for (int i = n; i >= 1; i--) {
	    for (int j = 1; j <= i; j++) {
	        printf("*");
	    }
	    
	    for (int j = 1; j <= (n-i) * 2; j++) {
	        printf(" ");
	    }
	    
	    for (int j = 1; j <= i; j++) {
	        printf("*");
	    }
	    
	    printf("\n");
	}
}

void p21() {
    // P21 : 
    /*
        *****
        *   *
        *   *
        *   *
        *****

    // for n = 5;
    */

    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == n-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void p22() {
    // P22 : 
    /*
        5 5 5 5 5 5 5 5 5 
        5 4 4 4 4 4 4 4 5
        5 4 3 3 3 3 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 2 1 2 3 4 5
        5 4 3 2 2 2 3 4 5
        5 4 3 3 3 3 3 4 5
        5 4 4 4 4 4 4 4 5 
        5 5 5 5 5 5 5 5 5

    // for n = 5;
    */

    int n = 5;
    for (int i = n; i > 0; i--) {
	    for (int j = n; j >= i; j--) {
	        printf("%d ", j);
    	}
    	
    	for (int j = 0; j < (i-1)*2; j++) {
    	    printf("%d ", i);
    	}
    	
    	for (int j = i+1; j <= n; j++) {
    	    printf("%d ", j);
    	}
    	printf("\n");
	}
	
	// revert 
    for (int i = 2; i <= n; i++) {
	    for (int j = n; j >= i; j--) {
	        printf("%d ", j);
    	}
    	
    	for (int j = 0; j < (i-1)*2; j++) {
    	    printf("%d ", i);
    	}
    	
    	for (int j = i+1; j <= n; j++) {
    	    printf("%d ", j);
    	}
    	printf("\n");
	}

}


int main() {
    // Lecture 4 : Solving Patterns Problem 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    // p10();

    // p11();

    // p12();
    
    // p13();
    
    // p14();

    // p15();
    
    // p16();

    // p17();

    // p18();
    
    // p19();
    
    // p20();

    // p21();

    // p22();

    return 0;
}