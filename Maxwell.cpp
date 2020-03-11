#include <iostream>
#include "TMath.h"
using namespace std;

const Double_t lamb = 200; //MeV
const Double_t A = 5;

Double_t Maxwell(Double_t *x, Double_t *par) {
  if (x[0] > par[1] && par[2] > 0 && par[0] >0) {
      return par[0]*(x[0]-par[1])/par[2]*TMath::Exp(-x[0]-par[1])/par[2];
    }
    else {return 0.;}
  }
