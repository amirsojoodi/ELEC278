/*
  Tutorial 3 - LinkedLists

  Polynomials implemented using Linked Lists

  Code provided for ELEC-278 Tutorial at Queen's University

  @author AmirHossein Sojoodi
  @date 2022-09-19
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct polyterm_st polyterm, *p_polyterm;

struct polyterm_st {
  struct polyterm_st *ptnext;  // link to next item in list
  int exp;                     // Exponent value
  double factor;               // Factor value
};

typedef struct poly_st polynomial, *p_polynomial;

struct poly_st {
  polyterm *pt;  // pointer to list of terms
};

polynomial *new_polynomial(void) {
  polynomial *ppnm = (polynomial *)malloc(sizeof(polynomial));
  if (ppnm != NULL) {
    ppnm->pt = NULL;
  }
  return ppnm;
}  // new_polynomial()

polyterm *new_polyterm(int expon, double multiplier) {
  polyterm *ptm = (polyterm *)malloc(sizeof(polyterm));
  if (ptm != NULL) {
    ptm->ptnext = NULL;
    ptm->exp = expon;
    ptm->factor = multiplier;
  }
  return ptm;
}  // new_polyterm()

int power(int n, int exp) {
  int count;
  int rslt = 1;  // lets us handle 0 exponent
  if (exp < 0)
    rslt = -1;
  else
    for (count = 1; count <= exp; count++) rslt = rslt * n;
  return rslt;
}

double evaluate(polyterm *pt, double x) {
  double sum = 0.0;
  while (pt != NULL) {
    sum = sum + (pt->factor) * power(x, pt->exp);
    pt = pt->ptnext;
  }
  return sum;
}

void print(polyterm *pt) {
  int donefirst = 0;  // you’ll see why in a moment
  while (pt != NULL) {
    char sign = (pt->factor < 0) ? '-' : '+';
    double abscoeff = abs(pt->factor);
    // print sign
    if (donefirst || sign == '-') {
      printf(" %c ", sign);
    }
    donefirst = 1;
    printf("%8.2lf X^%d ", abscoeff, pt->exp);
    pt = pt->ptnext;
  }
}

void differentiate(polyterm *pt) {
  while (pt != NULL) {
    pt->factor = pt->factor * pt->exp;
    pt->exp--;
    if (pt->ptnext->exp == 0) {
      polyterm *ptmp = pt->ptnext;
      pt->ptnext = NULL;  // unlink it from polynomial
      free(ptmp);         // get rid of the Term
    }
    pt = pt->ptnext;
  }
}

polynomial *addPolynomials(polynomial *pa, polynomial *pb) {
  polynomial *pnew;  // point to new polynomial

  if (pa == NULL || pa->pt == NULL || pb == NULL || pb->pt == NULL) {
    pnew = NULL;
  } else {
    polyterm *pta, *ptb;
    pnew = new_polynomial();
    pta = pa->pt;
    ptb = pb->pt;
    while (pta != NULL || ptb != NULL) {
      if ((ptb == NULL) || (pta->exp > ptb->exp)) {
        polyterm *p = new_polyterm(pta->exp, pta->factor);
        InsertPolyTerm(pnew, p, 0);
        pta = pta->ptnext;
        continue;
      }
      if ((pta == NULL) || (ptb->exp > pta->exp)) {
        polyterm *p = new_polyterm(ptb->exp, ptb->factor);
        InsertPolyTerm(pnew, p, 0);
        ptb = ptb->ptnext;
        continue;
      }
      if (pta->exp == ptb->exp) {
        polyterm *p = new_polyterm(pta->exp, pta->factor + ptb->factor);
        InsertPolyTerm(pnew, p, 0);
        pta = pta->ptnext;
        ptb = ptb->ptnext;
        continue;
      }
    }
  }
  return pnew;
}
